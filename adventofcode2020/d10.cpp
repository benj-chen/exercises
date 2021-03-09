// with O2 optimization flag, time is 0.004s! I DID IT LETS GOOOOOOO
#include <bits/stdc++.h>

using namespace std;
using ull=unsigned long long;
int max_jolt;
void extract_combocount(const vector<int>& input, ull combos[], int targ, int ind) {

    if (combos[targ]) return;
    if (max_jolt-targ<4) { // base case
        combos[targ]=pow(2,input.size()-1-ind);
        return;
    }
    for (int i=ind+1;i<input.size();i++) {
        if (input[i]<=targ+3) {
            extract_combocount(input,combos,input[i],i);
            combos[targ]+=combos[input[i]];
        }
        else return;
    }
}
int main() {
    vector<int> input(1); // begin with 0 as a starting thing
    ifstream in("i10");
    int ind=0;
    while (in >> input[ind++]) input.resize(ind+1);
    sort(input.begin(),input.end());
    int diff[]={0,1}; // end is always going to be 3 above the max
    for (int i=0;i<input.size()-1;i++)
        switch(input[i+1]-input[i]) {
            case 1: diff[0]++; break;
            case 3: diff[1]++;
        }


    // DYNAMIC PROGRAMMING is the key............ muhaha. shoulda realizes from the start.
    
    int combosize=input.back()+1;
    ull combos[combosize]; // 1 indexing
    for (int i: input) combos[i]=0;
    max_jolt=combosize+2;
    extract_combocount(input,combos,input[0],0);
    // part 1 answer 1885
    cout << diff[0]*diff[1] << endl <<
    // part 2 answer 2024782584832 (I feel redeemed now that I earned the solution myself)
    combos[input[0]] << endl;

}