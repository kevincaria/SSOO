/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 2*(i+2) procesos hijos en cada iteración del bucle externo, donde `i` es la iteración actual del bucle externo.

2. En un bucle externo, el proceso padre debe crear un proceso hijo en cada iteración. Este bucle debe ejecutarse 2 veces.

3. Dentro de cada iteración del bucle externo, debe haber un bucle interno que se ejecute `i+2` veces.

4. En cada iteración del bucle interno, el proceso actual debe crear un nuevo proceso hijo. 
Si el proceso actual es un hijo (es decir, `fork()` devuelve 0), debe imprimir su PID y el PID de su proceso padre, y luego romper ambos bucles.

5. Después de romper el bucle interno, si el proceso actual es un hijo, 
debe ejecutar la aplicación "gnome-calculator" utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute la aplicación "gnome-calculator".

6. Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), 
debe crear otro proceso hijo, imprimir su PID y el PID de su proceso padre, 
y luego ejecutar la aplicación "xload" utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute la aplicación "xload".

7. Al final de cada iteración del bucle externo, si el proceso actual es el proceso padre, 
debe esperar a que todos sus procesos hijos terminen antes de continuar con la siguiente iteración del bucle externo.

8. Al final del programa, si el proceso actual es el proceso padre, debe imprimir el tiempo total de ejecución del programa.

*/

#include <sys/wait.h>
#include <unistd.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int i, j;
    pid_t pid, nuevo, nuevo1;
    time_t ini, fin;

    ini = time(NULL);

    for (i= 0; i< 2; i++){
        pid= getpid();
        for (j= 0; j< i+2; j++){
            nuevo= fork();
            if(nuevo== 0){
                printf("Soy el proceso de PID=%d y mi padre tiene=%d de PID. (i=%d, j=%d)\n", getpid(), getppid(), i, j);
                break;
            }
            nuevo1= fork();
            if(nuevo1== 0) {
                printf("Soy el proceso de PID=%d y mi padre tiene=%d de PID. (i=%d, j=%d)\n", getpid(), getppid(), i, j);
                execlp ("xload", "xload", NULL);
                exit(0);
            }
            wait(NULL);
        }
        if (pid!= getpid()) {
            execlp ("gnome-calculator", "gnome-calculator", NULL);
            exit(0);
        }
        wait(NULL);
    }

    fin = time(NULL);
    printf("Tiempo total de ejecución: %ld segundos\n", fin - ini);

    return 0;
}
