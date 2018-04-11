#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"


/** \brief Pide un numero flotante
 *
 * \param char mensaje [] -- indica para qué será usado el numero (en este caso un operando)
 * \return float -- devuelve el numero ingresado sin cambios
 */
float pedirNumero (char mensaje[])
{
    float num;
    printf("Ingrese el %s ", mensaje);
    scanf("%f", &num);
    return num;
}



/** \brief suma dos operandos ingresados anteriormente
 *
 * \param num1 float -- 1er operando ingresado
 * \param num2 float -- 2do operando ingresado
 * \return float -- resultado
 */
float sumar(float num1, float num2)
{
            float suma;
            suma = num1 + num2;
            return suma;
}


/** \brief toma dos operandos ingresados anteriormente y realiza una resta en orden de ingreso
 *
 * \param num1 float -- 1er operando ingresado
 * \param num2 float -- 2do operando ingresado
 * \return float -- resultado
 */
float restar(float num1, float num2)
{
            float resta;
            resta = num1 - num2;
            return resta;
}




/** \brief toma dos operandos ingresados anteriormente y los multiplica entre si
 *
 * \param num1 float -- 1er factor ingresado
 * \param num2 float -- 2do factor ingresado
 * \return float -- resultado
 */
float multiplicar(float num1, float num2)
{
            float producto;
            producto = num1 * num2;
            return producto;
}





/** \brief Pregunta al usuario si desea continuar luego de realizar una acción
 *
 * \param int seguir (si/no)
 * \return int seguir devuelve el dato ingresado y muestra (o no) la ultima consulta
 */
char continuar()
{
    char seguir;
    printf("Desea continuar? s/n: \n");
    seguir = getch();
    while(!(seguir == 's' || seguir == 'n'))
    {
            printf("Opcion incorrecta. Desea continuar? s/n: \n");
            seguir = getch();
    }
    return seguir;
}




/*
** \brief toma dos operandos ingresados anteriormente y realiza una division en orden de ingreso
 *
 * \param num1 float -- 1er nro ingresado, dividendo
 * \param num2 float -- 2do nro ingresado, divisor
 * \return float -- resultado
 *
float dividir(float num1, float num2)
{
    float division;
    switch(num2)
    {
        case 0:
        printf("Error! No se puede dividir por cero.\n");
            division = void
            break;
        default:
            division = num1 / num2;
            break;
    }
        return division;

} */
///RUHL PAULA INES
///40011750
///1° B
