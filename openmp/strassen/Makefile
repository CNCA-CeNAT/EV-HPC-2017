all: strassen

strassen: strassen.cpp 
	icpc -qopenmp -o strassen strassen.cpp 
	icpc -w -o strassen_serial strassen.cpp 

clean:
	rm -f strassen strassen_serial
