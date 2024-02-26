#include <fstream>

using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 1; task <= 100; task++) {
        int N;
        int M;
        int K;
        in >> N >> M >> K;

        int D[N+1];
        for (int i = 0; i < N; i++)
            in >> D[i];

        int last = 0;
        int cnt = 0;

        D[N] = K;
        for (int i = 0; i < N; i++) {
            if (D[i+1] > last + M) {
                last = D[i];
                cnt++;
            }
        }

        out << cnt << endl;
    }

    in.close();
    out.close();

    return 0;
}
