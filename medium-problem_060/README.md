### Problem 60 (medium)

This problem was asked by Facebook.

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset `{15,5,20,10,35,15,10}`, it would return true, since we can split it up into `{15,5,10,15,10}` and `{20,35}`, which both add up to `55`.

Given the multiset `{15,5,20,10,35}`, it would return false, since we can't split it up into two subsets that add up to the same sum.

---

This problem is easier than it seems. It actually is one problem disguised at two. You only need to find ONE subset and verify the other. Think about it: if both subsets are equal, then the entire set is twice as much. Let's use the above example: `{15,5,20,10,35,15,10}` adds up to 110, so we want each subset to add up to 55. That would make both subsets equal. The actual problem becomes finding a subset that totals 55, and then confirming that the remainder also adds up to 55.

Analyze the second set: `{15,5,20,10,35}` ... that totals 85, which is not an even number, and therefore will not yield two subsets which are equal.
