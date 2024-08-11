#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int y=n;
    bool a[n];int x=1;
    for(int i=0;i<n;i++){a[i]=1;}
    int n1,n2=0,tian=0;
    while(n>0){
        tian++;
        if(n%3!=2){
            n=n/3*2;
        }else{
            n=n/3*2;
            n++;
        }
        for(int i=0;i<y;i++){
            if(a[i]==1){
                if(x%3==1){
                    a[i]=0;
                }
                x++;
            }
        }

       if((a[y-1]==0)&&(n2==0)){
        n2=1;
        n1=tian;
       }
        x=1;

    }
    cout<<tian<<" "<<n1;
     return 0;
}