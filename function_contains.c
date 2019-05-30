#include <main.h>

//------------------------------------------------------------CONTAINS----------------------------------------------------------------
int contains_produto(no_prod_t* no, unsigned int key_prod){
	if (no==NULL){
		printf("\nPRODUTO NAO ENCONTRADO - NAO ESTA CONTIDO NA ARVORE!\n");
		//return;
		return -1;
	}
	else if (key_prod > no->key){
		contains_produto(no->dir, key_prod);
	}
	else if (key_prod < no->key){
		contains_produto(no->esq, key_prod);
	}
	else if (key_prod == no->key){
		printf("\nPRODUTO ENCONTRADO - ESTA CONTIDO NA ARVORE!\n");
		//return;
		return 1;
	}
	return 0;
}

int contains_categoria(no_cat_t* no, unsigned int key_cat, unsigned int key_prod){
	if (no==NULL){
		printf("\nCATEGORIA NAO ENCONTRADA!\n");
		//return;
		return -1;
	}
	else if (key_cat > no->key){
		contains_categoria(no->dir, key_cat, key_prod);
	}
	else if (key_cat < no->key){
		contains_categoria(no->esq, key_cat, key_prod);
	}
	else if (key_cat == no->key){
		printf("\nCATEGORIA ENCONTRADA - ESTA CONTIDA NA ARVORE!\n");
		contains_produto(no->prods, key_prod);
		//return;
		return 1;
	}
	return 0;
}
