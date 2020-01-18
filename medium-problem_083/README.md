### PROBLEM 83 (medium)

This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:
```
    a
   / \
  b   c
 / \  /
d   e f
```
should become:
```
  a
 / \
 c  b
 \  / \
  f e  d
```
---
### SOLUTION

I used two different techniques for navigating the tree: iteration for adding to the tree, and recursion for displaying and inverting. One complication arose, which is that due to using templates, the solution must be built differently (in terms of the "includes"). The object file for the tree cannot be compiled independently from the solution, which was my original intent.

Since my tree is an actual binary tree, it was not possible to construct the tree given in the provided example. The letter `d` should not appear before the letter `b` in a binary tree. Storing values in arbitrary locations defeats the purpose of a binary tree.

For good measure, I also used numeric values, which is why templates were employed.

![output](images/output.png "output")
