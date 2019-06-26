#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <ctype.h>
#include "reglasNegocio.h"
#include "Funcionex_aux.h"
#include "LinkedList.h"

#define PERSONAL 0
#define FAMILIAR 1
#define CORPORATIVO 2
eCliente* cliente_new()
{
    eCliente* cliente;
    cliente= (eCliente*) malloc(sizeof(eCliente)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT
    return cliente;
}
eAbono* abono_new()
{
    eAbono* abono;
    abono= (eAbono*) malloc(sizeof(eAbono)); // RESERVANDO ESPACIO EN MEMORIA PARA LA STRUCT
    return abono;
}

int parser_ClienteFromText(FILE* pFile, LinkedList* pClientes)
{
    int r;
    char id[10];
    char nombre[30];
    char sexo[10];
    char numeroTelefono[21];
    char importe[10];
    int cont = 0;
    eCliente* clienteAux;
    do
    {
        clienteAux= cliente_new();
        r= fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, sexo, numeroTelefono,importe);
        if(r==5)
        {
            if(cont>0)
            {

                clienteAux= cliente_newParameters(id,nombre,sexo,numeroTelefono,importe, clienteAux); // SE ENVIA LOS DATOS PARSEADOS PARA QUE SE AGREGEN A LA STRUCT
                ll_add(pClientes, clienteAux); // SE AGREGA LA STRUCT A EL ARRAY DE STRUCT
                //printf("Alumno--%d AGREGADO\n", cont);
            }
            else
            {
                //printf("FORMATO: %s--%s--%s--%s \n", id, nombre, hsTrabajadas, sueldo);
            }
            cont++;

        }
        else
        {
            printf("ERROR AL PARSEAR\n");
        }
    }
    while(!feof(pFile));

    return 1;
}

int altasClientes(LinkedList* listaClientes)
{
    char nombreArchivo[51];
    FILE* pArchivo;
    int valid= 0;
    fflush(stdin);
    printf("Ingrese nombre de archivo: ");
    gets(nombreArchivo);

    ll_clear(listaClientes);
    pArchivo= fopen(nombreArchivo,"r");

    if(pArchivo!= NULL)
    {
        valid= 1;
        parser_ClienteFromText(pArchivo, listaClientes);
        fclose(pArchivo);
        printf("Archivo abierto\n");

    }
    else
    {
        printf("NO SE ENCONTRO EL ARCHIVO\n");

    }

    //wipeScreen();
    return valid;
}
eCliente* cliente_newParameters(char* idStr,char* nombreStr,char* sexoStr, char* numeroTelStr,char* importeStr, eCliente* pCliente)
{
    pCliente->id = atoi(idStr);
    if(verificarNombre(nombreStr) == 1 && verificarCadena(nombreStr) == 1)
    {
        strcpy(pCliente->nombre, nombreStr);
    }
    if(verificarSexo(sexoStr) == 1)
    {
        strcpy(pCliente->sexo, sexoStr);
    }
    if(validarTelefono(numeroTelStr) == 1)
    {
        strcpy(pCliente->numeroTelefono, numeroTelStr);
    }
    if(verificarImporte( (int)importeStr) )
    {
        pCliente->importe = atoi(importeStr);
    }

    return pCliente;
}

