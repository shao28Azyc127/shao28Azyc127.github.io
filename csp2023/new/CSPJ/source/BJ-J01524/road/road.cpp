#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int a[n+1][3];
    for(int i=1;i<n;i++){
        scanf("%d",&a[i][0]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i][1]);
    }
    int ans=0,s=0,c=0,v=a[0][1];
    for(int i=0;i<n-1;i++){
        while((c*d+s)<a[i+1][0]){
            c++;
        }
        s=(c*d+s)-a[i+1][0];
        ans+=c*v;
        c=0;
        if(a[i+1][1]<=v){
            v=a[i+1][1];
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
