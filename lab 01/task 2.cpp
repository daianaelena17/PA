#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(compute_sqrt());
    }

private:
    double n;

    void read_input() {
        ifstream fin("in");
        fin >> n;
        fin.close();
    }

    double compute_sqrt() {
        /*
        TODO: Calculati sqrt(n) cu o precizie de 0.001
        Precizie de 10^-x = |rezultatul vostru - rezultatul corect| <= 10^-x
        */
        if (n == 0 || n == 1) {
          return n;
        }
        double debut = 0.0, fin = n, resultat, mid;
        
        if (n < 1) {
          fin = 1.0;
        }

        while (debut <= fin) {
          mid = (debut + fin) * 0.5;
          if (mid * mid > n - 0.0001 && mid * mid < n + 0.001)
            return mid;
          if (mid * mid < n) {
            debut = mid + 0.0001;
          } else {
            fin = mid - 0.0001;
          }
        }

            return 0.0;
    }

    void print_output(double result) {
        ofstream fout("out");
        fout << setprecision(4) << fixed << result;
        fout.close();
    }
};

// Please always keep this simple main function!
int main() {
    // Allocate a Task object on heap in order to be able to
    // declare huge static-allocated data structures inside the class.
    Task *task = new Task();
    task->solve();
    delete task;
    return 0;
}
