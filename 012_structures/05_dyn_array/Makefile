# make - собрать bin/app, make clean - удалить obj и bin
# проверка утечек: valgrind -q --leak-check=full ./bin/app

CFLAGS = -Wall -Wextra -std=c17 -g

bin/app: obj/main.o obj/dyn_array.o
	mkdir -p bin
	gcc obj/main.o obj/dyn_array.o -o bin/app

obj/main.o: main.c dyn_array.h
	mkdir -p obj
	gcc $(CFLAGS) -c main.c -o obj/main.o

obj/dyn_array.o: dyn_array.c dyn_array.h
	mkdir -p obj
	gcc $(CFLAGS) -c dyn_array.c -o obj/dyn_array.o

clean:
	rm -rf obj bin
