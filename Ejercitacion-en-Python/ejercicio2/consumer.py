import socket

def consumer():
    # Crea un socket
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        # Conéctate al socket del productor
        s.connect(('localhost', 12345))
        # Lee los datos del socket
        message = s.recv(1024).decode()
        print("Datos recibidos del productor:", message)

if __name__ == "__main__":
    consumer()