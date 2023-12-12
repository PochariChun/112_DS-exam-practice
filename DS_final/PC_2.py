from collections import deque

def neighbors(city):
    # Generate neighboring cities
    for i in range(2):
        new_city = list(city)
        new_city[i], new_city[i + 1] = new_city[i + 1], new_city[i]
        yield tuple(new_city)

def bfs(start):
    # Use BFS to find the shortest path from start city to (1, 2, 3)
    queue = deque([(start, 0)])
    visited = {start}

    while queue:
        current_city, distance = queue.popleft()
        if current_city == (1, 2, 3):
            return distance

        for next_city in neighbors(current_city):
            if next_city not in visited:
                visited.add(next_city)
                queue.append((next_city, distance + 1))

    return -1  # If the castle cannot be reached

def main():
    M = int(input(""))
    for _ in range(M):
        city_code = tuple(map(int, input("").split()))
        print(bfs(city_code))

if __name__ == "__main__":
    main()
