#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"
#include "ArchivosBin.h"
#include "-ArrayList.h"

int main()
{

    ArrayList* pList=al_newArrayList();//FUNCION 1
    EMovie* movie;

    ArrayList* PlistBajas=al_newArrayList(); // para guardar las bajas

    //************cargamos los datos desde un archivo binario*****************

    cargarSIZEdesArchivo(pList,PlistBajas);

    if(cargarDesdeArchivo(pList,PlistBajas)==1)
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

//*******************************************************************

    char seguir='s';
    int opcion=0;
    int retorn;

    while(seguir=='s')
    {
        printf("\n*** %c ADMINISTRACION DE PELICULAS %c ***\n\n",178,178);
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Ver el total de peliculas cargadas\n");
        printf("5- Ordenar las peliculas Por titulo\n");
        printf("6- Ver lista de peliculas dadas de baja\n");
        printf(">>>>>> 7-Borrar todas las peliculas dadas de baja\n");
        //printf("8- Ver lista especifica de peliculas cargadas\n\n");
        printf("8- Guardar y Salir\n\n");


        opcion=TomarValidarCadSoloNumerica("ingrese una opcion :\n\n");

        if (opcion==0)
            system("cls");

        switch(opcion)
        {
        case 1:
            movie=agregarPelicula(pList,"ingrese el titulo de la pelicula :","ingrese el genero :","ingrese la duracion ( 00:00 ) :","ingrese la descripcion :","ingrese puntaje ( 1 / 10 ) :","titulo invalido ,solo letras,numeros y 50 caracteres como maximo ,reingrese :","genero invalido,reingrese :","duracion invalida reingrese :","descripcion invalida solo numeros,reingrese :","puntaje invalido solo numero 1/10 reingrese");
            retorn=pList->add(pList,movie);  // cargamos el puntero movie ala lista //FUNCION 2

            if (retorn==0)
            {
                printf("---A agregado una pelicula exitosamente---\n");
                getch();
                system("cls");
            }
            break;

        case 2:
            if (pList->len(pList)>0)// solo ingresa a este case si hay por lo menos una pelicula cargada // FUNCION 4
            {
                retorn=DeleteMovie(pList,PlistBajas);
                if (retorn==0)
                {
                    printf("---A borrado una pelicula exitosamente---");
                    getch();
                    system("cls");
                }

            }
            else
            {
                printf("primero ingrese algun dato!\n");
                getch();
                system("cls");
            }

            break;

        case 3:
            retorn=pList->isEmpty(pList);//verificamos que el size no sea igual a cero para ingresar//FUNCION 13
            if (retorn != 1)
            {
                modifyMovie(pList,movie);
            }
            else
            {
                printf("primero ingrese algun dato!\n");
                getch();
                system("cls");
            }
            break;

        case 4:
            retorn=pList->isEmpty(pList);
            if (retorn != 1)
            {
                system("cls");
                printArrayListMovies(pList);
                system("pause");
                system("cls");
            }
            else
            {
                printf("primero ingrese algun dato!\n");
                getch();
                system("cls");
            }
            break;

        case 5:
            retorn=pList->isEmpty(pList);
            if (retorn != 1)
            {
                system("cls");
                printf("--Presione (1) para ordenar Ascendentemente\n");
                printf("--Presione (2) para ordenar descendentemente\n\n");
                opcion=TomarValidarCadSoloNumerica("ingrese una opcion :\n\n");

                while (opcion==0)
                {
                    system("cls");
                    printf("--Presione (1) para ordenar Ascendentemente\n");
                    printf("--Presione (2) para ordenar descendentemente\n\n");
                    opcion=TomarValidarCadSoloNumerica("ingrese una opcion :\n\n");
                }
//*********Submenu para para validar los parametros de ordenamiento*******

                switch(opcion)
                {
                case 1:
                    printf("ORDEN : %c %c %c\n\n",24,24,24);
                    retorn=pList->sort(pList,compareMovie,0);
                    if (retorn!=-1)
                    {
                        printArrayListMovies(pList);
                        getch();
                        system("cls");
                    }
                    break;

                case 2:
                    printf("ORDEN : %c %c %c\n\n",25,25,25);
                    retorn=pList->sort(pList,compareMovie,1);
                    if (retorn!=-1)
                    {
                        printArrayListMovies(pList);
                        getch();
                        system("cls");
                    }
                    break;

                default:
                    printf("dato invalido.\n");
                    getch();
                    system("cls");
                    break;
                }

            }
            else
            {
                printf("primero ingrese algun dato!\n");
                getch();
                system("cls");
            }
            break;
//*****************************************************************************
        case 6:
            if (pList->len(PlistBajas)>0)// solo ingresa a este case si hay por lo menos una pelicula cargada // FUNCION 4
            {
                system("cls");
                printArrayListMovies(PlistBajas);
                getch();
                system("cls");
            }
            else
            {
                printf("Primero debe borrar alguna pelicula!\n");
                getch();
                system("cls");
            }
            break;

        case 7:
            if (pList->len(PlistBajas)>0)// solo ingresa a este case si hay por lo menos una pelicula cargada // FUNCION 4
            {
                retorn=pList->remove(PlistBajas,0); // FUNCION 8
                if (retorn==0)
                {
                    printf("---A borrado la lista de bajas exitosamente---");
                    getch();
                    system("cls");
                }

            }
            else
            {
                printf("Primero debe borrar alguna pelicula!\n");
                getch();
                system("cls");
            }
            break;
        case 8:
            printf("\nGuardar cambios S/N ?: ");
            seguir = tolower(getche());
            if(seguir == 's')
            {
                if(guardarEnArchivo(movie,pList,PlistBajas)==1 || GuardarSizeEnArchivo(pList,PlistBajas)==-1)
                {
                    printf("\nNo se pudo abrir el fichero\n");
                }
                else
                {

                    printf("\nSe guardo la informacion con exito\n");
                }
            }

            //*************Liberamos recursos y salimos******************

            pList->clear(pList);
            PlistBajas->clear(PlistBajas);
            pList->deleteArrayList(pList);
            PlistBajas->deleteArrayList(PlistBajas);

            seguir = 'n';
            break;

        default:
            system("cls");
            break;
        }
    }


    return 0;
}

