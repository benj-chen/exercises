#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define f(n) for(int i=0;i<n;i++)
using namespace std;
int main() {
    vector<int> v = {5,4,3,2,1};
    int upto = 3;
    sort(v.begin(),v.begin()+upto);
    for (int i: v) cout << i << endl;
}