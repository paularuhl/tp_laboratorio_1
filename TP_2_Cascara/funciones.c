#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define VACIO -1

void inicializarEstructura(EPersona persona[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        persona[i].estado = valor;
    }
}


int buscarPrimerOcurrencia(int array[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++) //si termina de iterar y no se cumple, retorna -1
    {
        if(array[i] == valor)
        {
            return i;
        }
    }
    return -1;
}


int buscarDni(EPersona arrayPersonas[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(arrayPersonas[i].dni == valor)
        {
            return i;
        }
    }
    return -1;
}

int buscarIndexEstado(EPersona arrayPersonas[],int tamanho,int valor)
{
    int i;
    for(i=0; i < tamanho; i++)
    {
        if(arrayPersonas[i].estado == valor)
        {
            return i;
        }
    }
    return -1;
}

int esSoloLetras(char array[])
{
    int i=0;
    while(array[i] != '\0')
    {
        if((array[i] != ' ') && (array[i] < 'a' || array[i] > 'z') && (array[i] < 'A' || array[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int esNumerico(char array[])
{
    int i=0, flag=1;
    while(array[i] != '\0')
    {
        if((!isdigit(array[i])))
        {
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

int getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

int ingresoStringNumerico(char mensaje[])
{
    char auxDato[20];
    int dato;
    printf("Ingrese %s:",mensaje);
    getString(" ",auxDato);
    while(!esNumerico(auxDato))
    {
        printf("*%s* solo puede estar compuesto por numeros.\n",mensaje);
        printf("Reingrese %s: ",mensaje);
        fflush(stdin);
        gets(auxDato);
    }
    dato = atoi(auxDato);

    return dato;
}

int validarDatoMaxMin(int dato, char mensaje[], int min, int max)
{
    while((dato < min) || (dato > max))
    {
        printf("El item *%s* debe estar entre %d y %d.\n",mensaje,min,max);
        dato = ingresoStringNumerico(mensaje);
    }
    return dato;
}

void registrarDatos (EPersona persona[], int tamanio, char nombre[], int dni, int edad, int index)
{
    strlwr(nombre);
    for(int i=0; i<50; i++)
    {
        if(nombre[i]==' ')
        {
            nombre[i+1]=toupper(nombre[i+1]);
        }
    }
    nombre[0]=toupper(nombre[0]);
    strcpy(persona[index].nombre,nombre);
    persona[index].edad = edad;
    persona[index].dni = dni;
    persona[index].estado = 1;
    printf("Alta realizada correctamente.");
}


void graficoBarras(int menores18,int de19a35,int mayor35)
{
    int mayorTodos;
    int flag=0,flag2=0, i;

    if(menores18 >= de19a35 && menores18 >= mayor35)
    {
        mayorTodos = menores18;
    }
    else if(de19a35 >= menores18 && de19a35 >= mayor35)
    {
        mayorTodos = de19a35;
    }
    else
    {
        mayorTodos = mayor35;
    }

    for(i=mayorTodos; i>0; i--)
    {
        printf("\n%02d|",i);
        if(i<= menores18)
        {
            printf("\t%c",'*');
            flag=2;
            flag2=1;
        }
        if(i<=de19a35)
        {
            flag=1;

            if(flag2==0)
            {
                printf("\t\t\t%c",'*');
            }
            if(flag2==1)
            {
                printf("\t\t%c",'*');
            }
        }
        if(i<= mayor35)
        {
            if(flag==0)
            {
                printf("\t\t\t\t\t%c",'*');
            }

            if(flag==1)
            {
                printf("\t\t%c",'*');
            }
            if(flag==2)
            {
                printf("\t\t\t\t%c",'*');
            }
        }
    }
    printf("\n--|----------------------------------------------\n");
    printf("--|    <18            19-35            >35\n");
    printf("Tot:    %d               %d               %d\n",menores18,de19a35,mayor35);
}


int mostrarListado(EPersona persona[], int tamanho)
{
    int i, flag=1;
    printf("DNI\t NOMBRE\t\t\t EDAD\n");
    for(i=0; i<tamanho; i++)
    {
        if(persona[i].estado!=-1)
        {
            printf("%d\t %s\t\t %d\n", persona[i].dni, persona[i].nombre, persona[i].edad);
            flag=0;
        }
    }
    if(flag)
    {
        system("cls");
        return 0;
    }
    else
    {
        return 1;
    }
}
void ordenarPorNombre(EPersona persona[], int tamanho)
{
    EPersona auxPersona;
    int i, j;

    for(i=0; i < tamanho - 1; i++)
    {
        if(persona[i].estado == VACIO)
        {
            continue;
        }
        for(j=i+1; j < tamanho; j++)
        {
            if(persona[j].estado == VACIO)
            {
                continue;
            }
            if(strcmp(persona[i].nombre,persona[j].nombre) > 0)
            {
                auxPersona = persona[j];
                persona[j] = persona[i];
                persona[i] = auxPersona;
            }
        }
    }
}


///TESTING
void inicializarUsuariosHardCode(EPersona persona[])
{


    int edad[] = {19, 20, 32, 40, 22, 12, 13, 21, 39, 93, 26, 98, 27};
    char nombre[][50]= {"Luis Fernandez", "Fernando Ruhl", "Adolfo Jajano", "Joaquin Descartes", "Hugo Kitch", "Yolanda Blaise", "Sandra Lopez", "Ines Stelliano", "Camila Wool", "Macarena Madera", "Delfina Connor", "Valeria Salto", "Francisco Tablada"};
    int dni[] = {1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,1100000,1200000,1300000,1400000};
    int i;

    for(i=0; i<13; i++)
    {
        persona[i].edad=edad[i];
        persona[i].dni=dni[i];
        persona[i].estado = 1;
        strcpy(persona[i].nombre, nombre[i]);

    }
}

