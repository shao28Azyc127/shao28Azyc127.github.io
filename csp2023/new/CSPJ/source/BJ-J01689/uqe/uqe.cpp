#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("uqe.in","r",stdin);
   freopen("uqe.out","w",stdout);
   float a[5005],b[5005],c[5005],tri[5005],ac[5005],t,m;
   cin>>t>>m;
   for(int i=0;i<t;i++)
   {
       cin>>a[i]>>b[i]>>c[i];
       ac[i]=4*a[i]*c[i];
       tri[i]=b[i]*b[i]-ac[i];
       if(tri[i]<0){
        cout<<"No"<<endl;
        continue;}
       if(tri==0)
        cout<<-b[i]/2/a[i];
       else{
        if(-b[i]/2/a[i]!=0)
            cout<<-b[i]/2/a[i]<<"+";
        if(a[i]<0.5)
            cout<<"sqrt("<<tri[i]<<")/"<<2*a[i]<<endl;
        if(a[i]==0.5)
            cout<<"sqrt("<<tri[i]<<")"<<endl;
        if(a[i]>0.5)
            cout<<2*a[i]<<"*sqrt("<<tri[i]<<")"<<endl;
       }
   }
return 0;
}