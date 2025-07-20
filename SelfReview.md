# Self Review Topics

## Topics

### **Foundation Concepts**
1. Algorithm Analysis
    - **Why important**: Learn to predict performance, compare algorithms, and understand trade-offs between time and space complexity
    - **Foundation for**: Making informed decisions about which data structure or algorithm to use in different scenarios

2. Pointers and Memory Management
    - **Why important**: Essential for understanding linked structures, dynamic allocation, and how data structures connect elements
    - **Foundation for**: Implementing linked lists, trees, graphs, and understanding memory leaks and efficient allocation

3. Memory Access Patterns and Cache Efficiency 
    - **Why important**: Explains why arrays can be faster than linked lists, and why certain tree traversals are more efficient
    - **Foundation for**: Understanding real-world performance differences and optimizing data structure usage

4. Classes 
    - **Why important**: Needed to understand how data structures encapsulate data and methods together
    - **Foundation for**: Object-oriented design, data hiding, and creating reusable data structure implementations

5. Templates 
    - **Why important**: Allow you to create generic data structures that work with any data type
    - **Foundation for**: Understanding STL containers, writing reusable code, and type-safe generic programming

6. Vectors and Dynamic Arrays
    - **Why important**: Most fundamental dynamic container, basis for understanding resizing strategies and amortized analysis
    - **Foundation for**: All other container types, understanding when contiguous memory is beneficial

7. Linear Search
    - **Why important**: Simple sequential search, foundation for understanding search complexity
    - **Foundation for**: Understanding O(n) search operations and when they're necessary

8. List/Stack/Queue 
    - **Why important**: Core linear data structures that form building blocks for more complex structures
    - **Foundation for**: Understanding LIFO/FIFO principles, recursion (stacks), and breadth-first search (queues)

8. Iterators 
    - **Why important**: Provide uniform way to traverse different data structures without exposing internal implementation
    - **Foundation for**: Generic algorithms, separation of algorithms from data structures, and modern C++ practices

9. Recursion
    - **Why important**: Essential for trees, graphs, and divide-and-conquer algorithms
    - **Foundation for**: Tree traversals, graph algorithms, and recursive problem-solving techniques

10. Stack vs Heap Memory
    - **Why important**: Understanding where different data is stored and performance implications
    - **Foundation for**: Memory management decisions, understanding when to use dynamic allocation

11. Logarithms and Mathematical Foundations
    - **Why important**: Essential for understanding tree heights, complexity analysis, and algorithm performance
    - **Foundation for**: Analyzing balanced trees, hash functions, and algorithm complexity

12. Exception Handling and Error Management
    - **Why important**: How to handle errors in data structure operations safely
    - **Foundation for**: Robust data structure implementations and error recovery strategies

### **Tree Structures**
1. Binary Search (Fundamental search technique)
2. Binary Search Tree (BST) Search (Search operations in tree structures)
3. Trees (AVL)
4. Trees (Splay Trees, B-Trees)
5. Heaps

### **Hash-Based Structures**
1. Sets/Maps
2. Hashing
3. Hash Table Search (O(1) average search operations)

### **Sorting Algorithms**
8. Sorting

### **Graph Theory**
1. Union/Find
2. Depth-First Search (DFS) (Graph/tree traversal and searching)
3. Breadth-First Search (BFS) (Level-by-level searching and shortest paths)
4. Graph Algorithms

### **Algorithm Design Paradigms**
11. Divide and Conquer
12. Greedy Algorithms
13. Dynamic Programming

### **Advanced Topics**
14. Randomized Algorithms

## **Practice Recommendations**

### **Foundation Concepts (5-10 problems each)**
- **Arrays/Vectors**: 10-15 problems (most fundamental)
- **Pointers (Two Pointers)**: 5-8 problems
- **Recursion**: 8-10 problems
- **Binary Search**: 8-10 problems

### **Linear Data Structures (5-8 problems each)**
- **Lists/Linked Lists**: 8-10 problems
- **Stacks**: 5-7 problems
- **Queues**: 5-7 problems

### **Tree Structures (8-12 problems each)**
- **Binary Trees**: 10-12 problems
- **Binary Search Trees**: 8-10 problems
- **Heaps**: 6-8 problems
- **Advanced Trees (AVL/Splay)**: 3-5 problems

