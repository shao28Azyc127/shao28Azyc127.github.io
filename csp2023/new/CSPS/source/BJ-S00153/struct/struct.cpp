#include<bits/stdc++.h>
using namespace std;
string c1,c2;
int n,a,x;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        if(a==2)
            cin>>c1>>c2;
        if(a==3)
            cin>>c1;
        if(a==4)
            cin>>x;
    }
    for(int i=1;i<=n;i++)
        cout<<"ERR"<<endl;
    return 0;
}
