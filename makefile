default:
	gcc -std=c11 -fdiagnostics-color=always -g main.c queue.c genericLinkedList.c safeGet.c -o bin/main.exe -Wall

windows:
	gcc -std=c11 -fdiagnostics-color=always -g main.c queue.c genericLinkedList.c safeGet.c -o bin/main.exe -Wall

linux:
	gcc -std=c11 -fdiagnostics-color=always -g main.c queue.c genericLinkedList.c safeGet.c -o bin/main -Wall