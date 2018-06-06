CC=gcc

all: graph hypergraph

graph: graph_generator.c
	$(CC) -o graph_generator graph_generator.c

hypergraph: hypergraph_generator.c
	$(CC) -o hypergraph_generator hypergraph_generator.c

clean:
	rm graph_generator hypergraph_generator
