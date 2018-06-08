#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED


typedef struct{
    int id;
    char titulo[40];
    char genero[20];
    int duracion;
    char descripcion[400];
    int puntaje;
    char linkImagen[200];
    int estado;
}EMovie;

/** \brief muestra las opciones del menu principal y pide al usuario cual elige
 *
 * \param void
 * \return int opcion del menu
 *
 */
int menuPrincipal (void);


/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
void agregarPelicula(EMovie* listado,int length,int* contador);

/** \brief borra una pelicula de la base de datos
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param contador int cuenta las peliculas ingresadas
 * \return void
 *
 */
void borrarPelicula(EMovie* lista,int length,int* contador);





/** \brief verifica que un dato ingresado no esté vacío
 *
 * \param char value es el valor a analizar
 * \return 1 si es null, 0 si no lo es.
 */
int isNull (char value);


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */ void getString(char mensaje[],char input[]);

/**
 * \brief Verifica si el valor recibido es numérico
 * \param array Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 */ int esNumerico(char array[]);

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param array Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */ int esSoloLetras(char array[]);

 /**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param array Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */ int esAlfanumerico(char array[]);



/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */ int getStringNumeros(char mensaje[],char input[]);

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */ int getStringLetras(char mensaje[],char input[]);

 /**
 * \brief Solicita un texto alfanumérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene numeros y letras
 */ int getStringAlfaNumerico(char mensaje[],char input[]);

/**
 * \brief Verifica si la cadena ingresada es numerica y de no serlo muestra mensaje de error
 * \param str Array con la cadena a ser analizada
 * \return int valor cambiado a entero
 */ int ingresoStringNumerico(char mensaje[]);

/** \brief pide un string numerico, lo valida como tal, muestra error o lo transforma a entero y verifica que este entre x rango
 *
 * \param mensaje el item a validar "Ingrese *mensaje*:"
 * \param min, max rango
 * \return int numero validado
 */ int validarDatoMaxMin(int dato, char mensaje[], int min, int max);

/** \brief genera una web con las peliculas cargadas en base de datos
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param nombre[] char string con el nombre de la pelicula
 * \return void
 *
 */
void generarPagina(EMovie* peliculas,int length,char nombre[]);

/** \brief busca un indice libre para cargar nueva pelicula
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param index int* -1 para buscar cual esta vacio
 * \return int devuelve el indice libre
 *
 */
int buscarLibre(EMovie* peliculas,int length,int* index);

/** \brief inicializa los estaods en -1, vacio
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \return void
 *
 */
void inicializarEstados(EMovie* peliculas,int length);

/** \brief carga las peliculas de la base de datos
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param contador int cuenta las peliculas ingresadas
 * \return void
 */
void cargarPelicula(EMovie* peliculas,int length,int* contador);

/** \brief muestra pelicula
 *
 * \param peliculas EMovie*
 * \param length int tamaño del array de estructuras
 * \return void
 */
void mostrarPelicula(EMovie* peliculas,int length);

/** \brief da de alta una pelicula pidiendo sus datos
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \return void
 */
void alta(EMovie* peliculas,int length,int* contador);

/** \brief busca una pelicula segun el id ingresado
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param id int id ingresado
 * \return int devuelve el indice correspondiente a la pelicula
 */
int buscarPelicula(EMovie* peliculas,int length,int id);

/** \brief modifica una pelicula de la base de datos
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \param contador int cuenta las peliculas ingresadas
 * \return void
 */
void modificarPelicula(EMovie* peliculas,int length,int* contador);

/** \brief genera un id autoincremental
 *
 * \param peliculas EMovie* puntero a estructura
 * \param length int tamaño del array de estructuras
 * \return int id
 */
int idIncremental(EMovie* peliculas,int length);

#endif // FUNCIONES_H_INCLUDED
