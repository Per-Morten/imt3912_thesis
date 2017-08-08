set terminal pdf color
set output 'thesis-gnuplottex-fig7.pdf'
unset title
set logscale x 2

set key below
set format y "%8.2f"
set grid

plot\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$10) with linespoints title "No layered execution update"

unset logscale x
unset logscale y

