### PROBLEM 43 (easy)

This problem was asked by Amazon.

Implement a stack that has the following methods:

- push(val), which pushes an element onto the stack
- pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
- max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.

Each method should run in constant time.

---
The very last line of the requirement, "run in constant time", tells us something about the solution: it should NOT be O(n), which would be "linear time", not constant time. Constant time would be O(1), O(2), or any other constant number that doesn't depend on the size of the data structure. In order to achieve constant time, we cannot have a structure such as a singly-linked list, UNLESS if the head is at the last element, and the newest entry is at the head. We tend to think of the head as the "first" element and the tail to be the "last" element. We might be tempted to implement this as a doubly-linked list, where we keep track of the tail independently in order to avoid traversing the links, but we can use a singly-linked list where the tail is the "oldest" element and the head is the "newest" element.

This is the approach we are NOT going to take:

[head, n+1, n+2, ..., tail]

That approach has us add at the end of the list. We will insert at the beginning of the list:

[tail, ..., n+2, n+1, head]