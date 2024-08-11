#include<bits/stdc++.h>
using namespace std;

int n;

int main(){
    struct Node{
        string type;
        int place;
    };
   Node base[4];
   base[1].type='short';
   base[1].place=2;
   base[0].type='byte';
   base[0].place=1;
   base[2].type='int';
   base[2].place=4;
   base[3].type='long';
   base[3].place=8;
   Node unbase[105];
cin>>n;
for(int i=0;i<n;i++){
        int op;
    cin>>op;
    int num=0;
if(op==1){
        int maxp=0;
    string a;
    cin>>a;

    int k;
    cin>>k;
    for(int j=0;j<k;j++){
            string t1;
       cin>>t1;
       unbase[num].type=t1;
       bool isbase=false;
       for(int l=0;l<4;l++){
        if(t1==base[l].type){
                isbase=true;
                if(maxp<base[l].place){
        maxp=base[l].place;
        }

    }
       }//if(isbase==false){
       //for(int l=0;l<=num;l++){
        //if(t1==unbase[l].type){
            //if(maxp<unbase[l].place)maxp=unbase[l].place;
        }
       }
       }
       string n1;
       cin>>n1;


    }
    cout<<k*maxp<<" "<<maxp;
    unbase[num].place=maxp*k;
    num++;
}

}

return 0;}
