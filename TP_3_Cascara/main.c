#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define SIZE 100
///RUHL PAULA INES
///40011750
///1° B

int main()
{
    char seguir='s';
    int opcion=0;
    EMovie peliculas[SIZE];
    inicializarEstados(&peliculas,SIZE);
    int acumuladorPelis=0;
    cargarPelicula(&peliculas,SIZE,&acumuladorPelis);
    while(seguir=='s')
    {
        opcion = menuPrincipal();

        switch(opcion)
        {
            case 1:
                alta(&peliculas,SIZE,&acumuladorPelis);
                printf("\n");
                system("pause");
                break;
            case 2:
                borrarPelicula(&peliculas,SIZE,&acumuladorPelis);
                printf("\n");
                system("pause");
                break;
            case 3:
                modificarPelicula(&peliculas,SIZE,&acumuladorPelis);
                printf("\n");
                system("pause");
               break;
            case 4:
                generarPagina(&peliculas,SIZE,"ListadoDePeliculas.html");
                printf("\n");
                system("pause");
                break;
            case 5:
                printf("Adios!\n");
                system("pause");
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta, intente otra vez.\n");
                system("pause");
                break;
        }
        system("cls");
    }


return 0;
}
