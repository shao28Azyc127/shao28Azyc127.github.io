#include<bits/stdc++.h>
using namespace std;
int n;
int d;
int sl[100005];// the length between stations
int sm[100005];// the money need at this station
int mon;//the least money he needs to pay
float oil,oilneed;
int sn(int x){
    int oneed=0;
    int mn=0;
    for(int i=x;i<=n;i++){
        if(sm[i]<sm[x]) break;
        oneed+=(sl[i]/d);
        if(sl[i]%d!=0) {
                oneed++;
        }
        mn+=oilneed*sm[x];
    }
    return mn;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        if(i<n)cin>>sl[i];
        cin>>sm[i];
    }
    for(int i=1;i<=n-1;i++){
        oilneed=(sl[i]/d);
        if(sl[i]%d!=0) {
            oilneed++;
        }
        oilneed=oilneed-oil;
        if(oil<oilneed && sm[i+1]<sm[i]){//need oil and next is cheeper
            mon+=oilneed*sm[i];//buy
            oil+=oilneed;
        }
        if(oil<oilneed && sm[i+1]>sm[i]){//need oil and this station is cheep
            mon+=sn(i);//buy more
            oil+=sn(i)/sm[i];
        }
        //if(oil>=oilneed && sm[i]>sm[i+1]){//don't need oil and next is cheeper
            //don't buy
        //}
        //if(oil<oilneed && sm[i+1]<sm[i]){//don't need oil but this station is cheep
            //mon+=sn(i);//buy more
            //oil+=sn(i)/sm[i];
        //}
        oil-=sl[i]/d;
    }
    cout<<mon+1;
    return 0;
}
