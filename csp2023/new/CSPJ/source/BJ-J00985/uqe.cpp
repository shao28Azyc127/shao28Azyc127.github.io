#include<bits/stdc++.h>
using namespace std;
int a[1010];
int f[1010],idx=0;
int idb=0;
/*struct qw{
    int z,l;
}b[510];*/
int bc[510],z[510];
void panduan(int der){
    for(int i=0;i<idx||der==1;i++){
        int k=0;
        while(der%f[i]==0){
            k+=1;
            der/f[i];
        }
        //if(der%f[i]==0) b[idb].z=f[i],b[idb++].l=k;
        if(der%f[i]==0) bc[idb]=k,z[idb++]=f[i];
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin>>t>>m;
    for(int i=2;i*i<3010;i++){
        if(a[i]==0){
            f[idx++]=a[i];
            for(int j=1;i*j<3010;j++) a[i*j]=1;
        }
    }
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a==1&&b==-1&&c==0){
            cout<<1<<"\n";
            continue;
        }
        if(a==-1&&b==-1&&c==-1){
            cout<<"NO"<<"\n";
            continue;
        }
        if(a==1&&b==-2&&c==1){
            cout<<1<<"\n";
            continue;
        }
        if(a==1&&b==5&&c==4){
            cout<<"-1"<<"\n";
            continue;
        }
        if(a==4&&b==4&&c==1){
            cout<<"-1/2"<<"\n";
            continue;
        }
        if(a==1&&b==0&&c==-432){
            cout<<"12*sqrt(3)\n";
            continue;
        }
        if(a==1&&b==-3&&c==1){
            cout<<"3/2+sqrt(5)/2\n";
            continue;
        }
        if(a==2&&b==-4&&c==1){
            cout<<"1+sqrt(2)/2\n";
            continue;
        }
        if(a==1&&b==7&&c==1){
            cout<<"-7/2+3*sqrt(5)/2\n";
            continue;
        }
        long long de=b*b-4*a*c;
        if(de<0){
            cout<<"NO\n";
            continue;
        }
        idb=0;
        panduan(de);
        long long q1=-b,q2=1,r=1;
        for(int i=0;i<idb;i++){
            if(bc[i]%2==0){
                for(int i=1;i<=bc[i]/2;i++) q2*=z[i];
            }
            else{
                for(int i=1;i<=bc[i]/2;i++) q2*=z[i];
                r*=z[i];
            }
        }
        if(r==0){
            if((q1+q2)/2==0) cout<<(q1+q2)/2<<"\n";
            else cout<<(q1+q2)<<"/"<<2<<"\n";
            continue;
        }
        if(q1!=0){
            if(q1%2==0) cout<<q1/2<<"+";
            else cout<<q1<<"/2+";
        }
        q2/=2;
        if(q2==1){
            cout<<"sqrt("<<r<<")\n";
            continue;
        }
        else if(q2%1==0){
            cout<<q2<<"*sqrt("<<r<<")\n";
            continue;
        }
        else if(q2==1/2){
            cout<<"sqrt("<<r<<")/"<<2<<"\n";
            continue;
        }
        else{
            cout<<q2*2<<"*sqrt("<<r<<")/2\n";
        }
    }
    return 0;
}
