# Qualquer mudança deve ser propagada no conf

CC = gcc -g
CC_FLAGS = -fopenmp

destDir = /tmp/binary_search/

all: gen_bin gen_data mv_bin

gen_bin: binary_search.c generateInput.c
	$(CC) $(CC_FLAGS) binary_search.c -o binary_search
	$(CC) $(CC_FLAGS) generateInput.c -o genInput 

gen_data: gen_bin

	# Gera um vetor de 2000000 numeros aleatorios de 1 até 2000000, onde os primeiros 1000000 são ordenados

	./genInput 2000000 1000000

	./binary_search 1000000 85 input_2000000 gold_2000000

mv_bin: gen_data
	mkdir -p $(destDir)
	mv genInput binary_search input_2000000 gold_2000000 $(destDir)
	@echo "All Done, executables should be in the $(destDir)"

clean: 
	rm *.o binary_search genInput gold_2000000
