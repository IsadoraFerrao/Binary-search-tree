#include <main.h>

// -----------------------------------------  CEILLING  ------------------------------------------
int c_ceiling(no_cat_t* no, int key_cat, int key_prod){
	if (no==NULL){
		printf("ARVORE NAO ENCONTRADA!\n");
		return -1;
	}
	else if (key_cat > no->key){
		c_ceiling(no->dir, key_cat, key_prod);
	}
	else if (key_cat < no->key){
		c_ceiling(no->esq, key_cat, key_prod);
	}
	else if (key_cat == no->key){
		p_ceiling(no->prods, key_prod);
		return 1;
	}
	return 0;
}

int p_ceiling(no_prod_t* no, int key_prod){
	if (no==NULL){
		printf("ELEMENTO NAO ENCONTRADO!\n");
		return -1;
	}
	else if (key_prod > no->key){
		p_ceiling(no->dir, key_prod);
	}
	else if (key_prod < no->key){
		p_ceiling(no->esq, key_prod);
	}
	else if (key_prod == no->key){
		printf("\nELEMENTO CEILING ENCONTRADO!\n");
		printf("Nome: %s\n", no->nome_produto);
		printf("Chave: %d\n", no->key);
		printf("Fabricante: %s\n", no->fabricante);
		printf("Modelo: %s\n", no->modelo);
		printf("Ano: %d\n", no->ano);
		printf("Valor: %f\n", no->valor);	
		return 1;
	}
	return 0;
}
