### PROBLEM 36 (medium)

This problem was asked by Dropbox.

Given the root to a binary search tree, find the second largest node in the tree.

---
Having worked on other binary tree problems, I already have template code for inserting, searching, and displaying binary trees. That portion of code was reused. The additional logic is as follows:

To find the largest node, simply rcursively traverse the tree only to the right. En route to the last node, keep the value of the previous node. This is not a doubly-linked list, so we cannot traverse in reverse. Instead, keep track of the current node's value, and THEN move to the next node. If that node does not contain a child node, you have arrived at the last node AND kept track of the second largest.
