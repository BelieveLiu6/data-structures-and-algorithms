#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2


#define LIST_INIT_SIZE 100//线性表存储空间的初始分配量
#define LISTINCREMENT 10//线性表存储空间的分配增量
typedef struct {
    int *elem;//存储空间基址
    int length;//当前长度
    int listsize;//当前分配的存储容量
}SqList;
//有序表初始化
int InitList_Sq(SqList *L){
    L->elem=(int *)malloc(LIST_INIT_SIZE*sizeof(int));
    if(!L->elem) exit(OVERFLOW);
    L->length=0;
    L->listsize=LIST_INIT_SIZE;
    return OK;
}
//插入操作
int ListInsert_Sq(SqList *L,int i,int e){//在顺序线性表L的第i个元素之前插入新的元素e 
    int *newbase,*q,*p;
    if(i<1||i>L->length+1) return ERROR; //i值不合法
    if(L->length>=L->listsize){//当前存储空间已满，增加分配
        newbase=(int *)realloc(L->elem,(L->listsize+LISTINCREMENT)*sizeof(int));//realloc函数重新分配内存空间
        if(!newbase) exit(OVERFLOW);
        L->elem=newbase;
        L->listsize+=LISTINCREMENT;
    }
    q=&(L->elem[i-1]);//获取插入位置的地址
    for(p=&(L->elem[L->length-1]);p>=q;--p) *(p+1)=*p;//插入位置及之后的元素右移
    *q=e;//插入e
    ++L->length;//表长增1 
    return OK;
}
//查找操作
int ListLocate_Sq(SqList L, int e) { // 在有序顺序线性表L中查找第一个值等于e的元素的位序   //先移位 再方数
    int i = 0; // 从索引 0 开始
    while (i < L.length && L.elem[i] != e) ++i; // 从表头开始查找，直到表尾或找到为止
    if (i < L.length) return i + 1; // 返回元素的位序（从 1 开始）
    else return 0; // 未找到元素
}
//删除操作
int ListDelete_Sq(SqList *L,int i,int *e){//在顺序线性表L中删除第i个元素，并用e返回其值
    int *p,*q;
    if(i<1||i>L->length) return ERROR;//i值不合法
    p=&(L->elem[i-1]);//p为被删除元素的位置
    *e=*p;//被删除元素的值赋给e
    q=L->elem+L->length-1;//L->elem首地址 +L->length-1 移动到末尾元素位置
    for(++p;p<=q;++p)  //++p指向被删除元素的下一个元素
    *(p-1)=*p;//被删除元素之后的元素左移
    --L->length;//表长减1
    return OK;
}
//修改操作
int ListChange_Sq(SqList *L,int i,int e){//在顺序线性表L中修改第i个元素的值为e
    if(i<1||i>L->length) return ERROR;//i值不合法
    L->elem[i-1]=e;
    return OK;
}
//输出操作
void ListPrint_sq(SqList *L){
    int i;
    for(i=0;i<L->length;i++){
        printf("%d ",L->elem[i]);
    }
    printf("\n");
}



int main(){
    SqList L;
    if(InitList_Sq(&L)!= OK) //初始化失败
	{
        printf("InitList_Sq: 初始化失败!\n");
        return -1;
    }
    printf("InitList_Sq: 初始化成功!\n");
    for(int i=1;i<=10;i++){
        ListInsert_Sq(&L,i,i); //插入1-10
    }
    ListPrint_sq(&L);
    int e;
    ListDelete_Sq(&L,5,&e); //删除第5个元素
    printf("删除第5个元素:%d\n",e);
    printf("删除第5个元素后的顺序表:\n");
    ListPrint_sq(&L);
    ListChange_Sq(&L,5,100); //修改第5个元素的值为100
    printf("修改第5个元素的值为100后的顺序表:\n");
    ListPrint_sq(&L);
    int index=ListLocate_Sq(L,10); //查找值为100的元素
    printf("查找值为100的元素是第%d\n 个",index);
    return 0;
}