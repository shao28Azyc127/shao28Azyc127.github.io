#include<bits/stdc++.h>
using namespace std;
long long n,op,cnt;vector<long long> mem;
long long find(long long x){
    long long l=0,r=mem.size();long long mid=(l+r)/2;
    while(l!=mid){
        if(mem[mid]>x){
            r=mid;mid=(l+r)/2;
        }else{
            l=mid;mid=(l+r)/2;
            }
    }
    if(mem[l]==x){
        return 1;
    }
    return 0;
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
   cin>>n;
   map<string,long long> w;   map<long long,string> d;
   for(int i=1;i<=n;i++){
    cin>>op;
    if(op==2){
            string a,b;
        cin>>a>>b;
        w[b]=cnt;//cout<<cnt;
        d[cnt]=b;
        if(a=="long"){
            mem.push_back(cnt);cnt+=8;
            //cout<<"lo"<<endl;
        }
        if(a=="int"){
             mem.push_back(cnt);cnt+=4;
            //cout<<"int"<<endl;
        }
        if(a=="short"){
             mem.push_back(cnt);cnt+=2;
            //cout<<"sho"<<endl;
        }
    }
    if(op==3){
        string a,b;
        cin>>a;
        cout<<w[a]<<endl;
    }
    if(op==4){
        int a,b;
        cin>>a;
        if(find(a)==1){
            cout<<d[a]<<endl;
        }else{
            cout<<"ERR"<<endl;
        }
    }
   }


    return 0;
    }

