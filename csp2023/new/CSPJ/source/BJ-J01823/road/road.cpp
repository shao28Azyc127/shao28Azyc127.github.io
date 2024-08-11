#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int i,j=0,n,d,a[100001],b[100001],y=0,yj=0,l;
    for(i=1;i<=n-1;i++)cin>>a[i];
    for(i=1;i<=n;i++)cin>>b[i];
    b[n]=0;
    yj=a[1]/d;
    y*=d;
    yj*=b[1];
    if(a[1]%d!=0){
        yj+=b[1];
        y+=d;
    }
    y-=a[1];
    for(i=2;i<=n;i++){
        a[i]-=y;
        y=0;
        l=a[i]/d;
        if(a[i]%d!=0)l++;
        if(b[i]>=b[i+1]){
            yj+=b[i]*l;
            y=l*d;
            y-=a[i];
        }else{
            while(b[i]<b[i+j]){
                l=a[i+j-1]/d;
                if(a[i+j-1]%d!=0)l++;
                yj+=b[i]*l;
                y=l*d;
                y-=a[i+j-1];
                a[i+j]-=y;
                y=0;
                j++;
            }
            i+=j;
        }
    }
    cout<<yj;
    fclose(stdin);
    fclose(stdout);
return 0;
}
