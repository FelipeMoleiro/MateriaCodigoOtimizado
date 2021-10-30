set autoscale
set terminal png size 1024,768
set output 'analise4.png'
set title "Analise de algoritmos"
set xrange [1:100000]
plot "bubble.txt" with line
