#include <iostream>
#include <string>
using namespace std;
using str = string;
int main() {
    int T;
    cin >> T;
    while (T--) {
        int A,B,N;
        cin >> A >> B >> N;
        B--;
        str in;
        
        while (in!="CORRECT" && N--) {
            int md= (A+B)/2;
            cout << md << endl;
            cin >> in;
            if (in=="TOO_SMALL") A=md;
            else B=md;
        }
    }
}