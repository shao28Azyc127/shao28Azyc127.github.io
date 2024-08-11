#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 100005
int main()
{
    int c,t,n,m,val[maxn];
    bool typ[maxn],no[maxn];
    char num[maxn];
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            typ[i]=0;
            no[i]=0;
            val[i]=i;
        }
        for(int i=1;i<=m;i++){
            char v;
            cin>>v;
            if(v=='T'||v=='F'||v=='U'){
                int x;
                cin>>x;
                typ[x]=1;
                num[x]=v;
            }
            else{
                int x,y;
                cin>>x>>y;
                typ[x]=typ[y];
                if(typ[y]==0){
                    if(v=='+'){
                        no[x]=no[y];
                    }
                    else{
                        no[x]=!no[y];
                    }
                    val[x]=val[y];
                }
                else{
                    if(v=='+'||num[y]=='U'){
                        num[x]=num[y];
                    }
                    else{
                        if(num[y]=='T'){
                            num[x]='F';
                        }
                        else{
                            num[x]='T';
                        }
                    }
                }
            }
        }
        int ans=0;
        if(c==3||c==4){
            for(int i=1;i<=n;i++){
                if(typ[i]==1){
                    if(num[i]=='U'){
                        ans++;
                    }
                }
            }
        }
        else{
            for(int i=1;i<=min(n,5000000/n);i++){
                for(int j=1;j<=n;j++){
                    if(typ[j]==0){
                        if(val[j]==j){
                            if(no[j]==1){
                                typ[j]=1;
                                num[j]='U';
                            }
                        }
                        else{
                            int x=j,y=val[j];
                            typ[x]=typ[y];
                            if(typ[y]==0){
                                if(no[j]==0){
                                    no[x]=no[y];
                                }
                                else{
                                    no[x]=!no[y];
                                }
                                val[x]=val[y];
                            }
                            else{
                                if(no[j]==0||num[y]=='U'){
                                    num[x]=num[y];
                                }
                                else{
                                    if(num[y]=='T'){
                                        num[x]='F';
                                    }
                                    else{
                                        num[x]='T';
                                    }
                                }
                            }
                        }
                    }
                }
            }
            for(int i=1;i<=n;i++){
                if(typ[i]==1){
                    if(num[i]=='U'){
                        ans++;
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
