#include<bits/stdc++.h>
using namespace std;
int n,ans;char a[2000000];
int s(int x,int y){
    char b[x+10]={0};
    for(int i=1;i<=x;i++){
        b[i]=a[i+y-1];
    }
    /*for(int i=1;i<=x;i++){
        cout<<b[i]<<" ";
    }cout<<endl;*/
    int i=1,l=x;
    while(l!=0&&i<=l){//?
        if(b[i]==b[i+1]){
                //
            for(int j=i;j<l;j++){
                b[j]=b[j+2];
            }l-=2;
            for(int d=0;d<l;d++){
                //cout<<b[d]<<" ";
            }
            //cout<<endl<<x<<" "<<y<<endl;
            i=0;
        }
        i++;//cout<<"sign"<<endl;
        if(l==0){
              // cout<<endl<<x<<" "<<y<<endl;
            return 1;
        }
        if(i>l){
            return 0;
        }
    }
    return 0;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
for(int i=2;i<=n;i+=2){//changdu
    for(int j=1;j<=1+n-i;j++){//qishi
        ans+=s(i,j);
        //if(s(i,j)==1){
        //   cout<<i<<" "<<j<<endl;}

    }
}
cout<<ans;
    return 0;
    }

