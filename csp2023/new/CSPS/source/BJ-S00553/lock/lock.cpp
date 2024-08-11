#include<bits/stdc++.h>
using namespace std;
int same[5],dif[5];
int scnt = 0,dcnt = 0;

int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
//==========≥ı º==========
    int n;
    int ans = 0;
    cin >> n;
    int a[n][5];

    for(int i = 0 ; i < n  ; i++)
    {
        for(int j = 0 ; j < 5 ; j ++)
        {
            cin >> a[i][j];
        }
    }
//==========≥ı º==========


    if(n == 1)
    {
        ans = 81;
    }
    else if(n == 2)
    {
		//bool pd;
		for(int i = 0 ; i < 5 ; i ++)
        {
            if(a[0][i] == a[1][i])
            {
                same[scnt] = i;
                scnt = scnt + 1;
            }
            else
            {

                dif[dcnt] = i;
                dcnt = dcnt + 1;
            }
        }
        //cout << "scnt = " << scnt << endl;
        //cout << "dif[0] = " << dif[0] << endl;
        
        if(scnt < 3)
        {
            ans = 0;
        }
        
        if(scnt == 4)
        {
			if(a[0][dif[0]] == a[1][dif[0]])
			{
				ans = 10 - 1;
			}
			else
			{
				ans =  10  - 2;
			}
		}
		
		
		
		if(scnt == 3)
		{
			
                    int k1 = a[1][dif[0]];
                    int k2 = a[1][dif[1]];
                    int cmp1 = 10 + a[0][dif[0]];
                    int cmp2 = 10 + a[0][dif[1]];


                    if(((cmp1 - k1) % 10) == ((cmp2 - k2) % 10))
                    {
						ans = 8;
					}
					else
					{
						ans = 0;
					}
		}
		if(scnt == 5)
		{
			ans = 81;
		}
	}
    else
    {
		ans = 10 - n;
	}


    cout << ans;

    return 0;
}