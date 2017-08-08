set terminal pdf color
set output 'thesis-gnuplottex-fig11.pdf'
unset title
set logscale x 2
#set logscale y 2

set key below
#set format y "2^{%L}"
set format y "%8.2f"
set grid
#

plot\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$4) with linespoints title "Atomic sequentially consistent",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$6) with linespoints title "Component regular virtual",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$8) with linespoints title "No layered execution receive events",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$10) with linespoints title "No layered execution update",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$12) with linespoints title "Thread pool using lock free stack",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$14) with linespoints title "Entity manager using locked queue",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$16) with linespoints title "Event using heap allocator",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$18) with linespoints title "Event using linear allocator",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$20) with linespoints title "Lock-free stack using linear allocator",\
"benchmark_results/fast_spawn/internal/comparison_time.csv" using 1:($2/$22) with linespoints title "Identifier using string id"



#plot\
#"benchmark_results/fast_spawn/internal/ecs_atomic_use_seq_cst_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "atomic use seq cst",\
#"benchmark_results/fast_spawn/internal/ecs_ecs_component_virtual_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "component virtual",\
#"benchmark_results/fast_spawn/internal/ecs_ecs_layered_execution_entity_events_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "layered execution entity events",\
#"benchmark_results/fast_spawn/internal/ecs_ecs_layered_execution_update_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "no layered execution update",\
#"benchmark_results/fast_spawn/internal/ecs_entitymanager_pool_use_lock_free_stack_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "entitymanager pool use lock free stack",\
#"benchmark_results/fast_spawn/internal/ecs_entitymanager_use_locked_queue_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "entitymanager use locked queue",\
#"benchmark_results/fast_spawn/internal/ecs_event_use_heap_allocator_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "event use heap allocator",\
#"benchmark_results/fast_spawn/internal/ecs_event_use_linear_allocator_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "event use linear allocator",\
#"benchmark_results/fast_spawn/internal/ecs_lockfreestack_use_linear_allocator_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "lockfreestack use linear allocator",\
#"benchmark_results/fast_spawn/internal/ecs_no_optimization_toggles_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "ecs",\
#"benchmark_results/fast_spawn/internal/ecs_use_string_type_id_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "use string type id"

# Removed because it leaked memory!
#"benchmark_results/fast_spawn/internal/ecs_ecs_component_unique_ptr_virtual_fast_spawning_gcc_deletes_10_time.csv" using 1:2 with linespoints title "component unique ptr virtual",\

unset logscale x
unset logscale y

