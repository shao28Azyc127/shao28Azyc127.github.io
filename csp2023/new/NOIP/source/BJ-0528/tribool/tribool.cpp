#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int c,t,n,m,ans,tmp;
int x[maxn],x1[maxn],x2[maxn];
int a,b;

int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    //T=1,F=-1,U=0;
    scanf("%d%d",&c,&t);
    while(t--){
        ans=0;
        scanf("%d%d",&n,&m);
        if(c==3 || c==4){
            memset(x,-1,sizeof(x));
            for(int i=1;i<=n;i++){
                char ch;
                cin>>ch>>tmp;
                if(ch=='T'){
                    x[tmp]=1;
                }
                else if(ch=='F'){
                    x[tmp]=-1;
                }
                else if(ch=='U'){
                    x[tmp]=0;
                }
            }
            for(int i=1;i<=n;i++){
                if(x[i] == 0) ans++;
            }
            cout<<ans<<endl;
            continue;
        }

        if(c==5 || c==6){
            memset(x,-1,sizeof(x));
            int cnt=0,flag=1;
            for(int i=1;i<=n;i++){
                char ch;
                cin>>ch;
                if(ch=='+'){
                    cin>>a>>b;
                    x1[++cnt]=a;
                    x2[++cnt]=b;
                    x[tmp]=1;
                    x[a]=x[b];
                }
                else if(ch=='U'){
                    cin>>tmp;
                    x[tmp]=0;
                }
            }
            while(flag){
                flag=0;
                for(int i=1;i<=cnt;i++){
                    a=x[x1[i]],b=x[x2[i]];
                    if(a != b){
                        flag=1;
                        a=b;
                    }
                }
            }

            for(int i=1;i<=n;i++){
                if(x[i] == 0) ans++;
            }
            cout<<ans<<endl;
            continue;
        }
    }
}
