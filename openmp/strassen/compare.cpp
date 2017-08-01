/**
 * Costa Rica Institute of Technology
 * School of Computing
 * ce5504: High Performance Computing
 * Instructor Esteban Meneses, PhD (emeneses@ic-itcr.ac.cr)
 * Compares two output files.
 */

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// Reads two files and compares them
int compare_files(int N, char *file_name_A, char *file_name_B, float error){
	ifstream file_A(file_name_A);
	ifstream file_B(file_name_B);
	float value_A, value_B;

	if(file_A.is_open() && file_B.is_open()){
		
		// reading values
		for(int i=0; i<N; i++){
			file_A >> value_A;
			file_B >> value_B;
			if(fabs(value_A-value_B)/fmin(fabs(value_A),fabs(value_B)) > error){
				file_A.close();
				file_B.close();
				return 1;
			}
		}

		// closing files
		file_A.close();
		file_B.close();

	} else {
		cout << "Error opening files: " << file_name_A << " and " << file_name_B << endl;
		return 1;
	}
	return 0;
}

// Main method      
int main(int argc, char* argv[]) {
	int N, result;
	float error;

	// checking parameters
	if (argc != 4 && argc != 5) {
		cout << "Parameters: <N> <file_A> <file_B> [<error>]" << endl;
		return 1;
	}
	N = atoi(argv[1]);

	// reading error (optional)
	if(argc == 5){
		error = atof(argv[4]);
	} else {
		error = 0.0;
	}

	// comparing files
	result = compare_files(N,argv[2],argv[3],error);
	if(!result)
		cout << "OK" << endl;
	else
		cout << "FAIL" << endl;
	return 0;	
}

