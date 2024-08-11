#include<iostream>
using namespace std;
const string Type[4]={"byte","short","int","long"};
struct node
{
	string type,name;
	int Type,q;
	long long p,len;
};
struct Struct
{
	string name;
	int k,q;
	long long len;
	node a[110];
};
Struct a[110];
node A[110];
int n,num=3,Num=0;
inline long long F(long long x,long long y)
{
	return x+(y-x%y)%y;
}
inline void init(node &x)
{
	for(int j=0;j<4;j++)
	{
		if(x.type==Type[j])
		{
			x.Type=j;
			x.len=x.q=1<<j;
			return;
		}
	}
	for(int j=4;j<=num;j++)
	{
		if(x.type==a[j].name)
		{
			x.Type=j;
			x.len=a[j].len;
			x.q=a[j].q;
			return;
		}
	}
}
int main()
{
	freopen("struct.in","r",stdin);
	freopen("struct.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	while(n--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			num++;
			cin>>a[num].name>>a[num].k;
			for(int i=1;i<=a[num].k;i++)
			{
				cin>>a[num].a[i].type>>a[num].a[i].name;
				init(a[num].a[i]);
				a[num].a[i].p=F(a[num].a[i-1].p+a[num].a[i-1].len,a[num].a[i].q);
				a[num].q=max(a[num].q,a[num].a[i].q);
			}
			a[num].len=F(a[num].a[a[num].k].p+a[num].a[a[num].k].len,a[num].q);
			cout<<a[num].len<<" "<<a[num].q<<endl;
		}
		if(op==2)
		{
			Num++;
			cin>>A[Num].type>>A[Num].name;
			init(A[Num]);
			A[Num].p=F(A[Num-1].p+A[Num-1].len,A[Num].q);
			cout<<A[Num].p<<endl;
		}
		if(op==3)
		{
			string s;
			cin>>s;
			long long p;
			int now;
			for(int i=0;i<s.size();i++)
			{
				int j=i;
				while(j<s.size()&&s[j]!='.')
				{
					j++;
				}
				string name=s.substr(i,j-i);
				if(!i)
				{
					for(int k=1;k<=Num;k++)
					{
						if(name==A[k].name)
						{
							p=A[k].p,now=A[k].Type;
							break;
						}
					}
					i=j;
					continue;
				}
				for(int k=1;k<=a[now].k;k++)
				{
					if(name==a[now].a[k].name)
					{
						p+=a[now].a[k].p;
						now=a[now].a[k].Type;
						break;
					}
				}
				i=j;
			}
			cout<<p<<endl;
		}
		if(op==4)
		{
			long long p;
			cin>>p;
			int now=-1;
			string ans;
			for(int i=1;i<=Num;i++)
			{
				if(p<A[i].p)
				{
					break;
				}
				if(p<A[i].p+A[i].len)
				{
					p-=A[i].p;
					now=A[i].Type;
					ans=A[i].name;
					break;
				}
			}
			if(now<0)
			{
				cout<<"ERR"<<endl;
				continue;
			}
			bool flag=1;
			while(now>3)
			{
				bool Flag=1;
				for(int i=1;i<=a[now].k;i++)
				{
					if(p<a[now].a[i].p)
					{
						break;
					}
					if(p<a[now].a[i].p+a[now].a[i].len)
					{
						p-=a[now].a[i].p;
						ans+="."+a[now].a[i].name;
						now=a[now].a[i].Type;
						Flag=0;
						break;
					}
				}
				if(Flag)
				{
					flag=0;
					break;
				}
			}
			if(!flag)
			{
				cout<<"ERR"<<endl;
				continue;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
}