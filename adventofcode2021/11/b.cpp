#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
vvi grid; // grid.size()=10, grid[0].size()=10
int ct=0;
void flash(int x,int y, bool orig) {
    // orig: do we need to add 1?
    if(x<0||x>9||y<0||y>9) return;
    if (!orig)
        grid[x][y]++;
    if(grid[x][y]==10) { // first time experiencing a flash
        for (int i=-1;i<2;i++)for(int j=-1;j<2;j++)if (i||j) flash(x+i, y+j,false);
    }
}

int main() {
    char c;
    for (int i=0;i<10;i++) {
        grid.push_back({});
        for (int j=0;j<10;j++) {
            cin >> c;
            grid.back().push_back(c-'0');
        }
        cin.ignore();//newline
    }
    for (int t=0;true;t++) {
        for (int i=0;i<10;i++) for (int j=0;j<10;j++) {
            grid[i][j]++;
            if (grid[i][j]>9) flash(i,j, true);
        }
        bool all = 1;
        for (int i=0;i<10;i++) for (int j=0;j<10;j++){ if(grid[i][j]>9) {grid[i][j]=0;ct++;} else {all=0;}}
        if (all) {
            cout << t+1 << endl;
            break;
        }
    }
}