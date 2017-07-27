all: shear

shear: shear.cpp shear_main.cpp
	icpc -qopenmp -o shear shear.cpp shear_main.cpp
	icpc -w -o shear_serial shear.cpp shear_main.cpp

clean:
	rm -f shear shear_serial
