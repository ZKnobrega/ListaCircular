#include <stdio.h>
#include <stdlib.h>



struct elemento{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}


int insere_final(Lista* li, int valor){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->num = valor;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int insere_inicio(Lista* li, int valor){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->num = valor;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insere_lista(Lista* li, int valor){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->num = valor;
    if((*li) == NULL){
        *li = no;
        no->prox = no;
        return 1;
    }
    else{
        if((*li)->num > valor){
            Elem *atual = *li;
            while(atual->prox != (*li))
                atual = atual->prox;
            no->prox = *li;
            atual->prox = no;
            *li = no;
            return 1;
        }
        Elem *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->num < valor){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return 1;
    }
}

int remove_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while(atual->prox != (*li))
        atual = atual->prox;

    Elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;

    if((*li) == (*li)->prox){
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;
    while(no->prox != (*li)){
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista(Lista* li, int valor){
    if(li == NULL)
        return 0;
    if((*li) == NULL)
        return 0;
    Elem *no = *li;
    if(no->num == valor){
        if(no == no->prox){
            free(no);
            *li = NULL;
            return 1;
        }else{
            Elem *ult = *li;
            while(ult->prox != (*li))
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->num != valor){
        ant = no;
        no = no->prox;
    }
    if(no == *li)
        return 0;

    ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do{
        printf("no: %d\n",no->num);
        no = no->prox;
    }while(no != (*li));
}

int consulta_lista(Lista* li, int valor){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;
    while(no->prox != (*li) && no->num != valor)
        no = no->prox;
    if(no->num != valor)
        return 0;
    else{
        return 1;
    }
}

void listar_apartir(Lista * li, int valor){
    if(li == NULL || (*li) == NULL)
        return;

    int aux,no1;
    Elem* no=*li;
    no1 = no;
    aux=no1;
    while(no->prox != (*li) && no->num != valor){
        no = no->prox;}
    if(no->num==valor){
        *li= no;
        imprime_lista(li);
    }
    *li=aux;
}

int main(){
    int valor,insere,tamanho,remover,consulta,opt,opt1,opt2;

    Lista *li=cria_lista();
    do{
    printf("0. Sair:\n");
    printf("1. Listar:\n");
    printf("2. Inserir na lista:\n");
    printf("3. Remover da lista:\n");
    printf("4. Tamanho da lista:\n");
    printf("5. consultar numero na lista:\n");
    printf("6. Listar a partir de um determinado numero:\n");
    printf("opcao:");
    scanf("%i",&opt);
    switch(opt){
        case(0):
        break;
        case(1):
        printf("lista:\n");
        imprime_lista(li);
        break;
        case(2):
            printf("1. Inserir na lista:\n");
            printf("2. Inserir na lista no inicio:\n");
            printf("3. Inserir na lista no final:\n");
            scanf("%d",&opt1);
            switch(opt1){
                case(1):
                    printf("entre com um numero:\n");
                    scanf("%i",&valor);
                    insere= insere_lista(li,valor);
                    printf("inserido com sucesso!\n");
                break;
                case(2):
                    printf("entre com um numero:\n");
                    scanf("%i",&valor);
                    insere= insere_inicio(li,valor);
                    printf("inserido com sucesso!\n");
                break;
                case(3):
                    printf("entre com um numero:\n");
                    scanf("%i",&valor);
                    insere= insere_final(li,valor);
                    printf("inserido com sucesso!\n");
                break;
                default:
                    printf("opicao invalida!\n");
                break;
            }
        break;
        case(3):
            printf("1. Remover numero escolhido:\n");
            printf("2. Remover do inicio:\n");
            printf("3. Remover do final:\n");
            scanf("%d",&opt2);
            switch(opt2){
                case(1):
                    printf("entre com um numero:\n");
                    scanf("%i",&valor);
                    remover= remove_lista(li, valor);
                break;
                case(2):
                    remover = remove_inicio(li);
                    printf("Removido com sucesso!\n");

                break;
                case(3):
                    remover = remove_final(li);
                    printf("Removido com sucesso!\n");
                break;
                default:
                    printf("opicao invalida!\n");
                break;
            }
        break;
        case(4):
            tamanho= tamanho_lista(li);
            printf("Quantidade de elementos da lista:%d\n",tamanho);
        break;
        case(5):
            printf("entre com um numero:\n");
            scanf("%i",&valor);
            consulta = consulta_lista(li, valor);
            if(consulta == 1){
                printf("esta contido na lista\n");
            }
            else{
                printf("nao esta contido na lista\n");
            }
        break;
        case(6):
            printf("entre com um numero:\n");
            scanf("%i",&valor);
            listar_apartir(li,valor);
        break;
        default:
            printf("opicao invalida!\n");
        break;
    }
    }while(opt!=0);
    return 0;
}
