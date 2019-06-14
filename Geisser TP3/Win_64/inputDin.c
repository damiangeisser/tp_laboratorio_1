#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// 1 -------------------------------------------------------------------------------
int checkNumber(char* input)
{
    int error=0;

    for(int i=0; i<strlen(input); i++)
    {
        if(input[i]<'0' || input[i]>'9')
        {
            error=1;
            break;
        }
    }
    return error;
}
// 2 -------------------------------------------------------------------------------
int checkLetter(char* input)
{
    int error=0;

    for(int i=0; i<strlen(input); i++)
    {
        if((input[i]!=' ') && (input[i]<'a' || input[i]>'z') && (input[i]<'A' || input[i]>'Z'))
        {
            error=1;
            break;
        }
    }
    return error;
}
// 3 -------------------------------------------------------------------------------
int checkSymbol(char* input, char target, int maxCopies)
{
    int error=1;
    int copies=0;

    for(int i=0; i<strlen(input); i++)
    {
        if(input[i]==target)
        {
            copies++;
        }
    }

    if(copies>0 && copies<=maxCopies)
    {
        error = 0;
    }

    return error;
}

// 4 -------------------------------------------------------------------------------
int getInt(int* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    int valor;
    int returnScanf;
    int error = 1;

    printf("%s ", message);
    returnScanf = scanf("%d", &valor);

    while(returnScanf == 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%d", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
// 5 -------------------------------------------------------------------------------
int getFloat(float* input,char message[],char eMessage[], float lowLimit, float hiLimit)
{
    float valor;
    int returnScanf;
    int error = 1;

    printf("%s ", message);
    returnScanf = scanf("%f", &valor);

    while(returnScanf == 0 || valor < lowLimit || valor > hiLimit)
    {

        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        returnScanf = scanf("%f", &valor);
    }

    *input = valor;
    error = 0;

    return error;
}
// 6 ----------------------------------------------------------------------------------
int getChar(char* input,char message[],char eMessage[], char lowLimit, char hiLimit)
{
    char valor;
    int error = 1;

    printf("%s ", message);
    fflush(stdin);
    scanf("%c", &valor);

    while(valor < lowLimit || valor > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        scanf("%c", &valor);
    }

    *input = valor;
    error = 0;

    return error;

    //*input = 'S';
    //return 0;
}
// 7 ----------------------------------------------------------------------------------
int getString(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = 1;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    while(strlen(valor) < lowLimit || strlen(valor) > hiLimit)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);
    }

    strcpy(input,valor);

    error = 0;

    return error;
}
// 8 ----------------------------------------------------------------------------------
int getCharGender(char* input,char message[],char eMessage[])
{
    char valor;
    int error = 1;

    printf("%s ", message);
    fflush(stdin);
    scanf("%c", &valor);
    valor=toupper(valor);

    while(valor !='F' && valor !='M')
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        scanf("%c", &valor);
        valor=toupper(valor);
    }

    *input = valor;
    error = 0;

    return error;
}
// 9 ----------------------------------------------------------------------------------
int getDate(int* inputY, int* inputM, int* inputD, char message[], int yLowLimit, int yHiLimit)
{
    int day;
    int month;
    int year;
    int leap=0;//Bandera para los años bisiestos.
    int error = 1;
    char printYear[50]="Ingrese el anio de ";
    char printMonth[50]="Ingrese el mes de ";
    char printDay[50]="Ingrese el dia de ";

    strcat(printYear, message);
    strcat(printMonth, message);
    strcat(printDay, message);

    getInt(&year,printYear,"(!) El anio ingresado no es valido (!)\n", yLowLimit, yHiLimit);

    if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
    {
        leap=1;//El año es bisiesto.
    }

    *inputY = year;

    getInt(&month,printMonth,"(!) El mes ingresado no es valido (!)\n", 1, 12);

    *inputM = month;

    if(leap==0 && month == 2)
    {

        getInt(&day,printDay,"(!) No es un dia valido para el anio y mes ingresados (!)\n", 1, 28);

    }
    else if(leap==1 && month == 2)
    {

        getInt(&day,printDay,"(!) No es un dia valido para el anio y mes ingresados (!)\n", 1, 29);

    }
    else if(month == 4 || month == 6 || month == 9 || month == 11)
    {


        getInt(&day,printDay,"(!) No es un dia valido para el mes ingresado (!)\n", 1, 30);

    }
    else
    {
        getInt(&day,printDay,"(!) No es un dia valido (!)\n", 1, 31);
    }

    *inputD = day;

    error = 0;

    return error;
}
// 10 -------------------------------------------------------------------------------
int getPhone(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = 1;
    int notNumber;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    notNumber = checkNumber(valor);

    while((strlen(valor) < lowLimit || strlen(valor) > hiLimit)|| notNumber)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);
        notNumber = checkNumber(valor);
    }

    strcpy(input,valor);

    error = 0;

    return error;
}
// 11 -------------------------------------------------------------------------------
int titleCase(char* input)
{
    strlwr(input);

    input[0] = toupper(input[0]);

    for(int i=0; i<strlen(input); i++)
    {
        if(input[i] == ' ')
        {
            input[i+1] = toupper(input[i+1]);
        }
    }
    return 0;
}
// 12 -------------------------------------------------------------------------------
int getName(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = 1;
    int notLetter;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    notLetter=checkLetter(valor);

    while((strlen(valor) < lowLimit || strlen(valor) > hiLimit) || notLetter)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);

        notLetter=checkLetter(valor);
    }

    titleCase(valor);

    strcpy(input,valor);

    error = 0;

    return error;
}
// 13 -------------------------------------------------------------------------------
int getEmail(char* input,char message[],char eMessage[], int lowLimit, int hiLimit)
{
    char valor[50];
    int error = 1;
    int notAt;
    int notDot;

    printf("%s ", message);
    fflush(stdin);
    gets(valor);

    notAt=checkSymbol(valor,'@',1);

    notDot=checkSymbol(valor,'.',10);

    while((strlen(valor) < lowLimit || strlen(valor) > hiLimit) || notAt || notDot)
    {
        printf("\n%s\n", eMessage);
        printf("\n%s ", message);
        fflush(stdin);
        gets(valor);

        notAt=checkSymbol(valor,'@',1);
        notDot=checkSymbol(valor,'.',10);
    }

    strlwr(valor);

    strcpy(input,valor);

    error = 0;

    return error;
}

