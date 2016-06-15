#include "-ArrayList.h"

typedef struct
{
    char titulo [50];
    char genero [20];
    char duracion[6];
    char descripcion[500];
    int puntaje ;

}EMovie;

EMovie* agregarPelicula(ArrayList* Plist,char dato1[],char dato2[],char dato3[],char dato4[],char dato5[],char Error1[],char Error2[],char Error3[],char Error4[],char Error5[]);
int searchMovie(ArrayList*plist,char input[]);
void PrintMovie(EMovie* p);
void PrintMovieTitle(EMovie* p);
void printArrayListMoviesTitle(ArrayList* lista);
void printArrayListMovies(ArrayList* lista);
int getIndex(ArrayList*plist,char input[]);
int DeleteMovie(ArrayList* Plist,ArrayList* PlistBajas);
void modifyMovie(ArrayList* Plist,EMovie *movie);
int compareMovie(void*  movieA,void* movieB);
