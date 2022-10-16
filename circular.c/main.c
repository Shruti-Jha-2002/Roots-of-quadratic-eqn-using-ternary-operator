#include <stdio.h>
#include <stdlib.h>
#define max 5
int f=-1;
int r=-1;
int Cqueue[max];
void enqueue(int ele){
    if(f==-1 && r==-1){
        f=r=0;
        Cqueue[r]=ele;
    }
    else if((r+1)%max==f){
        printf("Overflow. The queue is Full\n");
    }
    else{
        r=(r+1)%max;
        Cqueue[r]=ele;
    }
}

int dequeue(){
    if(r==-1 && f==-1){
        printf("Underflow. The queue is Empty.\n");
    }
    else if(f==r){
        printf("The dequeued element is %d\n",Cqueue[f]);
        f=r=-1;
    }
    else{
        printf("The dequeued element is %d\n",Cqueue[f]);
        f=(f+1)%max;
    }
}
void display(){
    if(f==-1 && r==-1){
        printf("The Queue is Empty.\n");
    }
    else{
        int i=f;
        while(i!=r){
            printf("%d ",Cqueue[i]);
            i=(i+1)%max;
        }
        printf("%d",Cqueue[r]);
        printf("\n");
    }
}
int main()
{
    char c='Y';
    int d;
    while(c!='q'){
        printf("1: Insert\n");
        printf("2: Delete\n");
        printf("3: Display\n");
        printf("Press 'q' to quit %c\n",c);
        scanf(" %c",&c);
        switch(c){
            case '1':
                printf("Enter the element to be inserted: ");
                scanf("%d",&d);
                enqueue(d);
                break;
            case '2':
                dequeue();
                break;
            case '3':
                display();
                break;
        }
    }
    printf("Thank you");
    return 0;
}
