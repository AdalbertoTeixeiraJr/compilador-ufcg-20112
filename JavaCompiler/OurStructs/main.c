#include <stdio.h>
#include "ourStructs.h"

int main(){

	if (createClassContext("Classe A") != OK){
		printf("Error Class Creation!\n");
	}


	if (insertStringToStrList("a") != OK){
		printf("Error Id1!\n");
	}
	if (insertStringToStrList("a") != OK){
		printf("Error Id2!\n");
	}
	if (insertStringToStrList("c") != OK){
		printf("Error Id3!\n");
	}


	if (insertVarListInClassContext("STRING", NO) != OK){
		printf("Error VarList Addition!\n");
	}


	if(insertMethodInClassContext("MethodA", "INT") != OK){
		printf("Error Method1!\n");
	}
	if(insertMethodInClassContext("MethodA", "INT") != OK){
		printf("Error Method2!\n");
	}
	if(insertMethodInClassContext("MethodC", "INT") != OK){
		printf("Error Method3!\n");
	}

	displayClassContext();

	return 0;
}
