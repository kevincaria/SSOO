"""
Realizar un programa en Phyton que comunique 2 procesos o 2 Threads de un mismo proceso que a través de una “cola de mensajes”. 
Envíe información de un string entre uno y otro proceso. 
El código debe estar comentado con lo que realizan en cada punto y deberá explicar cómo funciona el sistema de cola de mensaje en su programa.
"""
import multiprocessing

# Funcion que envia mensajes a la cola
def sender(queue):
    messages = ["Hola", "¿Cómo estás?", "Espero que estés bien"]
    for message in messages:
        queue.put(message) # Guarda un mensaje en la cola
        print(f"Enviado: {message}")
    # Envía un mensaje de finalización
    queue.put(None)

# Funcion que recibe mensajes de la cola
def receiver(queue):
    while True:
        message = queue.get()  # Obtiene un mensaje de la cola
        if message is None:  # Si el mensaje es None, termina el bucle
            break
        print(f"Recibido: {message}")  # Imprime el mensaje recibido

if __name__ == "__main__":
    # Crea una cola de mensajes
    message_queue = multiprocessing.Queue()

    # Crea los procesos
    sender_process = multiprocessing.Process(target=sender, args=(message_queue,))
    receiver_process = multiprocessing.Process(target=receiver, args=(message_queue,))

    # Inicia los procesos
    sender_process.start()
    receiver_process.start()
