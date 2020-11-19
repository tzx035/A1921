#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef int dataType;
typedef struct node{
    dataType data;
    struct node*next;
}LinkList,node;

//��������
LinkList* CreateList() {
   LinkList *head; 
   head=(LinkList*)malloc(sizeof(LinkList));
   head->next=NULL;
   return head;
}

//�������Ԫ�ظ���
int Size(LinkList *l)  {
    node *p=l->next;
    int k=0;
    while (p) {
    k++;
    p=p->next;
    }
    return k;
}

//������1�ĵ�k��λ�ò���Ԫ��x
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

//ɾ������1�ĵ�k��Ԫ��
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

//�ж������Ƿ�Ϊ��
int Empty(LinkList *l, int k)  {
   return l->next == NULL;
}
   //������1�ĵ�lk��Ԫ�ص�ֵ
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

//������1�в���ֵΪx��Ԫ��
node* Find(LinkList *l,dataType x) {
   node *p = l->next;                                                                                                           
   while (p && p->data!=x)
   p = p->next;
 return p;
}

//�������
void Print(LinkList *l) {
   node *p = l->next;
   while (p) {
      printf("%d", p->data);
      p =  p->next;
   }
   printf("\n");
}

//�������
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
   printf("�����Ԫ�ظ���Ϊ: %d\n", Size(list));
   Print(list);
   printf("����ĵڶ���Ԫ��Ϊ�� %d", GetData(list, 2));
   system("pause");
}
                                             
