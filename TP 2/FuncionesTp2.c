#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesTp2.h"


/**
 * \brief Inicializa todas las filas del array en (o)
 * \param unaPersona Es el array que se va a inicializar
 * \param longitud Indica la logitud del array
 * \return -
 *
 */
void InicializarArray(EPersona unaPersona[],int longitud)
{
    int i;
    for(i=0;i < longitud; i++)
    {
        unaPersona[i].estado = 0;
    }
}
/**
 * \brief Busca el primer lugar no utilizado en el array
 * \param unaPersona Es el array en el cual buscar
 * \param longitud Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 */
int BuscarPrimerLugarVacio(EPersona unaPersona[],int longitud)
{
    int i;
    for(i=0;i < longitud; i++)
    {
        if(unaPersona[i].estado== 0)
        {
            return i;
        }
    }
    return -1;
}
/**
 * \brief Busca la persona por su dni
 * \param unaPersona Es el array en el cual buscar
 * \param longitud Indica la logitud del array
 * \return Si lo encuentra la posicion del mismo (i),sino (-1);
 */
 int BuscarPersonaPorDni(EPersona unaPersona[],int longitud,long int dni)
 {
     int i;
      for(i=0; i< longitud; i++)
      {
          if (unaPersona[i].dni == dni && unaPersona[i].estado==1 )
          {
              return i;
          }
      }
      return -1;
 }
 /** \brief  valida un entero entre ciertos parametros
 * \param int numero,numero ingresado por el usuario,a validar
 * \param int desde,minimo numero aceptado
  *\param int hasta,maximo numero aceptado
 * \return un numero entero 1 o 0
 */
int validarRangoEdad(int numero,int minimo,int maximo)
{
     int esValido=0;
     if (numero>=minimo && numero<=maximo)
     {
         return 1;
     }
     return esValido;
}
 /** \brief  valida un entero largo entre ciertos parametros
 * \param long int numero,numero ingresado por el usuario,a validar
 * \param long int desde,minimo numero aceptado
  *\param long int hasta,maximo numero aceptado
 * \return un numero entero 1 o 0
 */
  int validarRAngoDni(long int numero,long int minimo,long int maximo)
 {
     int esValido=0;
     if (numero>=minimo && numero<=maximo)
     {
         return 1;
     }
     return esValido;
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
 /** \brief  verifica si el valor recibido contiene solo letras
 * \param str,array con la cadena a ser analizada
 * \return 1 contiene solo letras 0 sino lo es
 */
 int esSoloLetras(char str[])
 {
    int i=0;
      while(str[i] != '\0')
      {
          if((str[i] != ' ') && (str[i]<'a' || str[i]>'z') && (str[i]<'A' || str[i]>'Z'))
          {
              return 0;
          }
            i++;
      }
      return 1;
 }

