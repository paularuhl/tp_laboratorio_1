#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include "funciones.h"
#define VACIO -1


int menuPrincipal (void)
{
    int opcion;

    fflush(stdin);
    printf("Sitio principal\n1. Agregar pelicula\n2. Borrar pelicula\n3. Modificar pelicula\n4. Generar pagina web\n5. Salir\n");
    opcion = ingresoStringNumerico("opcion");

    return opcion;
}




///validar inputs

int isNull (char value)
{
    if(value=='\0' || value ==' ')
    {
        return 1;
    }
    return 0;
}

int esNumerico(char array[])
{
    int i=0, flag=1;

    if(isNull(array[0]))
    {
        flag = 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])))
            {
                flag = 0;
                break;
            }
            i++;
        }
    }
    return flag;
}

int esSoloLetras(char array[])
{
    int i=0, flag=1;
    if(isNull(array[0]))
    {
        flag = 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if( (!isspace(array[i])) && (!isalpha(array[i])) )
            {
                flag = 0;
                break;
            }
            i++;
        }
    }
    return flag;
}

int esAlfanumerico(char array[])
{
    int i=0, flag=1;
    if(isNull(array[0]))
    {
        flag = 0;
    }
    else
    {
        while(array[i] != '\0')
        {
            if((!isdigit(array[i])) && (!isalpha(array[i])) && (!isspace(array[i])) && (array[i] != ':') && (array[i] != '-') && (array[i] != ',') && (array[i] != '.'))
            {
                flag = 0;
                break;
            }
            i++;
        }
    }
    return flag;
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


int validarLargoString (int tope, char string[])
{
    int largo;
    largo=strlen(string);
    if(largo<tope)
    {
        return 1;
    }
    return 0;
}
///get strings
void getString(char mensaje[],char input[])
{
    fflush(stdin);
    printf("%s",mensaje);
    gets(input);
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

int getStringAlfaNumerico(char mensaje[],char input[])
{
    char aux[256];
    getString(mensaje,aux);
    if(esAlfanumerico(aux))
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
    printf("\nIngrese %s:",mensaje);
    getString(" ",auxDato);
    while(!esNumerico(auxDato))
    {
        printf("*%s* solo puede estar compuesto por numeros.\nReingrese %s: ",mensaje,mensaje);
        fflush(stdin);
        gets(auxDato);
    }
    dato = atoi(auxDato);

    return dato;
}


///utiles
/*
int IdIncremental(EMovie* peliculas,int length,int index)
{
    *(index)=0;
    int i;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            index=i+1;
        }
    }
    return *(index)+1;
}*/
int idIncremental(EMovie* peliculas,int length)
{
    int id = 0;
    int i;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1 && (peliculas+i)->id > id)///si el anterior esta ocupado y es mayor al retorno
        {
            id=(peliculas+i)->id;///devuelve esa id
        }
        else
        {
            break;
        }
    }

    return id+1;///y retorna el lugar siguiente
}

char stringToUpper(char inicial[])
{
    int i;
    int largo;
    inicial[0]=toupper(inicial[0]);
    largo=strlen(inicial);
    for(i=0; i<largo; i++)
    {
        if(inicial[i]==' ')
        {
            i=i+1;
            inicial[i]=toupper(inicial[i]);
        }
    }
    return inicial;
}



void inicializarEstados(EMovie* peliculas,int length)
{
    int i;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)!=NULL)
        {
            (peliculas+i)->estado=VACIO;
        }
    }
}



int buscarLibre(EMovie* peliculas,int length,int* index)
{
    int i;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==VACIO&&(peliculas+i)!=NULL)
        {
            *(index)=i;
            break;
        }
    }
    return *(index);
}


void cargarPelicula(EMovie* peliculas,int length,int* contador)
{
    int i;
    FILE* dbFile;
    dbFile=fopen("movieDatabase.bin","rb");
    if(dbFile!=NULL)
    {
        fread(contador,sizeof(int),1,dbFile);
        for(i=0; i<*(contador); i++)
        {
            fread((peliculas+i),sizeof(EMovie),1,dbFile);
        }
        printf("Existe una base de datos para este programa.\n");

    }
    fclose(dbFile);
}
void agregarPelicula(EMovie* peliculas,int length,int* contador)
{
    *(contador)=0;
    int i;
    FILE* dbFile;
    dbFile=fopen("movieDatabase.bin","wb");
    if(dbFile!=NULL)
    {
        for(i=0; i<length; i++)
        {
            if((peliculas+i)->estado==1 )
            {
                *(contador)=*(contador)+1;
            }
        }
        fwrite(contador,sizeof(int),1,dbFile);

        for(i=0; i<length; i++)
        {
            if((peliculas+i)->estado==1 )
            {
                fwrite((peliculas+i),sizeof(EMovie),1,dbFile);
            }
        }
    }
    fclose(dbFile);
}


