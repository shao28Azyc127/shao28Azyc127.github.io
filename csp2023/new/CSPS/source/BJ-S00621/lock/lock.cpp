#include <bits/stdc++.h>
using namespace std;
long long n,a[10],ansa,ansb;
long long sndiff(long long a,long long b){
    if(b>=a)return b-a;
    return 10-a+b;
}
bool diff(long long a,long long b){
    vector<long long> aa,bb,dif;
    long long ta=a,tb=b,la=0,lb=0;
    while(ta){
        ta/=10;
        la++;
    }
    while(tb){
        tb/=10;
        lb++;
    }

    while(a){
        aa.push_back(a%10);
        a/=10;
    }
    while(b){
        bb.push_back(b%10);
        b/=10;
    }
    for(long long i=0;i<5-la;i++)aa.push_back(0);
    for(long long j=0;j<5-lb;j++)bb.push_back(0);
    /*
    for(long long i=0;i<aa.size();i++)cout<<aa[i]<<" ";
    cout<<endl;
    for(long long i=0;i<bb.size();i++)cout<<bb[i]<<" ";
    cout<<endl;
    */
    for(long long i=0;i<5;i++){
        if(aa[i]!=bb[i])dif.push_back(i);
    }
    if(dif.size()>2)return 0;
    if(dif.size()==1){
            ansa++;
        return 1;
    }
    if(dif.size()==2){
        if(dif[1]-dif[0]==1&&sndiff(aa[dif[0]],bb[dif[0]])==sndiff(aa[dif[1]],bb[dif[1]])){
            //cout<<"ansb\n";
            ansa++;
            return 1;
        }
        return 0;
    }
    return 0;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        for(long long j=0;j<5;j++){
            long long tmp;
            cin>>tmp;
            a[i]*=10;
            a[i]+=tmp;
        }
    }
    //cout<<diff(28301,28355);
    for(long long i=0;i<=99999;i++){
        bool flag=1;
        for(long long j=0;j<n;j++){
                //cout<<j<<endl;
            flag=flag&&diff(i,a[j]);
        }
        if(flag){
            ansb++;
            //cout<<i<<endl;
        }
        //cout<<i<<endl;
    }
    cout<<ansb;
    return 0;
}
