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
tk      = tokens.h
structs = OurStructs
constants = OurConstants
context = ClassContext

java_compiler: $(constants) $(structs) $(context) $(lexico) $(sintatico) 
	$(CC) -o $@ $(constants).c $(structs).c $(context).c $(lexico).c $(sintatico).c  

$(lexico): $(lexico).yy
	$(LEX) -o$(lexico).c $^
	$(CC) -o $@ -c $(lexico).c

$(sintatico): $(sintatico).y
	$(YACC) -t --define=$(tk) $(REPORT) -o$(sintatico).c $^
	$(CC) -o $@ -c $(sintatico).c

$(structs):
	$(CC) -o $@ -c $(structs).c

$(context):
	$(CC) -o $@ -c $(context).c 

$(constants):
	$(CC) -o $@ -c $(constants).c

clean:
	rm -rf $(lexico) $(lexico).c $(sintatico) $(sintatico).c $(structs) $(constants) $(context) java_compiler report.txt sintatico.output *~

remake: clean java_compiler
	
