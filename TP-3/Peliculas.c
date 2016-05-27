#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Peliculas.h"
#include "funciones.h"

#define MAX 10

/** \brief registra una pelicula
 * \param movie es la estrucutura Emovie donde se guardaron los datos
 * \param dato1 es el mensaje a ser mostrado
* \param dato2 es el mensaje a ser mostrado
* \param dato3 es el mensaje a ser mostrado
* \param dato4 es el mensaje a ser mostrado
* \param dato5 es el mensaje a ser mostrado
* \param dato6 es el mensaje a ser mostrado
* \param Error1 es el mensaje a ser mostrado
* \param Error2 es el mensaje a ser mostrado
* \param Error3 es el mensaje a ser mostrado
* \param Error4 es el mensaje a ser mostrado
* \param Error5 es el mensaje a ser mostrado
* \param Error6 es el mensaje a ser mostrado
 * \return -
 *
 */
void agregarPelicula(EMovie movie[],int longitud,char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char dato6[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[],char Error6[])
{
    char auxTitulo[200];
    char auxGenero[200];
    char auxDuracion[200];
    char auxDescripcion[1000];
    char auxPuntaje[200];
    char auxLink[500];

    int cantCarac;
    int auxPunta;

    int indiceEncontrado;
    int indiceLugarVacio;

     if (longitud > 0 || movie != NULL)
     {


       indiceLugarVacio=BuscarPrimerLugarVacio(movie,MAX);

        if (indiceLugarVacio==-1)
          {
            printf("capacidad de almacenamiento completa!!\n\n");
            system("pause");
            system("cls");
          }
          else
          {

          printf("***ALTA PELICULAS***\n\n");

          puts(dato1);//titulo
          fflush(stdin);
          gets(auxTitulo);//solo letras

          cantCarac=strlen(auxTitulo);

          while (esAlfaNumerico(auxTitulo)!=1 || (cantCarac<1 || cantCarac>50) )
          {
              puts(Error1);
              fflush(stdin);
              gets(auxTitulo);
              cantCarac=strlen(auxTitulo);
          }
          strlwr(auxTitulo);
          auxTitulo[0]=toupper(auxTitulo[0]);

          indiceEncontrado=BuscarPelicula(movie,MAX,auxTitulo);

          if (indiceEncontrado!=-1  )
          {
              printf("la Pelicula ya esta registrada!\n");
              system("pause");
              system("cls");
          }
                    else
                    {

                     strcpy(movie[indiceLugarVacio].titulo,auxTitulo);

                     puts(dato2);// genero
                     fflush(stdin);
                     gets(auxGenero);

                     cantCarac=strlen(auxGenero);

                     while(esSoloLetras(auxGenero)==0 || cantCarac<1 || cantCarac>20 )
                     {
                      puts(Error2);
                      fflush(stdin);
                      gets(auxGenero);
                      cantCarac=strlen(auxGenero);
                     }

                    strlwr(auxGenero);
                    auxGenero[0]=toupper(auxGenero[0]);

                    strcpy(movie[indiceLugarVacio].genero,auxGenero);

                    puts(dato3);//duracion
                    fflush(stdin);
                    gets(auxDuracion);

                   cantCarac=strlen(auxDuracion);

                   while(esNumericoHora(auxDuracion)==0 || cantCarac<1 || cantCarac>5 )
                   {
                    puts(Error3);
                    fflush(stdin);
                    gets(auxDuracion);
                    cantCarac=strlen(auxDuracion);
                   }

                   strcpy(movie[indiceLugarVacio].duracion,auxDuracion);

                   puts(dato4);//Descripcion
                   fflush(stdin);
                   gets(auxDescripcion);

                   cantCarac=strlen(auxDescripcion);

                  while(esSoloLetrasComPun(auxDescripcion)==0 || cantCarac<1 || cantCarac>500)
                  {
                  puts(Error4);
                  fflush(stdin);
                  gets(auxDescripcion);
                  cantCarac=strlen(auxDescripcion);
                  }

                  /*strlwr(auxDescripcion);
                  auxDescripcion[0]=toupper(auxDescripcion[0]);*/

                  strcpy(movie[indiceLugarVacio].descripcion,auxDescripcion);

                  puts(dato5);//puntaje
                  fflush(stdin);
                  gets(auxPuntaje);

                  cantCarac=strlen(auxPuntaje);

                  while(esNumerico(auxPuntaje)!=1 || validarRAngoPuntaje(auxPunta=atoi(auxPuntaje),1,10)!=1 ||  (cantCarac<1) )
                  {
                  puts(Error5);
                  fflush(stdin);
                  gets(auxPuntaje);
                  cantCarac=strlen(auxPuntaje);
                  }

                 movie[indiceLugarVacio].puntaje=auxPunta;

                 puts(dato6);//link imagen
                 fflush(stdin);
                 gets(auxLink);

                cantCarac=strlen(auxLink);

                while(cantCarac<1)
                {
                puts(Error6);
                fflush(stdin);
                gets(auxLink);
                cantCarac=strlen(auxLink);
                }

                strcpy(movie[indiceLugarVacio].link,auxLink);

                movie[indiceLugarVacio].estado=1;
                //flagOpciones=1;

                printf("---A agregado una pelicula exitosamente---\n");
                system("pause");
                system("cls");

               /*printf("%s\n  %s\n  %s\n %s\n %d\n %s\n %d\n %d\n",movie[indiceLugarVacio].titulo,movie[indiceLugarVacio].genero,movie[indiceLugarVacio].duracion,movie[indiceLugarVacio].descripcion,movie[indiceLugarVacio].puntaje,movie[indiceLugarVacio].link,movie[indiceLugarVacio].estado,indiceLugarVacio);
               system("pause");*/

          }
      }

   }
   else
   {
       printf("no se pudo agregar la pelicula\n");
       system("pause");
       system("cls");
   }
}
/** \brief  borrar una pelicula
 * \param movie la estructura donde se buscara la pelicula
 * \param longitud cantidad maxima de elementos de la estructura
 * \return -
 *
 */
void borrarPelicula(EMovie movie[],int longitud)
{
    int indiceEncontrado;
    char auxTitulo[200];
    int cantCarac;

    if (longitud > 0 || movie != NULL)
    {
        printf("***BAJAS-PELICULAS**\n\n");
        printf("Ingrese el nombre de la pelicula :\n ");
        fflush(stdin);
        gets(auxTitulo);//solo letras

          cantCarac=strlen(auxTitulo);

          while (esAlfaNumerico(auxTitulo)!=1 || (cantCarac<1 || cantCarac>50) )
          {
              puts("titulo invalido reingrese por favor :\n");
              fflush(stdin);
              gets(auxTitulo);
              cantCarac=strlen(auxTitulo);
          }
          strlwr(auxTitulo);
          auxTitulo[0]=toupper(auxTitulo[0]);

          indiceEncontrado=BuscarPelicula(movie,MAX,auxTitulo);

              if (indiceEncontrado==-1)
             {
               printf("la pelicula que desea borrar no esta registrada\n");
               system("pause");
               system("cls");
             }

             else if (indiceEncontrado!=-1 && movie[indiceEncontrado].estado==1)
            {
             movie[indiceEncontrado].estado=0;
             printf("---A borrado una pelicula exitosamente---\n");
             system("pause");
             system("cls");
            }

    }
    else
    {
        printf("no se pudo agregar la pelicula\n");
        system("pause");
        system("cls");
    }


}
/** \brief modifica los datos seleccionados de una pelicula
 * \param movie es la estructura en la cual se modificaran datos
 * \param longitud cantidad maxima de elementos del array movie
 * \return -

 */
 void ModificarDatosPeliculas(EMovie movie[],int longitud)
 {
     char auxInput[200];

     int indiceEncontrado;

     int opcion;
     int seguir='s';

    char auxGenero[200];   //• Género • Duración • Descripción • Puntaje • Link de imagen
    char auxDuracion[200];
    char auxDescripcion[1000];
    char auxPuntaje[200];
    int auxPunta;
    char auxLink[200];

    int cantCarac;

    int flagMenu=0;
    int flagMenu1=0;
    int flagMenu2=0;
    int flagMenu3=0;
    int flagMenu4=0;

    if (longitud > 0 || movie != NULL)
    {

     printf("---para modificar datos ingrese el nombre de la pelicula por favor :\n");
     fflush(stdin);
     gets(auxInput);

     cantCarac=strlen(auxInput);

          while (esAlfaNumerico(auxInput)!=1 || (cantCarac<1 || cantCarac>50) )
          {
              puts("el nombre debe contener solo letras y numeros,reingrese :\n");
              fflush(stdin);
              gets(auxInput);
              cantCarac=strlen(auxInput);
          }
          strlwr(auxInput);
          auxInput[0]=toupper(auxInput[0]);

          indiceEncontrado=BuscarPelicula(movie,MAX,auxInput);

            if (indiceEncontrado!=-1)
           {
                    do
                    {
                        system("cls");
                        printf("**MODIFICACIONES**\n\n");

                        printf("Cuando algun dato sea modificado exitosamente se marcara con el siguiente simbolo ( %c )\n\n",174);

                        printf("DATOS ENCONTRADOS :\n\n");


                        if (flagMenu==0)
                          printf("1-GENERO :  %4s\n",movie[indiceEncontrado].genero);
                        else
                          printf("1-GENERO :  %4s %c\n",movie[indiceEncontrado].genero,174);


                        if (flagMenu1==0)
                          printf("2-DURACION :  %s\n",movie[indiceEncontrado].duracion);
                        else
                          printf("2-DURACION :  %s %c\n",movie[indiceEncontrado].duracion,174);


                        if (flagMenu2==0)
                          printf("3-DESCRIPCION :  %4s\n\n",movie[indiceEncontrado].descripcion);
                        else
                          printf("3-DESCRIPCION :  %4s %c\n\n",movie[indiceEncontrado].descripcion,174);

                        if (flagMenu3==0)
                          printf("4-PUNTAJE :  %d\n",movie[indiceEncontrado].puntaje);
                        else
                          printf("4-PUNTAJE :  %d %c\n",movie[indiceEncontrado].puntaje,174);

                        if (flagMenu4==0)
                          printf("5-LINK IMAGEN :  %4s\n",movie[indiceEncontrado].link);
                        else
                          printf("5-LINK IMAGEN :  %4s %c\n\n",movie[indiceEncontrado].link,174);

                          printf("\n6-SALIR\n");




                        opcion=TomarValidarCadSoloNumerica("\n\nEliga la opcion correspondiente al dato a modificar :\n\n ");

                                if (opcion==0)
                                  {
                                     printf("dato invalido.\n");
                                     system("pause");
                                     continue;
                                  }


                    switch(opcion)
                    {
                    case 1:
                    printf("ingrese el nuevo genero :");
                    fflush(stdin);
                    gets(auxGenero);

                    cantCarac=strlen(auxGenero);

                     while(esSoloLetras(auxGenero)==0 || cantCarac<1 || cantCarac>20 )
                     {
                      puts("dato invalido :\n");
                      fflush(stdin);
                      gets(auxGenero);
                      cantCarac=strlen(auxGenero);
                     }

                    strlwr(auxGenero);
                    auxGenero[0]=toupper(auxGenero[0]);

                    strcpy(movie[indiceEncontrado].genero,auxGenero);

                    flagMenu=1;
                    break;

                    case 2 :
                    printf("ingrese la nueva duracion :" );
                    fflush(stdin);
                    gets(auxDuracion);

                    cantCarac=strlen(auxDuracion);

                    while(esNumericoHora(auxDuracion)==0 || cantCarac<1 || cantCarac>5 )
                   {
                    puts("dato invalido,reingrese :\n");
                    fflush(stdin);
                    gets(auxDuracion);
                    cantCarac=strlen(auxDuracion);
                   }

                   strcpy(movie[indiceEncontrado].duracion,auxDuracion);
                   flagMenu1=1;

                   break;

                   case 3:
                    printf("ingrese la nueva descripcion :");
                    fflush(stdin);
                    gets(auxDescripcion);

                    cantCarac=strlen(auxDescripcion);

                    while(esSoloLetrasComPun(auxDescripcion)==0 || cantCarac<1 || cantCarac>500)
                  {
                  puts("descripcion invalida,reingrese :\n");
                  fflush(stdin);
                  gets(auxDescripcion);
                  cantCarac=strlen(auxDescripcion);
                  }

                  strlwr(auxDescripcion);
                  auxDescripcion[0]=toupper(auxDescripcion[0]);

                  strcpy(movie[indiceEncontrado].descripcion,auxDescripcion);
                  flagMenu2=1;
                  break;

                  case 4:
                  printf("ingrese el nuevo puntaje :\n");
                  fflush(stdin);
                  scanf("%s",auxPuntaje);

                  cantCarac=strlen(auxPuntaje);

                  while(esNumerico(auxPuntaje)!=1 || validarRAngoPuntaje(auxPunta=atoi(auxPuntaje),1,10)!=1 ||  (cantCarac<1) )
                  {
                  puts("ingrese solo numeros para el puntaje :\n");
                  fflush(stdin);
                  gets(auxPuntaje);
                  cantCarac=strlen(auxPuntaje);
                  }

                 movie[indiceEncontrado].puntaje=auxPunta;
                 flagMenu3=1;

                 break;

                case 5:
                 puts("ingrese el nuevo link :\n");
                 fflush(stdin);
                 gets(auxLink);

                cantCarac=strlen(auxLink);

                while(cantCarac<1)
                {
                puts("link invalido,reingrese :\n");
                fflush(stdin);
                gets(auxLink);
                cantCarac=strlen(auxLink);
                }

                strcpy(movie[indiceEncontrado].link,auxLink);
                flagMenu4=1;

                break;

                case 6:
                seguir='n';
                system("cls");
                break;

                default:
                printf("dato invalido.\n");
                system("pause");
                break;

                                  }

                    } while(seguir=='s');
            }

            else
            {
              printf("--La Pelicula no esta registrada---\n");
              system("pause");
              system("cls");
            }
    }
    else
    {
        printf("no se pudo Modificar la pelicula la pelicula\n");
        system("pause");
        system("cls");
    }

 }
