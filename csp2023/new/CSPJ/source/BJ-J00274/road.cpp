#include<bits/stdc++.h>
using namespace std;
int n,l,a[100050],v[100050],p=0,dangban[100050],dangbanlc[100050],dblclen=0,indb=0,dblen=0,oilNow,lowest=10000000;
int c(double a){
    if(a>floor(a)) return 1+floor(a);
    return floor(a);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>l;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    dangban[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i==n) v[i]=10000000;
        //here is the dangban
        if(i==1) lowest==v[i];
        if(v[i]<lowest){
            lowest=v[i];
            dblen++;
            dangban[dblen-1]=i-1;
            dangbanlc[dblen-1]=0;
        }
        //now,we have all the dangbans
    }
    dblen--;
    for(int i=1;i<=dblen;i++){
        dblclen++;
        for(int j=1+dangban[i-1];j<=dangban[i];j++){
            dangbanlc[i]+=a[j];
        }
    }
    dblclen++;
    for(int j=1+dangban[dblen];j<=n;j++){
        dangbanlc[dblen+1]+=a[j];
    }#include<bits/stdc++.h>
using namespace std;
int n,l,a[100050],v[100050],p=0,dangban[100050],dangbanlc[100050],dblclen=0,indb=0,dblen=0,oilNow,lowest=10000000;
int c(double a){
    if(a>floor(a)) return 1+floor(a);
    return floor(a);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>l;
    for(int i=1;i<=n-1;i++) cin>>a[i];
    dangban[0]=0;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        if(i==n) v[i]=10000000;
        //here is the dangban
        if(i==1) lowest==v[i];
        if(v[i]<lowest){
            lowest=v[i];
            dblen++;
            dangban[dblen-1]=i-1;
            dangbanlc[dblen-1]=0;
        }
        //now,we have all the dangbans
    }
    dblen--;
    for(int i=1;i<=dblen;i++){
        dblclen++;
        for(int j=1+dangban[i-1];j<=dangban[i];j++){
            dangbanlc[i]+=a[j];
        }
    }
    dblclen++;
    for(int j=1+dangban[dblen];j<=n;j++){
        dangbanlc[dblen+1]+=a[j];
    }
    for(int i=1;i<=dblclen;i++){
        double clc=1LL*((1LL*dangbanlc[i])+(1LL*oilNow))/(1LL*l);
        p+=ceil(clc)*v[dangban[i]];
        oilNow+=ceil(clc)*l;
        oilNow-=dangbanlc[i];
    }
    cout<<p;
    return 0;
}
r(int i=1;i<=dblclen;i++){
        double clc=1LL*((1LL*dangbanlc[i])+(1LL*oilNow))/(1LL*l);
        p+=ceil(clc)*v[dangban[i]];
        oilNow+=ceil(clc)*l;
        oilNow-=dangbanlc[i];
    }
    cout<<p;
    return 0;
}
