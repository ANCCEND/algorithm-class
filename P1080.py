import sys


def solve():
    input_data = sys.stdin.read().split()

    n = int(input_data[0])
    king_a = int(input_data[1])
    king_b = int(input_data[2])

    index = 3
    minister = []

    for _ in range(n):
        a = int(input_data[index])
        b = int(input_data[index + 1])
        minister.append((a, b))
        index += 2

    minister.sort(key=lambda x: x[0] * x[1])

    max_reward = 0
    current_sum = king_a

    for a, b in minister:
        reward = current_sum // b
        if reward > max_reward:
            max_reward = reward
        current_sum *= a
    print(max_reward)


if __name__ == "__main__":
    solve()
