#include <stdio.h>
#include <stdlib.h>/*Sabemos que a fila sequencial utiliza um vetor, e é circular porque caso hajá espaço a esquerda dos valores, 
o novo elemtno será inserido ali */
#define MAX 5
typedef struct Fila { //Estrutura da Fila
	int elementos[ MAX ]; // vetor que vai armazenar os elementos
	int frente; // variável usada para controlar o início da fila
    int final; // variável usada para controlar o final da fila
    int tam;  // número de elementos na fila
}Fila;


/* Criar uma fila sequencial circular vazia
*/
Fila *create () {
    Fila *f = (Fila*) malloc(sizeof(Fila));
	f->frente = 0; 
	f->final  = -1; // condição de fila vazia
	f->tam    = 0;  // condição de fila vazia
}

/* Verificar se a fila está (ou não) vazia
 * Parâmetros: a fila (uma struct) passada por referência
 */
int filaVazia (Fila *f ){ 

    return f->tam == 0; }

/* Verificar se a fila está (ou não) cheia
 * Parâmetros: a fila (uma struct) passada por referência
 */
int filaCheia (Fila *f ){ 
    return f->tam == MAX; }

/* Consultar o elemento que se encontra na frente da fila
 * Parâmetros: a fila passada por referência e um 
 * ponteiro "de retorno" que guardará o "elemento-frente" consultado
 */
int elementoFrente (Fila *f, int valor ){
	// se fila está vazia 
if ( filaVazia( f) ) return 0;
	valor = f->elementos[ (f->frente) ];
	return 1;
}

/* Enfileirar um elemento na fila 
 * Parâmetros: a fila passada por referência e um elemento qualquer
 */
int enfileira (Fila *f, int elemento ){
	// se fila está cheia
	if ( filaCheia( f ) )return 0;
   
	(f->tam)++;
	f->final = (f->final + 1) % MAX;
    f->elementos[ f->final ] = elemento;
	return 1;
} 

/* Retirar (desenfileirar) um elemento da fila 
 * Parâmetros: a fila passada por referência e um 
 * ponteiro "de retorno" que guardará o elemento retirado
 */
int desenfileiraa (Fila *f, int valor ) {
   	if ( !elementoFrente( f, valor ) ) return 0;

	(f->tam)--;
	f->frente = (f->frente + 1) % MAX;
    return 1;
}

/* Imprimir o contéudo da fila sequencial circular
 * Parâmetros: a fila (uma struct) passada por referência
 */
void imprima (Fila *f ) {
    printf("\nFila = [ ");

	// varrendo todos os elementos
	for ( int i = 1, aux = f->frente;
	                  i <= f->tam; i++, aux = (aux + 1) % MAX )
		printf( "%d ", f->elementos[ aux ] );

    printf( "]" );
}
int main(){
    Fila *f = create();
    enfileira(f,10);
    enfileira(f, 18);
    enfileira(f,12);
    enfileira(f, 20);
    enfileira(f, 30);
    imprima(f);
    desenfileiraa(f,10);
    imprima(f);
    enfileira(f,200);
    imprima(f);

}