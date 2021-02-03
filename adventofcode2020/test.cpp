#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int c;
    cin >> c;
    c++;
    for (int i=1;i<c;i++)
    {
        int n,b;
        cin >> n >> b;
        int h[n];
        for (int j=0;j<n;j++)
        {
            cin >> h[j];
        }
        sort(h,h+n);
        int ct=-1;
        for (int k: h) {
            if (b<0) break;
            b-=k;
            ct++;
        }
        cout << "Case #" << i << ": " << ct << endl;
    }
}