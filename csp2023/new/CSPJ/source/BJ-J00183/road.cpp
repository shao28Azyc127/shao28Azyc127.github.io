#include<bits/stdc++.h>
using namespace std;
int u[100005],a[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,ans=0,sy=0;
    scanf("%d %d",&n,&d);
    for(int i=0;i<n-1;i++){
        scanf("%d",&u[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;){
        int down=n-1;
        int dis=0;
        int pay=0;
        int amt=0;
        for(int j=n-1;j>i;j--){
            if(a[j]<=a[i]) down=j;
        }
        for(int j=i;j<down;j++){
            dis+=u[j];
        }
        amt=ceil(1.0*(dis-sy)/d);
        sy=amt*d-(dis-sy);
        pay=(a[i]*amt);
        ans+=pay;
        i=down;
    }
    printf("%d",ans);
}
