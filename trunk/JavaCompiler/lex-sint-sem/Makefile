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
LEX     = flex
YACC    = bison -y -v
REPORT  = --report=all 
lexico  = lexico
sintatico = sintatico
tk      = tk.h

java_compiler: $(lexico) $(sintatico)
	$(CC) -o$@ $^  

$(lexico): $(lexico).yy
	$(LEX) -o$(lexico).c $^
	$(CC) -o $@ -c $(lexico).c

$(sintatico): $(sintatico).y
	$(YACC) -t --define=$(tk) $(REPORT) -o$(sintatico).c $^
	$(CC) -o $@ -c $(sintatico).c

clean:
	rm -rf $(lexico) $(lexico).c $(sintatico) $(sintatico).c java_compiler report.txt sintatico.output *~
