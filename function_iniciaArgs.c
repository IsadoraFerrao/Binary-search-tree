#include <main.h>

//-----------------------------------------------------INICIA ARGS-------------------------------------------------------------
void iniciaArgs(entradaArgumentos_t* entradaArgs) {
	memset (entradaArgs->opts_exec_order, 0, strlen(VALID_EXEC_OPTIONS)+1);
	memset (entradaArgs->filePut, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileGet, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileDelete, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileContains, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileRank, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileFloor, 0, MAX_FILE_NAME_SIZE);
	memset (entradaArgs->fileCeiling, 0, MAX_FILE_NAME_SIZE);
}
