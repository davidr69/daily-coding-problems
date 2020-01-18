# Daily Coding Problems

I subscribed to a service which sends a daily email with a coding problem, and the difficulty will vary from easy to medium to hard. The site is:
https://www.dailycodingproblem.com/

These problems are usually best solved using Python, while in some cases, Java would be better. I don't see why they can't also be solved using JavaScript, but I decided to brush up on my C++ skills, trying to incorporate advances made in C++11, C++14, and C++17. I try avoiding the Boost libraries and sticking to the core C++ libraries. I do not have the time to solve all the problems in C++, so you will not find the solution to some of the problems.

Unless otherwise stated, each solution can be compiled as follows:

```shell
$ g++ problem_n.cpp
$ ./a.out
```
I decided that the solutions should have a more "C++ native" building approach, so some solutions will contain a Makefile, and all required flags and dependencies will be taken care of. For example, one flag I use is `-std=c++17`, which will apply the C++17 syntax and features. Solutions that leverage threads will contain the `-lpthread` flag to link against the POSIX thread library. A typical example woudl be:

```shell
$ make
$ ./problem_1
```
The problem number changes per solution.
