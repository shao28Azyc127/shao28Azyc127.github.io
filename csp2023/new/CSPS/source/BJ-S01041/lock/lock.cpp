#include <bits/stdc++.h>
using namespace std;
ifstream fin("lock.in");
ofstream fout("lock.out");

enum{ N=8 };
int n;
int a[N][5];
bool able(const auto& A,const auto& B){
    int cnt{0};
    for(int i=0;i<5;i++) cnt+=A[i]!=B[i];
    if(cnt==1) return true;
    if(cnt!=2) return false;
    int x1{-1},x2{-1};
    for(int i=0;i<5;i++) if(A[i]!=B[i]) (x1==-1?x1:x2)=i;
    if(x2-x1!=1) return false;
    if((A[x1]-B[x1]+10)%10!=(A[x2]-B[x2]+10)%10) return false;
    return true;
}
bool check(const array<int,5>& c){
    for(int i=0;i<n;i++)
        if(!able(c,a[i])) return false;
    return true;
}
int main(){
    fin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<5;j++) fin>>a[i][j];
    
    int ans{0};
    for(int i=0;i<10;i++)
     for(int j=0;j<10;j++)
      for(int k=0;k<10;k++)
       for(int l=0;l<10;l++)
        for(int m=0;m<10;m++)
        ans+=check({i,j,k,l,m});
    fout<<ans<<'\n';

    return 0;
}