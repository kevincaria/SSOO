/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 6 procesos, incluyendo el proceso padre.

2. En un bucle externo, el proceso padre debe crear un proceso hijo en cada iteración. 
Este bucle debe ejecutarse 3 veces.

3. Dentro de cada iteración del bucle externo, debe haber un bucle interno que se ejecute 2 veces.

4. En cada iteración del bucle interno, el proceso actual debe crear un nuevo proceso hijo. 
Si el proceso actual es un hijo (es decir, `fork()` devuelve 0), debe imprimir su PID y el PID de su proceso padre, y luego romper ambos bucles.

5. Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), 
debe continuar con la siguiente iteración del bucle interno.

6. Al final de cada iteración del bucle externo, si el proceso actual es el proceso padre, debe romper el bucle externo.

7. Al final del programa, si el proceso actual es el proceso padre, 
debe esperar a que todos sus procesos hijos terminen antes de imprimir un mensaje que indique que cada proceso hijo ha terminado.

*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define L1 2
#define L2 3

int main (int argc, char *argv[]) {
    int cont1, cont2;
    pid_t pid;

    for (cont2= 0; cont2< L2; cont2++) {
        for (cont1= 0; cont1< L1; cont1++) {
            pid= fork();
            if (pid== 0) {
                printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n", getpid(), getppid());
                break;
            }
        }
        if (pid != 0) {
            break;
        }
    }

    if (pid != 0) {
        for (cont1= 0; cont1< L1; cont1++) {
            printf ("Fin del proceso de PID %d.\n", wait (NULL));
        }
    }

    return 0;
}