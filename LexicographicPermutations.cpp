#include <iostream>
#include <vector>
using namespace std;

/* Recursive factorial helper function.
 * Performance isn't as good as other 
 * implementations, but we're only calculating
 * 9!, so I'm willing to forego performance for
 * simplicity.
 */ 
int factorial(int n) {
    if (n == 1 || n == 0) return 1;
    else return n * factorial(n - 1);
}

/* Given a list of ordered digits, and an index of which
 * permutation should be returned, returns that lexicographic
 * permutation.
 * 
 * Ex. {0, 1, 2}, 6 -> "210"
 * 
 * To find the first digit, integer-divide the 0-index by the
 * factorial (one less than the size of the vector).  Just like
 * an odometer, you'll need to "roll over" that many times to
 * get to the desired index.  Add the digit at this index to
 * answer, then erase that index from the vector since it's been
 * used.
 * 
 * The remainder of the division becomes the new index, then
 * the process is repeated until the remainder is 0.
 * 
 * If there are still digits left in the vector, add them
 * in order to the answer.
 */
string indexPermutation(vector<int> perms, int index) {
    index;
    string ans = "";
    int r = index - 1; // Convert to 0-based indexing
    int f = perms.size() - 1; // the first factorial
    do {
        int thisFactorial = factorial(f--);
        int thisIndex = r / thisFactorial;
        ans += perms[thisIndex] + '0'; // ASCII conversion
        perms.erase(perms.begin() + thisIndex);
        r %= thisFactorial;
    } while (r != 0);
    while (perms.size() > 0) {
        ans += perms[0] + '0'; // ASCII conversion
        perms.erase(perms.begin());
    }
    return ans;
}

int main() {
    vector<int> perms {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    cout << indexPermutation(perms, 1000000) << endl;
    return 0;
}
