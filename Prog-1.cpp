#include<iostream>
#include<stdio.h>

#define INT_MIN 0x80000000 //定義int最小值


using namespace std;

void BFMaxSubarray(int* N,int n);

int main(void)
{
    /*宣告*/
    int N[10000];
    int n=0;
    char tmp;
    /*I/O*/
    while(cin>>tmp,tmp != 'x')
    {
        cin.putback(tmp);
        cin>>N[n++];
    }
    BFMaxSubarray(N,n);
}


void BFMaxSubarray(int* N,int n)
{
    int max=INT_MIN;

    for(int i=0; i<n ; i++)
    {
        int sum=0;
        for(int j=i ; j<n ; j++)
        {
            sum+=N[j];
            if(sum > max)max = sum;
        }
    }
    cout<<max;
}
