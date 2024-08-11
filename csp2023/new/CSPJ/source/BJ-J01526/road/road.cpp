#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,d,p[100010],l[100010],sum=0,w,x,m=0,q;
    cin>>n>>d;
    for(int i=0;i<n-1;i++)
    {
        cin>>l[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    int i=0;
    while(i<n-1){
        w=1;
        x=l[i];
        while(p[i]<p[i+w]&&i+w<n-1){
            w++;
            x=x+l[i+w-1];
        }
        q=x;
        if((x-m)%d==0){
            x=((x-m)/d);
        }
        else{
            x=((x-m)/d+1);
        }
        m=d*x-q;
        sum=sum+x*p[i];
        i=i+w;
    }
    cout<<sum;
	return 0;
	}
