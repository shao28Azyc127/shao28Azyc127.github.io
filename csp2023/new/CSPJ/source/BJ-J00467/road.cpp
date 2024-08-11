#include<bits/stdc++.h>
using namespace std;
struct r{
    int id,a;
};
r s[100010];
int v[100010],pre[100010];
bool b[100010];
bool cmp(r x,r y){
    return x.a<y.a;
}
int fir;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>v[i];
        pre[i]=pre[i-1]+v[i];
        //cout<<pre[i]<<endl;
    }
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        if(i==1)fir=a;
    s[i]=(r){i,a};
    }
    sort(s+1,s+n,cmp);
    int l=n;
    int ans=0;
    int yu=0;
    //for(int i=1;i<=n;i++){
     //   cout<<s[i].a<<" ";
    //}
    //cout<<endl;
    int lst;
    for(int i=1;i<n;i++){
        //cout<<i<<" "<<s[i].id<<" "<<l<<endl;
        //cout<<b[s[i].id]<<endl;
        if(!b[s[i].id]&&s[i].id<l){
                //cout<<12345<<endl;
            //cout<<l<<" "<<yu<<" "<<s[i].a<<endl;
        //cout<<pre[l]<<" "<<pre[s[i].id]<<" "<<yu<<endl;
            ans+=(pre[l]-pre[s[i].id]+yu)/d*s[i].a;
            //cout<<ans<<endl;
            yu=(pre[l]-pre[s[i].id]+yu)%d;
            if((pre[l]-pre[s[i].id])%d==0){
                ans+=s[lst].a;
                //cout<<l<<" "<<s[lst].a<<endl;
                yu=0;
            }
            for(int j=s[i].id;j<=l;j++)b[j]=true;
            //for(int j=1;j<=n;j++)cout<<b[j]<<" ";
            //cout<<endl;
            l=s[i].id;
            lst=i;
        }
    //cout<<l<<endl;
        if(l<=1)break;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
