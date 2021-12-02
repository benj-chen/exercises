#include <iostream>
using namespace std;
using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;
#define FOR(a,st,b) for (int a=st;a<b;a++)
#define EACH(a,b) for (auto& a: b)
#define vt vector
#define vi vt<int>
// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum
/*keep in mind, to find the sum of a range, this would be the function:
int sumrange(int st, int end) {
    assert (end>=st);
    return (st+end)*(end-st+1)>>1;
}
but since we do it once, there's no need to put it in a function. st is 1 and end is 100. see line 20*/
int main() {
    ull sum_sq=0,sq_sum=0;
    FOR(i,1,101) sum_sq+=i*i;
    sq_sum = 101*50; // sq_sum=(1+100)*(100-1+1)>>1; // FOR(i,1,101) sq_sum+=i;
    sq_sum*=sq_sum;
    cout << sq_sum-sum_sq << endl;
}