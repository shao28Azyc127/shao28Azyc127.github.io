#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+6;

int n;
string arr[N];

int f[N];
int getfa(int x){
    if(f[x] == x) return x;
    return f[getfa(x)] = x;

}

void merge(int x, int y){
    f[getfa(x)] = getfa(y);
}

map<string, int> ma;
map<string, int> pos;
int op;
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    ma["byte"] = 1;
    ma["short"] = 2;
    ma["int"] = 4;
    ma["long"] = 8;
    cin >> n;
    int lastjie= -1, lastyuan;
    while(n--){
        cin >> op;
        if(op == 1){
            string s;
            int k, maxn = -1;
            cin >> s >> k;
            int be, en;
            for(int i = 1;i <= k;i++){
                string type, name;
                cin >> type >> name;
                if(type == "byte" || type == "short" ||type == "int" ||type == "long"){
                    maxn = max(ma[type], maxn);
                }
                if((lastjie+1) % ma[type] != 0){
                    for(int j = lastjie + 1; ;j++){
                        if(max(j, ma[type]) % min(j, ma[type]) == 0){
                            lastjie = j + ma[type] - 1;
                            if(i == 1) be = j;
                            pos[type] = j;
                            break;
                        }
                    }
                }else{
                    if(i == 1) be = lastjie;
                    lastjie = lastjie + ma[type];
                }
                //cout << lastjie << endl;
            }
            //cout <<maxn <<endl;
            if ((lastjie + 1) % maxn != 0){
                for(int j = lastjie + 1; ;j++){
                    if(max(j, maxn) % min(j, maxn) == 0){
                        lastjie = j - 1;
                        break;
                    }
                }
            }
            ma[s] = lastjie - be;
            //cout << lastjie << " " <<be << endl;
            cout << lastjie - be << " " << maxn << endl;
        }
    }


    return 0;
}

