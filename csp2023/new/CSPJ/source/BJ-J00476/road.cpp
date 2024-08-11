#include <iostream>
#include <cstdio>
using namespace std;

int n,d;
int v[100001];
int a[100001];
int sum=0;
int num=0;
int dis=0;
int i2=0;
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++) {
        cin>>v[i];
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n-1;i++) {
        i=i2;
        for(int j=i;j<n;j++) {
            if(a[j]<a[i]) {
                i2=j;
                break;
            }
            dis+=v[j];
        }
        if(dis%d==0) {
            num=dis/d;
        }
        else {
            num=dis/d+1;
            dis-=num*d;
        }
        sum+=num*a[i];
    }
    cout<<sum;
    return 0;
}
