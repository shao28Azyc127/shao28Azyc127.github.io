#include<bits/stdc++.h>
using namespace std;
short b[10][10][10][10][10];
struct Node{
    short a,b,c,d,e;
}a[9];

void add(Node x){
    b[x.a][x.b][x.c][x.d][x.e]++;
}

int n;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    map< Node , int>s;
    cin>>n;
    /*
    if(n==1){
        cout<<81<<endl;
        return 0;
    }
    */
    for(int i=1;i<=n;i++){
        cin>>a[i].a;
        cin>>a[i].b;
        cin>>a[i].c;
        cin>>a[i].d;
        cin>>a[i].e;
    }
    //cout<<"finish1"<<endl;
    Node temp;
    for(int i=1;i<=n;i++){
        temp.a=a[i].a;
        temp.b=a[i].b;
        temp.c=a[i].c;
        temp.d=a[i].d;
        temp.e=a[i].e;
        for(int j=1;j<=9;j++){
            temp.a=(temp.a+1)%10;
            add(temp);
        }
        temp.a=a[i].a;
        for(int j=1;j<=9;j++){
            temp.b=(temp.b+1)%10;
            add(temp);
        }
        temp.b=a[i].b;
        for(int j=1;j<=9;j++){
            temp.c=(temp.c+1)%10;
            add(temp);
        }
        temp.c=a[i].c;
        for(int j=1;j<=9;j++){
            temp.d=(temp.d+1)%10;
            add(temp);
        }
        temp.d=a[i].d;
        for(int j=1;j<=9;j++){
            temp.e=(temp.e+1)%10;
            add(temp);
        }
        temp.e=a[i].e;
        for(int j=1;j<=9;j++){
            temp.a=(temp.a+1)%10;
            temp.b=(temp.b+1)%10;
            add(temp);
        }
        temp.a=a[i].a;
        temp.b=a[i].b;
        for(int j=1;j<=9;j++){
            temp.b=(temp.b+1)%10;
            temp.c=(temp.c+1)%10;
            add(temp);
        }
        temp.b=a[i].b;
        temp.c=a[i].c;
        for(int j=1;j<=9;j++){
            temp.c=(temp.c+1)%10;
            temp.d=(temp.d+1)%10;
            add(temp);
        }
        temp.c=a[i].c;
        temp.d=a[i].d;
        for(int j=1;j<=9;j++){
            temp.d=(temp.d+1)%10;
            temp.e=(temp.e+1)%10;
            add(temp);
        }
        temp.d=a[i].d;
        temp.e=a[i].e;
        //cout<<"finish2-"<<i<<endl;
    }
    int ans=0;
    for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int l=0;l<=9;l++){
                    for(int o=0;o<=9;o++){
                        if(b[i][j][k][l][o]==n){
                            ans++;
                        }
                    }
                }
            }
        }
        //cout<<"finish3-"<<i<<endl;
    }
    cout<<ans<<endl;
    return 0;
}
