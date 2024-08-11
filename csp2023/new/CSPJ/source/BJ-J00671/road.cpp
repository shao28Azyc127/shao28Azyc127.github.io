#include<bits/stdc++.h>
using namespace std;
int n,d;
const int N=1e5+1;
int v[N],a[N];
int m;
int num(int a,int b){
    double x,y;
    x=a,y=b;
    if(a/b!=x/y){
        return a/b+1;
    }else{
        return a/b;
    }
}
int oil;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=1;
    int i=1;
    while(i<n){
        cnt=1;
        for(int j=i+1;j<=n;j++){
            if(a[j]<a[i]) break;
            cnt++;
        }
        int scnt=0;
        for(int j=i;j<i+cnt;j++){
            scnt+=v[j];
        }

        scnt-=oil;
//        cout<<"i="<<i<<"->"<<i+cnt<<" ";
        m+=(num(scnt,d))*a[i];
        oil=(num(scnt,d))*d-scnt;
//        cout<<"+"<<m<<' '<<(num(scnt,d))*a[i]<<endl;
        i+=cnt;
    }
    cout<<m;
    return 0;
}
