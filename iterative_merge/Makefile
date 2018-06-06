# C compiler
CC = gcc -std=c99 -std=gnu99 -g
CC_FLAGS = -fopenmp

destDir = /tmp/merge

all: gen_bin gen_data mv_bin

gen_bin: merge.c generateInput.c
	$(CC) $(CC_FLAGS) merge.c -o merge
	$(CC) $(CC_FLAGS) generateInput.c -o genInput

gen_data: gen_bin
	./genInput
	./merge 100000 inputsort_100000 gold_100000

mv_bin: gen_data
	mkdir -p $(destDir)
	cp genInput merge inputsort_100000 gold_100000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean:
	rm *.o merge genInput gold_100000 inputsort_100000
