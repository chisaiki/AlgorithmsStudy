# Recursion Practice - Step by Step Approach
# Start with these fundamental patterns

# ========================================
# PATTERN 1: COUNTING DOWN (Base Case: 0)
# ========================================

def countdown(n):
    """
    Simple countdown - helps visualize the call stack
    Base case: n <= 0
    Recursive case: print n, then countdown(n-1)
    """
    if n <= 0:  # Base case
        print("Blast off!")
        return
    
    print(f"Counting: {n}")
    countdown(n - 1)  # Recursive case - getting closer to base case

# Try: countdown(5)

# ========================================
# PATTERN 2: ACCUMULATING RESULTS
# ========================================

def factorial(n):
    """
    Classic factorial: n! = n * (n-1) * ... * 1
    Base case: n <= 1 returns 1
    Recursive case: n * factorial(n-1)
    """
    if n <= 1:  # Base case
        return 1
    
    return n * factorial(n - 1)  # Recursive case

# Try: factorial(5) = 5 * 4 * 3 * 2 * 1 = 120

# ========================================
# PATTERN 3: DIVIDE AND CONQUER
# ========================================

def sum_list(arr):
    """
    Sum all elements in a list recursively
    Base case: empty list returns 0
    Recursive case: first element + sum of rest
    """
    if not arr:  # Base case: empty list
        return 0
    
    return arr[0] + sum_list(arr[1:])  # First + sum of rest

# Try: sum_list([1, 2, 3, 4]) = 1 + sum_list([2, 3, 4])

# ========================================
# PATTERN 4: TREE-LIKE PROBLEMS
# ========================================

def fibonacci(n):
    """
    Fibonacci sequence: F(n) = F(n-1) + F(n-2)
    Base cases: F(0) = 0, F(1) = 1
    Shows how recursion can branch (tree-like)
    """
    if n <= 1:  # Base cases
        return n
    
    return fibonacci(n - 1) + fibonacci(n - 2)  # Two recursive calls

# Try: fibonacci(6) - notice this creates a tree of calls

# ========================================
# DEBUGGING HELPER: VISUALIZE CALL STACK
# ========================================

def factorial_debug(n, depth=0):
    """
    Factorial with debug info to see call stack
    """
    indent = "  " * depth
    print(f"{indent}→ factorial_debug({n})")
    
    if n <= 1:
        print(f"{indent}← Base case: returning 1")
        return 1
    
    result = n * factorial_debug(n - 1, depth + 1)
    print(f"{indent}← Returning {n} * {result // n} = {result}")
    return result

# Try: factorial_debug(4) to see the call stack in action!

if __name__ == "__main__":
    print("=== RECURSION PRACTICE ===")
    print("\n1. Countdown:")
    countdown(3)
    
    print("\n2. Factorial:")
    print(f"5! = {factorial(5)}")
    
    print("\n3. Sum List:")
    print(f"Sum of [1,2,3,4] = {sum_list([1,2,3,4])}")
    
    print("\n4. Fibonacci:")
    print(f"6th Fibonacci number = {fibonacci(6)}")
    
    print("\n5. Debug Factorial:")
    factorial_debug(4)