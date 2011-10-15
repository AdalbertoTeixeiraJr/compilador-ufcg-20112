#include <stdio.h>
#include "ourStructs.h"

int main(){

	char * className = "Classe A";
	char * id1 = "a";
	char * id2 = "b";
	char * id3 = "c";
	char * id4 = "d";
	char * id5 = "e";

	char * typeval1 = "STRING";

	if (createClassContext(className) != OK){
		puts("Error!");
	}

	StrNode * strList = createStrNode(getClassContext(), id1);
	addStringToNode(getClassContext(), strList, id2);
	addStringToNode(getClassContext(), strList, id3);
	addStringToNode(getClassContext(), strList, id4);
	addStringToNode(getClassContext(), strList, id5);

	if (addVarListInContext(getClassContext(), strList, typeval1, NO) != OK){
		puts("Error!");
	}

	displayAllVarsOfContext(getClassContext());

	return 0;
}
