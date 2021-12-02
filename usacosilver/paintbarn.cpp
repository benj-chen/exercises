#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

struct unit {
    int x;
    int y;
    int layers;
    unit(int xi, int yi) {
        x=xi;
        y=yi;
        layers=0;
    }
    void addRec(int xa,int ya,int xb,int yb) {
        if (x>=xa || y <= ya || x <= xb || y >= yb) layers++;
    }
};

int main() {
    ifstream cin("paintbarn.in"); // over-ride cin and cout, comment these two lines if you want standard in and out. Iostream included.
    ofstream cout("paintbarn.out");
    int n,k,a,b,c,d;
    cin >> n >> k;

    vector<vector<unit> > board(1000);
    for (int i=0;i<1000;i++) {
        
        for (int j=0;j<1000;j++) {
            board[i].push_back(unit(i,j));
        }
    }
    for (int i=0;i<n;i++) {
        cin >> a >> b >> c >> d;
        for (vector<unit> vec: board) {
            for (unit un: vec) {
                un.addRec(a,b,c,d);
            }
        }
    }
    a=0;
    for (int i=0;i<1000;i++) {
        for (int j=0;j<1000;j++) {
            cout << board[i][j].layers << endl;
            a+=(board[i][j].layers==k);
        }
    }
    cout << a;
    

}