#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}EPersona;

int buscarPrimerOcurrenciaEstructuraEstado(EPersona arrayPersonas[],int tamanho,int valor);

/**
 * \brief Inicializa un array de Personas con el valor recibido
 * \param array Es el array a ser inicializado
 * \param cantidadDeElementos Indica la logitud del array
 * \param valor Es el valor que sera cargado en cada posición
 * \return void
 *
 */
void inicializarEstructura(EPersona persona[],int tamanho,int valor);

/**
 * \brief Busca la primer ocurrencia de un valor en un array de enteros
 * \param array Es el array en el cual buscar
 * \param tamanho Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay la posicion de la misma (i)
 *
 */
int buscarPrimerOcurrencia(int array[],int tamanho,int valor);

/**
 * \brief Busca el dni ingresado en la estructura
 * \param array Es el array en el cual buscar
 * \param tamanho Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarDni(EPersona arrayPersonas[],int tamanho,int valor);

/**
 * \brief Busca el estado indicado en un array
 * \param array Es el array en el cual buscar
 * \param tamanho Indica la logitud del array
 * \param valor Es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarIndexEstado(EPersona arrayPersonas[],int tamanho,int valor);
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char array[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */
int esNumerico(char str[]);

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 *
 */
int ingresoStringNumerico(char mensaje[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 *
 */
int validarDatoMaxMin(int dato, char mensaje[], int min, int max);
///TESTING
/**
 * \brief Inicializa una estructura hardcodeandola para testing
 * \param estructura a inicializar
 * \return void
 */
void inicializarUsuariosHardCode(EPersona persona[]);


/** \brief Copia los valores auxiliares a la estructura Persona
 * \param  estructura persona y su tamanio
 * \param  dni auxiliar
 * \param  edad auxiliar
 * \param  nombre auxiliar
 * \param  index libre de la estructura
 */
void registrarDatos (EPersona persona[], int tamanio, char nombre[], int dni, int edad, int index);

/** \brief Ordena los nombres alfabeticamente (A-Z)
 * \param  estructura Persona
 * \param  tamanio de persona
 */
 void ordenarPorNombre(EPersona persona[], int tamanho);

 /** \brief Muestra los datos visibles de la estructura Persona
 * \param  estructura EPersona
 * \param  tamanio de persona
 * \return Si no encuentra a nadie devuelve 0, si hay gente en la lista, 1.
 */
 int mostrarListado(EPersona persona[], int tamanho);

 /** \brief Crea un grafico de barras desde las edades.
 * \param  acumulador de -19 años
 * \param  acumulador de 19 a 35 años
 * \param  acumulador de +35 años
 */
void graficoBarras(int menores18,int de19a35,int mayor35);




#endif // FUNCIONES_H_INCLUDED
