Found at [https://codeforces.com/problemset/problem/118/A](https://codeforces.com/problemset/problem/118/A)

exec 62 ms, memory 0 kb

Pretty simple, for each character, run it through the goalstr function, returning the string that the character should be. If it's a vowel, return nothing. Otherwise, return a period plus the character as a lowercase (had to look up both the char-to-string type conversion and the tolower() method). Print that result out.
