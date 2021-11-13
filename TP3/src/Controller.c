#include <stdio.h>
#include <stdlib.h>

#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"
#include "funcionesGet.h"


int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;

    if(pArchivo!=NULL)
    {
        pArchivo=fopen(path, "r");
        parser_EmployeeFromText(pArchivo,pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}



int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    FILE* pArchivo;
    int retorno = -1;

    if(pArchivo != NULL)
    {
        pArchivo = fopen(path, "rb");
        parser_EmployeeFromBinary(pArchivo,pArrayListEmployee);
        retorno = 1;
    }
    fclose(pArchivo);

    return retorno;
}



int controller_nextID(LinkedList* pArrayListEmployee)
{
    Employee* employeeAux;

    int i;
    int aux;
    int id= 0;
    int listLen;
    int idAnterior;

    if(pArrayListEmployee != NULL)
    {
        listLen = ll_len(pArrayListEmployee);
        if(listLen > 0)
        {
            for(i = 0; i<listLen; i++)
            {
                employeeAux = (Employee*)ll_get(pArrayListEmployee,i);
                employee_getId(employeeAux,&aux);
                if(aux > id)
                {
                    idAnterior = id;
                    id = aux;
                    if(idAnterior + 1 != id)
                    {
                        id = idAnterior;
                        break;
                    }
                }
            }
            id++;
        }
        else
        {
            id = 1;
        }
    }
    return id;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;
    pEmpleado = employee_new();

    int retorno= -1;
    int idAux;
    int horasCharAux;
    int sueldoCharAux;

    char nombreChar[100];
    char sueldoChar[100];
    char horasChar[100];

    if(pArrayListEmployee != NULL)
    {
        idAux = controller_nextID(pArrayListEmployee);
        printf("Ingrese el nuevo nombre: ");
        fflush(stdin);
        gets(nombreChar);
        while(esSoloLetras(nombreChar)==0)
        {
            printf("Usted ha ingresado un tipo de nombre incorrecta.");
            fflush(stdin);
            gets(nombreChar);
        }
        stringToUpper(nombreChar);


        printf("Ingrese el nuevo sueldo: ");
        fflush(stdin);
        gets(sueldoChar);
        while(esNumerico(sueldoChar)==0)
        {
            printf("Usted ha ingresado un sueldo incorrecto.");
            fflush(stdin);
            gets(sueldoChar);
        }
        sueldoCharAux= atoi(sueldoChar);


        printf("Ingrese las nuevas horas: ");
        fflush(stdin);
        gets(horasChar);
        while(esNumerico(horasChar)==0)
        {
            printf("Usted ha ingresado horas incorrecto.");
            fflush(stdin);
            gets(horasChar);
        }
        horasCharAux= atoi(horasChar);

        if(pEmpleado != NULL)
        {
            employee_setId(pEmpleado, idAux);
            employee_setNombre(pEmpleado, nombreChar);
            employee_setSueldo(pEmpleado, sueldoCharAux);
            employee_setHorasTrabajadas(pEmpleado, horasCharAux);
            ll_add(pArrayListEmployee, pEmpleado);
            retorno = 0;
        }
    }
    return retorno;
}



int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empleado;

    int i;
    int retorno = -1;
    int idCharAux;
    int idObtenido;
    int opcionCharAux;
    int sueldoCharAux;
    int horasCharAux;

    char idChar[100];
    char opcionChar[100];
    char nombreChar[100];
    char sueldoChar[100];
    char horasChar[100];

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el ID del empleado: ");
        fflush(stdin);
        gets(idChar);

        while(esNumerico(idChar)==0)
        {
            printf("Usted ha ingresado un tipo ID incorrecta.");
            fflush(stdin);
            gets(idChar);
        }
        idCharAux=atoi(idChar);

        for(i = 0; i< ll_len(pArrayListEmployee); i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&idObtenido);

            if(idObtenido == idCharAux)
            {
                printf("\n\n OPCIONES:");
                printf("\n (1) Modificar nombre.");
                printf("\n (2) Modificar sueldo.");
                printf("\n (3) Modificar horas trabajadas.");
                printf("\n (4) Cancelar.");
                printf("\n\n Opcion:");
                fflush(stdin);
                gets(opcionChar);

                while(esNumerico(opcionChar)==0)
                {
                    printf("Usted ha ingresado un tipo ID incorrecta.");
                    fflush(stdin);
                    gets(opcionChar);
                }
                opcionCharAux=atoi(opcionChar);

                switch(opcionCharAux)
                {
                case 1:
                    printf("Ingrese un nuevo nombre: ");
                    fflush(stdin);
                    gets(nombreChar);

                    while(esSoloLetras(nombreChar)==0)
                    {
                        printf("Usted ha ingresado un tipo de nombre incorrecta.");
                        fflush(stdin);
                        gets(nombreChar);
                    }
                    stringToUpper(nombreChar);
                    employee_setNombre(empleado, nombreChar);
                    retorno = 0;
                    break;

                case 2:
                    printf("Ingrese un nuevo sueldo: ");
                    fflush(stdin);
                    gets(sueldoChar);

                    while(esNumerico(sueldoChar)==0)
                    {
                        printf("Usted ha ingresado un sueldo incorrecto.");
                        fflush(stdin);
                        gets(sueldoChar);
                    }

                    sueldoCharAux= atoi(sueldoChar);
                    employee_setSueldo(empleado, sueldoCharAux);
                    retorno = 0;
                    break;

                case 3:
                    printf("Ingrese las nuevas horas: ");
                    fflush(stdin);
                    gets(horasChar);
                    while(esNumerico(horasChar)==0)
                    {
                        printf("Usted ha ingresado horas incorrecto.");
                        fflush(stdin);
                        gets(horasChar);
                    }
                    horasCharAux= atoi(horasChar);
                    employee_setHorasTrabajadas(empleado, horasCharAux);
                    retorno = 0;
                    break;

                case 4:
                    opcionCharAux=4;
                    printf("\nCancelando...\n\n");
                    break;

                default:
                    printf("Error. Usted eligio una opcion invalida.\n");
                }
            }
        }
    }
    return retorno;
}



