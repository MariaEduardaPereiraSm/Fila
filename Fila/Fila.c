#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Elemento{
    int num;
    struct Elemento *prox;
}Elemento;

typedef struct Fila
{
    struct Elemento *inicio;
    struct Elemento *fim;
    int cont;
}Fila;

Fila* create(){
    Fila* f = (Fila*) malloc(sizeof(Fila));
        f->fim=NULL;
        f->inicio=NULL;
        f->cont=0;
    return f;
}

int verifica(Fila f, int valor){
    while (f.inicio!=NULL)
    {
       if(f.inicio->num==valor){
           return 0;
       }
       f.inicio = f.inicio->prox;
    }
    return 1;
    
}
int contem(Fila f, int valor){
    int v=0;
    while (f.inicio!=NULL)
    {
       if(f.inicio->num==valor){
           printf("O elemento %d já está inserido na fila\n", valor);
           v++;
           break;
       }
       f.inicio = f.inicio->prox;
    }
    if(v==0){
        printf("O elemento %d ainda não foi inserido na fila\n", valor);
    }
    
}
void enqueue(Fila* f, int valor){
    Elemento *NovoNo = (Elemento*) malloc(sizeof(Elemento));
    NovoNo->num = valor;
    NovoNo->prox = NULL;
    if (f->inicio==NULL){ //Se a fila estiver vazia inicio e fim serão iguais
        f->inicio=NovoNo;
        f->fim=NovoNo;
        f->cont++;
    }
    else if(verifica(*f,valor)==1){//caso a pilha ja contenha algum elemento, o novo elemento será sempre inserido no fim da fila
        f->fim->prox = NovoNo;
        f->fim=NovoNo;
        f->cont++;
    }
}

int dequeue(Fila *f){
    if(f->inicio==NULL){
        printf("A fila está vazia\n");
        return -1;
    }
    else{
        Elemento *aux = f->inicio;
        int removido = aux->num;
        f->inicio= f->inicio->prox; 
        f->cont--;
        free(aux);
        return removido;
    }
}
void imprimir(Fila f){
    if(f.inicio==NULL){
        printf("A Filha está vazia\n");
    }else{
        printf("Início -> ");
        while(f.inicio!=NULL){
            printf("%d - ", f.inicio->num);
            f.inicio= f.inicio->prox;
        }
        printf(" Fim :)\n");
    }}
int clonagemdafila(Fila f){
    Fila *FilaClonada = create();
    while(f.inicio!=NULL){
    enqueue(FilaClonada, f.inicio->num);
    f.inicio= f.inicio->prox;
    }
    printf("Cópia da Fila Original: ");
    imprimir(*FilaClonada);
}
int main(){
    Fila *f = create();
    enqueue(f,12);
    enqueue(f,30);
    enqueue(f,70);
    enqueue(f,05);
    imprimir(*f);;
    dequeue(f);
    imprimir(*f);
    clonagemdafila(*f);
    imprimir(*f);
}
