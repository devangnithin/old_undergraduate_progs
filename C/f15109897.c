#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct node
{
	int id;
	char name[20];
	int sem;
	struct node *link;
};
typedef struct node NODE;

NODE insert_front(int id, char name[],int sem, NODE first)
{
	NODE *temp;
	temp=(NODE*)malloc(sizeof(struct node));
	temp->id=id;
	strcpy(temp->name,name);
	temp->sem=sem;
	temp->link=first;
	return temp;
}

NODE insert_rear(int id, char name[],int sem, NODE first)
{
NODE *temp,*cur;
int item;
	temp=(NODE)malloc(sizeof(struct node));
	temp->id=id;
	strcpy(temp->name,name);
	temp->sem=sem;
	temp->link=NULL;

	if(first==NULL) return temp;
	cur=first;

	while(cur->link!=NULL)
	{
		cur=cur->link;
	}
	cur->link=item;
	return first;
}

NODE insert_at_pos(int id, char name[],int sem, NODE first)
{
	NODE *temp,*cur,*prev;
	int pos,count;
	temp=(NODE)malloc(sizeof(struct node));
		temp->id=id;
	strcpy(temp->name,name);
	temp->sem=sem;
	temp->link=NULL;

	if(first==NULL) return temp;

	if(first==NULL)
	{
		printf("invalid position\n");
		return NULL;
	}

	if(pos==1)
	{
		temp->link=first;
		return temp;
	}

	count=1;
	prev=NULL;
	cur=first;

	while(cur!=NULL && count!=pos)
	{
		prev=cur;
		cur=cur->link;
		count++;
	}

	if(count==pos)
	{
		prev->link=temp;
		temp->link=cur;
		return first;
}


NODE delete_id(int id, char name[],int sem, NODE first)
{
	NODE *temp,*cur,*prev;
	if(first==NULL)
	{
		printf("student information does not exit\n");
		return NULL;
	}

	if(id==first->id)
	{
		temp=first->link;
		free(first);
	}

	prev=NULL;
	cur=first;
	while(cur!=NULL)
	{
		if(id==cur->id) break;
		prev=cur;
		cur=cur->link;
	}

	if(cur==NULL)
	{
		printf("student id not found\n");
		return first;
	}

	prev->link=cur->link;
	free(cur);
	return first;
}

NODE search_update(int id,NODE first)
{
	NODE *cur;
	if(first==NULL)
	{
		printf("student information does not exits\n");
		return;
	}

	cur=first;
	while(cur!=NULL)
	{
		if(id==cur->id) break;
		cur=cur->link;
	}

	if(cur==NULL)
	{
		printf("student id not found\n");
		retun first;
	}
	printf("enter id, name & sem to be manipulated\n");
	scanf("%d %s %d", &cur->id, cur->name, cur->sem);
}


NODE display(NODE first)
{
	NODE *cur;
	if(first==NULL)
	{
		printf("student information does not exits\n");
		return;
	}
	printf("id sem name\n");
	cur=first;
	while(cur!=NULL)
	{
	printf("%d%d%s\n",cur->id,cur->sem,cur->name);
	cur=cur->link;
	}
	}


	void main()
	{
	int choice,id,sem,pos;
	char name[20];
	first=NULL;
	for(;;)
	{
	printf("1->insert at front\n2->insert at back\n3insert at specified pos\n4->delete node\n5->search and update\n5->display\n7->exit\n");
	printf("enter ur choice\n");
	scanf("%d",&choice);
	switch(choice)
	{
	case 1:printf("enter id name and sem\n");
	scanf("%d%s%s",&id,name,&sem);
	first=insert_front(id,name,sem,first);
	break;
	case 2:printf("enter id name and sem\n");
	scanf("%d%s%s",&id,name,&sem);
	first=insert_rear(id,name,sem,first);
	break;
	case 3:printf("enter id name and sem\n");
	scanf("%d%s%s",&id,name,&sem);
	first=insert_at_position(id,name,sem,pos,first);
	break;
	case 4:printf("enter id\n");
	scanf("%d",&id);
	first=delete_id(id,first);
	break;
	case 5:printf("enter id\n");
	scanf("%d",&id);
	first=search_update(id,first);
	break;
	case 6:display(first);
	break;
	case 7:exit(0);
	default:printf("invalid choice\n");
	}
	}

