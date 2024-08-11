#include<bits/stdc++.h>
using namespace std;
int d[100001];
int o[100001];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int x,y;
    cin>>x>>y;
    for(int i=1;i<x;i++){
        cin>>d[i];
    }
    for(int i=1;i<=x;i++){
        cin>>o[i];
    }
    int t=1,cnt=0,t2;
    double ol=0;
    for(int i=1;i<x;i++){
        if(ol*y<d[i]){
            t2=((int)(d[i]-ol*y)/y)+((int)(d[i]-ol*y)%y!=0)*1;
            cnt+=o[i]*t2;
            cout<<cnt<<" "<<ol<<endl;
            ol+=t2;
        }
        t=i;
        while(t<=x){
            if(o[t]<=o[t+1]) t++;
            else if(o[t+1]<=o[i])break;
        }
        t2=0;
        for(int j=i;j<t;j++){
            t2+=d[j];
        }
            if(ol*y<t2){
                t2=(int)(t2-ol*y)/y+((int)(t2-ol*y)%y!=0)*1;
                cnt+=o[i]*t2;
                cout<<cnt<<" "<<ol<<endl;
                ol+=t2;
        }
        ol-=d[i]*1.0/y;
    }
    cout<<cnt;
    return 0;
}
