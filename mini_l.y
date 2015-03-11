%{
/*Prologue: definitions of headers, types and variables used in actions*/
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <sstream>
#include <list>


using namespace std;

void yyerror (const char* msg);

/* need symbol table. can implement using a map struct */
map <string, int> symbol_table;
vector <string> ident_list;
int label_ctr, temp_ctr, pred_ctr  = 0;

bool errorFound;
list<string> milcode;

string newTemp();
string newPred ();
string genExprCode ( string dst, string src1, string src2, string op );

extern int currLine;
extern int currPos; 
extern int yylex();
extern FILE * yyin;
extern char* yytext;

enum IDENT_TYPE
{
	TYPE_INT = 0,
	TYPE_ARRAY = 1
};
   
	

%}



/*Bison Declarations*/
%union{
    char* IntString;
    char* String;
    
    // struct attribute was here
    struct attribute
	{
		//char* name;
		char name [255];
		int type;
		char* size;
		char* code;
	};

    
    struct attribute myAttri; 
}

%error-verbose
%start S
%token PLUS "+" SUB "-" MULT "*" DIV "/"  MOD "%" EQUAL "="
%token PROGRAM
%token BEGIN_PROGRAM
%token END_PROGRAM
%token INTEGER
%token ARRAY
%token OF
%token IF THEN ENDIF ELSE ELSEIF WHILE DO BEGINLOOP ENDLOOP BREAK CONTINUE EXIT
%token READ WRITE
%token AND OR NOT TRUE FALSE EQ NEQ LT GT LTE GTE
%token SEMICOLON ";" COLON ":" COMMA "," QUESTION "?"
%token L_BRACKET "[" R_BRACKET "]" L_PAREN "(" R_PAREN ")" ASSIGN ":="
%token <String> IDENT
%token <IntString> NUMBER
%token <string> COMMENT


%left PLUS SUB
%left MULT DIV
%left MOD
%right NEG

%left EQ
%left NEQ
%left LT
%left GT
%left LTE
%left GTE


%type <myAttri> statement;
%type <myAttri> stmt_loop;

%type <myAttri> declaration;
%type <myAttri> array_decl;

//%type <myAttri> bBEGIN_PROGRAM;

%type <myAttri> term;
%type <myAttri> var;

%type <myAttri> mult_expr;
%type <myAttri> expr;
%type <myAttri> bool_expr;
%type <myAttri> relation_and_expr;
%type <myAttri> relation_expr;
%type <myAttri> comp;


/*Grammar Rules*/
%%

S:          program
            ;

program:    PROGRAM IDENT SEMICOLON block END_PROGRAM 
	{ printf("program -> PROGRAM IDENT SEMICOLON block END_PROGRAM\n"); /*cout << milCode;*/
	  list <string>::iterator it;
	  
	  for ( it = milcode.begin(); it != milcode.end(); ++it)
			cout << *it << endl;
	}
	| error IDENT SEMICOLON block END_PROGRAM
	| PROGRAM IDENT SEMICOLON block error
	| PROGRAM error SEMICOLON block END_PROGRAM
	| PROGRAM IDENT error block END_PROGRAM
    ;

block:    decl_loop bBEGIN_PROGRAM stmt_loop
		  | decl_loop error stmt_loop
          ;
          
bBEGIN_PROGRAM:		BEGIN_PROGRAM { milcode.push_back(" : START"); }
					;

decl_loop:  declaration SEMICOLON decl_loop
	    | declaration SEMICOLON 
	    | declaration error 
        ;
        
stmt_loop:  statement SEMICOLON stmt_loop { $$.code = $1.code; }
	    | statement SEMICOLON { $$.code = $1.code; }
	    | statement error stmt_loop 
	    | statement error
        ;

declaration: ident_loop COLON array_decl INTEGER
{ 	/* check if identifer in symbol table
	iterate through identifier list and search for it in map. if it's there,
	print out an error message. otherwise, add to symbol table.
	*/

	int size = ident_list.size();
		
	for (int i = 0; i < size; i++ )
	{
		string ident = ident_list[i];
		map <string, int>::iterator it = symbol_table.find (ident);
		
		// if ident isn't in symbol table and ident is an array
		// add to the symbol table.
		if (it == symbol_table.end() && $3.type == TYPE_ARRAY )
		{
			symbol_table[ident] = TYPE_ARRAY;
			string arrSize = $3.size;
			
			// generate milcode
			// TODO
			string newCode = "\t.[] _" +  ident + ", " + arrSize;
			milcode.push_back (newCode);
		}
		
		// if ident isn't in symbol table and ident is an int
		// add to the symbol table.	
		else if ( it == symbol_table.end() && $3.type == TYPE_INT)
		{
			symbol_table[ident] = TYPE_INT;
			// TODO
			string newCode =  "\t. _" + ident;
			milcode.push_back (newCode);
		}
			
	}
}
	     | ident_loop  array_decl INTEGER 
	       {printf("Syntax error at line %d: invalid declaration\n", currLine);}
         ;


