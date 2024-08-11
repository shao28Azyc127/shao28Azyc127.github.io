#include<bits/stdc++.h>
using namespace std;
struct bl{
    string lx;
    string name;
    long long l,r;
};
struct jgt{
    string name;
    bl type[1000];
    long long l,r;
}a[1000];
bl y[10001];
map<string ,int> h,s;
int cnt=0,len=0;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int t;
    cin>>t;
    h["long"]=8;
    h["int"]=4;
    h["short"]=2;
    h["byte"]=1;
    while(t--){
        int op;
        cin>>op;
        if(op==1){
            int k;
            string t;
            cin>>t>>k;
            a[++cnt].name=t;
            int ans=0,sum=0;
            for(int i=1;i<=k;i++){
                string l,x;
                cin>>l>>x;
                a[cnt].type[i].lx=l;
                a[cnt].type[i].name=x;
                a[cnt].type[i].l=ans;
                a[cnt].type[i].r=ans+h[l]-1;
                sum=max(sum,h[l]);
                ans+=h[l];
            }
            h[t]=ans+ans%sum;
            cout<<h[t]<<" "<<sum<<endl;
        }
        if(op==2){
            string t;
            string n;
            cin>>t>>n;
            y[++len].lx=t;
            y[len].name=n;
            y[len].l=s[t];
            y[len].r=s[t]+h[t]-1;
            cout<<s[t]<<endl;
            s[t]+=h[t];
        }
        if(op==3){
            string x;
            string in;
            cin>>x;
            bool b=false;
            for(int i=1;i<=len;i++){
                if(y[i].name==x){
                    cout<<y[i].l<<endl;
                    b=true;
                    break;
                }
            }
            for(int i=1;i<=cnt&&b==false;i++){
                if(a[i].name==x){
                    cout<<a[i].l<<endl;
                    b=true;
                    break;
                }
            }
        }
        if(op==4){
            long long addr;
            bool b=false;
            cin>>addr;
            for(int i=1;i<=len;i++){
                if(y[i].l<=addr&&y[i].r>=addr){
                    cout<<y[i].name<<endl;
                    b=true;
                    break;
                }
            }
            for(int i=1;i<=cnt&&b==false;i++){
                if(a[i].l<=addr&&a[i].r>=addr){
                    cout<<a[i].name<<endl;
                    b=true;
                    break;
                }
            }
        }
    }
    return 0;
}