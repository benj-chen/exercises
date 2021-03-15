#include <bits/stdc++.h>
using namespace std;
using st=string;
vector<st> input(1);
int l,w;
void replace(st& s, int ind, char c) {
    s=s.substr(0,ind) + string(1,c) + s.substr(ind+1,s.length());
}
void reset(bool arr[]) {
    for (int i=0;i<l;i++) {
        for (int j=0;j<w;j++) {
            arr[i][j]=0;
        }
    }
}
bool equals(bool arr1[], bool arr2[]) {
    for (int i=0;i<l;i++) {
        for (int j=0;j<w;j++) {
            if ((*arr1)[i][j]!=(*arr2)[i][j]) return false;
        }
    }
    return true;
}
int get_adj(int xloc, int yloc) {
    int ct=0;
    for (int x=-1;x<2;x++) for (int y=-1;y<2;y+=!x+1) if (input[xloc+x][yloc+y]=='#') ct++;
    // the !x+1 is so that if it's 0, it won't create 0,0 which is just itself and instead skip to 1.
    return ct;
}
int get_far(const int xloc, const int yloc) {
    int ct=0,x=xloc,y=yloc;
    if (xloc>0) {
        while (x--) // check up
            if (input[x][yloc]=='#') {
                ct++;
                cout << x << " " << yloc << endl;
                break;
            }
    }            
    if (xloc+1<l) {
        for (x=xloc+1;x<l;x++) // check down
            if (input[x][yloc]=='#') {
                ct++;
                cout << x << " " << yloc << endl;
                break;
            }
    }            

    if (yloc>0) {
        while (y--) // check left
            if (input[xloc][y]=='#') { ct++;
            cout << xloc << " " << y << endl;
            break;}
    }
    if (yloc<w-1) {
        for (y=yloc+1;y<w;y++) // check right
            if (input[xloc][y]=='#') {
                ct++;
                cout << xloc << " " << y << endl;
                break;
            }
    }            
    return ct;
}
int main() {
    ifstream in("i11");
    
    in >> input[0];
    w=input[0].length();
    st raw_input;
    while (in >> raw_input) input.push_back(raw_input);
    l=input.size();
    // x is the row number-1, y is the col number-1. l is the row number, w is the column number
    // sol 1
    bool mark[w][l];
    bool prevmark[w][l];
    while (1) {
        reset(*mark);
        for (int i=0;i<l;i++) {
            
            for (int j=0;j<w;j++) {
                if (input[i][j]=='#') {
                    // if 4 or more seats are filled, mark it
                    if (get_adj(i,j)>3) {
                        mark[i][j]=1;
                    }
                }
                else if (input[i][j]=='L')
                {
                    // if 0 adjacent seats are filled, mark it
                    if (!get_adj(i,j)) {
                        mark[i][j]=1;
                    }
                }
            }
        }
        if (equals(mark,prevmark)) {
            for (int i=0;i<l;i++) {
                for (int j=0;j<w;j++) {
                    if (mark[i][j]) {
                        replace(input[i],j,
                        (input[i][j]=='#'? 'L' : '#'));
                    }
                }
            }         
            break;
        }
        for (int i=0;i<l;i++) {
            for (int j=0;j<w;j++) {
                // substitute prevmark with mark;
                prevmark[i][j]=mark[i][j];
                if (mark[i][j]) {
                    replace(input[i],j,
                    (input[i][j]=='#'? 'L' : '#'));
                }
            }
        }


    }
    int sum=0;
    for (st s: input) {
        sum+=count(s.begin(),s.end(),'#');
    }
    cout << sum << endl;
}