#include<bits/stdc++.h>
using namespace std;
int n,ans,a[1000],lenth,b[1000],c[1000];
string st;
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    cin>>st;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            bool bo=true;
            lenth=0;
            memset(a,0,sizeof(a));
            memset(b,0,sizeof(b));
            memset(c,0,sizeof(c));
            int x;
            for(int k=i;k<=j;k++){
                x=st[k];
                lenth++;
                a[x]++;
                if(b[x]==0) b[x]=k;
                else{
                    c[x]=k-b[x];
                    b[x]=k;
                    if(c[x]%2==0) bo=false;
                }
            }
            if(lenth%2!=0) bo=false;
            for(int i=97;i<=122;i++){
                if(a[i]%2!=0) bo=false;
            }
            if(bo==true) ans++;
            //cout<<i<<" "<<j<<" "<<bo<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
