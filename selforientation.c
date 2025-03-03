#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *link;
}node;

node *start=NULL;
void display()
{
    node *temp;
    if(start==NULL)
    printf("NO LINKED LIST AVAILABLE\n");
    else{
        temp=start;
        while(temp->link!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->link;
        }
        printf("%d->NULL\n",temp->data);
    }
}
node *append(int data)
{
    node *temp,*curr;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(start==NULL)
    {
        temp->link=NULL;
        start=temp;
        return start;
    }
    else
    {
        temp->link=NULL;
        curr=start;
        while(curr->link!=NULL)
        {
            curr=curr->link;
        }
        curr->link=temp;
        return start;
    }
}
node *insert_begin(int data)
{
    node *temp;
    temp=(node *)malloc(sizeof(node));
    temp->data=data;
    if(start==NULL)
    {
        temp->link=NULL;
        start=temp;
    }
    else
    {
        temp->link=start;
        start=temp;
        
    }
    return start;
}
node *self(int item)
{
    node *temp,*curr,*prev;
    if(start==NULL)
    {
        printf("WRONG CHOICE\n");
        return 0;
    }
    else
    {
        curr=start;
        while(curr->data!=item && curr->link!=NULL)
        {
            prev=curr;
            curr=curr->link
        }
        if(curr->data==item)
        {
            if(curr->link==NULL)
            {
                curr->link=start;
                start=curr;
                prev->link=NULL;
            }
        prev->link=curr->link;
        curr->link=start;
        start=curr;
        }
    return start;
    }
}
void fmem()
{
    node *prev;
    while(start->link!=NULL)
    {
        prev=start;
        start=start->link;
        free(prev);
    }
    free(start);
}
int main()
{
    int choice,item,data,val;
    do
    {
    printf("PRESS '1' TO DISPLAY\n");
    printf("PRESS '2; TO APPEND\n");
    printf("PRESS '3' TO INSERT BEGIN\n");
    printf("PRESS '4' TO FETCH AN ITEM\n");
    printf("PRESS '5' TO EXIT\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
        display();
        break;
    case 2:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&val);
        append(val);
        break;
    case 3:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&data);
        insert_begin(data);
        break;
    case 4:
        printf("ENTER THE VALUE TO FETCH\n");
        scanf("%d",&item);
        self(item);
        printf("YOUR %d ITEM IS NOW AT BEGGINING ",item);
        break;
    case 5:
        printf("BYE\n");
        break;
    default:
        printf("WRONG CHOICE\n");
    }
} while (choice!=5);
fmem();
return 0;
}