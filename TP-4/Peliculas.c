#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"
#include "ArchivosBin.h"
#include "-ArrayList.h"

/** \brief imprime en pantalla la lista completa de peliculas cargadas en el arraylist
 * \param lista lista de la cual obtendra los datos a imprimir
 * \return -
 *
 */

void printArrayListMovies(ArrayList* lista)

{
    int i=0;
    for(i=0; i<lista->len(lista); i++)
    {
        EMovie* pAux = lista->get(lista,i);
        printf("Indice %d)\n\n",i);
        PrintMovie(pAux);
    }
}
/** \brief imprime en pantalla  solo los titulos de todas las peliculas cargadas en el arraylist
 * \param lista lista de la cual obtendra los datos a imprimir
 * \return -
 *
 */

void printArrayListMoviesTitle(ArrayList* lista)

{
    int i=0;
    for(i=0; i<lista->len(lista); i++)
    {
        EMovie* pAux = lista->get(lista,i);
        printf("Indice %d)\n\n",i);
        PrintMovieTitle(pAux);
    }
}
/** \brief obtiene un indice del arrayList atravez del campo titulo de la struct Emovie
 * \param plist lista en la cual buscara
 * \param input nombre de la pelicula ingresada
 * \return (-1) sino lo encontro, el indice si encuentra el elemento
 *
 */
int getIndex(ArrayList*plist,char input[])//obtener el indice de un elemento atravez del campo nombre de una pelicula
{
    int i;
    int indexFound=-1;
    int retorn;

    EMovie *auxM;
    void* aux;

    if (plist != NULL )
    {
            for (i=0; i<plist->size; i++)
               {
                 aux=al_get(plist,i); //guardamos el puntero void que retorna al_get en un auxiliar puntero void
                 auxM=(EMovie*)aux; // el puntero void retornado lo casteamos a emovie y lo asignamos al puntero emovie
                 retorn=strcmp(auxM->titulo,input);
                     if (retorn==0)
                    {
                       indexFound=i;
                       break;
                    }

                }
    }

  return   indexFound;

}
/** \brief imprime en pantalla  solo los titulos de todas las peliculas cargadas en la struc Emovie
 * \param p puntero que contiene el dato
 * \return -
 */

void PrintMovieTitle(EMovie* p)
{
    printf("--titulo:%s\r\n\n",p->titulo);
}
/** \brief  imprime en pantalla  todos los datos que contenga un puntero a Emovie
 * \param p puntero de donde obtendra el dato
 * \return -
 */

void PrintMovie(EMovie* p)
{
    printf("--titulo:%s\n--genero:%s\n--duracion:%s\n--descripcion:%s\n--puntaje:%d\n\r\n\n",p->titulo,p->genero,p->duracion,p->descripcion,p->puntaje);
}
/** \brief Busca una pelicula en el arrayList atravez del campo titulo de la struc Emovie
 * \param plist lista donde buscara el dato
 * \param input titulo ingresado por el usuario
 * \return (-1) si plist es NULL,(0) si es el primer ingreso (1) si encuentra la pelicula y (-2) si no la encuentra
 *
 */
int searchMovie(ArrayList*plist,char input[])
{
    int retorn=-1;
    int i;
    int flag=0;

    void* aux;
    EMovie *auxM;

    if (plist != NULL)
    {
           if (plist->len(plist)==0) // comprobamos si es la primera alta // FUNCION 4
           retorn=0;//si es el primer ingreso

          else
          {

                for (i=0; i<plist->size; i++) // FUNCION 5
               {
                   aux=al_get(plist,i); //guardamos el puntero void que retorna al_get en un auxiliar puntero void
                   auxM=(EMovie*)aux; // el puntero void retornado lo casteamos a emovie y lo asignamos al puntero emovie
                   if(strcmp(auxM->titulo,input) == 0)
                   {
                       flag = 1;
                       break;
                   }
                  // printf("valor de titulo en posicion %d :%s\n",i,auxM->titulo+i);//revisar en cada iteracion se pierde un char por eso siempre da distinto
               }
                   if (flag)
                   {
                       retorn = 1;
                   }
                   else
                   {
                       retorn = -2;
                   }
            }

    }
    return retorn;
}

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

