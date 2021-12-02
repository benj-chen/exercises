Found at [https://codeforces.com/problemset/problem/96/A](https://codeforces.com/problemset/problem/96/A)

exec 60 ms, memory 0 kb

Start the count at 0 so that when counting the first character the count is 1 (which it should be). Iterate through the string. If the current character doesn't match, start the count at 1, and change the type to look for to the current character. It's okay to use references here because I don't modify c, only type_ln. As soon as the count reaches 7, print YES and finish. If it never does, then print NO.
