#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;
int n,z1=4,z2=0,beggg=0;
struct node1{
    ll k,siz,suo;
    string s;
    ll d[N];
    string e[N];
    ll beg[N];
    ll sizz[N];
    ll suoo[N];
}a[N];
struct node2{
    ll type;
    string s;
    ll beg,siz;
}b[N];
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    a[1].k=0;
    a[1].s="byte";
    a[1].siz=1;
    a[1].suo=1;
    a[2].k=0;
    a[2].s="short";
    a[2].siz=2;
    a[2].suo=2;
    a[3].k=0;
    a[3].s="int";
    a[3].siz=4;
    a[3].suo=4;
    a[4].k=0;
    a[4].s="long";
    a[4].siz=8;
    a[4].suo=8;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            z1++;
            int k;
            string s;
            cin>>s>>k;
            a[z1].k=k;
            a[z1].s=s;
            for(int i=1;i<=k;i++){
                string s1,s2;
                cin>>s1>>s2;
                for(int j=1;j<z1;j++){
                    if(a[j].s==s1){
                        a[z1].d[i]=j;
                        a[z1].e[i]=s2;
                        a[z1].suo=max(a[j].suo,a[z1].suo);
                        a[z1].sizz[i]=a[j].siz;
                        a[z1].suoo[i]=a[j].suo;
                        break;
                    }
                }
            }
            if(k!=0) a[z1].beg[0]=0;
            for(int i=2;i<=k;i++){
                if((a[z1].beg[i-1]+a[z1].sizz[i-1])%a[z1].suoo[i]==0)
                    a[z1].beg[i]=a[z1].beg[i-1]+a[z1].sizz[i-1];
                else
                {
                    ll temp=(a[z1].beg[i-1]+a[z1].sizz[i-1])/a[z1].suoo[i];
                    a[z1].beg[i]=(temp+1)*a[z1].suoo[i];
                }
            }
            a[z1].siz=(a[z1].beg[k]+a[z1].sizz[k])/a[z1].suo;
            if((a[z1].beg[k]+a[z1].sizz[k])%a[z1].suo!=0)
                a[z1].siz++;
            a[z1].siz*=a[z1].suo;
            cout<<a[z1].siz<<" "<<a[z1].suo<<endl;
        }
        if(op==2){
            z2++;
            string s1,s2;
            cin>>s1>>s2;
            for(int j=1;j<=z1;j++){
                if(a[j].s==s1){
                    b[z2].s=s2;
                    b[z2].type=j;
                    b[z2].siz=a[j].siz;
                    int su=a[j].suo;
                    ll temp=b[z2-1].beg+b[z2-1].siz;
                    b[z2].beg=temp/su;
                    if(temp%su!=0)
                        b[z2].beg++;
                    b[z2].beg*=su;
                    cout<<b[z2].beg<<endl;
                    break;
                }
            }
        }
        if(op==3){
            int ans=0;
            getchar();
            string s="";
            char c;
            while(1){
                c=getchar();
                if(c=='\n'||c=='.'){
                    break;
                }
                s+=c;
            }
            int pl;
            for(int i=1;i<=z2;i++)
                if(s==b[i].s){
                    pl=i;
                    break;
                }
            ans+=b[pl].beg;
            if(c=='\n')
            {
                cout<<ans<<endl;
                continue;
            }
            int jj=b[pl].type;
            while(1){
                string s3="";
                while(1){
                    c=getchar();
                    if(c=='\n'||c=='.'){
                        break;
                    }
                    s3+=c;
                }
                int kk;
                for(int i=1;i<=a[jj].k;i++)
                    if(s3==a[jj].e[i])
                        kk=i;
                //cout<<s3<<jj<<kk<<endl;
                ans+=a[jj].beg[kk];
                if(c=='\n')
                {
                    break;
                }
                jj=a[jj].d[kk];
            }
            cout<<ans<<endl;
        }
        if(op==4){
            ll addr;
            cin>>addr;
            int i=1;
            for(i=1;i<=z2;i++){
                if(b[i].beg+b[i].siz-1>=addr)
                    break;
            }
            if(i==z2+1){
                cout<<"ERR"<<endl;
                continue;
            }
            bool flag=0;
            int jj=b[i].type;
            while(a[jj].k!=0){
                for(int i=1;i<=a[jj].k;i++){
                    if(a[jj].beg[i]+a[jj].sizz[i]-1>=addr){
                        if(a[jj].beg[i]>addr){
                            cout<<"ERR"<<endl;
                            flag=1;
                            break;
                        }
                        jj=a[jj].d[i];
                    }
                }
                if(flag)
                    break;
            }
            if(flag)
                continue;
            jj=b[i].type;
            cout<<b[i].s;
            while(a[jj].k!=0){
                for(int i=1;i<=a[jj].k;i++){
                    if(a[jj].beg[i]+a[jj].sizz[i]-1>=addr){
                        cout<<'.'<<a[jj].e[i];
                        jj=a[jj].d[i];
                    }
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
