CC=gcc
OUT=fw

destDir = /tmp/fw/

all: fw gen_data mv_bin

fw: fw.c
	$(CC) -o $(OUT) fw.c

gen_data: fw
	./fw tests/input_1k tests/gold_1k

mv_bin: gen_data
	mkdir -p $(destDir)
	cp tests/input_1k $(destDir)
	cp fw tests/gold_1k $(destDir)
	@echo "All Done, executables should be in the $(destDir)"

clean:
	rm $(OUT)
