/*
Consigna:

1. Desarrolle un programa en C que utilice la función `fork()` para crear nuevos procesos. 
El programa debe crear un total de 2 procesos hijos.

2. El proceso padre debe crear un proceso hijo. Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), 
debe imprimir su PID y el PID de su proceso padre, y luego ejecutar el comando `ls -l` utilizando la función `execlp()`. Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `ls -l`.

3. El primer proceso hijo debe imprimir su PID y el PID de su proceso padre, y luego ejecutar el comando `ps` utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `ps`.

4. Después de que el primer proceso hijo termine, el proceso padre debe crear otro proceso hijo. 
Si el proceso actual es el proceso padre (es decir, `fork()` devuelve un valor distinto de 0), debe esperar a que su segundo proceso hijo termine.

5. El segundo proceso hijo debe imprimir su PID y el PID de su proceso padre, 
y luego ejecutar el comando `df -h` utilizando la función `execlp()`. 
Asegúrese de pasar los argumentos correctos a `execlp()` para que se ejecute el comando `df -h`.

6. Al final del programa, si el proceso actual es el proceso padre, debe esperar a que todos sus procesos hijos terminen antes de terminar 
el programa.

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

if(pid==0)
{
printf("SOY EL PROCESO HIJO:%d (PROCESOS) Y MI PADRE ES:%d\n",getpid(),getppid());
execlp ("ps", "ps", NULL);
exit(0);
}
else
{

pid=fork();
        if(pid==0)
        {
        printf("SOY EL PROCESO HIJO: %d (ESPACIO EN DISCO) Y MI PADRE ES:%d\n",getpid(),getppid());
        execlp ("df","df","-h", NULL);
        exit(0);
        }

        else
        {
        printf("SOY EL PROCESO PADRE:%d (LS) Y MI PADRE ES:%d\n",getpid(),getppid());
        execlp("ls","ls","-l",NULL);
        wait(NULL);
        }
}
wait(NULL);
return 0;
}