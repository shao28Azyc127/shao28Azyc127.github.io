//·ğ×æ±£ÓÓÎÒÄÃ70·Ö£¡£¡£¡
#include<bits/stdc++.h>
using namespace std;
string a[10010],s[10010],c[10010];
int d[10010];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    int n,m;
    cin >> n >> m;
    if(m == 1){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        string minn;
        minn = a[1];
        int cnt;
        for(int i = 2; i <= n; i++){
            if(a[i] < minn){
                minn = a[i];
                cnt = i;
            }
        }
        for(int i = 1; i <= n; i++){
            if(i == cnt) cout<<1;
            else cout<<0;
        }
    }
    if(m == 2){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = a[i];
            c[i] = a[i];
            if(c[i][0] > c[i][1]) swap(c[i][0],c[i][1]);
            if(s[i][0] < s[i][1]) swap(s[i][0],s[i][1]);
        }

        int cnt;
        for(int i = 1; i <= n; i++){
            //c[]
            cnt = 0;
            for(int j = 1; j <= n; j++){
                //s[]
                if(j == i) continue;
                if(s[j] <= c[i]) cnt = 1;
            }
            if(cnt == 0) cout << 1;
            else cout << 0;
        }
    }
    return 0;
}
