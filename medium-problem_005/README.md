### Problem 5 (medium)

This problem was asked by Jane Street.

`cons(a, b)` constructs a pair, and `car(pair)` and `cdr(pair)` returns the first and last element of that pair. For example, `car(cons(3, 4))` returns `3`, and `cdr(cons(3, 4))` returns `4`.

Given this implementation of cons:

```python
def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
```
Implement `car` and `cdr`.

---
This is a python-specific question. The solution, in python, is:

```python
def car(fn):
	def nest(x, y):
		return x
	foo = fn(nest)
	return foo

def cdr(fn):
	def nest(x, y):
		return y
	foo = fn(nest)
	return foo
```
I don't find this problem to be useful. It does not determine your ability to think logically; it simply tests your knowledge of syntax. This syntax is not portable across languages. For example, C/C++ cannot nest functions, and since they are strongly typed, they present issues when passing arguments.

We can simulate nested functions, but this alters the nature and spirit of the question. Nonetheless, here we go ...

We can levarge lambda expressions, which yield functions, BUT a lambda expression can only be converted to a function pointer if it does not capture, but our lambda expression does capture:

```c++
auto pair = [a, b](auto *f) -> int { return f(a, b); };
```

It captures `[a, b]` so that it can pass them to the function `f`. Different work-arounds can be implemented, but they invariably end up being object oriented (even a struct can resemble a class).

Looking at my Python implementation of the `car` function, we see a function named `nest` within it. This is simply not permitted in C/C++. Instead, I defined `nesta` and `nestb` as top-level functions:

```c++
int nesta(int a, int b) { return a; }
```
Now we can create a reference to the function and pass it to the lambda expression:
```c++
int (*fn1)(int, int) = nesta; // "car" function pointer
cout << foo(fn1) << endl;
```
