###################################
## Projeto Compiladores - 2011.2 ##
## UFCG - DSC			 ##	
## Prof.: Franklin Ramalho	 ##
## Equipe:			 ##
##	Adalberto Teixeira	 ##
##	Andrey Menezes		 ##
## 	Augusto Macedo		 ##
## Ling. Fonte: Java		 ##
###################################
###################################
## Makefile:			 ##
## 	- Analise Lexica	 ##
##	- Analise Sintatica	 ##
###################################

CC	= gcc
LEX     = flex
LEX_REPORT  = --report=all --report-file=lex_report.txt
CFLAGS  = -std=gnu99 
LEXICO = lexico

lexico: $(LEXICO).yy
	$(LEX) -o $(LEXICO).c $^
	$(CC) $(CFLAGS) -o $@ -c $(LEXICO).c
