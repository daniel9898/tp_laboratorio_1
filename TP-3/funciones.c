#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "funciones.h"

 /**
 * \brief Inicializa todas las filas del array en (o)
 * \param movie Es el array que se va a inicializar
 * \param longitud Indica la logitud del array
 * \return -
 *
 */
void InicializarArrayPeliculas(EMovie movie[],int longitud)
{
    int i;

    if (longitud > 0 && movie != NULL) // Invalid length or NULL pointer
     {
         for(i=0;i < longitud; i++)
         {
          movie[i].estado = 0;
         }
     }
      else
      {
        printf("Error no se pudo inicializar el array\n");
        system("pause");
	    system("cls");
      }

}
/** \brief toma un string y valida que sea numerico  y si lo es lo castea a entero
 * \param mensaje es el mensaje a ser mostrado
 * \return aux si es numerico o sino lo es
 */

int TomarValidarCadSoloNumerica(char mensaje[])
{
    int aux;
    char auxiliar[300] ;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);

    if(esNumerico(auxiliar)==1)
    {
        aux=atoi(auxiliar);
        return aux;
    }

    return 0;
}
/**
 * \brief Busca una pelicula por su nombre
 * \param movie Es el array en el cual buscar
 * \param longitud Indica la logitud del array
 * \return Si lo encuentra la posicion del mismo (i),sino (-1);
 */
 int BuscarPelicula(EMovie movie[],int longitud,char input[])// Busca por titulo
 {
     int i;

     if (longitud > 0 && movie != NULL) // Invalid length or NULL pointer
     {
            for(i=0; i< longitud; i++)
           {
                if (strcmp(input,movie[i].titulo)==0 && movie[i].estado==1 )
                {
                    return i;
                }
           }
     }

      return -1;
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

 /**
 * \brief Busca el primer lugar no utilizado en el array
 * \param movie Es el array en el cual buscar
 * \param longitud Indica la logitud del array
 * \return Si no hay lugares libres (-1) y si la hay la posicion del mismo (i)
 */
int BuscarPrimerLugarVacio(EMovie movie[],int longitud)
{
    int i;
    for(i=0;i < longitud; i++)
    {
        if(movie[i].estado==0)
        {
            return i;
        }
    }
    return -1;
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
