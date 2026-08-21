#include "testlib.h"
#include <vector>
#include <cmath>

using namespace std;

// Computes (a^b) % mod efficiently using binary exponentiation
long long power_mod(long long a, long long b, long long mod) {
    long long result = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) result = (result * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return result;
}

// Calculates i^i % mod
long long calculate_i_power_i(long long i, long long mod) {
    return power_mod(i, i, mod);
}

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    int n = inf.readInt();  // Read N from the input file
    int m = ouf.readInt();  // Read M from the contestant's output

    // Check if M is within the allowed range
    if (m < 0 || m > 4e5) {
        quitf(_wa, "Number of operations M = %d is out of range [0, 4 * 10^5]", m);
    }

    // Calculate Q = M/N for scoring
    double q = static_cast<double>(m) / n;

    // Calculate score based on the given formula
    double score;
    if (q > 20) {
        score = 0.0;
    } else if (q > 5) {
        score = pow(0.9, q - 4);
    } else {
        score = 1.0;
    }

    // Use multiple modulos to increase reliability of checks
    // Using different prime modulos reduces the chance of false positives
    const vector<long long> mods = {1000000007, 1000000009, 998244353};

    // Initialize arrays A for each modulo with all 1's
    vector<vector<long long>> A(mods.size(), vector<long long>(n + 1, 1));

    // Simulate the operations from the contestant's output
    for (int i = 0; i < m; i++) {
        string op = ouf.readToken();
        int x = ouf.readInt();
        int y = ouf.readInt();
        int k = ouf.readInt();

        // Check if indices are valid
        if (x < 1 || x > n || y < 1 || y > n || k < 1 || k > n) {
            quitf(_wa, "Indices in operation %d are out of range", i + 1);
        }

        // Perform the operation for each modulo
        for (size_t j = 0; j < mods.size(); j++) {
            if (op == "+") {
                A[j][k] = (A[j][x] + A[j][y]) % mods[j];
            } else if (op == "*") {
                A[j][k] = (A[j][x] * A[j][y]) % mods[j];
            } else {
                quitf(_wa, "Unknown operation '%s' in line %d", op.c_str(), i + 1);
            }
        }
    }

    // Check for extra data in the output
    if (!ouf.seekEof()) {
        quitf(_wa, "Extra data in output");
    }

    // Verify the final state of array A against the expected values
    for (int i = 1; i <= n; i++) {
        for (size_t j = 0; j < mods.size(); j++) {
            long long expected = calculate_i_power_i(i, mods[j]);
            if (A[j][i] != expected) {
                quitf(_wa, "A[%d] is not equal to %d^%d (checking with modulo %lld)",
                      i, i, i, mods[j]);
            }
        }
    }

    // Return the contestant's score
    quitp(score * 100.0, "Score: %.6f", score);
}

