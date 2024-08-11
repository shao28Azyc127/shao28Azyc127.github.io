#include<iostream>
#include<algorithm>
#include<string>
#include<fstream>
using namespace std;
int n,m,c,d;
fstream in,out;
int data[100001];
bool torf[100001];
bool isU[100001];
int positive(int a,int b){
    data[a]=data[b];torf[a]=torf[b];
}

int negative(int b,int a){
 if(data[a]<0){
    torf[b]=true;
    if(data[a]==-1)data[b]=-2;
    else if(data[a]==-2)data[b]=-1;
    else if(data[a]==-3)data[b]=-3;
 }
 else{
    data[b]=data[a];

        torf[b]=1-torf[a];

 }
}


int main(){
    in.open("tribool.in");
 out.open("tribool.out");
  in>>d>>c;
  for(int k=0;k<c;k++){
    in>>n>>m;int ans=0;
    for(int i=1;i<=n;i++){ data[i]=i; torf[i]=true;isU[i]=false;}

    for(int j=1;j<=m;j++){
        /*
  if(k==4){
                    for(int i=1;i<=n;i++){
       cout<<torf[i]<<' '<<data[i]<<endl;
    }
    cout<<endl;}
    */
        char Type;int a,b;
        in>>Type;
        if(Type=='T'||Type=='F'||Type=='U'){
            in>>a;
            torf[a]=true;
            if(Type=='T')data[a]=-1;
            if(Type=='F')data[a]=-2;
            if(Type=='U')data[a]=-3;
        }
        else{
           in>>a>>b;
           if(Type=='+'){positive(a,b);}
           if(Type=='-'){negative(a,b);}
           int currentplace=a;
           while(data[currentplace]>0 && currentplace!=data[a] && a!=data[a]){
             currentplace=data[a];
             if(torf[a]) positive(a,data[a]);
             else negative(a,data[a]);
           }

        }
    }

     for(int i=1;i<=n;i++){
            if(data[i]==i && torf[i]==false){
                isU[i]=true;ans++;
            }
            if(data[i]==-3){
                isU[i]=true;ans++;
            }
    }
    bool append=true;
    while(append){
       append=false;
       for(int i=1;i<=n;i++){
         if(!isU[i] && data[i]>0 && isU[data[i]]){
            isU[i]=true;
            append=true;ans++;
         }
    }








  }

 out<<ans<<endl;

}
}
