Found at [https://codeforces.com/problemset/problem/546/A](https://codeforces.com/problemset/problem/546/A)

exec 15 ms, memory 0 kb

If k (first banana price) is $1, then paying for w bananas is 1+2+...+w. Using the handy arithmetic sequence formula of seqsum = (1+w)*w/2, multiply that by k, subtract n to get the borrowed money, and if that's negative then print 0, else that number.
