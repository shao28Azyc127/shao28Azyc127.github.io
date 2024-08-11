#include <bits/stdc++.h>
using namespace std;
int dist[100000+10];
int p[100000+10];
int n,d;
int
calc(int a,int b){
    int sum=0,ans=0;
    for(int i=0;i<a-1;i++){
        sum=sum+dist[i];
    }
    if(sum%d!=0){
        ans=ans+(sum/d+1)*p[0];
    }else{
        ans=ans+(sum/d)*p[0];
    }
    sum=0;
    for(int i=a;i<b-1;i++){
        sum=sum+dist[i];
    }
    if(sum%d!=0){
        ans=ans+(sum/d+1)*p[a];
    }else{
        ans=ans+(sum/d)*p[a];
    }
    sum=0;
    for(int i=b;i<n-1;i++){
        sum=sum+dist[i];
    }
    if(sum%d!=0){
        ans=ans+(sum/d+1)*p[b];
    }else{
        ans=ans+(sum/d)*p[b];
    }
    return ans;
}

int
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>dist[i];
    }
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=0;i<n;i++){
        if(minn>p[i]){
            sec=minn;
            pos2=pos1;
            minn=p[i];
            pos1=i;
        }
    }
    if(pos1<pos2){
        cout<<calc(pos1,pos2)<<endl;
    }else{
        cout<<calc(pos2,pos1)<<endl;
    }
    return 0;
}
