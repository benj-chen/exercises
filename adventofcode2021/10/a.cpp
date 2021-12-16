#include <map>
#include <stack>
#include <iostream>
using namespace std;

int main() {
    map<char, int> scores {
        {')',3},
        {']',57},
        {'}',1197},
        {'>',25137}
    }, opp {
        {')', '('},
        {']', '['},
        {'}', '{'},
        {'>', '<'}
    };
    string s;
    int score = 0;
    while (cin>>s) {
        stack<int> q;
        for (char c: s) {
            switch(c) {
                case '(': case '[': case '{': case '<':
                q.push(c);
                break;
                case ')': case ']': case '}': case '>':
                
                if (q.top()!=opp[c]) {
                    score += scores[c];
                    goto end;
                }
                q.pop();
            }
        }
        end:;
    }
    cout << score << endl;
}