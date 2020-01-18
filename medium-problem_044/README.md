### Problem 44 (medium)

We can determine how "out of order" an array A is by counting the number of inversions it has. Two elements `A[i]` and `A[j]` form an inversion if `A[i] > A[j]` but `i < j`. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.

---
Before even discussing the solution, let's observe that the requirement is to do this faster than O(N^2). We tend to focus on control statements (if, for, while, etc.) to determine the efficiency of an algorithm, but let me present a completely unrealistic example to explain why there is more to efficiency than loops and comparisons.

Let's say we want to display each character of a string individually. Yes, I can craft up a very concise list comprehension in Python, but let's drag this out. Let's do the following:

```python
s = 'Hello'
for i in s:
    temp = i
    print temp
```

Immediately, we see the unnecessary temporary variable. However, consider the following:

```python
def letter(src, pos):
    if pos < len(src):
        print src[pos]
        letter(src, pos + 1)

letter('Hello', 0)
```
Are both of these equally efficient (or inefficient)? They both have one control statement, one output statement, but the `for` loop has the additional assignment. The `for` loop is significantly more efficient. Why? Consider the mechanics of recursion: each call requires a return address and values to be placed on the stack, and upon exiting, they must be pulled of the stack. None of that implicit overhead is present in the for loop. The requirement to be less than O(N^2) needs to consider these additional factors which are normally overlooked when determining the efficiency of an algorithm.

---
Now for the approach on the solution ...

First allow me to call out the fact that the solution contains the following:
```c++
struct Inversion {
	int pos1;
	int pos2;
};
```
"How could you have a `struct` rather than a `class`?" That mentality invariably comes from Java developers. Yes, I am a Java developer, but I'm also pragmatic and a realist, not an idealist. Java has abused the concept of a POJO. Why do you need a class with private members, only to create an accessor and mutator for every member? Is that not functionally equivalent to having a class with public members?

Another issue, perhaps tangential, is the idea that a POJO is an object (*rolls eyes*); it is not. An object is supposed to contain code which acts upon the members. Yes, every POJO inherits some methods (e.g. toString()), but there are no user-defined methods; the methods are defined at the Object() level, from which we implicitly inherit.

All rants aside, the solution is relatively straight-forward: iterate over the array until no swaps are required. Instead of swapping each time a "lower" element is found, iterate over the entire array to find the lowest, and record its position. When the iteration is complete, swap the "first" element with the one at the position you kept track of. On the next iteration, the "first" item changes to position 2 since we are guaranteed that position 1 has the lowest. Worst case scenario, this gives us an efficiency of O(n + (n-1) + (n-2) + ... + 1). With our array of 5 elements, the most we should iterate is 5 + 4 + 3 + 2, or 14, which is much less than 5^2. The difference only increases with more elements: 6^2 vs 6 + 5 + 4 + 3 + 2, or 20.

---
A couple of notes:

I'm not sure how the original question came up with "(2, 1), (4, 1), and (4, 3)" as the first result; I get "(2,1), (4,2), and (4,3)". For the second, their result is "The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion." My result is only 2 inversions:

|step|array|swap|
|---|---|---|
|1|5, 4, 3, 2, 1|(5,1)|
|2|1, 4, 3, 2, 5|(4,2)|

Done!

There is no mention in the requirements that the comparisons or swaps must be between adjacent items.