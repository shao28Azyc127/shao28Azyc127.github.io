

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int _strN = 0;
int _strLength = 0;

vector<string> _oriList;
vector<string> _sortListOne;
vector<string> _sortListTwo;

vector<int> _resList;

string SortOne (string strOri) {
    int myHash[256] = {};
    string res = "";

    for (int i = 0; i < strOri.size(); i++) {
        myHash[(int) strOri[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        for (int m = 0; m < myHash[i]; m++) {
            res += (char) i;
        }
    }

    return res;
}

string SortTwo (string strOri) {
    int myHash[256] = {};
    string res = "";

    for (int i = 0; i < strOri.size(); i++) {
        myHash[(int) strOri[i]]++;
    }

    for (int i = 255; i > -1; i--) {
        for (int m = 0; m < myHash[i]; m++) {
            res += (char) i;
        }
    }

    return res;
}

void ParseIn () {
    string curStr = "Error";

    ifstream inFile("dict.in");

    inFile >> _strN >> _strLength;

    for (int i = 0; i < _strN; i++) {
        inFile >> curStr;
        _oriList.push_back(curStr);
        _sortListOne.push_back(SortOne(curStr));
        _sortListTwo.push_back(SortTwo(curStr));
    }

    inFile.close();
}

void Core () {
    string curStr = "Error";

    for (int i = 0; i < _strN; i++) {
        curStr = _sortListOne[i];
        _resList.push_back(1);

        for (int m = 0; m < _strN; m++) {
            if (i == m) {
                continue;
            }

            if (!(curStr < _sortListTwo[m])) {
                _resList[i] = 0;
                break;
            }
        }
    }
}

void WriteOut () {
    ofstream outFile("dict.out");

    for (int i = 0; i < _strN; i++) {
        outFile << _resList[i];
    }
    outFile << endl;

    outFile.close();
}

void CWriteOut () {
    for (int i = 0; i < _strN; i++) {
        cout << _resList[i];
    }
    cout << endl;
}

int main () {
    ParseIn();
    Core();
    // CWriteOut();
    WriteOut();

    return 0;
}