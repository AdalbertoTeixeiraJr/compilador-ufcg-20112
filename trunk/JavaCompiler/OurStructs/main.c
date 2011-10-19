#include <stdio.h>
#include "ClassContext.h"

int main(){

	setCurrentContext(CLASS_CONTEXT);

	if (createClassContext("Classe A") != OK){
		printf("Error Class Creation!\n");
	}


	if (insertStringToStrList("a") != OK){
		printf("Error Id1!\n");
	}
	if (insertStringToStrList("b") != OK){
		printf("Error Id2!\n");
	}
	if (insertStringToStrList("c") != OK){
		printf("Error Id3!\n");
	}


	if (insertVarListInGlobalContext("STRING", NO) != OK){
		printf("Error VarList Addition!\n");
	}

	setCurrentContext(METHOD_CONTEXT);

	if(insertMethod("MethodA", "INT") != OK){
		printf("Error Method1!\n");
	}
	if (insertStringToStrList("d") != OK){
		printf("Error Id4!\n");
	}
	insertVarListInCurrMethodContext("DOUBLE", 0);


	if(insertMethod("MethodB", "INT") != OK){
		printf("Error Method2!\n");
	}
	if(insertMethod("MethodC", "INT") != OK){
		printf("Error Method3!\n");
	}

	if (insertStringToStrList("d") != OK){
		printf("Error Id4!\n");
	}
	if (insertStringToStrList("e") != OK){
		printf("Error Id5!\n");
	}
	if (insertStringToStrList("f") != OK){
		printf("Error Id6!\n");
	}

	insertVarListInCurrMethodContext("FLOAT", 1);

	displayClassContext();

	freeClassContext();

	return 0;
}