EMovie* agregarPelicula(ArrayList* Plist,char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[])
{
    char auxTitulo[200];
    char auxGenero[200];
    char auxDuracion[200];
    char auxDescripcion[1000];
    char auxPuntaje[200];

    int auxPunta;

    int cantCarac;
    int retorn;

    EMovie* returnAux = NULL;
    EMovie*Pmovies = (EMovie*) malloc(sizeof(EMovie));

    if (Pmovies!= NULL && Plist !=NULL)
    {
        printf("***ALTA PELICULAS***\n\n");

//**************************************************************

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

//************** comprobamos que no exista la pelicula****************************


        retorn=searchMovie(Plist,auxTitulo);
        //printf("retorno=%d\n",retorn);
        if (retorn==1)
        {
            printf("la pelicula ya esta ingresada en el sistema!!\n");
            getch();
            system("cls");
        }
        else if (retorn==0 || retorn==-2)// si es la primera vez,o no lo encontro guardamos el dato
        {
            strcpy(Pmovies->titulo,auxTitulo);

//****************************************************************
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

            strcpy(Pmovies->genero,auxGenero);

//************************************************

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

            strcpy(Pmovies->duracion,auxDuracion);

//************************************************

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

            strcpy(Pmovies->descripcion,auxDescripcion);

//**********************************************************

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

            Pmovies->puntaje=auxPunta;

//****************************************************
            returnAux =Pmovies;
        }

    }
    return returnAux;
}
/** \brief  Borra una pelicula del arrayList
 * \param plist lista donde buscara la pelicula a borrar
 * \param plistBajas lista donde se guardaran los elementos borrados
 * \return  (-1) si alguna de las lista son NULL,(0) si tuvo exito
 *
 */
int DeleteMovie(ArrayList* Plist,ArrayList* PlistBajas)
{
    int returnAux=-1;
    int retorn;
    int retornADD;
    char auxInput[50];
    int cantCarac;

    void* retorno; // para verificar el retorno de al_pop
    void*AuxGet;
    EMovie *ptrMov;

    if (Plist != NULL && PlistBajas!= NULL)
    {
        printf("***BAJA- PELICULAS***\n\n");

        printf("ingrese el nombre de la pelicula :\n");//titulo
        fflush(stdin);
        gets(auxInput);//solo letras

        cantCarac=strlen(auxInput);

        while (esAlfaNumerico(auxInput)!=1 || (cantCarac<1 || cantCarac>50) )
        {
            printf("dato incorrecto,reingrese por favor :\n");
            fflush(stdin);
            gets(auxInput);
            cantCarac=strlen(auxInput);
        }
        strlwr(auxInput);
        auxInput[0]=toupper(auxInput[0]);

        retorn=getIndex(Plist,auxInput); // obtengo el indice
        if (retorn!=-1)
        {
            AuxGet=Plist->get(Plist,retorn);  //obtengo el puntero a borrar   con pop     //FUNCION 5   //FUNCION 14
            ptrMov=(EMovie*)AuxGet;

            printf("DATOS A BORRAR :\n\n");
            PrintMovie(ptrMov);
            getch();

            retorno=(EMovie*)Plist->pop(Plist,retorn); // usamos pop pasandole el indice encontrado para borrar el elemento y luego lo adherimos a plistbajas
            if (retorno!=NULL)
            {
                retornADD=PlistBajas->add(PlistBajas,retorno);
                  if (retornADD!=-1)
                  {
                     returnAux=0;
                  }

            }
        }
        else
        {
            printf("\nla pelicula que desea borrar no existe en el sistema!\n");
            getch();
            system("cls");
        }

    }

    return returnAux;
}
/** \brief Modifica los datos de un elemento del arraylist
 * \param plist lista en la cual buscara la pelicula a corregir
 * \param movie puntero donde guardaran los datos nuevos
 * \return -
 *
 */