int buscarPelicula(EMovie* peliculas,int length,int id)
{
    int index=VACIO;
    int i;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            if((peliculas+i)->id==id)
            {
                return i;
            }
        }
    }
    return index;
}


void mostrarPelicula(EMovie* peliculas,int length)
{
    int i;
    printf("Para ver el listado detallado, ingrese al archivo html en el indice de este archivo...\n");
    printf("ID\tNombre\n");
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            printf("%d\t%s\n",(peliculas+i)->id,(peliculas+i)->titulo);
        }
    }
}




void alta(EMovie* peliculas,int length,int* contador)
{
    char confirmar = 'x';
    int index=VACIO;
    buscarLibre(peliculas,length,&index);
    if(index!=VACIO)
    {
        fflush(stdin);
        getStringAlfaNumerico("\nIngrese titulo: ",(peliculas+index)->titulo);
        while(!esAlfanumerico((peliculas+index)->titulo))
        {
            getStringAlfaNumerico("Error, los unicos simbolos permitidos son: ': - , .'\nReingresar titulo: ",(peliculas+index)->titulo);
        }

        fflush(stdin);
        getStringLetras("\nIngrese genero: ",(peliculas+index)->genero);
        while(!esSoloLetras((peliculas+index)->genero))
        {
            getStringLetras("Error, el genero solo puede contener letras y espacios.\nReingresar genero: ",(peliculas+index)->genero);
        }

        (peliculas+index)->duracion = ingresoStringNumerico("duracion (mins)");

        fflush(stdin);
        getStringAlfaNumerico("\nIngrese descripcion: ",(peliculas+index)->descripcion);
        while(!esAlfanumerico((peliculas+index)->descripcion))
        {
            getStringAlfaNumerico("Error, los unicos simbolos permitidos son: ': - , .'\nReingresar descripcion: ",(peliculas+index)->descripcion);
        }

        (peliculas+index)->puntaje = validarDatoMaxMin(ingresoStringNumerico("puntaje"),"puntaje",0,100);

        getString("\nIngrese link de imagen para la pelicula: ",(peliculas+index)->linkImagen);
        while(isNull((peliculas+index)->linkImagen[0]))
        {
            getString("Error, el link no puede estar vacio.\nReingresar link: ",(peliculas+index)->linkImagen);
        }

        printf("\nConfirmar pelicula? s/n: ");
        fflush(stdin);
        confirmar = getche();
        if(confirmar == 's' || confirmar == 'S')
        {
            (peliculas+index)->estado = 1;
            (peliculas+index)->id = idIncremental(peliculas,length);
            agregarPelicula(peliculas,length,contador);
        }
        else
        {
            printf("\nNo se cargo la pelicula");
        }

    }
    else
    {
        printf("\nNo hay espacio disponible!\n");
    }

}

void borrarPelicula(EMovie* peliculas,int length,int* contador)
{
    int i;
    int flag=0;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        int id=0;
        int index;
        char respuesta;
        mostrarPelicula(peliculas,length);
        id = ingresoStringNumerico("ID de la pelicula a dar de baja");
        index=buscarPelicula(peliculas,length,id);
        if(index!=VACIO)
        {
            printf("\nEsta seguro de DAR DE BAJA la pelicula?? s/n: ");
            fflush(stdin);
            respuesta = getche();
            if(respuesta=='s')
            {
                (peliculas+index)->estado=2;
                printf("\nBaja exitosa!");
                agregarPelicula(peliculas,length,contador);
            }
            else
            {
                printf("\nBaja cancelada.");
            }
        }
        else
        {
            printf("No se encontro el ID ingresado...\n");
        }
    }
    else
    {
        printf("No hay ninguna pelicula ingresada...\n");
    }

}

