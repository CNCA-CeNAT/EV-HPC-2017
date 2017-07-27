#
# Escuela de veranillo en computacion de alto rendimiento.
# 24-28 julio 2017
# CNCA, CeNAT.
# 
# M. Sc. Ricardo Roman-Brenes, PRIS-Lab/EIE/UCR
# ricardo.roman@ucr.ac.cr
#

SRC=vader.c
BIN=$(SRC).out

all:
	gcc $(SRC) -o $(BIN)

# compilacion sin opciones
build0: 
	gcc $(SRC)

# especificando nombre del archivo de salida
build1:
	gcc $(SRC) -o $(BIN)

# generando la tabla de simbolos para depuracion
build2:
	gcc -g $(SRC) -o $(BIN)

# optimizacion nivel 0 (sin optimizacion)
O0:
	gcc $(SRC) -O0 -o $(BIN).O0

# optimizacion nivel 3 (maximo nivel)
O3:
	gcc $(SRC) -O3 -o $(BIN).O3 

# solo compilar
compile_only:
	gcc $(SRC) -C -o $(BIN).t

# solo enlazar
link_only:
	gcc *.t -o $(BIN)

# generacion de codigo ensamblador
asm:
	gcc $(SRC) -S

# generacion de codigo ensamblador con optimizacion 0
asm-O0:
	gcc $(SRC) -O0 -S -o $(BIN).S.O0

# generacion de codigo ensamblador con optimizacion 3
asm-O3:
	gcc $(SRC) -O3 -S -o $(BIN).S.O3


