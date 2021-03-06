#include <main.h>

//--------------------------------------------------------GET OPT--------------------------------------------------------------
void getOpts(int argc, char **argv, entradaArgumentos_t* input_args) {

	int option = 0;

	while ((option = getopt(argc, argv,"p:g:d:c:smMR:HIF:C:S:h")) != -1) {
		switch (option) {
			case 'p' : 
				nameFiles(&input_args->filePut[0], optarg);
			break;

			case 'g' : 
				nameFiles(&input_args->fileGet[0], optarg);
			break;

			case 'd' : 
				nameFiles(&input_args->fileDelete[0], optarg);
			break;

			case 'c' : 
				nameFiles(&input_args->fileContains[0], optarg);
			break;

			case 'R' : 
				nameFiles(&input_args->fileRank[0], optarg);
			break;

			case 'F' :
				nameFiles(&input_args->fileFloor[0], optarg);
			break;

			case 'C' :
				nameFiles(&input_args->fileCeiling[0], optarg);
			break;

			case 's' :
			case 'm' :
			case 'M' :
			case 'H' :
			case 'I' :
			break;

			case 'S' :
				if (strlen(optarg) <= strlen(VALID_EXEC_OPTIONS) && opValidas(optarg) == true) 
					strcpy(input_args->opts_exec_order, optarg);
				else 
					printf("INVALID -S parameter! Check options (no repetition allowed) and lenght!\n");
			break;

			case 'h':
				helpProg(argv[0]);
				exit(EXIT_SUCCESS);
			break;

			default:
				helpProg(argv[0]);
				exit(EXIT_FAILURE);
			break;

		}
	}
}
