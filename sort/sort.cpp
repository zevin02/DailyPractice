/*
快排：分治
1.确定分界点 q[l],q[r],q[(l+r)/2],三个点，一般我们用第一个点
2.调整区间，让左边的都小于分界点，右边的都大于分界点
3.递归的处理左右两段




思路：
左右各一个指针，以第一个值作为分界点x
1.i从左往右走，j从右往左走
2.i一直走发现，指向的值大于x停下来，j走，走到指向的值小于x停下来，两者交换，然后继续走，直到两者穿过
3.i左边的数都是小于等于x的，j右边的数都是大于等于x的
*/

#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e2;
int n;
int q[N];


void quick_sort(int q[],int l,int r)
{
    if(l>=r)//穿过或者重合之后就不用再往下走了
    return ;
    int x=q[l];//我们把左边的数据当作分界点，这边用l的话，下面的递归就要用j，不然会右边界问题
    int i=l-1;//我们都把它放在边界的左右两边
    int j=r+1;//每一次不管怎么样，先把指针往中间移动一位
    while(i<j)
    {
        do i++;while(q[i]<x);//
        do j--;while(q[j]>x);
        if(i<j)
        swap(q[i],q[j]);//交换，且还没有穿过去
    }
    //因为可能会穿过，所以j和j+1
    quick_sort(q,l,j);//递归处理左区间
    quick_sort(q,j+1,r);//递归处理右区间

}





int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
   
    quick_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d ",q[i]);

    return 0;
}