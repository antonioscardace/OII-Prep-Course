#include <fstream>
using namespace std;

int main() {
    ifstream in("input.txt");
    ofstream out("output.txt");

    for (int task = 0; task < 100; task++) {
        int N;
        in >> N;

        double result = 0;
        double minimo = 100;
        
        for (int i = 0; i < N; i++) {
            double tmp;
            in >> tmp;
            
            if (tmp < minimo) minimo = tmp;
            else if(tmp - minimo > result) result = tmp - minimo;
        }

        out << result << endl;
    }

    in.close();
    out.close();
    return 0;
}
