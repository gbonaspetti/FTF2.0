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
	./merge 1000000 inputsort_1000000 gold_1000000

mv_bin: gen_data
	mkdir -p $(destDir)
	cp genInput merge inputsort_1000000 gold_1000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean:
	rm *.o merge genInput gold_1000000 inputsort_1000000
