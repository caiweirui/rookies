#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct linknode
{
	int data;
	struct linknode *next;
};
struct linknode *Init_LinkList()
{
	struct linknode *header=(struct linknode*)malloc(sizeof(struct linknode));
	header->data=-1;
	header->next=NULL;
	struct linknode *prear=header;
	int val=-1;
	while(1)
	{
		scanf("%d",&val);
		if(val==-1)
		{
			break;
		}
		struct linknode *newnode=(struct linknode*)malloc(sizeof(struct linknode));
		newnode->data=val;
		newnode->next=NULL;
		prear->next=newnode;
		prear=newnode;
	}
}

void Insert_LinkList(struct linknode *header,int olddata,int newdata)
{
	if(NULL==header)
	{
		return;
	}
	//fuzhuzhizhen
	struct linknode *pprev=header;
	struct linknode *pcurrent=pprev->next;
	while(pcurrent!=NULL)
	{
		if(pcurrent!=NULL)
		{
			break;
		}
		pprev=pcurrent;
		pcurrent=pcurrent->next;
	}
	if(pcurrent==NULL)
	{
		return;
	}
	struct linknode *newnode=(struct linknode*)malloc(sizeof(struct linknode));
	newnode->data=newdata;
	newnode->next=newnode;
}
//
void Remove_LinkList(struct linknode *header,int deletedata)
{
	if(header==NULL)
	{
		return;
	}
	struct linknode *pprev=header;
	struct linknode *pcurrent=pprev->next;
	while(pcurrent!=NULL)
	{
		if(pcurrent!=NULL)
		{
			break;
		}
		pprev=pcurrent;
		pcurrent=pcurrent->next;
	}
	pprev->next=pcurrent->next;
	free(pcurrent);
}

void Foreach_LinkList(struct linknode)
{
	struct linknode *header=(struct linknode*)malloc(sizeof(struct linknode));
	if(NULL==header)
	{
		return;
	}
	struct linknode *pcurrent=header;
	while(*pcurrent!=NULL)
     {
          printf("%d ",pcurrent->data);
     }
     pcurrent=pcurrent->next;
}

void Destory_LinkList(struct linknode)
{
	if(NULL==header)
	{
		return;
	}
	struct Linknode *pcurrent=header;
	while(pcurrent!=NULL)
	{
		struct linknode *pnext=pcurrent->next;
		free(pcurrent);
	}
}

void Clear_LinkList(struct LinkNode *header)
{
	if(NULL==header)
	{
		return;
	}
	struct Linknode *pcurrent=header->next;
	while(pcurrent!=NULL)
	{
		struct linknode *pnext=pcurrent->next;
		free(pcurrent);
	}
}

 