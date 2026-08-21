#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    // Read the score from the contestant's output
    double minScore = ouf.readDouble(0.0, 1.0, "score");
    string s = ouf.readString();

    // 1. Check for Perfect Score with Buffer
    if (minScore >= 1.0 - EPS) {
        quitf(_ok, "Perfect score! (%.10f) Message: %s", minScore, s.c_str());
    }
    
    // 2. Check for Zero Score (Negative or extremely small)
    if (minScore <= EPS) {
        quitf(_wa, "Zero score or invalid: %.10f", minScore);
    }

    // 3. Otherwise, return Partial Credit
    // quitp is used for scores strictly between 0 and 1
    quitp(minScore * 100, "Partial credit awarded: %.10f", minScore);

    return 0;
}