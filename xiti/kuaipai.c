/*************************************************************************
	> File Name: kuaipai.c
	> Author: 
	> Mail: 
	> Created Time: 2015年05月15日 星期五 23时20分33秒
 ************************************************************************/

#include <stdio.h>
#define Max 10
int Qkpass(int m[Max], int low, int high)
{
    
    m[0] = m[low];
    while(low < high){
        while(low < high && m[high] >= m[0]) --high;
        m[low] = m[high];
        while(low < high && m[low] <= m[0])  ++low;
        m[high] = m[low];
    }
    m[low]= m[0];
    return low;
}

void QKSort(int m[Max], int low, int high)
{
    int pos;
    if(low < high){
        pos = Qkpass(m, low, high);
        QKSort(m,low,pos-1);
        QKSort(m, pos+1, high);
    }
}
int main()
{
    int i;
    int m[Max]= {12,34,23,45,67,30,27,43,20,9};
    QKSort(m, 1, Max-1);
    for(i = 1; i < Max;i++ )
        printf("%d  ", m[i]);
    printf("\n");
    return 0;
}
