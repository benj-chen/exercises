Found at [https://codeforces.com/problemset/problem/266/A](https://codeforces.com/problemset/problem/266/A)

exec 30 ms, memory 0 kb

I split the string by whenever the letter changes (for example, RRG become RR and G). Then I get the size, subtract 1 to account for the filler variable at initialization and subtract that from the overall number of stones n.
