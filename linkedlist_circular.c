
# include<stdio.h>
# include<stdlib.h>

struct node {
    int data; 
    struct node* Next; 
};
struct node* Createll(struct node* start)
{
    int val; 
    printf("\t Note: Enter -1 to Exit\n");
    printf("Enter Element: ");
    scanf("%d", &val);

    while (val != -1) {
        struct node* Newnode = (struct node*)malloc(sizeof(struct node));
        Newnode->data = val; 
        Newnode->Next = NULL; 

        if (start == NULL) {
            start = Newnode; 
            start->Next = start ;
        } else { 
            struct node* ptr = start; 
            while (ptr->Next != start) {
                ptr = ptr->Next;
            }
            ptr->Next = Newnode; 
            Newnode->Next=start ;  
        }

        printf("Enter Element: ");
        scanf("%d", &val);
    }

    return start; 
}

void print_lin(struct node* start) {
    if (start == NULL) {
        printf("\t NULL list\n");
    } else {
        struct node* ptr = start;
        printf("End->");
        do  {
            printf(" %d->", ptr->data);
            ptr = ptr->Next; 
        } while (ptr != start) ;
    }
}

struct node* delete_beg( struct node * start){
    if ( start  == NULL){
        printf("LL is Empty");
    } else { 
        struct node *  ptr = start ; 
        struct node * ptr2 ;
        while( ptr->Next!= start){
            ptr= ptr ->Next ; 
            
        }
        ptr2 = start ;
        start  = start->Next ; 
        ptr->Next=start ;
        free(ptr2);
    }
    return start ; 
}
struct node * delete_end (struct node * start){
    if ( start  == NULL){
        printf("LL is Empty");
    } else { 
        struct node *  ptr = start ; 
        struct node *  ptr1 = NULL ; 
        while ( ptr->Next != start ){
            ptr1 = ptr ; // should be upper only ; 
            ptr= ptr->Next ; 
        }
            ptr1->Next =start ; ;
            free( ptr );
    }
    return start ; 
}
struct node * insert_start (struct node * start , int val){
        struct node* Newnode = (struct node*)malloc(sizeof(struct node));
        Newnode->data = val; 
        Newnode->Next = NULL; 

        if (start == NULL) {
            start = Newnode; 
            start->Next = start ;
        } else { 
            struct node* ptr = start; 
            while (ptr->Next != start) {
                ptr = ptr->Next;
            }
            ptr->Next = Newnode; 
            Newnode->Next=start; 
            start=Newnode ; 
        }
    return start ; 
}


int main() {
    struct node* start = NULL;
     start = Createll(start); // inmp to remember ; 
    print_lin(start);
    start = delete_beg(start);
    print_lin(start);
    // start = delete_end(start);
    // print_lin(start) ;
    start = insert_start(start , 57);
    print_lin(start) ;

    return 0;
}
