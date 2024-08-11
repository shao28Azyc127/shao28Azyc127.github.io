#include <bits/stdc++.h>
using namespace std;

int n,k,start[1034885],addr,tot1=0,tot2=0;    //tot1 shi struct daxiao 2 yaoqiu
int newadd=0,newname,newkind;
struct node{
    char kind;
    char name;
}a[205];



int main()
{
     freopen("struct.in","r",stdin);
     freopen("struct.out","w",stdout);

    cin>>n;
    for(int l=1;l<=n;l++){
        int x;
        cin>>x;
        if(x==1){
            cin>>k;
            for(int i=1;i<=k;i++){
                cin>>a[i].kind>>a[i].name;


            }
            tot1+=k*4;
            tot2+=4;
            cout<<tot1<<" "<<tot2<<endl;
        }
        else if(x==2){
            cin>>newkind>>newname;
            cout<<newadd;
            newadd+=4;
        }
       
    }
    return 0;
}
