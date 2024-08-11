

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

struct TypeNode {
    string _type;
    string _name;
    long long _size;
    int _address;

    long long _memberN;
    long long _maxMemberSize;
    vector<long long> _memberList;
    vector<string> _memberName;
    map<string, long long> _memberMap;
};

int _numN = 0;
int _operType = 0;

vector<TypeNode> _typeList;
vector<TypeNode> _memTree;
long long _memNext = 0;

map<string, long long> _typeToIndexMap;
map<string, long long> _nameToIndexMap;

void Init () {
    TypeNode byteType;
    TypeNode shortType;
    TypeNode intType;
    TypeNode longType;

    byteType._type = "byte";
    shortType._type = "short";
    intType._type = "int";
    longType._type = "long";

    byteType._size = 1;
    shortType._size = 2;
    intType._size = 4;
    longType._size = 8;

    byteType._memberN = 0;
    shortType._memberN = 0;
    intType._memberN = 0;
    longType._memberN = 0;

    _typeList.push_back(byteType);
    _typeList.push_back(shortType);
    _typeList.push_back(intType);
    _typeList.push_back(longType);

    _typeToIndexMap.insert(make_pair("byte", 0));
    _typeToIndexMap.insert(make_pair("short", 1));
    _typeToIndexMap.insert(make_pair("int", 2));
    _typeToIndexMap.insert(make_pair("long", 3));
}

long long CreateObject (string curType, string curName, long long address) {
    // cout << curType << "," << curName << "," << address << endl;

    TypeNode curTypeNode;
    long long curTypeNodeIndex = _memTree.size();

    TypeNode oriTypeNode = _typeList[_typeToIndexMap[curType]];
    // cout << oriTypeNode._type << endl;

    string newObjectType = "Error";
    string newObjectName = "Error";
    long long newObjectAddress = 0;

    curTypeNode._type = curType;
    curTypeNode._name = curName;
    curTypeNode._size = oriTypeNode._size;
    curTypeNode._address = address;

    curTypeNode._memberN = oriTypeNode._memberN;
    curTypeNode._maxMemberSize = oriTypeNode._maxMemberSize;
    curTypeNode._memberName = oriTypeNode._memberName;

    _memTree.push_back(curTypeNode);

    for (int i = 0; i < curTypeNode._memberN; i++) {
        newObjectType = _typeList[oriTypeNode._memberList[i]]._type;
        newObjectName = curTypeNode._memberName[i];
        newObjectAddress = address + curTypeNode._maxMemberSize * i;

        // cout << "DEBUG:" << newObjectType << "," << newObjectName << "," << newObjectAddress << endl;

        curTypeNode._memberList.push_back(CreateObject(newObjectType, newObjectName, newObjectAddress));
        curTypeNode._memberMap.insert(make_pair(curTypeNode._memberName[i], curTypeNode._memberList[i]));
    }

    _memTree[curTypeNodeIndex] = curTypeNode;

    return curTypeNodeIndex;
}

long long Search (long long index, string target) {
    // cout << "target->" << target << endl;
    // cout << _memTree[index]._type << endl;

    string targetFather = "";
    string targetSon = "";
    int point = 0;

    for (int m = 0; m < target.length(); m++) {
        point = m;
        if (target[m] == '.') {
            break;
        }
    
        targetFather += target[m];
    }

    if (target.length() == 0) {
        return _memTree[index]._address;
    }

    for (int m = point + 1; m < target.length(); m++) {
        targetSon += target[m];
    }

    // cout << targetFather << endl;
    // cout << targetSon << endl;

    return Search(_memTree[index]._memberMap[targetFather], targetSon);
}


string SearchTwo (long long index, int address) {
    string curRes = "Error";
    string solo = "Error";

    if (address > _memTree[index]._address - 1 && address < _memTree[index]._address + _memTree[index]._size + 1) {
        if (_memTree[index]._memberN == 0) {
            return _memTree[index]._name;
        }

        for (int i = 0; i < _memTree[index]._memberN; i++) {
            solo = SearchTwo(_memTree[index]._memberList[i], address);

            if (solo != "ERR") {
                curRes = _memTree[index]._name + "." + solo;
                return curRes;
            }
        }

        return "ERR";
    }

    return "ERR";
}

