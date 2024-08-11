

#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

const int MAXI = 1e5 + 9;

struct Variable {
    string _type; // "value" or "oper"
    int _timeStamp;

    char _value;

    char _oper;
    int _from;
};

int _testPoint = 0;
int _dataN = 0;

int _varN = 0;
int _operN = 0;

Variable _varArr[MAXI];

vector<int> _resList;

vector<int> _graphRev[MAXI];
set<int> _mySet;
queue<int> _updateQueue;

bool _myHash[MAXI];
int _dfn[MAXI];
int _low[MAXI];

int _curTime = 0;

int _myStack[MAXI];
bool _inStack[MAXI];
int _stackTop = 0;

int _sccN = 0;
vector<int> _sccList[MAXI];

// void Merge (int curVar) {
//     // cout << curVar << ":" << endl;
//     if (_varArr[curVar]._type != "oper" || _varArr[_varArr[curVar]._from]._type == "") {
//         return;
//     }

//     if (_varArr[curVar]._oper == '+') {
//         // cout << "EXIT:" << curVar << endl;
//         _varArr[curVar] = _varArr[_varArr[curVar]._from];
//         return;
//     }

//     if (_varArr[_varArr[curVar]._from]._type == "value") {
//         _varArr[curVar] = _varArr[_varArr[curVar]._from];

//         if (_varArr[curVar]._value == 'T') {
//             _varArr[curVar]._value = 'F';
//             return;
//         }
//         if (_varArr[curVar]._value == 'F') {
//             _varArr[curVar]._value = 'Y';
//             return;
//         }
//         return;
//     }

//     _varArr[curVar] = _varArr[_varArr[curVar]._from];
//     if (_varArr[curVar]._oper == '+') {
//         _varArr[curVar]._oper = '-';
//         return;
//     }
//     if (_varArr[curVar]._oper == '-') {
//         _varArr[curVar]._oper = '+';
//         return;
//     }
// }

int Search (int node) {
    int curRes = 1;

    if (_myHash[node]) {
        return 0;
    }

    for (int i = 0; i < _graphRev[node].size(); i++) {
        curRes += Search(_graphRev[node][i]);
    }

    return curRes;
}

void Tarjan (int node) {
    _myHash[node] = true;
    _dfn[node] = _curTime;
    _low[node] = _curTime;
    _curTime++;

    _myStack[_stackTop] = node;
    _stackTop++;
    _inStack[node] = true;

    int to = 0;

    for (int i = 0; i < _graphRev[node].size(); i++) {
        to = _graphRev[node][i];
        // cout << "->" << node << "," << to << endl;

        if (!_myHash[to]) {
            Tarjan(to);
            _low[node] = min(_low[node], _low[to]);
        }

        if (_inStack[to]) {
            _low[node] = min(_low[node], _dfn[to]);
        }
    }

    if (_dfn[node] == _low[node]) {
        _sccN++;
        // cout << node << endl;

        while (_inStack[node]) {
            _stackTop--;
            _inStack[_myStack[_stackTop]] = false;

            _sccList[_sccN].push_back(_myStack[_stackTop]);
        }
    }
}