void modificarPelicula(EMovie* peliculas,int length,int* contador)
{
    int i;
    int flag=0;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        int id=0, opcion=0, index, flagSwitch=0;
        char repetirPelicula;
        mostrarPelicula(peliculas,length);
        id = ingresoStringNumerico("ID de la pelicula a modificar");
        index=buscarPelicula(peliculas,length,id);
        if(index!=VACIO)
        {
            do
            {
                printf("\nIngrese item a modificar:\n");
                printf("1. Titulo\n2. Genero\n3. Duracion\n4. Descripcion\n5. Puntaje\n6. Link de Imagen\n0. Volver atras\n\nIngrese opcion: ");
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    fflush(stdin);
                    getStringAlfaNumerico("\nIngrese nuevo titulo: ",(peliculas+index)->titulo);
                    while(!esAlfanumerico((peliculas+index)->titulo))
                    {
                        getStringAlfaNumerico("Error, los unicos simbolos permitidos son: ': - , .'\nReingresar titulo: ",(peliculas+index)->titulo);
                    }
                    stringToUpper((peliculas+index)->titulo);
                    break;
                case 2:
                    fflush(stdin);
                    getStringLetras("\nIngrese nuevo genero: ",(peliculas+index)->genero);
                    while(!esSoloLetras((peliculas+index)->genero))
                    {
                        getStringLetras("Error, el genero solo puede contener letras y espacios.\nReingresar genero: ",(peliculas+index)->genero);
                    }
                    stringToUpper((peliculas+index)->genero);
                    break;
                case 3:
                    (peliculas+index)->duracion = ingresoStringNumerico("nueva duracion (mins)");
                    break;
                case 4:
                    fflush(stdin);
                    getStringAlfaNumerico("\nIngrese nueva descripcion: ",(peliculas+index)->descripcion);
                    while(!esAlfanumerico((peliculas+index)->descripcion))
                    {
                        getStringAlfaNumerico("Error, los unicos simbolos permitidos son: ': - , .' .\nReingresar descripcion: ",(peliculas+index)->descripcion);
                    }
                    stringToUpper((peliculas+index)->descripcion);
                    break;
                case 5:
                    (peliculas+index)->puntaje = validarDatoMaxMin(ingresoStringNumerico("nuevo puntaje"),"puntaje",0,100);
                    break;
                case 6:
                    getString("\nIngrese nuevo link de imagen para la pelicula: ",(peliculas+index)->linkImagen);
                    while(isNull((peliculas+index)->linkImagen[0]))
                    {
                        getString("Error, el link no puede estar vacio.\nReingresar link: ",(peliculas+index)->linkImagen);
                    }
                    break;
                case 0:
                    flagSwitch=1;
                    break;
                default:
                    printf("Opcion invalida. Intente otra vez.\n");
                    break;
                }
                if(flagSwitch)
                {
                    break;
                }

                printf("Modificacion realizada con exito.\n Desea modificar otro item de *%s*?",(peliculas+index)->titulo);
                fflush(stdin);
                repetirPelicula = getche();
            }
            while(repetirPelicula == 's' || repetirPelicula == 'S');
            agregarPelicula(peliculas,length,contador);
        }
        else
        {
            printf("ID inexistente!\n");
        }
    }
    else
    {
        printf("No hay ninguna pelicula ingresada...\n");
    }
}

void generarPagina(EMovie* peliculas,int length,char nombre[])
{
    int i;
    int flag=0;
    for(i=0; i<length; i++)
    {
        if((peliculas+i)->estado==1)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        FILE* miArchivo;
        miArchivo=fopen(nombre,"w");
        if(miArchivo!=NULL)
        {
            fprintf(miArchivo,"<!DOCTYPE html><!-- Template by Quackit.com --><html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags --><title>Lista peliculas</title><!-- Bootstrap Core CSS --><link href='css/bootstrap.min.css' rel='stylesheet'><!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles --><link href='css/custom.css' rel='stylesheet'><!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries --><!-- WARNING: Respond.js doesn't work if you view the page via file:// --><!--[if lt IE 9]><script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script><script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script><![endif]--></head><body><div class='container'><div class='row'>");
            int i;
            for(i=0; i<length; i++)
            {
                if((peliculas+i)->estado==1)
                {
                    fprintf(miArchivo,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s'alt=''></a><h3><a href='#'>%s</a></h3><ul><li>Genero: %s</li><li>Puntaje: %d/100</li><li>Duracion: %dmins</li></ul><p>%s</p></article>",(peliculas+i)->linkImagen,(peliculas+i)->titulo,(peliculas+i)->genero,(peliculas+i)->puntaje,(peliculas+i)->duracion,(peliculas+i)->descripcion);
                }
            }
            fprintf(miArchivo,"</div><!-- /.row --></div><!-- /.container --><!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
            printf("Pagina web creada, encuentrela en el indice de este programa.\n");
        }
        fclose(miArchivo);
    }
    else
    {
        printf("No hay peliculas ingresadas...\n");
    }

}

