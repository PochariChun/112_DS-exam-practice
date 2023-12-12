def evaluate_postfix(expression):
    """
    Evaluate a postfix expression and return the result.

    Args:
    expression (str): A string of a postfix expression where operands and operators are separated by spaces.

    Returns:
    int: The result of the postfix expression.
    """
    # Split the expression into tokens
    tokens = expression.split()

    # Initialize an empty stack
    stack = []

    # Iterate over each token in the postfix expression
    for token in tokens:
        if token.isdigit():
            # If the token is an operand, push it to the stack
            stack.append(int(token))
        else:
            # If the token is an operator, pop two operands from the stack and apply the operator
            b = stack.pop()
            a = stack.pop()

            if token == '+':
                stack.append(a + b)
            elif token == '-':
                stack.append(a - b)
            elif token == '*':
                stack.append(a * b)
            elif token == '/':
                stack.append(a // b)  # Using integer division
            elif token == '%':
                stack.append(a % b)
            else:
                raise ValueError("Invalid operator")

    # The result is the last item in the stack
    return stack.pop()

# Example usage
expression = "1 2 3 4 5 * + % -"
print(evaluate_postfix(expression))
