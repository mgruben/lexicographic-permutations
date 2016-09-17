#include <iostream>
#include <vector>
#include <string>
using namespace std;

int factorial(int n) {
    if (n == 1 || n == 0) return 1;
    else return n * factorial(n - 1);
}

string indexPermutation(vector<int> perms, int index) {
    index--;
    string ans = "";
    int r = index;
    int f = perms.size() - 1;
    do {
        int thisFactorial = factorial(f--);
        int thisIndex = r / thisFactorial;
        ans += perms[thisIndex] + 48;
        perms.erase(perms.begin() + thisIndex);
        r %= thisFactorial;
    } while (r != 0);
    while (perms.size() > 0) {
        ans += perms[0] + 48;
        perms.erase(perms.begin());
    }
    return ans;
}

int main() {
    vector<int> perms {0, 1, 2};
    for (int i = 1; i <= 6; i++)
    cout << indexPermutation(perms, i) << endl;
    return 0;
}
