#include <bits/stdc++.h>
using namespace std;
const int N = 1e9+9;
int n,role=0,date=1;
struct Node{
    int pre,nex;
    int v;
}a[N];
int head=1;
void delate(int y){
    if(head==y)
        head = a[y].nex;
        role++;
    int x = a[y].pre;
    int z = a[y].nex;
    a[x].nex = z;
    a[z].pre = x;

}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        a[i].pre = i-1;
        a[i].nex = i+1;
        a[i].v = i;
    }
   a[n].nex = 0;
   a[1].pre = 0;
   int cnt=0;
   for(int i=1;i<=n;++i){
        for(int j=1;j<=3;++j)
            cnt = a[cnt].nex;
    if(cnt==n)
        date = role;
    delate(cnt);

   }
   printf("%d %d",role,head);
    return 0;
}
