#include <main.h>

//----------------------------------------------------------- HEIGHT --------------------------------------------------------------------------
int c_height(no_cat_t *no) {
	if (no != NULL) {
		c_height(no->esq);
        printf("Categoria[%d] possui Altura %d\n", no->key, p_height(no->prods));
        c_height(no->dir);
	}
}

int p_height(no_prod_t *no) {
	if (no == NULL){
		return -1;
	} 
	else {
		int he = p_height(no->esq);
		int hd = p_height(no->dir);
		if (he < hd){
			return hd + 1;
		}
		else{
			return he + 1;
		}
	}
}
