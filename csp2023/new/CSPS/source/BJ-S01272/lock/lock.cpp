#include<bits/stdc++.h>
using namespace std;
long b[1000],x;
int pp=0;
int main(){
   freopen("lock.in","r",stdin);
   freopen("lock.out","w",stdout);
   int n,jishu=0;
   cin>>n;
   int a[5];
   if(n==1){
        for(int i=0;i<5;i++){
        cin>>a[i];
      }
        cout<<"81";
        return 0;
   }
   for(int i=0;i<n;i++){
      for(int i=0;i<5;i++){
        cin>>a[i];
      }
      for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            int b[5];b[0]=a[0];b[1]=a[1];b[2]=a[2];b[3]=a[3];b[4]=a[4];
            b[i]-=j;
            if(b[i]<0){
                b[i]=abs(b[i]);
            }
            int x=b[0]*1000+b[1]*100+b[2]*10+b[3];
            b[pp]=x;
            pp++;
            b[i]+=2*j;
            if(b[i]>9){
                b[i]=b[i]%10;
            }

            x=b[0]*1000+b[1]*100+b[2]*10+b[3];
            b[pp]=x;
           pp++;
        }
      }
      for(int i=0;i<4;i++){
        for(int j=0;j<9;j++){
            int b[5];b[0]=a[0];b[1]=a[1];b[2]=a[2];b[3]=a[3];b[4]=a[4];
            b[i]-=j;b[i+1]-=j;
            if(b[i]<0){
                b[i]=abs(b[i]);
            }
            if(b[i+1]<0){
                b[i]=abs(b[i]);
            }
            int x=b[0]*1000+b[1]*100+b[2]*10+b[3];
            b[pp]=x;
            pp++;
            b[i]+=2*j;b[i+1]+=2*j;
            if(b[i]>9){
                b[i]=b[i]%10;
            }
            if(b[i]>9){
                b[i]=b[i]%10;
            }
            x=b[0]*1000+b[1]*100+b[2]*10+b[3];
            b[pp]=x;
            pp++;
        }
      }
   }
   sort(b,b+pp+1);
   for(int i=0;i<pp+1;i++){
    if(b[i]==b[i+1]){
        jishu+=1;
        i+=1;
        continue;
    }else{
       jishu+=2;
       i+=1;
    }
   }
   cout<<jishu;
   return 0;
}
