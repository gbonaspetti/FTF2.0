#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* C program for recursive implementation of Bubble sort */

void swap(int* a, int*b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bubbleOne(int arr[], int n) {
  int ret = 1;

  if (n <= 1) {
    return 1;
  }
  if (arr[0] > arr[1]) {
    swap(&arr[0], &arr[1]);
    ret = 0;
  }
  return bubbleOne(arr+1, n-1) && ret;
}

void bubbleSort(int arr[], int n) {
  if (n <= 1 || bubbleOne(arr, n)) {
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

unsigned * ibubble_wrapper(int size, char * inputFile) {
  unsigned *data = (unsigned *)malloc(size*sizeof(unsigned));

  readInput(data, inputFile, size);
  bubbleSort(data, size);

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
    fprintf(stderr, "Usage: %s <input size> <input file> <output file> <detectLog file>\n", argv[0]);
    exit(1);
  }

  // Execute bubblesort and save the result at data1
    data1 = ibubble_wrapper(size, inputFile);
    // Execute bubblesort and save the result at data2
    data2 = ibubble_wrapper(size, inputFile);

    // Compare outputs to check for SDCs
    compare_output(size, data1, data2, detectLog);

    writeInput(data1, outputFile, size);

    free(data1);
    free(data2);

  return 0;
}
