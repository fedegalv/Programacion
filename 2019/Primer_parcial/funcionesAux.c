#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ctype.h"
#include "funcionesAux.h"
#include "pelicula.h"
#include "informes.h"
#define CANT_PEL 10
#define CANT_ACTORES 5
int menuOpciones(void)
{
    int opcion;
    sPelicula listaPeliculas[CANT_PEL];
    sPelicula copiaListaPeliculas[CANT_PEL];
    sActor listaActores[5];
    sActor copiaListaActores[5];
    int idOrigen= 1000;
    int posicionLibre;
    int opcionDos;

    sActor_Hardcoded(listaActores);
    sPelicula_Init(listaPeliculas, CANT_PEL);
    idOrigen= sPelicula_Hardcoded(listaPeliculas, idOrigen, listaActores);
    do{
        printf("***** MENU PRINCIPAL **** \n\n");
        printf("1- ALTAS PELICULAS "
               "\n2- LISTAR "
               "\n3- MODIFICAR DATOS "
               "\n4- BAJA PELICULA"
               "\n5- LISTAR ORDENADA"
               "\n6- FILTROS"
               "\nOPCION SELECCIONADA: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            posicionLibre=  sPelicula_buscarLugarLibre(listaPeliculas, CANT_PEL);
            altasPelicula(listaPeliculas, listaActores, idOrigen, posicionLibre, CANT_PEL);
            idOrigen++;
            break;
        case 2:
            //listaPeliculaSinActores(listaPeliculas, CANT_PEL);
            fflush(stdin);
            printf("1- Lista sin actores\n2- Lista con actores\nOPCION SELECCIONADA: ");
            scanf("%d", &opcionDos);
            if(opcionDos == 1)
            {
            printf("LISTA SIN ACTORES\n");
            listaPeliculaConActores(listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 2)
            {
            limpiarPantalla();
            printf("LISTA CON ACTORES\n");
            mostrarPeliculasYActores(listaPeliculas, listaActores,CANT_PEL, CANT_ACTORES);
            }
            else{printf("OPCION INVALIDA\n");}
            //mostrarPeliculasYActores()
            break;
        case 3:
            modificarPelicula(listaPeliculas, CANT_PEL, listaActores, CANT_ACTORES);
            break;
        case 4:
            bajaPelicula(listaPeliculas, CANT_PEL);
            break;
        case 5:
            limpiarPantalla();
            fflush(stdin);
            printf("1- Peliculas ordenadas por anio de estreno\n2- Actores ordenados por pais de origen\nOPCION SELECCIONADA: ");
            scanf("%d", &opcionDos);
            if(opcionDos == 1)
            {
                /*
                ordenarPorAnioEstreno(listaPeliculas, CANT_PEL);
                printf("PELICULAS ORDENADAS POR ANIO DE ESTRENO: \n");
                listaPeliculaConActores(listaPeliculas, CANT_PEL);
                */
                ordenarCopiaPorAnioEstreno(listaPeliculas,copiaListaPeliculas, CANT_PEL);
                printf("PELICULAS ORDENADAS POR ANIO DE ESTRENO: \n");
                listaPeliculaConActores(copiaListaPeliculas, CANT_PEL);
                limpiarPantalla();

            }else if(opcionDos == 2)
            {
                /*
                ordenarActoresPorOrigen(listaActores, 5);
                printf("ACTORES ORDENADO POR PAIS DE ORIGEN: \n");
                mostrarActores(listaActores, 5);
                */
                ordenarCopiaActoresPorOrigen(listaActores, copiaListaActores, CANT_ACTORES);
                printf("ACTORES ORDENADO POR PAIS DE ORIGEN: \n");
                mostrarActores(copiaListaActores, CANT_ACTORES);

            }else{printf("OPCION INVALIDA\n");}
            limpiarPantalla();
            break;
            case 6:
                fflush(stdin);
                printf("1- Todas las peliculas con genero y actor\n2- Peliculas cuya nacionalidad del actor sea EEUU\n3- Peliculas nacionalidad ingresada por consola\n"
                       "4- Peliculas por genero\n5- Cantidad peliculas por genero\n6- Actores que mas peliculas protagonizaron\n"
                       "7- Genero/s con menos peliculas\n8- Actor/es que no trabajaron en ninguna pelicula\nOPCION SELECCIONADA: ");
            scanf("%d", &opcionDos);
            if(opcionDos == 1)
            {
            filtroGenero(listaActores, listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 2)
            {
                filtroActoresNacionalidad(listaActores, listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 3)
            {
                filtroIngresadoPorConsola(listaPeliculas, CANT_PEL, listaActores);
            }
            else if(opcionDos == 4)
            {
                filtroGeneroPeliculas(listaActores, listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 5)
            {
                filtroGeneroPeliculasContador(listaActores, listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 6)
            {
                filtroActoresCantidadPeliculas(listaPeliculas, CANT_PEL, listaActores, CANT_ACTORES);
            }
            else if(opcionDos == 7)
            {
                filtroGenerosMenosPeliculas(listaPeliculas, CANT_PEL);
            }
            else if(opcionDos == 8)
            {

            }
            else{printf("OPCION INVALIDA\n");}
            limpiarPantalla();
            break;

                break;
        default:
            printf("OPCION NO VALIDA\n");
            fflush(stdin);
            limpiarPantalla();
        }
    }while(opcion != 11);
    return 1;

}
void limpiarPantalla(void)
{
    system("pause"); // pausa el programa, para limpiar
    system("cls"); // se limpia la consola
}
int ingresoNumero(void)
{
    int numero;
    int esNumero; // esNumero funcionara como booleano, para validar si el numero es valido o no, en caso que no sea valido se volvera a pedirlo
    int numeroDevolver; // Numero a devolver
    do
    {
        //COMPROBACION DEL NUMERO INGRESADO
        char aux;
        if(scanf("%d%c", &numero, &aux) != 2 || aux != '\n') // Comprueba si lo ingresado valido o no
        {
            esNumero= 0;
            printf("No ingreso un numero valido. Reintentelo otra vez\n");
            fflush(stdin); // Limpiar el buffer de teclado
        }
        else
        {
            esNumero =1;
            numeroDevolver = numero; // Variable que guarda el numero a retornar
            fflush(stdin); // Limpiar el buffer de teclado
        }
    }
    while(esNumero == 0); // Realizar el pedido mientras el numero no sea valido.

    return numeroDevolver;
}

int verificarCadena(char cadena[51])
{
    int largoCadena;
    int i;
    largoCadena= strlen(cadena); // SE TOMA EL LARGO DEL NOMBRE
    int banderaCadena=0; // BANDERA PARA MARCAR QUE SE ENCONTRO UN CARACTER NO ALFABETICO, INICIALIZADO EN 0
    do
    {

        fflush(stdin);
        for(i=0; i<largoCadena; i++) // RECORRE EL STRING
        {
            if( isalpha(cadena[i]) || isspace(cadena[i]) ) // isalpha DEVUELVE UN VALOR DISTINTO A CERO SI EL CARACTER ES ALFABETICO, SI NO 0
            {
                banderaCadena = 1; // banderaCadena MARCARA 1 SI ES QUE EL CARACTER ANALIZADO ES ALFABETICO
            }
            else
            {
                banderaCadena=0; // EN CASO DE ENCONTRAR UN CARACTER NO ALFABETICO , SE BAJA LA BANDERA
                break;
            }
        }
        if(banderaCadena== 0) // SI EN ALGUN MOMENTO LA BANDERA FUE BAJADA, O NUNCA FUE SUBIDA, SE PIDE QUE REINGRESE EL NOMBRE Y SE VERIFICARA EN EL PROXIMO LOOP
        {
            printf("INGRESO ALGUN CARACTER INVALIDO. Reingrese de manera correcta:");
            scanf("%[^\n]",cadena);
        }
        //banderaCadena= 0;
        largoCadena= strlen(cadena); // SE VUELVE A MEDIR EL LARGO DEL NUEVO STRING

    }
    while(banderaCadena == 0);

    return 0;
}

void formateoCadenas(char* texto)
{
    int i; // VARIABLE CONTROL
    int largo; // VARIABLE ALMACENA LARGO DEL STRING
    for(i = 0; texto[i]; i++) // POR SI ACASO PASAMOS TODOS LOS CARACTERES A MINUSCULA
    {
        texto[i] = tolower(texto[i]);
    }
    texto[0]=toupper(texto[0]); // SE CAMBIA LA PRIMERA LETRA A MAYUSCULA
    largo = strlen(texto); // SE ALMACENA EN largo LA CANTIDAD DE CARACTERES DEL STRING
    for(i=0; i< largo; i++) // SE RECORRE EL STRING
    {
        if(texto[i]==' ') // SI ENCUENTRA UN ESPACIO EN LA CADENA, ENTRA EN EL IF
        {
            texto[i+1]=toupper(texto[i+1]); // SE PONE EN MAYUSCULA EL CARACTER QUE LE SIGUE A EL ESPACIO(i ES EL ESPACIO, i+1 ES EL CARACTER QUE LE SIGUE)
        }
    }

}


