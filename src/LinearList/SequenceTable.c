#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "LinearList/SequenceTable.h"


//-----线性表的静态分配顺序存储结构的基本操作函数实现-----//
Status InitList_Static(StaticSqList *L){ 
  //构造一个空的顺序表
  L->Length = 0;
  return OK;
}   

Status DestroyList_Static(StaticSqList *L){
  //销毁线性表L
  L->Length = 0;
  return OK;
}    

Status ClearList_Static(StaticSqList *L){
  //将L重置为空表
  L->Length = 0;
  return OK;
}     

Status ListEmpty_Static(StaticSqList *L){
  //判断表是否为空
  return (L->Length == 0) ? TRUE : FALSE;
}       

int ListLength_Static(StaticSqList *L){
  //返回L中数据元素个数
  return L->Length;
}        

Status GetElem_Static(StaticSqList *L, int i, ElemType* e){
  //用e返回L中第i个数据元素的值
  if(i < 1 || i > L->Length)
    return OVERFLOW;
  *e = L->data[i-1];
  return OK;
}

//返回第一个匹配的数据元素次序
Status LocateElem_Static (StaticSqList *L, ElemType e) {
    for (int i = 0; i < L->Length; ++i) {
        if(L->data[i] == e){
            return i;
        }
    }
    return 0;
}

//返回cur_e的前驱
Status PriorElem_Static(StaticSqList *L, ElemType cur_e, ElemType *pre_e){
    int curIndex = LocateElem_Static(L, cur_e);
    if( curIndex > 0 ){
        *pre_e = L->data[curIndex - 1];
        return OK;
    }
    return ERROR;
}

//返回cur_e的后继
Status NextElem_Static(StaticSqList *L, ElemType cur_e, ElemType *next_e){
    int curIndex = LocateElem_Static(L, cur_e);
    if(curIndex < L->Length-1){
        *next_e = L->data[curIndex + 1];
        return OK;
    }
    return ERROR;
}

//在L的第i个位置上插入e
Status ListInsert_Static(StaticSqList *L, int i, ElemType e){
    //1、范围检查
    if ( i<0 || i > L->Length ||i > MaxSize-1 ) {
        return OVERFLOW;
    }
    for (int j = L->Length; j > i; j--) {
        L->data[j] = L->data[j-1];
    }
    L->data[i] = e;
    L->Length++;
    return OK;
}

//在L的第i个位置删除元素
Status ListDelete_Static(StaticSqList *L, int i, ElemType *e){
    if (i >= L->Length || i < 0 ) {
        return OVERFLOW;
    }
    *e = L->data[i];
    for (int j = i; j < L->Length-1; j++) {
        L->data[j] = L->data[j+1];
    }
    L->Length--;
    return OK;
}

//打印顺序表
Status ListPrint_Static(StaticSqList *L){
    for (int i = 0; i < L->Length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("end\n");
    return OK;
}

//辅助函数
//参数检查
Status checkParameterSqList(IndexType index){

}

//创建一个Demo顺序表
Status createDemoSqList(StaticSqList *L, int count){
    L->Length = count;
    srand((unsigned int)time(NULL));
    for (int i = 0; i < count; i++) {
        L->data[i] = rand()%100;
    }
    //ListPrint_Static(L);
    return OK;
}

//-----线性表的动态分配顺序存储结构的基本操作函数实现-----//
Status InitList_Dynamic(DynamicSqList* L){
  //构造一个空的顺序表
  L->elem = (ElemType*)malloc(sizeof(ElemType)*LIST_INIT_SIZE);
  if(!L->elem) exit(OVERFLOW);          //存储分配失败
  L->Length = 0;                        //空表长度为0
  L->ListSize = LIST_INIT_SIZE;         //初始存储容量
  return OK;
}

Status DestroyList_Dynamic(DynamicSqList* L){
  L->Length = 0;
  L->ListSize = 0;
  free(L->elem);
  return OK;
  //销毁线性表·
} 
Status ClearList_Dynamic(DynamicSqList* L){
  //将L重置为空表 
  L->Length = 0;
  return OK;
}  

Status ListEmpty_Dynamic(DynamicSqList* L){
  //判断表是否非空
  return (L->Length == 0) ? TRUE : FALSE;
}    

int ListLength_Dynamic(DynamicSqList* L){
  //返回L中数据元素个数
  return L->Length;
}       

Status GetElem_Dynamic(DynamicSqList *L, int i, ElemType* e){
  //用e返回L中第i个数据元素的值
  if(i < 1 || i > L->Length)
    return OVERFLOW;
  *e = L->elem[i];
  return OK;
}

Status LocateElem_Dynamic (DynamicSqList *L, int e) {
    for (int i = 0; i < L->Length; ++i) {
        if(L->elem[i] == e){
            return i;
        }
    }
    return 0;
}

//返回cur_e的前驱
Status PriorElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *pre_e){
    int curIndex = LocateElem_Dynamic(L, cur_e);
    if ( curIndex > 0 ){
        *pre_e = L->elem[curIndex-1];
        return OK;
    }
    return ERROR;
}

//返回cur_e的后继
Status NextElem_Dynamic(DynamicSqList *L, ElemType cur_e, ElemType *next_e){
    int curIndex = LocateElem_Dynamic(L, cur_e);
    if (curIndex < L->Length-1){
        *next_e = L->elem[curIndex+1];
        return OK;
    }
    return ERROR;
}

//在L的第i个位置上插入e
Status ListInsert_Dynamic(DynamicSqList *L, int i, ElemType e) {
    if (i < 0 || i > L->Length) {
        return OVERFLOW;
    }
    if (i == L->ListSize){
        if(!IncreaseSize(L)){
            return OVERFLOW;
        }
    }
    for (int j = L->ListSize; j > i; j--){
        L->elem[j] = L->elem[j-1];
    }
    L->elem[i] = e;
    L->Length++;
    return OK;
}

