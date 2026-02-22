
# Data Structures Project: Emergency Traveling Plan
## Project Overview

This project simulates an emergency traveling plan using fundamental data structures: Linked List, Queue, and Graph (Adjacency List). The goal is to find the shortest travel time (in days) between cities, considering normal and aerial routes.

## Data Structures Used

### Linked List
Each city and its connections are represented as nodes in a linked list. Each node contains:
- `data`: City number (integer)
- `aerial_root`: Boolean flag for aerial route
- `next`: Pointer to the next node

### Queue
Used for breadth-first traversal of the graph:
- `enqueue(value)`: Adds a city to the queue
- `dequeue()`: Removes the front city
- `Front()`: Returns the city at the front
- `isEmpty()`: Checks if the queue is empty

### Graph (Adjacency List)
The graph represents cities and their connections:
- `add_edge(city1, city2)`: Adds a directed edge
- `add_adjacent_edges()`: Adds edges between consecutive cities
- `add_aerial_root(city1, city2)`: Adds an aerial route
- `print_aerial_roots()`: Prints aerial connections
- `print_graph()`: Prints all connections

## Algorithm: Breadth-First Traversal

The algorithm finds the shortest path (in days) from the first city to the last city:
- Normal route: 4 hours between adjacent cities
- Aerial route: 24 hours between cities
- Maximum 6 cities can be traveled in one day
- Uses a queue and visited array to traverse the graph
- Calculates total hours and converts to days (rounded)

## Usage

1. Run the program.
2. Enter the number of test cases.
3. For each test case:
	- Enter the total number of cities.
	- Enter the number of aerial roots.
	- For each aerial root, enter the source and destination cities.
4. The program outputs the shortest travel time in days for each test case.

## Example

```
enter the no of test cases: 1
Enter the total number of cities: 5
Enter the number of aerial root : 1
Enter the aerial root1:
from city: 2
to city: 5
-----------------------------------------------------------------------
shortest distance is: 1 days
-----------------------------------------------------------------------
```

## Main Function

Handles user input, constructs the graph, adds edges and aerial roots, and calculates the shortest travel time in days.

## License

This project is for educational purposes.

The breadth-first traversal algorithm finds the shortest path in terms of days between cities. Key points:

- Normal travel time between cities is 4 hours.
- Aerial travel time is 24 hours.
- The algorithm uses a queue to traverse the graph and calculates the shortest distance in days.

### Main Function

The main function handles user input for multiple test cases, constructs the graph, adds edges and aerial roots, and calculates the shortest travel time in days.
