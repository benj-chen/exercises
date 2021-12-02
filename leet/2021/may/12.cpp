// Range Sum Query 2D - Immutable
// alternatively, use 2d prefix sums, like this:
/*
Say you want a square in the middle. With the prefix sum that calculates the prefix sums of those before
with respect to an origin at the bottom right, you could get the rectangle that goes to the top left corner,
then subtract the rectangle that goes to the top right corner,
then subtract the rectangle that goes to the bottom left corner
then add the rectangle that goes to the bottom right, to cover the last
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define vi vector<int>
#define vvi vector<vi>
class NumMatrix {
public:
    vvi m1,m2;
    NumMatrix(const vector<vector<int>>& matrix) {
        m1=matrix;
        m2=matrix;
        // prefix sums, I guess
        for (vi& v: m1) {
            for (int i=1;i<v.size();i++) {
                v[i]+=v[i-1];
            }
        }
        // column prefix sums, I guess
        int sz=m2[0].size();
        for (int i=1;i<m2.size();i++) {
            for (int j=0;j<sz;j++) {
                m2[i][j]+=m2[i-1][j];
            }
        }
        cout << "init done" << endl;
    }
    int row(int r, int i, int j) {
        return m1[r][j]-(i==-1? 0 : m1[r][i]);
    }
    int col(int c, int i, int j) {
        return m2[j][c]-(i==-1? 0: m2[i][c]);
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans=0;
        if (row2-row1 < col2-col1) {
            // use row
            for (;row1<=row2;row1++) {
                ans+=row(row1,col1-1,col2);
            }
        }
        else {
            // use col
            for (;col1<=col2;col1++) {
                ans+=col(col1,row1-1,row2);
            }
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
int main() {
    cout << "you should probably submit it here: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3740/" << endl;return 0;
}