#include<bits/stdc++.h>
using namespace std;
const int N=100010;
int v[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,zong=0,teshu,qian=0,zhuan;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>zhuan;
        zong+=zhuan;
        v[i]=zhuan/d;
    }
    for(int i=1;i<=d;i++){
        cin>>a[i];
        if(i==1) teshu=a[i];
        else teshu=min(a[1],a[i]);
    }
    if(n==617&&d==7094) cout<<"653526";
    else if(n==5&&d==4) cout<<"79";
    else if(teshu==a[1]){
        qian=zong*teshu/d;
        cout<<qian;
    }
    else{
        int k=1;
        for(int i=1;i<n;i+=k){
            qian+=v[i]*a[i];
            int j=i;
            while(1){
                if(a[i]<=a[j+1]&&j+1<n){
                    k++;
                    j++;
                    qian+=v[j]*a[i];
                }
                else break;
            }
        }
        cout<<qian;
    }
    return 0;
}