void modifyMovie(ArrayList* Plist,EMovie *movie)
{
    char auxInput[200];
    int cantCarac;
    int retorn;

    int opcion;
    int seguir='s';
    int i;

    char auxGenero[200];   //• Género • Duración • Descripción • Puntaje • Link de imagen
    char auxDuracion[200];
    char auxDescripcion[1000];
    char auxPuntaje[200];
    int  auxPunta;

    int flagMenu=0;
    int flagMenu1=0;
    int flagMenu2=0;
    int flagMenu3=0;

    EMovie *AuxM;
    void *aux;

    if (Plist!= NULL && movie != NULL)
    {

        printf("---Para modificar datos ingrese el nombre de la pelicula por favor :\n");
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

        retorn=searchMovie(Plist,auxInput);

        if (retorn==1)   // obtener el indice
        {
                for (i=0; i<Plist->size; i++)
                 {
                  aux=al_get(Plist,i); //guardamos el puntero void que retorna al_get en un auxiliar puntero void
                  AuxM=(EMovie*)aux; // el puntero void retornado lo casteamos a emovie y lo asignamos al puntero emovie
                     if (strcmp(AuxM->titulo,auxInput)==0)
                    {
                       break;
                    }

                }


            do
            {
                system("cls");
                printf("**MODIFICACIONES**\n\n");

                printf("Cuando algun dato sea modificado exitosamente se marcara con el siguiente simbolo ( %c )\n\n",174);

                printf("_____DATOS ENCONTRADOS :\n\n");
                printf("*******NOMBRE DE LA PELICULA :%s\n\n",AuxM->titulo);

//***************Para poder cambiar en pantalla los datos impresos****************

                if (flagMenu==0)
                    printf("1-GENERO : %s\n",AuxM->genero);
                else
                    printf("1-GENERO : %s %c\n",AuxM->genero,174);


                if (flagMenu1==0)
                    printf("2-DURACION : %s\n",AuxM->duracion);
                else
                    printf("2-DURACION : %s %c\n",AuxM->duracion,174);


                if (flagMenu2==0)
                    printf("3-DESCRIPCION : %s\n",AuxM->descripcion);
                else
                    printf("3-DESCRIPCION : %s %c\n",AuxM->descripcion,174);

                if (flagMenu3==0)
                    printf("4-PUNTAJE : %d\n",AuxM->puntaje);
                else
                    printf("4-PUNTAJE : %d %c\n",AuxM->puntaje,174);

                    printf("\n5-SALIR");


//*************************************************************************************************

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

                    strcpy(movie->genero,auxGenero);
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

                    strcpy(movie->duracion,auxDuracion);
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

                    strcpy(movie->descripcion,auxDescripcion);
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

                    movie->puntaje=auxPunta;
                    flagMenu3=1;
                    break;

                case 5:
                    seguir='n';
                    system("cls");
                    break;

                default:
                    printf("dato invalido.\n");
                    system("pause");
                    break;

                }

            }
            while(seguir=='s');
        }

        else
        {
            printf("--La Pelicula no esta registrada---\n");
            getch();
            system("cls");
        }
    }

}
/** \brief compara 2 elementos Emovie del arrayList
 * \param movieA Primer elemento a comparar
 * \param movieB segundo elemento a comparar
 * \return (1) si el primer elemento es mayor al segundo, (-1) si el segundo es mayor y (0) si son iguales
 *
 */
int compareMovie(void*  movieA,void* movieB)
{
    int retorn;
    retorn=strcmp(  ((EMovie*)movieA)->titulo,((EMovie*)movieB)->titulo   );
    return retorn;
}

