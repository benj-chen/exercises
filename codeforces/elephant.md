Found at [https://codeforces.com/contest/617/problem/A](https://codeforces.com/contest/617/problem/A)

Simply take the number, divide by 5 (max stride length), and round up. I accomplished this with the mod operator as a bool (0 if the modulus is 0, 1 if not), and added that to the floored division of the number by 5. I didn't bother with the using namespace std; part because I was only using the cin and cout statements once, which means that it's not much trouble for me to put the std:: part in front.
