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
    printf("Bienvenido! Elija una de las siguientes opciones para comenzar: \n");
    while(seguir=='s')
    {
        double factorial = 1; //resets factorial
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");
        scanf("%c",&opcion);

        switch(opcion)
        {
            case '1':
                A = pedirNumero("primer operando:");
                seguir = continuar();
                break;
            case '2':
                B = pedirNumero("segundo operando:");
                seguir = continuar();
                break;
            case '3':
                suma = sumar(A, B);
                printf("La suma entre %.2f y %.2f es %.2f.\n", A, B, suma);
                seguir = continuar();
                break;
            case '4':
                resta = restar(A, B);
                printf("La resta entre %.2f y %.2f es %.2f.\n", A, B, resta);
                seguir = continuar();
                break;
            case '5':
                //division = dividir(A, B);  - no hay float q pueda devolver el error if B == 0
                if(B==0)
                {
                    printf("Error! No se puede dividir por cero.\n");
                }
                else
                {
                    division = A / B;
                    printf("El resultado de %.2f dividido por %.2f es %.2f.\n", A, B, division);
                }
                seguir = continuar();
                break;
            case '6':
                multiplicacion = multiplicar(A, B);
                printf("El resultado de %.2f multiplicado por %.2f es %.2f.\n", A, B, multiplicacion);
                seguir = continuar();
                break;
            case '7':
                if (A < 0)
                {
                    printf("Oops! Los numeros negativos no tienen factorial\n");
                }
                else if (A == 0)
                {
                    printf("El factorial de 0 es por definición 1.\n");
                }
                else
                {
                    for(float i = 1; i <= A; i++)
                    {
                        factorial = factorial * i;

                    }
                    printf("El factorial de %.2f es %.2lf.\n", A, factorial);
                }
                seguir = continuar();
                break;
            case '8':
                suma = sumar(A, B);
                resta = restar(A, B);
                multiplicacion = multiplicar(A, B);
                printf("La suma entre %.2f y %.2f es %.2f.\n", A, B, suma);
                printf("La resta entre %.2f y %.2f es %.2f.\n", A, B, resta);
                if(B==0)
                {
                    printf("Error! No se puede dividir por cero.\n");
                }
                else
                {
                    division = A / B;
                    printf("El resultado de %.2f dividido por %.2f es %.2f.\n", A, B, division);
                }
                printf("El resultado de %.2f multiplicado por %.2f es %.2f.\n", A, B, multiplicacion);

                if (A < 0)
                {
                    printf("Oops! Los numeros negativos no tienen factorial\n");
                }
                else if (A == 0)
                {
                    printf("El factorial de 0 es por definición 1.\n");
                }
                else
                {
                    for(double i = 1; i <= A; i++)
                    {
                        factorial = factorial * i;

                    }
                    printf("El factorial de %.2f es %.2lf.\n", A, factorial);
                }

                seguir = continuar();
                break;
            case '9':
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta, por favor reingresar: \n");
                scanf("%c",&opcion);
        }


    }
    return 0;
}


