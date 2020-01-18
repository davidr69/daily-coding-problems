
### Problem 49 (medium)

This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.

---
There is an implicit requirement here, which is that the sum should not be negative.

I had solved this in Python during an assessment, but it lacked one requirement stated above. First my solution:

```python
total = 0
begin = 0
end = 0
loopsum = None
for outer in range(0, len(arr)):
	loopsum = 0
	for inner in range(outer, len(arr)):
		loopsum = loopsum + arr[inner]
		if(loopsum > total):
			begin = outer
			end = inner
			total = loopsum
return total
```
The problem with this solution is that it doe not meet the requirement of being O(n); it is O(Σn).

Let's consider how many subarrays are possible using a set of 4 numbers: [a,b,c,d]. We can get (and this grouping is very intentional):
```
a         1
ab        2
abc       3
abcd      4
 b        5
 bc       6
 bcd      7
  c       8
  cd      9
   d      10
```
That literally is Σ4 (1 + 2 + 3 + 4). Consider how these staggered groups begin at specific offsets. The first set (1-4) begins on the first column. The second set (5-7) on the second, the third group (8-9) on the third column, and the last (10) on the fourth. How about we launch 4 threads to handle the 4 sets? Technically, the longest one will be O(4), which is O(n).

I cannot see any other way to compute 10 sums in 4 steps, but if there is, I would like to know.

This solution must be compiled by using a special flag:

```
$ g++ problem_49.cpp -lpthread
```
