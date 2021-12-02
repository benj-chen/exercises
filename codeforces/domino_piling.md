Found at [https://codeforces.com/problemset/problem/50/A](https://codeforces.com/problemset/problem/50/A)

exec 30 ms, memory 0 kb

To solve well, let's have an example M=N=15. I decided to split a that rectangle into a 15x14 rectangle and a 15x1 rectangle. This second rectangle only applies if N is odd. The first rectangle then becomes easy to solve; a 15x14 rectangle has 15*(14/2) dominoes. If applicable, the second rectangle can contain 15/2=7 dominoes (rounding down for obvious reasons).
