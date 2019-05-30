#include <main.h>

//-----------------------------------------------------MAX----------------------------------------------------------------
int cat_maximo(no_cat_t* no){
	if(no != NULL){
		cat_maximo(no->esq);
    		printf("CATEGORIA:%s - Chave[%d]\nELEMENTO MAXIMO: %d\n\n", no->nome_categoria, no->key, prod_maximo(no->prods));
    		cat_maximo(no->dir);
	}
}

int prod_maximo(no_prod_t* no){
	if(no!=NULL){
		while( no->dir != NULL){
			no = no->dir;
		}
	}
	return no->key;
}
