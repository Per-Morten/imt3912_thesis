set terminal pdf color
set output 'thesis-gnuplottex-fig3.pdf'
unset title
set logscale x 2
set logscale y 2

set key below
#set format y "2^{%L}"
set format y "%8.2fs"
set grid

plot\
"benchmark_results/75_cmps/75_cmps_final_atomic_use_seq_cst_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Atomic sequentially consistent",\
"benchmark_results/75_cmps/75_cmps_final_ecs_component_unique_ptr_virtual_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Component through unique pointer and virtual",\
"benchmark_results/75_cmps/75_cmps_final_ecs_component_virtual_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Component regular virtual",\
"benchmark_results/75_cmps/75_cmps_final_ecs_layered_execution_update_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "No layered execution update",\
"benchmark_results/75_cmps/75_cmps_final_entitymanager_pool_use_lock_free_stack_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Thread pool using lock free stack",\
"benchmark_results/75_cmps/75_cmps_final_entitymanager_use_locked_queue_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Entity manager using locked queue",\
"benchmark_results/75_cmps/75_cmps_final_event_use_heap_allocator_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Event using heap allocator",\
"benchmark_results/75_cmps/75_cmps_final_event_use_linear_allocator_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Event using linear allocator",\
"benchmark_results/75_cmps/75_cmps_final_lockfreestack_use_linear_allocator_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Lock-free stack using linear allocator",\
"benchmark_results/75_cmps/75_cmps_final_no_optimization_toggles_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "NOX ECS",\
"benchmark_results/75_cmps/75_cmps_final_use_string_type_id_numerous_gcc_75_actors_time.csv" using 1:2 with linespoints title "Identifier using string id",

unset logscale x
unset logscale y

