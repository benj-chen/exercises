#include<vector>
#include <algorithm>
#include<iostream>
using namespace std;
using vi = vector<int>;
int binary(const vi& ls, int element, int front, int back) {
    // standardize front and back
    // front is inclusive (initially 0)
    // back is exclusive (initially ls.size())
    cout << endl << front << " " << back << endl;

    if (front + 1 == back) {
        // 1 element list
        cout << "1 elem" << endl;
        return front;
    }

    int mid = front + (back-front)/2;
    // split the list based on midpoint
    if (ls[mid] > element) {
        cout << "bottom half" << endl;
        return binary(ls, element, front, mid);
    }
    else {
        // somewhere in the upper half
        cout << "top half" << endl;
        return binary(ls,element, mid, back);
    }
}

int main() {
    vi ls = {1,2,4,5,6,6,6,7};
    cout << binary(ls,3,0,ls.size()) << endl;    
    cout << binary(ls,1,0,ls.size()) << endl;    
    cout << binary(ls,7,0,ls.size()) << endl;    
    cout << binary(ls,6,0,ls.size()) << endl;    
    cout << binary(ls,4,0,ls.size()) << endl;    
    cout << binary(ls,0,0,ls.size()) << endl;    
    cout << binary(ls,10,0,ls.size()) << endl;    
    // mid = 4

}