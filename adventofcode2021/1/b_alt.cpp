#include <iostream>
#include <queue>
using namespace std;
int main() {
    queue<int> q;
    int in, score=0;
    for (int i=0;i<3;i++) {
        cin>>in;
        q.push(in); // start with size of 3: {A, AB, AB}
    }
    while (cin>>in) {
        if (in>q.front()) // same idea as b main
            score++;
        q.push(in);
        q.pop();
    }
    cout<<score<<endl;
}