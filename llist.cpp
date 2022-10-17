#include<bits/stdc++.h>

using namespace std;
//Creating a struct for node
struct node{
    int data;
    struct node* ptr;
};

//Initialising a function with which we can access data from the linked list.
//It takes the address of the start, position, and del which decides whether the user wants to delete the node after accessing it data.
int access_node(struct node** add_start, int pos, int del=0);
//Function for creating a node
struct node* create_node()
{
    return (struct node*)malloc(sizeof(struct node));
}
//Function to make the space used by node free
void free_node(struct node* p)
{
    free(p);
}
//Function to add node wherever the user wants by giving the position.
//If user wants to add in the front, the user can give pos=0 or if the user wants to add in the last the user can give pos=-1
void add_node(struct node** add_start, int pos, int n)
{
    struct node* start = *add_start; 

    if(pos==-1)
    {
        struct node* p = start;
           
            while(p->ptr)
            {
                p = p->ptr;
            }
            p->ptr = create_node();
            p->ptr->data = n;
            p->ptr->ptr = NULL;
    
    }

    else if(pos==0)
    {
        struct node* p = start;
        start = create_node();
        start->ptr = p;
        start->data = n;
    }

    else{
        int c = 0;
        struct node* p = start;
        while(p->ptr!=NULL && c<pos-1)
        {
            p = p->ptr;
            c++;
        }
        if(c!=pos-1)
        {
            cout<<"Linked List out of bounds";
        }
        else{
            struct node* temp = p->ptr;
            p->ptr = create_node();
            p->ptr->data = n;
            p->ptr->ptr = temp;
        }
    }
}
//Function to delte the node at whichever position the user wants.
//If the user enter a position which is out of bound an error message will be shown.
void delete_node(struct node** add_start, int pos)
{
    struct node* start = *add_start;
    if(pos == -1)
    {
        struct node* p = start;
        while(p->ptr->ptr)
        {
            free(p->ptr);
            p->ptr = NULL;
        }
    }

    else if(pos==0)
    {
        struct node* temp = start->ptr;
        free_node(start);
        start = temp; 
    }
    else
    {
        int c = 0;
        struct node* p = start;
         while(p->ptr!=NULL && c<pos-1)
         {
            p=p->ptr;
            c++;
         }

         if(c!=pos-1)
        {
            cout<<"Linked List out of bounds";
        }

        else{
            struct node* temp = p->ptr->ptr;
            free(p->ptr);
            p->ptr = temp;
        }

    }
}
//Function to retrieve data from the linked list.
int access_node(struct node** add_start, int pos, int del)
{
    struct node* start = *add_start;
    if(pos == -1)
    {
        struct node* p = start;
        while(p->ptr)
        {
            p=p->ptr;
        }
        return p->data;
        if(del!=0)
        {
            delete_node(add_start, pos);
        }
    }
    else
    {
        int c = 0;
        struct node* p = start;
         while(p->ptr!=NULL && c<pos)
         {
            p=p->ptr;
            c++;
         }

         if(c!=pos)
        {
            cout<<c<<"Linked List out of bounds";
            return -1;
        }

        else{
            return p->data;
            if(del!=0)
            {
                delete_node(add_start, pos);
            }
        }
    }
}
//Function to print the linked list.
void print_ll(struct node** add_start)
{
    struct node* p = *add_start;
    
    while(p->ptr)
    {
        
        cout<<p->data<<endl;
        p=p->ptr;
    }
    
}
//Function to get the address of a node.This may be useful when we need to perform operations which require addresses.
struct node* get_address(struct node** add_start, int pos)
{
    int c=0;
    struct node* start = *add_start;
    struct node* p  = start;
    while(p->ptr!=NULL && c<=pos)
    {
        p=p->ptr;
    } 
    if(c!=pos)
    {
        cout<<"Linked List out of bounds"<<endl;
        return NULL;
    }
    else{
        return p;
    }
}
//Function to search the linked list
void search_ll(struct node** add_start, int n)
{
    struct node* p = *add_start;
    int found=0;
    if(p->data ==n)
    {   
        found=1;
        
    }
    while(p->ptr)
    {
        p=p->ptr;
        if(p->data ==n)
        {   
            found=1;            
        }
    }
    if(found==1)
    {
        cout<<"Number is present in Linked List"<<endl;
    }
    else
    {
        cout<<"Number is not present in Linked List"<<endl;
    }
}
//Function to sort Linked list
void sort_ll(struct node** add_start)
{
    struct node* start = *add_start;
    struct node* p = start;
    // int min=p->data;
    // struct node* add_min = p;
    // int c = 0;
    int count=-1;
    while(p)
    {
        count++;
        p=p->ptr;
    }
    p=start;
    // while(count--)
    // {
    //     while(p)
    //     {
    //         if(p->data<min)
    //         {
    //             min = p->data;
    //             add_min = p;
    //         }
    //         struct node* pos_min = get_address(add_start, c);
    //         int temp = pos_min->data;
    //         pos_min->data = min;
    //         add_min->data = temp;
    //         c++;
    //     }
    //     p=start;
    // }
    
    for(int i=0;i<count;i++)
    {
        for(int j=0;j<count-1;j++)
        {
            if(p->data > p->ptr->data)
            {
                int temp = p->ptr->data;
                p->ptr->data = p->data;
                p->data = temp;               
            }   
            p=p->ptr;        
        }
        p=start;
    }
}

int main()
{
    clock_t star, end;
    star = clock();
    struct node * start=create_node();
    start->ptr = NULL;
    
    struct node** add_start = &start;
    add_node(add_start, -1, 0);
    
    // add_node(add_start, 1, 10);
    // delete_node(add_start, 1);
    add_node(add_start, 1, 10);
    add_node(add_start, 2, 20);
    // int a = access_node(add_start,2, 0);
    // cout<<a<<endl;
    // delete_node(add_start, 1);
    print_ll(add_start);
    // search_ll(add_start, 20);
    // add_node(add_start, 1, 10);
    // print_ll(add_start);
    // struct node* address1 = get_address(add_start, 1);
    // cout<<address1;
    // print_ll(add_start);
    /* Example:
    Add numbers of your choice, store it and the sort it.
    */
    // sort_ll(add_start);
    // print_ll(add_start);
    /*
    Calculating time taken to add numbers and display them
    */
    end = clock();
    double time_taken = double(end - star) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed 
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    //The time taken for the program to execute ranges from 0.000031 to 0.000049
}