#include <main.h>

// -----------------------------------------  INORDER TRAVERSAL  ------------------------------------------
int inorder_traversal (no_cat_t *no){
    if(no != NULL){
        inorder_traversal(no->esq);
        inorder_busca_produto (no->prods);
        inorder_traversal(no->dir);
    }
}

int inorder_busca_produto (no_prod_t *no){
    if(no != NULL){
    	inorder_busca_produto(no->esq);
    	printf("\nPRODUTO ENCONTRADO!\n");
        printf("Nome: %s\n", no->nome_produto);
        printf("Chave: %d\n", no->key);
        printf("Fabricante: %s\n", no->fabricante);
        printf("Modelo: %s\n", no->modelo);
        printf("Ano: %d\n", no->ano);
        printf("Valor: %f\n", no->valor);
        inorder_busca_produto(no->dir);
    }
}
