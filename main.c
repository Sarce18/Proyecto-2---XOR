#include <stdio.h>
#include "XOR.h"

int main()
{

    int option, x, y;
    list *lista = crearLista();
    do
    {
        printf("1. Inicializar lista.\n");
        printf("2. Es vacia.\n");
        printf("3. Insertar principio.\n");
        printf("4. Insertar final.\n");
        printf("5. Insertar ordenado.\n");
        printf("6. Buscar.\n");
        printf("7. Sacar principio.\n");
        printf("8. Sacar final.\n");
        printf("9. Sacar primera ocurrencia.\n");
        printf("10. Listar inicio a final.\n");
        printf("11. Listar final a inicio.\n");
        printf("12. Cantidad de elementos.\n");
        printf("13. Salir.\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            inicializar(lista);
            break;
        case 2:
            if (esVacia(lista))
                printf("La lista esta vacia.\n");
            else
                printf("La lista no esta vacia.\n");
            break;
        case 3:
            printf("Ingrese el numero: ");
            scanf("%d", &x);
            insertarPrincipio(lista, x);
            break;
        case 4:
            printf("Ingrese el numero: ");
            scanf("%d", &x);
            insertarFinal(lista, x);
            break;
        case 5:
            printf("Ingrese el numero: ");
            scanf("%d", &x);
            insertarOrden(lista, x);
            break;
        case 6:
            printf("Ingrese el numero: ");
            scanf("%d", &x);
            buscar(lista, x);
            break;
        case 7:
            sacarPrincipio(lista, &y);
            break;
        case 8:
            sacarFinal(lista, &y);
            break;
        case 9:
            printf("Ingrese el numero: ");
            scanf("%d", &x);
            sacarPrimeraOcurrencia(lista, x);
            break;
        case 10:
            listarInicioAFinal(lista);
            break;
        case 11:
            listarFinalAInicio(lista);
            break;
        case 12:
            printf("Cantidad de elementos: %i\n", cantidadElementos(lista));
            break;

        default:
            printf("Inserte una opcion valida.\n");
            break;
        }
    } while (option != 13);

    /*    insertarPrincipio(lista, -10);
        insertarPrincipio(lista, -20);
        insertarPrincipio(lista, -30);
        insertarPrincipio(lista, -40);
        insertarFinal(lista, 0);
        insertarFinal(lista, 10);
        insertarFinal(lista, 20);

        listarInicioAFinal(lista);
        listarFinalAInicio(lista);

        buscar(lista, -40);

        printf("Cantidad de elementos: %i", cantidadElementos(lista));

        int e;
        sacarFinal(lista, &e);
        printf("\nsacarFinal: %d", e);
        sacarPrincipio(lista, &e);
        printf("\nsacarPrincipio: %d", e);

        listarInicioAFinal(lista);
        listarFinalAInicio(lista);

        printf("\nInicializar");
        inicializar(lista);
        listarInicioAFinal(lista);
        listarFinalAInicio(lista);

        printf("\ninsertar ordenado\n");
        insertarOrden(lista, 0);
        insertarOrden(lista, 10);
        insertarOrden(lista, 1);
        insertarOrden(lista, 10);
        insertarOrden(lista, 3);
        insertarOrden(lista, 4);
        insertarOrden(lista, 6);
        insertarOrden(lista, 7);
        insertarOrden(lista, 8);
        insertarOrden(lista, 9);
        insertarOrden(lista, 4);
        insertarOrden(lista, 5);
        insertarOrden(lista, 2);

        listarInicioAFinal(lista);
        listarFinalAInicio(lista);

        printf("\nsacar primera ocurrencia\n");
        sacarPrimeraOcurrencia(lista, 4);
        sacarPrimeraOcurrencia(lista, 4);
        sacarPrimeraOcurrencia(lista, 5);
        sacarPrimeraOcurrencia(lista, 10);
        sacarPrimeraOcurrencia(lista, 10);
        sacarPrimeraOcurrencia(lista, 0);
        sacarPrimeraOcurrencia(lista, 0);
        sacarPrimeraOcurrencia(lista, 1);

        listarInicioAFinal(lista);
        listarFinalAInicio(lista);

        return (0);*/
}