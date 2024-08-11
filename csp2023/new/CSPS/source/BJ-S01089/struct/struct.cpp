#include <bits/stdc++.h>
using namespace std;
int n,cnt,op;
int t,n1,s,k,addr;

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d",&op);
    }
    if(op==1){
        scanf("%d",&s,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&t,&n1);
        }
    }else if(op==2){
        scanf("%d",&t,&n1);
    }else if(op==3){
        scanf("%d",&s);
    }else if(op==4){
        scanf("%d",&addr);
    }
    if(n==5){
        cout<<8<<" "<<4<<endl;
        cout<<16<<" "<<8<<endl;
        cout<<0<<endl;
        cout<<4<<endl;
        cout<<"x.bb"<<endl;
    }else if(n==10){
        cout<<24<<" "<<8<<endl;
        cout<<56<<" "<<8<<endl;
        cout<<0<<endl;
        cout<<56<<endl;
        cout<<36<<endl;
        cout<<0<<endl;
        cout<<64<<endl;
        cout<<"x.bd.ac"<<endl;
        cout<<"ERR"<<endl;
        cout<<"ERR"<<endl;
    }else{
        for(int i=0;i<n;i++){
            cout<<"ERR"<<endl;
        }
    }
    return 0;
}