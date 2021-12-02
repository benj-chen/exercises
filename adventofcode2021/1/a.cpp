#include <iostream>
using namespace std;
int main() {
    int cur, last, score=0;
    cin>>last;
    while (cin>>cur) {
        if (cur>last) score++;
        last = cur;
    }
    cout<<score<<endl;
}