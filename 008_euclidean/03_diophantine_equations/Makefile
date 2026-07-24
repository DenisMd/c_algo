# sudo apt install make
#
#   make        — собрать программу в bin/app
#   make run    — собрать и запустить
#   make test   — собрать и прогнать тесты
#   make clean  — удалить obj/ и bin/
#
# Этот урок ПЕРЕИСПОЛЬЗУЕТ расширенный алгоритм Евклида из прошлого урока:
# исходник gcd_ext компилируется в obj/gcd_ext.o и линкуется сюда.

# Путь до общей библиотеки тестов — задан один раз, меняется в одном месте.
TESTSUITE = ../../utils/testsuite

# Прошлый урок: берём эталонную реализацию gcd_ext (solved_algo).
# Уже решили урок 02? Можно переключить на $(GCD_EXT_DIR)/algo/algo.c.
GCD_EXT_DIR = ../02_gcd_extended
GCD_EXT_SRC = $(GCD_EXT_DIR)/algo/solved_algo/algo.c
GCD_EXT_HDR = $(GCD_EXT_DIR)/algo/algo.h

# -I добавляет папку в список тех, где ищутся #include "...".
CFLAGS = -Wall -g -Wextra -std=c11 -Ialgo -I$(TESTSUITE)

all: bin/app

bin/app: obj/main.o obj/algo.o obj/gcd_ext.o
	mkdir -p bin
	gcc obj/main.o obj/algo.o obj/gcd_ext.o -o bin/app

bin/tests: obj/test_algo.o obj/algo.o obj/gcd_ext.o obj/testsuite.o
	mkdir -p bin
	gcc obj/test_algo.o obj/algo.o obj/gcd_ext.o obj/testsuite.o -o bin/tests

obj/main.o: exec/main.c algo/algo.h
	mkdir -p obj
	gcc $(CFLAGS) -c exec/main.c -o obj/main.o

obj/algo.o: algo/algo.c algo/algo.h $(GCD_EXT_HDR)
	mkdir -p obj
	gcc $(CFLAGS) -c algo/algo.c -o obj/algo.o

# gcd_ext из прошлого урока. Компилируем с его собственным заголовком:
# -I на его папку algo, чтобы его #include "algo.h" нашёл именно тот файл.
obj/gcd_ext.o: $(GCD_EXT_SRC) $(GCD_EXT_HDR)
	mkdir -p obj
	gcc -Wall -g -Wextra -std=c11 -I$(GCD_EXT_DIR)/algo -c $(GCD_EXT_SRC) -o obj/gcd_ext.o

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
