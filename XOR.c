#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdbool.h>
#include "XOR.h"

// devuelve el valor XOR de las direcciones de los nodos
node *XOR(node *a, node *b)
{
    return (node *)((uintptr_t)a ^ (uintptr_t)b);
}

// funcion para crear un nuevo nodo

node *newnode(int data)
{
    node *new_node;
    if ((new_node = (node *)malloc(sizeof(node))) == NULL)
    {
        fprintf(stderr, "Error en malloc.");
        return NULL;
    }

    // asignar valor dado
    new_node->data = data;

    return new_node;
}

// operaciones

list *crearLista()
{
    list *lista = (list *)malloc(sizeof(list));
    lista->first = lista->last = NULL;
    return lista;
}

bool esVacia(list *lista)
{
    if (lista->first == NULL)
        return true;
    return false;
}

bool inicializar(list *lista)
{

    // se verifica si la lista esta vacia
    if (esVacia(lista))
        return false;

    // se recorre la lista y se va realizando free
    while (lista->first->npx)
    {
        node *prev = lista->first;
        lista->first = lista->first->npx;
        lista->first->npx = XOR(prev, lista->first->npx);
        free(prev);
    }

    free(lista->first);

    lista->last = lista->first = NULL;

    return true;
}

bool sacarPrincipio(list *lista, int *e)
{
    if (esVacia(lista))
        return false;

    *e = lista->first->data;

    if (lista->first == lista->last)
    {
        free(lista->first);
        lista->first = lista->last = NULL;
        return true;
    }

    node *prev = lista->first;

    lista->first = lista->first->npx;

    lista->first->npx = XOR(prev, lista->first->npx);

    free(prev);

    return true;
}

bool sacarFinal(list *lista, int *e)
{
    if (esVacia(lista))
        return false;

    *e = lista->last->data;

    if (lista->first == lista->last)
    {
        free(lista->last);
        lista->first = lista->last = NULL;
        return true;
    }

    node *prev = lista->last;

    lista->last = lista->last->npx;

    lista->last->npx = XOR(prev, lista->last->npx);

    free(prev);

    return true;
}

bool sacarPrimeraOcurrencia(list *lista, int data)
{

    // se verifica si la lista esta vacia
    if (esVacia(lista))
        return false;

    // si el dato esta en el primer nodo de la lista
    if (lista->first->data == data)
        return sacarPrincipio(lista, &data);

    node *curr = lista->first;
    node *prev = NULL;
    node *next;

    // se recorre la lista

    while (curr != NULL)
    {

        if (curr->data == data)
        {

            node *curr_next = XOR(curr->npx, prev);

            prev->npx = XOR(XOR(prev->npx, curr), curr_next);

            if (curr_next != NULL)
                curr_next->npx = XOR(XOR(curr_next->npx, curr), prev);
            else
                lista->last = prev;
            return true;
        }

        next = XOR(prev, curr->npx);

        // Se actualizan prev y curr
        prev = curr;
        curr = next;
    }

    return false;
}

bool insertarPrincipio(list *lista, int data)
{

    // nuevo nodo
    node *new_node = newnode(data);

    // si es vacía, el nuevo nodo será el primero y el último
    if (esVacia(lista))
    {
        lista->first = lista->last = new_node;
        new_node->npx = NULL;
        return true;
    }

    // Se le asigna la cabeza al nuevo nodo
    new_node->npx = lista->first;

    // el nodo que se encontraba al principio pasa a ser el siguiente
    lista->first->npx = XOR(new_node, XOR(lista->first->npx, NULL));

    // nuevo primer elemento
    lista->first = new_node;

    return true;
}

bool insertarFinal(list *lista, int data)
{

    // nuevo nodo
    node *new_node = newnode(data);

    // si es vacía, el nuevo nodo será el primero y el último
    if (esVacia(lista))
    {
        lista->first = lista->last = new_node;
        new_node->npx = NULL;
        return true;
    }

    // Se le asigna la cola al nuevo nodo
    new_node->npx = lista->last;

    // el nodo que se encontraba al final pasa a ser el anterior
    lista->last->npx = XOR(XOR(NULL, lista->last->npx), new_node);

    // nuevo último elemento
    lista->last = new_node;

    return true;
}

bool insertarOrden(list *lista, int data)
{
    node *new_node = newnode(data);

    if (esVacia(lista))
    {
        new_node->npx = XOR(lista->first, NULL);
        lista->first = new_node;
        lista->last = new_node;
        return true;
    }

    if (data <= lista->first->data)
        return insertarPrincipio(lista, data);

    if (data >= lista->last->data)
        return insertarFinal(lista, data);

    node *curr = lista->first;
    node *prev = NULL;
    node *next;

    while (curr != NULL)
    {

        if (curr->data >= data)
        {
            prev->npx = XOR(new_node, XOR(prev->npx, curr));
            curr->npx = XOR(new_node, XOR(curr->npx, prev));
            new_node->npx = XOR(prev, curr);
            return true;
        }

        next = XOR(prev, curr->npx);

        // se actualiza prev y curr
        prev = curr;
        curr = next;
    }

    return 1;
}

bool buscar(list *lista, int data)
{

    if (esVacia(lista))
        return false;

    node *curr = lista->first;
    node *prev = NULL;
    node *next;
    int i = 0;

    while (curr != NULL)
    {

        i++;
        if (curr->data == data)
        {
            printf("\nElemento %i encontrado en la posicion %i\n", data, i);
            return true;
        }

        next = XOR(prev, curr->npx);

        // se actualiza prev y curr
        prev = curr;
        curr = next;
    }

    printf("\nElemento no encontrado.\n");
    return false;
}

void listarInicioAFinal(list *lista)
{

    if (esVacia(lista))
    {
        printf("\nLa lista esta vacia.\n");
        return;
    }
    node *curr = lista->first;
    node *prev = NULL;
    node *next;

    printf("\nElementos de la lista (desde el primero al ultimo): \n");

    while (curr != NULL)
    {

        // se imprime el valor de curr
        printf("%i ", (curr->data));

        next = XOR(prev, curr->npx);

        // Se actualiza prev y curr
        prev = curr;
        curr = next;
    }
}

void listarFinalAInicio(list *lista)
{

    if (esVacia(lista))
    {
        printf("\nLa lista esta vacia.\n");
        return;
    }
    node *curr = lista->last;
    node *prev = NULL;
    node *next;

    printf("\nElementos de la lista (desde el ultimo al primero): \n");

    while (curr != NULL)
    {

        // imprimir valor del nodo actual
        printf("%i ", (curr->data));

        next = XOR(curr->npx, prev);

        // se actualiza prev y curr
        prev = curr;
        curr = next;
    }
}

int cantidadElementos(list *lista)
{

    if (esVacia(lista))
    {
        return 0;
    }
    node *curr = lista->first;
    node *prev = NULL;
    node *next;
    int i = 0;

    while (curr != NULL)
    {
        i++;
        next = XOR(prev, curr->npx);
        prev = curr;
        curr = next;
    }

    return i;
}
