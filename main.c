#include <stdio.h>
#include "XOR.h"

int main()
{

    int option, x, y;
    list *lista = crearLista();
    do
    {
        printf("\n1. Inicializar lista.\n");
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
            break;
        }
    } while (option != 13);
}