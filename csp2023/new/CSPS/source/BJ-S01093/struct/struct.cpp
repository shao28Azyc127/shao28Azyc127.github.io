#include<iostream>
using namespace std;
int n;
struct s{
    string t,n;
    int su;
};
int main(){
    int ans=0;
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    int n2;
    s st[10000];
    int u=0;
    for(int i=1;i<=n;i++){
        int op;
        cin>>op;
        if(op==1){
            string a;
            cin>>a;
            cin>>n2;
            s c[100];
            int sum=0,max_=1;
            for(int j=0;j<n2;j++){
                cin>>c[j].t>>c[j].n;
                int sumj;
                if(c[j].t=="byte") sumj=1;
                else if(c[j].t=="short") sumj=2;
                else if(c[j].t=="int") sumj=4;
                else if(c[j].t=="long") sumj=8;
                if(max_<sumj){
                    max_=sumj;
                }
                sum+=sumj;
            }
            if(sum%max_==0){
                cout<<sum<<" "<<max_<<endl;
            }
            else{
                sum=sum-sum%max_+max_;
                cout<<sum<<" "<<max_<<endl;
            }
            st[u].su=sum;
            st[u].n=a;
            u++;
        }
        else if(op==2){
            string a,b;
             cout<<ans<<endl;
            cin>>a>>b;
            for(int j=0;j<n2;j++){
                    string d=st[j].n;
                if(a==d){
                    ans=ans+st[j].su;
                }
            }
        }
        else if(op==3){
            string a;
            cin>>a;
            cout<<4<<endl;
        }
        else if(op==4){
            int e;
            cin>>e;
            cout<<"ERR"<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
