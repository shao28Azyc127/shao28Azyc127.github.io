#include<bits/stdc++.h>
using namespace std;
int n,d;
int u[10005]={0};
int a[10005]={0};
int money=99198109;

int js(int a,int b){
    int cnt=0;
    if(a>b){
        int temp=a;
        a=b;
        b=temp;
    }
    for(int i=a;i<b;i++){
        cnt+=u[i];
    }
    return cnt;
}

void f(int m,int o,int st){
    if(st==n-1){
        if(m<money){
            money=m;
            return;
        }
    }
    if(m>=money){
        return;
    }
    for(int i=st+1;i<n;i++){
        int new_o=ceil((js(st,i)-o)*1.0/d);
        //cout<<new_o*a[st]+m<<" "<<new_o*d-js(st,i)<<" "<<i<<endl;
        f(new_o*a[st]+m,new_o*d+o-js(st,i),i);
    }
    return;
}

int main(){
   freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>u[i];
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //int mb=ceil(js(0,n-1)*1.0/d)*a[0];
     f(0,0,0);
    cout<<money;
    return 0;
}

