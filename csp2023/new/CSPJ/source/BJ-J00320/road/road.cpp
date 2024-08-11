#include<iostream>
using namespace std;
int qqq[1000010],mon[1000010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,u,a,min=1e9,minidx=0;long long sum=0;
    cin>>n>>d;
    for(int i=1;i<n;i++){cin>>qqq[i];sum+=qqq[i];}

    for(int i=1;i<=n;i++){
            cin>>mon[i];
            if(mon[i]<min){
                min=mon[i];
                minidx=i;
            }
    }
    if(minidx==1){
        if(sum%d)cout<<(sum/d+1)*min;
        else cout<<(sum/d)*min;
    }
    fclose(stdin);
    fclose(stdout);
}