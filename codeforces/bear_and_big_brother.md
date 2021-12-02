Found at [https://codeforces.com/problemset/problem/791/A](https://codeforces.com/problemset/problem/791/A)

exec 15 ms, memory 0 kb

Not my proudest problem. I noticed that a and b have to be less than 10. The maximum amount of years before a passes b is 6, because 3^6 * 1 > 2^6 * 10. 5 is too low. Anyway, with a maximum of 6 and a minimum of 1 (since a <=b), lower the maximum and raise the minimum until found. I could have used a for loop since it's guaranteed to only pass the loop 6 times, but that would require more work for me and the computer.
