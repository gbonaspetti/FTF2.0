#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void merge_FD(unsigned * X, int l, int r, unsigned * tmp) {
    int i = l;
    int mid = (l+r)/2;
    int j = mid + 1;
    int ti = l;

    while (i<=mid && j<=r) {
        if (X[i] < X[j]) {
            tmp[ti] = X[i];
            ti++;
            i++;
        } else {
            tmp[ti] = X[j];
            ti++;
            j++;
        }
    }
    while (i<=mid) { /* finish up lower half */
        tmp[ti] = X[i];
        ti++;
        i++;
    }
    while (j<=r) { /* finish up upper half */
        tmp[ti] = X[j];
        ti++;
        j++;
    }

    for(i=l; i<=r; i++) {
        X[i]=tmp[i];
    }

}

void mergesort_FD(unsigned * X, int l, int r, unsigned * tmp)
{
    if (l >= r) return;
    int mid = (l+r)/2;

    mergesort_FD(X, l, mid, tmp);
    mergesort_FD(X, mid+1, r, tmp);

    merge_FD(X, l, r, tmp);
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

unsigned * rmerge_wrapper(int size, char * inputFile) {

    unsigned *data = (unsigned *)malloc(size*sizeof(unsigned));
  	unsigned *tmp = (unsigned *)malloc(size*sizeof(unsigned));

    readInput(data, inputFile, size);

    mergesort_FD(data, 0,size-1, tmp);

		free(tmp);
    return data;
}

void compare_output(int size, unsigned *data1, unsigned *data2, char *detectLog) {
    int i;
    FILE *fp;
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
    char * inputFile, * outputFile, *detectLog;
    unsigned *data1, *data2;

    if (argc == 5) {
        size = atoi(argv[1]);
        inputFile = argv[2];
        outputFile = argv[3];
				detectLog = argv[4];
    } else {
        fprintf(stderr, "Usage: %s <input size> <input file> <output file> <detectLog>\n", argv[0]);
        exit(1);
    }

    // Execute mergesort and save the result at data1
    data1 = rmerge_wrapper(size, inputFile);
    // Execute mergesort and save the result at data2
    data2 = rmerge_wrapper(size, inputFile);

    // Compare outputs to check for SDCs
    compare_output(size, data1, data2, detectLog);


		writeInput(data1, outputFile, size);
    //printf("\nDone\n");

		free(data1);
    free(data2);



    return 0;
}
