#include <stdio.h>
#include <string.h>
#include <iostream>
#include <unistd.h>
using namespace std;
//原地算法，不依赖额外空间，或者很少的空间。 对等空间复杂度()


//冒泡排序
void show_array(int arr[], int len)
{
    for(int i = 0 ; i< len ;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void show_array_f(float arr[], int len)
{
    for(int i = 0 ; i< len ;i++)
    {
        printf("%f ",arr[i]);
    }
    printf("\n");
}

//冒泡排序
void pupplesort(int arr[] , int len)
{
    for(int i = 0 ; i < len -1 ;i ++)
    {
        for(int j = 0 ;j < len; j ++)
        {
            if (arr[j] > arr[j+1]) // > 稳定的  。如果>= 的话，说明就不稳定了。
            {
                arr[j]  = arr[j] ^ arr[j+1];
                arr[j+1]  = arr[j] ^ arr[j+1];
                arr[j]  = arr[j] ^ arr[j+1];
            }
        }
    //    show_array(arr,len);
    //    getchar();
    }
}

void selectsort(int arr[], int len)
{
    for(int i = 0 ; i < len -1 ;i ++)
    {
        int min_idx = i;
        for(int j = i + 1 ;j < len; j ++)
        {
            if(arr[min_idx] > arr[j])
            {
                min_idx = j;
            }
        }
        if (i != min_idx)
        {
            arr[i] = arr[i] ^ arr[min_idx];
            arr[min_idx] = arr[i] ^ arr[min_idx];
            arr[i] = arr[i] ^ arr[min_idx];
        }
     //   show_array(arr,len);
     //   getchar();
    }
}


int find_binaray(int arr[] , int len , int find)
{
    int low = 0;
    int high = len - 1;
    while ( low <= high)
    {
        int mid = (low + high) /2;
        if (arr[mid] == find)
        {
            return mid; 
        }else if (arr[mid] > find ){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return -1;
}

int find_binaray_r(int arr[] , int low , int high ,int find){
    if (low > high)
    {
        return -1; 
    }
    int mid = (low + high) / 2;
    if (arr[mid] == find ){
        return mid;
    }
    else if (arr[mid] > find) {
        return find_binaray_r(arr,low,mid -1 , find);
    }else{
        return find_binaray_r(arr,mid + 1, high, find);
    }
}

// 插入排序
void insert_sort(int * arr, int len) {
    for (int i = 1 ; i < len ; i++)
    {
        for (int j = i - 1 ;j >=0 ;j--)
        {
            if (arr[j] > arr[j + 1])
            {
                arr[j] = arr[j]^arr[j+1];
                arr[j+1] = arr[j]^arr[j+1];
                arr[j] = arr[j]^arr[j+1];
            }
        }
    }
}
//插入算法2
void insert_sort_1(int * arr, int len) {
    for (int i = 1 ; i < len ; i++)
    {
        int k = arr[i];
        int j = i;
        for (;j - 1 >= 0 && arr[j-1] > k ;j--)
        {
            arr[j] = arr[j-1];
        }
        arr[j] = k;
    }
}
//希尔排序
//希尔排序是1959年，Shell发明的，这是第一个突破O(n2)的排序算法，他与直接插入排序不同的是，
//他会优先比较距离较近(应该是远吧?)的元素。因此，希尔排序又叫做缩小增量排序。
//希尔排序的实质就是分组的插入排序
//(i) 不稳定，在交换的过程中，会改变元素的相对次序。
//(ii) 希尔排序的时间复杂度依赖于增量序列函数，所以分析起来比较困难，当n在某个特定范围的时候，希尔排序的时间复杂都约为O(n1.3)
//为什么希尔能突破O(n2)的界，可以用逆序数来理解，假设我们要从小到大排序，一个数组中取两个元素如果前面比后面大，则为一个逆序，
  //容易看出排序的本质就是消除逆序数，可以证明对于随机数组，逆序数是O(n2)的，
  //而如果采用“交换相邻元素”的办法来消除逆序，每次正好只消除一个，因此必须执行O(n2)的交换次数，这就是为什么冒泡、插入等算法只能到平方级别的原因，
  //反过来，基于交换元素的排序要想突破这个下界，必须执行一些比较，交换相隔比较远的元素，使得一次交换能消除多个逆序，
  //希尔、快排、堆排等等算法都是交换比较远的元素，只不过规则各不同罢了。
void shell_sort(int * arr, int len) {
    int gap = len /2;
    while (gap >= 1) {
        for (int i = gap ; i < len ; i++)
        {
            int k = arr[i];
            int j = i;
            for (;j - gap >= 0 && arr[j-gap] > k ;j = j-gap)
            {
                arr[j] = arr[j-gap];
            }
            arr[j] = k;
        }
        gap = gap/2;
    }
}

//快速排序
int getflag(int * arr ,int l ,int r)
{
    int flag = l         ;
    int temp = arr[flag] ;
    while (l < r)
    {
        while ( l < r && arr[r] >= temp )
            r--;
        arr[l] = arr[r];
        while ( l < r && arr[l] <= temp )
            l++;
        arr[r] = arr[l];
    }
    arr[l] = temp;
    return l;
}

void qsort(int * arr ,int l ,int r)
{
    if (l  >=  r)
        return;
    int index = getflag(arr,l,r);
    qsort(arr,l,index-1);
    qsort(arr,index+1,r);
}
/*
1. 快速排序中效率的主要来源之一是参考位置，在这里计算机硬件经过优化，以便访问彼此相邻的内存位置往往比访问分散在内存中的内存位置更快。
   快速排序中的分区步骤通常具有良好的局部性，因为它访问前后相邻的连续数组元素。
   因此，“快速排序”往往比“堆排序”之类的其他排序算法执行得好得多，尽管它通常执行大致相同数量的比较和交换，
   因为在“堆排序”的情况下，访问更加分散。
2. 此外，快速排序通常比其他排序算法快得多，因为它可以就地运行，而不需要创建任何辅助数组来保存临时值。
   与merge-sort相比，这是一个巨大的优势，因为分配和释放辅助数组所需的时间是显而易见的。
   就地操作也提高了quicksort的位置。
3. 当使用链接列表时，这些优点都不一定适用。因为链表单元格通常分散在内存中，所以访问相邻的链表单元格并没有局部性的好处。
   因此，quicksort的一个巨大的性能优势被吞噬了。类似地，就地工作的好处不再适用，
   因为merge-sort的链表算法不需要任何额外的辅助存储空间。
*/


//归并排序。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。
//合并两个有序数组
void merge_array(int * src,int l, int r, int mid, int * dest)
{
    int len = r -l +1;
    int *arr1 = src + l;
    int *arr2 = src + mid;
    int ll = mid - l;
    int rl = r - mid +1;
    int index = ll-- + --rl;  //3个数组 的标识索引 ，都指向数组的最后一位
  
    while (rl >= 0)
    {
        dest[index--] = (ll >= 0 && arr1[ll] > arr2[rl]) ? arr1[ll--] : arr2[rl--];
    }
    while (ll >= 0)
    {
        dest[index--] = arr1[ll--];
    }
  //  show_array(dest,len);
  //  getchar();
    //拷贝回src对应地址中
    while (len --)
    {
        src[l+len] = dest[len];
    }
    //memcpy(src+l ,dest ,len * sizeof(int));//拷贝回原来的数组，已经排序好的；
}

void merge_sort(int * arr,int l,int r, int* temp)
{   
    if (l == r)
    {
        return ;
    }
    int mid = ( r + l ) / 2; 
    merge_sort (arr, l       , mid , temp);
    merge_sort (arr, mid + 1 , r   , temp);
    merge_array(arr ,l , r,  mid+1 , temp);
}
//归并排序。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。。


//堆排序
// 带实现
//计数排序
/*
如果原始数列的规模是N，最大最小整数的差值是M，由于代码中第1、2、4步都涉及到遍历原始数列，运算量都是N，第3步遍历统计数列，运算量是M，所以总体运算量是3N+M，去掉系数，时间复杂度是O(N+M)。
至于空间复杂度，如果不考虑结果数组，只考虑统计数组的话，空间复杂度是O(M)。

虽然计数排序看上去很强大，但是它存在两大局限性：
1.当数列最大最小值差距过大时，并不适用于计数排序.比如给定20个随机整数，范围在0到1亿之间，此时如果使用计数排序的话，
  就需要创建长度为1亿的数组，不但严重浪费了空间，而且时间复杂度也随之升高。
2.当数列元素不是整数时，并不适用于计数排序.如果数列中的元素都是小数，比如3.1415，或是0.00000001这样子，则无法创建对应的统计数组，这样显然无法进行计数排序。
  正是由于这两大局限性，才使得计数排序不像快速排序、归并排序那样被人们广泛适用。
*/
void count_sort(int *arr ,int len ,int max_num)
{
    //新建统计数组
    int * temp = new int[max_num + 1]{0};
    for(int i = 0 ;i < len ;i++)
    {
        temp[arr[i]]++;
    }
    int index = 0;
    for(int j = 0 ; j < max_num + 1 ; j++ )
    {
        int count = temp[j];
        while(count--)
        {
            arr[index++] = j;
        }
    }
    delete[] temp;
}
//桶排序
/*算法：桶排序*/
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <vector>
using namespace std;
 
void bksort(float A[],int l,int h){
    int size = h - l + 1;
    vector<float> b[size];//有size个数据，就分配size个桶
    for(int i=l ; i <= h ; i++) {
        int bi = size * A[i];//元素A[i]的桶编号
        b[bi].push_back(A[i]);//将元素A[i]压入桶中
    }

    for(int i = 0; i < size; i++)
        sort(b[i].begin() , b[i].end());//桶内排序

    int idx = l;//指向数组A的下标
    for(int i = 0 ;i < size ;i++ ) {//遍历桶
        for(int j=0 ;j < b[i].size() ; j++) {//遍历桶内元素
            A[idx++] = b[i][j];
        }
    }

}
//假定：输入是由一个随机过程产生的[0, 1)区间上均匀分布的实数。
//将区间[0, 1)划分为n个大小相等的子区间（桶），每桶大小1/n：[0, 1/n)， [1/n, 2/n)， [2/n, 3/n)，…，[k/n, (k+1)/n )，
//…将n个输入元素分配到这些桶中，对桶中元素进行排序，然后依次连接桶输入0 ≤A[1..n] <1辅助数组B[0..n-1]是一指针数组，指向桶（链表）。
//当要被排序的数组内的数值是均匀分配的时候，桶排序使用线性时间（Θ（n））
void bucket_sort(float A[],float max ,float min,int len)
{
    // A 的数值线性计算到0～1的区间内
    int   bucket_num = len;
    float dur = (max - min) / bucket_num;
    vector<float>  buckt[bucket_num];

    for (int i = 0 ;i < bucket_num ; i++)
    {
        float slot = (A[i] - min) / dur;
        buckt[int(slot)].push_back(A[i]);
    }

    for (int i = 0; i < bucket_num;i++)
    {
        sort(buckt[i].begin(),buckt[i].end());
    }

    int start = 0;
    for (int i = 0 ;i < bucket_num;i++){
        for (int j = 0 ;j < buckt[i].size();j++)
        {
            A[start++] = buckt[i][j];
        }
    }
        
}

int maxbit(int data[], int n) 
{
    int d = 1; //保存最大的位数
    int p = 10;
    for(int i = 0; i < n; ++i)
    {
        while(data[i] >= p)
        {
            p *= 10;
            ++d;
        }
    }
    return d;
}
void radixsort(int data[], int n) //基数排序
{
    int d = maxbit(data, n);
    int tmp[n];
    int count[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (data[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++){
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶 ,记录要插入的尾数固定的 最大 index + 1
        }

        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (data[j] / radix) % 10;
            tmp[count[k] - 1] = data[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到data中
            data[j] = tmp[j];

        radix = radix * 10;
    }
}


int main() {

/*
    基数排序
    int  A[] = {66,457,23312,332,66,1,33,22,445,11345,783,283,99,22,123,345,532,356,233,11,2,444,43,2,22,982};
    radixsort (A,sizeof(A)/sizeof(int));
    show_array(A,sizeof(A)/sizeof(int)); 
*/
    /*
    桶排序
    float A[] = {0.78,0.17,0.39,0.26,0.72,0.94,0.21,0.12,0.23,0.68};
    bucket_sort(A,1.0,0.0,10);
    show_array_f(A,10); 
    */

    /*
    int arr[10] = {5,6,8,7,9,4,2,3,0,1};
    printf("ccccccccccccccccccccccc\n");
    pupplesort(arr,10);   
    show_array(arr,10);
   
    printf("xxxxxxxxxxxxxxxxxxxxxxx\n");
    int arr1[10] = {5,6,8,7,9,4,2,3,0,1};
    selectsort(arr1,10);   
    show_array(arr1,10);

    //int index = find_binaray(arr1,10,5);
    int index = find_binaray_r(arr1,0,9,5);
    printf("index = %d\n",index);
    */

    /*
    int arr[] = {5,6,8,7,9,4,2,172,2,0,112,11,2,2,3};
    int length = sizeof(arr) / sizeof(int);
    printf("ccccccccccccccccccccccc\n");
    insert_sort(arr,length);   
    show_array(arr,length); 
    */

    /*
    int arr[] = {5,6,8,7,9,4,2,172,2,0,112,11,2,2,3};
    int length = sizeof(arr) / sizeof(int);
    printf("ccccccccccccccccccccccc\n");
    shell_sort(arr,length);   
    show_array(arr,length); 
    */

    /*
    int arr[] = {5,6,8,7,9,4,2,172,2,0,112,11,2,2,3};
    int length = sizeof(arr) / sizeof(int);
    printf("ccccccccccccccccccccccc\n");
    qsort(arr,0,length -1);   
    show_array(arr,length); 
    */

    // 归并算法搞定
    //int arr[] = {9,4,8,6};
    /*
    int arr[] = {1,2,8,10,12,9,11,28};
    int length = sizeof(arr) / sizeof(int);
    int *temp = new int[length];
    printf("ccccccccccccccccccccccc\n");
    merge_sort(arr,0,length -1,temp);   
    show_array(arr,length); 
    */

    /* 计数排序
    int arr[] = {5,6,8,7,9,4,2,172,2,0,112,11,2,2,3};
    int length = sizeof(arr) / sizeof(int);
    printf("ccccccccccccccccccccccc\n");
    count_sort(arr , length , 200);   
    show_array(arr , length ); 
    */

    

}