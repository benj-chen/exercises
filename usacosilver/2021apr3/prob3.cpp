// problem 3 working
#include <bits/stdc++.h>

using namespace std;

int main() {
    // always in your interest to increment the smallest one
    // not. always increment a group of l though
    // find the index such that the h_index would be higher than it + K

    int n,k,l;
    cin >> n >> k >> l;
    int scores[n];
    for (int i=0;i<n;i++) cin >> scores[i];
    sort(scores,scores+n);
    int ans=1;
    for (int index=n-1 /*backest possible index?*/;index>-1;index--) {
        if (scores[index]+k<ans++) {
            cout << ans-2 << endl;
            return 0;
        }
    }
    cout << ans-2 << endl;
    return 0;
    // I was so close... I don't think I'll make it though but I'll
    // write my analysis of it as I know it right now.
    
    /*
    Let's assume that L = N. Since we need to find the index i such that
    there are i indices over i, we should sort the array to look through
    linearly. Since any given paper can be incremented K times, we need
    to add K to whatever index we want to evaluate.

    To maximize the answer, we need to look at the biggest elements first,
    or the back indices of the sorted array c. You know you have found
    the h-index when the element at an index + K is less than the desired
    answer. After each iteration, increment the answer. This passes 11/20
    test cases.

    Since, however, L is often not N, and is often less than N, sometimes
    there will not be enough iterations to increment everything in a single
    paper. In other words, we can't increment a given index by K because
    we would need every index to be incremented by K, which is impossible if
    L is less than the index.

    I was not able to implement this last step into my solution. Too complex.
    */
}