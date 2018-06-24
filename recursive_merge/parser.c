#include <stdio.h>
#include <stdlib.h>

void readInput(unsigned *input, char *filename, int size) {
    FILE *finput;
    if (finput = fopen(filename, "rb")) {
        fread(input, size * sizeof(unsigned), 1 , finput);
    } else {
        printf("Error reading input file");
        exit(1);
    }
}


void compare_output(int size, unsigned *data1, unsigned *data2, char *compFile) {
    int i, qntd=0;
    FILE *fp;
    for(i=0; i<size; i++) {
        if(data1[i] != data2[i]) {
		qntd++;
        }
    }

    float porcent;
    porcent = (100.0*qntd)/size;

    if (fp = fopen(compFile, "a")) {
    	fprintf(fp, "%d elementos - %f%%\n\n",qntd,porcent);
        fclose(fp);
    }
}


int main(int argc, char** argv)
{
    	int size;
    	char * inputFile, * outputFile, *compFile;

    	if (argc == 5) {
        	size = atoi(argv[1]);
        	inputFile = argv[2];
        	outputFile = argv[3];
		compFile= argv[4];
    	} else {
        	fprintf(stderr, "Usage: %s <input size> <input file> <output file> <comp file>\n", argv[0]);
        	exit(1);
	}


	unsigned *data1 = (unsigned *)malloc(size*sizeof(unsigned));
	unsigned *data2 = (unsigned *)malloc(size*sizeof(unsigned));

    readInput(data1, inputFile, size);
	readInput(data2, outputFile, size);

/*	int i;
	printf("\n DATA 1:    ");
	for(i=0; i<size; i++)
	{
		printf("%d   ", data1[i]);
	}

	printf("\n DATA 2:    ");
	for(i=0; i<size; i++)
	{
		printf("%d   ", data2[i]);
	}
	printf("\n");
*/
	compare_output(size, data1, data2, compFile);

	free(data1);
	free(data2);


	return 0;
}
