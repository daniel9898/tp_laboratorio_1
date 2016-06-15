 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"
#include "ArchivosBin.h"
#include "-ArrayList.h"


/** \brief toma un string y valida que sea numerico  y si lo es lo castea a entero
 * \param mensaje es el mensaje a ser mostrado
 * \return aux si es numerico o sino lo es
 */

int TomarValidarCadSoloNumerica(char mensaje[])
{
    int aux;
    int retorno;
    char auxiliar[300] ;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);

    if(esNumerico(auxiliar)==1)
    {
        aux=atoi(auxiliar);
        retorno=aux;
    }
    else
        retorno=0;

    return retorno;
}

/** \brief valida que el puntaje este en un parametro establecido
 *\param numero numero a ser analizado
 * \param minimo aceptable
 * \param maximo aceptable
 * \return 1 si es correcto 0 sino no lo es
 *
 */
int validarRAngoPuntaje(int numero,int minimo,int maximo)
{
    int esValido=0;
    if (numero>=minimo && numero<=maximo)
    {
        return 1;
    }
    return esValido;
}

/** \brief verifica si el valor recibido contiene solo letras
 * \param str,array con la cadena a ser analizada
 * \return 1 si es solo letras 0 sino lo es
 *
 */
int esSoloLetras(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}
/** \brief verifica si el valor recibido contiene solo letras, espacios,puntos y comas
 * \param str,array con la cadena a ser analizada
 * \return 1 si es solo letras 0 sino lo es
 *
 */
int esSoloLetrasComPun(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] != '.') && (str[i] != ',') /*&& (str[i] != 'á'  )&& (str[i] != 'é'  )&& (str[i] != 'í'  )&& (str[i] != 'ó'  )&& (str[i] != 'ú'  )&& (str[i] != 'Á'  )&& (str[i] != 'É'  )&& (str[i] != 'Í'  )&& (str[i] !='Ó')&& (str[i] != 'Ú' )&& (str[i] != '´' )*/)
            return 0;
        i++;
    }
    return 1;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
            return 0;
        i++;
    }
    return 1;
}
/** \brief  verifica si el valor recibido es numerico y si contiene ( : )
* \param str,array con la cadena a ser analizada
* \return 1 si es numerico 0 sino lo es
*/
int esNumericoHora(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(  (str[i] <'0' || str[i]>'9') && (str[i] != ':') )
            return 0;
        i ++;
    }
    return 1;
}
/** \brief  verifica si el valor recibido es numerico
 * \param str,array con la cadena a ser analizada
 * \return 1 si es numerico 0 sino lo es
 */
int esNumerico(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] <'0' || str[i]>'9')
            return 0;
        i ++;
    }
    return 1;
}
