# C compiler
CC = gcc -std=c99 -std=gnu99 -g
CC_FLAGS = -fopenmp

destDir = /tmp/bubble

all: gen_bin gen_data mv_bin

gen_bin: bubble.c generateInput.c
	$(CC) $(CC_FLAGS) bubble.c -o bubble
	$(CC) $(CC_FLAGS) generateInput.c -o genInput 

gen_data: gen_bin
	./genInput
	./bubble 10 inputsort_1000000 gold_1000000

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput bubble inputsort_1000000 gold_1000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"


clean: 
	rm *.o bubble genInput gold_1000000
