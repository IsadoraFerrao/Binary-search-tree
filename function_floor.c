#include <main.h>

// ------------------------------------------  FLOOR  -------------------------------------------
int c_floor(no_cat_t* no, int key_cat, int key_prod){
	if (no==NULL){
		printf("ARVORE NAO ENCONTRADA!\n");
		return -1;
	}
	else if (key_cat > no->key){
		c_floor(no->dir, key_cat, key_prod);
	}
	else if (key_cat < no->key){
		c_floor(no->esq, key_cat, key_prod);
	}
	else if (key_cat == no->key){
		p_floor(no->prods, key_prod);
		return 1;
	}
	return 0;
}

int p_floor(no_prod_t* no, int key_prod){
	if (no==NULL){
		printf("ELEMENTO NAO ENCONTRADO!\n");
		return -1;
	}
	else if (key_prod > no->key){
		p_floor(no->dir, key_prod);
	}
	else if (key_prod < no->key){
		p_floor(no->esq, key_prod);
	}
	else if (key_prod == no->key){
		printf("\nELEMENTO FLOOR ENCONTRADO!\n");
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
