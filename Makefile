default:
	gcc -o rm rm.c
	gcc -o cat cat.c
	gcc -o date date.c
	gcc -o ls ls.c
	gcc -o ls1 ls1.c
	gcc -o lsa lsa.c
	gcc -o mkdir mkdir.c
	gcc main.c -lreadline
	./a.out