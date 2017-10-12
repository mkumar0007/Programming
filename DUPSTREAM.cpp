#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

char firstNonRepeating(string s) {
    int pos[256];
    fill_n(pos, sizeof(pos) / sizeof(int), -1);
    for (int i = 0; i < s.length(); ++i) {
        pos[s[i]] = (pos[s[i]] == -1) ? i : -1;
    }
    int m = -1;
    char c = '\0';
    for (int i = 0; i < 256; ++i) {
        if (pos[i] != -1 && (pos[i] < m || m == -1)) {
            m = pos[i];
            c = i;
        }
    }
    return c;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        cout << firstNonRepeating(string(argv[1])) << endl;
    }
    return 0;
}
