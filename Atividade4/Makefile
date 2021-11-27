all:
	gcc program.c -g -march=native -o program
	gcc program.c -g -march=native -O3 -o programO3
	/opt/intel/oneapi/compiler/latest/linux/bin/intel64/icc program.c -g -march=native -O3 -o programiccO3
	/opt/intel/oneapi/compiler/latest/linux/bin/intel64/icc program.c -g -march=native -O0 -o programiccO0
run:
	perf stat ./program 50000000
O1:
	gcc program.c -march=ivybridge -O1 -o program
O2:
	gcc program.c -march=ivybridge -O2 -o program
O3:
	gcc program.c -march=ivybridge -g -O3 -o program
Ofast:
	gcc program.c -march=ivybridge -Ofast -o program
Os:
	gcc program.c -march=ivybridge -Os -o program
testea:
	gcc program.c -march=ivybridge \
	  -fauto-inc-dec  \
          -fbranch-count-reg \
          -fcombine-stack-adjustments \
          -fcompare-elim \
          -fcprop-registers \
          -fdce \
          -fdefer-pop \
          -fdelayed-branch \
          -fdse \
          -fforward-propagate \
          -fguess-branch-probability \
          -fif-conversion2 \
          -fif-conversion \
          -finline-functions-called-once \
          -fipa-pure-const \
          -fipa-profile \
          -fipa-reference \
          -fmerge-constants \
          -fmove-loop-invariants \
          -freorder-blocks \
          -fshrink-wrap \
          -fsplit-wide-types \
          -fssa-backprop \
          -fssa-phiopt \
          -ftree-bit-ccp \
          -ftree-ccp \
          -ftree-ch \
          -ftree-coalesce-vars \
          -ftree-copy-prop \
          -ftree-dce \
          -ftree-dominator-opts \
          -ftree-dse \
          -ftree-forwprop \
          -ftree-fre \
          -ftree-phiprop \
          -ftree-sink \
          -ftree-slsr \
          -ftree-sra \
          -ftree-pta \
          -ftree-ter \
          -funit-at-a-time \
          -fomit-frame-pointer \
          -fthread-jumps \
          -falign-functions  -falign-jumps \
          -falign-loops  -falign-labels \
          -fcaller-saves \
          -fcrossjumping \
          -fcse-follow-jumps  -fcse-skip-blocks \
          -fdelete-null-pointer-checks \
          -fexpensive-optimizations \
          -fgcse  -fgcse-lm  \
          -finline-small-functions \
          -findirect-inlining \
          -fipa-sra \
          -foptimize-sibling-calls \
          -fpeephole2 \
          -fregmove \
          -freorder-blocks  -freorder-functions \
          -frerun-cse-after-loop  \
          -fsched-interblock  -fsched-spec \
          -fschedule-insns  -fschedule-insns2 \
          -fstrict-aliasing -fstrict-overflow \
          -ftree-switch-conversion \
          -ftree-pre \
          -ftree-vrp \
          -finline-functions -funswitch-loops -fpredictive-commoning -fgcse-after-reload -ftree-vectorize -fipa-cp-clone \
          -o program
