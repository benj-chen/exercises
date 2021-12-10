#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;
using vi = vector<int>;
vi split_delimiter_char(string s, char delim) {
    vi res;
    string cur_num="";
    for (char c: s) {
        if (c==delim) {res.push_back(stoi(cur_num)); cur_num = "";}
        else cur_num+=string(1,c);
    }
    return res;
}
struct Board {
    vector<vector<pair<int,bool>>> board;
    Board(const vector<vi>& b) {
        for (vi v: b) {
            board.push_back({});
            for (int i: v) {
                board.back().push_back(make_pair(i,0));
            }
        }    
    }
    bool add(int n) {
        for (int i=0;i<5 /* board dimension */; i++) {
            for (int j=0;j<5;j++) {
                if (board[i][j].first==n) {
                    board[i][j].second=1;
                    // check its row and column to see if the rest are 1
                    bool horiz = 1, vert = 1;
                    for (int k=0;k<5;k++) {
                        if (!(board[i][k].second)) {
                            horiz = 0;
                        }
                        if (!(board[k][j].second)) {
                            vert = 0;
                        }
                    }
                    return horiz || vert;
                }
            }
        }
        return 0;
    }
};
int main() {
    // get drawn numbers input
    string s; cin >> s; // in the input there are no spaces between commas
    vi draw = split_delimiter_char(s,',');
    // get board input
    vector<pair<Board,bool>> boards; // 0 for not done, 1 for done
    while (getline(cin,s)) {
        // get 5 lines; empty line is s
        vector<vi> board(5, vi(5));
        for (int i=0;i<5;i++) {
            for (int j=0;j<5;j++) {
                cin >> board[i][j];
            }
        }
        boards.push_back(make_pair(Board(board),0));
    }
    int ans;
    for (int i: draw) { 
        for (pair<Board,bool>& p: boards) {
            if (!(p.second)) {
                if (p.first.add(i)) {
                    p.second=1;
                    // winner
                    int sum = 0;
                    for (vector<pair<int,bool>> v: p.first.board) {
                        for (pair<int,bool> p: v) {
                            if (!p.second) {
                                sum+=p.first;
                            }
                        }
                    }
                    ans = sum * i; // ans will update until it gets to the last board, which is what we want.
                }
            }
        }
    }
    cout<<ans<<endl;
}