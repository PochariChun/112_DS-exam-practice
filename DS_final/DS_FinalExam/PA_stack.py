def matrix_multiple(matrix, expression):
    if len(expression) == 1:
        return 0  # If the expression contains only one character, return 0 as per your original code.
    else:
        stack = []  # Initialize a stack to process the expression.
        total = 0  # Initialize a variable to keep track of the total result.

        for char in expression:
            if char.isalpha():  # If the character is an alphabet (e.g., A, B, C).
                size = matrix[char]  # Get the size of the matrix from the dictionary.
                stack.append(size)  # Push the matrix size onto the stack.
            elif char == '(':  # If it's an open parenthesis, push it onto the stack.
                stack.append(char)
            else:
                chain = []  # Create a chain to store matrix sizes for multiplication.
                while stack[-1] != '(':  # Pop elements until an open parenthesis is encountered.
                    chain.append(stack.pop())
                stack.pop()  # Remove the open parenthesis from the stack.

                while len(chain) > 1:
                    a = chain.pop()
                    b = chain.pop()
                    if a[1] != b[0]:
                        return 'error'  # Check for matrix multiplication compatibility.
                    else:
                        total += a[0] * a[1] * b[1]  # Multiply matrices and add to the total.
                        chain.append((a[0], b[1]))
                stack.append(chain[0])

        stack.reverse()  # Reverse the stack to process any remaining multiplications.
        while len(stack) > 1:
            a = stack.pop()
            b = stack.pop()
            if a[1] != b[0]:
                return 'error'  # Check for matrix multiplication compatibility.
            else:
                total += a[0] * a[1] * b[1]  # Multiply matrices and add to the total.
                stack.append((a[0], b[1]))

    return total  # Return the final total result.

def main():
    num = int(input())
    matrix = {}

    # Input matrix dimensions
    for _ in range(num):
        name, row, col = input().split()
        row = int(row)
        col = int(col)
        matrix[name] = (row, col)  # Store matrix sizes in a dictionary.

    runs = int(input())

    # Perform matrix multiplications
    while runs > 0:
        expression = input()
        result = matrix_multiple(matrix, expression)
        print(result if result != 'error' else 'error')
        runs -= 1

if __name__ == "__main__":
    main()
