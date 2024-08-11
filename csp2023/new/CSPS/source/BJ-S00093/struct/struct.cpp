#include<bits/stdc++.h>
#define ll long long
using namespace std;
map<string, ll> sizmp;
string type[105];
string name[105];
vector<ll> eposition;
vector<string> etype;
vector<string> ename;

string str1, str2, str3, structtype;
ll n, k, sizemax = 0, op, cur = 0;
int main() {
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%lld", &n);
    sizmp["byte"] = 1;
    sizmp["short"] = 2;
    sizmp["int"] = 4;
    sizmp["long"] = 8;
    while (n--) {
        scanf("%lld", &op);
        if (op == 1) {
            cin >> str1;
            structtype = str1;
            scanf("%lld", &k);

            for (int i = 0; i < k; i++) {
                cin >> str2 >> str3;
                type[i] = str2;
                name[i] = str3;
                sizemax = max(sizemax, sizmp[str2]);
            }
            sizmp[structtype] = k * sizemax;
            printf("%lld %lld\n", k * sizemax, sizemax);

        } else if (op == 2) {
            cin >> str1 >> str2;

            if (eposition.size() != 0) {
                //printf("aaaaaaaa");

                eposition.push_back(eposition[eposition.size() - 1] + cur);
                printf("%lld\n", eposition[eposition.size() - 1]);
                cur = sizmp[str1];
            } else {
                printf("0\n");
                eposition.push_back(0);
                cur = sizmp[str1];
            }

            etype.push_back(str1);
            ename.push_back(str2);

            /*for (int i = 0; i < k; i++) {
                cout << type[i] << " ";
            }
            printf("\n");
            for (int i = 0; i < k; i++) {
                cout << name[i] << " ";
            }
            printf("\n");
            for (int i = 0; i < etype.size(); i++) {
                cout << etype[i] << " ";
            }
            printf("\n");
            for (int i = 0; i < ename.size(); i++) {
                cout << ename[i] << " ";
            }
            printf("\n");
            for (int i = 0; i < eposition.size(); i++) {
                cout << eposition[i] << " ";
            }
            printf("\n");*/

        } else if (op == 3) {
            cin >> str1;
            if (str1.find('.') != string::npos) {

                string namefind = str1.substr(0, str1.find('.'));
            //cout << namefind << " " << structtype << endl;
                for (int i = 0; i < ename.size(); ++i) {
                    if (ename[i] == namefind) {
                            //printf("aaaaaa");
                        if (etype[i] == structtype) {
                            //printf("bbbbbb");
                            namefind = str1.substr(str1.find('.') + 1, str1.size() - str1.find('.'));
                            //cout << namefind << endl;
                            for (int j = 0; j < k; j++) {
                                if (name[j] == namefind) {
                                    printf("%lld\n", eposition[i] + j * sizemax);
                                    break;
                                }
                            }
                        } else {
                            printf("%lld\n", eposition[i]);
                        }
                    }
                }
            } else {
                for (int i = 0; i < ename.size(); ++i) {
                    if (ename[i] == str1) {
                        printf("%lld\n", eposition[i]);
                        break;
                    }
                }
            }


        } else {
            ll aaa;
            scanf("%lld", &aaa);
            if (eposition[eposition.size() - 1] < aaa) {
                if (aaa > eposition[eposition.size() - 1] + sizmp[etype[etype.size() - 1]]) {
                    printf("ERR\n");
                } else {
                    if (etype[etype.size() - 1] == structtype) {
                            bool flag = false;
                        int index = eposition[eposition.size() - 1];
                        for (int j = 0; j < k; j++) {

                            if (index <= aaa && aaa < index + sizmp[type[j]]) {
                                cout << ename[ename.size() - 1] << "." << name[j] << endl;
                                flag = true;
                                break;
                            } else {
                                index += sizemax;
                            }
                        }
                        if (flag == false) {
                            printf("ERR\n");
                        }
                    } else {
                        cout << ename[ename.size() - 1] << endl;
                    }
                }
            } else {
                for (int i = 0; i < eposition.size() - 1; i++) {
                    if (eposition[i] < aaa && eposition[i + 1] > aaa) {
                        if (etype[i] == structtype) {
                                bool flag = false;
                            int index = eposition[i];
                            for (int j = 0; j < k; j++) {

                                if (index <= aaa && aaa < index + sizmp[type[j]]) {
                                    cout << ename[i] << "." << name[j] << endl;
                                    flag = true;
                                    break;
                                } else {
                                    index += sizemax;
                                }
                            }
                            if (flag == false) {
                                printf("ERR\n");
                            }
                        } else {
                            cout << ename[i] << endl;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
