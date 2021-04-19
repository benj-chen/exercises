#include <iostream>
using namespace std;
// What is the 10 001st prime number?
int main() {
    int num_primes_count=2; // start with 2 and 3 as a prime number
    int prime=-1;
    for (int i=5;num_primes_count<10001;i+=2) {
        for (int j=3;j<(i>>1);j+=2) {
            if (i%j==0) goto done;
        }
        num_primes_count++;
        prime=i;
        done:;
    }
    cout << prime << endl;
}