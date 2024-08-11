#include<bits/stdc++.h>
using namespace std;

bool compareStrings(string b) {
    string a = b;
code:
    for(char i = 'a'; i <= 'z'; i++) {
        char TempString[2] = {i, i};
        if(a.find(TempString) != string::npos) {
            a.replace(a.find(TempString), 2, "");
        }
    }
    bool flag = false;
    for(char i = 'a'; i <= 'z'; i++) {
        char TempString[2] = {i, i};
        if(a.find(TempString) != string::npos) {
            flag = true;
        }
    }
    if(flag)
        goto code;
    if(a.empty())
        return true;
    return false;
}


int main() {
    FILE *fpi, *fpo;
    fpi = freopen("game.in", "r", stdin);
    fpo = freopen("game.out", "w+", stdout);
    int n;
    string str;
    cin >> n >> str;
    int answer = 0;
    for(int i = 1; i <= n; i++) {//string size
        for(int j = 0; j < n - i + 1; j++) {
            string strTmp = str.substr(j, i);
            //cout << strTmp << " ";
            if(compareStrings(strTmp))
                answer++;
        }
    }
    cout << answer;
    fclose(fpi);
    fclose(fpo);
    return 0;
}
