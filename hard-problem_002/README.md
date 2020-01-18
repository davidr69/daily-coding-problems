### PROBLEM 2 (hard)

This problem was asked by Uber.

Given an array of integers, return a new array such that each element at index i of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5], the expected output would be [120, 60, 40, 30, 24]. If our input was [3, 2, 1], the expected output would be [2, 3, 6].

Follow-up: what if you can't use division?

---

I originally solved this in Python, before having decided to solve all the problems in C++, and this is what I came up with:

```python
#!/usr/bin/python

def products(nums):
	newlist = []
	for outer in range(0, len(nums)):
		current = 1
		for inner in range(0, len(nums)):
			if inner != outer:
				current = current * nums[inner]
		newlist.append(current)
	return newlist

print products([1, 2, 3, 4, 5])

print products([3, 2, 1])
```
The question regarding using division is puzzling; why **would** you need division?

The C++ equivalent is practically a literal translation of the Python script. In order to obtain an index of where within the list we are, we cannot use lambda expressions alone:

```c++
std::for_each(nums.begin(), nums.end(), [](int i) { cout << i << endl; });
```
We require the overhead of manually maintaining a counter which is updated within the lambda expression. A conventional for loop would be cleaner, but we want to be able to implement the C++ features.
