
#include<iostream>
#include<cstdio>
using namespace std;
int n, d;
long long v[100005];
long long a[100005];
long long k, mv, ans;
int go(int v, int d){    // to L
    if(v%d==0){
        return v/d;
    }else{
        return v/d+1;
    }
}
int main(){
    freopen("road1.in", "r", stdin);
    freopen("road.out", "w", stdout);
    cin>>n>>d;
    for(int i=2; i<=n; i++){
        cin>>v[i];
        k+=v[i];
    }
    for(int i=1; i<=n; i++){
        cin>>a[i];
    }
    mv=1;
    long long t=0, p=0, p1=0;
    for(int i=3; i<=n+1; i++){
        if(i==n+1){
            t+=k-p;
        }else{
            t+=v[i-1];

        }

        if(a[mv]>=a[i-1]){
            p1=0;
            ans+=go(t,d)*a[mv];    //L*prize
            p+=go(t,d)*d;
            t=0;
            mv=i-1;
        }else{
            continue;
        }


    }
    cout<<ans;


    fclose(stdin);
    fclose(stdout);
}
