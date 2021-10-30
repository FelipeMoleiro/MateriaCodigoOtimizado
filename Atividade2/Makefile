source_name=analysis.c
binary_name=analysis

all: compile run gprof createDot vis

compile:
	gcc $(source_name) -pg -o $(binary_name)

run:
	./$(binary_name)

gprof:
	gprof $(binary_name) gmon.out > saida_gprof.txt
	
createDot:
	gprof2dot saida_gprof.txt > saida_gprof.dot
	
vis:
	dot -Tpng -o saida_grafo.png saida_gprof.dot

clean:
	rm gmon.out $(binary_name)
