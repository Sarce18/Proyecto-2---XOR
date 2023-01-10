#ifndef HEAD_H_
#define HEAD_H_
#include <stdbool.h>

// Node structure of a memory  
// efficient doubly linked list 
typedef struct Node {
    int data;
    struct Node* npx; /* XOR of next and previous node */
}node;

typedef struct FL {
    struct Node* first;
    struct Node* last;
}list;

/* returns XORed value of the node addresses */
node* XOR(node* a, node* b);

node* newnode(int data);
//operaciones

list* crearLista();

bool esVacia(list* lista);

bool inicializar(list* lista);

bool sacarPrincipio(list* lista, int* e);

bool sacarFinal(list* lista, int* e);

bool sacarPrimeraOcurrencia(list* lista, int data);

bool insertarPrincipio(list* lista, int data);

bool insertarFinal(list* lista, int data);

bool insertarOrden(list* lista, int data);

bool buscar(list* lista, int data);

void listarInicioAFinal(list* lista);

void listarFinalAInicio(list* lista);

int cantidadElementos(list* lista);

#endif
