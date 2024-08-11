#include<bits/stdc++.h>
using namespace std;
int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='0') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
const int N=2e6+5;
int L[N],R[N];
void del(int now){
    R[L[now]]=R[now];
    L[R[now]]=L[now];
    return;
}
signed main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n=read();
    string s;
    cin>>s;
    int cnt=0;
    for(int i=0;i<s.size()-1;i++){
        for(int j=i+1;j<s.size();j+=2){
            for(int k=i+1;k<=j;k++){
                L[k]=k-1;
            }
            for(int k=i;k<j;k++){
                R[k]=k+1;
            }
            L[i]=-1;
            R[j]=n+1;
            bool flag=true;
            for(int k=1;k*2<=j-i+1;k++){
                bool f=0;
                int lft=i,rgt=j;
                for(int now=lft;now<=rgt;now=R[now]){
                    if(s[now]==s[R[now]]){
                        if(L[now]==-1) lft=R[now];
                        else del(now);
                        now=R[now];
                        if(L[now]==-1&&R[now]==n+1){
                            f=1;
                            break;
                        }
                        if(L[now]==-1) lft=R[now];
                        else if(R[now]==n+1) rgt=L[now];
                        else del(now);
                        f=1;
                        break;
                    }
                }
                if(!f){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
