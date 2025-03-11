#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *link;
}node;
node *start=NULL;
node *last=NULL;
void display()
{
    node *temp;
    if(start==NULL)
    {
        printf("NO LINKED LIST AVAILABLE\n");
        return;
    }
    else{
        temp=start;
        while(temp->link!=start)
        {
            printf("%d\n",temp->data);
            temp=temp->link;
        }
        printf("%d\n",temp->data);
    }
}

node *append(int data)
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->data=data;
if(start==NULL)
{
    temp->link=temp;
    start=temp;
    last=temp;
}
else
{
   temp->link=start;
   last->link=temp;
   last=temp;
}
return start;
}

node *insert_begin(int data)
{
node *temp;
temp=(node *)malloc(sizeof(node));
temp->data=data;
if(start==NULL)
{
temp->link=temp;
start=temp;
last=temp;
}
else
{
temp->link=start;
last->link=temp;
start=temp;
}
return start;
}

node *insert_pos(int data,int pos)
{
    node *temp,*curr,*prev;
    char ch;
    int i=1;
    temp=(node *)malloc(sizeof(node));
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
    else if(pos<=0)
    {
        printf("ERROR CHECK THE POSITION VALUE\n");
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
        while(i<pos && curr->link!=start)
        {
            prev=curr;
            curr=curr->link;
            i++;
        }
        if (i==pos)
        {
            if(curr==last)
            {
                append(data);
                
            }
        temp->link=curr;
        prev->link=temp;
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

node *insert_before_val(int data,int sval)
{
    node *curr,*prev,*temp;
    char ch;
    temp=(node *)malloc(sizeof(node));
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
        prev=start;
        while(curr->data!=sval && curr->link!=start)
        {
            prev=curr;
            curr=curr->link;
        } 
        if(curr->data==sval)
        {
            temp->link=curr;
            prev->link=temp;
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

node *insert_after_val(int data,int sval)
{
    node *temp,*curr;
    char ch;
    temp=(node *)malloc(sizeof(node));
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
        while(curr->data!=sval && curr->link!=start)
        {
            curr=curr->link;
        }
        if(curr->data==sval)
        {
            if(curr->link==start)
            last=temp;
            temp->link=curr->link;
            curr->link=temp;
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

void del_begin()
{
node *temp;
if(start==NULL)
{
    printf("CAN YOU DELETE A NODE WHICH IS NOT CREATED?\nI GUESS NOT!\n");
    return;
}
else if(start->link==NULL)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
    last=NULL;
 }
 else
 {
temp=start;
printf("DELETED VALUE=%d\n",temp->data);
start=start->link;
last->link=start;
free(temp);
}
}

void del_last()
{
    node *temp,*prev;
    if(start==NULL)
 {
    printf("CAN YOU DELETE A NODE WHICH IS NOT CREATED?\nI GUESS NOT!\n");
    return;
 }
 else if(start->link==NULL)
 {
    printf("DELETED VALUE=%d\n",start->data);
    free(start);
    start=NULL;
 }
 else 
 {
    temp=start;
    while(temp->link->link!=start)
    {
        prev=temp;
        temp=temp->link;
    }
    printf("DELETED VALUE=%d\n",temp->data);
    prev->link=start;
    last=prev;
    free(temp);

}
}

    void delete_pos(int pos)
{
    node *temp,*del;
    int c;
    char choice;
    c=1;
    if(start==NULL)
  {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
    return ;
  }
    else if(pos<=0)
    {
        printf("ERROR CHECK THE POSITION VALUE\n");
        return ;
    }
    else if(pos==1)
    {
        del_begin();
        return ;
    }
    else
    {
        temp=start;
        del=start;
        while(c<pos && del->link!=start)
        {
            temp=del;
            del=del->link;
            c++;
        }
        if(c==pos)
        { 
        	printf("DELETED VALUE=%d\n",del->data);
            temp->link=del->link;
            free(del);
        }
        else
        {
            printf("WRONG CHOICE\n");
            printf("DO YOU WANT TO DELETE THE LAST NODE?   Y/N\n");
            getchar();
            scanf("%c",&choice);
            if(choice=='Y' || choice=='y')
            del_last();
            else
            return;
        }
    }
}

void del_value(int sval) {
    node *curr = start, *prev = NULL;
    char ch;

    if (start == NULL) {  // Edge Case 1: Empty list
        printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED\n");
        return;
    }

    if (start->link == start && start->data == sval) {  
        del_begin();
        return;
    }

    if (start->data == sval) {  
        del_begin();
        return;
    }

    while (curr->data != sval && curr->link != start) {  
        prev = curr;
        curr = curr->link;
    }

    if (curr->data == sval) {
        if (curr == last) { 
            del_last();
            return;
        }

        printf("DELETED VALUE = %d\n", curr->data);
        prev->link = curr->link;  
        free(curr);
    } else { 
        printf("VALUE NOT FOUND IN THE LIST\n");
        printf("DO YOU WANT TO DELETE THE LAST NODE? (Y/N)\n");
        getchar();
        scanf("%c", &ch);
        if (ch == 'y' || ch == 'Y') {
            del_last();
        }
    }
}

void reverse() 
{
    if (start == NULL || start->link == start) {  
        printf("START IS NULL OR EMPTY NO NEED TO REVERSE\n");
        return;
    }

    node *prev = NULL, *curr = start, *next = NULL;
    last = start; 

    do
     {
        next = curr->link; 
        curr->link = prev;  
        prev = curr;       
        curr = next;       
    } while (curr != start);  

    start->link = prev; 
    start = prev;       
}

void freemem()
{
     node *prev;
     if(start!=NULL)
     {
    while(start->link!=start)
    {
        prev=start;
        start=start->link;
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
    printf("PRESS '9' TO DELETE AT ANY POSITION\n" );
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
            insert_before_val(val,sval);
            break;
        case 6:
            printf("ENTER THE VALUE TO STORE      ");
            scanf("%d",&val);
            printf("ENTER THE SEARCHING VALUE     ");
            scanf("%d",&sval);
            insert_after_val(val,sval);
            break;
        case 7:
            del_begin();
            break;
        case 8:
            del_last();
            break;
        case 9:
            printf("ENTER THE POSITION    ");
            scanf("%d",&pos);
            delete_pos(pos);
            break;
        case 10:
            printf("ENTER THE SEARCHING VALUE     ");
            scanf("%d",&sval);
            del_value(sval);
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
return 0;
}
