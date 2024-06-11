"""
Realizar dos programas Phyton que comunique el proceso de cada programa (proceso productor y proceso consumidor) 
a través de una “memoria  compartida”. 
Envíe información de un string entre uno y otro proceso. 
El código debe estar comentado con lo que realizan en cada punto 
y deberá explicar cómo funciona el sistema de compartición por memoria compartida en su programa.
"""
import socket

def producer():
    # Crea un socket
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Enlaza el socket a una dirección y un puerto
        s.bind(('localhost', 12345))
        # Escucha conexiones entrantes
        s.listen()
        # Acepta una conexión
        conn, addr = s.accept()
        with conn:
            # Escribe datos en el socket
            message = "Hola, consumidor! Te estoy enviando un mensaje !"
            conn.sendall(message.encode())

if __name__ == "__main__":
    producer()