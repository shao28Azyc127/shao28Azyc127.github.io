#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;

#define ts(c) (c=='U'?3:(c=='T'?1:2))
#define nt(x) (((x)==3?3:3-(x)))

ifstream fin("tribool.in");
ofstream fout("tribool.out");


int C,T;
int n,m;
char op[maxn];
int x[maxn],y[maxn];
int a[maxn];// 1T 2F 3U

int tmp[maxn];
int ans;
void dfs(int k){
    if(k==n+1){
        for(int i=1;i<=n;i++)
            tmp[i]=a[i];
        for(int i=1;i<=m;i++){
            if(op[i]=='+')
                tmp[x[i]]=tmp[y[i]];
            else if(op[i]=='-')
                tmp[x[i]]=nt(tmp[y[i]]);
            else
                tmp[x[i]]=ts(op[i]);
        }
        int res=0;
        for(int i=1;i<=n;i++)
            if(tmp[i]!=a[i])
                return;
        for(int i=1;i<=n;i++)
            if(tmp[i]==3)
                res++;
        ans=min(ans,res);
        return ;
    }
    a[k]=1;
    dfs(k+1);
    a[k]=2;
    dfs(k+1);
    a[k]=3;
    dfs(k+1);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);fout.tie(0);
    fin>>C>>T;
    while(T--){
        fin>>n>>m;
        for(int i=1;i<=m;i++){
            fin>>op[i];
            if(op[i]=='+'||op[i]=='-')
                fin>>x[i]>>y[i];
            else
                fin>>x[i];
        }
        for(int i=1;i<=n;i++)
            a[i]=0;

        if(C==1||C==2){
            ans=n;
            dfs(1);
            fout<<ans<<endl;
        }
        else if(C==3||C==4){
            ans=0;
            for(int i=1;i<=m;i++){
                a[x[i]]=ts(op[i]);
            }
            for(int i=1;i<=n;i++){
                if(a[i]==3)
                    ans++;
            }
            fout<<ans<<endl;
        }
        else if(C==5||C==6){
            int lans;
            do{
                lans=ans;
                for(int i=1;i<=m;i++){
                    if(op[i]=='U')
                        a[x[i]]=3;
                    else{
                        a[x[i]]=a[y[i]];
                    }
                }
                ans=0;
                for(int i=1;i<=n;i++){
                    if(a[i]==3)
                        ans++;
                }
            }
            while(ans!=lans);
            
            fout<<ans<<endl;
        }
    }




    return 0;
}