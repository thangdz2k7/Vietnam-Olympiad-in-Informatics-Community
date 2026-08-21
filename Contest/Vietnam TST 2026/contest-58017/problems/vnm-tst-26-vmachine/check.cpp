#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);

    if (ouf.seekEof()) {
        quitf(_pe, "no output");
    }

    string first = ouf.readWord();

    if (first == "Accepted") {
      ouf.readSpace();
      int ops = ouf.readInt(0, (int)4e6, "maxOP");
        if (!ouf.seekEof()) {
            quitf(_pe, "extra output after accepted message");
        }
        quitf(_ok, "maximum operations = %lld", ops);
    }

    if (first == "Wrong") {
        string second = ouf.readWord();
        if (second != "answer") {
            quitf(_pe, "unexpected output format");
        }

        string msg;
        while (!ouf.seekEof()) {
            string token = ouf.readWord();
            if (!msg.empty()) msg += ' ';
            msg += token;
        }

        if (msg.empty()) msg = "(no message)";
        quitf(_wa, "%s", msg.c_str());
    }

    quitf(_pe, "unexpected output format");
}