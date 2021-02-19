#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
bool is_done(int inp[],int inpsize) {
    for (int i=0;i<inpsize-1;i++) {
        if (inp[i+1]-inp[i]!=1) return 0;
    }
    return 1;
}
void swap(int inp[], int swapfr, int swapto) {
    inp[swapfr]+=inp[swapto];
    inp[swapto]=inp[swapfr]-inp[swapto];
    inp[swapfr]-=inp[swapto];
}
void rearr(int inp[],int swapfr, int swapto) {
    // places the index at swapfr to the index at swapto, moving everything to the side
    // ie rearr(arr,0,2) with arr as {1,2,3} would make arr {2,3,1}.
    if (swapfr>swapto) {
        for (swapfr;swapfr>swapto;swapfr--) swap(inp,swapfr,swapfr-1);
        return;
    }
    for (swapfr;swapfr<swapto;swapfr++) swap(inp,swapfr,swapfr+1);
}
int min_num(int inp[], int inpsize) {
    // brute force, improve later? (O 2**N)
    // sorted array
    
    int deltas[--inpsize];
    for(int i=0;i<inpsize;i++) {
        deltas[i]=inp[i+1]-inp[i];
    }
    // done? return 0
    bool done=1;

    for (int i: deltas) {
        if (i!=1){
            done=0;
            break;
        }
    }
    if (done) return 0;

    // new pos must be not at an endpoint
    // recursion
    // min nums would take the first or last and move them to the biggest delta
    int sum=0;
    int maxdelta[2]={0,0}; // loc, delta
    for (int i=0;i<inpsize;i++) {
        if (deltas[i]>maxdelta[1]) {
            maxdelta[0]=i;
            maxdelta[1]=deltas[i];
        }
    }
    // back endpoint, move closer to the middle (farther for max)
    
    // front endpoint
}

int become_max_num(int inp[], int inpsize) {
    // sorted array
    if (is_done(inp,inpsize)) return 1;
    int beg_move=1,end_move=1;
    // move the beginning to the next out-est spot
    int arr[]=inp;
    // swap(arr,0,1);
    // arr[1]=arr[0]+1;
}

int main() {
    int nums;
    ifstream in("herding.in");
    in >> nums;
    int inp[nums];
    for (int i=0;i<nums;i++) in >> inp[i];
    in.close();    
    sort(inp,inp+nums);
    ofstream out("herding.out");
    out << -1 << endl;
    for (int i: inp) {
        cout << i << ' ';
    }
    rearr(inp,2,0);
    cout << endl;
    for (int i: inp) {
        cout << i << ' ';
    }
    rearr(inp,0,2);
    cout << endl;
    for (int i: inp) {
        cout << i << ' ';
    }
    //rearr with switched in and out reverts

}