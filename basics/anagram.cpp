#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    string first,second,
    no_punc_1   ,no_punc_2;
    cout << "First string: ";
    getline(cin,first);
    cout << "Second string: ";
    getline(cin,second);
    // remove punctuation, spaces, and capitalization
    for (char c: first) {
        // if it's uppercase, make it lowercase and add it
        if('A' <= c and c <= 'Z') {
            c += 'a' - 'A'; // 'A' < 'a'
            no_punc_1 += c;
        }
        if( ('a' <= c and c <= 'z') or
            ('0'<= c and c <= '9') )
            no_punc_1 += c;
    }
    for (char c: second) {
        // if it's uppercase, make it lowercase and add it
        if ('A' <= c and c <= 'Z') {
            c += 'a' - 'A'; // 'A' < 'a'
            no_punc_2 += c;
        }
        if( ('a' <= c and c <= 'z') or
            ('0' <= c and c <= '9') ) 
            no_punc_2 += c;
    }
    sort(no_punc_1.begin(),no_punc_1.end());
    sort(no_punc_2.begin(),no_punc_2.end());
    
    cout << "they are ";
    if (no_punc_1 != no_punc_2)
        cout << "not ";
    cout << "anagrams" << endl;
}