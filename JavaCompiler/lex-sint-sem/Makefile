###################################
## Projeto Compiladores - 2011.2 ##
## UFCG - DSC                    ##     
## Prof.: Franklin Ramalho       ##
## Equipe:                       ##
##      Adalberto Teixeira       ##
##      Andrey Menezes           ##
##      Augusto Macedo           ##
## Ling. Fonte: Java             ##
###################################
###################################
## Makefile:                     ##
##      - Analise Lexica         ##
##      - Analise Sintatica      ##
###################################

CC      = gcc
IFLAGS  = -I .
CFLAGS  = -std=gnu99
LEX     = flex
YACC    = bison -y -v
REPORT  = --report=all --report-file=sint-report.txt 
lexico  = lexico
sintatico = sintatico
tk      = tk.h

compiler: $(sintatico).o $(lexico).o
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ -ll -ly

$(lexico).o: $(lexico).yy
	$(LEX) -o $(lexico).c $^
	$(CC) $(CFLAGS) -o $@ -c $(lexico).c

$(sintatico).o: $(sintatico).y
	$(YACC) -t --define=$(tk) $(REPORT) -o$(sintatico).c $^
	$(CC) $(CFLAGS) -o $@ -c $(sintatico).c

clean:
	rm -rf $(lexico).o $(lexico).c $(sintatico).o $(sintatico).c