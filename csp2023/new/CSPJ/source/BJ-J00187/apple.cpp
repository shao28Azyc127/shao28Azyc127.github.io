#include<iostream>
#include <cmath>
using namespace std;
int main()

{
    int n,apple,num1;
    cin>>n;
    int n1=n;
    for(int i=1;i<=n;i++)
    {
        int sum=0;
        if(n1-1==0)
        {
            apple=i;
            break;
        }
        else if((n1-1)%3==0)
        {
            apple=i;
            break;
        }

        else
        {
            for(int j=0;j<n1;j++)
            {
                if((j*3)+1<=n1)
                {
                    sum++;
                }
            }
            n1=n1-sum;
        }
    }
    n1=n;
    for(int i=1;i<=n1;i++)
    {
        int sum=0;
            for(int j=0;j<n;j++)
            {
                if((j*3)+1<=n)
                {
                    sum++;
                }
            }
            n=n-sum;

            if(n==0)
            {
                num1=i;
                break;
            }
    }
    cout<<num1<<" "<<apple;
    return 0;
}