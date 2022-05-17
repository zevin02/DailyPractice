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


/*
归并排序
1.先找到中间点
2.递归左右两边
3.合并


*/

int tmp[N];
void merge_sort(int q[],int l,int r)
{
    if(l>=r)//如果l超过了r的话就没有必要再继续排下去了，如果相等的话，就只有一个值的话也是没有必要继续排下去的
    return;//直接返回

    int mid=(l+r)>>1;//把中间的数当作分界点
    merge_sort(q,l,mid);//递归左边的
    merge_sort(q,mid+1,r);//递归右边的
    int i=l;//i指向第一个数组的左边界
    int j=mid+1;//j指向第二个数组的左边界
    int k=0;
    while(i<=mid&&j<=r)//如果其中一方走完就停止循环
    {
        if(q[i]>q[j])//把两者中间较为小的数字放到数组里面
        {
            tmp[k++]=q[j++];
        }
        else 
        tmp[k++]=q[i++];
    }
    while(i<=mid)//后面的就全部直接都放进去
    tmp[k++]=q[i++];
    while(j<=r)
    tmp[k++]=q[j++];
    for(int i=l,j=0;i<=r;i++,j++)//把那些数字在拷贝回去原数组
    q[i]=tmp[j];//r是右边界的下标，l是q左边界的下标
    
    

}


int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&q[i]);
    }
   
    //quick_sort(q,0,n-1);
    merge_sort(q,0,n-1);
    for(int i=0;i<n;i++)
    printf("%d ",q[i]);

    return 0;
}