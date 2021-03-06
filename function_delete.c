#include <main.h>

//----------------------------------------------------DELETE--------------------------------------------------------
no_prod_t* delete_produto(no_prod_t* no, unsigned int key_prod){
    if(no==NULL){
    	printf("\nPRODUTO NAO ENCONTRADO!\n");
        //return;
        return NULL;
	}
	else if(key_prod > no->key){
		no->dir=delete_produto(no->dir, key_prod);
	}
	else if(key_prod < no->key){
		no->esq=delete_produto(no->esq, key_prod);
	}
	else if(key_prod == no->key){ //achou o produto
		//elemento sem filhos
		if(no->esq == NULL && no->dir == NULL){
			free(no);
			no=NULL;
		}
		//so tem filhos a direita
		else if (no->esq == NULL){
			no_prod_t* t = no;
			no=no->dir;
			free(t);
		}
		//so tem filhos a esquerda
		else if (no->dir == NULL){
			no_prod_t* t = no;
			no=no->esq;
			free(t);
		}
		//tem os dois filhos
		else {
			no_prod_t* f = no->esq;
			while (f->dir != NULL){
				f=f->dir;
			}
			no->key = f->key;
			f->key = key_prod;
			no->esq = delete_produto(no->esq, key_prod);
		}
	}
	return no;
}

no_cat_t* delete_categoria(no_cat_t *no, unsigned int key_cat, unsigned int key_prod){
    if(no==NULL){
    	printf("\nCATEGORIA NAO ENCONTRADA!\n");
        //return;
        return NULL;
	}
	else if(key_cat > no->key){
		no->dir=delete_categoria(no->dir, key_cat, key_prod);
	}
	else if(key_cat < no->key){
		no->esq=delete_categoria(no->esq, key_cat, key_prod);
	}
	else if(key_cat == no->key){ //achou a categoria
		no->prods=delete_produto(no->prods, key_prod);
	}
	return no;
}
