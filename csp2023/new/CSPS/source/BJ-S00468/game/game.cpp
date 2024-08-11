

#include <bits/stdc++.h>

using namespace std;

char _myStr[2000009];
int _res;
int _num;

bool CanDel () {
    for (int i = 1; i < _num; i++) {
        if (_myStr[i] == _myStr[i - 1]) {
            return true;
        }
    }
    return false;
}

void Delete (int kai) {
    for (int i = kai + 1; i < _num; i++) {
        _myStr[i - 1] = _myStr[i];
    }
    for (int i = kai + 1; i < _num - 1; i++) {
        _myStr[i - 1] = _myStr[i];
    }
    _num -= 2;
}

void ParseIn () {
    freopen("game.in", "r", stdin);
    cin >> _num >> _myStr;
    _num++;
}

void Core () {
    int solo;
    int yuan = _num;
    while (CanDel()) {
        for (int i = 1; i < _num; i++) {
            if (_myStr[i] == _myStr[i - 1]) {
                Delete(i - 1);
                solo += 2;
                _res++;
            }
        }
    }
    if (solo == yuan - 1) {
        _res++;
    }
}

void WriteOut () {
    freopen("game.out", "w", stdout);
    cout << _res << endl;
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
