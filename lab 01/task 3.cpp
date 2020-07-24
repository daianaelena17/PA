#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result(n, x, y));
    }

private:
    int n, x, y;

    void read_input() {
        ifstream fin("in");
        fin >> n >> x >> y;
        fin.close();
    }

    int get_result(int n, int x, int y) {
        /*
        TODO: Calculati valoarea de pe pozitia (x, y) din matricea de dimensiune
        2^n x 2^n
        */
        // Am folosit modelul matricii Morton. Indexarea in matricea Morton se
        // face de la zero, pe cand problema o face de la 1. scad x si y cu o unitate
        x--;
        y--;

      // std::bitset<8> q(x);
      // std::bitset<8> r(y);
      // cout << q << " " << r << '\n';

    unsigned long long x_y_copy = 0;
   // matricea Morton implica faptul ca elementul de pe pozitia (x, y) are valoarea
   // intrepatrunderii bitilor coordonatelor. x = 01 si y = 01 atunci pe poz (x, y)
   // este elementul 0011 adica 3 (folosind intentarea de la 0 a elementelor din matrice)
    for (int i = 31; i >= 0; i--) {
        int mort = 0;
        int xbit = ((unsigned long) x) & (1 << i);
        mort = (mort |= xbit) << i+1;
        x_y_copy|= mort;
        mort = 0;
        int ybit = ((unsigned long) y) & (1 << i);
        mort = (mort |= ybit) << i;
        x_y_copy |= mort;
    }
    // std::bitset<16> s(x_y_copy);
    // cout << s << " ";

        return (int) x_y_copy + 1; // morton incepe de la 0. problema de fata incepe cu 1
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
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