void Core () {
    char oper = 'E';
    int curIntOne = 0;
    int curIntTwo = 0;

    int curRes = 0;

    bool flag = false;

    int curNode = 0;
    int sccSize = 0;
    int multi = 1;

    ifstream inFile("tribool.in");

    inFile >> _testPoint >> _dataN;

    for (int i = 0; i < _dataN; i++) {
        // cout << "DATA:" << i << endl;

        inFile >> _varN >> _operN;

        curRes = 0;
        _sccN = 0;
        memset(_varArr, 0, sizeof(_varArr));
        memset(_myHash, 0, sizeof(_myHash));
        
        for (int m = 1; m < _varN + 1; m++) {
            _graphRev[m].clear();
            _sccList[m].clear();
        }

        _mySet.clear();

        for (int m = 0; m < _operN; m++) {
            inFile >> oper;

            switch (oper) {
                case 'T':
                    inFile >> curIntOne;

                    _varArr[curIntOne]._type = "value";
                    _varArr[curIntOne]._timeStamp = m;
                    _varArr[curIntOne]._value = 'T';

                    break;

                case 'F':
                    inFile >> curIntOne;

                    _varArr[curIntOne]._type = "value";
                    _varArr[curIntOne]._timeStamp = m;
                    _varArr[curIntOne]._value = 'F';

                    break;

                case 'U':
                    inFile >> curIntOne;

                    _varArr[curIntOne]._type = "value";
                    _varArr[curIntOne]._timeStamp = m;
                    _varArr[curIntOne]._value = 'U';

                    break;

                case '+':
                    inFile >> curIntOne >> curIntTwo;

                    _varArr[curIntOne]._type = "oper";
                    _varArr[curIntOne]._timeStamp = m;
                    _varArr[curIntOne]._oper = '+';
                    _varArr[curIntOne]._from = curIntTwo;

                    // Merge(curIntOne);

                    break;

                case '-':
                    inFile >> curIntOne >> curIntTwo;

                    _varArr[curIntOne]._type = "oper";
                    _varArr[curIntOne]._timeStamp = m;
                    _varArr[curIntOne]._oper = '-';
                    _varArr[curIntOne]._from = curIntTwo;

                    // Merge(curIntOne);

                    break;
            }
        }

        for (int m = 0; m < _varN + 1; m++) {
            if (_varArr[m]._type == "oper") {
                _graphRev[_varArr[m]._from].push_back(m);
            }
        }

        // cout << "TEST" << endl;


        // for (int m = 1; m < _varN + 1; m++) {
        //     if (_varArr[m]._type == "value" && _varArr[m]._value != 'U') {
        //         _updateQueue.push(m);
        //     }

        //     if (_varArr[m]._type == "") {
        //         curRes--;
        //     }
        // }

        // while (!_updateQueue.empty()) {
        //     if (_myHash[_updateQueue.front()]) {
        //         _updateQueue.pop();
        //         continue;
        //     }
        //     _myHash[_updateQueue.front()] = true;

        //     curRes--;
            
        //     for (int m = 0; m < _graphRev[_updateQueue.front()].size(); m++) {
        //         _updateQueue.push(_graphRev[_updateQueue.front()][m]);
        //     }

        //     _updateQueue.pop();
        // }

        for (int m = 1; m < _varN + 1; m++) {
            if (_varArr[m]._type == "value" && _varArr[m]._value == 'U') {
                curRes += Search(m);
            }

            if (!_myHash[m]) {
                Tarjan(m);
            }
        }

        // cout << "TEST" << endl;

        for (int m = 1; m < _sccN + 1; m++) {
            multi = 1;
            for (int n = 0; n < _sccList[m].size(); n++) {
                // cout << _sccList[m][n] << ",";
                if (_varArr[_sccList[m][n]]._type == "oper" && _varArr[_sccList[m][n]]._oper == '-') {
                    multi *= -1;
                }
            }

            if (multi == -1) {
                curRes += _sccList[m].size();
            }

            // cout << endl;
        }

        _resList.push_back(curRes);

        // for (int i = 1; i < _varN + 1; i++) {
        //     // cout << _varArr[i]._type << "," << _varArr[i]._value << "," << _varArr[i]._oper << "," << _varArr[i]._from << endl;
        //     if (_mySet.find(i) != _mySet.end()) {
        //         // cout << "CONTINUE!" << endl;
        //         continue;
        //     }

        //     if (_varArr[i]._type == "oper" && _varArr[i]._oper == '-' && _varArr[i]._from == i) {
        //         _varArr[i]._type = "value";
        //         _varArr[i]._value = 'U';
                
        //         // for (int m = 0; m < _graphRev[i].size(); m++) {
        //         //     _mySet.insert(_graphRev[i][m]);
        //         //     curRes++;
        //         // }

        //         curRes += Search(i);

        //         continue;
        //     }

        //     if (_varArr[i]._type == "value" && _varArr[i]._value == 'U') {
        //         // _mySet.insert(i);

        //         // for (int m = 0; m < _graphRev[i].size(); m++) {
        //         //     _mySet.insert(_graphRev[i][m]);
        //         //     curRes++;
        //         // }

        //         curRes += Search(i);

        //         continue;
        //     }
        // }

        // // cout << endl;
    }

    inFile.close();
}

void WriteOut () {
    ofstream outFile("tribool.out");

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