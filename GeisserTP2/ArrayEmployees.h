typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

/**
* \brief Genera un menu de opciones, pide un int validado y lo devuelve.
* \param No recibe parámetros.
* \return El int que pide.
*
*/
int menu();

/**
* \brief Incializa los el vector seteando .isEmpty en 1.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return El int que pide.
*
*/
int initEmployees(Employee* arrayEmployee, int len);

/**
* \brief Muestra por pantalla los campos una estructura Employee.
* \param Employee emp es el elemento del array de estructuras que se quiere mostrar.
* \return Retorna 0 al finalizar su función.
*
*/
int showEmployee(Employee emp);

/**
* \brief Recorre un vector de estructuras Employee e imprime los campos de sus elementos. Valida que el vector no esté vacío.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return Retorna 0 al finalizar su función.
*
*/
int printEmployees(Employee* arrayEmployee, int len);

/**
* \brief Recorre un vector de estructuras Employee buscando el primer lugar vacío y lo devuelve.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return index posición del primer espacio vacío.
*
*/
int findEmpty(Employee* arrayEmployee, int len);

/**
* \brief Recorre un vector de estructuras Employee buscando un lugar vacío.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return arrayEmpty 1 si está vacío, 0 si no lo está.
*
*/
int checkEmpty(Employee* arrayEmployee, int len);

/**
* \brief Recorre un vector de estructuras Employee buscando un espacio libre. Asigna o copia los valores recibidos en los campos de esa posición.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \param int id es el id asignado a la estructura Employee libre en el campo homónimo.
* \param char name es string asignado a la estructura Employee libre en el campo homónimo.
* \param char lastName es string asignado a la estructura Employee libre en el campo homónimo.
* \param float salary es float asignado a la estructura Employee libre en el campo homónimo.
* \param int sector es el id asignado a la estructura Employee libre en el campo homónimo.
* \return Retorna 0 al finalizar su función.
*
*/
int addEmployee(Employee* arrayEmployee, int len, int id, char name[],char lastName[],float salary,int sector);

/**
* \brief Solicita el ingreso de los datos a guardar en los campos de una estructura empleado, excepto el id. Valida que haya espacio en el array.
* \param Employee* arrayEmployee el vector a recorrer buscando espacio libre.
* \param int len tamaño del vector a recorrer.
* \param int idMain es el valor auincremental que la función asignará al id de la nueva estructura.
* \return noError 1 si completó la tarea con éxito, 0 si no.
*
*/
int getData(Employee* arrayEmployee, int len, int idMain);

/**
* \brief Recorre un vector de estructuras Employee buscando una estructura en particular por su campo id.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \param int idSearch es el id de la estructura Employee buscada.
* \return index posición del elemento buscado.
*
*/
int findEmployeeById(Employee* arrayEmployee, int len, int idSearch);

/**
* \brief Recorre un vector de estructuras Employee buscando una estructura en particular por su campo id para darle de baja lógicamente.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \param int idSearch es el id de la estructura Employee buscada.
* \return Retorna 0 al finalizar su función.
*
*/
int removeEmployee(Employee* arrayEmployee, int len, int idSearch);

/**
* \brief Ordena un vector de estructuras Employee de forma ascendente o descendente por apellido y por sector.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \param int order determina si es ascendente 1 ó descendente 0.
* \return Retorna 0 al finalizar su función.
*
*/
int sortEmployees(Employee* arrayEmployee, int len, int order);

/**
* \brief Recorre un vector de estructuras Employee buscando una estructura en particular por su campo id para modificar su nombre, apellido o sector.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return Retorna 0 al finalizar su función.
*
*/
int modifyEmployee(Employee* arrayEmployee, int len);

/**
* \brief Genera un menu de opciones para el reporte, pide un int validado y lo devuelve.
* \param No recibe parámetros.
* \return El int que pide.
*
*/
int menuReport();

/**
* \brief Recorre un vector de estructuras Employee sumando en una acumulador el campo salary de los elementos.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return float total la suma de todos los campos salary hallados.
*
*/
float salarySum(Employee* arrayEmployee, int len);

/**
* \brief Recorre un vector de estructuras Employee contando los elementos dados de alta. Saca el promedio de los sueldos y lo devuelve.
* \param Employee* arrayEmployee el vector a recorrer.
* \param int len tamaño del vector a recorrer.
* \return float average promedio de los sueldos.
*
*/
float salaryAverage(Employee* arrayEmployee, int len);

/**
* \brief Presenta un switch que permite acceder a las funciones de reportes.
* \param Employee* arrayEmployee el vector a recorrer por las funciones de reporte.
* \param int len tamaño del vector a recorrer por las funciones de reporte.
* \return Retorna 0 al finalizar su función.
*
*/
int reports(Employee* arrayEmployee, int len);
