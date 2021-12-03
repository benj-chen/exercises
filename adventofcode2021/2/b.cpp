#include <iostream>
using namespace std;
int main() {
    string s;
    int in,x=0,y=0,aim=0;
    while (cin>>s>>in) {
        if (s=="forward") {
            x+=in;
            y+=aim*in;
        }
        else if (s=="down")
            aim+=in;
        else if (s=="up")
            aim-=in;
    }
    cout << x*y << endl;
}