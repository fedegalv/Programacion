
typedef struct
{
    char nombre[64];
    int edad;
} sPersona;

sPersona damePersona();
void mostrarPersona(sPersona);
void modificarPerson(sPersona* pPersona);
void agregarPersonaArray(sPersona persona, sPersona* arrayPersonas,int pos);

void mostrarPersonaPuntero(sPersona *unaPersona);
void mostrarPersonasPunteros(sPersona* arrayPersona, int cant);
void cargarArrayArimeticaPunteros(sPersona* arrayPersonas);
