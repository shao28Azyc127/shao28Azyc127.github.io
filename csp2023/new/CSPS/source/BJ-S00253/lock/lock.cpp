#include <iostream>

using namespace std;


int main()
{
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    
    int n;
    int a[8][5];
    int tmp[5];
    int differents=0;
    cin >> n;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<5;j++)
        {
            cin >> a[i][j];
            if(i == 0)
            {
                tmp[j]=a[i][j];
            }
            else
            {
                if (tmp[j] != a[i][j])
                {
                    differents++;
                }
            }
        }
    }
    if (n == 1)
    {
        cout << 81 << endl;
        return 0;
    }
    else if (differents == 1)
    {
        cout << 10 << endl;
        return 0;
    }
    long long cnt=0;
    for (int s1=0;s1<10;s1++)
    {
        for (int s2=0;s2<10;s2++)
        {
            for (int s3=0;s3<10;s3++)
            {
                for (int s4=0;s4<10;s4++)
                {
                    for  (int s5=0;s5<10;s5++)
                    {
                        bool flag=0;
                        for (int i=0;i<n;i++)
                        {
                            bool check=0,check2=0;
                            int cn=-1;
                            
                            if (a[i][0]!=s1)
                            {
                                if (check2 == 1)
                                {
                                    flag=1;
                                    break;
                                }
                                if (check == 1 )
                                {
                                    if (cn!=0-1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        check2=1;
                                    }
                                }
                                else
                                {
                                    check=1;
                                    cn=0;
                                }
                                
                                
                            }

                            if (a[i][1]!=s2)
                            {
                                if (check2 == 1)
                                {
                                    flag=1;
                                    break;
                                }
                                if (check == 1)
                                {
                                    if (cn!=1-1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        check2=1;
                                    }
                                }
                                else
                                {
                                    check=1;
                                    cn=1;
                                }
                                
                                
                            }

                            if (a[i][2]!=s3)
                            {

                                if (check2 == 1)
                                {
                                    flag=1;
                                    break;
                                }
                                if (check == 1)
                                {
                                    if (cn!=2-1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        check2=1;
                                    }
                                }
                                else
                                {
                                    check=1;
                                    cn=2;
                                }
                                
                                
                            }

                            if (a[i][3]!=s4)
                            {
                                if (check2 == 1)
                                {
                                    flag=1;
                                    break;
                                }
                                if (check == 1)
                                {
                                    if (cn!=3-1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        check2=1;
                                    }
                                }
                                else
                                {
                                    check=1;
                                    cn=3;
                                }
                                
                                
                            }

                            if (a[i][4]!=s5)
                            {
                                if (check2 == 1)
                                {
                                    flag=1;
                                    break;
                                }
                                if (check == 1)
                                {
                                    if (cn!=4-1)
                                    {
                                        flag=1;
                                        break;
                                    }
                                    else
                                    {
                                        check2=1;
                                    }
                                }
                                else
                                {
                                    check=1;
                                    cn=4;
                                }
                                
                                
                            }
                            if (check==0)
                            {
                                flag=1;
                            }

                        }
                        if (!flag)
                        {
                            cnt++;

                        }
                        //cout << cnt << endl;
                        
                    }
                    
                    
                }
            }
        }
    }
    cout << cnt << endl;
    return 0;
}