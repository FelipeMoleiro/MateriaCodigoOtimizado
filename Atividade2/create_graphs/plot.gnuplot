set autoscale
set terminal png size 1024,768
set output 'counting_K1bi.png'
set title "Counting Sort"
set style line 1 linecolor rgb '#ff3300'
plot "countingK1bi.txt" with linespoints
