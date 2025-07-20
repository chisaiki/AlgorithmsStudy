#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Recursion Practice - Step by Step Approach
// Start with these fundamental patterns

// ========================================
// PATTERN 1: COUNTING DOWN (Base Case: 0)
// ========================================

void countdown(int n) {
    /*
    Simple countdown - helps visualize the call stack
    Base case: n <= 0
    Recursive case: print n, then countdown(n-1)
    */
    if (n <= 0) {  // Base case
        cout << "Blast off!" << endl;
        return;
    }
    
    cout << "Counting: " << n << endl;
    countdown(n - 1);  // Recursive case - getting closer to base case
}

// Try: countdown(5)

// ========================================
// PATTERN 2: ACCUMULATING RESULTS
// ========================================

int factorial(int n) {
    /*
    Classic factorial: n! = n * (n-1) * ... * 1
    Base case: n <= 1 returns 1
    Recursive case: n * factorial(n-1)
    */
    if (n <= 1) {  // Base case
        return 1;
    }
    
    return n * factorial(n - 1);  // Recursive case
}

// Try: factorial(5) = 5 * 4 * 3 * 2 * 1 = 120

// ========================================
// PATTERN 3: DIVIDE AND CONQUER
// ========================================

int sumArray(vector<int>& arr, int index = 0) {
    /*
    Sum all elements in an array recursively
    Base case: index >= arr.size() returns 0
    Recursive case: current element + sum of rest
    */
    if (index >= arr.size()) {  // Base case: reached end of array
        return 0;
    }
    
    return arr[index] + sumArray(arr, index + 1);  // Current + sum of rest
}

// Alternative approach using array slicing concept
int sumVector(const vector<int>& arr) {
    if (arr.empty()) {  // Base case: empty vector
        return 0;
    }
    
    vector<int> rest(arr.begin() + 1, arr.end());  // Create subvector
    return arr[0] + sumVector(rest);  // First + sum of rest
}

// ========================================
// PATTERN 4: TREE-LIKE PROBLEMS
// ========================================

int fibonacci(int n) {
    /*
    Fibonacci sequence: F(n) = F(n-1) + F(n-2)
    Base cases: F(0) = 0, F(1) = 1
    Shows how recursion can branch (tree-like)
    */
    if (n <= 1) {  // Base cases
        return n;
    }
    
    return fibonacci(n - 1) + fibonacci(n - 2);  // Two recursive calls
}

// Try: fibonacci(6) - notice this creates a tree of calls

// ========================================
// PATTERN 5: STRING MANIPULATION
// ========================================

string reverseString(const string& str) {
    /*
    Reverse a string recursively
    Base case: empty string or single character
    Recursive case: last char + reverse of rest
    */
    if (str.length() <= 1) {  // Base case
        return str;
    }
    
    // Last character + reverse of everything except last
    return str.back() + reverseString(str.substr(0, str.length() - 1));
}

// ========================================
// PATTERN 6: MATHEMATICAL OPERATIONS
// ========================================

int power(int base, int exponent) {
    /*
    Calculate base^exponent recursively
    Base case: exponent = 0 returns 1
    Recursive case: base * power(base, exponent-1)
    */
    if (exponent == 0) {  // Base case: anything^0 = 1
        return 1;
    }
    
    return base * power(base, exponent - 1);
}

// ========================================
// DEBUGGING HELPER: VISUALIZE CALL STACK
// ========================================

int factorialDebug(int n, int depth = 0) {
    /*
    Factorial with debug info to see call stack
    */
    string indent(depth * 2, ' ');
    cout << indent << "→ factorialDebug(" << n << ")" << endl;
    
    if (n <= 1) {
        cout << indent << "← Base case: returning 1" << endl;
        return 1;
    }
    
    int result = n * factorialDebug(n - 1, depth + 1);
    cout << indent << "← Returning " << n << " * " << (result / n) 
         << " = " << result << endl;
    return result;
}

// ========================================
// MAIN FUNCTION - TEST ALL EXAMPLES
// ========================================

int main() {
    cout << "=== RECURSION PRACTICE IN C++ ===" << endl;
    
    cout << "\n1. Countdown:" << endl;
    countdown(3);
    
    cout << "\n2. Factorial:" << endl;
    cout << "5! = " << factorial(5) << endl;
    
    cout << "\n3. Sum Array:" << endl;
    vector<int> numbers = {1, 2, 3, 4};
    cout << "Sum of [1,2,3,4] = " << sumArray(numbers) << endl;
    
    cout << "\n4. Sum Vector (alternative):" << endl;
    cout << "Sum of [1,2,3,4] = " << sumVector(numbers) << endl;
    
    cout << "\n5. Fibonacci:" << endl;
    cout << "6th Fibonacci number = " << fibonacci(6) << endl;
    
    cout << "\n6. Reverse String:" << endl;
    string text = "hello";
    cout << "'" << text << "' reversed = '" << reverseString(text) << "'" << endl;
    
    cout << "\n7. Power:" << endl;
    cout << "2^5 = " << power(2, 5) << endl;
    
    cout << "\n8. Debug Factorial (shows call stack):" << endl;
    factorialDebug(4);
    
    return 0;
}