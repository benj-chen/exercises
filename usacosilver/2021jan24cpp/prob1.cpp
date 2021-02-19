#include <iostream>
#include <vector>
using namespace std;
int a;
int geti() { // get int but subtract 1 for zero indexing
    cin >> a;
    return a-1;
}
vector<int> concat(vector<int> a, vector<int> b) {
    for (int c: b) {
        a.push_back(c);
    }
    return a;
}
/*
int uniq_pos(const vector<int> swaps[], const vector<int> go[], int ind, int beg_of_cycle, bool first_time=1) {
    if (!first_time && beg_of_cycle==ind) { // cycle has come full circle
        return 0;
    }
    return go[beg_of_cycle].size() + uniq_pos(swaps,go, ind,go[beg_of_cycle][go[beg_of_cycle].size()-1],0);
}
*/
int last(vector<int> vec) {
    return vec[vec.size()-1];
}
vector<int> spots(const vector<vector<int> > swaps, const vector<vector<int> > go, // per the test cases 6-10 guidelines
int cyclestart, int ind, bool not_first_time=0) { // add a visited of type vector<bool> showing which have been visited
    if (not_first_time && ind==cyclestart) return {};
    
    return concat(go[ind],spots(swaps,go,cyclestart,last(go[ind]),1));
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int> > swaps(k);
    for (int i=0;i<k;i++) swaps[i]={geti(),geti()};
    vector<vector<int> > go(n);
    vector<int> facing(n);
    for (int i=0;i<n;i++) facing[i]=i;
    for (vector<int> vec: swaps) {

        go[facing[vec[0]]].push_back(facing[vec[1]]);
        go[facing[vec[1]]].push_back(facing[vec[0]]);
        facing[vec[0]]=vec[1];
        facing[vec[1]]=vec[0];
    }
    
    // use recursion
    // WORKS: testing swaps and go for the next 7 lines
    cout << endl;
    for (vector<int> vec: go) {
        for (int i: vec) {
            cout << i << ' ';
        }
        cout << endl;
    }
    for (int i=0;i<n;i++) {
        cout << i << ":\t";
        // vector<int> vec = spots(swaps,go,i,i);
        // for (int j: vec) {
        //     cout << j << " ";
        // }
        cout << endl;
    }
}

/*
bool isNeverSwapped(vector<vector<int> > &swaplist,int target) {
    for (vector<int> vec: swaplist) {
        if (vec[0]==target || vec[1]==target) return false;
    }
    return true;
}
void swap(vector<vector<int> > &vec,int inda, int indb) {
    inda--;indb--;
    int temp=vec[inda][1];
    vec[inda][1] = vec[indb][1];
    vec[indb][1] = temp;
}
bool in(int elem,vector<int> &elems) {
    for (int x: elems) {
        if (x==elem) return true;
    }
    return false;
}
vector<int> recurse(vector<vector<int> > locs, const vector<vector<int> > &swaplist, int toObserve) {
    toObserve--;
    int ct=0;
    bool hasChangedBefore=0;
    int preval=-1;
    vector<int> visited={toObserve+1};
    while (true) {
        for (vector<int> vec: swaplist) {
            if (!hasChangedBefore) {
                preval=locs[toObserve][1];
            }
            swap(locs,vec[0],vec[1]);
            if (preval!=locs[toObserve][1]) hasChangedBefore=1;
            if (hasChangedBefore && locs[toObserve][1]==toObserve+1){
                return visited;
            }
            if (!in(locs[toObserve][1],visited)) visited.push_back(locs[toObserve][1]);
        }
    }
}

int main() {
    int n,k;
    cin >> n >> k;
    vector<vector<int> > swaps,locs;
    vector<int> temp_inp(2);
    for (int i=0;i<k;i++) {
        cin >> temp_inp[0] >> temp_inp[1];
        swaps.push_back(temp_inp);
    }
    for (int i=1;i<=n;i++) {
        temp_inp[0]=i;
        temp_inp[1]=i;
        locs.push_back(temp_inp);
    }
    // setup done
    // cout << '\n';
    // for (vector<int> vec: locs) {
    //     cout << vec[0] << ' ' << vec[1] << '\n';
    // }
    // swap(locs,swaps[0][0],swaps[0][1]);
    // for (vector<int> vec: locs) {
    //     cout << vec[0] << ' ' << vec[1] << '\n';
    // }
    for (int i=1;i<=n;i++) { // last one produces an infinite loop
        
        if (isNeverSwapped(swaps,i)) {
            cout << 1 << '\n';
            continue;
        }
        vector<int> sol=recurse(locs,swaps,i);
        cout << "testing solution " << i << ":\n";
        cout << "size = " << sol.size() << '\n';
        cout << "elements are: \n";
        for (int x: sol) cout << x << '\t';
        cout << '\n';

    }
    
    // test swap
}
*/