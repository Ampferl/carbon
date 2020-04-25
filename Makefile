CORE_PATH = ./src/core/
OBJECTS = $(CORE_PATH)main.c

build: $(objects)
	gcc $(OBJECTS) -o carbon

clean:
	rm -rf *.o carbon
