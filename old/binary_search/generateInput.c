#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Se mudar o INPUTSIZE, lembrar de mudar também no makefile o nome do arquivo input
#define INPUTSIZE 2000000

void merge(unsigned *X, int l, int r, unsigned *tmp) {
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

void mergesort(unsigned *X, int l, int r, unsigned *tmp)
{
	if (l >= r) return;
	int mid = (l+r)/2;
	mergesort(X, l, mid, tmp);
	mergesort(X, mid+1, r, tmp);

	merge(X, l, r, tmp);
}

int main(int argc, char** argv){
	srand(time(NULL));

	int size, range;
	if (argc == 3) {
        range = atoi(argv[1]);
        size = atoi(argv[2]);
    } else {
        fprintf(stderr, "Usage: %s <input range> <input size>\n", argv[0]);
        exit(1);
    }

	int k = INPUTSIZE, *ndata = NULL, i;

	ndata = (int *)malloc(k * sizeof(int));

	for (i = 0; i < k; i++)
	{
		ndata[i] = rand() % range + 1;
	}

/*
    unsigned *ndata = (unsigned*)malloc(INPUTSIZE*sizeof(unsigned));
    printf("Generating input, this will take a long time..."); 
	fflush(stdout);

    for (unsigned int i=0; i<INPUTSIZE; i++)
    {
        // Build data 8 bits at a time
		ndata[i] = 0;
        char *ptr = (char *)&(ndata[i]);

        for (unsigned j=0; j<sizeof(unsigned); j++)
        {
	        *ptr++ = (char)(rand() & 255);
        }
	}
*/

	unsigned *tmp;
	tmp = (unsigned *)malloc(size*sizeof(unsigned));
	
	/*
	for(i=0;i<10;i++){
    	fprintf(stderr, "%d  ", ndata[i]);
	}
    fprintf(stderr, "\n");
	*/
	
	mergesort(ndata, 0,size-1, tmp);
	
	/*	
	for(i=0;i<10;i++){
    	fprintf(stderr, "%d  ", ndata[i]);
	}
    fprintf(stderr, "\n");
	*/

	free(tmp);


	char input_name[500];
    snprintf(input_name, 500, "input_%d",INPUTSIZE);
	FILE *finput;
    	if (!(finput = fopen(input_name, "wb"))) {
        	printf("Warning! Couldn't write the input to file, proceeding anyway...\n");
        } else {
        	fwrite(ndata, INPUTSIZE*sizeof(unsigned), 1 , finput);
            fclose(finput);
        }
        printf("Done.\n");
}
