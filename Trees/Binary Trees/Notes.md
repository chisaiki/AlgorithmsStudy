## Traversals

### How to Pick a Traversal Method
There are four standard traversal algorithms **(All depth first search traversals)** for a binary tree.<br>The first three :<br>
- Preorder<br> 
- Inorder<br>
- Postorder<br>

The final algorithm is a **breadth first search**(BFS) traversal.

For many problems, any traversal algorithm will lead to a solution. However, there are certain cases where a particular algorithm is preferred.

#### Depth First Search

In general, depth first search algorithms are preferred when the solution is expected to be deeper within the tree since the algorithm follows one branch as far as possible before backtracking and exploring other paths. In these scenarios, a breadth first approach may still find a solution, but more slowly since it traverses nodes closest to the root first.

Inorder traversals are commonly used for finding leaves, the height of the tree, or the diameter of the tree.

##### Inorder

Given a binary search tree, inorder will traverse the nodes in sorted ascending order.

Inorder traversals are commonly used for binary search tree tasks or converting a binary search tree to a sorted list.

##### Preorder

Given a binary tree, preorder will process the root of the tree before either subtree. It also processes nodes in the order they were inserted into the tree.

Preorder traversals are commonly used for tree copying, expression tree evaluation, and serializing a tree.

##### Postorder

Given a binary tree, postorder will process the subtrees before the root.

Postorder traversals are commonly used for deleting a tree and expression tree evaluation.

#### Breadth First Search

Given a binary tree, breadth first search traverses nodes higher up in the tree (closest to the root) first. It is preferred when you expect the solution to be closer to the root. It also explores nodes level by level, from left to right.

Breadth first search is commonly used for problems that require traversing by level.



