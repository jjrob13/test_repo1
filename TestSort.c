#include <stdio.h>
#include <stdlib.h>

int* mergeSort(int*, int);
int* merge(int*, int*, int, int);
void printArray(int*, int);
int main(int argc, char* argv[]){


	
	//Change input reading to fit needs and everything else should work
	
	int arraySize;
	scanf("%d", &arraySize);
	int *array = malloc(sizeof(int) * arraySize);

	for(int i = 0; i < arraySize; i++) {
		scanf("%d", &array[i]);
	}

	printArray(array, arraySize);


	array = mergeSort(array, arraySize);

	printArray(array, arraySize);

	free(array);

	return 0;

}


int* mergeSort(int* array, int size) {

	if(size == 1)
	{
		return array;
	}


	int tempSize1, tempSize2, split = size/2;

	tempSize1 = split;
	tempSize2 = split;

	//Not an evenly space array.
	if(size % 2 == 1) {
		tempSize2++;
	}

	int *temp1 = malloc(sizeof(int) * tempSize1);
	int *temp2 = malloc(sizeof(int) * tempSize2);

	//fill temp arrays
	for(int i = 0; i < tempSize1; i++) {
		temp1[i] = array[i];
	}

	for(int i = 0; i < tempSize2; i++) {
		temp2[i] = array[split + i];
	}


	temp1 = mergeSort(temp1, tempSize1);
	temp2 = mergeSort(temp2, tempSize2);

	array = merge(temp1, temp2, tempSize1, tempSize2);

	free(temp1);
	free(temp2);

	return array;


}


int* merge(int* a, int* b, int sizeA, int sizeB) {
	int* result = malloc(sizeof(int) * (sizeA + sizeB)), index = (sizeA + sizeB)-1;

	while(sizeA != 0 && sizeB != 0) {
		if(b[sizeB - 1] > a[sizeA - 1]) {
			result[index--] = b[--sizeB];
		}else {
			result[index--] = a[--sizeA];
		}
		
	}

	if(sizeA == 0) {
		while(sizeB != 0) {
			result[index--] = b[--sizeB];
		}
	}else {
		while(sizeA != 0) {
			result[index--] = a[--sizeA];
		}
	}

	return result;
}

void printArray(int* array, int size) {
	printf("[ ");
	for(int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("]\n");
}