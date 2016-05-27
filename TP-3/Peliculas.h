typedef struct
{
    char titulo [50];
    char genero [20];
    char duracion[6];
    char descripcion[500];
    int puntaje ;
    char link[300];
    int estado;

}EMovie;

void agregarPelicula(EMovie movie[],int longitud,char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char dato6[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[],char Error6[]);
void borrarPelicula(EMovie movie[],int longitud);
void ModificarDatosPeliculas(EMovie movie[],int longitud);
