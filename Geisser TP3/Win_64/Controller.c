#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputDin.h"
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* fCSV;

    int loadCheck;

    fCSV = fopen(path,"r");

    if(fCSV == NULL)
    {
        printf(" (!) No se pudo abrir el archivo de texto (!)\n");
        system("pause");
    }
    else
    {

        loadCheck = parser_EmployeeFromText(fCSV,pArrayListEmployee);
    }

    fclose(fCSV);

    if(loadCheck)
    {

        printf("\n>> Archivo de texto cargado exitosamente <<\n");
        system("pause");
    }

    return 1;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)//Revisar
{
    FILE* fBIN;

    int loadCheck=1;

    fBIN = fopen(path,"rb");

    if(fBIN == NULL)
    {
        printf("(!) No se pudo abrir el archivo binario (!)\n");
        system("pause");
    }
    else
    {
        loadCheck = parser_EmployeeFromBinary(fBIN,pArrayListEmployee);
    }


    fclose(fBIN);

    if(loadCheck)
    {

        printf("\n>> Archivo binario cargado exitosamente <<\n");
        system("pause");
    }

    return 1;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    Employee* empAux;

    char buffer[3][20];
    char idAux;
    char nameAux[30];
    int hoursAux;
    int wageAux;

    idAux=itoa(ll_len(pArrayListEmployee)+1,buffer[0],10);

    system("cls");
    printf("Alta de empleado\n\n");
    printf("ID autogenerado del nuevo empleado: %s\n",buffer[0]);
    getName(nameAux,"Ingrese el nombre del empleado:","El nombre no es valido",1,30);
    getInt(&hoursAux,"Ingrese la cantidad de horas trabajadas en el mes:","La cantidad no es valida", 0,300);
    getInt(&wageAux,"Ingrese el sueldo del empleado:", "El sueldo no es valido", 10000,80000);

    empAux=employee_newParametros(buffer[0],nameAux,itoa(hoursAux,buffer[1],10),itoa(wageAux,buffer[2],10));

    ll_add(pArrayListEmployee, empAux);

    printf(">> Empleado dado de alta exitosamente <<\n");
    system("pause");

    return 1;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int listLimit;
    int searchID;
    char confirmChar;
    int option;
    int foundFlag = 0;
    Employee* pEmpAux;

    listLimit=ll_len(pArrayListEmployee);

    if(!listLimit)
    {
        printf("\n(!) No existen empleados cargados en el sistema (!)\n");
        system("pause");
    }
    else
    {
        getInt(&searchID,"Por favor ingrese el ID del empleado que desea modificar: ","El ID ingresado no es valido", 0, 5000);

        for(int i =0; i<listLimit; i++)
        {
            pEmpAux=ll_get(pArrayListEmployee, i);

            if(pEmpAux->id==searchID)
            {
                printf("\n");
                mostrarEmpleado(pEmpAux);

                foundFlag=1;

                printf("\n\nPresione s para modificar a este empleado: ");
                fflush(stdin);
                confirmChar = getche();
                printf("\n");

                if(tolower(confirmChar) == 's')
                {
                    do
                    {
                        system("cls");
                        getInt(&option,"\nIndique la modificacion que desee realizar:\n1- Modificar ID\n2- Modificar nombre\n3- Modificar horas\n4- Modificar sueldo\n5- Salir\n","\n(!)Opcion no valida (!)\n",1,5);
                        switch(option)
                        {
                        case 1:
                            getInt(&pEmpAux->id, "\nIngrese el nuevo ID: ","\n(!) Id invalido (!)\n",0,5000);
                            printf("\n>> ID modificado exitosamente <<\n");
                            system("pause");
                            break;
                        case 2:
                            getName(&pEmpAux->nombre, "\nIngrese el nuevo nombre: ","\n(!) Nombre invalido (!)\n",1,20);
                            printf("\n>> Nombre modificado exitosamente <<\n");
                            system("pause");
                            break;
                        case 3:
                            getInt(&pEmpAux->horasTrabajadas, "\nIngrese la nueva cantidad de horas: ","\n(!) Cantidad invalida (!)\n",0,800);
                            printf("\n>> Cantidad de horas modificada exitosamente <<\n");
                            system("pause");
                            break;
                        case 4:
                            getInt(&pEmpAux->sueldo , "\nIngrese el nuevo sueldo: ","\n(!) Sueldo invalido (!)\n",10000,80000);
                            printf("\n>> Sueldo modificado exitosamente <<\n");
                            system("pause");
                        default:
                            printf("\nVolviendo al menu principal\n");
                        }
                    }
                    while(option!=5);


                    system("pause");
                }
                break;
            }
        }
        if(!foundFlag)
        {
            printf("\nNo fue posible encontrar a un empleado con ese ID\n");
            system("pause");
        }
    }
    return 1;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int listLimit;
    int searchID;
    char confirmChar;
    int foundFlag = 0;
    Employee* pEmpAux;

    listLimit=ll_len(pArrayListEmployee);

    if(!listLimit)
    {
        printf("\n(!) No existen empleados cargados en el sistema (!)\n");
        system("pause");
    }
    else
    {
        getInt(&searchID,"Por favor ingrese el ID del empleado que desea dar de baja: ","El ID ingresado no es valido", 0, 5000);

        for(int i =0; i<listLimit; i++)
        {
            pEmpAux=ll_get(pArrayListEmployee, i);

            if(pEmpAux->id==searchID)
            {
                printf("\n");
                mostrarEmpleado(pEmpAux);

                foundFlag=1;

                printf("\n\nPresione s para dar de baja a este empleado: ");
                fflush(stdin);
                confirmChar = getche();
                printf("\n");

                if(tolower(confirmChar) == 's')
                {
                    ll_remove(pArrayListEmployee, i);
                    printf("\nEmpleado dado de baja exitosamente\n");
                    system("pause");
                }
                break;
            }
        }
        if(!foundFlag)
        {
            printf("\nNo fue posible encontrar a un empleado con ese ID\n");
            system("pause");
        }
    }
    return 1;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int counter=0;

    if(!ll_len(pArrayListEmployee))
    {
        printf("\n(!) No existen empleados cargados en el sistema (!)\n");
        system("pause");
    }
    else
    {
        system("cls");
        printf("\nEmpleados:\n");
        printf("\nID\tNombre\tHoras\tSueldo\n\n");

        for(int i = 0; i < ll_len(pArrayListEmployee); i++)
        {
//            if(counter==50)
//            {
//                system("pause");
//                counter=0;
//            }
            mostrarEmpleado((Employee*) ll_get(pArrayListEmployee,i));
            counter++;
        }
        system("pause");
    }

    return 1;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int listLimit;
    Employee* pEmpA = employee_new();
    Employee* pEmpB = employee_new();
    Employee* pEmpAux = employee_new();

    listLimit=ll_len(pArrayListEmployee);//Determino el tamaño de la lista.

    if(!listLimit)
    {
        printf("\n(!) No existen empleados cargados en el sistema (!)\n");
        system("pause");
    }
    else if (pEmpA!=NULL && pEmpB != NULL && pEmpB!=NULL)
    {
        for(int i=0; i<listLimit; i++)
        {
            for(int j=i+1; j<listLimit; j++)
            {
                pEmpA=ll_get(pArrayListEmployee, i);
                pEmpB=ll_get(pArrayListEmployee, j);

                if(strcmp(pEmpA->nombre,pEmpB->nombre)>0)
                {
                    *pEmpAux=*pEmpA;
                    *pEmpA=*pEmpB;
                    *pEmpB=*pEmpAux;
                }//strcmp
            }//for j
        }//for i

        printf("\n>> Lista ordenada alfabeticamente con exito <<\n");
        system("pause");

    }//else

    return 1;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pText;

    int listSize;
    Employee* pEmpAux;

    pText=fopen(path,"w");

    listSize = ll_len(pArrayListEmployee);

    if(pText==NULL)
    {
        printf("\n(!) Error al escribir el archivo de texto (!)");
        system("pause");
    }
    else
    {
        fprintf(pText, "id,nombre,horasTrabajadas,sueldo");

        for(int i=0; i < listSize; i++)
        {
            pEmpAux = ll_get(pArrayListEmployee, i);

            fprintf(pText,"%d,%s,%d,%d", pEmpAux->id, pEmpAux->nombre, pEmpAux->horasTrabajadas, pEmpAux->sueldo);
        }
        printf("\n>> Archivo de texto guardado exitosamente <<\n");
        system("pause");
    }

    fclose(pText);

    return 1;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pBin;

    int listSize;
    Employee* pEmpAux;

    pBin=fopen(path,"wb");

    listSize = ll_len(pArrayListEmployee);

    if(pBin==NULL)
    {
        printf("\n(!) Error al escribir el archivo binario (!)");
        system("pause");
    }
    else
    {
        for(int i=0; i < listSize; i++)
        {
            pEmpAux = ll_get(pArrayListEmployee, i);
            fwrite((void*)pEmpAux,sizeof(Employee),1,pBin);
        }
        printf("\n>> Archivo binario guardado exitosamente <<\n");
        system("pause");
    }

    fclose(pBin);

    return 1;
}

int controller_menu()
{
    int option;

    system("cls");
    printf("  --- ABM Empleados ---\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)\n");
    printf("3. Alta de un empleado\n");
    printf("4. Modificar datos de un empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)\n");
    printf("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)\n");
    printf("10. Salir\n");
    getInt(&option,"Ingrese una opcion: ","(!) Opcion invalida (!)", 1, 10);

    return option;
}

char controller_exit(LinkedList* pArrayListEmployee)
{
    char exitChar;

    printf("\nConfirma la salida del programa? s/n: ");
    fflush(stdin);
    exitChar = getche();

    if(tolower(exitChar) == 's')
    {
        ll_deleteLinkedList(pArrayListEmployee);
        printf("\n\n- Programa finalizado -\n");
    }

    return exitChar;

}

