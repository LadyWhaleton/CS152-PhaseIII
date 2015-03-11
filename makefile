all:
	bison -v -d --file-prefix=y mini_l.y
	flex mini_l.lex
	g++ -o myParser y.tab.c lex.yy.c -lfl
	myParser < input.txt > input.mil
	cat input.mil
	
compile:
	bison -v -d --file-prefix=y mini_l.y
	flex mini_l.lex
	g++ -o myParser y.tab.c lex.yy.c -lfl

milcode:
	myParser < input.txt > input.mil
	
mil:
	mil_run primes.mil < input.txt	

Tmail:
	tar -cvf CS152-Phase3.tar .
	echo "body" | mutt -a *.tar -s "CS152 Phase 3" -- twang033@ucr.edu

Smail:
	tar -xvf CS152-Phase3.tar .
	echo "body" | mutt -a *.tar -s "CS152 Phase 3" -- stong002@ucr.edu

tar:
	tar -cvf CS152-Phase3.tar .
	
untar:
	tar -xvf CS152-Phase3.tar .

clean:
	rm lex.yy.c y.output y.tab.c y.tab.h myParser
	
cleantext:
	rm *.txt

cleantar:
	rm *.tar
