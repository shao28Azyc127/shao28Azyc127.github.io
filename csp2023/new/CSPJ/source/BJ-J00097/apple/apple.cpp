#include<iostream>
#include<queue>
using namespace std;
int main()
{
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    queue <int> a;
  for(int i=1;i<=n;i++)
   {
        a.push(i);
  }
    int ans;
    int i=0;
    int an=0;
    int l=n;
    int j=0;
    int t;
    while(l>0)
    {
		t=l;
		while(j<=t-1)
		{
			ans=a.front();
			a.pop();
			l--;
			j++;
			if(ans==n)
			{
				an=i;
			}
			for(int i=0;i<2;i++)
			{
					a.push(a.front());
					a.pop();
					j++;
					if(j>t-1)
					{
						break;
					}
			}
		}
			j=0;
			i++;
	}
	cout<<i<<' '<<an+1;
    return 0;
}
