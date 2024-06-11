/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 7 procesos, incluyendo el proceso padre.

2. En un bucle, el proceso padre debe crear dos procesos hijos. Si el proceso es un hijo (es decir, `fork()` devuelve 0), 
debe romper el bucle y no crear más procesos hijos.

3. Después del bucle, el proceso padre y los dos procesos hijos deben crear dos procesos hijos adicionales cada uno.

4. Cada proceso, incluido el proceso padre, debe imprimir su PID (ID de proceso) y el PID de su proceso padre.

*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int num;
    pid_t nuevo;  

for (num= 0; num< 2; num++) {
nuevo= fork();/* 1 */
if (nuevo== 0)
break;
}
nuevo= fork(); /* 2 */
nuevo= fork(); /* 3 */
printf("Soy el proceso %d y mi padre es %d\n", getpid(), getppid());
    return 0;
}