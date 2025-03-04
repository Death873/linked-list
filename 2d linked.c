#include<stdio.h>
#include<stdlib.h>

typedef struct Node{

    int data;
    struct Node *prev;
    struct Node *next;
}link2;

link2 *start=NULL;

void display()
{link2 *temp;
    if(start==NULL)
    {
        printf("NO LINKED LIST AVAILABLE\n");
        return ;
    }
    else
    {temp=start;
        while(temp->next!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}

link2 *append(int data)
{
    link2 *temp,*previ;
    temp=(link2*)malloc(sizeof(link2));
    temp->data=data;
    if(start==NULL)
    {
        temp->next=NULL;
        temp->prev=NULL;
        start=temp;
    }
    else
    {
        previ=start;
        while(previ->next!=NULL)
        {
            previ=previ->next;
        }
        previ->next=temp;
        temp->prev=previ;
        temp->next=NULL;
    }
    return start;
}

link2 *insert_begin(int data)
{
    link2 *temp;
    temp=(link2 *)malloc(sizeof(link2));
    temp->data=data;
    temp->prev=NULL;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->next=start;
        start->prev=temp;
        start=temp;
    }
    return start;
}

link2 *insert_pos(int data,int pos)
{
    link2 *temp,*curr;
    char ch;
    int i=0;
    temp=(link2*)malloc(sizeof(link2));
    temp->data=data;
    if(start==NULL || pos<=0)
    {
        printf("WRONG CHOICE\n");
        printf("DO YOU WANT TO INSERT BEGIN?     Y/N\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        insert_begin(data);
        else
        return 0;
    }
    else if(pos==1)
    {
        insert_begin(data);
        return 0;
    }
    else
    {
        curr=start;
        while(i<pos-1 && curr->next!=NULL)
        {
            curr=curr->next;
            i++;
        }
        if(i==pos-1)
        {
            if(curr->next==NULL)
            {
                append(data);
                return 0;
            }
        temp->prev=curr->prev;
        temp->next=curr->next;
        curr->prev=temp;
        curr->prev->next=temp;
        }

        else
        {
        printf("WRONG CHOICE\n");
        printf("DO YOU WANT TO INSERT END?     Y/N\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        append(data);
        else
        return 0;
        }
    }
}

link2 *insert_before(int data,int sval)
{
    link2 *temp,*curr;
    char ch;
    temp=(link2*)malloc(sizeof(link2));
    temp->data=data;
    if(start==NULL)
    {
        printf("wrong choice\n");
        printf("DO YOU WANT TO INSERT THIS VALUE AT BEGINNING?   Y/N\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        insert_begin(data);
        else
        return 0;
    }
    else
    {
        curr=start;
        while(curr->data!=sval && curr->next!=NULL)
        {
            curr=curr->next;
        }
        if(curr->data==sval)
        {
            if(curr->next==NULL)
            {
                append(data);
                return 0;
            }
            temp->next=curr;
            temp->prev=curr->prev;
            curr->prev->next=temp;
            curr->prev=temp;
            return start;
        }
        else
        {
            printf("wrong choice\n");
            printf("DO YOU WANT TO INSERT THIS VALUE AT END?    Y/N\n");
            getchar();
            scanf("%c",&ch);
            if(ch== 'y' || ch=='Y')
            append(data);
            else
            return 0;
        }
    }
}

link2 *insert_after(int data, int sval)
{
    link2 *temp,*curr;
    char ch;
    temp=(link2*)malloc(sizeof(link2));
    temp->data=data;
    if(start==  NULL)
    {
        printf("wrong choice\n");
        printf("DO YOU WANT TO INSERT THIS VALUE AT BEGINNING?   Y/N\n");
        getchar();
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        insert_begin(data);
        else
        return 0;
    }
    else
    {
        curr=start;
        while(curr->data!=sval && curr->next!=NULL)
        curr=curr->next;
        if(curr->data==sval)
        {
            if(curr->next==NULL)
            {
                append(data);
                return 0;
            }
            temp->next=curr->next;
            temp->prev=curr;
            curr->next->prev=temp;
            curr->next=temp;
            return start;
        }
        else
        {
            printf("wrong choice\n");
            printf("DO YOU WANT TO INSERT THIS VALUE AT END?    Y/N\n");
            getchar();
            scanf("%c",&ch);
            if(ch== 'y' || ch=='Y')
            append(data);
            else
            return 0;
        }
    }
}

void delete_begin()
{
    link2 *temp;
    if(start==NULL)
    {
        printf("WRONG CHOICE\nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
        return;
    }
    else if(start->next==NULL)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
 }
 else
 {
    temp=start;
    start=start->next;
    start->prev=NULL;
    printf("DELETED VALUE=%d\n",temp->data);
    free(temp);
 }
}
void delete_end()
{
    link2 *temp;
    if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED");
    return;
 }
 else if(start->next==NULL)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
}
else 
 {
  temp=start;
  while (temp->next->next!=NULL)
  {
    temp=temp->next;
  }
  printf("DELETED VALUE=%d\n",temp->next->data);
  free(temp->next);
  temp->next=NULL;
 }
}

void delete_pos(int pos)
{
    link2 *curr;
    int i=0;
    char ch;
    if(start==NULL || pos<=0)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
    return ;
 }
 else if (pos==1)
{
    delete_begin();
    return;
 }
 else
 {
    curr=start;
    while(i<pos && curr->next!=NULL)
    {
        curr=curr->next;
        i++;
    }
    if(i==pos)
    {
        if(curr->next==NULL)
        {
            delete_end();
            return;
        }
    printf("DELETED VALUE=%d\n",curr->data);
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    free(curr);
    }
    else
    {
        printf("POSITION OUT OF THE LIST\n");
        printf("DO YOU WANT TO DELETE END?      Y/N\n");
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            delete_end();
            return;
        }
        else
        return;
    }
 }
}