int listarClientes(LinkedList* listaClientes, int isValid)
{
    wipeScreen();
    int validList= 0;
    int listLen;
    int i;
    eCliente* auxCliente;
    auxCliente= cliente_new();
    if(isValid == 1)
    {
        printf("LISTA DE CLIENTES: \n");
        printf("%5s %20s %4s %15s %10s \n", "ID","NOMBRE","SEXO","TELEFONO", "IMPORTE");
        listLen= ll_len(listaClientes);
        for(i=0; i < listLen; i++)
        {
            auxCliente= (eCliente*) ll_get(listaClientes, i);
            printf("%5d %20s %4s %15s %10d\n", auxCliente->id, auxCliente->nombre, auxCliente->sexo, auxCliente->numeroTelefono, auxCliente->importe);
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    wipeScreen();
    return validList;
}

int idSet(eAbono* abono, int cont)
{
    abono->id= cont;//+1
    return 1;
}
int tipoSet(eAbono* abono, int contTelefonos)
{
    if(contTelefonos == 1)
    {
        abono->tipo= PERSONAL;
    }
    else if( contTelefonos >= 2 && contTelefonos <= 4)
    {
        abono->tipo= FAMILIAR;
    }
    else if(contTelefonos >= 5)
    {
        abono->tipo= CORPORATIVO;
    }
    return 1;
}
int idClienteSet(eAbono* abono, int idCliente)
{
    abono->idCliente = idCliente;
    return 1;
}
int comparaId(void* clienteA,void* clienteB)
{

    if(((eCliente*)clienteA)->id > ((eCliente*)clienteB)->id)
    {
        return 1;
    }
    if(((eCliente*)clienteA)->id < ((eCliente*)clienteB)->id)
    {
        return -1;
    }
    return 0;
}
int sortImporte(void* clienteA,void* clienteB)
{

    if(((eAbonoCompleto*)clienteA)->importeFinal > ((eAbonoCompleto*)clienteB)->importeFinal)
    {
        return 1;
    }
    if(((eAbonoCompleto*)clienteA)->importeFinal < ((eAbonoCompleto*)clienteB)->importeFinal)
    {
        return -1;
    }
    return 0;
}
int buscarId(LinkedList* listaClientes, int index)
{
    int i;
    int contadorTelefono=0;
    eCliente* pCliente;
    pCliente= cliente_new();

    for(i=0; i < ll_len(listaClientes); i++)
    {
        pCliente= ll_get(listaClientes, i);
        if(pCliente->id == index)
        {
            contadorTelefono++;
        }
    }
    return contadorTelefono;
}
int importeFinalCalcular(LinkedList* listaClientes, int index)
{
    int i;
    int importeFinal=0 ;
    eCliente* pCliente;
    pCliente= cliente_new();

    for(i=0; i < ll_len(listaClientes); i++)
    {
        pCliente= ll_get(listaClientes, i);
        if(pCliente->id == index)
        {
            importeFinal= importeFinal + pCliente->importe;

        }
    }
    return importeFinal;
}
int importeFinalSet(eAbono* abono, int contTelefonos, int importeTotalCliente)
{
    int importeFinal;
    if(contTelefonos == 1)
    {
        abono->importeFinal= importeTotalCliente;
    }
    else if( contTelefonos >= 2 && contTelefonos <= 4)
    {
        importeFinal= importeTotalCliente -(importeTotalCliente/100 * 10); ///DESCUENTO

        abono->importeFinal= importeFinal;
    }
    else if(contTelefonos >= 5)
    {

        importeFinal= importeTotalCliente - (importeTotalCliente/100 * 20); ///DESCUENTO
        abono->importeFinal= importeFinal;
    }
    return 1;
}
int idMasAlta(LinkedList* listaClientes)
{
    int i;
    eCliente* clienteAux;
    clienteAux= cliente_new();
    int idMayor;
    idMayor= 1;
    for(i=0; i < ll_len(listaClientes); i++)
    {
        clienteAux= ll_get(listaClientes, i);
        if(clienteAux->id > idMayor)
        {
            idMayor= clienteAux->id;
        }
    }

    return idMayor;
}

int asignacionAbono(LinkedList* listaClientes, LinkedList* listaAbonos) // DEVUELVE 0 SI SALIO TODO BIEN
{
    int i;
    int contTelefonos=0;
    int listLen;
    eAbono* abonoAux;
    eCliente* clienteAux1;
    clienteAux1= cliente_new();
    listLen= ll_len(listaClientes);
    for(i=0 ; i< listLen; i++)
    {
        abonoAux= abono_new();
        clienteAux1= ll_get(listaClientes, i);
        contTelefonos= buscarId( listaClientes, clienteAux1->id);
        idSet(abonoAux, i);
        tipoSet(abonoAux, contTelefonos);
        idClienteSet(abonoAux, clienteAux1->id);
        importeFinalSet(abonoAux, contTelefonos, clienteAux1->importe );
        ll_add(listaAbonos, abonoAux);
        /*
        if(valid == 0)
        {
            printf("agregado abono %d\n", i);
        }
        */

    }

    //printf("ELEM EN ABONO %d\n", ll_len(listaAbonos));
    printf("ELEMENTOS AGREGADOS\n");
    wipeScreen();

    return 1;
}


int listarAbonos(LinkedList* listaAbono, LinkedList* listaClientes, int isValid)
{
    wipeScreen();
    int validList= 0;
    int listLen;
    int i;
    eAbono* abonoAux;
    abonoAux= abono_new();
    if(isValid == 1)
    {
        printf("LISTA DE CLIENTES: \n");
        printf("%9s %9s %9s %15s \n", "ID","tipo","idCliente","importeFinal");
        listLen= ll_len(listaAbono);
        for(i=0; i < listLen; i++)
        {
            abonoAux= ll_get(listaAbono, i);
            printf("%9d %9d %9d %15d\n", abonoAux->id, abonoAux->tipo, abonoAux->idCliente, abonoAux->importeFinal);
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    wipeScreen();
    return validList;
}
int crearAbonoCompleto(LinkedList* listaAbono,LinkedList* listaCliente, LinkedList* listaCompleta, int clienteValido, int abonoValido)
{
    int retorno =0;
    if(abonoValido== 1 && clienteValido == 1)
    {
        retorno = 1;
        int i;
        eAbono* abonoAux;
        eCliente* clienteAux;
        eAbonoCompleto* completoAux;
        for(i=0; i < ll_len(listaCliente); i++ )
        {
            clienteAux= cliente_new();
            abonoAux= abono_new();
            completoAux= (eAbonoCompleto*) malloc(sizeof(eAbonoCompleto));

            clienteAux= ll_get(listaCliente, i);
            abonoAux= ll_get(listaAbono, i);

            completoAux->idCliente = clienteAux->id;
            strcpy(completoAux->nombre, clienteAux->nombre);
            strcpy(completoAux->sexo, clienteAux->sexo);
            strcpy(completoAux->numeroTelefono, clienteAux->numeroTelefono);
            completoAux->importe =clienteAux->importe;

            completoAux->id= abonoAux->id;
            completoAux->tipo= abonoAux->tipo;
            completoAux->importeFinal= abonoAux->importeFinal;

            ll_add(listaCompleta, completoAux);
        }

    }
    return retorno;
}
void tipoAbonoTexto(int tipo, char texto[])
{
    if(tipo == PERSONAL)
    {
        strcpy(texto, "PERSONAL");
    }
    else if(tipo == FAMILIAR)
    {
        strcpy(texto, "FAMILIAR");
    }
    else if(tipo == CORPORATIVO)
    {
        strcpy(texto, "CORPORATIVO");
    }
}

int listarAbonosCompletos(LinkedList* listaCompleta, int isValid)
{
    wipeScreen();
    int validList= 0;
    int listLen;
    int i;
    char tipoAbono[10];
    eAbonoCompleto* completoAux;
    completoAux= (eAbonoCompleto*) malloc(sizeof(eAbonoCompleto) );
    if(isValid == 1)
    {
        printf("LISTA DE CLIENTES: \n");
        printf("%5s %14s %9s %10s /// %22s %4s %12s %5s \n", "ID","TIPO","idCliente","Imp Final", "Nombre", "Sexo", "Telefono", "Importe");
        listLen= ll_len(listaCompleta);
        for(i=0; i < listLen; i++)
        {
            completoAux= ll_get(listaCompleta, i);
            //strcpy(tipoAbono, tipoAbonoTexto(completoAux->tipo));
            tipoAbonoTexto(completoAux->tipo, tipoAbono);
            printf("%5d %14s %9d %10d /// %22s %2s %12s %5d \n", completoAux->id, tipoAbono, completoAux->idCliente, completoAux->importeFinal,
                   completoAux->nombre, completoAux->sexo, completoAux->numeroTelefono, completoAux->importe);
        }
        validList= 1;
        printf("CANT ELEM LISTA : %d \n",listLen);
    }
    else
    {
        printf("NO HAY ELEMENTOS PARA MOSTRAR, O NO SE INGRESO ELEMENTOS PREVIAMENTE\n");
    }
    wipeScreen();
    return validList;

}

int saveAsCSV(char* path, LinkedList* listaAbonos,int isValid)
{
    if(isValid == 1)
    {
        FILE* pFile;
        pFile= fopen(path,"w");
        wipeScreen();
        int listLen;
        int i;

        char sId[10];
        char sTipo[12];
        char sIdCliente[10];
        char sImporteFinal[10];



        eAbono* abonoAux;
        abonoAux= abono_new();
        printf("\nCopiando a archivo CSV...\n");

        listLen= ll_len(listaAbonos);
        fprintf(pFile, "%s%s%s%s%s%s%s%s", "id", ",", "tipo", ",", "idCliente", ",", "importeFinal","\n");
        for(i=0; i < listLen; i++)
        {
            abonoAux= ll_get(listaAbonos, i);
                snprintf(sId, 10, "%d", abonoAux->id );
                snprintf(sTipo, 10, "%d", abonoAux->tipo );
                snprintf(sIdCliente, 10, "%d", abonoAux->idCliente );
                snprintf(sImporteFinal, 10, "%d", abonoAux->importeFinal );
                fprintf(pFile, "%s%s%s%s%s%s%s%s", sId, ",", sTipo, ",", sIdCliente, ",", sImporteFinal,"\n");
        }
        fclose(pFile);
        //printf("Archivo escrito de manera correcta!\n");
        printf("Escritura completa!\n");

    }
    else
    {
        printf("NO HAY DATOS QUE GUARDAR!\n");
    }
    wipeScreen();

    return 0;
}
int saveAsBinary(char* path, LinkedList* listaAbonos, int isValid)
{
    if (isValid == 1)
    {


        if(listaAbonos!= NULL)
        {

                FILE* pFile;
                pFile= fopen(path,"wb");
                int listLen;
                int i;
                eAbono* abonoAux;
                listLen= ll_len(listaAbonos);
                printf("\nCopiando a archivo BIN...\n");
                for(i=0; i < listLen; i++)
                {
                    abonoAux= ll_get(listaAbonos, i);
                    fwrite(abonoAux, sizeof(eAbono), 1, pFile);
                }
                fclose(pFile);
                printf("Escritura completa\n");

        }
    }
    else
    {
        printf("NO HAY DATOS QUE GUARDAR!\n");
    }
    wipeScreen();

    return 0;
}
