set terminal pdf color
set output 'thesis-gnuplottex-fig6.pdf'
unset title
set logscale x 2

set key below
set format y "%8.3f"
set grid

plot\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$16) with linespoints title "Event using heap allocator",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$18) with linespoints title "Event using linear allocator",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$20) with linespoints title "Lock-free stack using linear allocator"

unset logscale x
unset logscale y

