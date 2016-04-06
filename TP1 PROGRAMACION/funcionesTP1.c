#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/** \brief suma los 2 numeros ingresados por el usuario
 * \param x primer numero ingresado
 * \param y segundo numero ingresado
 * \return la suma de dichos numeros
 */
float suma(float x,float y)
 {
     float suma=x+y;
     return suma;
 }
 /** \brief resta los 2 numeros ingresados por el usuario
 * \param x primer numero ingresado
 * \param y segundo numero ingresado
 * \return la resta de dichos numeros
 */
float resta(float x,float y)
 {
     float resta=x-y;
     return resta;
 }
/** \brief Divide los 2 numeros ingresados por el usuario
 * \param x primer numero ingresado
 * \param y segundo numero ingresado
 * \return resultado de la division de dichos numeros
 */

 float division(float x,float y)
 {
     float division=x/y;
     if (y==0)
     {
         printf("No se puede dividir un numero entre 0 !!\n");
     }
     else
     {
         return printf("La division es %.2f \n",division);
     }
 }

   /** \brief Multiplica los 2 numeros ingresados por el usuario
 * \param x primer numero ingresado
 * \param y segundo numero ingresado
 * \return el producto de dichos numeros
 */
float multiplicacion(float x,float y)
 {
     float multiplicacion=x*y;
     return multiplicacion;
 }

/** \brief calcula el factorial del primer numero ingresado por el usuario
 * \param x primer numero ingresado
 * \return resultado del factorial
 */

double factorial(float x)
{
    double fac;
    if ( x>1)
    {
        fac=x * factorial(x-1);
    }
    else if (x==0 || x==1)
    {
        fac=1;
    }
 return fac;

}

