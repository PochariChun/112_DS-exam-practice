def generate_sequences(n, clues, index=0, sequence=[]):
    """ 產生所有可能的黑色方塊排列 """
    if index == len(clues):
        if len(sequence) <= n:
            sequence += [0] * (n - len(sequence))
            return [sequence]
        else:
            return []

    all_sequences = []
    for start in range(len(sequence), n):
        new_sequence = sequence + [0] * (start - len(sequence)) + [1] * clues[index]
        if index < len(clues) - 1:
            new_sequence.append(0)  # 在每组黑色方块之间添加至少一个白色空格
        all_sequences.extend(generate_sequences(n, clues, index + 1, new_sequence))
    
    return all_sequences

def find_common_blocks(all_sequences):
    """ 找到所有排列中共同的黑色方塊找到所有排列中共同的黑色方塊 """
    return [1 if all(seq[i] for seq in all_sequences) else 0 for i in range(len(all_sequences[0]))]

def main():
    n = int(input().strip())  # 讀取棋盤大小
    m = int(input().strip())  # 讀取提示數量
    clues = list(map(int, input().strip().split()))  # 讀取提示數字

    all_sequences = generate_sequences(n, clues)
    common_blocks = find_common_blocks(all_sequences)

    print(' '.join(map(str, common_blocks)))  # 輸出結果，黑色方塊為 1，白色為 0

if __name__ == "__main__":
    main()
