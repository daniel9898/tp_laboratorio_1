#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"

#define MAX 10

/** \brief genera una pagina web
 * \param movie la estructura de donde se extraeran los datos
 * \param longitud cantidad maxima de elementos
 * \return -
 *
 */
 void generarPaginaWeb(EMovie *movie,int longitud)
 {
     int i;
     char auxNombre[200];
     int cantidadCar;

     FILE *f;
     printf("***GENERAR PAGINA WEB***\n\n");

     printf("Ingrese el nombre  :\n ");
     fflush(stdin);
     gets(auxNombre);

     cantidadCar=strlen(auxNombre);
     while (cantidadCar<1 || cantidadCar>30)
     {
         printf("datos invalidos para la pagina,reingrese :\n ");
         fflush(stdin);
         gets(auxNombre);
         cantidadCar=strlen(auxNombre);
     }
     strcat(auxNombre,".html");

     f=fopen(auxNombre, "w");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        for(i=0; i<longitud; i++)
        {
            if (movie[i].estado==1)
            {
                fprintf(f,"<html lang='en'><head><meta charset='utf-8'><meta http-equiv='X-UA-Compatible' content='IE=edge'><meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css'   rel='stylesheet'><link href='css/custom.css'    rel='stylesheet'></head><body><div class='container'><div class='row'> ");
                fprintf(f,"<article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''></a><h3><a href='#'>%s </a></h3><ul><li>Genero:%s </li><li>Puntaje:%d </li><li>Duracion:%s </li></ul><p>%s </p></article><br><br><HR>",movie[i].link,movie[i].titulo,movie[i].genero,movie[i].puntaje,movie[i].duracion,movie[i].descripcion);
                fprintf(f,"</div></div><script src='js/jquery-1.11.3.min.js'    ></script><script src='js/bootstrap.min.js'   ></script><script src='js/ie10-viewport-bug-workaround.js'    ></script><script src='js/holder.min.js'   ></script></body></body>");
            }

        }
    }
     fclose(f);

      printf("Listado de peliculas creado exitosamente\n");
      system("pause");
      system("cls");
 }
/** \brief carga las estructuras desde un archivo binario
 * \param movie estructura donde se van a cargar los datos
 * \return 1 sino pudo cargar o si pudo
 */
 int cargarDesdeArchivo(EMovie *movie)
 {
    int flag = 0;
	FILE *f;

	f=fopen("bin.dat", "rb");

	if(f==NULL)
	{
		f= fopen("bin.dat", "wb");
		if(f==NULL)
		{
			return 1;
		}

		flag=1;

	}

	if(flag ==0)
	{
	fread(movie,sizeof(EMovie),MAX,f);
    }

	fclose(f);
	return 0;

 }
/** \brief guarda los datos en un archivo binario
 * \param movie estructura desde donde se copiaran los datos
 * \return 1 sino pudo guardar 0 si pudo
 */
 int guardarEnArchivo(EMovie *movie)
 {
     	FILE *f;

		f=fopen("bin.dat","wb");
		if(f == NULL)
		{
			return 1;
		}

	fwrite(movie,sizeof(EMovie),MAX,f);

	fclose(f);

	return 0;

 }

