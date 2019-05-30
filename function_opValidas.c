#include <main.h>

//------------------------------------------------------OP VALIDAS-------------------------------------------------------------
bool opValidas(char *ops) {
	int i, j;
	char valid_ops[strlen(VALID_EXEC_OPTIONS)+1];
	char repeated_ops[strlen(VALID_EXEC_OPTIONS)+1];
	bzero(valid_ops, strlen(VALID_EXEC_OPTIONS)+1);
	bzero(repeated_ops, strlen(VALID_EXEC_OPTIONS)+1);
	strcpy (valid_ops, VALID_EXEC_OPTIONS);
	for (i = 0; i < strlen(ops); i++) {
		for (j = 0; j < strlen(VALID_EXEC_OPTIONS); j++) {
			if (ops[i] == valid_ops[j]) {
				if (repeated_ops[j] != '1')
					repeated_ops[j] = '1';
				else 
					return false;
				break;
			}
		}
		if (j >= strlen(VALID_EXEC_OPTIONS))
			return false;
	}
	return true;
}
