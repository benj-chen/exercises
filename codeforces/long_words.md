Found at [https://codeforces.com/contest/71/problem/A](https://codeforces.com/contest/71/problem/A)

For each string:
First of all, ignore the directions if the word's length is less than or equal to 10 aka less than 11. By taking advantage of the std::string.length() function, the number that goes between the first and last character of the string is just the length-2, to compensate for the lack of the first and last character being there. The cout statements, in order, are:
1. Print the first letter
2. Print the length -2 (I did this with --len-1 to decrement the length by 1)
3. Print the last letter, with nothing because I decremented in step 2.
