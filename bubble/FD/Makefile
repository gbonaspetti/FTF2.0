# C compiler
CC = gcc -std=c99 -std=gnu99 -g
CC_FLAGS = -fopenmp

destDir = /tmp/bubble_fulldup

all: gen_bin gen_data mv_bin

gen_bin: bubble_fulldup.c generateInput.c
	$(CC) $(CC_FLAGS) bubble_fulldup.c -o bubble_fulldup
	$(CC) $(CC_FLAGS) generateInput.c -o genInput

gen_data: gen_bin
	./genInput
	./bubble_fulldup 10 inputsort_1000000 gold_1000000 /tmp/bubble_fulldup_detection.log

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput bubble_fulldup inputsort_1000000 gold_1000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean:
	rm *.o bubble_fulldup genInput gold_1000000
