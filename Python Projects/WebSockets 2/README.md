# Informe
 
## Integrantes:
 
Angulo Israel Adrian  
Rodenas Balestrini Miguel Angel  
Uribe Tomas Alfonso  
 
---
## Estructura del servidor
 
El servidor que implementamos usa como medio un sistema de sockets programados que permiten la comunicación cliente/servidor realizado en el lenguaje python y usando como protocolo de transferencia de datos HFTP (Home-made File Transfer Protocol). 
 
El servidor se ejecuta con un host y número de puerto y conecta un socket. En ese momento el servidor espera o escucha hasta que llega una peticiones de algún clientes que desea conectarse. Luego el servidor acepta al cliente y crea e inicia el socket de comunicación. En este el cliente HFTP inicia el envío de mensajes de pedidos o comandos al servidor y el servidor responde a cada uno antes de procesar el siguiente hasta que el cliente envía un comando de fin de conexión, en caso que se envían múltiples comando el servidor responde en el orden que se enviaron.
 
Una vez el cliente esté desconectado el servidor termina la comunicación con el socket y nuevamente estará disponible para un nuevo cliente.
## Decisiones de diseño
 
Nuestras decisiones de diseño fueron:
Implementamos funciones para que el cliente pueda usarlos como "get_file_listing", "get_metadata", "get_slice" y "quit", todas estas con una función "handle" que se llama en el servidor permitiendo usar las 4 anteriores mencionadas. También se usó un sistema de buffer para poder almacenar comandos para tener mayor robustez y evitar problemas de comando malintencionados. También se planteó tener en cuenta la mayor cantidad de excepciones posibles, para un buen comportamiento del servidor.
## Dificultades que encontramos
 
Al momento de iniciar, no encontramos tantas complicaciones, ya que el grupo tenía algunas experiencias usando sockets previamente, pero sí hubo algunas complicaciones de interpretación de funciones, pero nada complicado de resolver debatiendo un poco y poniendo los puntos de vista de cada uno.  
Una dificultad que encontramos fue la hora de terminar la función handle, ya que teníamos algunos errores de funcionamiento, y en general el código podía ejecutarse, y funcionaba, pero no era tan robusto y al principio no pasaba correctamente los test. Los pasar los test fue principalmente la parte que más tiempo nos llevó solucionar más cerca del final del proyecto. Pero con paciencia pudimos completar todo.
## Preguntas
 
1. ¿Qué estrategias existen para poder implementar este mismo servidor pero con
capacidad de atender múltiples clientes simultáneamente? Investigue y responda
brevemente qué cambios serían necesarios en el diseño del código.
 
Por lo que estuvimos investigado existen varias formas de un servidor con múltiples clientes simultáneamente, por ejemplo un servidor UDP o TCP, pero en este caso sería ver con el servidor que tenemos debemos ver que estrategias utilizar.  
 
Algunas estrategias y la más mencionada es usando hilos o mejor dicho multihilos o en inglés multithreaded (usando threading)esto nos permitirá la conexión múltiple con varios clientes.  
 
Otra forma sería usando procesos para cada cliente, pero tras investigar este método suele no siempre funcionar.  
 
Por último vimos que había otra estrategia más pero bastante más compleja que utiliza un solo proceso y un solo hilo mediante bucles de evento asíncronos. Pero de esta última conseguimos información precisa y entendible, aunque encontramos un ejemplo de su uso para chat entre clientes.  
 
2. Pruebe ejecutar el servidor en una máquina del laboratorio, mientras utiliza el cliente
desde otra, hacia la ip de la máquina servidor. ¿Qué diferencia hay si se corre el
servidor desde la IP “localhost”, “127.0.0.1” o la ip “0.0.0.0”?

Entre la direccion IP "localhost", "127.0.0.1" y la ip "0.0.0.0" podemos entender que 127.0.0.1 y 0.0.0.0 apuntan a localhost, pero la diferencia es que, 127.0.0.1 es la direccion de bucle invertido ( tambien conocida como localhost), mientras que 0.0.0.0 es un meta direccion no enrutable utilizada para designar un invalido, desconocido o objeto no aplicable (un marcador de posición "sin dirección particular").
 
Entonces en el contexto de los servidores 0.0.0.0 significa todas las direcciones IPv4 en la máquina local. Es decir si un host tiene dos direcciones de ip y un servidor se ejecuta en el host escucha en 0.0.0.0, será accesible en ambas direcciones IP.
 
Mientras como ya mencionamos la dirección IP 127.0.0.1 es la dirección del protocolo de internet de bucle (IP) también conocida como localhost. La dirección se usa para establecer una conexión IP a la misma máquina o computadora que usa el usuario final.
