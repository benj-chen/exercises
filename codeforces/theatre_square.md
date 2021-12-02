Found at [https://codeforces.com/contest/1/problem/A](https://codeforces.com/contest/1/problem/A)

exec 31 ms, memory 0 kb

Basically, since going over is needed, divide m and n by a and ceil it. I didn't feel like using the ceil() function because that requires a float or double as an argument. Not only that, it requires importing the cmath header, which imports a lot of other things that I don't want. Since in the worst case n*m would be 10^9 x 10^9 which is 10^18, I had to specify the type (ull) when multiplying. Not sure how necessary this is - I'm fuzzy on these types of things and didn't want to go to the internet until I finished the problem.
