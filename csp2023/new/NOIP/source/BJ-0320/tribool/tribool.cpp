#include<iostream>
using namespace std;
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int n,m,c,t;
    int f[100000];
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        int ans=0;
        for(int i=0;i<n;i++){
            f[i]=0;
        }
        for(int i=0;i<n;i++){
            char c;int m1,m2;
            cin>>c;
            cin>>m1;
            if(c=='U'){f[m1]++;}
            //cin>>m1;
            if(c=='+'||c=='-') cin >>m2;
            else if(c!='U')
                    f[m1]=0;


        }
        ans=0;
        for(int i=0;i<n;i++){
            if(f[i])ans++;
        }
        cout<<ans<<endl;
    }


    return 0;
}

