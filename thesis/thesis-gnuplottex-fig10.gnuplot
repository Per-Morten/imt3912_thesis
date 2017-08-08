set terminal pdf color
set output 'thesis-gnuplottex-fig10.pdf'
unset title
set logscale x 2
set logscale y 2
set key below

set format y '%.0s%cB'
#set format y "2^{%L}B"
#set format y "%8.2fs"
set grid

plot\
"benchmark_results/fast_spawn/ecs_no_optimization_toggles_fast_spawning_gcc_deletes_10_memory.csv" using 1:2 with linespoints title "NOX ECS",\
"benchmark_results/fast_spawn/nox_fast_spawning_gcc_deletes_10_sprite_actors_memory.csv" using 1:2 with linespoints title "NOX Actor"

unset logscale x
unset logscale y

