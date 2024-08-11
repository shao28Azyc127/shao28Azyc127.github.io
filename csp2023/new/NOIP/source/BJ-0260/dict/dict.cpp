#include <iostream>

using namespace std;

int m, n;
const int maxn = 3003;
const int maxm = 3003;
char s[maxn][maxm];
char ms[maxm];
char coc[maxm];
char yu[maxm];

void my_copy(int i){
    for (int j = 0; j < m; j++)
        ms[j] = s[i][j];
}
void my_copy2(){
    for (int j = 0; j < m; j++)
        coc[j] = ms[j];
}

void my_copy3(int i){
    for (int j = 0; j < m; j++)
        yu[j] = s[i][j];
}

void help(int t){
    int index = 0;
    char mins = 'a';
    for (int i = 0; i < m; i++){
        if (s[t][i] >= mins){
            mins = s[t][i];
            index = i;
        }
    }
    int w = 0;
    while (ms[w] == mins && w + 1 < m) w++;
    if (index > w){
    ms[index] = ms[w];
    ms[w] = mins;
    }
}

void help2(int t){
    int index = 0;
    char mins = 'z';
    for (int i = 0; i < m; i++){
        if (s[t][i] <= mins){
            mins = s[t][i];
            index = i;
        }
    }
    int w = 0;
    while (yu[w] == mins && w + 1 < m) w++;
    if (index > w){
    yu[index] = yu[w];
    yu[w] = mins;
    }
}

bool help3(){
    bool l = 0;
    for (int i = 0; i < m; i++){
        if (ms[i] > coc[i]) return false;
        if (ms[i] < coc[i]) return true;
    }
    return false;
}

bool help4(){
    bool l = 0;
    for (int i = 0; i < m; i++){
        if (yu[i] > coc[i]) return false;
        if (yu[i] < coc[i]) return true;
    }
    return false;
}

int main(){
    freopen("dict.in", "r", stdin);
    freopen("dict.out", "w", stdout);
    int ppp = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        cin >> s[i];
        my_copy(i);
        help(i);
        if (i == 0) my_copy2();
        else if (help3()) my_copy2(), ppp = i;
    }
    //cout << coc << endl;
    for (int i = 0; i < n; i++){
        if (i == ppp) {
            cout << 1;
            //cout << "---------\n";
            continue;
        }
        else{
            my_copy3(i);
            help2(i);
            //cout << yu << endl;
            if (help4()) cout << 1;
            else cout << 0;
            //cout << "----------------------\n";
        }
    }
    return 0;
}
