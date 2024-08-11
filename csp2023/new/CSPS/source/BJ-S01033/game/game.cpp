#include <bits/stdc++.h>

using namespace std;

int main()
{

 freopen("game.in","r",stdin);
 freopen("game.out","w",stdout);


 int a;
 cin>>a;
 char b[a];
 //cin>>b;
 //cout<<a<<endl;
 //cout<<b;

 for(int i=0;i<=a;i++)
    {
cin>>b[i];
//cout<<b[i];
 }



int count=0;
for(int i=0;i<=a;i++){
        for(int j=0;j<=a;j++){
 if(b[i]==b[j*2+1]){
         count=count+1;
   if(b[i]==b[j+1]){
        count=count+1;
    }
//j=j+1;
 }
 j=j+1;
}
i=i+1;
}



cout<<count-1;



//cout<<"================"<<endl;
   //cout << "Hello world!" << endl;
    return 0;
}
