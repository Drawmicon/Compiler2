
lexer: lexer1.lex main.c
	flex lexer1.lex
	gcc lex.yy.c -o flexo -ll
	./flexo flexoInput.txt
	
bison: lexer1.lex Parser_project.y main.c 
	bison -d Parser_project.y
	flex  -o lex.yy.c lexer1.lex
	gcc -o $@ Parser_project.tab.c lex.yy.c main.c -w
	
clean:
	clear
	rm -f flexo bison lex.yy.c Parser_project.tab.c Parser_project.tab.h
	ls -l