int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    int retorno = -1;
    int i;
    char idChar[100];
    int idCharAux;
    int idObtenido;
    int opcionAConfirmar;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el Id del empleado: ");
        fflush(stdin);
        gets(idChar);

        while(esNumerico(idChar)==0)
        {
            printf("Usted ha ingresado un tipo ID incorrecta.");
            fflush(stdin);
            gets(idChar);
        }
        idCharAux=atoi(idChar);

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {
            pEmployee = ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee, &idObtenido);

            if(idObtenido == idCharAux)
            {
                printf("\n\n Desea dar de baja el usuario?");
                printf("\n Ingrese 1 para SI.");
                printf("\n Ingrese 2 para NO.");
                printf("\n Ingrese opcion: ");
                scanf("%d", &opcionAConfirmar);

                switch(opcionAConfirmar)
                {
                case 1:
                    employee_delete(pEmployee);
                    ll_remove(pArrayListEmployee,i);
                    retorno = 0;
                    break;

                case 2:
                    retorno = -2;
                    break;

                default:
                    printf("\n\nUsted ingreso una opcion invalida.\n");
                    retorno = -2;
                    break;
                }
            }
        }
    }
    return retorno;
}



int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* pEmpleado;

    int retorno = -1;
    int i;
    int id;
    int sueldo;
    int horasTrabajadas;

    char nombre[128];

    if(pArrayListEmployee != NULL)
    {
        printf("\n\nID-- \t\t   NOMBRE \t\t SUELDO \t\tHORAS \n\n");
        retorno = 0;

        for(i=0; i < ll_len(pArrayListEmployee); i++)
        {
            pEmpleado = ll_get(pArrayListEmployee,i);
            employee_getNombre(pEmpleado, nombre);
            employee_getId(pEmpleado,&id);
            employee_getSueldo(pEmpleado,&sueldo);
            employee_getHorasTrabajadas(pEmpleado,&horasTrabajadas);
            printf("%d -- %20s %20d %20d \n\n", id, nombre, sueldo, horasTrabajadas);
        }
    }
    return retorno;
}



int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        employee_sortEmployee(pArrayListEmployee);
        retorno = 0;
    }
    return retorno;
}



int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int retorno = -1;
    int i;
    int* idAux;
    char* nombreAux;
    int* sueldoAux;
    int* horasAux;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        idAux = malloc(sizeof(int));
        nombreAux = malloc(sizeof(char)*100);
        sueldoAux = malloc(sizeof(int));
        horasAux = malloc(sizeof(int));

        pArchivo = fopen(path, "w");
        fprintf(pArchivo,"id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = ll_get(pArrayListEmployee,i);
            employee_getId(empleadoAux,idAux);
            employee_getSueldo(empleadoAux,sueldoAux);
            employee_getNombre(empleadoAux, nombreAux);
            employee_getHorasTrabajadas(empleadoAux,horasAux);
            fprintf(pArchivo,"%d,%s,%d,%d\n",*idAux,nombreAux,*sueldoAux,*horasAux);
        }

        free(nombreAux);
        free(idAux);
        free(sueldoAux);
        free(horasAux);
        fclose(pArchivo);
    }
    return retorno;
}



int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    Employee* empleadoAux;

    int retorno = -1;
    int i = 0;

    if(pArrayListEmployee != NULL && path != NULL)
    {
        pArchivo = fopen(path,"wb");

        for(i=0; i< ll_len(pArrayListEmployee); i++)
        {
            empleadoAux = (Employee*)ll_get(pArrayListEmployee,i);
            fwrite(empleadoAux, sizeof(Employee),1,pArchivo);
        }
        fclose(pArchivo);
    }
    return retorno;
}
