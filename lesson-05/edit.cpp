#include <fstream>
#include <string>

using namespace std;

int edit(string x, string y, int n, int m) {
    int memo[n+1][m+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {

            if (i == 0) memo[i][j] = j;
            else if (j == 0) memo[i][j] = i;
            else if (x[i-1] == y[j-1]) memo[i][j] = memo[i-1][j-1];
            else memo[i][j] = 1 + min(memo[i-1][j], min(memo[i][j-1], memo[i-1][j-1]));
        }
    }

    return memo[n][m];
}

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {
        int N;
        int M;
        string X;
        string Y;

        in >> N >> M;
        in >> X >> Y;

        out << edit(X, Y, N, M) << endl;
    }

    in.close();
    out.close();

    return 0;
}
