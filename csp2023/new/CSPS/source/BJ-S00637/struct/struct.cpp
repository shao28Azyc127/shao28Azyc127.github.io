#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int n,cnt,cnt2;
long long now;
string t[N],na[N];
map<long long,string> r;
map<string,long long> ress;
struct node{
    string s,t[N],na[N];
    int k,maxn = 0;
}u[N];
int get(string s){
    if(s == "byte") return 1;
    if(s == "short") return 2;
    if(s == "int") return 4;
    return 8;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        int op; scanf("%d",&op);
        if(op == 1){
            cin >> u[++cnt].s;
            scanf("%d",&u[cnt].k);
            long long last = now;
            for(int j = 1;j <= u[cnt].k;j++){
                cin >> u[cnt].t[j] >> u[cnt].na[j];
                string name = (u[cnt].s + "." + u[cnt].na[j]);
                int x = get(u[i].t[j]);
                u[i].maxn = max(u[i].maxn,x);
                if(now % x != 0)
                    now = now + x - (now % x);
                now += x;
                for(int k = now - x;k < now;k++)
                    r[k] = name;
                ress[name] = now - x + 1;
            }
            printf("%lld %d\n",now - last,u[i].maxn);
        }
        else if(op == 2){
            cin >> t[++cnt2] >> na[cnt2];
            int x = get(t[cnt2]);
            u[i].maxn = max(u[i].maxn,x);
            if(now % x != 0)
                now = now + x - (now % x);
            now += x;
            for(int k = now - x;k < now;k++)
                r[k] = na[cnt2];
            ress[na[cnt2]] = now - x + 1;
            printf("%lld\n",now - x);
        }
        else if(op == 3){
            string s; cin >> s;
            printf("%d\n",ress[s] - 1);
        }
        else{
            long long add;
            scanf("%lld",&add);
            if(r[add] == "") printf("ERR\n");
            else cout << r[add] << '\n';
        }
    }
    return 0;
}
/*
25
1 a 2
short aa
int ab
1 b 2
byte x
long b
2 int k
*/