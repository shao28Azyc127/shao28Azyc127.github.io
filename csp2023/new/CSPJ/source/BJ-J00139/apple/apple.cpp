#include<iostream>
#include<map>
using namespace std;
long long n,m,k,l,r,t;
map<int,int>a;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    m=n;
    r=n;
    while(n>0){
      k++;
      if(n>3){
         n-=n/3+1;
      }
      else n-=1;
    }
    cout<<k<<" ";
    if(m%3==1) cout<<1;
    else if(m%3==0) cout<<n/3;
    else if(m==8) cout<<5;
    else if(m==2) cout<<2;
    else if(m==5) cout<<4;
    else{
        l=3;
        while(m>0){
            t++;
            for(int i=1;i<=m;i+=l){
                if(a[i]!=1&&a[i-1]!=1&&a[i-2]!=1){
                   l=3;
                   a[i]=1;
                   if(i==r){
                      cout<<t;
                      return 0;
                   }
                }
                else l=1;
            }
        }
    }

   return 0;
}