ident_loop: 	iIDENT COMMA ident_loop 
				| iIDENT 
				| IDENT error ident_loop
               	;

iIDENT:		IDENT 
			{ 
				string ident = $1; 
				// check if ident is already in the symbol table
				map <string, int>::iterator it = symbol_table.find (ident);
				
				// if it isn't in symbol table, push ident onto list
				// of idents
				if ( it == symbol_table.end() )
					ident_list.push_back(ident);
				
				// otherwise, why are you redeclaring ident??!?! >:(	
				else
				{
					// TODO:
					cout << "Error at line " << currLine 
						 << ": redeclaration of '" << ident << "'\n";
				}	
			}
			;

/* Here, we might want to set a flag if it's an array or not */
array_decl: 	/*empty */ { $$.type = TYPE_INT; }
              	| ARRAY L_BRACKET NUMBER R_BRACKET OF { $$.type = TYPE_ARRAY; $$.size = $3 }
              	| IDENT NUMBER R_BRACKET OF {printf("Invalid array declaration\n");}
		| ARRAY OF { printf ("Invalid array declaration!\n"); }
		| ARRAY R_BRACKET OF { printf ("Invalid array declaration!\n"); }
		| ARRAY L_BRACKET NUMBER OF { printf ("Invalid array declaration!\n"); }
		| ARRAY L_BRACKET NUMBER R_BRACKET error {}
		| ARRAY L_BRACKET NUMBER error {}
  		;

/* var assign var_branch {$$.code = "hi"} */
statement:	var assign expr 
			{
				string varName = $1.name;
				string exprName = $3.name;
				
				string newCode = "\t= " + varName + ", " + exprName;
				milcode.push_back (newCode);
			} 
			| var assign bool_expr QUESTION expr COLON expr
         	| IF bool_expr THEN if_body ENDIF {}
         	| WHILE bool_expr BEGINLOOP stmt_loop ENDLOOP {}
        	| DO BEGINLOOP stmt_loop ENDLOOP WHILE bool_expr {}
         	| READ var_loop {}
         	| WRITE var_loop {}
         	| BREAK {}
         	| CONTINUE {}
         	| EXIT {}
         	;
         	
assign: ASSIGN 
		| error 
/*		
var_branch:     expr 
                | bool_expr QUESTION expr COLON expr	
                ;
*/
         
var_loop:   var COMMA var_loop 
            | var 
            ;         
                
var:    IDENT 
		{
			string ident = $1; 
			// check if ident is already in the symbol table
			map <string, int>::iterator it = symbol_table.find (ident);
			
			// TODO:	
			if ( it == symbol_table.end() )
			{
				cout << "Error at line " << currLine << ": '" << ident
					 << "' was not declared\n";
			}
			
			strcpy ($$.name, $1);
		}
		
        | IDENT L_BRACKET expr R_BRACKET 
        {
			/*	need to determine if array access or array assignment
				ex: n = array[0] vs array[0] = n;
			*/	
        } 
        ;
        

if_body:    stmt_loop ELSEIF bool_expr elseif_body 
            | stmt_loop ELSE stmt_loop   
            | stmt_loop 
            ;

elseif_body:    stmt_loop ELSEIF bool_expr elseif_body 
                | stmt_loop ELSE stmt_loop 
                | stmt_loop 
                ;   

bool_expr:	relation_and_expr {}
			| relation_and_expr OR bool_expr {}
           	;

relation_and_expr: 	relation_expr {}	
					| relation_expr AND relation_and_expr {}
                    ;

relation_expr:	NOT expr comp expr 
				{
					string expr1_name = $2.name;
					string expr2_name = $4.name;
					
					string bool_op = $3.name;
					
					string predName1 = newPred();
					
					// first, we generate code for "p_n = expr comp expr"
					//genExprCode (dest, src1, src2, OP)
					string newCode = genExprCode (predName1, expr1_name, expr2_name, bool_op);
					milcode.push_back (newCode);
					
					// then, we generate code for "p_(n+1) = NOT p_n"
					string predName2 = newPred();
					newCode = "\t! " + predName2 + predName1;
					milcode.push_back (newCode);
					
					strcpy ($$.name, predName2.c_str());
					
				}
				| NOT TRUE
				{
					// p contains the value of the bool_expr
					// p <- false <- NOT true
					string predName = newPred();
					strcpy ($$.name, predName.c_str());
					
					// ! dest, src
					string newCode = "\t! " + predName + "true";
					milcode.push_back (newCode);
					
				}
				| NOT FALSE
				{	
					// p contains the value of the bool_expr
					// p <- true <- NOT false
					string predName = newPred();
					strcpy ($$.name, predName.c_str());
					
					// ! dest, src
					string newCode = "\t! " + predName + "false";
					milcode.push_back (newCode);
					
				}
				| NOT L_PAREN bool_expr R_PAREN 
				{
					string boolexpr_name = $3.name;
					string predName = newPred();
					strcpy ($$.name, predName.c_str());
					
					string newCode = "\t! " + predName + boolexpr_name;
					milcode.push_back (newCode);
				}
				| expr comp expr 
				{
					string expr1_name = $1.name;
					string expr2_name = $3.name;
					
					string bool_op = $2.name;
					
					string predName = newPred();
					strcpy ($$.name, predName.c_str());
					
					string newCode = genExprCode(predName, expr1_name, expr2_name, bool_op);
					milcode.push_back (newCode);
					
				}
				| TRUE { string temp = "true"; strcpy($$.name, temp.c_str()); }
				| FALSE { string temp = "false"; strcpy ($$.name, temp.c_str()); }
				| L_PAREN bool_expr R_PAREN { strcpy ($$.name, $$.name); }
				| error { printf("Syntax Error: Invalid condition\n"); }
				;

