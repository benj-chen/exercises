#include <fstream>
int main() {
    int n,q,a,b,ghj[4];
    std::ifstream in("bcount.in");
    in >> n >> q;
    int nn[n];
    for (int i=0;i<n;i++) in >> nn[i];
    std::ofstream out("bcount.out");
    for (int i=0;i<q;i++) {
        ghj[1]=0;ghj[2]=0;ghj[3]=0;
        in >> a >> b;
        for (a--;a<b;a++) ghj[nn[a]]++;
        out << ghj[1] << ' ' << ghj[2] << ' ' << ghj[3] << '\n';
    }
}