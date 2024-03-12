#include <iostream>

using namespace std;

void hanoi(int n, char from, char via, char to) {
    if (n == 1) {
        cout << "Sposto da " << from << " -> " << to << endl;
        return;
    }

    hanoi(n-1, from, to, via);
    hanoi(1, from, via, to);
    hanoi(n-1, via, from, to);
}

int main() {
    int N = 4;
    hanoi(N, 'A', 'B', 'C');
  
    return 0;
}
