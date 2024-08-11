#include<iostream>
#include<map>
using namespace std;

map<string, int> mp;
string p[1005];
bool flag = true;
int l;

int dfs(string s){
    int cnt = 0;
    for(int i = 0; i <= 4; i++){
        for(int j = 0; j <= 9;j++){
            string s2 = "";
            for(int k = 0; k <= 4; k++){
                if(k != i){
                    s2 += s[k];
                }
                else{
                    char c = char(j+'0');
                    s2 += c;
                }
            }
            //cout << s2 << " ";
            if(s2 != s)mp[s2]++;
            if(flag && s2 != s){cnt++;p[cnt] = s2;}
        }
    }
    for(int i = 0; i <= 3; i++){
        for(int j = 0; j <= 9; j++){
            int t1 = (s[i]+j-'0') % 10;
            char c1 = char(t1 + '0');
            int t2 = (s[i+1]+j-'0') % 10;
            char c2 = char(t2 + '0');
            if(c1 > '9') c1 -= 10;
            if(c2 > '9') c2 -= 10;
            string s2 = "";
            for(int k = 0; k <= 4; k++){
                if(k != i && k != i+1){
                    s2 += s[k];
                }
                else{
                    if(k == i) s2 += c1;
                    else s2 += c2;
                }
            }
            //cout << s2 << " ";
            if(s2 != s)mp[s2]++;
            if(flag && s2 != s){cnt++;p[cnt] = s2;}
        }
    }
    return cnt;
}

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n; cin >> n;
    for(int i = 1; i <= n; i++){
        int a[5]; cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
        string s = "";
        for(int i = 0; i <= 4; i++){
            s += a[i]+'0';
        }
        //cout << s << " ";
        if(flag) l = dfs(s);
        else dfs(s);
        flag = false;
        mp[s]--;
    }
    //cout << l << " ";
    int ans = 0;
    for(int i = 1; i <= l; i++){
        if(mp[p[i]] == n){
            ans++;
        }
    }
    cout << ans;
    return 0;
}