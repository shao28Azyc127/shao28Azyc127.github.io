#include<bits/stdc++.h>
using namespace std;
map<long long , string> q;
map<string, long long>  f;
long long top;
int make(string t){
    int x;
    if(t=="byte"){
        x=1;
    }
    else if(t=="short"){
        x=2;
    }
    else if(t=="int"){
        x=4;
    }
    else if(t=="long"){
        x=8;
    }
    else x=-1;
    return x;
}
void add(string k, string t, bool flag){
    int x=make(k);
    if(x==-1) return;
    if(top%x!=0) top+=x-(top%x);
    //cout<<x<<" "<<top<<endl;
    if(flag) cout<<top<<endl;
    f[t]=top;
    for(long long i=top;i<top+x;i++){
        q[i]=t;
    }

    top+=x-1;
}
int main(){
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    //byte 1, short 2, int 4, long 8;
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            string s;
            int k, maxs=1;//structname num
            cin>>s>>k;
            s=s+'.';
            int tmp=top;
            for(int i=1;i<=k;i++){
                string t;
                string n;//kind name
                cin>>t>>n;
                maxs=max(maxs, make(t));
                n=s+n;
                add(t, n, 0);
            }
            cout<<top-tmp+1<<" "<<maxs<<endl;
        }
        else if(op==2){
            string t, n;//kind name
            cin>>t>>n;
            add(t, n, 1);
        }
        else if(op==3){
            string s;//name
            cin>>s;
            cout<<f[s]<<endl;
        }
        else if(op==4){
            long long addr;//map
            cin>>addr;
            if(q[addr]=="") cout<<"ERR"<<endl;
            else cout<<q[addr]<<endl;
        }
    }
    return 0;
}
