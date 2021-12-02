#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
void a() {
    int cur, last, score=0;
    cin>>last;
    while (cin>>cur) {
        if (cur>last) score++;
        last = cur;
    }
    cout<<score<<endl;
}
void b() { // same speed as b_alt() but b_alt() probably has better memory
    int i,score=0;
    vi in;
    while (cin>>i) {
        in.push_back(i);
    }
    // compare index 0 to index 3, etc, because for groups A and B they have 2 numbers in common, so we don't care about them
    for(int ind = 3; ind<in.size();ind++)
        if (in[ind]>in[ind-3])
            score++;
    cout<<score<<endl;
}
void b_alt() {
    queue<int> q;
    int in, score=0;
    for (int i=0;i<3;i++) {
        cin>>in;
        q.push(in); // start with size of 3: {A, AB, AB}
    }
    while (cin>>in) {
        if (in>q.front()) // same idea
            score++;
        q.push(in);
        q.pop();
    }
    cout<<score<<endl;
}
int main() {
    b();
}