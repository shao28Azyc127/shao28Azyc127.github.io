#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    string s;
};
long long inf[105];
map <string,int> fa;
map <long long,string> ad;
map <string,long long> fad;
vector <node> s[105];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    long long t,cnt = 0,now = 0;
    cin >> t;
    while(t--){
        int obt,k,ans = 0,e = 0;
        string a,b,c;
        cin >> obt;
        if(obt == 1){
            cnt++;
            cin >> a >> k;
            fa[a] = cnt;
            //cout << fa[a] << " " << a << " " ;
            for(int i = 1;i <= k;i++){
                cin >> b >> c;
                if(b == "byte"){
                    s[cnt].push_back(node{1,"." + c});
                    ans = max(ans,1);
                }
                else if(b == "short"){
                    s[cnt].push_back(node{2,"." + c});
                    ans = max(ans,2);
                }
                else if(b == "int"){
                    s[cnt].push_back(node{4,"." + c});
                    ans = max(ans,4);
                }
                else if(b == "long"){
                    s[cnt].push_back(node{8,"." + c});
                    ans = max(ans,8);
                }
                else{

                }
                if(i != 1){
                    int f = (s[cnt][i - 2].l + e) / s[cnt][i - 1].l;
                    if(s[cnt][i - 2].l + e > f * s[cnt][i - 1].l){
                        f++;
                    }
                    e = f * s[cnt][i - 1].l;
                }
            }
            int f = (s[cnt][k - 1].l + e) / ans;
            if(s[cnt][k - 1].l + e > f * ans){
                f++;
            }
            e = f * ans;
            cout << e << " " << ans << endl;
            inf[cnt] = ans;
        }
        else if(obt == 2){
            cin >> a >> b;
            cout << now << endl;
            fad[b] = now;
            if(a == "byte"){
                //cout << 1;
                ad[now] = b;
                fad[b] = now;
                now += 1;
            }
            else if(a == "short"){
                //cout << 2;
                for(int i = now;i <= now + 1;i++) ad[i] = b;
                now += 2;
            }
            else if(a == "int"){
                //cout << 3;
                for(int i = now;i <= now + 3;i++) ad[i] = b;
                now += 4;
            }
            else if(a == "long"){
                //cout << 4;
                for(int i = now;i <= now + 7;i++) ad[i] = b;
                now += 8;
            }
            else{
                cnt = fa[a];
                //cout << a << " " << cnt << " ";
                for(int i = 0;i < s[cnt].size();i++){
                    if(i != 0){
                        int f = (s[cnt][i - 2].l + e) / s[cnt][i - 1].l;
                        if(s[cnt][i - 2].l + e > f * s[cnt][i - 1].l){
                            f++;
                        }
                        e = f * s[cnt][i - 1].l;
                    }
                    long long l = now + e;
                    fad[b + s[cnt][i].s] = now + e;
                    //cout << s[cnt][i].s << " ";
                    for(int j = l;j <= l + s[cnt][i].l - 1;j++){
                        ad[j] = b + s[cnt][i].s;
                    }
                }
                int f = (s[cnt][s[cnt].size() - 1].l + e) / inf[cnt];
                if(s[cnt][s[cnt].size() - 1].l + e > f * inf[cnt]){
                    f++;
                }
                e = f * ans;
                now += e;
            }
        }
        else if(obt == 3){
            cin >> a;
            cout << fad[a] << endl;;
        }
        else{
            cin >> k;
            if(ad.count(k)) cout << ad[k] << endl;
            else cout << "ERR" << endl;
        }
    }
    return 0;
}
