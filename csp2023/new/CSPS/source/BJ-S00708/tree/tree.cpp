#include<iostream>
#include<fstream>
using namespace std;
int *a,*b,*c,*t,n,d=1,mini=100001;
bool *e[100001],is=false;
bool done(){
for(int i=1;i<=n;++i){
if(t[i]<a[i]){return false;}
}
return false;
}
void bfs(){
if(done()){is=false;
mini=min(mini,d);
return;
}
++d;
for(int i=1;i<=n;++i){
if(t[i]!=-1){continue;}
for(int j=1;j<=i;++j){
if(t[j]!=-1&&e[j][i]){
t[i]=max(1,b[i]+d*c[i]);
bfs();
t[i]=-1;
if(is){--d;}
}}}
is=true;
return;
}
int main(){
ifstream fin("tree.in");
ofstream fout("tree.out");
int u,v;
fin>>n;
a=new int[n+1];
b=new int[n+1];
c=new int[n+1];
t=new int[n+1];
for(int i=1;i<=n;++i){
e[i]=new bool[n+1];
for(int j=1;j<=n;++j){
e[i][j]=false;
}}
for(int i=2;i<=n;++i){t[i]=-=1;}
for(int i=1;i<=n;++i){fin>>a[i]>>b[i]>>c[i];}
for(int i=1;i<=n;++i){
fin>>u>>v;
e[min(u,v)][max(u,v)]=true;
}
t[1]=max(1,b[1]+d*c[1]);
bfs();
fout<<mini;
fin.close();
fout.close();
return 0;
}