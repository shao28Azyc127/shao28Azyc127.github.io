#include<bits/stdc++.h>
using namespace std;
int n,a[100000010],b[100000010],flag=0,flag1=1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        a[i]=1;
        b[i]=i;
    }
    int sum=0,day=0;
    int j=1,ans=0;
    while(sum!=n){
        a[j]=0;
        sum++;
        flag=0;
        while(flag!=3){
            j++;
            if(j>n){
                day++;
                for(int i = 1;i<=n;i++){
                    if(a[i]==1){
                        j=i;
                        break;
                    }
                }
                break;
            }

            if(a[j]==1){
                flag++;
            }
        }
        if(a[n]==0&&flag1==1){
            flag1=0;
            ans=day;
        }
    }
    cout<<day<<" "<<ans;


    return 0;
}
