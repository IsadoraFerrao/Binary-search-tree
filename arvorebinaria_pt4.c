#include <main.h>

//----------------------------------------------------------FUNÇÃO MAIN---------------------------------------------------------
int main(int argc, char **argv){
	no_cat_t* raiz = NULL;
	entradaArgumentos_t getArgs;
	char fabricante[128], nome_produto[128], modelo[128], nome_categoria[128];
	char option, ordem;
	float valor;
	int key_prod, key_cat, ano, i=0;
	int chave_cat, chave_prod, inorder, sair=1, resp_rank;
	FILE *entrada, *saida, *filePut, *fileget, *filedelete, *filerank, *filefloor, *fileceiling, *filecontains;
	FILE *exe_time;
	struct timeval inicio, final; 	//Para medir o tempo
	double total;			//Para medir o tempo
	
	if(argc<2){
		printf("Argumentos insuficientes!\n");
		printf("Digite para executar:\n %s <-p -g -d -c -s -m -M -R -H -I -F -C -S -h>\n", argv[0]);
		exit(-1);
	}
	
	exe_time=fopen("01_Tempos_de_execucao.dat", "w");
	
	iniciaArgs(&getArgs);
	getOpts(argc,argv,&getArgs);
	while (i < strlen(getArgs.opts_exec_order)) {
		ordem = getArgs.opts_exec_order[i];
		i++;
		switch (ordem) {
			case 'p':
				//PARA TESTAR A PUT
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.filePut, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.filePut);
					exit(-1);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u; %[^;]; %[^;]; %u; %f[^\n]",nome_categoria, &key_cat, nome_produto, &key_prod, fabricante, modelo, &ano, &valor)!=EOF){
						raiz=inserir_categoria(raiz, key_cat, nome_categoria, key_prod, nome_produto, fabricante, modelo, ano, valor);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Put\t\t%4lf\n", (total/1000000));
				break;
				
			case 'g':
				//PARA TESTAR A GET
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
	 			entrada = fopen(getArgs.fileGet, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileGet);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
						busca_categoria(raiz, key_cat, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Get\t\t%4lf\n", (total/1000000));
				break;
				
			case 'd':
				//PARA TESTAR A DELETE
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.fileDelete, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileDelete);
					exit(-1);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
						raiz=delete_categoria(raiz, key_cat, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Delete\t\t%4lf\n", (total/1000000));
	 			break;
				
			case 'c':
				//PARA TESTAR A CONTAINS
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.fileContains, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileContains);
					exit(-1);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
						contains_categoria(raiz, key_cat, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Contains\t%4lf\n", (total/1000000));
				break;
				
			case 's':
				//PARA TESTAR SIZE 
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				cat_size(raiz);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Size\t\t%4lf\n", (total/1000000));
				break;
				
			case 'm':
				//PARA TESTAR MINIMO
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				cat_minimo(raiz);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Minimo\t\t%4lf\n", (total/1000000));
				break;
				
			case 'M':
				//PARA TESTAR MÁXIMO
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				cat_maximo(raiz);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Maximo\t\t%4lf\n", (total/1000000));	
				break;
				
			case 'R':
				//PARA TESTAR A RANK
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.fileRank, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileRank);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
	 					resp_rank=rank_categoria(raiz, key_prod);
						printf("Ha %d elementos antes da chave %d!\n",resp_rank, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Rank\t\t%4lf\n", (total/1000000));
	 			break;
				
			case 'H':
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				//PARA TESTAR HEIGHT
				c_height(raiz);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Height\t\t%4lf\n", (total/1000000));
				break;

			case 'I':
				//PARA TESTAR INORDER
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				inorder_traversal(raiz);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Inorder\t\t%4lf\n", (total/1000000));
				break;
				
			case 'F':
				//PARA TESTAR FLOOR
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.fileFloor, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileFloor);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
		 				c_floor(raiz, key_cat, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Floor\t\t%4lf\n", (total/1000000));
	 			break;
			
			case 'C':
				//PARA TESTAR CEILING
				gettimeofday(&inicio, NULL);//Captura o tempo de inicio
				entrada = fopen(getArgs.fileCeiling, "r");
				if(entrada == NULL) {
					printf("ERRO na abertura do arquivo %s!\n", getArgs.fileCeiling);
				}else {
					while(fscanf(entrada, "%[^;]; %u; %[^;]; %u;", nome_categoria, &key_cat, nome_produto, &key_prod)!=EOF){
		 				c_ceiling(raiz, key_cat, key_prod);
					}
				}
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
			 	fprintf(exe_time, "Ceiling\t\t%4lf\n", (total/1000000));
	 			break;

			case 'h':
				//PARA MOSTRAR AJUDA
				helpProg(argv[0]);
				gettimeofday(&final, NULL);//Captura o tempo do final
 				total = (((final.tv_sec - inicio.tv_sec)*1000000) + (final.tv_usec - inicio.tv_usec));
				break;
				
			default:
				printf("OPERACAO INVALIDA!\n\n ");
				break;
		}
	}
	fclose(exe_time);
	system("gnuplot 01_grafico.gnu");
}
