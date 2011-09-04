///////////////////////////////////
// Projeto Compiladores - 2011.2 //
// UFCG - DSC			 //	
// Prof.: Franklin Ramalho	 //
// Equipe:			 //
//	Adalberto Teixeira	 //
//	Andrey Menezes		 //
// 	Augusto Macedo		 //
// Ling. Fonte: Java		 //
///////////////////////////////////

//definitions

col_delimit	[ \r\t]
line_delimit	[\n]
zero_digit	[0]
non_zero_digit	[1-9]
digit		{zero_digit}|non_zero_digit
int	       zero_digit*digit
letter          [A-Za-z]

%%
//rules


%%
//user code

