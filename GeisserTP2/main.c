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

#define TAM_EMP 20

int main()
{
//    Employee empList[TAM_EMP]= {{101,"Juan", "Perez", 20000,1,0},
//        {102,"Maria", "Gomez", 23000,2,0},
//        {103,"Julian", "Gomez", 24000,3,0},
//        {104,"Liliana", "Smith", 32000,5,0},
//        {105,"Pedro", "Perez", 25500,1,0},
//        {106,"Carlos", "Garcia", 23000,2,0},
//    };//Hardcoding para testeo.

    int idAuto=1;
    int banderaAlta;
    char exit;
    char cont='s';
    int auxId;
    int flagEmpty=0;

    Employee empList[TAM_EMP];

    initEmployees(empList, TAM_EMP);

    do
    {
        switch(menu())
        {
        case 1:
            banderaAlta = getData(empList, TAM_EMP, idAuto);
            if(banderaAlta)
            {
                idAuto++;
            }
            banderaAlta=0;
            system("pause");
            break;
        case 2:
            modifyEmployee(empList, TAM_EMP);
            system("pause");
            break;
        case 3:
            flagEmpty=checkEmpty(empList, TAM_EMP);
            if(!flagEmpty)
            {
                getInt(&auxId,"\nIngrese el legajo del empleado a dar de baja: ","\n(!) No es un legajo valido (!)\n", 1, 5000);
                removeEmployee(empList, TAM_EMP, auxId);//Respeté el hecho de que esta función debe recibir el id. El getInt lo hubiese incluído en la función de no ser por la consigna del TP.
            }
            else
            {
                printf("\n(!) No hay empleados registrados (!)\n");
            }//Respeté el hecho de que removeEmployee debe recibir el id y no puede pedirlo. Si no hubiese confirmado que el array tiene elementos en la misma función como en el caso 2 y 4.
        system("pause");
        break;
    case 4:
        reports(empList, TAM_EMP);
        system("pause");
        break;
    default:
        printf("\nConfirma la salida del programa? s/n: ");
        fflush(stdin);
        exit = getche();

        if( tolower(exit) == 's')
        {
            printf("\n\n- Programa finalizado -\n");
            cont = 'n';
        }
    }
}
while(cont == 's');

return 0;
}


