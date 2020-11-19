#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int dataType;
typedef struct node{
    dataType data;
    struct node*next;
}LinkList,node;

//创建链表
LinkList* CreateList() {
   LinkList *head; 
   head=(LinkList*)malloc(sizeof(LinkList));
   head->next=NULL;
   return head;
}

//求链表的元素个数
int Size(LinkList *l)  {
    node *p=l->next;
    int k=0;
    while (p) {
    k++;
    p=p->next;
    }
    return k;
}

//在链表1的第k个位置插入元素x
void Insert(LinkList *l,int k,dataType x) {
   if (k<1)exit(1);
   node *p =l;
   int i=0;
   while (p && i<k-1){
      p = p->next;
      i++;
   }
   if(!p) exit(1);
   node *s= (node*)malloc(sizeof(node));
   s->data=x;
   s->next=p->next;
   p->next=s;
 }

//删除链表1的第k个元素
void Delete(LinkList *l,int k)  {
  if (k<1) exit(1);
  node *p =l;
  int i=0;
  while (p->next && i<k-1)  {
     p =p->next;
     i++;
  }
  if (p->next==NULL) exit(1);
  node  *q = p->next;
  p->next = q->next;
  free (q);
}

//判断链表是否为空
int Empty(LinkList *l, int k)  {
   return l->next == NULL;
}
   //求链表1的第lk个元素的值
dataType GetData(LinkList *l,int k)  {
   if (k<1) exit(1);
   node *p = l;
   int i =0;
   while (p && i<k) {
       p = p->next;
       i++;
   }
   if (!p) exit(1);
   return p->data;
}

//在链表1中查找值为x的元素
node* Find(LinkList *l,dataType x) {
   node *p = l->next;                                                                                                           
   while (p && p->data!=x)
   p = p->next;
 return p;
}

//输出链表
void Print(LinkList *l) {
   node *p = l->next;
   while (p) {
      printf("%d", p->data);
      p =  p->next;
   }
   printf("\n");
}

//清空链表
void ClearList(LinkList *l) {
   node *p, *q;
   p = l->next;
   while (p) {
      q = p;
      p = p->next;
      free(q);
   }
   l->next = NULL;
}

int main() {
   LinkList  *list = CreateList();
   Insert(list, 1, 10);
   Insert(list, 1, 20);
   Delete(list, 2);
   Insert(list, 1, 30);
   Insert(list, 1, 40);
   printf("链表的元素个数为: %d\n", Size(list));
   Print(list);
   printf("链表的第二个元素为： %d", GetData(list, 2));
   system("pause");
}
                                             
