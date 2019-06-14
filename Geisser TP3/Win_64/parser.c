#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char buffer[4][20];
    int qty;
    Employee* empAux;
    fscanf(pFile, "%[^,],%[^,],%[^,],%5s", buffer[0], buffer[1], buffer[2], buffer[3]);//Lectura fantasma encabezados.

    while(!feof(pFile))
    {
        qty = fscanf(pFile, "%[^,],%[^,],%[^,],%5s",buffer[0],buffer[1],buffer[2],buffer[3]);

        if(qty < 4)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("(!) No se leyo correctamente el ultimo registro (!)");
                system("pause");
                break;
            }
        }

        empAux = employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);

        if (empAux!=NULL)
        {
            ll_add(pArrayListEmployee, empAux);
        }
    }

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int qty;
    Employee* empAux;

    while(!feof(pFile))
    {
        empAux = employee_new();

        if(empAux == NULL)
        {
            printf("(!) Error en memoria dinamica (!)\n");
            system("pause");
            break;
        }

        qty=fread(empAux,sizeof(Employee),1,pFile);

        if(qty!=1)
        {
            if(feof(pFile))
            {
                break;
            }
            else
            {
                printf("\n(!) No se leyo correctamente el ultimo registro (!)\n");
                system("pause");
                break;
            }
        }
        ll_add(pArrayListEmployee, empAux);
    }

    return 1;
}
