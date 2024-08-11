#include <bits/stdc++.h>
#include <stdint.h>
using namespace std;

int T,C;
const int MAXN = 100006;

// -1 = false
// 0 = UNK(NULL)
// 1 = true
int x[MAXN];


// -1 = false
// 0 = UNK(NULL)
// 1 = true
int f(int val){
    return -val;
}

// T2
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    //Nullable : bool?

    // duo ce qing kong
    cin>>C>>T;
    srand(time(0));
    while(T--){
        int N=0;
        int M=0;
        memset(x,1,sizeof(x));
        cin>>N>>M;
        bool allAdd=true;
        bool allUnk=true;
        for(int i=0;i<M;i++){
            string x;
            cin>>x;
            if(x=="+"){
                int a,b;
                allUnk=false;
                cin>>a>>b;
                x[b]=x[a];
            }
            else if(x=="-"){
                int a,b;
                allAdd=false;
                allUnk=false;
                cin>>a>>b;
            }
            else if(x=="U"){
                int a;
                allAdd=false;

                cin>>a;
                x[a]=-1;
            }
            else if(x=="T"){
                int a;
                allAdd=false;
                cin>>a;
            }
            else if(x=="F"){
                int a;
                allAdd=false;
                cin>>a;
            }
        }
        int ans = N;
        if(allUnk){
            ans=N;
        }
        else if(allAdd){
            ans=0;
        }
        cout<<ans<<endl;
    }
    cout<<endl;
    return 0;
}
