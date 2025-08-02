# PHILO Project Roadmap

---

## 1. Arguments & Input
- `number_of_philosophers`: Number of philosophers (threads) in the simulation.
- `time_to_die`: Max time a philosopher can go without eating before dying.
- `time_to_eat`: Time a philosopher spends eating.
- `time_to_sleep`: Time a philosopher spends sleeping.
- `[meals]` (optional): Number of times each philosopher must eat before simulation ends.

## 2. Initialization
- Allocate and initialize data structures for philosophers and forks.
- Initialize mutexes (`pthread_mutex_init`) for each fork.

## 3. Thread Creation
- Each philosopher is represented by a thread (`pthread_create`).
- The main process creates all philosopher threads and a monitor thread.

## 4. Philosopher Routine
- Each thread runs a loop:
  1. **Take forks** (lock two mutexes in a consistent order to prevent deadlock).
  2. **Eat** (update last meal time, increment meal counter, sleep for `time_to_eat`).
  3. **Release forks** (unlock mutexes).
  4. **Sleep** (pause for `time_to_sleep`).
  5. **Think** (no forks needed).
- If a meal limit is set, the thread exits after reaching it.

## 5. Forks & Mutexes
- Forks are mutexes (`pthread_mutex_t`).
- Only one philosopher can hold a fork at a time (`pthread_mutex_lock`/`unlock`).
- Consistent locking order (by pointer address) prevents deadlock.

## 6. Time Management
- Use `gettimeofday` for precise timing (ms accuracy).
- Use `ft_usleep` for accurate sleep intervals.

## 7. Monitor Thread
- Separate thread checks for:
  - Philosopher death (if time since last meal > `time_to_die`).
  - All philosophers have eaten enough (if meal limit is set).
- Sets flags to stop simulation when conditions are met.

## 8. Thread & Process Concepts
- A thread is a unit of execution within a process; multiple threads run in parallel.
- All threads share memory space but have their own stack and registers.
- Data races can occur if threads access shared data without mutexes.

## 9. Cleanup
- Destroy mutexes (`pthread_mutex_destroy`) when done.
- Use `pthread_join` to wait for threads to finish.
- Use `pthread_detach` if threads should clean up themselves.

## 10. Edge Cases & Rules
- 1 philosopher: can never eat, dies after `time_to_die`.
- Meal limit: simulation stops when all have eaten enough.
- Timing: actions must respect minimum time constraints (≥ 60 ms).

## 11. Summary
- The project simulates the dining philosophers problem using threads and mutexes.
- Correct fork locking order and careful synchronization are key to avoiding deadlocks and ensuring accurate simulation.

---