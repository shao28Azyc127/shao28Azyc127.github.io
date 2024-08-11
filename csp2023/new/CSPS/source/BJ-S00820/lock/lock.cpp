#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
struct arr{
    int a[5];
};
struct difference{
    int number;
    int amplitude;
};
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    cin>>n;
    queue<arr> q;
    for (int i=0;i<100000;i++){
        int j=i;
        arr ar;
        for (int k=0;k<5;k++){
            ar.a[k]=j%10;
            j/=10;
        }
        reverse(ar.a,ar.a+5);
        q.push(ar);
    }
    for (int i=0;i<n;i++){
        int a2[5],s=q.size(),cnt1=0,cnt2=0;
        for (int j=0;j<5;j++) cin>>a2[j];
        for (int j=0;j<s;j++){
            vector<difference> v;
            for (int k=0;k<5;k++) if (q.front().a[k]-a2[k]){
                difference p;
                p.number=k;
                p.amplitude=(q.front().a[k]-a2[k]+10)%10;
                v.push_back(p);
            }
            arr ar=q.front();
            q.pop();
            if (v.size()==1||v.size()==2&&(v[1].number-v[0].number==1&&v[0].amplitude==v[1].amplitude)) q.push(ar);
        }
    }
    cout<<q.size();
    return 0;
}