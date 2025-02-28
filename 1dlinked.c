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
node *insert_pos(int data,int pos)
{
    node *temp,*curr;
    char ch;
    int c=1;
    curr=(node *)malloc(sizeof(node));
    curr->data=data;
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
    {temp=start;
        while(c<pos && temp->link!=NULL)
        { 
            temp=temp->link;
            c++;
        }
        if(c==pos)
        {
            curr->link=temp->link;
            temp->link=curr;
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
        while(curr->data!=sval && curr->link!=NULL)
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
        while(curr->data!=sval && curr->link!=NULL)
        {
            curr=curr->link;
        }
        if(curr->data==sval)
        {	temp->link=curr->link;
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
void delete_begin()
{
 node *temp;
 if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED");
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
    start=start->link;
    printf("DELETED VALUE=%d\n",temp->data);
    free(temp);
 }
}
void delete_end()
{
    node *temp;
    if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED");
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
  while (temp->link->link!=NULL)
  {
    temp=temp->link;
  }
  printf("DELETED VALUE=%d\n",temp->link->data);
  free(temp->link);
  temp->link=NULL;
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
        delete_begin();
        return ;
    }
    else if(start->link==NULL)
    {
        delete_begin();
        return;

    }
    else
    {
        temp=start;
        del=start;
        while(c<pos && del->link!=NULL)
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
            delete_end();
            else
            return;
        }
    }
    
}
void delete_before(int sval)
{
    node *temp,*del;
    char choice;
    if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED");
    return;
 }
  else if(start->data==sval)
    {
        printf("NO PREVIOUS NODE EXISTS\n");
        return;

    }
    else
    {
        temp=NULL;
        del=start;
        while(del->link!=NULL && del->link->data!=sval)
        {
            temp=del;
            del=del->link;
        }
        if (del->link==NULL)
        {
    
        
        printf("WRONG CHOICE\n");
        printf("DO YOU WANT TO DELETE THE LAST NODE?   Y/N\n");
        getchar();  
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
            delete_end();
            return;
    }

   
    if (temp == NULL) {
        start = del->link;  
    } else {
        temp->link = del->link;  
    }

    printf("DELETED VALUE = %d\n", del->data);
    free(del);  
}
         
    }

void delete_after(int sval)
{
    node *temp,*del;
    char choice;
    if(start==NULL)
 {
    printf("WRONG CHOICE \nYOU CANNOT DELETE A NODE WHICH IS NOT CREATED");
    return;
 }
  else if(start->link==NULL)
    {
       printf("NO DELETATION POSSIBLE AS THERE ARE NO VALUE AFTER THE GIVEN NUMBER\n");
        return;

    }
    else
    {
        temp=NULL;
        del=start;
        while (del->link!=NULL && del->data!=sval)
        {
            del=del->link;
        }
        if (del->link==NULL)
        {
    
        
        printf("WRONG CHOICE\n");
        printf("DO YOU WANT TO DELETE THE LAST NODE?   Y/N\n");
        getchar();  
        scanf("%c", &choice);
        if (choice == 'Y' || choice == 'y')
            delete_end();
            return;
        }
        else
        {
            temp=del->link;
            printf("DELETED VALUE=%d\n",temp->data);
            del->link=temp->link;
            free(temp);
        }
    }

        
        
}

node *reverse()
{
node *prev,*curr,*next;
if(start==NULL)
{
    printf("WRONG CHOICE\n");
    return 0;
}
 else if(start->link==NULL)
{
return start;
}
else
{
    prev=NULL;
    curr=start;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev=curr;
        curr=next;
    }
    start=prev;
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

void main()
{
    int choice,data,val,b,s,pos,a,s1val,s2val;
    int pos1,val1,val2;
    do
    {
    printf("PRESS '1' TO DISPLAY\n");
    printf("PRESS '2' TO APPEND\n");
    printf("PRESS '3' TO INSERT BEGIN\n");
    printf("PRESS '4' TO INSERT ANY POSITION\n");
    printf("PRESS '5' TO INSERT BEFORE ANY VALUE\n");
    printf("PRESS '6' TO INSERT AFTER ANY VALUE\n");
    printf("PRESS '7' TO DELETE BEGIN\n");
    printf("PRESS '8' TO DELETE END\n");
    printf("PRESS '9' TO DELETE FROM ANY POSITION\n");
    printf("PRESS '10' TO DELETE BEFORE VALUE\n");
    printf("PRESS '11' TO DELETE AFTER VALUE\n");
    printf("PRESS '12' TO REVERSE THE LIST\n");
    printf("PRESS '13' TO EXIT\n");
    printf("ENTER CHOICE\n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        display();
        break;
    case 2:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&a);
        append(a);
        break;
    case 3:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&b);
        insert_begin(b);
        break;
    case 4:
        printf("ENTER THWE VALUE TO STORE    ");
        scanf("%d",&s);
        printf("ENTER THE POSITION   ");
        scanf("%d",&pos);
        insert_pos(s,pos);
        break;
    case 5:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&data);
        printf("ENTER THE SEARCHING VALUE     ");
        scanf("%d",&s1val);
        insert_before_val(data,s1val);
        break;
    case 6:
        printf("ENTER THE VALUE TO STORE    ");
        scanf("%d",&val);
        printf("ENTER THE SEARCHING VALUE     ");
        scanf("%d",&s2val);
        insert_after_val(val,s2val);
        break;
    case 7:
        delete_begin();
        break;
    case 8:
       delete_end();
        break;
    case 9:
        printf("ENTER THE POSITION      ");
        scanf("%d",&pos1);
        delete_pos(pos1);
        break;
    case 10:
        printf("ENTER THE SEARCHING VALUE       ");
        scanf("%d",&val1);
        delete_before(val1);
        break;
    case 11:
        printf("ENTER THE SEARCHING VALUE       ");
        scanf("%d",&val2);
        delete_after(val2);
        break;
    case 12:
        reverse();
        break;
    case 13:
        printf("BYE");
        break;
    default:
        printf("INVALID CHOICE");
        break;
    }
    } while (choice!=13);
    
    
    fmem();
}
