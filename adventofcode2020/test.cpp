#include <iostream>
#include <vector>
using namespace std;
bool isIn(vector<int> &c, int &target)
{
    for (int &i: c)
    {
        if (i==target) return true;
    }
    return false;
}
bool hasRepeats(vector<int> &vec) {
    vector<int> vecc;
    for (int i: vec) {
        if (isIn(vecc,i)) return true;
        vecc.push_back(i);
    }
    return false;
}
int main() {
    cout << x;
    int len;
    cin >> len;
    int n;
    int trace,rows,columns;
    for (int g=1;g<=len;g++)
    {
        cin >> n;
        vector< vector<int> > matr(n);
        vector<int> vec(n);
        trace=0;
        rows=0;
        columns=0;        
        for (int i=0;i<n;i++) {
            for (int j=0;j<n;j++) cin >> vec[j];
            matr[i]=vec;
        }

        for (int i=0;i<n;i++){
            trace+=matr[i][i]; //trace
            rows+=hasRepeats(matr[i]); //rows
            for (int j=0;j<n;j++) vec[j]=matr[j][i]; //col
            columns+=hasRepeats(vec); //col
        }
        cout << "Case #" << g << ": " << trace << " "
        << rows << " " << columns << "\n";
    }
}