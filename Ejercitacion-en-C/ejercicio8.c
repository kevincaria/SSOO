/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. El programa debe crear un total de 2 procesos hijos.

2. El proceso padre debe crear un proceso hijo. Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), 
debe imprimir su PID y el PID de su proceso padre, esperar a que su proceso hijo termine 
y luego ejecutar el comando `ps -eaf` utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `ps -eaf`.

3. El primer proceso hijo debe crear otro proceso hijo. Si el proceso actual es el primer proceso hijo (es decir, `fork()` 
devuelve un valor distinto de 0), debe imprimir su PID y el PID de su proceso padre, ejecutar el comando `df -h` utilizando la función `execlp()` 
y luego esperar a que su proceso hijo termine. Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `df -h`.

4. El segundo proceso hijo debe imprimir su PID y el PID de su proceso padre, y luego ejecutar el comando `ls -l` utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `ls -l`.

*/
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
int i, j;
pid_t pid;

pid=fork();

if(pid!=0)
{
printf("SOY EL PROCESO PADRE:%d (PROCESOS) Y MI PADRE ES:%d\n",getpid(),getppid());
wait(NULL);
execlp ("ps", "ps","-eaf", NULL);
}
else
{
pid=fork();
        if(pid!=0)
        {
        printf("SOY EL PROCESO HIJO: %d (ESPACIO EN DISCO) Y MI PADRE ES:%d\n",getpid(),getppid());
        execlp ("df","df","-h", NULL);
        wait(NULL);
        }

        else
        {
        printf("SOY EL PROCESO HIJO:%d (LS) Y MI PADRE ES:%d\n",getpid(),getppid());
        execlp("ls","ls","-l",NULL);
        exit(0);
        }
}

return 0;
}
