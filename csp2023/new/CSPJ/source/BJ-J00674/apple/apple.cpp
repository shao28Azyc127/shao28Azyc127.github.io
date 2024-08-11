

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 9;
int _vis[N];
int _num;
int _all;

void ParseIn () {

    ifstream inFile("apple.in");
//    freopen("apple.in", "r", stdin);

    inFile >> _num;

    inFile.close();
}

void Core () {
    int have;//yong you
    int kai = 1;//kai
    while (have < _num) {
        _all++;
        while (_vis[kai] == 1 && kai < _num) {
             kai++;
        }
        int cnt = 1;
        _vis[kai] = _all;
        have++;
        for (int i = kai; i < _num + 1; i++) {
            if (_vis[i] == 0 && cnt < 4) {
                cnt++;
            }
            if (_vis[i] == 0 && cnt == 4) {
                cnt = 1;
                have++;
                _vis[i] = _all;
            }
        }
        kai++;
    }
    if (!_vis[_num]) {
        _vis[_num] = _all;
    }
}

void WriteOut () {

    ofstream outFile("apple.out");
    //freopen("apple.out", "w", stdout);
    outFile << _all << ' ' << _vis[_num] << endl;

    outFile.close();
}

int main () {

    ParseIn();
    Core();
    WriteOut();

    return 0;
}
