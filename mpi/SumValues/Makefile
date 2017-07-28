FLAGS=

all: serialSum parallelSum

serialSum: serialSumValues.c
	mpicc $(FLAGS) serialSumValues.c -o serialSum

parallelSum: parallelSumValues.c
	mpicc $(FLAGS) parallelSumValues.c -o parallelSum

clean:
	rm -f serialSum parallelSum
