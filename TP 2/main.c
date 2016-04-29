/*******************************************************************
*Programa: ABM
*
*Objetivo:
Ingresar datos de personas,dar de baja ,imprimirlos.

     Nombre[51]
     Edad
     Dni
*
*Version: 0.1 28 de abril del 2016
*Autor: Daniel Pereira
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "FuncionesTp2.h"

#define MAX_PERS 20

int main()
{
    EPersona unaPersona[MAX_PERS];
    EPersona auxPersona;

    char seguir='s';
    int opcion=0;
    int flagOpciones=0;
    int cantCaract;
    int resp; // se utilizara para almacenar retornos de funciones;

    char auxNombreStr[70];// se utilizaran para validar los datos ingresados
    char auxEdadStr[50];
    char auxDniStr[50];
    char auxOpcion[50];
    long int auxDni;
    int auxEdad;


    int indiceLugarVacio;
    int indiceEncontrado;

    int contadorMen18=0;
    int contadorMay35=0;
    int contadorResto=0;   // personas entre 19 y 35 años.

    int i , j ;

    int max=0;  //utilizado para el grafico

    InicializarArray(unaPersona,MAX_PERS);

    while(seguir=='s')
    {
        printf("\t\n****ABM****\n\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n\n");

        printf("**Indique una opcion por favor :\n\n");
        scanf("%s",auxOpcion);

        if (esNumerico(auxOpcion)==0)
        {
            printf("Opcion no valida !!\n");
            break;
        }

        opcion=atoi(auxOpcion);


              switch(opcion)
        {
            case 1:

                indiceLugarVacio=BuscarPrimerLugarVacio(unaPersona,MAX_PERS);
                if (indiceLugarVacio==-1)
                {
                    printf("-Se completo la capacidad de almacenamiento !!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("** ALTA **\n\n");

                printf("Ingrese el nombre por favor :\n");
                fflush(stdin);
                gets(auxNombreStr);

               if (esSoloLetras(auxNombreStr)==0)
                {
                   printf("el nombre debe contener solo letras !!\n\n");
                   system("pause");
                   system("cls");
                   break;
                }
                else
                {
                      cantCaract=strlen(auxNombreStr);
                      if (cantCaract>50)
                     {
                       printf("Nombre muy largo maximo 50 caracteres !!\n\n");
                       system("pause");
                       system("cls");
                       break;
                      }
                }

                printf("Ingrese la edad por favor (1/99) :\n");
                scanf("%s",auxEdadStr);


                if (esNumerico(auxEdadStr)==0)
                {
                    printf("La edad debe contener solo numeros !!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else
                {
                    auxEdad=atoi(auxEdadStr);

                    if (validarRangoEdad(auxEdad,1,99)==0)
                    {
                        printf("Rango invalido para la edad !!\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                }

                printf("ingrese el Dni por favor :\n");
                scanf("%s",auxDniStr);

                if (esNumerico(auxDniStr)==0)
                {
                    printf("el dni debe contener solo numeros!!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                else

                    auxDni=atol(auxDniStr);

                    if(validarRAngoDni(auxDni,1000000,99000000)==0)
                    {
                        printf("Rango invalido para el dni !!\n\n");
                        system("pause");
                        system("cls");
                        break;
                    }
                      resp=BuscarPersonaPorDni(unaPersona,MAX_PERS,auxDni);
                      if (resp != -1)
                      {
                          printf("El dni ya esta ingresado en el sistema !!\n\n");
                          system("pause");
                          system("cls");
                          break;
                      }

               strlwr(auxNombreStr);
               auxNombreStr[0]=toupper(auxNombreStr[0]);
               cantCaract=strlen(auxNombreStr);

               for (i=1; i<cantCaract; i++)
               {
                   if (auxNombreStr[i]==' ')
                   {
                       auxNombreStr[i+1]=toupper(auxNombreStr[i+1]);
                   }
               }

               strcpy(unaPersona[indiceLugarVacio].nombre,auxNombreStr);
               unaPersona[indiceLugarVacio].edad=auxEdad;
               unaPersona[indiceLugarVacio].dni=auxDni;
               unaPersona[indiceLugarVacio].estado= 1 ;

                   if (unaPersona[indiceLugarVacio].edad <= 18)
                   {
                       contadorMen18++;
                   }
                   else if (unaPersona[indiceLugarVacio].edad >35)
                   {
                       contadorMay35++;
                   }
                   else
                   {
                         contadorResto++;
                   }


               flagOpciones=1;
               system("cls");
            break;

            case 2:

                if (flagOpciones==0)
                {
                    printf("Para borrar datos primero debe ingresarlos !!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                    printf("** BAJA **\n\n");

                    printf("Ingrese el dni de la persona :\n\n");
                    scanf("%s",auxDniStr);

                     if (esNumerico(auxDniStr)==0)
                    {
                      printf("el dni debe contener solo numeros!!\n\n");
                      system("pause");
                      system("cls");
                      break;
                    }

                    auxDni=atol(auxDniStr);

                          if (validarRAngoDni(auxDni,1000000,99000000)==0)
                          {
                          printf("Rango invalido para el dni !!\n\n");
                          system("pause");
                          system("cls");
                          break;
                          }

                          indiceEncontrado=BuscarPersonaPorDni(unaPersona,MAX_PERS,auxDni);

                         if (indiceEncontrado== -1)
                         {
                         printf("El dni que pretende dar de baja no existe en el sistema !!\n\n");
                         system("pause");
                         system("cls");
                         break;
                         }

                         unaPersona[indiceEncontrado].estado = 0 ;

                         if (unaPersona[indiceEncontrado].edad <= 18)
                         {
                             contadorMen18--;
                         }
                         else if (unaPersona[indiceEncontrado].edad >35)
                         {
                             contadorMay35--;
                         }
                         else
                            contadorResto--;

                         printf("Baja exitosa !!\n");
                         system("pause");
                         system("cls");
            break;

            case 3:

                  if (flagOpciones==0)
                {
                    printf("Para  imprimir lista primero debe ingresar datos !!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                    printf("** LISTAR **\n\n");

                  for (i=0; i<MAX_PERS-1;  i++)
                  {
                      if (unaPersona[i].estado==0)
                      {
                          continue;
                      }
                      for (j=i+1;  j<MAX_PERS; j++)
                      {
                           if (unaPersona[i].estado==0)
                           {
                             continue;
                           }
                           if (stricmp(unaPersona[i].nombre,unaPersona[j].nombre)>0)
                           {
                               auxPersona=unaPersona[i];
                               unaPersona[i]=unaPersona[j];
                               unaPersona[j]=auxPersona;
                           }
                      }
                  }
                  for(i=0; i<MAX_PERS;i++)
                  {
                      if (unaPersona[i].estado==0)
                      {
                          continue;
                      }
                      printf("NOMBRE :%18s  EDAD :%8d \tDNI :%8d\n",unaPersona[i].nombre,unaPersona[i].edad,unaPersona[i].dni);
                  }
                    system("pause");
                    system("cls");
            break;

            case 4:

                   if (flagOpciones==0)
                {
                    printf("Para  imprimir grafico primero debe ingresar datos !!\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
                printf("**GRAFICO DE BARRAS-ESTADISTICA SOBRE EDADES INGRESADAS**\n\n");

                int valoresContadores[]={contadorMen18,contadorResto,contadorMay35};

               for(i=0; i<3; i++)
              {
                if (valoresContadores[i]>max)
                   {
                     max=valoresContadores[i];
                   }
              }
             for(i=max; i>0; i--)
             {
                   for(j=0; j<3; j++)
                  {
                     if (valoresContadores[j]>=i)
                       {
                        printf("     *");
                       }
                     else
                        printf("      ");
                  }
                  putchar('\n') ;
            }
            printf("   <18   19-35   >35\n\n");
                system("pause");
                system("cls");
            break;

            case 5:

                seguir='n';
                printf("Gracias totales !!\n");
            break;

            default :

                printf("*Opcion invalida \n");
                system("pause");
                system("cls");
            break;

        }
    }

return 0;
}
