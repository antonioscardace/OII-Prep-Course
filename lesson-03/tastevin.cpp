#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int f(int n, vector<int> g, int i, int last) {
    if (i >= n)
        return 0;

    if (g[i] >= last) 
        return max(f(n, g, i+2, g[i]) + 1, f(n, g, i+1, last));

    return f(n, g, i+1, last);
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {

        int n;
        in >> n;

        vector<int> g(n);

        for (int i = 0; i < n; i++)
            in >> g[i];

        out << f(n, g, 0, 0) << endl;
    }

    in.close();
    out.close();

    return 0;
}
