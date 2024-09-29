#include <stdio.h>
#include <stdlib.h>

// 定义链表节点
typedef struct ListNode{
    int data; // 数据域
    struct  ListNode *Next; // 指针域
}ListNode;

//定义链表
typedef struct LinkedList
{
   ListNode *head; // 头节点
}LinkedList;

// 初始化链表
void initList(LinkedList *list){
    list->head = (ListNode *)malloc(sizeof(ListNode));   //带头节点的链表
    list->head->Next = NULL;//初始链表中一开始头节点的指针域为空
}
//创建节点
ListNode *createNode(int data){
    ListNode *node=(ListNode *)malloc(sizeof(ListNode));
    node->data=data;
    node->Next=NULL;
    return  node;
}
//在链表尾部插入节点
void insertAtEnd(LinkedList *l,int data){
    ListNode *node=createNode(data);
    ListNode *p=l->head;
    while(p->Next!=NULL){
       p=p->Next;
    }
    p->Next=node;
}
//在链表头部插入节点
void insertAtHead(LinkedList *l,int data){
    ListNode *node=createNode(data);
    node->Next=l->head->Next;
    l->head->Next=node;
}
//在指定位置插入节点
void insertAtPosition(LinkedList *l,int data,int position){//position从0开始
    ListNode *node=createNode(data);
    ListNode *p=l->head;//指向头节点
    for(int i=0;i<position&&p!=NULL;i++){ //position=0时，p指向头节点
        p=p->Next;//找到要插入位置的前一个节点
    }
    if(p==NULL){
        printf("位置无效\n");
        return;
    }
    node ->Next=p->Next;//新节点指向原来节点的下一个节点
    p->Next=node;//原来节点指向新节点   
}
//删除指定位置的节点
void deleteAtPosition(LinkedList *l,int pos){
    ListNode *p=l->head;
    for(int i=0;i<pos&&p!=NULL;i++){  //一个循环一个节点
        p=p->Next; //删除节点的前面一个节点
    }
    if(p==NULL||p->Next==NULL){
        printf("位置无效\n");
        return;
    }
    ListNode *q=p->Next; //q指向要删除的节点
    p->Next=q->Next;
    free(q);//释放节点
}
//删除链表中的所有节点
void deleteList(LinkedList *l){
    ListNode *p=l->head;
    while(p!=NULL){
        ListNode *q=p;
        p=p->Next;
        free(q);
    }
}

void printList(LinkedList *l){
    ListNode *p=l->head->Next;
    while(p!=NULL){
        ListNode *q=p;
        p=p->Next;
        printf("%d\n",q->data);
    }
}
int countList(LinkedList *L){
    ListNode *p=L->head;
    int count =0;
    while(p->Next!=NULL){
        count++;
        p=p->Next;
    }
    return count;
}
void main(){
    LinkedList l;
    initList(&l);
    insertAtEnd(&l,1);
    insertAtEnd(&l,2);
    insertAtEnd(&l,3);
    insertAtEnd(&l,4);
    insertAtEnd(&l,5);
    insertAtHead(&l,0);
    insertAtPosition(&l,6,6);
    deleteAtPosition(&l,6);
    printList(&l);
    printf("链表长度：%d\n",countList(&l));
    deleteList(&l);
}