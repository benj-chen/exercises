#include <iostream>
#include <utility>
#include <vector>
using namespace std;
using pii = pair<int,int>;
using vp = vector<pii>;
using ul = unsigned long; // number should be between 0 and something
#define f first
#define s second
ul ans;

int main() {
    int N;
    cin >> N;
    vp locs(N);
    for (int i=0;i<N;i++) cin >> locs[i].f >> locs[i].s;
    ans=2+N; // empty plus all plus individuals


    // generate all subsets which would pass like 1-5. Naive. You could also use dp to calculate bigger ones
    // you could bundle up into groups of 2, then bundle those up into groups of 2 etc
    // aggregate one into two that are close to each other? linear time?
    
}