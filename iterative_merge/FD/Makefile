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
	./merge_fulldup 100000 inputsort_100000 gold_100000 /tmp/merge_fulldup_detection.log

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput merge_fulldup inputsort_100000 gold_100000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean:
	rm *.o merge_fulldup genInput gold_100000 inputsort_100000
