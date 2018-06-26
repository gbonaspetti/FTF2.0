# C compiler
CC = gcc -std=c99 -std=gnu99 -g
CC_FLAGS = -fopenmp

destDir = /tmp/merge_fulldup

all: gen_bin gen_data mv_bin

gen_bin: merge_fulldup.c generateInput.c
	$(CC) $(CC_FLAGS) merge_fulldup.c -o merge_fulldup
	$(CC) $(CC_FLAGS) generateInput.c -o genInput

gen_data: gen_bin
	./genInput
	./merge_fulldup 1000000 inputsort_1000000 gold_1000000 /tmp/merge_fulldup_detection.log

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput merge_fulldup inputsort_1000000 gold_1000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean:
	rm *.o merge_fulldup genInput gold_1000000 inputsort_1000000
