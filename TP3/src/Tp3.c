#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();

    int option;
    int validarController;
    int validarAdd;
    int validarEdit;
    int validarRemove;
    int validarList;
    int validarSort;
    int validarSave;
    int validarCargarTexto= 0;
    int validarCargarBinario= 0;

    do
    {
        printf("MENU:\n");
        printf("(1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("(2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
        printf("(3) Alta de empleado.\n");
        printf("(4) Modificar datos de empleado.\n");
        printf("(5) Baja de empleado.\n");
        printf("(6) Listar empleados.\n");
        printf("(7) Ordenar empleados.\n");
        printf("(8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("(9) Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
        printf("(10) Salir.\n");

        printf("\nElija una opcion: ");
        scanf("%d", &option);

        while (option!=1 && option!=2 && option!=3 && option!=4 && option!=5 && option!=6 && option!=7 && option!=8 && option!=9 && option!=10)
        {
            printf("Error. Usted eligio una opcion invalida.\n");
            printf("\nElija una opcion: ");
            scanf("%d", &option);
        }

        switch(option)
        {
        case 1:
            if(validarCargarTexto == 0)
            {
                validarController = controller_loadFromText("data.csv",listaEmpleados);
                if(validarController == 1)
                {
                    printf("\nSe ha cargado el archivo.\n\n");
                }
                else
                {
                    printf("\nNo se ha cargado el archivo.\n\n");
                }
            validarCargarTexto=1;
            }
            else if(validarCargarTexto == 1)
            {
                printf("El archivo ya fue cargado.\n");
            }
            break;

        case 2:
            if(validarCargarBinario == 0)
            {
                validarController = controller_loadFromBinary("data.bin",listaEmpleados);
                if(validarController == 1)
                {
                    printf("\nSe ha cargado el archivo.\n\n");
                }
                else
                {
                    printf("\nNo se ha cargado el archivo.\n\n");
                }
            validarCargarBinario=1;
            }
            else if(validarCargarBinario == 1)
            {
                printf("El archivo ya fue cargado.\n");
            }
            break;

        case 3:
            validarAdd = controller_addEmployee(listaEmpleados);
            if(validarAdd == 0)
            {
                printf("\nSe ha cargado el empleado.\n\n");
            }
            else
            {
                printf("\nNo se ha cargado el empleado.\n\n");
            }
            break;

        case 4:
            validarEdit = controller_editEmployee(listaEmpleados);
            if(validarEdit == 0)
            {
                printf("\nSe ha modificado el empleado.\n\n");
            }
            else
            {
                printf("\nNo se ha modificado el empleado.\n\n");
            }
            break;

        case 5:
            validarRemove = controller_removeEmployee(listaEmpleados);
            if(validarRemove == -1)
            {
                printf("\nNo se ha encontrado el ID.\n\n");
            }
            else if(validarRemove == -2)
            {
                printf("\nNo se ha eliminado el empleado.\n\n");
            }
            else
            {
                printf("\nSe ha eliminado el empleado.\n\n");
            }
            break;

        case 6:
            validarList = controller_ListEmployee(listaEmpleados);
            if(validarList == 0)
            {
                printf("\nSe ha cargado la lista.\n\n");
            }
            else
            {
                printf("\nNo se ha cargada la lista.\n\n");
            }
            break;

        case 7:
            validarSort = controller_sortEmployee(listaEmpleados);
            if(validarSort == 0)
            {
                printf("\nSe ha ordenado la lista.\n\n");
            }
            else
            {
                printf("\nNo se ha ordenado la lista.\n\n");
            }
            break;

        case 8:
            validarSave = controller_saveAsText("data.csv", listaEmpleados);
            if(validarSave == -1)
            {
                printf("\nSe ha guardado el archivo.\n\n");
            }
            else
            {
                printf("\nNo se ha guardado el archivo.\n\n");
            }
            break;

        case 9:
            validarSave = controller_saveAsBinary("data.bin",listaEmpleados);
            if(validarSave == -1)
            {
                printf("\nSe ha guardado el archivo.\n\n");
            }
            else
            {
                printf("\nNo se ha guardado el archivo.\n\n");
            }
            break;

        case 10:
            option=10;
            printf("\nSaliendo...\n\n");
            break;

        default:
            printf("Error. Usted eligio una opcion invalida.\n");
        }

        system("pause");
        system("cls");
    }
    while(option != 10);

    return 0;
}
