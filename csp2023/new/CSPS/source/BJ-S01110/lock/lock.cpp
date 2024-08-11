#include<iostream>
using namespace std;
struct node
{
	int b[10];
};
node a[100000];
int c[10];
int s[1000];
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].b[1]>>a[i].b[2]>>a[i].b[3]>>a[i].b[4]>>a[i].b[5];
	}
	int q=0,w=0,e=0,r=0,t=0,flag=0;
	int ans=0,m,m1;
	while(c[1]<10)
	{
		q=0;
		w=0;
		e=0;
		r=0;
		t=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].b[1]!=c[1])
			q++;
			if(a[i].b[2]!=c[2])
			w++;
			if(a[i].b[3]!=c[3])
			e++;
			if(a[i].b[4]!=c[4])
			r++;
			if(a[i].b[5]!=c[5])
			t++;
			if(q+w+e+r+t>2 || q+w+e+r+t==0)
			{
				flag=1;
				break;
			}
			else
			if(q+w+e+r+t==2)
			{
				if(q+w!=2 && w+e!=2 && e+r!=2 && r+t!=2)
				{
					flag=1;
					break;
				}
					s[1]=a[i].b[1]-c[1];
					s[2]=a[i].b[2]-c[2];
					s[3]=a[i].b[3]-c[3];
					s[4]=a[i].b[4]-c[4];
					s[5]=a[i].b[5]-c[5];
					for(int j=1;j<=5;j++)
					if(s[j]!=0)
					{
						m=s[j];
						m1=s[j+1];
						break;
					}
					if(m!=m1)
					{
						if(m<0)
						m=0-m;
						else
						if(m1<0)
						m1=0-m1;
						if( m+m1!=10)
						{
							flag=1;
							break;
						}
					}
			}
			
			q=0;
			w=0;
			e=0;
			r=0;
			t=0;
		}
		if(flag==0)
		ans++;
		c[5]++;
		if(c[5]==10)
		c[5]=0,c[4]++;
		if(c[4]==10)
		c[4]=0,c[3]++;
		if(c[3]==10)
		c[2]++,c[3]=0;
		if(c[2]==10)
		c[2]=0,c[1]++;
		flag=0;
	}
	cout<<ans<<endl;
	return 0;
}
