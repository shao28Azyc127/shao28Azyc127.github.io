

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXI = 1e5 + 9;

struct Challenge {
    int _day;
    int _last;
    int _reward;
};

int _testPoint = 0;
int _dataN = 0;

int _dayN = 0;
int _challengeN = 0;
int _limitN = 0;
int _energyN = 0;

Challenge _challengeArr[MAXI];

long long _dpTabOne[MAXI];
long long _dpTabTwo[MAXI];
long long _lastDay[MAXI];

vector<long long> _resList;

bool Compare (Challenge a, Challenge b) {
    return a._day < b._day;
}

void Core () {
    Challenge solo;

    ifstream inFile("run.in");

    inFile >> _testPoint >> _dataN;

    for (int i = 0; i < _dataN; i++) {
        memset(_dpTabOne, 0, sizeof(_dpTabOne));
        memset(_dpTabTwo, 0, sizeof(_dpTabTwo));
        memset(_lastDay, 0, sizeof(_lastDay));

        inFile >> _dayN >> _challengeN >> _limitN >> _energyN;

        for (int m = 1; m < _challengeN + 1; m++) {
            inFile >> solo._day >> solo._last >> solo._reward;
            _challengeArr[m] = solo;
        }

        sort(_challengeArr + 1, _challengeArr + _challengeN, Compare);

        for (int m = 1; m < _challengeN + 1; m++) {
            // cout << _challengeArr[m]._day << ",";
            for (int n = m - 1; n > -1 && _challengeArr[m]._day - _challengeArr[n]._day < _limitN + 1; n--) {
                // cout << m << "," << n << ":" << _lastDay[n] << endl;
                
                if (_challengeArr[m]._day - _challengeArr[n]._day > _limitN && _dpTabTwo[n] + _challengeArr[m]._reward - _energyN * _challengeArr[m]._last > _dpTabOne[m]) {
                    // cout << "->" << 1 << endl;
                    _dpTabOne[m] = _dpTabTwo[n] + _challengeArr[m]._reward - _energyN * _challengeArr[m]._last;
                    _lastDay[m] = _challengeArr[m]._last;
                }

                if (_lastDay[n] + _challengeArr[m]._day - _challengeArr[n]._day < _limitN + 1
                && _dpTabOne[n] + _challengeArr[m]._reward - _energyN * (_challengeArr[m]._day - _challengeArr[n]._day) > _dpTabOne[m]) {
                    // cout << "->" << 2 << endl;
                    _dpTabOne[m] = _dpTabOne[n] + _challengeArr[m]._reward - _energyN * (_challengeArr[m]._day - _challengeArr[n]._day);
                    _lastDay[m] = _lastDay[n] + _challengeArr[m]._day - _challengeArr[n]._day;
                }
            }

            _dpTabTwo[m] = max(_dpTabOne[m - 1], _dpTabTwo[m - 1]);

            // cout << _dpTabOne[m] << "," << _dpTabTwo[m] << endl;
        }

        _resList.push_back(max(_dpTabOne[_challengeN], _dpTabTwo[_challengeN]));
    }

    inFile.close();
}

void WriteOut () {
    ofstream outFile("run.out");

    for (int i = 0; i < _dataN; i++) {
        outFile << _resList[i] << endl;
    }

    outFile.close();
}

void CWriteOut () {
    for (int i = 0; i < _dataN; i++) {
        cout << _resList[i] << endl;
    }
}

int main () {
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}