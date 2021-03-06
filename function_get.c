#include <main.h>

//---------------------------------------------------------GET---------------------------------------------------------------------
void busca_produto (no_prod_t *no, unsigned int key_prod){
    if(no == NULL){
        printf("\nPRODUTO NAO ENCONTRADO!\n");
        return;
    }
    else if(no->key == key_prod){
    	printf("\nPRODUTO ENCONTRADO!\n");
        printf("Nome: %s\n", no->nome_produto);
        printf("Chave: %d\n", no->key);
        printf("Fabricante: %s\n", no->fabricante);
        printf("Modelo: %s\n", no->modelo);
        printf("Ano: %d\n", no->ano);
        printf("Valor: %f\n", no->valor);
        return;
    }
    else{
        if(key_prod > no->key){
            busca_produto(no->dir, key_prod);
        }
        else if(key_prod < no->key){
            busca_produto(no->esq, key_prod);
        }
    }
}

void busca_categoria (no_cat_t *no, unsigned int key_cat, unsigned int key_prod){
    if(no == NULL){
        printf("\nCATEGORIA NAO ENCONTRADA!\n");
        return ;
    }
    else if(no->key == key_cat){
    	printf("\nCATEGORIA ENCONTRADA!\n");
        printf("Nome: %s\n", no->nome_categoria);
        printf("Codigo: %d\n", no->key);
        busca_produto(no->prods, key_prod);
        return;
    }
    else{
        if(key_cat > no->key){
            busca_categoria(no->dir, key_cat, key_prod);
        }
        else if(key_cat < no->key){
            busca_categoria(no->esq, key_cat, key_prod);
        }
    }
}
