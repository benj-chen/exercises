#include <iostream>
#include <vector>
#include <array>

using namespace std;
using ai = array<int,2>;
using ai4=array<int,4>;
using vi=vector<int>;

bool in(vector<ai>& vec, ai& item){
    for (ai& v: vec) {
        if (v==item) return 1;
    }
    return 0;
}

int main() {
    int n;
    cin >> n;
    vector<ai> p;
    int q,r;
    vector<array<int,4> > comfy; // x,y, xloc yloc that needs to be filled in
    for (int i=0;i<n;i++) {

        
        cin >> q >> r;
        ai temp={q,r};
        p.push_back(temp);
        vector<int> spots;
        for (int i=-1;i<2;i++) { // add affecting-others after
            
            for (int j=-1;j<2;j++) if ((i||j)&&(!i||!j)){
                ai temp = {q+i,r+j};
                if (!in(p,temp)) {
                spots.push_back(q+i);
                spots.push_back(r+j);
                }
            }
        }
        cout << spots.size() << endl;
        if (spots.size()==2) {
            // comfy
            ai4 temp={q,r,spots[0],spots[1]};
            comfy.push_back(temp);
        }
        for (ai4 a: comfy) {
            for (int i: a) cout << i << ' ';
            cout << endl;
        }
        cout << comfy.size() << " (comfysize) " << p.size() << " (psize)\n";



    }
}