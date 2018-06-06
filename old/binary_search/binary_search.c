#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <omp.h>

// A recursive binary search function. It returns 
// location of x in given array arr[l..r] is present, 
// otherwise -1
int binary_search(int x, int arr[], int l, int r)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        //printf("mid: %d\n", mid);
 
        // If the element is present at the middle 
        // itself
        if (arr[mid] == x)  
            return mid;
 
        // If element is smaller than mid, then 
        // it can only be present in left subarray
        if (arr[mid] > x) 
            return binary_search(x, arr, l, mid-1);
 
        // Else the element can only be present
        // in right subarray
        return binary_search(x, arr, mid+1, r);
   }
 
   // We reach here when element is not 
   // present in array
   return -1;
}


void readFileUnsigned(unsigned *input, char *filename, int size) {
    FILE *finput;
    if (finput = fopen(filename, "rb")) {
        //printf("oi entrei no input\n");
        fread(input, size * sizeof(unsigned), 1 , finput);
    } else {
        printf("Error reading input file");
        exit(1);
    }
}

int main(int argc, char** argv)
{
    int size, iterations, num_search, result;
    char * inputFile, *outputFile;
    unsigned *data;

    if (argc == 5) {
        size = atoi(argv[1]);
        //printf("size: %d\n", size);
		num_search = atoi(argv[2]);
        //printf("num_search: %d", num_search);
        //omp_num_threads = atoi(argv[3]);
        inputFile = argv[3];
        //printf("inputFile: %c\n", *inputFile);
        outputFile = argv[4];
        //printf("outputFile: %c\n", *outputFile);
    } else {
        fprintf(stderr, "Usage: %s <input size> <num_search> <input file> <output file>\n", argv[0]);
        //exit(1);
    }
    //omp_set_num_threads(omp_num_threads);

    data = (unsigned *)malloc(size*sizeof(unsigned));

    readFileUnsigned(data, inputFile, size);

    result = binary_search(num_search, data, 0, size-1);
    //printf("result: %d\n", result);

    FILE *fp;
    if (fp = fopen(outputFile, "wb")) {
        //printf("oi entrei no arquivo output\n");

		/*
		Checagem do resultado enviado pela função, tamanho e vetor recebidos
		
        fprintf(stderr, "%d    %d\n", result, size);
		int i;
		for(i=0;i<10;i++)
        	fprintf(stderr, "%d\n", data[i]);
		*/

        fwrite(&result, size * sizeof(unsigned), 1 , fp);
    } else {
        printf("Error writing output file\n");
        exit(1);
    }
    fclose(fp);

    printf("Done\n");

    return 0;
}