comp:	EQ { string temp = "=="; strcpy($$.name, temp.c_str()); }
     	| NEQ { string temp = "!="; strcpy($$.name, temp.c_str()); }
    	| LT { string temp = "<"; strcpy($$.name, temp.c_str()); }
     	| GT { string temp = ">"; strcpy($$.name, temp.c_str()); }
     	| LTE { string temp = ">="; strcpy ($$.name, temp.c_str()); }
     	| GTE { string temp = "<="; strcpy ($$.name, temp.c_str()); }
     	;

/*
// This does mult first, but subtraction then addition
expr:	mult_expr { $$.name = $1.name; }
		| mult_expr PLUS expr
		{
			string multExprName = $1.name;
			string exprName = $3.name;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, multExprName, exprName, "+");
			milcode.push_back (newCode);
		}
		| mult_expr SUB expr 
		{
			string multExprName = $1.name;
			string exprName = $3.name;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, multExprName, exprName, "-");
			milcode.push_back (newCode);
		}
		;
*/

// This one does mult, add, mult, sub
expr:	mult_expr { strcpy($$.name, $1.name); }
		| expr PLUS mult_expr
		{
			string exprName = $1.name;
			string multExprName = $3.name;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, exprName, multExprName, "+");
			milcode.push_back (newCode);
		}
		| expr SUB mult_expr 
		{
			string exprName = $1.name;
			string multExprName = $3.name;
			
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, exprName, multExprName, "-");
			milcode.push_back (newCode);
		}
		;

mult_expr:	mult_expr MULT term
		{
			string termName = $3.name;
			string mult_exprName = $1.name;
			string tempName = newTemp();
			strcpy($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, mult_exprName, termName, "*");
			milcode.push_back (newCode);
			
		}
		| mult_expr DIV term
		{
			string termName = $3.name;
			string mult_exprName = $1.name;
			string tempName = newTemp();
			strcpy($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, mult_exprName, termName, "/");
			milcode.push_back (newCode);
		}
		| mult_expr MOD term 
		{
			string termName = $3.name;
			string mult_exprName = $1.name;
			string tempName = newTemp();
			strcpy($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode(tempName, mult_exprName, termName, "%");
			milcode.push_back (newCode);
		}
		| term { strcpy($$.name, $1.name); }
		;

term:	SUB var /* same thing as "dst = 0 - var" */
		{ 
			string varName = $2.name;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", varName, "-");
			// milCode = milCode + tempCode;
			milcode.push_back (newCode);
		}
		| SUB NUMBER 
		{
			string varName = $2;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", varName, "-");
			//milCode = milCode + tempCode;
			milcode.push_back (newCode);
		}
		| SUB L_PAREN expr R_PAREN 
		{
			string varName = $3.name;
			string tempName = newTemp();
			strcpy ($$.name, tempName.c_str());
			
			//genExprCode (dest, src1, src2, OP)
			string newCode = genExprCode (tempName, "0", varName, "-");
			// milCode = milCode + tempCode;
			milcode.push_back (newCode);
		}
		| var { strcpy($$.name, $1.name); }
		| NUMBER { strcpy($$.name, $1); }
		| L_PAREN expr R_PAREN { strcpy($$.name, $2.name);}
		;

%%

/*	generates the mil code for the expressions
	dst = src1 OP src2 ----> OP dest, src1, src2
	OP can be '+', '-', '/', etc.
*/
string genExprCode ( string dst, string src1, string src2, string op )
{
	string exprCode = "\t" + op + " " + 
					  dst + ", " + 
					  src1 + ", " +
					  src2;
	return exprCode;
}

/*	generates a new temp variable, tn.
	where n is a number
*/
string newTemp ()
{
	stringstream ss;
	ss << temp_ctr;
	string newTempName = "t" + ss.str();
	temp_ctr++;
	
	return newTempName;
}

/*	generates a new predicate variable, pn.
	where n is a number
*/
string newPred ()
{
	stringstream ss;
	ss << pred_ctr;
	string newPredName = "p" + ss.str();
	pred_ctr++;
	
	return newPredName;
}

int main() {

    yyparse();
    return 0;
}

void yyerror (const char* msg)
{

    printf( "line %d: %s\n", currLine, msg );
//    printf("Syntax error at line %d: \n",currLine, );
//	printf("Syntax error at line %d: \n", currLine, yytext);
}

