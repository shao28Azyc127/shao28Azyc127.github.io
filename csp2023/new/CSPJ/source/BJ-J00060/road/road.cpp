#include<bits/stdc++.h>
using namespace std;
long long n,m,ny=0;
long long f=0;

int flag=0;
long long e=1;
long long b[1000010]={0};
long long ans=0;
struct P{
    int x;
    int y;
};
P a[1000010]={0};
P ae[1000010]={0};
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<n;i++){
        cin>>b[i];
        ans+=b[i];
    }
    for(int i=1;i<=n;i++){
        a[i].x=i;
        cin>>a[i].y;
        ae[i].x=i;
        ae[i].y=a[i].y;
    }
    for(int j=1;j<n;j++){
        for(int i=1;i<n;i++){
            if(a[i].y>a[i+1].y)
            {
                e=a[i].x;
                a[i].x=a[i+1].x;
                a[i+1].x=e;
                e=a[i].y;
                a[i].y=a[i+1].y;
                a[i+1].y=e;
            }
        }
    }

    if(a[1].x==1)
    {
        if(ans%m==0)
        {
            f=ans/m*a[1].y;
        }
        else{
            f=(ans/m+1)*a[1].y;
        }
    }
    else{
        for(int j=1;j<n;j++){
            if(ae[j].y>=ae[j+1].y)
            {
                if(b[j]%m==0)
                {
                    f+=b[j]/m*ae[j].y;
                }
                else{
                    f+=(b[j]/m+1)*ae[j].y;
                }
            }
            else
            {
                ae[j+1].y=ae[j].y;
            }
        }
    }
    cout<<f;
    return 0;
}

