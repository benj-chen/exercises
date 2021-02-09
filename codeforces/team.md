Found at [https://codeforces.com/contest/231/problem/A](https://codeforces.com/contest/231/problem/A)

For context, sum is the total number of problems that the team uploads. sumprob is the total number of people that are sure that they got a certain problem. gb is the good/bad variable, denoting if the current input says that a person is sure that they got the problem or not (except for the number of problems, every input is a 1 or 0, so I used a bool).

First, evaluate the problems one at a time using a for loop on the inputted number n. Reset sumprob to 0, then grab the 3 inputs and count them, essentially. If it's greater than 1 (2 or more people are sure that they got it), then increment sum. Print sum at the end.
