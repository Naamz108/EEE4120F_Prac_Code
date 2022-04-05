//TODO: set your arguments for the kernel. Note that you have to indicate if the argument is global or local. Global arguments are accessable by both host and this target device. While local can only be accessed by the device running this kernel. eg __global int* inputMatrixA, __local int* groupMemory
__kernel void matrixMultiplication(__global int* Size,__global int* output,__global int* matrixA,__global int* matrixB){
	
	//TODO: program your kernel here
	int workItemNum = get_global_id(0);
	int size = *Size;
	printf("kernal working, work item num: %d \n",workItemNum);
	printf("Size parsed: %d \n",size);
	printf("matrixA parsed %d \n",matrixA);

	int temp = 0;

	for(int k = 0; k < size; k++)
	{
		temp += matrixA[k + workItemNum]*matrixA[k*size + workItemNum];
	}

	output[workItemNum] = temp;
}




