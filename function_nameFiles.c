#include <main.h>

//-----------------------------------------------------NAME FILES--------------------------------------------------------------
void nameFiles(char *string, char *data) {
	if (strlen(data) < MAX_FILE_NAME_SIZE) {
		strcpy (string, data);
	} else {
		printf("ERROR: file name \"%s\" is too long! Max # of chars equals %d!\n", data, MAX_FILE_NAME_SIZE);
	}
}
