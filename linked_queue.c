#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int info;
    struct queue *link;

}*front=NULL,*rear=NULL,*new,*temp;

void enque();
void deque();
void display();
struct queue *allocate_node();

int ch;

void main()
{
    printf("\tImplementation of queue using linked list\n");
    
    do{
        printf("\n   Queue Operations: \n\n");
        printf("\t1.Enque\n");
        printf("\t2.Deque\n");
        printf("\t3.Display\n");
        printf("\t4.Exit\n");
        
        printf("\n Enter the choice: ");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1: enque();
                    break;

            case 2: deque();
                    break;

            case 3: display();
                    break;
            
            case 4: printf("\n   --> Exited from program\n");
                    break;
                        
            default: printf("\n   --> Invalid choice, Enter a valid choice\n");
        }
        
    }while(ch!=4);
}

struct queue *allocate_node()
{
    new = (struct queue *)malloc(sizeof(struct queue));
    
    if(new == NULL)
    {
        printf("\n   --> Memory allocation for a new node failed!!\n");
        exit(1);
    }
    
    else    
        return new;
}

void enque()
{
    int item;
    
    printf("\n Enter the element to be inserted: ");
    scanf("%d",&item);
    
    new=allocate_node();
    new->info=item;
    new->link=NULL;
    
    if(front==NULL)
        front=rear=new; 
    
    else
    {
        rear->link=new;
        rear=new;
    }
    
    printf("\n   --> Element %d is inserted to queue\n",item);
}

void deque()
{
    int item;
    
    temp=front;
    
    if(front==NULL)
        printf("\n   --> Queue Underflow, Cannot delete element\n");
    
    else    
    {
        item=front->info;
        front=temp->link;
        printf("\n   --> Element %d is deleted from queue\n",item);
        free(temp);
    }
}

void display()
{
    temp=front;

    if(temp==NULL)
        printf("\n   --> Queue is empty\n");
    
    else
    {
        printf("\n   Elements in the queue: \n\n");
        
        while(temp!=NULL)
        {
            printf("\t   %d\n",temp->info);
            temp=temp->link;
        }
    }
}
