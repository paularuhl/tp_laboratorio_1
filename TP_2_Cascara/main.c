#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define QTY_PERSONAS 20
#define VACIO -1
///RUHL PAULA INES
///40011750
///1° B
int main()
{
    EPersona persona[QTY_PERSONAS];
    char seguir='s', respuesta='x';
    int opcion=0;
    int auxEdad, auxDni, lugarLibre, indexEncontrado;
    int mayor35=0, menor19=0, de19a35=0;
    char auxNombre[50];

    inicializarEstructura(persona,QTY_PERSONAS,VACIO);
    inicializarUsuariosHardCode(persona);
    int i;
    for(i=0; i < 13; i++)
    {
        if(persona[i].edad <19)
        {
            menor19++;
        }
        else if(persona[i].edad>35)
        {
            mayor35++;
        }
        else
        {
            de19a35++;
        }
    }


    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        opcion = ingresoStringNumerico("opcion");
        switch(opcion)
        {
        case 1:
            lugarLibre = buscarIndexEstado(persona, QTY_PERSONAS, VACIO);
            if(lugarLibre == VACIO)
            {
                printf("No hay lugares libres!\n");
                break;
            }
            else

                printf("\n *AGREGAR* \n");

            if(!getStringLetras("\nIngrese un nombre: ",auxNombre))
            {
                printf("El nombre debe estar compuesto solo por letras.\n");
                break;
            }

            auxEdad = ingresoStringNumerico("edad");
            validarDatoMaxMin(auxEdad,"edad",1,100);
            auxDni = ingresoStringNumerico("DNI");
            validarDatoMaxMin(auxDni,"DNI", 1, 100000000);
            if((buscarDni(persona,QTY_PERSONAS,auxDni)!=VACIO))
            {
                printf("DNI ya registrado. Por favor, intente nuevamente.\n");
            }
            if(auxEdad<19)
            {
                menor19++;
            }
            else if(auxEdad>35)
            {
                mayor35++;
            }
            else
            {
                de19a35++;
            }
            registrarDatos(persona,QTY_PERSONAS,auxNombre,auxDni,auxEdad,lugarLibre);

            break;
        case 2:
            printf("\n*BORRAR*\n");
            mostrarListado(persona,QTY_PERSONAS);

            auxDni = ingresoStringNumerico("DNI de la persona a eliminar");
            validarDatoMaxMin(auxDni,"DNI de la persona a eliminar", 1, 100000000);
            indexEncontrado = buscarDni(persona,QTY_PERSONAS,auxDni);
            if (indexEncontrado != VACIO)
            {
                printf("Esta seguro de eliminar a esta persona? s/n\n %d | %s | %d\n", persona[indexEncontrado].dni, persona[indexEncontrado].nombre, persona[indexEncontrado].edad);
                respuesta = getche();
                if(respuesta=='s')
                {
                    printf("Ha eliminado correctamente al usuario %s\n", persona[indexEncontrado].nombre);
                    if(persona[indexEncontrado].edad<19)
                    {
                        menor19--;
                    }
                    else if(persona[indexEncontrado].edad>35)
                    {
                        mayor35--;
                    }
                    else
                    {
                        de19a35--;
                    }
                    persona[indexEncontrado].estado = VACIO;
                }
                else
                {
                    printf("Accion cancelada.");
                }

            }
            else
            {
                printf("Error, DNI no registrado.\n");
            }
            break;
        case 3:
            printf("\n*LISTADO POR NOMBRE*\n");
            ordenarPorNombre(persona,QTY_PERSONAS);

            if(!mostrarListado(persona,QTY_PERSONAS))
            {
                printf("No hay altas en sistema.\n");
            }

            break;
        case 4:
            if(menor19==0 && de19a35==0 && mayor35==0)
            {
                printf("No hay altas para realizar el grafico.\n");
                break;
            }
            graficoBarras(menor19,de19a35,mayor35);

            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion invalida, intente de nuevo.\n");
            break;
        }

        getch();
        system("cls");
    }

    return 0;
}
