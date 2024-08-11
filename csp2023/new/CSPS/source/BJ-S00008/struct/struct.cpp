#include <bits/stdc++.h>

using namespace std;

struct _struct {
    string _structname;
    int _length;
    vector<string> _type;
    vector<string> _name;
    int _addrlong;
};

int n;
int maxaddr;

string test;
map<int, string> addr;
vector<_struct> Struct;
vector<string> type;
vector<string> name;

int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    cin >> n ;

    while (n--) {
        int op;

        cin >> op ;

        if (op == 1) {
            string s;
            int k;
            int maxaddr_temp;
            map<int, bool> addr_temp;
            _struct temp;

            cin >> s >> k ;

            temp._structname = s;
            temp._length = k;

            for (int i = 0; i < k; i++) {
                string type, name;

                cin >> type >> name ;

                temp._type.push_back(type);
                temp._name.push_back(name);

                if (type == "byte") {
                    int i;
                    int maxaddr_temp1 = maxaddr_temp;

                    for (i = 0; i < maxaddr_temp1; i++) {
                        if (!addr_temp[i]) {
                            break;
                        }
                    }

                    addr_temp[i] = 1;

                    if (i == maxaddr_temp1) {
                        maxaddr_temp++;
                    }
                } else if (type == "short") {
                    int i;
                    int maxaddr_temp1 = maxaddr_temp - 2;

                    for (i = 0; i < maxaddr_temp1; i++) {
                        if (!addr_temp[i] && !addr_temp[i + 1]) {
                            break;
                        }
                    }

                    addr_temp[i] = 1;
                    addr_temp[i + 1] = 1;

                    if (i == maxaddr_temp1) {
                        maxaddr_temp += 2;
                    }
                } else if (type == "int") {
                    int i;
                    int maxaddr_temp1 = maxaddr_temp - 4;

                    for (i = 0; i < maxaddr_temp1; i++) {
                        if (!addr_temp[i] && !addr_temp[i + 1] && !addr_temp[i + 2] && !addr_temp[i + 3]) {
                            break;
                        }
                    }

                    addr_temp[i] = 1;
                    addr_temp[i + 1] = 1;
                    addr_temp[i + 2] = 1;
                    addr_temp[i + 3] = 1;

                    if (i == maxaddr_temp1) {
                        maxaddr_temp += 4;
                    }
                } else if (type == "long") {
                    int i;
                    int maxaddr_temp1 = maxaddr_temp - 8;

                    for (i = 0; i < maxaddr_temp1; i++) {
                        if (!addr_temp[i] && !addr_temp[i + 1] && !addr_temp[i + 2] && !addr_temp[i + 3] && !addr_temp[i + 4] && !addr_temp[i + 5] && !addr_temp[i + 6] && !addr_temp[i + 7]) {
                            break;
                        }
                    }

                    addr_temp[i] = 1;
                    addr_temp[i + 1] = 1;
                    addr_temp[i + 2] = 1;
                    addr_temp[i + 3] = 1;
                    addr_temp[i + 4] = 1;
                    addr_temp[i + 5] = 1;
                    addr_temp[i + 6] = 1;
                    addr_temp[i + 7] = 1;

                    if (i == maxaddr_temp1) {
                        maxaddr_temp += 8;
                    }
                } else {
                    int len = Struct.size();
                    for (int i = 0; i < len; i++) {
                        if (Struct[i]._structname == s) {
                            int i;
                            int addrlong = Struct[i]._addrlong;
                            int maxaddr1 = maxaddr - addrlong;

                            for (i = 0; i < maxaddr1; i++) {
                                bool ok = 1;

                                for (int j = 0; j < addrlong; j++) {
                                    if (addr[i + j] != test) {
                                        ok = 0;
                                        break;
                                    }
                                }

                                if (ok) {
                                    break;
                                }
                            }

                            for (int j = 0; j < addrlong; j++) {
                                addr[i + j] == name;
                            }

                            if (i == maxaddr1) {
                                maxaddr += addrlong;
                            }

                            break;
                        }
                    }
                }
            }

            temp._addrlong = maxaddr_temp;

            Struct.push_back(temp);
        }

        if (op == 2) {
            string type, name;

            cin >> type >> name ;

            if (type == "byte") {
                int i;
                int maxaddr1 = maxaddr;

                for (i = 0; i < maxaddr1; i++) {
                    if (addr[i] == test) {
                        break;
                    }
                }

                addr[i] = name;

                if (i == maxaddr1) {
                    maxaddr++;
                }
            } else if (type == "short") {
                int i;
                int maxaddr1 = maxaddr - 2;

                for (i = 0; i < maxaddr1; i++) {
                    if (addr[i] == test && addr[i + 1] == test) {
                        break;
                    }
                }

                addr[i] = name;
                addr[i + 1] = name;

                if (i == maxaddr1) {
                    maxaddr += 2;
                }
            } else if (type == "int") {
                int i;
                int maxaddr1 = maxaddr - 4;

                for (i = 0; i < maxaddr1; i++) {
                    if (addr[i] == test && addr[i + 1] == test && addr[i + 2] == test && addr[i + 3] == test) {
                        break;
                    }
                }

                addr[i] = name;
                addr[i + 1] = name;
                addr[i + 2] = name;
                addr[i + 3] = name;

                if (i == maxaddr1) {
                    maxaddr += 4;
                }
            } else if (type == "long") {
                int i;
                int maxaddr1 = maxaddr - 8;

                for (i = 0; i < maxaddr1; i++) {
                    if (addr[i] == test && addr[i + 1] == test && addr[i + 2] == test && addr[i + 3] == test && addr[i + 4] == test && addr[i + 5] == test && addr[i + 6] == test && addr[i + 7] == test) {
                        break;
                    }
                }

                addr[i] = name;
                addr[i + 1] = name;
                addr[i + 2] = name;
                addr[i + 3] = name;
                addr[i + 4] = name;
                addr[i + 5] = name;
                addr[i + 6] = name;
                addr[i + 7] = name;

                if (i == maxaddr1) {
                    maxaddr += 8;
                }
            } else {
                int len = Struct.size();
                for (int i = 0; i < len; i++) {
                    if (Struct[i]._structname == name) {
                        int i;
                        int addrlong = Struct[i]._addrlong;
                        int maxaddr1 = maxaddr - addrlong;

                        for (i = 0; i < maxaddr1; i++) {
                            bool ok = 1;

                            for (int j = 0; j < addrlong; j++) {
                                if (addr[i + j] != test) {
                                    ok = 0;
                                    break;
                                }
                            }

                            if (ok) {
                                break;
                            }
                        }

                        for (int j = 0; j < addrlong; j++) {
                            addr[i + j] == name;
                        }

                        if (i == maxaddr1) {
                            maxaddr += addrlong;
                        }

                        break;
                    }
                }
            }
        } else if (op == 3) {
            string s;

            cin >> s ;

            for (int i = 0; i < maxaddr; i++) {
                if (addr[i] == s) {
                    cout << i << endl;
                }
            }
        } else if (op == 4) {
            int q_addr;

            cin >> q_addr ;

            if (addr[q_addr] == test) {
                cout << "ERR" << endl;
            } else {
                cout << addr[q_addr] << endl;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
