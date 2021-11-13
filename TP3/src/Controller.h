#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"


Employee* employee_new()
{
    Employee* newEmployee;
    newEmployee = (Employee*)malloc(sizeof(Employee));

    if(newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}



Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* newEmployee;
    newEmployee = employee_new();

    int auxId;
    int auxHoras;
    int auxSueldo;

    auxId= atoi(idStr);
    auxHoras= atoi(horasTrabajadasStr);
    auxSueldo= atoi(sueldoStr);

    if(newEmployee != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        employee_setNombre(newEmployee, nombreStr);
        employee_setId(newEmployee, auxId);
        employee_setHorasTrabajadas(newEmployee, auxHoras);
        employee_setSueldo(newEmployee, auxSueldo);
    }

    return newEmployee;
}



void employee_delete(Employee* this)
{
    if(this!=NULL)
    {
        free(this);
    }
}



int employee_setId(Employee* this,int id)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(id >= 0)
        {
            this->id = id;
            retorno = 0;
        }
    }
    return retorno;
}



int employee_getId(Employee* this,int* id)
{
    int retorno = -1;

    if(this!=NULL && id !=NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}



int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;

    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}



int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL)
    {
        if(horasTrabajadas >= 0)
        {
            this->horasTrabajadas = horasTrabajadas;
            retorno = 0;
        }
    }
    return retorno;
}



int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno = -1;

    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}



int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;

    if(this!=NULL)
    {
        this->sueldo = sueldo;
        retorno=0;
    }
    return retorno;
}



int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno = -1;

    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}



int employee_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        printf("\n\n OPCIONES:");
        printf("\n (1) Ordernar lista de empleados por nombre.");
        printf("\n (2) Ordenar lista de empleados por sueldo.");
        printf("\n (3) Ordenar lista de empleados por horas trabajadas.");
        printf("\n (4) Cancelar.");
        printf("\n\n Opcion:");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            printf("\nLa lista se esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorNombre, 1);
            break;

        case 2:
            printf("\nLa lista se esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorSueldo, 1);
            break;

        case 3:
            printf("\nLa lista se esta ordenando...\n\n");
            ll_sort(pArrayListEmployee, employee_ordenarPorHoras, 1);
            break;

        case 4:
            opcion=4;
            printf("\nCancelando...\n\n");
            break;

        default:
            printf("Error. Usted eligio una opcion invalida.\n");
        }

        retorno= 0;
    }
    return retorno;
}



int employee_ordenarPorSueldo(void* thisUno, void* thisDos)
{
    int sueldoUno;
    int sueldoDos;
    int retorno = 0;

    employee_getSueldo(thisUno, &sueldoUno);
    employee_getSueldo(thisDos, &sueldoDos);

    if(sueldoUno>sueldoDos)
    {
        retorno = 1;
    }
    else if(sueldoUno<sueldoDos)
    {
        retorno = -1;
    }

    return retorno;
}



int employee_ordenarPorNombre(void* thisUno, void* thisDos)
{
    char nombreUno[50];
    char nombreDos[50];
    int retorno = 0;

    employee_getNombre(thisUno, nombreUno);
    employee_getNombre(thisDos, nombreDos);

    if(strcmp(nombreUno, nombreDos)>0)
    {
        retorno = 1;
    }
    else if(strcmp(nombreUno, nombreDos)<0)
    {
        retorno = -1;
    }

    return retorno;
}



int employee_ordenarPorHoras(void* thisUno, void* thisDos)
{
    int horasUno;
    int horasDos;
    int retorno = 0;

    employee_getHorasTrabajadas(thisUno, &horasUno);
    employee_getHorasTrabajadas(thisDos, &horasDos);

    if(horasUno>horasDos)
    {
        retorno = 1;
    }
    else if(horasUno<horasDos)
    {
        retorno = -1;
    }

    return retorno;
}
