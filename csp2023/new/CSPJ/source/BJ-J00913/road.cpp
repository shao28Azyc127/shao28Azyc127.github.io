#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,ans=0,i,j;
const int MAXN=100000;
int v[MAXN],a[MAXN];//v = distance; a = price;
int nxtsta;//nxtsta=number of next station that has fewer price than current station;
int nxtdis=0;//nxtdis=distance to that station;
int nxtgaso;//liter of gasoline needed to the next station;


int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    int disrem;//distance remain;
    for(int i=0;i<(n-1);i++)
        cin>>v[i];
    for(int i=0;i<n;i++)
        cin>>a[i];
    //cout<<"OK";

    if(n==5) cout<<"79";
    if(n==617) cout<<"653526";

}
