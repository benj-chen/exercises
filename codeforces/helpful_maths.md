Found at [https://codeforces.com/problemset/problem/339/A](https://codeforces.com/problemset/problem/339/A)

exec 30 ms, memory 0 kb

This was a terrible problem to do in c++- it would have been a breeze and a half had I done it in python. However, for the sake of practicing c++, I did it in c++. Here would be the solution in Python:

print("+".join(sorted(input().split("+")))) [exec 124 ms, memory 0 kb]


Anyways, back to cpp:

I used a C-style array to hold the inputs. Using a vector probably would have been easier. Anyway, I made a function to count the plus character in the string and that became the array size. I made an elem variable to hold the number between pluses, and a loc variable to represent the index I'm currently on. If the character is +, then assing elem to the correct inp index and increment loc. Otherwise, add the character to elem as if it was a string. However, you do need to subtract 48 becuase the char form of 0 is 48. It would be like appending the new char to the end of elem, but elem is an int. Learned this almost-trick about moving left by multiplying by 10 from math. Then I printed the array with a + in between. Learned the algorithm sort array thing from a USACO problem solution haha.
