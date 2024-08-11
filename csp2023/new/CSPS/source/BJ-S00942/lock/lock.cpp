#include<bits/stdc++.h>
using namespace std;
class psw
{
    private:
    int l[5];
    public:
    	int psn(int pos)
    	{
            return l[pos];
    	}
    	bool operator ==(psw p2)
    	{
    	    int d[5],cnt=0;
    	    for(int i=0;i<5;i++) if(l[i]!=p2.psn(i)) d[cnt++]=i;
    	    if(cnt>2) return false;
    	    if(cnt<1) return false;
    	    if(cnt==1) return true;
    	    if(d[cnt-1]-1!=d[cnt-2]) return false;
    	    if(p2.psn(d[cnt-2])-l[d[cnt-2]]+l[d[cnt-1]]-p2.psn(d[cnt-1])==0) return true;
    	    return false;
    	}
    	void read()
    	{
    	    for(int i=0;i<5;i++) scanf("%d",&l[i]);
    	}
    	psw pls(int typ,int num,int pos)
    	{
    	    psw tmp=*this;
    	    for(int i=0;i<typ;i++)
    	    {
    	        l[pos+i]+=num;
    	        l[pos+i]%=10;
    	    }
    	    swap(*this,tmp);
    	    return tmp;
        }
    	void print()
    	{
    	    for(int i=0;i<5;i++) printf("%d ",l[i]);
    	    putchar('\n');
    	}
};
queue<psw> q;
void setnew(psw a)
{
    for(int i=1;i<=9;i++)
    {
    	for(int pos=0;pos<4;pos++) for(int typ=1;typ<=2;typ++) q.push(a.pls(typ,i,pos));
    	q.push(a.pls(1,i,4));
    }
}
void del(psw a)
{
    queue<psw> r;
    while(!q.empty())
    {
    	if(q.front()==a) r.push(q.front());
    	q.pop();
    }
    swap(q,r);
}
signed main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;
    scanf("%d",&n);
    psw a[n];
    for(int i=0;i<n;i++) a[i].read();
    setnew(a[0]);
    for(int i=1;i<n;i++) del(a[i]);
    printf("%ld\n",q.size());
    return 0;
}