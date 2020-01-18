### Problem 47 (easy)

This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

---
I had been asked this question in a previous assessment, and this is the solution I devised (Python 3):

```python
def solution(prices):
	if len(prices) == 0:
		return 0
	max = 0
	for outer in range(0, len(prices)):
		for inner in (range(outer + 1, len(prices) )):
			if prices[inner] - prices[outer] > max:
				max = prices[inner] - prices[outer]
	return max

print(solution([9, 11, 8, 5, 7, 10]))
```
There is a simple, literal analog in C++:
```c++
	int max = 0;
	for(int outer = 0; outer < prices.size(); outer++) {
		for(int inner = outer + 1; inner < prices.size(); inner++) {
			if(prices[inner] - prices[outer] > max) {
				max = prices[inner] - prices[outer];
			}
		}
	}
```
If we use a more high-level approach and leverage iterators and lambda expressions, it is more verbose due to some restriction:
```c++
	int offset = 1;
	for_each(prices.begin(), prices.end(), [prices, &max, &offset](int outer) {
		for_each(prices.begin() + offset++, prices.end(), [outer, &max](int inner) {
			if(inner - outer > max) {
				max = inner - outer;
			}
		});
	});
```
What is the need for "offset"? In JavaScript, it is common to obtain not only the item in an iterator, but also the index. Consider the following:

```javascript
var l = [4, 2, 1, 3];
l.forEach(function(item, idx) { console.log(idx, item); });
```

We cannot get the equivalent of "idx" in the C++ iterator, so we manually keep track of "offset".
