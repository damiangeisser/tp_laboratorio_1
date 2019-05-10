#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "input.h"
#include "ArrayEmployees.h"

#endif // employee_H_INCLUDED

//typedef struct
//{
//    int id;
//    char name[51];
//    char lastName[51];
//    float salary;
//    int sector;
//    int isEmpty;
//} Employee;

//1 -------------------------------------------
int menu()
{
    int option;

    system("cls");
    printf("--- ABM Empleados ---\n\n");
    printf("1- Alta de empleados\n");
    printf("2- Modificar empleado\n");
    printf("3- Baja de empleado\n");
    printf("4- Informes\n");
    printf("5- Salir\n");

    getInt(&option,"Ingrese una opcion: ","\n(!) Opcion invalida (!)", 1, 5);

    return option;
}
//2 -------------------------------------------
int initEmployees(Employee* arrayEmployee, int len)
{
    for(int i=0; i < len; i++)
    {
        arrayEmployee[i].isEmpty = 1;
    }

    return 0;
}
//3 -------------------------------------------
int showEmployee(Employee emp)
{
    printf("%d\t%s\t%s\t%d\t%.2f\n", emp.id, emp.lastName, emp.name, emp.sector, emp.salary);

    return 0;
}
//4 -------------------------------------------
int printEmployees(Employee* arrayEmployee, int len)
{
    int flagFind=0;

    system("cls");
    printf("\nLegajo\tApellido Nombre Sector\tSueldo\n");

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty==0)
        {
            showEmployee(arrayEmployee[i]);
            flagFind=1;
        }
    }

    if(flagFind==0)
    {
        printf("\n(!) No hay empleados para mostrar (!)");
    }

    return 0;
}
//5 -------------------------------------------
int findEmpty(Employee* arrayEmployee, int len)
{
    int index=-1;

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }

    return index;
}
//6 -------------------------------------------
int checkEmpty(Employee* arrayEmployee, int len)
{
    int arrayEmpty=1;

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty == 0)
        {
            arrayEmpty=0;
            break;
        }
    }

    return arrayEmpty;
}
//8 -------------------------------------------
int addEmployee(Employee* arrayEmployee, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index = -1;

    index = findEmpty(arrayEmployee, len);

    arrayEmployee[index].id=id;
    strcpy(arrayEmployee[index].name,name);
    strcpy(arrayEmployee[index].lastName,lastName);
    arrayEmployee[index].salary=salary;
    arrayEmployee[index].sector=sector;
    arrayEmployee[index].isEmpty=0;

    //Esta función es invocada por getData, que en encarga de chequear que existe un lugar libre antes de pedirle los
    // datos al usuario. Entiendo que volver a buscar la posición libre en esta función es redundante, pero quise respetar
    //al pie de la letra los parámetros que recibe addEmployee y estos no incluyen el índice de la posición libre.

    return 0;
}
//9 -------------------------------------------
int getData(Employee* arrayEmployee, int len, int idMain)
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int canAdd;
    int noError=0;

    canAdd=findEmpty(arrayEmployee, len);

    if(canAdd!=-1)
    {

        id=idMain;

        getName(name,"\nIngrese el nombre del empleado: ","\nEl nombre no es valido", 2, 51);

        getName(lastName,"\nIngrese el apellido del empleado: ","\nEl apellido no es valido", 2, 51);

        getFloat(&salary,"\nIngrese el sueldo del empleado: ","\nEl sueldo no es valido", 10000, 50000);

        getInt(&sector,"\nIngrese el sector del empleado (1 a 5): ","\nEl sector no es valido", 1, 5);

        addEmployee(arrayEmployee, len, id, name, lastName, salary, sector);

        noError = 1;
    }
    else
    {
        printf("\n(!) No hay lugar en el sistema (!)\n");
    }

    return noError;
}
//10 -------------------------------------------
int findEmployeeById(Employee* arrayEmployee, int len, int idSearch)
{

    int index = -1;

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty == 0 && arrayEmployee[i].id == idSearch)
        {
            index = i;
            break;
        }
    }

    return index;
}
//11 -------------------------------------------
int removeEmployee(Employee* arrayEmployee, int len, int idSearch)
{
    int index;
    char confirm;

    index=findEmployeeById(arrayEmployee,len, idSearch);

    if(index == -1)
    {
        printf("\n(!) No existe un empleado con ese legajo (!)\n");
    }
    else
    {
        showEmployee(arrayEmployee[index]);
        printf("\n\nDesea dar de baja a este empleado? s/n: ");
        confirm = getche();
        if(tolower(confirm)=='s')
        {
            arrayEmployee[index].isEmpty=1;
            printf("\n\n-- Empleado dado de baja exitosamente --\n");
        }
    }
    return -1;
}
//12 -------------------------------------------
int sortEmployees(Employee* arrayEmployee, int len, int order)
{
    Employee auxEmp;

    if(order==1)
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName)>0)
                {
                    auxEmp = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[j];
                    arrayEmployee[j] = auxEmp;
                }
                else if((strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName)==0) && arrayEmployee[i].sector>arrayEmployee[j].sector)
                {
                    auxEmp = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[j];
                    arrayEmployee[j] = auxEmp;
                }
            }//Cierre 2do for
        }//Cierre 1er for
    }
    else
    {
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName)<0)
                {
                    auxEmp = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[j];
                    arrayEmployee[j] = auxEmp;
                }
                else if((strcmp(arrayEmployee[i].lastName, arrayEmployee[j].lastName)==0) && arrayEmployee[i].sector<arrayEmployee[j].sector)
                {
                    auxEmp = arrayEmployee[i];
                    arrayEmployee[i] = arrayEmployee[j];
                    arrayEmployee[j] = auxEmp;
                }
            }//Cierre 2do for
        }//Cierre 1er for
    }//Cierre else

    return 0;
}
//13 -------------------------------------------
int modifyEmployee(Employee* arrayEmployee, int len)
{
    int option;
    int idSearch;
    int index;
    char confirm;
    int flagEmpty;

    flagEmpty=checkEmpty(arrayEmployee,len);

    if(!flagEmpty)
    {
        system("cls");

        getInt(&idSearch,"Ingrese el legajo del empleado a modificar: ","\n(!) Legajo invalido (!)", 1, 5000);

        index=findEmployeeById(arrayEmployee,len, idSearch);

        if(index == -1)
        {
            printf("\n(!) No existe un empleado con ese legajo (!)\n");
        }
        else
        {
            showEmployee(arrayEmployee[index]);
            printf("\n\nDesea modificar a este empleado? s/n: ");
            confirm = getche();

            if(tolower(confirm)=='s')
            {
                printf("\n\n--- Modificar Empleados ---\n\n");
                printf("1- Modificar nombre\n");
                printf("2- Modificar apellido\n");
                printf("3- Modificar salario\n");
                printf("4- Modificar sector\n");

                getInt(&option,"Ingrese una opcion: ","\n(!) Opcion invalida (!)", 1, 4);

                switch(option)
                {
                case 1:
                    getName(arrayEmployee[index].name,"\nIngrese el nuevo nombre del empleado: ","\nEl nombre no es valido", 2, 51);
                    printf("\n\n-- Nombre modificado exitosamente --\n");
                    break;
                case 2:
                    getName(arrayEmployee[index].lastName,"\nIngrese el nuevo apellido del empleado: ","\nEl apellido no es valido", 2, 51);
                    printf("\n\n-- Apellido modificado exitosamente --\n");
                    break;
                case 3:
                    getFloat(&arrayEmployee[index].salary,"\nIngrese el nuevo sueldo del empleado: ","\nEl sueldo no es valido", 10000, 50000);
                    printf("\n\n-- Sueldo modificado exitosamente --\n");
                    break;
                default:
                    getInt(&arrayEmployee[index].sector,"\nIngrese el nuevo sector del empleado (1 a 5): ","\nEl sector no es valido", 1, 5);
                    printf("\n\n-- Sector modificado exitosamente --\n");
                }//Cierre Switch
            }//Cierre 3er if
        }//Cierre else
    }
    else
    {
        printf("\n(!) No hay empleados registrados (!)\n");
    }

    return 0;
}
//14 -------------------------------------------
int menuReport()
{
    int option;

    system("cls");
    printf("--- Informes Empleados ---\n\n");
    printf("1- Listar empleados alfabeticamente\n");
    printf("2- Reporte de sueldos\n");

    getInt(&option,"Ingrese una opcion: ","\n(!) Opcion invalida (!)", 1, 5);

    return option;
}
//15 -------------------------------------------
float salarySum(Employee* arrayEmployee, int len)
{
    float total=0;

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty == 0)
        {
            total = total + arrayEmployee[i].salary;
        }
    }
    return total;
}
//16 -------------------------------------------
float salaryAverage(Employee* arrayEmployee, int len)
{
    float total;
    float empNumber=0;
    float average;

    for(int i=0; i < len; i++)
    {
        if(arrayEmployee[i].isEmpty == 0)
        {
            empNumber++;
        }
    }
    total=salarySum(arrayEmployee,len);
    average=total/empNumber;

    return average;
}
//17 -------------------------------------------
int reports(Employee* arrayEmployee, int len)
{
    float total;
    float average;
    int overAverage=0;
    int flagEmpty;

    flagEmpty=checkEmpty(arrayEmployee,len);

    if(!flagEmpty)
    {
        switch(menuReport())
        {
        case 1:
            sortEmployees(arrayEmployee, len, 1);
            printEmployees(arrayEmployee, len);
            break;
        default:
            total=salarySum(arrayEmployee, len);
            average=salaryAverage(arrayEmployee, len);

            for(int i=0; i < len; i++)
            {
                if((arrayEmployee[i].isEmpty == 0) && arrayEmployee[i].salary>average)
                {
                    overAverage++;
                }
            }
            printf("\nSueldos totales: %.2f\n", total);
            printf("\nSueldo promedio: %.2f\n", average);
            printf("\nCantidad de empleados que superan el sueldo promedio: %d\n\n", overAverage);
        }
    }
    else
    {
        printf("\n(!) No hay empleados registrados (!)\n");
    }
    return 0;
}
