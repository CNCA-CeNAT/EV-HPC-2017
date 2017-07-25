SRC=vader.c
BIN=$(SRC).out

all:
	gcc $(SRC) -o $(BIN)

build0:
	gcc $(SRC)

build1:
	gcc $(SRC) -o $(BIN)

build2:
	gcc -g $(SRC) -o $(BIN)

build3:
	gcc $(SRC) -O0 -o $(BIN).O0 -S

build4:
	gcc $(SRC) -O3 -o $(BIN).O3 -S

compile_only:
	gcc $(SRC) -C -o $(BIN).t

link_only:
	gcc *.t -o $(BIN)

asm:
	gcc $(SRC) -S


asm-O0:
	gcc $(SRC) -S -o $(BIN).S.O0


asm-O3:
	gcc $(SRC) -S -o $(BIN).S.O3


