// Construct Target Array With Multiple Sums

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size()==1 && target.front()!=1) return false;
        for (int i: target) {
            cout << i << " ";
        }
        cout << endl;
        sort(target.begin(),target.end());
        for (int i: target) if (i!=1) goto end;
        return true;
        end:;
        long long sum=0;
        for (int i: target) {
            sum+=i;
        }
        sum-=target.back(); // this is the number that needs to be subtracted from the back
        int backdiff=target.back()-target[target.size()-2];
        int jump = backdiff/sum + bool(backdiff%sum);
        int tb=target.back();
        target.back()-=jump*sum;
        if (target.back()==tb) return false;
        if (target.back()<1) return false;
        return isPossible(target);
    }
};
int main() {
    Solution s;
    cout << boolalpha << s.isPossible({1});
}