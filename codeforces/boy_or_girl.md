Found at [https://codeforces.com/contest/236/problem/A](https://codeforces.com/contest/236/problem/A)

Hold a string with all the unique values (if I knew more things like set this would have been easier). Run through each character and check if it's in the unique values string. If so, break and don't do anything. Otherwise, add that unique character. Also have a bool that switches between true and false every time a unique character is added. If at the end it's true, then the string had an odd number of unique characters. Otherwise, even.
