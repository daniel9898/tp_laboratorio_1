typedef struct {

    char nombre[51];
    int edad;
    int estado;// indica (o) posicion vacia, (1) si esta llena.
    long int dni;

}EPersona;

void InicializarArray(EPersona unaPersona[],int longitud);
int BuscarPrimerLugarVacio(EPersona unaPersona[],int longitud);
int BuscarPersonaPorDni(EPersona unaPersona[],int longitud,long int dni);
int validarRAngoDni(long int numero,long int minimo,long int maximo);
int validarRangoEdad(int numero,int minimo,int maximo);
int esNumerico(char str[]);
int esSoloLetras(char str[]);

