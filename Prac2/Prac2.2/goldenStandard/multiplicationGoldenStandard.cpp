
//Author: Christopher Hill For the EEE4120F course at UCT

#include<stdio.h>
#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include <tuple>
#include <ctime>
using namespace std;



//creates a square matrix of dimensions Size X Size, with the values being the column number
void createKnownSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = j + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}


//creates a random square matrix of dimensions Size X Size, with values ranging from 1-100
void createRandomSquareMatrix(int Size, int* squareMatrix, bool displayMatrices){

	
	for(int i = 0; i<Size; i++){
		
		for(int j = 0; j<Size; j++){
			squareMatrix[i*Size+j] = rand() % 100 + 1;
			if(displayMatrices){
				cout<<squareMatrix[i*Size+j]<<"\t ";
			}
		}
		if(displayMatrices){
			cout<<"\n";
		}
	}
	

}




int main(void){
	int Size = 5;
	cout<<"Enter square matrix column/row size: \n";
	cin>>Size;
	clock_t startRuntime = clock();
	//New code for prac 2.2
	bool displayMatrices = true;
	int countA = Size*Size;
	int* matrixA = new int[countA];
	createKnownSquareMatrix(Size,matrixA, displayMatrices);
	cout<<"Number of elements in matrix 1: "<<countA<<"\n";
	cout<<"Dimensions of matrix 1: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 1 pointer: "<<matrixA<<"\n";
	

	
	
	int countB = Size*Size;
	int* matrixB = new int[countB];
	createKnownSquareMatrix(Size, matrixB, displayMatrices);
	cout<<"Number of elements in matrix 2: "<<countB<<"\n";
	cout<<"Dimensions of matrix 2: "<<Size<<"x"<<Size<<"\n";
	cout<<"Matrix 2 pointer: "<<matrixB<<"\n";
	
	
	int* output = new int[countA];

	//TODO: code your golden standard matrix multiplication here
	clock_t startCalcTime = clock();

		for(int i = 0; i < Size; i++){
				for(int j = 0; j < Size; j++)
				{
					output[i*Size+j] = 0;
					for(int k = 0; k < Size; k++)
					{
						output[i*Size+j] += matrixA[k]*matrixA[k*Size + j];
					}
				}
		}

		clock_t endCalc = clock();			
	
	//This if statement will display the matrix in output	
	if(displayMatrices){
		printf("\nOutput in the output_buffer \n");
		for(int j=0; j<countA; j++) {
			printf("%i \t " ,output[j]);
			if(j%Size == (Size-1)){
				printf("\n");
			}
		}
	}
	
	clock_t endPrint = clock();
	printf ("Calc Time: %0.8f sec \n",((float) endCalc - startCalcTime)/CLOCKS_PER_SEC);
	printf ("Run Time: %0.8f sec \n",((float) endPrint - startRuntime)/CLOCKS_PER_SEC);
	delete[] matrixA;
	delete[] matrixB;
	delete[] output;

	return 0;
}
