// solution written after reading the analysis and looking at the code a lot
// dfs for the first time in a problem
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > adjacent;
int dfs(int start, int parent) {
    int ans=0;
    int neededcows=(parent==-1)+adjacent[start].size();// begin needed cows at 1 if start according to the solution on usaco.guide
    // this is because the amount of cows needed normally is the number of adjacent (adjacent -1 for parent
    // +1 for the starting point itself), but since -1 isn't part of the tree, it's adjacent +1 with no -1
    // because the parent isn't in the adjacent thing
    // since it's a tree, with 0 at the top and each child not connecting to another child
    // we don't have to make a "visited" vector because as long as there are children they are new
    // normally a visited vector would be needed, but the problem specs don't require it
    int cows=1;
    while (cows<neededcows) {
        ans++; // one more day of superspreader
        cows*=2;
    }
    for (int i: adjacent[start]) {
        if (i!=parent) ans+=dfs(i,start)+1; // plus 1 because you must move a cow to i as well
    }
    return ans;
}
int main() {
    int n;
    cin >> n;
    adjacent.resize(n);
    int r1,r2;
    for (int i=1;i<n;i++) {
        cin >> r1 >> r2;
        adjacent[--r1].push_back(--r2);
        adjacent[r2].push_back(r1);
    }
    cout << dfs(0,-1) << endl;

}