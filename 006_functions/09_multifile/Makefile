# sudo apt install make
# Сборка в два этапа: .c -> .o (в папку obj), затем линковка -> bin/app.
# Заголовок account.h сам не компилируется — его подключают через #include.

bin/app: main account
	mkdir -p bin
	gcc obj/main.o obj/account.o -o bin/app

main: main.c account.h
	mkdir -p obj
	gcc -c main.c -o obj/main.o

account: account.c account.h
	mkdir -p obj
	gcc -c account.c -o obj/account.o

clean:
	rm -rf obj bin
