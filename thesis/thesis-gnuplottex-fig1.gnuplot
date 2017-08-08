set terminal pdf color
set output 'thesis-gnuplottex-fig1.pdf'
unset title
set logscale x 2
set logscale y 2
set key below
#set format y "2^{%L}"
set format y "%8.2fs"
set grid
#
plot "benchmark_results/200_actors/ecs_no_opt_numerous_gcc_components_200_time.csv" using 1:2 with linespoints title "NOX ECS", "benchmark_results/200_actors/nox_numerous_gcc_components_200_time.csv" using 1:2 with linespoints title "NOX Actor"

unset logscale x
unset logscale y

