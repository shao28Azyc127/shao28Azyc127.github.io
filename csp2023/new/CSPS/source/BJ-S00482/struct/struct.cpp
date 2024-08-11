#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Num
{
    ll st;
    ll ed;
    string name;
};
Num num[105];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n,now = 0;
    cin >> n;
    num[0] = {-1,-1};
    while(n--){
        int op;
        cin >> op;
        if(op == 2){
            string s,t;
            cin >> s >> t;
            if(s == "short"){
                now++;
                num[now] = {num[now-1].ed+1,num[now-1].ed+2,t};
            }
            if(s == "int"){
                now++;
                num[now] = {num[now-1].ed+1,num[now-1].ed+4,t};
            }
            if(s == "byte"){
                now++;
                num[now] = {num[now-1].ed+1,num[now-1].ed+1,t};
            }
            if(s == "long"){
                now++;
                num[now] = {num[now-1].ed+1,num[now-1].ed+8,t};
            }
        }
        else if(op == 3){
            string s;
            cin >> s;
            for(int i = 1;i <= now;i++){
                if(num[i].name == s){
                    cout << num[i].st << endl;
                    break;
                }
            }
        }
        else if(op == 4){
            ll add;
            cin >> add;
            bool have = false;
            for(int i = 1;i <= now;i++){
                if(num[i].st <= add && add <= num[i].ed){
                    cout << num[i].name << endl;
                    have = true;
                    break;
                }
            }
            if(!have)cout << "ERR" << endl;
        }
    }
    return 0;
}