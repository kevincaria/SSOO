/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 2 procesos hijos.

2. En un bucle externo, el proceso padre debe crear un proceso hijo en cada iteración.

3. Dentro de cada iteración del bucle externo, debe haber un bucle interno que se ejecute `i+2` veces, 
donde `i` es la iteración actual del bucle externo.

4. En cada iteración del bucle interno, el proceso actual debe crear un nuevo proceso hijo. 
Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), 
debe imprimir su PID y el PID de su proceso padre, luego crear otro proceso hijo, 
imprimir nuevamente su PID y el PID de su proceso padre, y finalmente romper el bucle interno.

5. Si el proceso actual no es el proceso padre (es decir, `fork()` devuelve 0), 
debe continuar con la siguiente iteración del bucle interno sin crear un nuevo proceso hijo.

6. Al final de cada iteración del bucle externo, si el proceso actual no es el proceso padre, debe romper el bucle externo.

*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int i; int j;
    pid_t nuevo, pid;  

    for (i= 0; i< 2; i++) {
        pid= getpid();
        for (j= 0; j< i+2; j++) {
            nuevo= fork(); /* 1 */
            if (nuevo!= 0) {
                printf("Soy el proceso de PID=%d y mi padre tiene=%d de PID. (i=%d, j=%d)\n", getpid(), getppid(), i, j);
                nuevo= fork(); /* 2 */
                if (nuevo != 0) {
                    printf("Soy el proceso de PID=%d y mi padre tiene=%d de PID. (i=%d, j=%d)\n", getpid(), getppid(), i, j);
                }
                break;
            }
        }
        if (pid!= getpid())
            break;
    }

    return 0;
}