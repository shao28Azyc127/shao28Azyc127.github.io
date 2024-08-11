

#include <iostream>
#include <vector>

using namespace std;

struct node {
    string nam;
    vector<string> indn;
    vector<long long> indl;
}_a[109];

struct ele {
    string nam, a;
    vector<long long> st;
    vector<long long> len;
}_b[109];

long long _cnta, _cntb, _o[109];
long long _st;

int main () {
    long long T, op, x;
    string s1, s2;

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);

    cin >> T;

    while (T--) {
        cin >> op;

        if (op == 1) {
            cin >> s1 >> x;

            //cerr << 1 << ' ' << s1 << ' ' << x << endl;

            _cnta++;
            _a[_cnta].nam = s1;

            while (x--) {
                cin >> s1 >> s2;

                //cerr << s1 << ' ' << s2 << endl;

                if (s1 == "byte") {
                    _a[_cnta].indn.push_back(s2);
                    _a[_cnta].indl.push_back(1);
                }

                else if (s1 == "short") {
                    _a[_cnta].indn.push_back(s2);
                    _a[_cnta].indl.push_back(2);
                }

                else if (s1 == "int") {
                    _a[_cnta].indn.push_back(s2);
                    _a[_cnta].indl.push_back(4);
                }

                else {
                    _a[_cnta].indn.push_back(s2);
                    _a[_cnta].indl.push_back(8);
                }
            }

            _o[0] = 0;
            long long maxi = 0;

            for (int i = 0; i < _a[_cnta].indl.size(); i++) {
                maxi = max(maxi, _a[_cnta].indl[i]);

                _o[i + 1] = _o[i] + _a[_cnta].indl[i];

                while (_o[i + 1] % _a[_cnta].indl[i] != 0) {
                    _o[i + 1]++;
                }
            }

            while (_o[_a[_cnta].indl.size()] % maxi != 0) {
                _o[_a[_cnta].indl.size()]++;
            }

            cout << _o[_a[_cnta].indl.size()] << ' ' << maxi << endl;
        }

        else if (op == 2) {
            cin >> s1 >> s2;

            //cerr << 2 << ' ' << s1 << ' ' << s2 << endl;

            _cntb++;
            _b[_cntb].nam = s2;
            _b[_cntb].a = s1;

            if (s1 == "byte") {
                _b[_cntb].st.push_back(_st);
                _b[_cntb].len.push_back(1);
                //cerr << 1 << ' ' << _st << endl;
                cout << _st << endl;

                _st += 1;
            }

            else if (s1 == "short") {
                while (_st % 2 != 0) {
                    _st++;
                }

                _b[_cntb].st.push_back(_st);
                _b[_cntb].len.push_back(2);
                //cerr << 2 << ' ' << _st << endl;
                cout << _st << endl;

                _st += 2;
            }

            else if (s1 == "int") {
                while (_st % 4 != 0) {
                    _st++;
                }

                _b[_cntb].st.push_back(_st);
                _b[_cntb].len.push_back(4);
                //cerr << 4 << ' ' << _st << endl;
                cout << _st << endl;

                _st += 4;
            }

            else if (s1 == "long") {
                while (_st % 8 != 0) {
                    _st++;
                }

                _b[_cntb].st.push_back(_st);
                _b[_cntb].len.push_back(8);
                //cerr << 8 << ' ' << _st << endl;
                cout << _st << endl;

                _st += 8;
            }

            else {
                for (int i = 1; i <= _cnta; i++) {
                    if (_a[i].nam == s1) {
                        for (int j = 0; j < _a[i].indl.size(); j++) {
                            while (_st % _a[i].indl[j] != 0) {
                                _st++;
                            }

                            _b[_cntb].st.push_back(_st);
                            _b[_cntb].len.push_back(_a[i].indl[j]);
                            //cerr << _a[i].indl[j] << ' ' << _st << ' ' << _a[i].indn[j] << endl;

                            if (j == 0) {
                                cout << _st << endl;
                            }

                            _st += _a[i].indl[j];
                        }
                    }
                }
            }
        }

        else if (op == 3) {
            cin >> s1;

            //cerr << 3 << ' ' << s1 << endl;

            bool f = 0;
            string ss1 = "", ss2 = "";

            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == '.') {
                    f = 1;
                }

                else if (!f) {
                    ss1 += s1[i];
                }

                else {
                    ss2 += s1[i];
                }
            }

            //cerr << f << ' ' << ss1 << ' ' << ss2 << endl;

            if (!f) {
                for (int i = 1; i <= _cntb; i++) {
                    if (_b[i].nam == ss1) {
                        cout << _b[i].st[0] << endl;
                    }
                }
            }

            else {
                for (int i = 1; i <= _cntb; i++) {
                    //cerr << i << ' ' << _b[i].nam << endl;

                    if (_b[i].nam == ss1) {
                        //cerr << i << endl;

                        for (int j = 1; j <= _cnta; j++) {
                            if (_a[j].nam == _b[i].a) {
                                //cerr << j << endl;

                                for (int k = 0; k < _a[j].indn.size(); k++) {
                                    if (_a[j].indn[k] == ss2) {
                                        cout << _b[i].st[k] << endl;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        else {
            cin >> x;

            //cerr << 4 << ' ' << x << endl;

            bool f = 0;

            for (int i = 1; i <= _cntb; i++) {
                if (_b[i].a == "byte" || _b[i].a == "short" || _b[i].a == "int" || _b[i].a == "long") {
                    if (_b[i].st[0] <= x && x < _b[i].st[0] + _b[i].len[0]) {
                        f = 1;
                        cout << _b[i].nam << endl;
                    }
                }

                else {
                    for (int j = 1; j <= _cnta; j++) {
                        if (_a[j].nam == _b[i].a) {
                            //cerr << i << ' ' << j << ' ' << _a[j].nam << endl;

                            for (int k = 0; k < _a[j].indn.size(); k++) {
                                if (_b[i].st[k] <= x && x < _b[i].st[k] + _b[i].len[k]) {
                                    f = 1;
                                    cout << _b[i].nam << '.' << _a[j].indn[k] << endl;
                                }
                            }
                        }
                    }
                }
            }

            if (!f) {
                cout << "ERR" << endl;
            }
        }
    }

    return 0;
}
