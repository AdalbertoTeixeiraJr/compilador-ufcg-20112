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
		puts("Error Class Creation!");
	}

	if (addStringToNode(getClassContext(), id1) != OK){
		puts("Error Id1!");
	}
	if (addStringToNode(getClassContext(), id2) != OK){
		puts("Error Id2!");
	}
	if (addStringToNode(getClassContext(), id3) != OK){
		puts("Error Id3!");
	}
	if (addStringToNode(getClassContext(), id4) != OK){
		puts("Error Id4!");
	}
	if (addStringToNode(getClassContext(), id5) != OK){
		puts("Error Id5!");
	}


	if (addVarListInContext(getClassContext(), typeval1, NO) != OK){
		puts("Error Context Addition!");
	}


	displayAllVarsOfContext(getClassContext());

	return 0;
}
