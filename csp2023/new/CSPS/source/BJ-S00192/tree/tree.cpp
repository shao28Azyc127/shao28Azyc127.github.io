#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>
#define fr(xx,yy,zz) for(int xx=yy;xx<=zz;xx++)
#define ll long long
#define pt printf
#define pii pair<int,int>
using namespace std;
const int N=1e6+33,inf=0x3f3f3f3f;////////////////////////
void rd(){}template<typename T,typename...args>inline void rd(T&x,args&...y){
    bool f=0;char ch=getchar();
    for(;ch<'0'||'9'<ch;ch=getchar())if(ch=='-')f=1;
    for(x=0;'0'<=ch&&ch<='9';ch=getchar() )x=(x<<1)+(x<<3)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
int main(){
int n;
rd(n);
pt("%d\n",n+(rand()%2));
    return 0;
}
