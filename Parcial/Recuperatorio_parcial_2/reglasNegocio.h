#include "LinkedList.h"
struct
{
    int id;
    char nombre[51];
    char sexo[2];
    char numeroTelefono[21];
    int importe;

}typedef eCliente;

struct
{
    int id;
    int tipo;
    int idCliente;
    int importeFinal;

}typedef eAbono;

struct
{
    char nombre[51];
    char sexo[2];
    char numeroTelefono[21];
    int importe;
    int id;
    int tipo;
    int idCliente;
    int importeFinal;

}typedef eAbonoCompleto;


eCliente* cliente_new(void);
int parser_ClienteFromText(FILE* , LinkedList* );
int altasClientes(LinkedList* );
eCliente* cliente_newParameters(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelStr,char* importeStr, eCliente* );
int listarClientes(LinkedList* , int isValid);
int idSet(eAbono* abono, int cont);
int tipoSet(eAbono* abono, int tipo);
int idClienteSet(eAbono* abono, int idCliente);
int importeFinalSet(eAbono* abono , int , int);
int asignacionAbono(LinkedList* listaClientes, LinkedList* listaAbonos);
int comparaId(void* ,void* );
int sortImporte(void* ,void* );
int listarAbonos(LinkedList* listaAbono,LinkedList* , int isValid);
int buscarId(LinkedList* , int id);
int calcularImporteFinal(eAbono* , int);
int importeFinalCalcular(LinkedList* , int );
int idMasAlta(LinkedList* listaClientes);
int listarAbonosCompletos(LinkedList* listaCompleto, int isValid);
int crearAbonoCompleto(LinkedList* listaAbono,LinkedList* listaCliente, LinkedList* listaCompleta, int, int);
void tipoAbonoTexto(int tipo, char texto[]);
int saveAsCSV(char* , LinkedList* listaAbonos,int isValid);
int saveAsBinary(char* , LinkedList* listaAbonos, int isValid);
