#include <stdio.h>  
#include <stdlib.h>  
struct node    
{  
    int data;    
    struct node * next;    
};    
typedef struct node NODE;   
typedef struct node * PNODE;  
PNODE constructlist( PNODE head, int num );  
void outlist( PNODE head );  
void deleteneg( PNODE head )  
{    
   PNODE p=NULL,q=head;
   for(p=head->next;p!=NULL;q=p,p=p->next)
{
    while(p->data<0)
    {
      if(p->next==NULL)
     {
      q->next=NULL;
       break;
     }
      else
      p=p->next;
    }
     if(p->data>0)
     q->next=p;
  }
  return;
}
int main ( )    
{   int num=1;    
    PNODE head;    
    head = (PNODE)malloc( sizeof(NODE) );    
    head->next = NULL;    
    head->data = -1;    
    
    while ( num!=0 )    
    {   scanf("%d", &num);    
        if ( num!=0 )    
           constructlist (head, num);    
    }    
    deleteneg( head );  
    outlist( head );    
    return 0;    
}    
PNODE constructlist( PNODE head, int num )  
{   PNODE p;  
    p = (PNODE)malloc( sizeof(NODE) );   
    p->data = num;  
    p->next = head->next;   
    head->next = p;  
    return head;  
}  
  
void outlist( PNODE head )    
{   PNODE p;    
    p = head->next;    
    while ( p != NULL )    
    {   printf("%d\n", p->data);    
        p = p->next;    
    }    
}    