//在L的第i个位置删除元素
Status ListDelete_Dynamic(DynamicSqList *L, int i, ElemType *e){
    if (i >= L->Length || i < 0) {
        return OVERFLOW;
    }
    *e = L->elem[i];
    for(int j = i; j < L->Length-1; j++){
        L->elem[j] = L->elem[j+1];
    }
    L->Length--;
    return OK;
}

//打印顺序表
Status ListPrint_Dynamic(DynamicSqList *L){
    for (int i = 0; i < L->Length; i++){
        printf("%d ", L->elem[i]);
    }
    printf("end\n");
    return OK;
}

//动态增加顺序表长度
Status IncreaseSize(DynamicSqList *L){
    int *p = L->elem;
    L->elem = (ElemType* )malloc((L->ListSize+LISTINCREAMENT)*sizeof(ElemType));
    if (!L->elem){
        exit(-1);
        return ERROR;
    }
    for (int i = 0; i < L->Length; i++){
        L->elem[i] = p[i];
    }
    L->ListSize += LISTINCREAMENT;
    free(p);
    return OK;
}

//------------数组有关查找算法的实现(以静态顺序表为例)-----------//
//默认升序
//折半查找
int binarySearch(StaticSqList L, ElemType key){
    int low = 0;
    int high = L.Length - 1;
    while ( low < high ){
        int mid = (low + high)/2;
        if ( L.data[mid] == key ){
            return mid;
        } else if ( L.data[mid] < key ){
            low = mid + 1;
        } else if ( L.data[mid] > key ){
            high = mid - 1;
        }
    }
    return FALSE;
}



//------------数组有关排序算法的实现----------//
//快速排序
Status quickSort(ElemType arr[], IndexType low, IndexType high){
    //参数检查
    if ( low < high ){
        IndexType piovtIndex = partition(arr, low, high);
        quickSort(arr, low, piovtIndex - 1);
        quickSort(arr, piovtIndex + 1, high);
    }
    return OK;
}

IndexType partition(ElemType arr[], IndexType low, IndexType high){

    ElemType piovt = arr[low];
    while ( low < high ) {
        while ( low < high && arr[high] >= piovt ) high--;
        arr[low] = arr[high];
        while ( low < high && arr[low] <=piovt ) low++;
        arr[high] = arr[low];
    }
    arr[low] = piovt;

    return low;
}

//归并排序
Status Merge(StaticSqList* L, IndexType low, IndexType mid, IndexType high){
    //ElemType* arr = (ElemType*)malloc(sizeof(ElemType)*(low-high+1));
    ElemType arr[MaxSize] = {0};
    //copy数组
    for (int i = low; i <= high; i++){
        arr[i] = L->data[i];
    }

    int indexI = low;
    int indexJ = mid+1;
    int index = low;
    while (indexI <= mid && indexJ <= high){
        if ( arr[indexI] <= arr[indexJ] ){
            L->data[index++] = arr[indexI++];
        } else if ( arr[indexI] > arr[indexJ] ){
            L->data[index++] = arr[indexJ++];
        }
    }

    while ( indexI <= mid )  L->data[index++] = arr[indexI++];
    while ( indexJ <= high ) L->data[index++] = arr[indexJ++];

//    free(arr);
    return OK;
}

Status mergeSort(StaticSqList* L, IndexType low, IndexType high){
    int mid = (low + high)/2;
    if ( low < high ){
        mergeSort(L, low, mid);
        mergeSort(L, mid+1, high);
        Merge(L, low, mid, high);
    }

    return OK;
}

//------------数组有关操作算法的实现(参考王道强化DS打卡表)-----------//
//顺序表前后翻转
Status reverseSqList(StaticSqList* L){
    for (int front = 0, end = L->Length-1; front < end; front++, end--){
        //交换操作
        int temp = L->data[front];
        L->data[front] = L->data[end];
        L->data[end] = temp;
    }
    return OK;
    //时间复杂度：O(n)
    //空间复杂度：O(1)
}


//删除数组中的指定元素X
Status removeElemSqList(StaticSqList* L, ElemType x){
    int index = 0;
    while ( index < L->Length ) {
        if ( L->data[index] == x ){
            //末尾元素为x的情况，将末尾数组元素舍去（即数组长度-1），后继续访问倒数第二个
            while (L->data[L->Length-1] == x)   (L->Length)--;

            //该情况为index后续全为x，故while循环一直舍去至index> L->Length-1
            if (index > L->Length-1) break;

            L->data[index] = L->data[L->Length-1];
            (L->Length)--;

        }
        index++;
    }

    return OK;
    //时间复杂度：O(n)
    //空间复杂度：O(1)
}


//合并两个有序数组;
Status mergeOrderSqList(StaticSqList* L1, StaticSqList* L2, StaticSqList* L3){
    int ansIndex = 0;
    int index1 = 0, index2 = 0;

    while (index1 < L1->Length && index2 < L2->Length){
        if ( L1->data[index1] <= L2->data[index2] ){
            L3->data[ansIndex++] = L1->data[index1++];
            L3->Length++;
        } else {
            L3->data[ansIndex++] = L2->data[index2++];
            L3->Length++;
        }
    }

    while ( index1 < L1->Length ) {
        L3->data[ansIndex++] = L1->data[index1++];
        L3->Length++;
    }

    while ( index2 < L2->Length ) {
        L3->data[ansIndex++] = L2->data[index2++];
        L3->Length++;
    }

    return OK;
}












