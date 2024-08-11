#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("road.in",r,stdin);
   freopen("road.out",w,stdout);
   long long a,b;
   cin>>a>>b ;
   long long m[a],n[a];
   for(long long i=0;i<a;i++)cin>>m[i];
   for(long long i=0;i<a;i++)cin>>n[i];
   long long w=1;
   long long you=0,qian=0;
   while(w=a){
        long long s=0;
        long long o=w;
        for(long long i=w;i<=a;i++){
            s+=m[i];
            if(n[i]<n[0]){
                w+=i;
                break;
            }
       }
       if(w==o)w=a;
       s-=you*b;
       if(q%b==0)int k=s/b;
       else long long k=s/b+1;
       qian+=k*n[o];
       you=k*b-s;
   }
   cout<<qian;
   
}
