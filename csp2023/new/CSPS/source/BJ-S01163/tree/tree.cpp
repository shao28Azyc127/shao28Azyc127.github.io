#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int b[100005];
int c[100005];

int getpay(int i,int a,int b,int c,int l,int r){
    if(l==r){
        return l;
    }
    int mid=(l+r)/2;
    long long payn=mid*b+(2*i+mid-1)*(mid+1)*c;
    if(a==payn){return mid;}
    if(a<payn){return getpay(i,a,b,c,l,mid);}
    if(a>payn){return getpay(i,a,b,c,mid+1,r);}
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    if(n<=20){
        cout<<n+1<<endl;
    }
    else{
        long long pay;
        long long maxpay=INT_MIN,payd,payn;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(c[i]>0){
                pay=getpay(i,a[i],b[i],c[i],1,1e9);
                maxpay=max(maxpay,pay);
            }
            else {
                pay=0;
                payd=i;
                payn=b[i]-(payd*c[i]);
                while(payn>1&&pay<=a[i]){
                    pay+=b[i]-(payd*c[i]);
                    payd++;
                    payn=b[i]-(payd*c[i]);
                }
                if(pay<a[i]){
                    payd+=a[i]-pay;
                }
                maxpay=max(maxpay,payd);
            }
        }
        cout<<maxpay;
    }
    return 0;
}
