#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
int main() {
    int i,score=0;
    vi in;
    while (cin>>i)
        in.push_back(i);
    // compare index 0 to index 3, etc, because for groups A and B they have 2 numbers in common, so we don't care about them
    for(int ind = 3; ind<in.size();ind++)
        if (in[ind]>in[ind-3])
            score++;
    cout<<score<<endl;
}