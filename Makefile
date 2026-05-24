all: src/main.c
	if not exist build mkdir build
	gcc src/main.c -o build/main.exe
run:
	./build/main.exe
clean: 
	del /q /f build\main.exe