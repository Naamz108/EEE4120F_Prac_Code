//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory
__kernel void matrixMultiplication(__local int* Size,__global int* output,__local int* matrixA,__local int* matrixB){
	
	//TODO: program your kernel here
	int size = Size;
	
	for(int i = 0; i < Size; i++){
				for(int j = 0; j < Size; j++)
				{
					output[i*size+j] = 0;
					for(int k = 0; k < Size; k++)
					{
						output[i*size+j] += matrixA[k]*matrixA[k*size + j];
					}
				}
		}
	
}




