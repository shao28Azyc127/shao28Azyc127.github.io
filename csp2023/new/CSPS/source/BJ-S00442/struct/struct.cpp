#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;

int n,op;
map <string , string> m;
vector <string> v; int it=0; // di zhi
bool pd(string s) {
    if(s=="") return 0;
    int l=s.size();
    forr(i,0,l-1) if(s[i]=='.') return 0;
    return 1;
}
int main() {
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    //cout<<n;
    forr(I,1,n) {
        //cout<<"i:"<<I<<"    ";
        //cout<<"qq";
        cin>>op;
        if(op==1) {
            int k,dq=0,Size=0,ik=0; string s,n,t;
            cin>>s>>k;
            //cout<<s<< ' ' <<k<<endl;
            //cout<<"ks "<<k<<' '<<s<<endl;
            forr(i,1,k) {
                //cout<<"op=1:in"<<endl;
                cin>>t>>n;
                //cout<<t<<' '<<n<<endl;
                n=s+"."+n;
                if(t=="byte") {
                    v.push_back(n);
                    it++;
                    dq = max(dq,1);
                    if(i!=k) Size += 1;
                    if(i==k) ik=1;
                }
                if(t=="short") {
                    v.push_back(n);
                    v.push_back(n);
                    it+=2;
                    dq = max(dq,2);
                    if(i!=k) Size += 2;
                    if(i==k) ik=2;
                }
                if(t=="int") {
                    forr(i,1,4) v.push_back(n);
                    it+=4;
                    dq = max(dq,4);
                    if(i!=k) Size += 4;
                    if(i==k) ik=4;
                }
                if(t=="long") {
                    forr(i,1,8) v.push_back(n);
                    it+=8;
                    dq = max(dq,8);
                    if(i!=k) Size += 8;
                    if(i==k) ik=8;
                }
            }
            Size += dq;
            int tt= dq-ik; it+=tt; forr(i,1,tt) v.push_back("");
            cout<<Size<<' '<<dq<<endl;
        }
        if(op==2) {
            string t,n;
            cin>>t>>n;

            cout<<it<<endl;
            //m[n]=t;
            if(t=="byte") v.push_back(n),it++;
            if(t=="short") {
                v.push_back(n);
                v.push_back(n);
                it+=2;
            }
            if(t=="int") {
                forr(i,1,4) v.push_back(n);
                it+=4;
            }
            if(t=="long") {
                forr(i,1,8) v.push_back(n);
                it+=8;
            }
        }
        if(op==3) {
            string s; cin>>s;
            forr(i,0,it) {
                if(v[i]==s) {
                    cout<<i<<endl;
                    break;
                }
            }
        }
        if(op==4) {
            int addr; cin>>addr;
            if(addr<=it ) {
                if( pd(v[addr]) ) cout<<v[addr]<<endl;
                else puts("ERR");
            }
            else puts("ERR");
        }
        //cout<<"it:"<<it<<endl;

    }

}
