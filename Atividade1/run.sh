#!/bin/bash

mkdir results

for i in {1..10};
	do
		perf stat -e L1-dcache-loads,L1-dcache-load-misses,branch-instructions,branch-misses ./matrix 100 li &> "results/100li$i.out"
		perf stat -e L1-dcache-loads,L1-dcache-load-misses,branch-instructions,branch-misses ./matrix 1000 li &> "results/1000li$i.out"
		perf stat -e L1-dcache-loads,L1-dcache-load-misses,branch-instructions,branch-misses ./matrix 100 lu &> "results/100lu$i.out"
		perf stat -e L1-dcache-loads,L1-dcache-load-misses,branch-instructions,branch-misses ./matrix 1000 lu &> "results/1000lu$i.out"
	done
