Found at [https://codeforces.com/problemset/problem/263/A](https://codeforces.com/problemset/problem/263/A)

exec 30 ms, memory 0 kb

I marked the locations as:
(1,1) (1,2) (1,3) (1,4) (1,5)
(2,1) (2,2) (2,3) (2,4) (2,5)
and so on.

Therefore, the target spot is at (3,3).

To get the input, I stored it into a bool (they have to be 0 or 1). If it was 1, look at i and j and subtract 3 from it (the target spot). Make it the absolute value of itself, add them together, and print it.
