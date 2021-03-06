#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream F;
    F.open("./F");

    fstream G;
    G.open("G", fstream::out);

    if (!F.is_open() || !G.is_open()) return -1;

    string line;
    while (getline(F, line)) {
        for (auto i = line.length() - 1; i >= 0 && i < line.length(); i--) {
            auto c = line[i];
            switch (c) {
                case 'e':
                case 'E':
                case 'r':
                case 't':
                case 'U':
                    break;
                default:
                    G << c;
            }
        }
        G << endl;
    }
    G.close();
    F.close();

    G.open("G", fstream::in);
    F.open("F", fstream::in);

    cout << "[[F file]]" << endl;
    cout << F.rdbuf() << endl;

    cout << "[[G file]]" << endl;
    cout << G.rdbuf() << endl;

    F.close();
    G.close();

    return 0;
}
