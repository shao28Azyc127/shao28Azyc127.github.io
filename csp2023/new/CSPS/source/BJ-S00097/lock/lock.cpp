#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
    int a[6]={};
}lck[10];
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>lck[i].a[1]>>lck[i].a[2]>>lck[i].a[3]>>lck[i].a[4]>>lck[i].a[5];
    if(n==1) cout<<81;
    else if(n==2){
        int ans=1,cnt=0,l1=-1,l2=-1;
        for(int i=1;i<=5;i++){
            if(lck[1].a[i]!=lck[2].a[i]){
                cnt++;
                if(l1==-1) l1=i;
                else l2=i;
            }
        }
        if(cnt>2) cout<<0;
        else{
            if(l1==-1) cout<<81;
            else if(l2==-1){
                if(abs(lck[1].a[l1]-lck[2].a[l1])%2==1) cout<<0;
                else{
                    if(l1==1||l1==5) cout<<10;
                    else cout<<20;
                }
            }
            else if(l2-l1!=1) cout<<0;
            else{
                if(abs(lck[1].a[l1]-lck[2].a[l1])%2==1||abs(lck[1].a[l2]-lck[2].a[l2])%2==1) cout<<0;
                else cout<<1;
            }
        }
    }
    return 0;
}