void delete_val(int sval)
{
link2 *curr;
char ch;
if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
    return;
 }
 else if(start->next==NULL && start->data==sval)
 {
    delete_begin();
    return ;
 }
 else
 {
    curr=start;
    while(curr->data!=sval && curr->next!=NULL)
    {
        curr=curr->next;
    }
    if(curr->data==sval)
    {
        if(curr->next==NULL)
        {
            delete_end();
            return;
        }
    printf("DELETED VALUE=%d\n",curr->data);
    curr->prev->next=curr->next;
    curr->next->prev=curr->prev;
    free(curr);
    }
    else
    {
        printf("POSITION OUT OF THE LIST\n");
        printf("DO YOU WANT TO DELETE END?      Y/N\n");
        scanf("%c",&ch);
        if(ch=='y' || ch=='Y')
        {
            delete_end();
            return;
        }
        else
        return;
    }
    }
}
link2 *reverse()
{
    link2 *temp,*curr;
    
    if(start==NULL)
    {
        printf("NO LINKED LIST AVAILABLE TO REVERSE\n");
        return 0;
    }
    else
    {curr=start;
        while(curr!=NULL)
        {
            temp=curr->prev;
            curr->prev=curr->next;
            curr->next=temp;
            curr=curr->prev;
        }
        start=temp->prev;
        return start;
    }
}

void freemem()
{
     link2 *prev;
     if(start!=NULL)
     {
    while(start->next!=NULL)
    {
        prev=start;
        start=start->next;
        free(prev);
    }
    free(start);
}
}

int main()
{
    int choice,data,value,val,pos,sval;
    do{
    printf("PRESS '1' TO DISPLAY\n");
    printf("PRESS '2' TO APPEND\n");
    printf("PRESS '3' TO INSERT BEGIN\n");
    printf("PRESS '4' TO INSERT AT ANY POSITION\n");
    printf("PRESS '5' TO INSERT BEFORE VALUE\n");
    printf("PRESS '6' TO INSERT AFTER A VALUE\n");
    printf("PRESS '7' TO DELETE BEGIN\n");
    printf("PRESS '8' TO DELETE END\n");
    printf("PRESS '9 TO DELETE AT ANY POSITION\n" );
    printf("PRESS '10' TO DELETE A VALUE\n");
    printf("PRESS '11' TO REVERSE THE LIST\n");
    printf("PRESS '12' TO EXIT\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
            display();
            break;
        case 2:
            printf("ENTER THE VALUE TO STORE:     ");
            scanf("%d",&data);
            append(data);
            break;
        case 3:
            printf("ENTER THE VALUE TO STORE:     ");
            scanf("%d",&value);
            insert_begin(value);
            break;
        case 4:
            printf("ENTER THE VALUE TO STORE     ");
            scanf("%d",&val);
            printf("ENTER THE POSITION    ");
            scanf("%d",&pos);
            insert_pos(val,pos);
            break;
        case 5:
            printf("ENTER THE VALUE TO STORE      ");
            scanf("%d",&val);
            printf("ENTER THE SEARCHING VALUE     ");
            scanf("%d",&sval);
            insert_before(val,sval);
            break;
        case 6:
            printf("ENTER THE VALUE TO STORE      ");
            scanf("%d",&val);
            printf("ENTER THE SEARCHING VALUE     ");
            scanf("%d",&sval);
            insert_after(val,sval);
            break;
        case 7:
            delete_begin();
            break;
        case 8:
            delete_end();
            break;
        case 9:
            printf("ENTER THE POSITION    ");
            scanf("%d",&pos);
            delete_pos(pos);
            break;
        case 10:
            printf("ENTER THE SEARCHING VALUE     ");
            scanf("%d",&sval);
            delete_val(sval);
            break;
        case 11:
        	reverse();
        	break;
        case 12:
            printf("BYE\n");
            break;
        default:
            printf("ENTER A VALID CHOICE\n");
            break;
    }
}while(choice!=12);
freemem();
}