void CCore () {
    TypeNode curType;
    long long curTypeIndex = 0;
    long long maxMemberSize = 0;
    
    string memberType = "Error";
    string memberName = "Error";

    string newType = "Error";
    string newName = "Error";

    string accessObject = "Error";
    string accessObjectFather = "";
    string accessObjectSon = "";
    int point = 0;

    long long accessAddress = 0;
    string curRes = "Error";

    Init();

    ifstream inFile("struct.in");

    inFile >> _numN;

    for (int i = 0; i < _numN; i++) {
        inFile >> _operType;

        if (_operType == 1) {
            inFile >> curType._type >> curType._memberN;

            curType._maxMemberSize = 0;
            curType._memberList.clear();
            curType._memberName.clear();
            curType._memberMap.clear();

            curTypeIndex = _typeList.size();
            _typeList.push_back(curType);

            _typeToIndexMap.insert(make_pair(curType._type, curTypeIndex));

            for (int m = 0; m < curType._memberN; m++) {
                inFile >> memberType >> memberName;

                curType._memberList.push_back(_typeToIndexMap[memberType]);
                curType._memberName.push_back(memberName);

                curType._memberMap.insert(make_pair(curType._memberName[m], curType._memberList[m]));
                
                curType._maxMemberSize = max(curType._maxMemberSize, _typeList[_typeToIndexMap[memberType]]._size);
                // cout << curType._memberName[m] << ",";
            }
            // cout << endl;

            curType._size = curType._maxMemberSize * curType._memberN;
            _typeList[curTypeIndex] = curType;

            cout << curType._size << " " << curType._maxMemberSize << endl;

            continue;
        }

        if (_operType == 2) {
            inFile >> newType >> newName;

            cout << _memNext << endl;
            _nameToIndexMap.insert(make_pair(newName, CreateObject(newType, newName, _memNext)));

            continue;
        }

        if (_operType == 3) {
            inFile >> accessObject;

            for (int m = 0; m < accessObject.length(); m++) {
                point = m;
                if (accessObject[m] == '.') {
                    break;
                }

                accessObjectFather += accessObject[m];
            }

            for (int m = point + 1; m < accessObject.length(); m++) {
                accessObjectSon += accessObject[m];
            }

            cout << Search(_nameToIndexMap[accessObjectFather], accessObjectSon) << endl;

            continue;
        }

        if (_operType == 4) {
            inFile >> accessAddress;

            for (int m = 0; m < _memTree.size(); m++) {
                curRes = SearchTwo(m, accessAddress);

                if (curRes != "ERR") {
                    break;
                }
            }

            cout << curRes << endl;
            continue;
        }
    }

    inFile.close();
}

void Core () {
    TypeNode curType;
    long long curTypeIndex = 0;
    long long maxMemberSize = 0;
    
    string memberType = "Error";
    string memberName = "Error";

    string newType = "Error";
    string newName = "Error";

    string accessObject = "Error";
    string accessObjectFather = "";
    string accessObjectSon = "";
    int point = 0;

    long long accessAddress = 0;
    string curRes = "Error";

    Init();

    ifstream inFile("struct.in");
    ofstream outFile("struct.out");

    inFile >> _numN;

    for (int i = 0; i < _numN; i++) {
        inFile >> _operType;

        if (_operType == 1) {
            inFile >> curType._type >> curType._memberN;

            curType._maxMemberSize = 0;
            curType._memberList.clear();
            curType._memberName.clear();
            curType._memberMap.clear();

            curTypeIndex = _typeList.size();
            _typeList.push_back(curType);

            _typeToIndexMap.insert(make_pair(curType._type, curTypeIndex));

            for (int m = 0; m < curType._memberN; m++) {
                inFile >> memberType >> memberName;

                curType._memberList.push_back(_typeToIndexMap[memberType]);
                curType._memberName.push_back(memberName);

                curType._memberMap.insert(make_pair(curType._memberName[m], curType._memberList[m]));
                
                curType._maxMemberSize = max(curType._maxMemberSize, _typeList[_typeToIndexMap[memberType]]._size);
                // cout << curType._memberName[m] << ",";
            }
            // cout << endl;

            curType._size = curType._maxMemberSize * curType._memberN;
            _typeList[curTypeIndex] = curType;

            outFile << curType._size << " " << curType._maxMemberSize << endl;

            continue;
        }

        if (_operType == 2) {
            inFile >> newType >> newName;

            outFile << _memNext << endl;
            _nameToIndexMap.insert(make_pair(newName, CreateObject(newType, newName, _memNext)));

            continue;
        }

        if (_operType == 3) {
            inFile >> accessObject;

            for (int m = 0; m < accessObject.length(); m++) {
                point = m;
                if (accessObject[m] == '.') {
                    break;
                }

                accessObjectFather += accessObject[m];
            }

            for (int m = point + 1; m < accessObject.length(); m++) {
                accessObjectSon += accessObject[m];
            }

            outFile << Search(_nameToIndexMap[accessObjectFather], accessObjectSon) << endl;

            continue;
        }

        if (_operType == 4) {
            inFile >> accessAddress;

            for (int m = 0; m < _memTree.size(); m++) {
                curRes = SearchTwo(m, accessAddress);

                if (curRes != "ERR") {
                    break;
                }
            }

            outFile << curRes << endl;
            continue;
        }
    }

    inFile.close();
    outFile.close();
}

int main () {
    // CCore();
    Core();

    return 0;
}