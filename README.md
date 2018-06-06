# FTF_da_lindeza

-> avg time for execution:
Precisamos dessa informação para podermos dar um timeout para o carol-fi. No momento estou usando time do linux, mas no futuro teremos que fazer uma média, já que a execução depende do tamanho da imagem.


** FIX ME

How to execute:

** binary_search:
	./binary_search 10 85 inputsort_50000 output_50000
	
	./binary_search <tamanho do vetor> <numero procurado> <inputsort_numero utilizado no arquivo generateInput> <arquivo de saida>

** merge_sort:
	./mergesort 5000000 4 inputsort_134217728 gold_5000000

	./mergesort <tamanho do vetor> <numero de threads> <inputsort_numero utilizado no arquivo generateInput> <arquivo de saida>

** newton_raphson:
	./newton 'file.txt' gold

	./newton <arquivo de entrada> <arquivo de saida>


