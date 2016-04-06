#include<iostream>
#include<stdio.h>
#define INT_MIN 0x80000000;
using namespace std;

int maxsubarray = 0;

int  DaCMaxSubarray(int* N,int s,int e);
int  max3(int a, int b , int c); //return 三者最大值
int  cross(int* N,int s,int e);

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

    cout<<DaCMaxSubarray(N,0,n-1);
}


/*遞迴：每次把當前陣列分成兩半﹐分別找出左右兩邊的最大連續子陣列和﹐並且再計算左右最大連續子陣列和
  return 最大者*/

int DaCMaxSubarray(int* N,int s,int e)
{
   int mid = s + (e-s)/2;
   
   if(e==s)
   {
       return N[s];
   }else
   {
       cout<<s<<"???"<<e<<endl;
       
       return max3( DaCMaxSubarray(N,s,mid) , DaCMaxSubarray(N,mid+1,e) , cross(N,s,e));
   }
}

/* */
int max3(int a , int b , int c )
{
    int max = a;
    if(b>max)max = b;
    if(c>max)max = c;

    return max;
}
/*從mid分別往左右找最大和﹐然後相加兩者並return*/
int  cross(int* N,int s,int e)
{
    int mid = s + (e-s)/2;
    int rsum= N[mid+1] , lsum= N[mid]; //right sum ,left sum
    int tmp;

    tmp = rsum;
    for(int i=mid+2 ; i <= e ; i++)
    {
        tmp += N[i];
        if(tmp > rsum)rsum = tmp;
    
    }
    tmp = lsum;
    for(int i=mid-1 ; i >= s ; i--)
    {
        tmp += N[i];
        if(tmp > lsum)lsum = tmp;
    }

    return lsum + rsum ;
}

