#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Peliculas.h"
#include "funciones.h"
#include "ArchivosBin.h"
#include "-ArrayList.h"

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int cargarSIZEdesArchivo(ArrayList* plist,ArrayList* plistBajas)
{
    FILE *F1;

    int flag = 0;
    int retorno;

//**************Si es la primera vez que ejecutamos********************

    if (plist->size==0)
        cant=0;
    else
        cant=plist->size;

    if (plistBajas->size==0)
        cant2=0;
    else
        cant2=plistBajas->size;

//***************************************************************************
    F1=fopen("Size.dat", "rb");

    if(F1==NULL)
    {
        F1= fopen("Size.dat", "wb");//sino exite el archivo el modo wb lo crea ,si se abre en modo escritura no se puede leer
        if(F1==NULL)
        {
            retorno= 1;
            flag=1;
        }

    }
    if(flag ==0 && plist != NULL && plistBajas!= NULL)
    {
        fread(&cant,sizeof(int),1,F1);
        fread(&cant2,sizeof(int),1,F1);
        retorno=0;
    }
    fclose(F1);
    return retorno;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
int GuardarSizeEnArchivo(ArrayList* plist,ArrayList* plistBajas)
{
    FILE *F1;
    int retorno;

    cant=plist->size;
    cant2=plistBajas->size;

    F1=fopen("Size.dat", "wb");

    if(F1==NULL)
        retorno=-1;
    else if (plist!=NULL && plistBajas!=NULL)
    {
        fwrite(&cant,sizeof(int),1,F1);
        fwrite(&cant2,sizeof(int),1,F1);
        retorno=0;
    }

    fclose(F1);

    return retorno;
}
/** \brief carga las estructuras desde un archivo binario
 * \param movie estructura donde se van a cargar los datos
 * \return 1 sino pudo cargar o si pudo
 */
int cargarDesdeArchivo(ArrayList* plist,ArrayList* plistbajas)//

{
    FILE *f;

    int flag = 0;
    int retorno;
    int i;

    f=fopen("bin.dat", "rb");

    if(f==NULL)
    {
        f= fopen("bin.dat", "wb");//sino exite el archivo el modo wb lo crea ,si se abre en modo escritura no se puede leer
        if(f==NULL)
        {
            retorno= 1;
        }
        flag=1;
    }

    if(flag ==0 && plist != NULL)
    {
        //printf("dentro de cargar desde archivo cant:%d cant2:%d\n",cant,cant2);//llegan bien los valores
        //getch();
        for (i=0; i<cant; i++)
        {
            EMovie*Pmovies = (EMovie*) malloc(sizeof(EMovie));
            if (Pmovies != NULL)
            {
                fread(Pmovies,sizeof(EMovie),1,f);
                retorno=plist->add(plist,Pmovies);
            }

        }
        for (i=0; i<cant2; i++)
        {
            EMovie*Ptmovies = (EMovie*) malloc(sizeof(EMovie));
            if (Ptmovies != NULL)
            {
                fread(Ptmovies,sizeof(EMovie),1,f);
                retorno=plistbajas->add(plistbajas,Ptmovies);
            }
        }
        retorno= 0;
    }

    fclose(f);

    return retorno;

}
/** \brief guarda los datos en un archivo binario
 * \param movie estructura desde donde se copiaran los datos
 * \return 1 sino pudo guardar 0 si pudo
 */
int guardarEnArchivo(EMovie *movie,ArrayList* plist,ArrayList* plistBajas)
{
    FILE *f;
    int retorno;
    int i;

    void* ptr;

    f=fopen("bin.dat","wb");
    if(f == NULL)
        retorno= 1;
    else
    {
        for (i=0; i<al_len(plist); i++)
        {
            ptr=al_get(plist,i);
            movie=(EMovie*)ptr;
            fwrite(movie,sizeof(EMovie),1,f);
        }
        if (al_len(plistBajas)>0)
        {
            for (i=0; i<al_len(plistBajas); i++)
            {
                movie=al_get(plistBajas,i);
                fwrite(movie,sizeof(EMovie),1,f);
            }
        }
        retorno=0;
    }

    fclose(f);

    return retorno;

}
