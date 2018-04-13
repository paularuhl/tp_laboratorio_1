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





/** \brief pregunta al usuario que hacer luego de realizar una acción
 *
 * \param void
 * \return void
 */
void continuar(void)
{
    printf("*********************************\n");
    printf("| Que operacion desea realizar? |\n");
    printf("*********************************\n");
}

/** \brief toma dos operandos ingresados anteriormente y realiza una division en orden de ingreso
 *
 * \param num1 float -- 1er nro ingresado, dividendo
 * \param num2 float -- 2do nro ingresado, divisor
 * \return float -- resultado
 */
float dividir(float num1, float num2)
{
    float division;
    division = num1 / num2;
    return division;

}
///RUHL PAULA INES
///40011750
///1° B
