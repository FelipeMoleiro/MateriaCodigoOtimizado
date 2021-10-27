source_name=analysis.c
binary_name=analysis

all: compile run gprof

compile:
	gcc $(source_name) -pg -o $(binary_name)

run:
	./$(binary_name)

gprof:
	gprof $(binary_name)

clean:
	rm gmon.out $(binary_name)