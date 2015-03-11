/* Name: Tina Wang
 * Partner's Name: Stephanie Tong
 * Project Name: Lexical Analyzer Generation Using flex
 * Project Description: We created the specifications of a lexical analyzer
 * for the Mini-L language.
 * Quarter: Winter 2015
 * Class: CS152
 * Lab Section: Section 21
 * My partner and I agree that this is our own original work.
 * 
 */

%{
    #include "y.tab.h"
    #include <string.h>
    
    int currLine = 1, currPos = 1;
    
%}

Letter [a-zA-Z]
Digit [0-9]
Underscore [_]
Ident {Letter}((({Letter}|{Digit})|{Underscore})*({Letter}|{Digit})+)*
Number ({Digit})+
Comment [#]{2}(.)*[\n]
badIdent1 {Digit}{Letter}(({Letter}|{Digit}{Underscore})*({Letter}|{Digit})+)*
badIdent2 {Letter}(({Letter}|{Digit}{Underscore})*({Letter}|{Digit})+)*{Underscore}

%%
" "                {currPos+=yyleng;}
"\n"               {currLine++; currPos = 1;}
"\t"               {currPos+=yyleng;}
"program"          {currPos+=yyleng; return PROGRAM; }
"beginprogram"     {currPos+=yyleng; return BEGIN_PROGRAM; }
"endprogram"       {currPos+=yyleng; return END_PROGRAM; }
"integer"          {currPos+=yyleng; return INTEGER; }
"array"            {currPos+=yyleng; return ARRAY; }
"of"               {currPos+=yyleng; return OF; }
"if"               {currPos+=yyleng; return IF; }
"then"             {currPos+=yyleng; return THEN; }
"endif"            {currPos+=yyleng; return ENDIF;}
"else"             {currPos+=yyleng; return ELSE; }
"elseif"           {currPos+=yyleng; return ELSEIF; }
"while"            { currPos+=yyleng; return WHILE; }
"do"               { currPos+=yyleng; return DO; }
"beginloop"        { currPos+=yyleng; return BEGINLOOP;} 
"endloop"          { currPos+=yyleng; return ENDLOOP;} 
"break"            { currPos+=yyleng; return BREAK; }
"continue"         { currPos+=yyleng; return CONTINUE;}
"exit"             { currPos += yyleng; return EXIT; }
"read"             { currPos += yyleng; return READ; }
"write"            { currPos += yyleng; return WRITE; }
"and"              { currPos += yyleng; return AND; }
"or"               { currPos += yyleng; return OR; }
"not"              { currPos += yyleng; return NOT; }
"true"             { currPos += yyleng; return TRUE; }
"false"            { currPos += yyleng; return FALSE; }
"-"                { currPos += yyleng; return SUB; }
"+"                { currPos += yyleng; return PLUS; }
"*"                { currPos += yyleng; return MULT; }
"/"                { currPos += yyleng; return DIV;}
"%"                { currPos += yyleng; return MOD; }
"=="               { currPos += yyleng; return EQ; }
"<>"               { currPos += yyleng; return NEQ; }
"<"                { currPos += yyleng; return LT; }
">"                { currPos += yyleng; return GT; }
"<="               { currPos += yyleng; return LTE; }
">="               { currPos += yyleng; return GTE; }
";"                { currPos += yyleng; return SEMICOLON;}
":"                { currPos += yyleng; return COLON; }
","                { currPos += yyleng; return COMMA; }
"?"                { currPos += yyleng; return QUESTION; }
"["                { currPos += yyleng; return L_BRACKET; }
"]"                { currPos += yyleng; return R_BRACKET; }
"("                { currPos += yyleng; return L_PAREN; }
")"                { currPos += yyleng; return R_PAREN; }
":="               { currPos += yyleng; return ASSIGN; }
{Ident}            { currPos += yyleng; yylval.String = new char[yyleng +1];
		     strcpy (yylval.String, yytext); return IDENT; }
{Number}           { currPos += yyleng; yylval.IntString = new char[yyleng+1]; 
		     strcpy (yylval.IntString, yytext); return NUMBER;}
{Comment}  	   { currPos = 1; currLine++;}
{badIdent1}        { printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter.\n", currLine, currPos, yytext);}          
{badIdent2}        { printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext);}      
.                  { printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n",currLine, currPos, yytext); } 
%%

/*
main(int argc, char**argv)
{
    yylex();
}
*/
