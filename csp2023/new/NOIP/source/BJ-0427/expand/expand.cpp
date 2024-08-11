#include<iostream>
using namespace std;
int cc,m,n,q,a[500005],b[500005],c[65],d[65],x1[65],x2[65];
void work1(){
    int x=1,y=1,ff=1;
    while(x<=n){
            if(y>m){
                y=m;
            }
        int f=1;
        while(a[x]<b[y]&&y<=m){
            y++;
            f=0;
        }
        if(f==0){
            x++;
            continue;
        }
        while(a[x]>=b[y]&&y>=1){
            y--;
        }
        if(a[x]>=b[1]&&y==0){
            ff=0;
            break;
        }
        x++;
        y++;
    }
    //cout<<endl<<y<<' '<<ff<<endl;
    if(y>m){
        y=m;
    }
    if(y==m&&ff==1){
        cout<<1;
    }
    else{
        cout<<"0";
    }
}
void work2(){
    int x=1,y=1,ff=1;
    while(x<=n){
            if(y>m){
                y=m;
            }
        int f=1;
        while(a[x]>b[y]&&y<=m){
            y++;
            f=0;
        }
        if(f==0){
            x++;
            continue;
        }
        while(a[x]<=b[y]&&y>=1){
            y--;
        }
        if(a[x]<=b[1]&&y==0){
            ff=0;
            break;
        }
        x++;
        y++;
    }
    if(y>m){
        y=m;
    }
    //cout<<endl<<y<<' '<<ff<<endl;
    if(y==m&&ff==1){
        cout<<1;
    }
    else{
        cout<<"0";
    }
}
void work(){
    if(  (  (a[1]>b[1])&&(a[n]<b[m])  ) ||(  (a[1]<b[1])  &&  (a[n]>b[m])  ) || a[1]==b[1] ||a[n]==b[m]  ){
        cout<<"0";
        return;
    }
    if(a[1]<b[1]){
        work1();
    }
    else{
        work2();
    }
}
int main(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    cin>>cc>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    work();
    while(q--){
            int nn,mm,yy;
        cin>>nn>>mm;
        for(int i=1;i<=nn;i++){
            cin>>x1[i]>>yy;
            c[i]=a[x1[i]];
            a[x1[i]]=yy;
        }
        for(int i=1;i<=mm;i++){
            cin>>x2[i]>>yy;
            d[i]=b[x2[i]];
            b[x2[i]]=yy;
        }
        work();
        for(int i=1;i<=nn;i++){
            a[x1[i]]=c[i];
        }
        for(int i=1;i<=mm;i++){
            b[x2[i]]=d[i];
        }
    }
    return 0;
}
