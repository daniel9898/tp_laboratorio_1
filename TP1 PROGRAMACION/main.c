#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

float suma(float x,float y);
float resta(float x,float y);
float division(float x,float y);
float multiplicacion(float x,float y);
double factorial(float x);

int main()
{
    float numero1;
    float numero2;
    char seguir='s';
    int opcion=0;
    float resultado;
    int flagOp1=0, flagOp2=0;

   do
        {
         system("cls");
         printf("***CALCULADORA***\n\n");

         if (flagOp1==0)
            printf("1- Ingresar 1er operando (A= X)\n");
         else
            printf("1- Ingresar 1er operando (A=%.2f)\n",numero1);
        if (flagOp2==0)
             printf("2- Ingresar 2do operando (B= Y)\n");
        else
            printf("2- Ingresar 2do operando (B=%.2f)\n",numero2);

         printf("3- Calcular la suma (A+B)\n");
         printf("4- Calcular la resta (A-B)\n");
         printf("5- Calcular la division (A/B)\n");
         printf("6- Calcular la multiplicacion (A*B)\n");
         printf("7- Calcular el factorial (A!)\n" );
         printf("8- Calcular todas las operaciones\n");
         printf("9- Salir\n");

         printf("\n\n**Indique opcion : ");
         scanf("%d",&opcion);

           switch(opcion)
           {
             case 1:
                printf("Ingrese el primer operando : ");
                scanf("%f",&numero1);
                flagOp1=1;
                break;

             case 2:
                printf("Ingrese el segundo operando : ");
                scanf("%f",&numero2);
                flagOp2=1;
                break;

             case 3:
                 if (flagOp1==0 || flagOp2==0)
                    printf("Operacion invalida !!\n");
                 else
                 {
                      resultado=suma(numero1,numero2);
                      printf("la suma es:%.2f \n",resultado);
                 }
                break;

             case 4:
                 if (flagOp1==0 || flagOp2==0)
                    printf("Operacion invalida !!\n");
                 else
                 {
                     resultado=resta(numero1,numero2);
                     printf("la resta es:%.2f \n",resultado);
                 }
                break;

             case 5:
                 if (flagOp1==0 || flagOp2==0)
                    printf("Operacion invalida !!\n");
                else
                    resultado=division(numero1,numero2);
                break;

             case 6:
                   if (flagOp1==0 || flagOp2==0)
                    printf("Operacion invalida !!\n");
                   else
                   {
                       resultado=multiplicacion(numero1,numero2);
                       printf("la multiplicacion es:%.2f \n",resultado);
                   }
                break;

             case 7:
                  if (flagOp1==0)
                    printf("Operacion invalida !!\n");
                  else if(numero1<0)
                     printf("\n-Para calcular el factorial el operador debe ser positivo !!\n");
                 else
                 {
                    resultado=factorial(numero1);
                    printf("El factorial es %2.f \n",resultado);
                 }
                break;

             case 8:
                 if (flagOp1==0 || flagOp2==0)
                    printf("Operacion invalida !!\n");
                    else
                    {
                        resultado=suma(numero1,numero2);
                        printf("la suma es:%.2f \n",resultado);

                       resultado=resta(numero1,numero2);
                       printf("la resta es:%.2f \n",resultado);

                       resultado=division(numero1,numero2);

                       resultado=multiplicacion(numero1,numero2);
                       printf("la multiplicacion es:%.2f \n",resultado);

                       if(numero1<0)
                         {
                           printf("-Para calcular el factorial el operador debe ser positivo !!\n");
                         }
                      else
                        {
                          resultado=factorial(numero1);
                          printf("El factorial es %2.f \n",resultado);
                        }
                    }
                break;

             case 9:
                seguir = 'n';
                break;

             default:
                printf("Ingrese una opcion valida !!\n");
                fflush(stdin);
                break;
            }
            system("pause");
     } while(seguir=='s');

  return 0;
}



