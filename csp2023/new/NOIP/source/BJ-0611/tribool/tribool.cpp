#include<bits/stdc++.h>

using namespace std;

char v[100005],ans[100005];
long long ii[100005],jj[100005];
long long n,m,c,t,cnt;
long long f[200005];

void init(int x){
    for(int i = 1;i<=x;i++){
        f[i] = i;
    }
    for(int i = x+1;i<=x*2;i++){
        f[i] = i-x;
    }
}

int fi(int x){
    return f[x] == x?f[x]:fi(f[x]);
}

void merg(int x,int y){
    f[y] = fi(x);
    cnt--;
}

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin >> c >> t;
    while(t--){
        memset(v,0,sizeof(v));
        memset(ans,0,sizeof(ans));
        memset(ii,0,sizeof(ii));
        memset(jj,0,sizeof(jj));
        cin >> n >> m;
        init(n);
        cnt = n;
        for(int i = 1;i<=n;i++){
            ans[i] = ' ';
        }
        for(int i = 1;i<=m;i++){
            cin >> v[i];
            if(v[i] == 'T'||v[i] == 'F'||v[i] == 'U'){
                cin >> ii[i];
            }
            else if(v[i] == '-'||v[i] == '+'){
                cin >> ii[i] >> jj[i];
            }
        }
        if(c == 3||c == 4){
            for(int i = m;i>=1;i--){
                if(ans[ii[i]]!=' '){continue;}
                ans[ii[i]] = v[i];
            }
            long long cnt1 = 0;
            for(int i = 1;i<=n;i++){
                if(ans[i] == 'U'){
                    cnt1++;
                }
            }
            cout << cnt1 << endl;
        }
        else if(c == 5||c == 6){
            for(int i = m;i>=1;i--){
                if(v[i] == '+'&&f[ii[i]]!=f[jj[i]]){
                    merg(ii[i],jj[i]);
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
