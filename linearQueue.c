#include <stdio.h>
#include <stdlib.h>
#define max 5


int f = -1;
int r = -1;
int queue[max];
void push(int ele){
    if(r==max-1){
        printf("Overflow\n");
    }
    else{
        queue[++r]=ele;
        if(f==-1){
            f=0;
        }
    }
}
int pop(){
    if(f==-1 || f>r){
        printf("Underflow\n");
    }
    else{
        printf("The popped element is: %d\n",queue[f++]);
    }
}

void display(){
    for(int i=f;i<r+1;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
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
                push(d);
                break;
            case '2':
                pop();
                break;
            case '3':
                display();
                break;
        }
    }
    printf("Thank you");
    return 0;
}
