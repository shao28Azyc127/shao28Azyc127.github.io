#include<iostream>
#include<cstdio>
using namespace std;
int n,cnt;
int l[10][6];
bool check(int a,int b,int c,int d,int e)
{
	bool f;
	for(int i=1;i<=n;++i)
	{
		f=true;
		int a2=l[i][1],b2=l[i][2],c2=l[i][3],d2=l[i][4],e2=l[i][5];
		for(int i=1;i<10;i++)
		{
			if( ( ( a2 + i ) % 10 == a && b2 == b && c2 == c && d2 == d && e2 == e) || ( a2 == a &&  ( b2 + i ) % 10 == b && c2 == c && d2 == d && e2 == e ) || ( a2 == a && b2 == b && ( c2 + i ) % 10 == c && d2 == d && e2 == e ) || ( a2 == a && b2 == b && c2 == c && ( d2 + i ) % 10 == d && e2 == e ) || ( a2 == a && b2 == b && c2 == c && d2 == d && ( e2 + i ) % 10 == e ) || ( ( a2 + i ) % 10 == a && ( b2 + i ) % 10 == b && c2 == c && d2 == d && e2 == e ) || ( a2 == a && ( b2 + i ) % 10 == b && ( c2 + i ) % 10 == c && d2 == d && e2 == e ) || ( a2 == a && b2 == b && ( c2 + i ) % 10 == c && ( d2 + i ) % 10 == d && e2 == e ) || ( a2 == a && b2 == b && c2 == c && ( d2 + i ) % 10 == d && ( e2 + i ) % 10 == e ) ) f=false;
		}
		if(f) return false;
	}
	return true;
}
int main()
{
	freopen("lock.in","r",stdin);
	freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=5;++j)
			cin>>l[i][j];
	for(int a=0;a<10;++a)
		for(int b=0;b<10;++b)
			for(int c=0;c<10;++c)
				for(int d=0;d<10;++d)
					for(int e=0;e<10;++e)
						if(check(a,b,c,d,e))
							++cnt;
	cout<<cnt;
	return 0;
}