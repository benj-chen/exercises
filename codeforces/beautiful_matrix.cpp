#include <iostream>

int main() {
    bool find_one;
    int xdist=-3,ydist=-3;
    for (int i=1;i<6;i++) {
        for (int j=1;j<6;j++) {
            std::cin >> find_one;
            if (find_one) {
                xdist+=i;
                if (xdist < 0) xdist=-xdist;
                ydist+=j;
                if (ydist < 0) ydist=-ydist;
                std::cout << xdist + ydist << '\n';
                return 0;
            }
        }
    }
}