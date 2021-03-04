#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    deque<int> inp(n);
    for (int i=0;i<n;i++) cin >> inp[i];
    sort(inp.begin(),inp.end());
    n=0;
    while (inp.size()>1)
    {
        int ma=inp.back(),mi=inp.front();
        n++;
        inp.pop_back();
        if (ma+mi<=x) inp.pop_front();
    }
    cout << n+inp.size();

}