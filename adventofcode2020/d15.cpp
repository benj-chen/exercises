#include <iostream>
#include <fstream>
#include <unordered_map> // significantly faster than map
#include <vector>
#include <string>
#include <utility>
using namespace std;
vector<int> INPUTS(1);
int INPUT_SIZE=1;
int solution(int n) {
    unordered_map<int,int> res;
    for (int i=0;i<INPUT_SIZE;i++) res.insert(make_pair(INPUTS[i],i));
    int to_consider=INPUTS.back();
    for (int i=INPUT_SIZE-1;i<n-1;i++) {
        int temp = (res.count(to_consider) ? i-res[to_consider]:0);
        res[to_consider]=i;
        to_consider=temp;
    }
    
    return to_consider;
}
int main() {
    ifstream fin("i15");
    string input;
    fin >> input;
    for (char c: input) {
        if (c==',') {INPUTS.push_back(0);INPUT_SIZE++;}
        else INPUTS.back()=INPUTS.back()*10+c-'0';
    }
    fin.close();
    cout << solution(2020) << endl << solution(30000000) << endl;
}