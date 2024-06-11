/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear tres procesos hijos en total.

2. Cada proceso, incluido el proceso padre, debe imprimir su PID (ID de proceso) y el PID de su proceso padre.

3. Si el proceso es un proceso hijo (es decir, `fork()` devuelve 0), debe romper el bucle y no crear más procesos hijos. 
Solo el proceso padre debe crear los tres procesos hijos.

4. Si el proceso es un proceso hijo, debe dormir durante un período de tiempo aleatorio antes de terminar. 
Utilice la función `srandom()` para inicializar la semilla del generador de números aleatorios con el PID del proceso actual, 
y luego `random()%5` para generar un número aleatorio de segundos para dormir.

5. Si el proceso es el proceso padre, debe esperar a que todos sus procesos hijos terminen antes de imprimir un mensaje 
que indique que cada proceso hijo ha terminado y luego termine.

*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main (int argc, char *argv[]) {
int num;
pid_t pid;
srandom(getpid());

for (num= 0; num< 3; num++) {
pid= fork();
printf ("Soy el proceso de PID %d y mi padre tiene %d de PID.\n",getpid(), getppid());
if (pid== 0)
break;
}

if (pid== 0)
sleep(random() %5);
else
for (num= 0; num< 3; num++)
printf ("Fin del proceso de PID %d.\n", wait (NULL));
return 0;
}
