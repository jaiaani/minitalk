# Minitalk:
``The purpose of this project is to code a small data exchange program
using UNIX signals.``

A simple project demonstrating message passing between processes using **UNIX signals**.  
 
- The **client** sends the message bit by bit using the allowed signals, where one will represent the 0 and other 1.
- The **server** decrypts the binary signal stream and prints the received message to `stdout`.  

###
> "Linux System does NOT queue signals when you already have pending signals of this type"

So if you send multiple signals of the same type very quickly, the system will only keep one pending signal of each type.
If the process for handling them is slow, extra signals will be lost.

#### Example:  
```bash
# Client (sending "hii" repeatedly)  
jiraya@jaiaani:~/minitalk$ ./client 238820 "hii"  
jiraya@jaiaani:~/minitalk$ ./client 238820 "hii"  
jiraya@jaiaani:~/minitalk$ ./client 238820 "hii"  

# Server (output with corruption due to signal loss)  
jiraya@jaiaani:~/minitalk$ ./server  
238820  
hii  
hii  
hii  
^��  
���������������  
```

In order to control this, on the mandatory part, you can alter the time the client waits to send the next signal.

In Bonus, signal loss is avoided by having the client send the next character only after it acknowledges that the server has processed the full character.
