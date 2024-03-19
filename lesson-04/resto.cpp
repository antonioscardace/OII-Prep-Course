#include <fstream>
#include <vector>
#include <limits>

#define INF 2000

using namespace std;

int change(int r, int n, vector<int> t, vector<int>& memo) {
    if (r == 0)
        return 0;

    if (r < 0)
        return INF;

    if (memo[r] != -1)
        return memo[r];

    int min_coins = INF;
    for (int i = 0; i < n; i++)
        min_coins = min(change(r-t[i], n, t, memo) + 1, min_coins);

    memo[r] = min_coins;
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

        vector<int> memo(R + 1, -1);
        int res = change(R, N, t, memo);

        if (res < INF)
            out << res << endl;
        else 
            out << -1 << endl;
    }

    in.close();
    out.close();

    return 0;
}
