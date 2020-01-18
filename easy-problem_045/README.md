### Problem 45 (easy)

This problem was asked by Two Sigma.

Using a function `rand5()` that returns an integer from 1 to 5 (inclusive) with uniform probability, implement a function `rand7()` that returns an integer from 1 to 7 (inclusive).

---

This approach is very simple; `rand7()` will call `rand5()` twice, the second time with a modulus of 3 (returns 0 to 2), and add the results.
