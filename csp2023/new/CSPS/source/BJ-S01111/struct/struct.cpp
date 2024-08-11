#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e6+5;
int t, op, sum, sz;
string f[N];
struct node{
    string s[105];
    int mx, k, sum, l[105];
} a[105];
map<string, int> mp; 
map<string, node> stc; 
map<string, int> m; 
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &t);
    mp["byte"] = 1, mp["short"] = 2, mp["int"] = 4, mp["long"] = 8;
    while(t--){
        scanf("%d", &op);
        if(op == 1){
            string s, t, v;
            cin>>s;
            scanf("%d", &a[++sz].k);
            for(int i = 1; i <= a[sz].k; i++){
                cin>>t>>v;
                a[sz].s[i] = v;
                a[sz].mx = max(a[sz].mx, mp[t]), a[sz].l[i] = mp[t];
            }
            a[sz].sum = a[sz].mx * a[sz].k, stc[s] = a[sz];
            cout<<a[sz].sum<<" "<<a[sz].mx<<"\n";
        }
        if(op == 2){
            string s, t;
            cin>>s>>t;
            if(mp.count(s)){
                m[t] = sum;
                cout<<sum<<"\n";
                for(int i = sum; i < sum + mp[s]; i++) f[i] = t;
                sum += mp[s];
                continue;
            }
            int SUM = 0;
            for(int i = 1; i <= stc[s].k; i++){
                string ss = s + "." + stc[s].s[i];
                m[ss] = sum+SUM;
                for(int j = sum+SUM; j < sum+SUM+stc[s].l[i]; j++) f[j] = ss;
                SUM += stc[s].mx;
            }
            cout<<sum<<"\n";
            sum += stc[s].sum;
        }
        if(op == 3){
            string s;
            cin>>s;
            cout<<m[s]<<"\n";
        }
        if(op == 4){
            ll addr;
            cin>>addr;
            if(addr > sum || f[addr] == "") cout<<"ERR\n";
            else cout<<f[addr]<<"\n";
        }
    }
    return 0;
}
