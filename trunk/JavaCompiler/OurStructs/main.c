#include <stdio.h>
#include "ourStructs.h"

int main(){

	char * className = "Classe A";
	char * id1 = "1";
	char * typeval1 = "STRING";

	if (createClassContext(className) != OK){
		puts("Error!");
	}

	if (addVarInContext(getClassContext(), id1, typeval1) != OK){
		puts("Error!");
	}

	displayValuesByNode(getClassContext(), "1");

	return 0;
}
