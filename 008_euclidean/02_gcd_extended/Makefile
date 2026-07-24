# sudo apt install make
#
#   make        — собрать программу в bin/app
#   make run    — собрать и запустить
#   make test   — собрать и прогнать тесты
#   make clean  — удалить obj/ и bin/
#
# Путь до общей библиотеки тестов — задан один раз, меняется в одном месте.
TESTSUITE = ../../utils/testsuite

# -I добавляет папку в список тех, где ищутся #include "...".
CFLAGS = -Wall -g -Wextra -std=c11 -Ialgo -I$(TESTSUITE)

all: bin/app

bin/app: obj/main.o obj/algo.o
	mkdir -p bin
	gcc obj/main.o obj/algo.o -o bin/app

bin/tests: obj/test_algo.o obj/algo.o obj/testsuite.o
	mkdir -p bin
	gcc obj/test_algo.o obj/algo.o obj/testsuite.o -o bin/tests

obj/main.o: exec/main.c algo/algo.h
	mkdir -p obj
	gcc $(CFLAGS) -c exec/main.c -o obj/main.o

obj/algo.o: algo/algo.c algo/algo.h
	mkdir -p obj
	gcc $(CFLAGS) -c algo/algo.c -o obj/algo.o

obj/test_algo.o: tests/test_algo.c algo/algo.h $(TESTSUITE)/testsuite.h
	mkdir -p obj
	gcc $(CFLAGS) -c tests/test_algo.c -o obj/test_algo.o

obj/testsuite.o: $(TESTSUITE)/testsuite.c $(TESTSUITE)/testsuite.h
	mkdir -p obj
	gcc $(CFLAGS) -c $(TESTSUITE)/testsuite.c -o obj/testsuite.o

run: bin/app
	./bin/app

test: bin/tests
	./bin/tests

clean:
	rm -rf obj bin

.PHONY: all run test clean
