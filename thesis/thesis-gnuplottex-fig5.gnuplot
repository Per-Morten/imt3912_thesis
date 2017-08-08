set terminal pdf color
set output 'thesis-gnuplottex-fig5.pdf'
unset title
set logscale x 2

set key below
set format y "%8.2f"
set grid

plot\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$4) with linespoints title "Atomic sequentially consistent",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$12) with linespoints title "Thread pool using lock free stack",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$14) with linespoints title "Entity manager using locked queue",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$18) with linespoints title "Event using linear allocator",\
"benchmark_results/75_cmps/comparison.csv" using 1:($2/$20) with linespoints title "Lock-free stack using linear allocator"

unset logscale x
unset logscale y

