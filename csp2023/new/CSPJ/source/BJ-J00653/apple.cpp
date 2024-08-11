#include<bits/stdc++.h>
using namespace std;

const long long N = 1e9+5;

long long n,ans,cnt;

long long a[N];

void dfs(long long x)
{
	if(x == 1)
	{
		cnt += 1;
		return;
	}	
	
	else if(x == 2)
	{
		cnt += 2;
		return;
	}	
	
	else if(x == 3)
	{
		cnt += 3;
		return;
	}
	
	else if(x == 4)
	{
		cnt += 1;
		return;
	}
	
	else if(x == 5)
	{
		cnt += 4;
		return;
	}
	
	else if(x == 6)
	{
		cnt += 2;
		return;
	}	
	else if(x == 7)
	{
		cnt += 1;
		return;
	}	
	
	else
	{
		if(x % 3 != 0)
        {
			cnt++;
			dfs(x-(x/3)-1);
        }
        else
        {
			cnt++;
			dfs(x-(x/3));
		}
	}		
}	
	
int main()
{
    
	freopen("apple.in","r",stdin);
	freopen("apple.out","w",stdout);
	
	cin>>n;
	
    if(n <= 3)
    {
        cout<<n<<" "<<n;
    }

    else
    {
        while(n > 1)
        {
            if(n % 3 != 0)
            {
                n = n-(n/3)-1;
                ans++;
            }
            else
            {
				n = n-(n/3);
				ans++;
			}
		}

        if(n % 3 == 1)
        {
			cnt = 1;
		}
		else
		{
			dfs(n);
		}	

        cout<<ans<<" "<<cnt;
    }
    return 0;
}
