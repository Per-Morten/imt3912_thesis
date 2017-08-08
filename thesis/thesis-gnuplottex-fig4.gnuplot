set terminal pdf color
set output 'thesis-gnuplottex-fig4.pdf'
unset title
set logscale x 2

set key below
set format y "%8.2f"
set grid

plot\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$6) with linespoints title "Component through unique pointer and virtual",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$8) with linespoints title "Component regular virtual"

unset logscale x
unset logscale y

