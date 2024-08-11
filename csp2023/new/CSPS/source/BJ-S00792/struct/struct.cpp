#include<bits/stdc++.h>
using namespace std;
string s,t,z[10010],ans;
int n,op,k,fa,mmax;
map<string,int> a,ma;
map<int,string> nm,m;
int idx,ids;
long long addr;
vector<int> tr[100010];
int dq[100010],lg[100010],lx[100010];
int nc[100010],st[100010];
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    a["byte"]=1;lg[1]=1;dq[1]=1;
    a["short"]=2;lg[2]=2;dq[2]=2;
    a["int"]=3;lg[3]=4;dq[3]=4;
    a["long"]=4;lg[4]=8;dq[4]=8;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>op;
        if(op==1)
        {
            cin>>s>>k;
            nm[++idx]=s;
            a[s]=idx;
            fa=idx;
            mmax=1;
            for(int j=1;j<=k;j++)
            {
                cin>>t>>s;
                nm[++idx]=s;lx[idx]=a[t];
                tr[fa].push_back(idx);
                mmax=max(mmax,lg[a[t]]);
            }
            lg[fa]=k*mmax;
            dq[fa]=mmax;
            cout<<lg[fa]<<" "<<dq[fa]<<endl;
        }
        else if(op==2)
        {
            cin>>t>>s;
            nc[++ids]=a[t];
            m[ids]=s;
            ma[s]=ids;
            st[ids]=st[ids-1]+lg[nc[ids]];
            cout<<st[ids]<<endl;
        }
        else if(op==3)
        {
            cin>>s;
            z[1].clear();
            int w=1;
            for(int j=0;j<s.size();j++)
            {
                if(s[j]=='.')
                {
                    w++;
                    z[w].clear();
                    continue;
                }
                z[w]+=s[j];
            }
            int f=ma[z[1]];int ans=st[f];
            for(int j=2;j<=w;j++)
            {
                for(auto j1:tr[f])
                {
                    if(nm[j1]==z[j])
                    {
                        f=j1;
                        break;
                    }
                    else
                    {
                        ans+=lg[j1];
                    }
                }
            }
            cout<<ans<<endl;
        }
        else
        {
            cin>>addr;
            mmax=0;int sum=0;
            for(int j=1;j<=ids;j++)
            {
                if(st[j]<=addr)
                {
                    mmax=st[j];
                    sum=j;
                }
                else{
                    break;
                }
            }
            if(nc[sum]<=4)
            {
                if(addr-st[i]+1>lg[nc[sum]])
                {
                    cout<<"ERR"<<endl;
                }
                else
                {
                    cout<<m[sum];
                }
            }
            else
            {
                ans+=m[sum]+".";
                int dis=addr-st[sum]+1;
                while(nc[sum]>4)
                {
                    for(auto j1:tr[sum])
                    {
                        if(dis<=dq[sum])
                        {
                            sum=j1;
                            ans+=nm[j1];
                            if(nc[j1]>4)
                            {
                                ans+=".";
                            }
                            break;
                        }
                        dis-=dq[sum];
                    }
                }
                if(dis>lg[i])
                {
                    cout<<"ERR"<<endl;
                }
                else
                {
                    cout<<ans+nm[sum];
                }
            }
        }
    }
    return 0;
}
