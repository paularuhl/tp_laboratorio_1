#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
///RUHL PAULA INES
///40011750
///1° B
int main()
{
    char seguir='s';
    char opcion=0;
    float A, B, suma, resta, division, multiplicacion;
    int flag = 0;
    printf("Bienvenido! Elija una de las siguientes opciones para comenzar: \n");
    while(seguir=='s')
    {
        double factorial = 1; //resets factorial
        float i = 1;  //Resets i
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        opcion = getch();

        switch(opcion)

        {
            case '1':
                A = pedirNumero("primer operando:");
                continuar();
                break;
            case '2':
                B = pedirNumero("segundo operando:");
                flag = 1;
                continuar();
                break;
            case '3':
                suma = sumar(A, B);
                printf("La suma entre %.2f y %.2f es %.2f.\n", A, B, suma);
                continuar();
                break;
            case '4':
                resta = restar(A, B);
                printf("La resta entre %.2f y %.2f es %.2f.\n", A, B, resta);
                continuar();
                break;
            case '5':
                while((flag==0) || (B==0))
                {
                    if(flag==0)
                    {
                    printf("Error! No ingreso un divisor.\n");
                    break;
                    } else {
                    printf("Error! No se puede dividir por cero.\n");
                    break;
                    }
                }

                if((flag!=0) && (B!=0))
                {
                    division = dividir(A, B);
                    printf("El resultado de %.2f dividido por %.2f es %.2f.\n", A, B, division);
                }
                continuar();
                break;
            case '6':
                multiplicacion = multiplicar(A, B);
                printf("El resultado de %.2f multiplicado por %.2f es %.2f.\n", A, B, multiplicacion);
                continuar();
                break;
            case '7':
                if (A < 0)
                {
                    printf("Oops! Los numeros negativos no tienen factorial\n");
                }
                else if (A == 0)
                {
                    printf("\nEl factorial de 0 es por definición 1.\n");
                }
                else
                {
                    for(i = 1; i <= A; i++)
                    {
                        factorial = factorial * i;

                    }
                    printf("El factorial de %.2f es %.2lf.\n", A, factorial);
                }
                continuar();
                break;
            case '8':
                suma = sumar(A, B);
                resta = restar(A, B);
                multiplicacion = multiplicar(A, B);
                printf("La suma entre %.2f y %.2f es %.2f.\n", A, B, suma);
                printf("La resta entre %.2f y %.2f es %.2f.\n", A, B, resta);
                while((flag==0) || (B==0))
                {
                    if(flag==0)
                    {
                    printf("Error! No ingreso un divisor.\n");
                    break;
                    } else {
                    printf("Error! No se puede dividir por cero.\n");
                    break;
                    }
                }
                if((flag!=0) && (B!=0))
                {
                    division = dividir(A, B);
                    printf("El resultado de %.2f dividido por %.2f es %.2f.\n", A, B, division);
                }

                printf("El resultado de %.2f multiplicado por %.2f es %.2f.\n", A, B, multiplicacion);

                if (A < 0)
                {
                    printf("Oops! Los numeros negativos no tienen factorial definido.\n");
                }
                else if (A == 0)
                {
                    printf("El factorial de 0 es por definición 1.\n");
                }
                else
                {
                    for(i = 1; i <= A; i++)
                    {
                        factorial = factorial * i;

                    }
                    printf("El factorial de %.2f es %.2lf.\n", A, factorial);
                }
                continuar();
                break;
            case '9':
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta, por favor reingresar: \n");
                break;
        }


    }
    return 0;
}


