#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
ll c,t,n,m,ans,num[N],X[N],Y[N];
char re[N],a[N],pp[N];
void visit(){
    for(int i=1;i<=n;i++)cout<<re[i]<<" ";
    cout<<endl;
    return ;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){
        if(c==3||c==4){
            memset(a,0,sizeof a);
            ans=0;
            cin>>n>>m;
            while(m--){
                char pos;
                int x;
                cin>>pos>>x;
                a[x]=pos;
            }
            for(int i=1;i<=n;i++){
                if(a[i]=='U')ans++;
            }
            cout<<ans<<endl;
        }else{
            memset(a,0,sizeof a);
            ans=0;
            cin>>n>>m;
            for(int i=1;i<=n;i++){
                a[i]='N';
                num[i]=i;
            }
            for(int i=1;i<=m;i++){
                cin>>pp[i]>>X[i];
                if(pp[i]=='+'){
                    cin>>Y[i];
                    a[X[i]]='N';
                    num[X[i]]=Y[i];
                    //printf("x=%d y=%d a[%d]=%c\n",X[i],Y[i],X[i],a[X[i]]);
                }else{
                    a[X[i]]=pp[i];
                    //printf("x=%d a[%d]=%c\n",X[i],X[i],a[X[i]]);
                }
            }
            for(int i=1;i<=n;i++)re[i]=a[i];
            bool flag=1;
            while(flag){
                flag=0;
                //visit();
                for(int i=1;i<=m;i++){
                    if(pp[i]=='+'){
                        if(a[Y[i]]=='N'){
                            a[X[i]]='N';
                            num[X[i]]=num[Y[i]];
                        }else{
                            a[X[i]]=a[Y[i]];
                        }
                    }else{
                        a[X[i]]=pp[i];
                    }
                }
                for(int i=1;i<=n;i++){
                    if(re[i]!=a[i])flag=1;
                    re[i]=a[i];
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]=='U'){
                    ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
