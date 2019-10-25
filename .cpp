#include <iostream>
#include <stdlib.h>
using namespace std;

struct elemento{
    int num;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

Lista* cria_lista(){
    Lista* li = new Lista;
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

void imprime_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do{
        cout << "no:\n" << no->num;
        no = no->prox;
    }while(no != (*li));
}
void listar_apartir(Lista * li, int valor){
    if(li == NULL || (*li) == NULL)
        return;

    Elem* aux;
    Elem* no1;
    Elem* no = *li;
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
    cout << "0 - Sair\n1 - Listar\n2 - Inserir na lista\n3 - Remover da lista\n4 - Tamanho da lista/n5 - consultar numero na lista\n6 - Listar a partir de um determinado numero\n";
    cout << "opcao:";
    cin >> opt;
    switch(opt){
        case(0):
        break;

        case(1):
        cout << "lista:\n" << endl;
        imprime_lista(li);
        break;

        case(2):
            cout << "1. Inserir na lista:\n2. Inserir na lista no inicio:\n3. Inserir na lista no final:\n";
            cin >> opt1;
            switch(opt1){
                case(1):
                    cout << "entre com um numero:\n" << endl;
                    cin >>valor;
                    insere= insere_lista(li,valor);
                    cout << "inserido com sucesso!\n" << endl;
                break;
                case(2):
                    cout << "entre com um numero:\n" << endl;
                    cin >> valor;
                    insere= insere_inicio(li,valor);
                    cout << "inserido com sucesso!\n" << endl;
                break;
                case(3):
                    cout << "entre com um numero:\n" << endl;
                    cin >> valor;
                    insere= insere_final(li,valor);
                    cout << "inserido com sucesso!\n" << endl;
                break;
                default:
                    cout << "opicao invalida!\n" << endl;
                break;
            }
        break;

        case(3):
            cout << "1. Remover numero escolhido:\n2. Remover do inicio:\n3. Remover do final:\n" << endl;
            cin >> opt2;
            switch(opt2){
                case(1):
                    cout << "entre com um numero:\n" << endl;
                    cin >> valor;
                    remover= remove_lista(li, valor);
                break;
                case(2):
                    remover = remove_inicio(li);
                    cout << "Removido com sucesso!\n" << endl;

                break;
                case(3):
                    remover = remove_final(li);
                    cout << "Removido com sucesso!\n" << endl;
                break;
                default:
                    cout << "opicao invalida!\n" << endl;
                break;
            }
        break;

        case(4):
            tamanho= tamanho_lista(li);
            cout << "Quantidade de elementos da lista:%d\n" << tamanho << endl;
        break;

        case(5):
            cout << "entre com um numero:\n";
            cin >> valor;
            consulta = consulta_lista(li, valor);
            if(consulta == 1){
                cout << "esta contido na lista\n";
            }
            else{
                cout << "nao esta contido na lista\n";
            }
        break;

        case(6):
            cout << "entre com um numero:\n";
            cin >> valor;
            listar_apartir(li,valor);
        break;

        default:
            cout << "opição invalida!\n";
        break;
    }
    }while(opt!=0);
    return 0;
}
