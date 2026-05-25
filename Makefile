all: src/main.c
	if not exist build mkdir build
	gcc src/main.c -o build/main.exe
run:
	./build/main.exe
clean: 
ifeq ($(OS),Windows_NT)
	rmdir /q /s build
else 
	rm -rf build
endif