# include<stdio.h>
# include<stdlib.h>

struct node {
    struct node* prev ;
    int data; 
    struct node* Next; 
};

struct node * CreatLL( struct node * start)
{
    int val; 
    printf("\t Note: Enter -1 to Exit\n");
    printf("Enter Element: ");
    scanf("%d", &val);
    while( val != -1){
        struct node * Newnode = (struct node *) malloc(sizeof(struct node));
        Newnode->data= val ;
        Newnode->Next = NULL ; 
        Newnode->prev = NULL ;
        if ( start == NULL){
            start = Newnode ; 
        }
        else { 
            struct node * ptr = start ; 
            while ( ptr->Next != NULL){
                ptr= ptr->Next;
            }
            ptr->Next = Newnode ; 
            Newnode->prev = ptr ; 
        }
    printf("Enter Element: ");
    scanf("%d", &val);
    }

    return start  ; 
}

struct node * Delete_node (struct node * start , int val){
    int flag ; 
    if ( start == NULL){
        printf("linked list Empty");
    }else { 
        struct node * ptr = start;
        while(ptr->data != val){
         ptr = ptr->Next ;
        }
        ptr->prev->Next=ptr->Next ; // imp to be remeber 
        ptr->Next->prev=ptr->prev ; // imp to be remeber 
        free(ptr);
    }
    return start ;
}
void print_lin(struct node* start) {
    if (start == NULL) {
        printf("\t NULL list\n");
    } else {
        struct node* ptr = start;
        while (ptr != NULL) {
            printf(" %d<->", ptr->data);
            ptr = ptr->Next; 
        }
        printf(" NULL\n");
    }
}
int main(){//
struct node* start = NULL ;
start = CreatLL(start);
print_lin(start);
int val ;
printf("\n Enter Element to delete : ");
scanf("%d", &val);
start= Delete_node( start ,val );
print_lin(start);
    return 0 ;
}