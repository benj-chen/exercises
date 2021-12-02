// Maximum Points You Can Obtain from Cards
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxScore(vector<int>& cardPoints1, int k) {
        vector<int> cardPoints;
        if (k*2>cardPoints.size()) {
            cardPoints = vector<int>(cardPoints1.begin(),cardPoints1.begin()+k);
            for (int i=cardPoints1.size()-k;i<cardPoints1.size();i++) {
                cardPoints.push_back(cardPoints1[i]);
            }
        }
        // remove a subvector that is the lowest value
        // use prefix sums as well
        vector<int> psum(1);
        // first is 0
        for (int i: cardPoints) {
            psum.push_back(psum.back()+i);
        }
        // psum.erase(psum.begin());
        // back is the sum
        // k--; // for 0 indexing
        for (int i: psum) {
            cout << i << endl;
        }
        int minsum=psum.back();
        for (int i=0;i<cardPoints.size()-k+1;i++) {
            cout << i+k << " " << i << endl;
            int newsum=psum[i+k]-psum[i];
            if (newsum<minsum) minsum=newsum;
            cout << newsum << endl;
        }
        cout << endl << minsum << endl;

        return psum.back()-minsum;
    }
};
int main() {
    cout << "https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3739/" << endl;
}