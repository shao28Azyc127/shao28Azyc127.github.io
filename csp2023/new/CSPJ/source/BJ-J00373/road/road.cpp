#include<bits/stdc++.h>
using namespace std;
int n,d,sum=0,temp1;
int yx=0;
int v[100005];
int a[100005];
int fnid(int t1,int t2,int temp){
    if(t2==n) return temp;
    if(a[t1]>a[t2]) return temp;
    temp+=v[t2];
    return fnid(t1,t2+1,temp);
}
int fnid1(int t1,int t2){
    if(t2==n) return n;
    if(a[t1]>a[t2]) return t2;
    return fnid1(t1,t2+1);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        if(a[i]<a[i+1]) temp1=fnid(i,i,0);
        else temp1=v[i];
        if((temp1-yx)%d==0){
            sum+=((temp1-yx)/d)*a[i];
            yx=temp1;
        }
        else{
            sum+=((temp1-yx)/d+1)*a[i];
            yx+=((temp1-yx)/d+1)*d;
        }
        yx-=temp1;
        if(a[i]<a[i+1]){i=fnid1(i,i)-1;}
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

