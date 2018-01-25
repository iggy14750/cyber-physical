
top: bin/lab1.exe

run:
	./bin/lab1.exe

bin/lab1.exe: bin lab1_algo.c
	gcc lab1_algo.c -o bin/lab1

bin:
	mkdir bin