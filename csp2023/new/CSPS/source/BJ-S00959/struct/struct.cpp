// rui_er is kawaii!!!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#ifndef RUIER
ifstream fin("struct.in");
ofstream fout("struct.out");
#define cin fin
#define cout fout
#endif

const ll N = 105;

ll n, addressPointer;

struct Type {
    bool isBasic;
    string typeName;
    ll size, required;
    unordered_map<string, tuple<string, ll>> elements; // {elementName, {elementTypeName, addressShift}}
    vector<tuple<ll, string, string>> orderedElements; // {addressShift, elementTypeName, elementName}
    Type() = default;
};

unordered_map<string, Type> typeDetails; // {typeName, type}

struct Variable {
    string typeName, variableName;
    ll addressHead, addressTail;
};

unordered_map<string, Variable> variableDetails; // {variableName, variable}
vector<tuple<ll, string>> orderedVariables; // {addressHead, variableName}

void initBasicTypes() {
    Type typeByte;
    typeByte.isBasic = true;
    typeByte.typeName = "byte";
    typeByte.size = typeByte.required = 1;
    typeDetails[typeByte.typeName] = typeByte;
    Type typeShort;
    typeShort.isBasic = true;
    typeShort.typeName = "short";
    typeShort.size = typeShort.required = 2;
    typeDetails[typeShort.typeName] = typeShort;
    Type typeInt;
    typeInt.isBasic = true;
    typeInt.typeName = "int";
    typeInt.size = typeInt.required = 4;
    typeDetails[typeInt.typeName] = typeInt;
    Type typeLong;
    typeLong.isBasic = true;
    typeLong.typeName = "long";
    typeLong.size = typeLong.required = 8;
    typeDetails[typeLong.typeName] = typeLong;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    initBasicTypes();
    cin >> n;
    for(ll _ = 1; _ <= n; ++_) {
        // cerr << "OPERATION #" << _ << " BEGIN" << endl;
        ll op;
        cin >> op;
        if(op == 1) {
            string typeName;
            ll elementsCount;
            cin >> typeName >> elementsCount;
            Type newType;
            newType.isBasic = false;
            newType.typeName = typeName;
            newType.size = newType.required = 0;
            for(ll i = 1; i <= elementsCount; ++i) {
                string elementTypeName, elementName;
                cin >> elementTypeName >> elementName;
                ll addressShift = newType.size, addressRequired = typeDetails[elementTypeName].required;
                if(addressShift % addressRequired != 0) {
                    addressShift += addressRequired - addressShift % addressRequired;
                }
                newType.elements[elementName] = make_tuple(elementTypeName, addressShift);
                newType.orderedElements.emplace_back(addressShift, elementTypeName, elementName);
                newType.size = addressShift + typeDetails[elementTypeName].size;
                newType.required = max(newType.required, addressRequired);
            }
            if(newType.size % newType.required != 0) {
                newType.size += newType.required - newType.size % newType.required;
            }
            typeDetails[newType.typeName] = newType;
            cout << newType.size << " " << newType.required << '\n';
        }
        else if(op == 2) {
            string typeName, variableName;
            cin >> typeName >> variableName;
            Variable newVariable;
            newVariable.typeName = typeName;
            newVariable.variableName = variableName;
            ll addressHead = addressPointer, addressRequired = typeDetails[typeName].required;
            if(addressHead % addressRequired != 0) {
                addressHead += addressRequired - addressHead % addressRequired;
            }
            ll addressTail = addressHead + typeDetails[typeName].size;
            newVariable.addressHead = addressHead;
            newVariable.addressTail = addressTail;
            variableDetails[newVariable.variableName] = newVariable;
            orderedVariables.emplace_back(newVariable.addressHead, newVariable.variableName);
            addressPointer = addressTail;
            cout << newVariable.addressHead << '\n';
        }
        else if(op == 3) {
            string queryElementName;
            cin >> queryElementName;
            vector<string> pathToElement;
            string now;
            for(char c : queryElementName) {
                if(c == '.') {
                    pathToElement.push_back(now);
                    now = "";
                }
                else {
                    now += c;
                }
            }
            pathToElement.push_back(now);
            string variableName = pathToElement[0];
            string variableTypeName = variableDetails[variableName].typeName;
            ll k = pathToElement.size(), address = variableDetails[variableName].addressHead;
            string fatherTypeName = variableTypeName;
            for(ll i = 1; i < k; ++i) {
                string elementName = pathToElement[i];
                string elementTypeName;
                ll addressShift;
                tie(elementTypeName, addressShift) = typeDetails[fatherTypeName].elements[elementName];
                address += addressShift;
                fatherTypeName = elementTypeName;
            }
            cout << address << '\n';
        }
        else {
            ll address;
            cin >> address;
            string rootVariableName;
            for(auto& variable : orderedVariables) {
                ll addressHead;
                string variableName;
                tie(addressHead, variableName) = variable;
                if(addressHead > address) break;
                rootVariableName = variableName;
            }
            string answer = rootVariableName;
            address -= variableDetails[rootVariableName].addressHead;
            string fatherTypeName = variableDetails[rootVariableName].typeName;
            while(!typeDetails[fatherTypeName].isBasic) {
                ll sonAddressShift = -1;
                string sonTypeName = "ERR";
                for(auto& element : typeDetails[fatherTypeName].orderedElements) {
                    ll addressShift;
                    string elementTypeName, elementName;
                    tie(addressShift, elementTypeName, elementName) = element;
                    if(addressShift > address) {
                        sonAddressShift = -1;
                        sonTypeName = "ERR";
                        answer = "ERR";
                        break;
                    }
                    if(addressShift <= address && address < addressShift + typeDetails[elementTypeName].size) {
                        sonAddressShift = addressShift;
                        sonTypeName = elementTypeName;
                        answer += ".";
                        answer += elementName;
                        break;
                    }
                }
                if(sonTypeName == "ERR") {
                    answer = "ERR";
                    break;
                }
                address -= sonAddressShift;
                fatherTypeName = sonTypeName;
            }
            cout << answer << endl;
        }
        // cerr << "OPERATION #" << _ << " END" << endl;
    }
    cout.flush();
    return 0;
}