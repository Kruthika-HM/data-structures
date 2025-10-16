#include <stdio.h>
#include <stdlib.h>
#define SIZE 5


struct queue{
    int r,f;
    int data[SIZE];

};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item){
    if(q->r==SIZE-1)
        printf("\n queue is full\n");
    else{
        q->r=q->r+1;
        q->data[q->r]=item;
        if(q->f==-1)
            q->f=0;
    }
}
void dequeue(QUEUE *q){
    if(q->f==-1)
        printf("\n queue is empty \n");
    else{
        printf("\n element deleted is %d",q->data[q->f]);
        if(q->f==q->r){
            q->f=-1;
            q->r=-1;
        }
        else
            q->f=q->f+1;
        }
}

void display(QUEUE q){
    int i;
    if(q.f==-1)
        printf("\n queue is empty");
    else{
        printf("\n queue element are:\n");
        for(i=q.f;i<=q.r;i++)
            printf("%d\t",q.data[i]);
        }
}
int main(){
    int item,ch;
    QUEUE q;
    q.f=-1;
    q.r=-1;
    for(;;){
        printf("\n 1.insert\n");
        printf("\n 2.delete\n");
        printf("\n 3.display\n");
        printf("\n 4.exit\n");
        printf("\n read choice :\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("\n read element to be inserted:");
                   scanf("%d",&item);
                   enqueue(&q,item);
                   break;
            case 2:dequeue(&q);
                   break;
            case 3:display(q);
                   break;
            default: exit(0);
        }
    }return 0;

}



























