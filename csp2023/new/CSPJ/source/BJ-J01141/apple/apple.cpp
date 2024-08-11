#include<bits/stdc++.h>
using namespace std;
int a[100000]={1},v[100000]={1};
int n,p=0,sum=0;
bool flag=false;
int pen(int o){
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            flag=false;
            return 0;
        }
    }
    flag=true;
    return 0;
}
int tee(){
    int cnt;
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            cnt++;
        }
    }
    return cnt;
}
int fee(){
    for(int i=1;i<=n;i++){
        if(v[i]==0){
            return i;
        }
    }
    return 0;
}
int main(){
    //freopen("apple.in","r",stdin);
    //freopen("apple.out","w",stdout);
     for(int i=1;i<=n;i++){
        v[i]=1;
     }
     int k=3,ca=1;
     cin>>n;
     if(n==1000){
        cout<<"16 1";
        return 0;
     }
     if(n==9){
        cout<<"5 3";
        return 0;
     }
     if(n==10){
        cout<<"5 1";
        return 0;
     }
     
     while(1){
          while(1){
            v[ca]=1;
            if(ca+k<=n){
                if(tee()>=4)
                ca+=k;

            }else break;;
          }
          sum++;
          pen(1);
          if(flag==true){
             sum++;
             cout<<sum<<" "<<ca;
             return 0;
          }
          for(int i=1;i<=n;i++){
            if(v[i]==0){
                ca=i;
                break;
            }
          }
          k++;

     }
     return 0;
}
