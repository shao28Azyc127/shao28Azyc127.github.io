#include <bits/stdc++.h>
using namespace std;
int n;
string ss1[105],ss2[105];
long long tot=0;
long long dq=0;
void pd(){
    if(ss1[tot] == "byte") dq=max(dq,(long long)1);
    if(ss1[tot] == "short") dq=max(dq,(long long)2);
    if(ss1[tot] == "int") dq=max(dq,(long long)4);
    if(ss1[tot] == "long") dq=max(dq,(long long)8);
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        int op;
        cin >> op;
        if(op == 2){
            cin >> ss1[++tot] >> ss2[tot];
            pd();
        }
        else if (op == 3){
            string ww;
            cin >> ww;
            for(int i = 1; i <= tot; i++){
                if(ss2[i]==ww){
                    cout << i*dq-dq << endl;
                    break;
                }
            }
        }
        else if(op == 4){
            unsigned long long addr;
            cin >> addr;
            addr++;
            long long x = addr/dq;
            long long y = addr%dq;
            if(x > tot) cout << "ERR";
            else if(y==0){
                if(ss1[x] != "long") cout<<"ERR";
                else cout << ss2[x];
            }
            else{
                x++;
                if(ss1[x] == "byte"&&y > 1) cout << "ERR";
                else if(ss1[x] == "short" && y > 2) cout << "ERR";
                else if(ss1[x] == "int" && y > 4) cout << "ERR";
                else cout << ss2[x];
            }
            cout << endl;
        }
    }
    return 0;
}
