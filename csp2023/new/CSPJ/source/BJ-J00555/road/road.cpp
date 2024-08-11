#include<iostream>
using namespace std;
struct car {
    long long dis,prize;
};
int n,d,a[100000];
long long v[100000];
car find_min(int e) {
    int minv=1e5+1,mink;
    for(int i=0;i<e;i++) {
        if(a[i]<minv) {
            minv=a[i];
            mink=i;
        }
    }
    car obj={0,0};
    if(mink!=0) obj=find_min(mink);
    long long dis;
    for(int i=mink;i<e;i++) dis+=v[i];
    obj.dis=((dis-obj.dis)%d==0?0:d-(dis-obj.dis)%d);
    obj.prize+=(dis+obj.dis)/d*a[mink];
    return obj;
}
int main() {
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++) {
        cin>>v[i];
    }
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    car c=find_min(n);
    cout<<c.prize<<endl;
    return 0;
}
