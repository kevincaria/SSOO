/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 3 procesos hijos.

2. En un bucle, el proceso padre debe crear un proceso hijo en cada iteración.

3. En la tercera iteración, si el proceso es un hijo (es decir, `fork()` devuelve 0), 
debe ejecutar el comando `ls -l` utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `ls -l`.

*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int num;
    pid_t nuevo;  

for (num= 1; num<= 3; num++){
nuevo= fork();
if ((num== 3) && (nuevo== 0))
execlp ("ls", "ls", "-l", NULL);
}
    return 0;
}