#include "testlib.h"

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char *argv[]) {
	registerTestlibCmd(argc, argv);

	int N = inf.readInt();
	
	int P = ouf.readInt();
	int px = ouf.readInt();
	
	int J = ans.readInt();
	int jx = ans.readInt();

	if (J < 0) {
		if (J == -1) quitf(_fail, "jury X.size() = %d != N = %d", jx, N);
		if (J == -2) quitf(_fail, "jury X[%d] <= 0", jx);
		if (J == -3) quitf(_fail, "jury only %d citizens left, N = %d", jx, N);
		if (J == -4) quitf(_fail, "jury %d citizens left in one turn", jx);
		if (J == -5) quitf(_fail, "jury order is wrong (vertex %d)", jx);
	}
	if (P < 0) {
		if (P == -1) quitf(_wa, "X.size() = %d != N = %d", px, N);
		if (P == -2) quitf(_wa, "X[%d] <= 0", px);
		if (P == -3) quitf(_wa, "only %d citizens left, N = %d", px, N);
		if (P == -4) quitf(_wa, "%d citizens left in one turn", px);
		if (P == -5) quitf(_wa, "order is wrong (vertex %d)", px);
	}

	int D = P - J;
	if (D <= 0) quitf(_ok, "correct");
	else if (D == 1) quitp(0.8 * 100, "D = 1");
	else if (D == 2) quitp(0.6 * 100, "D = 2");
	else if (3 <= D && D <= N) quitp(1.0 / (D - 1) * 100, "D = %d", D);
	else quitf(_wa, "D = %d > N = %d", D, N);

	return 0;
}