#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n";
#define pii pair<int,int>
#define p1(A) A.first
#define p2(A) A.second
string s;
int n;
inline int force(){
    int res=0;
    for(int l=1;l<=n;l++){
        stack<char>S;
        for(int r=l;r<=n;r++){
            if(S.empty())S.push(s[r]);
            else{
                if(S.top()==s[r])S.pop();
                else S.push(s[r]);
            }
            res+=S.empty();
        }
    }
    return res;
}
int f[2000300];
int mat[2000300];
inline int AC(){
    int res=0;
    for(int r=1;r<=n;r++){
        int t=r-1;
        while(t>0&&s[t]!=s[r])t=mat[t]-1;
        if(t>0)
        mat[r]=t;
        if(t>0)
        f[r]=f[t-1]+1;
        res+=f[r];
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("game4.in","r",stdin);
    //freopen("game4.out","w",stdout);
    freopen("game.in","r",stdin);////////////////////////////////////////////////////////
    freopen("game.out","w",stdout);//remember to update
    cin>>n>>s;
    s=" "+s;
    if(n<=8000){//50
            printf("%lld\n",force());
    }
    else{//100
        printf("%lld\n",AC());
    }
    fflush(stdout);
    fflush(stdin);
    fclose(stdin);
    fclose(stdout);
    cout.flush();

    return 0;
}
