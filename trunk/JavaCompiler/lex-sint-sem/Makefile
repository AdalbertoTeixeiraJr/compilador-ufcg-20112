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
REPORT  = --report=all --report-file=report.txt 
lexico  = lexico
sintatico = sintatico
tk      = tk.h

java_compiler: $(sintatico) $(lexico)
	$(CC) $(CFLAGS) $(IFLAGS) -o $@ $^ -ll -ly

$(lexico): $(lexico).yy
	$(LEX) -o $(lexico).c $^
	$(CC) $(CFLAGS) -o $@ -c $(lexico).c

$(sintatico): $(sintatico).y
	$(YACC) -t --define=$(tk) $(REPORT) -o$(sintatico).c $^
	$(CC) $(CFLAGS) -o $@ -c $(sintatico).c

clean:
	rm -rf $(lexico) $(lexico).c $(sintatico) $(sintatico).c java_compiler report.txt
