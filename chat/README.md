gcc -o server server.c chat.c
gcc -o client client.c chat.c

./server [port_number]

./client [nickname] [port_number]

OR (need to check)
./client <nickname> <port>
./client John 12345s