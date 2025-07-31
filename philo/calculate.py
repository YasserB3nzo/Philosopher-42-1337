import sys
from collections import defaultdict

def count_meals(lines):
    meal_counts = defaultdict(int)
    for line in lines:
        if "is eating" in line:
            parts = line.split()
            philo_id = parts[parts.index("is") - 1]  # Gets the number before "is eating"
            meal_counts[philo_id] += 1
    return meal_counts

def main():
    if len(sys.argv) > 1:
        # Read from file
        with open(sys.argv[1], 'r') as f:
            lines = f.readlines()
    else:
        # Read from stdin (piped input)
        lines = sys.stdin.readlines()
    
    meal_counts = count_meals(lines)
    
    # Sort by philosopher number
    sorted_philos = sorted(meal_counts.items(), key=lambda x: int(x[0]))
    
    print("\nTimes each philosopher ate:")
    for philo, count in sorted_philos:
        print(f"Philosopher {philo}: {count} times")

if __name__ == "__main__":
    main()
