#include<stdio.h>
#define mod 1000000007

void get_multi(long long int a[][2],long long int b[][2],long long int res[][2])
{
    int i,j,k;
    for(i=0;i<2;++i)
    {
        for(j=0;j<2;++j)
        {
            res[i][j]=0;
            for(k=0;k<2;++k)
            {
                res[i][j] += (a[i][k]*b[k][j])%mod;
                res[i][j] = res[i][j]%mod;
            }
        }
    }
}

void multi(long long int a[][2],long long int b[],long long int res[])
{
    
    res[0]=(a[0][0]*b[0]+a[0][1]*b[1])%mod;
    res[1]=(a[1][0]*b[0]+a[1][1]*b[1])%mod;
}

long long int get_fn(long long int n)
{
    long long int T1[2][2],T[2][2]={{1,1},{1,0}};
    long long int F1[2],F[]={3,2};
    long long int temp[2][2],res[2][2]={{1,0},{0,1}};
    
    if(n==1)
        return 2;
    if(n==2)
        return 3;
    n-=2;
    while(n)
    {
        if(n%2)
        {
            get_multi(T,res,temp);
            res[0][0]=temp[0][0];
            res[0][1]=temp[0][1];
            res[1][0]=temp[1][0];
            res[1][1]=temp[1][1];
        }
            get_multi(T,T,T1);
            T[0][0]=T1[0][0];
            T[0][1]=T1[0][1];
            T[1][0]=T1[1][0];
            T[1][1]=T1[1][1];
            n/=2;
    }
    multi(res,F,F1);
return F1[0]%mod;
}

int main()
{
int i,no_of_inputs;
long long int input;
scanf("%d",&no_of_inputs);
for(i=0;i<no_of_inputs;i++)
{    
    scanf("%lld",&input);
    printf("%lld\n",get_fn(input));
}
return 0;
}