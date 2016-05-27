#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"
#include "archivosBin.h"

#define MAX 10

int main()
{
    EMovie peliculas[MAX];

    char seguir='s';
    int opcion=0;
    int resp;
    int i;

    InicializarArrayPeliculas(peliculas,MAX);

    if(cargarDesdeArchivo(peliculas)==1)
	{
		printf("No se pudo abrir el fichero\n");
		exit(1);
	}
	else
	{
		printf("Se cargaron las estructuras con exito\n");
        system("pause");
	    system("cls");
	}


            while(seguir=='s')
       {
        printf("***ADMINISTRACION DE PELICULAS***\n\n");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");

        printf("5- Salir\n\n");

        opcion=TomarValidarCadSoloNumerica("ingrese una opcion :\n");

                if (opcion==0)
                    {
                        system("cls");
                        //continue;
                    }


                   switch(opcion)
                  {
                   case 1:
                   agregarPelicula(peliculas,MAX,"ingrese el titulo de la pelicula :","ingrese el genero :","ingrese la duracion ( 00:00 ) :","ingrese la descripcion :","ingrese puntaje ( 1 / 10 ) :","ingrese el link de imagen, puede copiar una url de cualquier imagen en la web y pegarla aqui :","titulo invalido ,solo letras,numeros y 50 caracteres como maximo ,reingrese :","genero invalido,reingrese :","duracion invalida reingrese :","descripcion invalida solo numeros,reingrese :","puntaje invalido solo numero 1/10 reingrese","link incorrecto reingrese :");

                   break;
                   case 2:
                         for(i=0; i<MAX; i++) //solo ingresa a este caso si hay alguna pelicula registrada
                                {
                                    if(peliculas[i].estado!=0)
                                    {
                                        borrarPelicula(peliculas,MAX);
                                        break;
                                    }
                                    else
                                        {
                                         printf("--Primero ingrese algun dato--\n");
                                         getch();
                                         system("cls");
                                         break;
                                        }
                                }

                   break;
                   case 3:
                           for(i=0; i<MAX; i++) //solo ingresa a este caso si hay alguna pelicula registrada
                                {
                                    if(peliculas[i].estado!=0)
                                    {
                                        ModificarDatosPeliculas(peliculas,MAX);
                                        break;
                                    }
                                    else
                                        {
                                         printf("--Primero ingrese algun dato--\n");
                                         getch();
                                         system("cls");
                                         break;
                                        }
                                }
                   break;
                   case 4:
                       for(i=0; i<MAX; i++) //solo ingresa a este caso si hay alguna pelicula registrada
                                {
                                    if(peliculas[i].estado!=0)
                                    {
                                        generarPaginaWeb(peliculas,MAX);
                                        break;
                                    }
                                    else
                                        {
                                         printf("--Primero ingrese algun dato--\n");
                                         getch();
                                         system("cls");
                                         break;
                                        }
                                }

                   break;
                   case 5:
                       printf("\nGuardar cambios S/N ?: ");
				       seguir = tolower(getche());
                    if(seguir == 's')
			     	{
                        if(guardarEnArchivo(peliculas)==1)
                        {
						printf("\nNo se pudo abrir el fichero\n");
                        }
					    else
					   {
						printf("\nSe guardo la informacion con exito\n");
                       }
				   }

                   seguir = 'n';
                   break;
                   default:
                       system("cls");
                   break;
                  }
         }


    return 0;
}



