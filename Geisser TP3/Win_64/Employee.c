#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

int employee_setId(Employee* this,int id)
{
    int error = 1;

    if( this != NULL)// no olvidar validar
    {
        this->id = id;
        error = 0;
    }

    return error;
}

int employee_getId(Employee* this,int* id)
{
    int error = 1;

    if( this != NULL)
    {
        *id = this->id;
        error = 0;
    }
    return error;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int error = 1;

    if( this != NULL)
    {
        strcpy(this->nombre, nombre);
        error = 0;
    }

    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int error = 1;

    if(this != NULL)
    {
        strcpy(nombre, this->nombre);
        error = 0;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = 1;

    if( this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        error = 0;
    }

    return error;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error =1;

    if( this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = 1;

    if( this != NULL)
    {
        this->sueldo = sueldo;
        error = 0;
    }

    return error;

}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = 1;

    if( this != NULL)
    {
        *sueldo = this->sueldo;
        error = 0;
    }
    return error;
}

Employee* employee_new()
{
    Employee* pEmp = (Employee*) malloc(sizeof(Employee));

    if(pEmp != NULL)
    {
        pEmp->id = 0;
        strcpy(pEmp->nombre, "");
        pEmp->horasTrabajadas = 0;
        pEmp->sueldo = 0;
    }

    return pEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    int error = 1;

    Employee* pEmp = (Employee*) malloc(sizeof(Employee));

    if(pEmp != NULL)
    {
        if( !employee_setId(pEmp, atoi(idStr)) && !employee_setNombre(pEmp, nombreStr) && !employee_setHorasTrabajadas(pEmp, atoi(horasTrabajadasStr)) && !employee_setSueldo(pEmp, atoi(sueldoStr)))
        {
            error=0;
        }//if setters
    }//if pEmp != NULL

    if(error)
    {
        free(pEmp);
        pEmp = NULL;
    }
    return pEmp;
}

void mostrarEmpleado(Employee* emp)
{
    if(emp != NULL)
    {
        printf("%4d %18s %5d %8d\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }
}

int employee_sortByName(void* emp1, void* emp2)
{
    Employee* pEmp1;
    Employee* pEmp2;
    //Employee* pEmpAux;

    int result = 0;

    if(emp1 != NULL && emp2 != NULL)
    {
        pEmp1 = (Employee*) emp1;
        pEmp2 = (Employee*) emp2;

        result=strcmp(pEmp1->nombre, pEmp2->nombre);
    }

return result;
}



//int ordenarXSueldo(void* emp1, void* emp2)
//{
//    Employee* pEmp1;
//    Employee* pEmp2;
//    Employee* pEmpAux;
//
//    int bubble = 0;
//
//    if( emp1 != NULL && emp2 != NULL)
//    {
//        pEmp1 = (Employee*) emp1;
//        pEmp2 = (Employee*) emp2;
//
//        if( pEmp1->sueldo > pEmp2-> sueldo)
//        {
//            pEmpAux = pEmp1;
//            pEmp1 = pEmp2;
//            pEmp2 = pEmpAux;
//
//            bubble = 1;
//        }
//    }
//
//    return bubble;
//}

//int ordenarXHoras( void* emp1, void* emp2)
//{
//    int retorno = 0;
//    Employee* p1;
//    Employee* p2;
//
//    if( emp1 != NULL && emp2 != NULL)
//    {
//        p1 = (Employee*) emp1;
//        p2 = (Employee*) emp2;
//
//        if( p1->horasTrabajadas > p2->horasTrabajadas)
//        {
//            retorno = 1;
//        }
//        else if( p1->horasTrabajadas < p2->horasTrabajadas)
//        {
//            retorno = -1;
//        }
//        else
//        {
//            retorno = 0;
//        }
//    }
//    return retorno;
//}

