#include <fstream>
#include <vector>
#include <limits>

using namespace std;

int change(int r, int n, vector<int> t) {
    vector<int> memo(r+1, numeric_limits<int>::max());
    memo[0] = 0;

    for (int i = 1; i <= r; i++) 
        for (int j = 0; j < n; j++) 
            if (i - t[j] >= 0) 
                memo[i] = min(memo[i], memo[i - t[j]] + 1);

    return memo[r];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {
        int R;
        int N;

        in >> R >> N;

        vector<int> t(N);
        for (int i = 0; i < N; i++)
            in >> t[i];

        int res = change(R, N, t);
        out << (res < numeric_limits<int>::max() ? res : -1) << endl;
    }

    in.close();
    out.close();

    return 0;
}
