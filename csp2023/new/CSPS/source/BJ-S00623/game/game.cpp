

#include <iostream>
#include <fstream>

using namespace std;

const int MAXI = 2e6 + 9;

int _lenN = 0;
string _myStr = "Error";

char _myStack[MAXI];
int _stackTop = 0;

long long _res = 0;

void ParseIn () {
    ifstream inFile("game.in");

    inFile >> _lenN;
    inFile >> _myStr;

    inFile.close();
}

void Core () {
    for (int i = 0; i < _lenN; i++) {
        for (int m = i; m < _lenN; m++) {
            _stackTop = 0;

            for (int n = i; n < m + 1; n++) {
                _myStack[_stackTop] = _myStr[n];
                _stackTop++;

                while (_stackTop > 1 && _myStack[_stackTop - 1] == _myStack[_stackTop - 2]) {
                    _stackTop -= 2;
                }
            }

            if (_stackTop == 0) {
                _res++;
            }
        }
    }
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("game.out");

    outFile << _res << endl;

    outFile.close();
}

int main () {
    ParseIn();
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}