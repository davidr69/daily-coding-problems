### Problem 27 (easy)

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string `([])[]({})`, you should return true.

Given the string `([)]` or `((()`, you should return false.

---
Anyone who has implemented even a rudimentary lexical analyzer knows that this is easily accomplished with a stack. C++'s STL (Standard Templates Library) has a stack class, but without it, stacks can be easily simulated with other data structures, such as lists or vectors.
