#include <fstream>
using namespace std;
int main() {
    int a,b,c,d;
    ifstream fin("paint.in");
    fin >> a >> b >> c >> d;
    fin.close();
    ofstream fout("paint.out");
    fout << (a<=c && b>=c || (c<=a && d>=a) ? 
    (b>d? b:d) - (a<c? a:c) // max and min
    :
    b-a+d-c);
}