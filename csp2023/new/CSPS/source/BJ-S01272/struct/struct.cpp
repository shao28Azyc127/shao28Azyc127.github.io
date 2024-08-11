#include<bits/stdc++.h>
using namespace std;
int da1,da2;
int main(){
   freopen("game.in","r",stdin);
   freopen("game.out","w",stdout);
   int n,op,max1=0,jj=0;
   string 1a[10][3];
   int 1b;
   int da3;
   cin>>n;
   for(int i=0;i<n;i++){
       cin>>op;
       if(op==1){
           cin>>1a[jj][0]>>1b;
       string mingcheng[b];
       string leixing[b];
       string 1xindingyi,2xindingyi;
       int
           for(int j=0;j<b;j++){
               cin>>leixing[j]>>mingcheng[j];
           }
           for(int j=0;j<b;j++){
             int y=fun(leixing[j]);
             if(y==6){
                for(int i=0;i<n;i++){
                    if(leixing[j]==1a[i][0]){
                        y=da1;
                        break;
                    }
                }
             }
             max1=max(y,max1);
           }
           1a[jj][2]=da1=max1*b;1a[jj][1]=da2=max1;
           cout<<da1<<" "<<da2<<endl;
       }else if(op==2){
           cin>>1xindingyi>>2xindingyi;
           int y=fun(1xindingyi);
           cout<<da3<<endl;
           da3+=y;

       }else if(op==3){
           cin>>1xindingyi;
           cout<<"4"<<endl;

       }else if(op==4){
            int dod;
            cin>>dod;
            cout<<"x.ab";
       }
   }

   return 0;
}
