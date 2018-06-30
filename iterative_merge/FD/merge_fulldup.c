#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Utility function to find minimum of two integers
int min(int x, int y) { return (x<y)? x :y; }

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int n)
{
	int curr_size;  // For current size of subarrays to be merged
                   // curr_size varies from 1 to n/2
   	int left_start; // For picking starting index of left subarray
                   // to be merged

   // Merge subarrays in bottom up manner.  First merge subarrays of
   // size 1 to create sorted subarrays of size 2, then merge subarrays
   // of size 2 to create sorted subarrays of size 4, and so on.
	for (curr_size=1; curr_size<=n-1; curr_size = 2*curr_size)
   	{
       // Pick starting point of different subarrays of current size
       for (left_start=0; left_start<n-1; left_start += 2*curr_size)
       {
           // Find ending point of left subarray. mid+1 is starting
           // point of right
           int mid = min(left_start + curr_size - 1, n - 1);

           int right_end = min(left_start + 2*curr_size - 1, n-1);

           // Merge Subarrays arr[left_start...mid] & arr[mid+1...right_end]
           merge(arr, left_start, mid, right_end);
       }
   }
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

unsigned * imerge_wrapper(int size, char * inputFile) {

    unsigned *data = (unsigned *)malloc(size*sizeof(unsigned));

    readInput(data, inputFile, size);

	mergeSort(data, size);

    return data;
}

void compare_output(int size, unsigned *data1, unsigned *data2, char *detectLog) {
    
	int i;
    FILE *fp;
                printf("%d", size);
				

    for(i=0; i<size; i++) {
        if(data1[i] != data2[i]) {
            if (fp = fopen(detectLog, "a")) {
				
                fprintf(fp, "[%d]: %u %u\n",i,data1[i],data2[i]);
                fclose(fp);
            }

        }
    }
}

void writeInput(unsigned *data, char *outputFile, int size) {
		FILE *output;
		if (output = fopen(outputFile, "wb")) {
				fwrite(data, size * sizeof(unsigned), 1 , output);
		} else {
				printf("Error writing  output file");
				exit(1);
		}
		fclose(output);
}

int main(int argc, char** argv)
{
	int size;
	char *inputFile, *outputFile, *detectLog;
	unsigned *data1, *data2;

	if (argc == 5) {
		size = atoi(argv[1]);
		inputFile = argv[2];
		outputFile = argv[3];
		detectLog = argv[4];
	} else {
		fprintf(stderr, "Usage: %s <input size> <input file> <output file> <detectLog file>\n", argv[0]);
		exit(1);
	}

    // Execute mergesort and save the result at data1
    data1 = imerge_wrapper(size, inputFile);
    // Execute mergesort and save the result at data2
    data2 = imerge_wrapper(size, inputFile);

    // Compare outputs to check for SDCs
    compare_output(size, data1, data2, detectLog);


	writeInput(data1, outputFile, size);
    //printf("\nDone\n");

	free(data1);
    free(data2);

	return 0;
}
