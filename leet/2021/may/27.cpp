#define bs binary_search
class Solution {
public:
    // make N(N+1)/2 comparisons, where N is the length, so O(N^2)
    int maxProduct(vector<string>& words) {
        int n = words.size();
        for (string& i: words) {
            sort(i.begin(),i.end());
        }
        int max=0;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                // share?
                // use binary search
                for (char c: words[j]) {
                    if (bs(words[i].begin(),words[i].end(),c)) {
                        goto done;
                    }
                }
                max=fmax(words[i].size()*words[j].size(),max);
                done:;
            }
        }
        return max;
    }
};