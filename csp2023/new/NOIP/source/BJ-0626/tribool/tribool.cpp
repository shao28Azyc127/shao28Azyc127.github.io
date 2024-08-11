#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
long long c,y,t,n,m,z;
char x;
long long  a[maxn],b[maxn];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    while(t--){

        long long  ans=0 ,cnt=0;
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            a[i]=1;b[i]=1;
        }

        for(int i=1;i<=m;i++){
            cin>>x;
            if(x=='+'||x=='-'){
            cin>>y>>z;
                if(x=='+'){
                a[y]=a[z];
            }
                else if(x=='-'){
                    a[y]=-a[z];
                }
        }
            else {
                cin>>y;
                if(x=='T')
                a[y]=1;

                else if(x=='F'){
                    a[y]=-1;
                }
                else if(x=='U'){
                    a[y]=0;
                }
                }
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(a[i]==0){
                ans++;
                flag=true;
            }
            else if(a[i]!=b[i]){
                cnt++;
            }
        }
        //if(ans=n-1&&!flag)ans=n;
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";

        }
        cout<<endl;
        cout<<ans<<endl;
    }
return 0;
}
