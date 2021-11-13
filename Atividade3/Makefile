all:
	gcc program.c -march=ivybridge -o program
run:
	perf stat ./program 50000000
O1:
	gcc program.c -march=ivybridge -O1 -o program
O2:
	gcc program.c -march=ivybridge -O2 -o program
O3:
	gcc program.c -march=ivybridge -O3 -o program
	
