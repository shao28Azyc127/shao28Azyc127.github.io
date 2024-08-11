#include <iostream>
#include<bits/stdc++.h>

using namespace std;
int v[100010],a[100010];
//for each pos ,find how many pos to skip
//and buy all the oil needed
int vs[100010];
int mylower[100010];
int n,d;
int getlower(int x){
    if(mylower[x])return x;
    //the first one that cheaper
    //find
    if(x==n)return mylower[x]=-1;//mean no cheaper
    int pos=x+1;
    if(a[pos]<a[x])return mylower[x]=pos;
    //pos>=x,skip
    for(;;){
        pos=getlower(pos);
        if(pos==-1)return mylower[x]=-1;//mean no cheaper
        if(a[pos]<a[x]){
            return mylower[x]=pos;
        }
    }


}
int getneedoil(int dis,int leftdis){
    dis-=leftdis;
    if(dis<=0)return 0;
    int ans=0;
    if(dis%d==0)ans+=dis/d;
    else ans+=dis/d+1;
    if(ans<0)return 0;
    return ans;
}
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
        vs[i]=v[i]+vs[i-1];
        //vs[1]:O--
        //vs[2]:O--O--
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    for(int i=1;i<=n;i++){
        getlower(i);
    }
    int ans=0;int oil_dis=0;
    for(int i=1;i<n;){
        if(mylower[i]==-1){//to the end
            int dis=vs[n-1]-vs[max(i-1,0)];//last dis
            int buyoil=getneedoil(dis,oil_dis);
            oil_dis+=buyoil*d;
            ans+=a[i]*buyoil;
            cout<<ans;
            return 0;
        }else{
            int dis=vs[mylower[i]-1]-vs[max(i-1,0)];
            int buyoil=getneedoil(dis,oil_dis);
            oil_dis+=buyoil*d;
            ans+=a[i]*buyoil;
            i=mylower[i];
            oil_dis-=dis;

        }
    }
    cout<<ans;
    return 0;
}
