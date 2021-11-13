#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "parser.h"
#include "Employee.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pEmployee;

    char idAux[50];
    char nombreAux[50];
    char horasTrabajadasAux[50];
    char sueldoAux[50];
    int retorno=-1;
    int flag=1;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flag)
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
                flag=0;
            }
            fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            printf("%s-%s-%s-%s\n", idAux, nombreAux, horasTrabajadasAux, sueldoAux);
            pEmployee=employee_NewParametros (idAux, nombreAux, horasTrabajadasAux, sueldoAux);

            if(pEmployee!=NULL)
            {
                ll_add(pArrayListEmployee, pEmployee);
                retorno=0;
            }
        }
    }
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployees)
{
    Employee* pEmployee;
    int retorno=-1;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            pEmployee=employee_new();
            fread(pEmployee, sizeof(Employee), 1, pFile);
            ll_add(pArrayListEmployees, pEmployee);
        }
        retorno=0;
    }
    return retorno;
}
