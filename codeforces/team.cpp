#include <iostream>
int main() {
    int n,sum=0,sumprob; // input problem #, total problems done, sum of the problem
    std::cin >> n;
    bool gb; // good/bad, whether someone is sure of the sol or not.
    for (int i=0;i<n;i++) {
        sumprob=0;
        for (int j=0;j<3;j++) {
            std::cin >> gb;
            if (gb) sumprob++;
        }
        if (sumprob>1) sum++;
    }
    std::cout << sum << '\n';
}