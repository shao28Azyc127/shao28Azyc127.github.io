#include<bits/stdc++.h>
#define ll long long
const int N=3010;
int maxn[N],minn[N];
int n,m;
char c;
char c1[N];
using namespace std;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    //zhuyi n==1 tepan
    for(int i=1;i<=n;i++){
        minn[i]=200;
        cin>>c1;
        for(int j=1;j<=m;j++){
            //scanf("%c",&c);
            c=c1[j-1];
            maxn[i]=max(maxn[i],int(c));
            minn[i]=min(minn[i],int(c));
        }
    }
    for(int i=1;i<=n;i++){
        bool flag=true;
        for(int j=1;j<=n;j++){
            if(j==i) continue;
            //cout<<maxn[j]<<minn[i]<<endl;
            if(maxn[j]<=minn[i]){
                flag=false;
                cout<<0;
                break;
            }
        }
        if(flag)
            cout<<1;
    }
    return 0;
}