### **Hash-Based (6-10 problems)**
- **Hash Tables/Maps**: 8-10 problems
- **Sets**: 4-6 problems

### **Sorting (5-8 problems)**
- **Basic Sorting**: 3-5 problems
- **Sorting Applications**: 5-8 problems

### **Graph Theory (10-15 problems)**
- **Graph Traversal (DFS/BFS)**: 8-10 problems
- **Union/Find**: 5-7 problems
- **Advanced Graph**: 5-8 problems

### **Algorithm Paradigms (8-12 problems each)**
- **Divide and Conquer**: 6-8 problems
- **Greedy**: 8-10 problems
- **Dynamic Programming**: 12-15 problems (most challenging)

### **Study Strategy:**
1. Start with Easy problems for each topic
2. Progress to Medium once comfortable
3. Mix in Hard problems for advanced topics
4. Focus on understanding patterns rather than memorizing solutions

**Total estimate**: ~150-200 problems for comprehensive coverage

### **Time Limits by Difficulty**

#### **Easy Problems**
- **Beginner**: 15-20 minutes
- **Intermediate**: 10-15 minutes
- **Advanced**: 5-10 minutes

#### **Medium Problems**
- **Beginner**: 25-35 minutes
- **Intermediate**: 20-25 minutes
- **Advanced**: 15-20 minutes

#### **Hard Problems**
- **Beginner**: 35-45 minutes
- **Intermediate**: 30-35 minutes
- **Advanced**: 25-30 minutes

### **Time Management Strategy**

#### **First Attempt**
- Spend the time limit trying to solve it yourself
- If you can't solve it, look at hints or solution approach
- **Don't** look at the full solution immediately

#### **Learning Phase**
- After seeing hints, give yourself another 10-15 minutes
- If still stuck, study the solution and understand the approach
- Code it yourself without looking at the solution

#### **Practice Phase**
- Come back to the problem after 1-2 days
- Should be able to solve it in 60-70% of the original time limit
- If not, review the pattern again

### **Special Considerations**
- **First Time with a Topic**: Add 50% more time to learn the pattern
- **Interview Prep**: Stick strictly to time limits
- **Pattern Recognition**: Once you recognize the pattern, aim for 50% of the time limit

**Remember**: It's better to understand one problem deeply than to rush through many problems superficially!

# Resources

- [Hunter 2016 335](https://grezesf.github.io/Courses-Taught/Hunter-CSCI335.html)

## **Creating a Study Website**

### **Benefits of Creating a Study Website**

#### **For Learning**
- **Active learning**: Writing content forces deeper understanding
- **Organization**: Better structure than scattered markdown files
- **Searchable**: Easy to find specific topics quickly
- **Visual aids**: Can include diagrams, animations, and interactive examples
- **Progress tracking**: Can add checkboxes, progress bars, or completion status

#### **For Practice**
- **Interactive examples**: Embed code snippets with syntax highlighting
- **Live coding**: Could integrate online compilers or CodePen
- **Visual algorithms**: Animations showing how algorithms work step-by-step
- **Cross-references**: Easy linking between related topics

#### **For Portfolio**
- **Demonstrates knowledge**: Shows mastery of the material
- **Technical skills**: Web development experience for your resume
- **Study dedication**: Visible commitment to learning
- **Shareable**: Can help other students and showcase your work

### **Technology Recommendations**

#### **Simple Options**
- **GitHub Pages + Jekyll**: Free hosting, markdown-based
- **Notion**: Easy to organize, good for notes and databases
- **GitBook**: Designed for documentation, very clean

#### **More Advanced**
- **Next.js/React**: If you want to practice web development
- **Docusaurus**: Facebook's documentation platform
- **VuePress**: Vue-based static site generator

#### **Quick Start**
- **GitHub Pages**: Convert your markdown files directly
- **Obsidian Publish**: If you use Obsidian for notes

### **Content Structure Ideas**
- Interactive algorithm visualizations
- Code examples in multiple languages
- Complexity analysis tables
- LeetCode problem collections by topic
- Progress tracking system

**Recommendation**: Start with GitHub Pages + Jekyll to convert your existing markdown files, then enhance with interactive features as you learn more!