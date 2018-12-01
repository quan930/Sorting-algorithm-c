#include "stdio.h"
#include "linked_list.c"
#include "time.h"
/**
 * 桶排序
 * @param array 数组
 * @param length 数组长度
 * @param range 数组范围 0～range
 */
void _bucket_sort(int *array,int length,int range){
    Node **bucket;//桶
    bucket = calloc(range,sizeof(Node*));//空桶
    Node *node;
    for (int i = 0; i < length; ++i) {//数据放入桶中,插入排序
        node = calloc(1,sizeof(Node));
        node->item = array[i];
        bucket[array[i]] = order_insert(bucket[array[i]],node,ascending_order);
    }
//    for (int i = 0; i < range; ++i) {
//        print_link(bucket[i]);
//        printf("\n");
//    }
    int data_size = 0;
    for (int i = 0; i < range; ++i) {//拷贝到原数组，并释放链表
        data_size =data_size+copy(bucket[i],&array[data_size]);
        free_linked(bucket[i]);//释放链表
    }
}

/**
 * 测试桶排序时间
 * @param array 数组
 * @param length 长度
 * @param range 数组范围 0～range
 * @return 桶排序时间(秒)
 */
double bucket_sort(int *array,int length,int range){
    clock_t start,finish;
    double time;
    start = clock();
    _bucket_sort(array,length,range);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}