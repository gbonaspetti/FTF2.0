#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* C program for recursive implementation of Bubble sort */

void swap(int* a, int*b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int bubbleOne(int arr[], int n)
{
    int ret = 1;
    if (n <= 1)
    {
        return 1;
    }
	if (arr[0] > arr[1])
	{
		swap(&arr[0], &arr[1]);
		ret = 0;
	}
	return bubbleOne(arr+1, n-1) && ret;
}

void bubbleSort(int arr[], int n)
{
	if (n <= 1 || bubbleOne(arr, n))
	{
	    return;
    }
	bubbleSort(arr, n-1);
}

void readInput(unsigned *input, char *filename, int size) {
	FILE *finput;
	if (finput = fopen(filename, "rb")) {
		fread(input, size * sizeof(unsigned), 1 , finput);
	} else {
		printf("Error reading input file");
		exit(1);
	}
}


int main(int argc, char** argv)
{
	int size;
	char * inputFile, * outputFile;
	unsigned *data, *test;

	if (argc == 4) {
		size = atoi(argv[1]);
		inputFile = argv[2];
		outputFile = argv[3];
	} else {
		fprintf(stderr, "Usage: %s <input size> <input file> <output file> \n", argv[0]);
		exit(1);
	}

	data = (unsigned *)malloc(size*sizeof(unsigned));

	readInput(data, inputFile, size);

	int i;
	for(i=0;i<size;i++)
		printf("%d  ", data[i]);
	printf("\n\n");

	bubbleSort(data, size);

	for(i=0;i<size;i++)
		printf("%d  ", data[i]);
	printf("\n\n");

	FILE *finput;
	if (finput = fopen(outputFile, "wb")) {
		fwrite(data, size * sizeof(unsigned), 1 , finput);
	} else {
		printf("Error writing  output file");
		exit(1);
	}
	fclose(finput);


	return 0;
}

