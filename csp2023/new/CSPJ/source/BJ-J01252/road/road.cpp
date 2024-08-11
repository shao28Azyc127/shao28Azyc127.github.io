#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int n,d,v[114514],a[114515];

bool lessen[114514];
int nprice;

int ntg,ret;
double lo;
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++) {
        cin>>v[i];
    }
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    nprice=a[1];
    lessen[1]=true;
    for(int i=2;i<n;i++) {
        if(a[i]<nprice) {
            lessen[i]=true;
            nprice=a[i];
        }
    }
    lessen[n]=true;
    for(int i=1;i<n;i++) {
        int j=i+1;
        ntg=v[i];
        while(!lessen[j]) {
            j++;
            ntg+=v[j];
        }
        //cout<<"current sum: "<<ret<<endl;
        int tempbt=ceil((double(ntg)/d)-lo);
        int tempct=tempbt*a[i];
        ret+=ceil((double(ntg)/d)-lo)*a[i];

        lo+=ceil((double(ntg)/d)-lo)-(double(ntg)/d);

        //cout<<"bought "<<tempbt<<" litres of fuel at station "<<i<<" for driving for "<<ntg<<" kilometres and lefting "<<lo<<" litres which costs "<<tempct<<" bucks, already a sum of "<<ret<<endl;
        i=j-1;
    }
    cout<<ret<<endl;
    return 0;
}
