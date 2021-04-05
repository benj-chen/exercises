#include <bits/stdc++.h>
#define v vector
#define f first
#define s second
using namespace std;
v<v<int> > board;
v<v<int> > must_visit(9); // envision a tictactoe board
const pair<int,int> adj_modifiers[]={make_pair(1,0),make_pair(0,1),
make_pair(-1,0),make_pair(0,-1)};
int ttt[9];
v<int> dfs_init(int a, int b, int parent_a, int parent_b) {
    // if it's a dead end
    int adj[4];
    for (int i=0;i<4;i++) {
        adj[i]=board[adj_modifiers[i].f][adj_modifiers[i].s];
    }
    int wallct=0;
    for (int i: adj) {
        if (i==-1) {
            wallct++;
        }
    }
    if (wallct==3) {
        if (board[a][b]==0 || board[a][b]==1) {
            return {}
        }
    }
}
int main() {
    /*
    make a graph that describes which cells you must visit in order
    to visit some other cell
    */
    int n;
    cin >> n;
    // int /*type*/ board[n][n];
    board.resize(n);
    for (v<int>& vec: board) vec.resize(n);
    return 0;
    string input;
    for (int i=0;i<9;i++) ttt[i]=-1;
    /*
    -1: wall
    0: O
    1: M
    2: Bessie's current location
    3: empty (moveable)
    */
    int bx,by;

    for (int i=0;i<n;i++) {
        cin >> input;
        for (int j=0;j<n;j+=3) {
            if (input[j]=='#') { // could use switch instead
                board[i][j]=-1;
            }
            else if (input[j]=='.') {
                board[i][j]=2;
            }
            else if (input[j]=='B') {
                bx=i;
                by=j;
                board[i][j]=3;
            }
            else {
                board[i][j]=input[j]=='M';
                ttt[input[j+1]-'1' * 3 + input[j+2]-'1']=(input[j]=='M');
            }
        }
        

    }
    
    // do a dfs to get a graph to do a dfs lol
    dfs_init(bx,by,-1,-1);
    
    ;
}