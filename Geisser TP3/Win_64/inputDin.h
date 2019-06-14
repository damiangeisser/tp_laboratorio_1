#ifndef INPUTDIN_H_INCLUDED
#define INPUTDIN_H_INCLUDED

/**
* \brief Solicita un número entero al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [1]
*
*/
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita un número real al usuario y lo valida
* \param input Se carga el numero ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el numero [0] si no [1]
*
*/
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit);

/**
* \brief Solicita un caracter al usuario y lo valida
* \param input Se carga el caracter ingresado
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Limite inferior a validar
* \param hiLimit Limite superior a validar
* \return Si obtuvo el caracter [0] si no [1]
*
*/
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario y la valida
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita una caracter para el sexo al usuario y valida que sea f o m.
* \param input Carga el char ingresado.
* \param message Es el mensaje a ser mostrado.
* \param eMessage Es el mensaje a ser mostrado en caso de error.
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getCharGender(char* input,char message[],char eMessage[]);

/**
* \brief Permite el ingreso de una fecha. Valida si el año es bisiesto y el número de días de cada mes.
* \param inputY Carga el año ingresado.
* \param inputM Carga el número del mes ingresado.
* \param inputD Carga el número del día ingresado.
* \param message Es el mensaje a ser mostrado concatenado con "Ingrese la fecha de ".
* \param yLowLimit Limite inferior a validar para los años.
* \param yHiLimit Limite superior a validar para los años.
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit);

/**
* \brief Valida si los caracteres de un vector son todos numeros.
* \param input Carga el vector a analizar.
* \return Si la cadena contiene al menos un caracter no númerico [0] si no [1]
*
*/
int checkNum(char* input);

/**
* \brief Valida si los caracteres de un vector son todas letras.
* \param input Carga el vector a analizar.
* \return Si la cadena contiene al menos un caracter que no sea una letra [0] si no [1]
*
*/
int checkLetter(char* input);

/**
* \brief Pasa a mayúscula la primera letra de cada palabra en una cadena de caracteres.
* \param input Carga el vector a convertir.
* \return Retorna [0] al finalizar.
*
*/
int titleCase(char* input);

/**
* \brief Valida la existencia de un caracter determinado una cantidad de veces entre 1 y un máximo establecido.
* \param input Carga el vector a analizar.
* \param target Carga caracter a buscar.
* \param maxCopies Carga la cantidad máxima de veces que debe aparecer el caracter elegido.
* \return Si la cadena no contiene al caracter buscado o lo hace una cantidad mayor de veces [0] si no [1]
*
*/
int checkSymbol(char* input, char target, int maxCopies);

/**
* \brief Solicita una cadena de caracteres al usuario compuesta exclusivamente por números con un largo mínimo y máximo determinado.
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getPhone(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario compuesta exclusivamente por letras con un largo mínimo y máximo determinado y deja la primera letra en mayúsculas.
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

/**
* \brief Solicita una cadena de caracteres al usuario que debe incluir '@' y al menos un '.' con un largo mínimo y máximo determinado.
* \param input Se carga la cadena ingresada
* \param message Es el mensaje a ser mostrado
* \param eMessage Es el mensaje a ser mostrado en caso de error
* \param lowLimit Longitud mínima de la cadena
* \param hiLimit Longitud máxima de la cadena
* \return Si obtuvo la cadena [0] si no [1]
*
*/
int getEmail(char* input,char message[],char eMessage[], int lowLimit, int hiLimit);

#endif // INPUTDIN_H_INCLUDED
