#include <iostream>
using namespace std;
int main() {
    string s;
    int ct=0;
    while (cin>>s) {
        // ignore 10 more times, including the delimiter
        for (int i=0;i<10;i++) cin>>s;
        for (int i=0;i<4;i++) {
            cin>>s;
            switch(s.size()) {
                case 2: case 3: case 4: case 7: ct++;
            }
        }
    }
    cout<<ct<<endl;
}