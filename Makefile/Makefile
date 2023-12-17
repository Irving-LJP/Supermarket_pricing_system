SRC = $(wildcard ./src/*.c)
IFLAGS = -I./include
LFLAGS = -L./lib -lc

bin/main:$(SRC)
	gcc $^ -o $@ $(IFLAGS)
clean:
	$(RM) bin/main
