#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
int n,m;
fstream in,out;

int strings[3001][3001];
char c;
int isbigger[3001];
bool ans[3001];
bool compares(int a,int b){
for(int i=0;i<m;i++){
    if(strings[a][m-1-i]<strings[b][m-1-i]){
        //isbigger[a]=true;
         return true;
    }
     if(strings[a][m-1-i]>strings[b][m-1-i]){
       // isbigger[a]=false;
        return false;
     }
}
return false;

}

bool compares2(int a,int b){
for(int i=0;i<m;i++){
    if(strings[a][i]<strings[b][m-1-i]){

         return false;
    }
     if(strings[a][i]>strings[b][m-1-i]){
        ans[a]=false;
        return true;
     }

}
ans[a]=false;
return true;
}
//all-true
int main(){
in.open("dict.in");
out.open("dict.out");
 in>>n>>m;
 if(n==1){
    out<<1;
    return 0;

 }
 for(int i=0;i<n;i++){
    isbigger[i]=i;
    ans[i]=true;
    for(int j=0;j<m;j++){
        in>>c;
        strings[i][j]=(int)c;
    }
    sort(strings[i],strings[i]+m);
 }

 sort(isbigger,isbigger+n,compares);
 //isbigger[0]
  for(int i=0;i<n;i++){
     if(i==isbigger[0])
     compares2(i,isbigger[1]);
    else{
        compares2(i,isbigger[0]);
    }
  }
    for(int i=0.;i<n;i++){
            out<<ans[i];
    }
in.close();
out.close();




}
