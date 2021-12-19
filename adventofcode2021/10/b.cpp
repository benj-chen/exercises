#include <map>
#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    map<char, int> scores {
        {'(',1},
        {'[',2},
        {'{',3},
        {'<',4}
    }, opp {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}
    };
    string s;
    vector<int> scor;
    while (cin>>s) {
        int score = 0;
        stack<int> q;
        for (char c: s) {
            switch(c) {
                case '(': case '[': case '{': case '<':
                q.push(c);
                break;
                case ')': case ']': case '}': case '>':
                
                if (q.top()!=opp[c]) {
                    goto end;
                }
                q.pop();
            }
        }

        while (!q.empty()) {
            score*=5;
            score+=scores[q.top()];
            q.pop();
        }
        cout<<score<<endl;
        scor.push_back(score);
        end:;
    }
    sort(scor.begin(),scor.end());
    cout<<scor[scor.size()/2]<<endl;
}
