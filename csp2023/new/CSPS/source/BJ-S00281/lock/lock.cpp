#include <iostream>

// #define debug
// #define debug_check

using namespace std;

const int N=9,M=6;
struct L
{
	int l[M];
}lock[N];

inline L makeL(int l1,int l2,int l3,int l4,int l5)
{
	L res;
	res.l[0]=0,res.l[1]=l1,res.l[2]=l2,res.l[3]=l3,res.l[4]=l4,res.l[5]=l5;
	return res;
}

bool check(L a,L b)
{
	bool flag=true;

	int cnt=0,cnt2=0;
	for(int i=1;i<5;i++)
	{
		if(a.l[i]-b.l[i])
		{
			cnt++;
			#ifdef debug_check
			cout<<1<<": "<<i<<endl;
			#endif
		}
		if((a.l[i]-b.l[i]+10)%10==(a.l[i+1]-b.l[i+1]+10)%10 && a.l[i]-b.l[i]!=0)
		{
			cnt2++;
			#ifdef debug_check
			cout<<2<<": "<<i<<" "<<a.l[i]-b.l[i]<<endl;
			#endif
		}
	}
	if(a.l[5]-b.l[5])
	{
		cnt++;
		#ifdef debug_check
		cout<<1<<": "<<5<<endl;
		#endif
	}

	#ifdef debug_check
	cout<<cnt<<" "<<cnt2<<endl;
	#endif
	
	if(cnt==1 || cnt2==1 && cnt==2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);

	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<M;j++)
		{
			cin>>lock[i].l[j];
		}
	}

	int res=0;
	for(int l1=0;l1<=9;l1++)
	for(int l2=0;l2<=9;l2++)
	for(int l3=0;l3<=9;l3++)
	for(int l4=0;l4<=9;l4++)
	for(int l5=0;l5<=9;l5++)
	{
		L passwd=makeL(l1,l2,l3,l4,l5);
		bool flag=true;
		for(int i=1;i<=n;i++)
		{
			if(!check(passwd,lock[i]))
			{
				flag=false;
			}
		}
		if(flag)
		{
			res++;
			#ifdef debug
			cout<<passwd.l[1]<<passwd.l[2]<<passwd.l[3]<<passwd.l[4]<<passwd.l[5]<<endl;
			#endif
		}
	}

	cout<<res<<endl;

	return 0;
}