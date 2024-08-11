

#include <iostream>
#include <fstream>
#include <set>

using namespace std;

struct Password {
    int _numArr[9];

    bool operator< (Password solo) const {
        for (int i = 1; i < 6; i++) {
            if (_numArr[i] != solo._numArr[i]) {
                return _numArr[i] < solo._numArr[i];
            }
        }

        return false;
    }
};

Password _passArr[9];

int _numN = 0;

int _res = 0;

set<Password> _passSetOne;
set<Password> _passSetTwo;

void PrintPass (Password solo) {
    for (int i = 0; i < 9; i++) {
        cout << solo._numArr[i] << ",";
    }
    cout << endl;
}

void GenPassSet () {
    Password curPass;
    Password nextPass;

    curPass = _passArr[1];
    nextPass = curPass;

    for (int i = 1; i < 6; i++) {
        for (int m = 1; m < 10; m++) {
            nextPass._numArr[i]++;
            nextPass._numArr[i] %= 10;

            _passSetOne.insert(nextPass);
            // PrintPass(nextPass);
        }

        nextPass._numArr[i]++;
        nextPass._numArr[i] %= 10;
    }

    for (int i = 1; i < 5; i++) {
        for (int m = 1; m < 10; m++) {
            nextPass._numArr[i]++;
            nextPass._numArr[i + 1]++;

            nextPass._numArr[i] %= 10;
            nextPass._numArr[i + 1] %= 10;

            _passSetOne.insert(nextPass);
            // PrintPass(nextPass);
        }

        nextPass._numArr[i]++;
        nextPass._numArr[i] %= 10;
        nextPass._numArr[i + 1]++;
        nextPass._numArr[i + 1] %= 10;
    }
}

void ParseIn () {
    ifstream inFile("lock.in");

    inFile >> _numN;

    for (int i = 1; i < _numN + 1; i++) {
        for (int m = 1; m < 6; m++) {
            inFile >> _passArr[i]._numArr[m];
        }
    }

    inFile.close();
}

void Core () {
    Password curPass;
    Password nextPass;

    GenPassSet();
    // cout << endl << endl;

    for (int i = 2; i < _numN + 1; i++) {
        curPass = _passArr[i];
        nextPass = curPass;

        if (i % 2 == 0) {
            _passSetTwo.clear();

            for (int i = 1; i < 6; i++) {
                for (int m = 1; m < 10; m++) {
                    nextPass._numArr[i]++;
                    nextPass._numArr[i] %= 10;

                    // PrintPass(nextPass);

                    if (_passSetOne.find(nextPass) != _passSetOne.end()) {
                        _passSetTwo.insert(nextPass);
                    }
                }

                nextPass._numArr[i]++;
                nextPass._numArr[i] %= 10;
            }

            for (int i = 1; i < 5; i++) {
                for (int m = 1; m < 10; m++) {
                    nextPass._numArr[i]++;
                    nextPass._numArr[i + 1]++;

                    nextPass._numArr[i] %= 10;
                    nextPass._numArr[i + 1] %= 10;

                    // PrintPass(nextPass);

                    if (_passSetOne.find(nextPass) != _passSetOne.end()) {
                        _passSetTwo.insert(nextPass);
                    }
                }

                nextPass._numArr[i]++;
                nextPass._numArr[i] %= 10;
                nextPass._numArr[i + 1]++;
                nextPass._numArr[i + 1] %= 10;
            }

            continue;
        }

        _passSetOne.clear();

        for (int i = 1; i < 6; i++) {
            for (int m = 1; m < 10; m++) {
                nextPass._numArr[i]++;
                nextPass._numArr[i] %= 10;

                if (_passSetTwo.find(nextPass) != _passSetTwo.end()) {
                    _passSetOne.insert(nextPass);
                }
            }

            nextPass._numArr[i]++;
            nextPass._numArr[i] %= 10;
        }

        for (int i = 1; i < 5; i++) {
            for (int m = 1; m < 10; m++) {
                nextPass._numArr[i]++;
                nextPass._numArr[i + 1]++;

                nextPass._numArr[i] %= 10;
                nextPass._numArr[i + 1] %= 10;

                if (_passSetTwo.find(nextPass) != _passSetTwo.end()) {
                    _passSetOne.insert(nextPass);
                }
            }

            nextPass._numArr[i]++;
            nextPass._numArr[i] %= 10;
            nextPass._numArr[i + 1]++;
            nextPass._numArr[i + 1] %= 10;
        }
        
    }

    if (_numN % 2 == 0) {
        _res = _passSetTwo.size();
        return;
    }

    _res = _passSetOne.size();
}

void CWriteOut () {
    cout << _res << endl;
}

void WriteOut () {
    ofstream outFile("lock.out");

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