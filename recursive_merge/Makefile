# C compiler
CC = gcc -std=c99 -std=gnu99 -g
CC_FLAGS = -fopenmp

destDir = /tmp/recursive_merge

all: gen_bin gen_data mv_bin

gen_bin: recursive_merge.c generateInput.c
	$(CC) $(CC_FLAGS) recursive_merge.c -o recursive_merge
	$(CC) $(CC_FLAGS) generateInput.c -o genInput 

gen_data: gen_bin
	./genInput
	./recursive_merge 100000000 inputsort_100000000 gold_100000000

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput recursive_merge inputsort_100000000 gold_100000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean: 
	rm *.o recursive_merge genInput gold_100000000
