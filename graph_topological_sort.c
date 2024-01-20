# include<stdio.h>
#define max 5
int Q[max] ; int f = -1; int r = -1 ; 
int adj[max][max] ; int vertex ; 

void display(){
    for( int i = 1 ; i <= vertex ; i ++ ){
        printf("\n");
        for ( int j = 1 ; j <= vertex ; j++){
            printf("%3d" , adj[i][j]);
        }
    }
}
void enQue(int value) {
    if (r == max - 1 ) {
        printf("Queue Overflow\n");
    } else if (f == r && r == -1) {
        f = r = 0;
        Q[r++] = value;
    } else {
        Q[r++] = value;
    }
}

int DeQue() {
    int val;
    if (f ==-1 || f > r ) {
        printf("Queue underflow\n");
       // f = r = -1 ;
        return -1;
    }
    else if ( f == r){
        val = Q[f];
        f = r = -1 ;
    } else {
        val = Q[f];
        f++; 
    }
    return val;
}


void creategraph(){
    int node , org , dest ;
    printf("Enter the Number of edges");
    scanf("%d" , &vertex);
    int max_edge = vertex*(vertex -1);
    for( int i  = 1 ; i <=max_edge ; i++){
        printf("Enter the uv of %d( 0 to Quit)" , i);
        scanf("%d %d" , &org , &dest);
        if ( org == 0 && dest == 0 ){
            break ; 
        }else if ( org > vertex || dest > vertex || dest <= 0 || org <= 0){
            printf("Invalid input");
            i-- ; 
        }else{
            adj[org][dest]=1 ; 
        }
    }

}

int in_deg(int node){
   int indeg=0 ; 
    for ( int i = 1 ; i <= vertex ; i++){
        if (adj[i][node]==1){
            indeg ++ ;
        }
    }
    return indeg ; 
}


void main(){
 int node ; int j=0;
 int topo[max] ; int indegree[max] ;
 creategraph();
 printf("Adjancey matrix") ; 
 display();

 for( node = 1 ; node <= vertex ; node ++){
    indegree[node]=in_deg(node);
    if ( indegree[node] == 0){
        enQue(node);
    }
 }
while( f > r){
    int del_node = DeQue();
    topo[j]=del_node ;
    j++ ; 
    for ( node = 1  ; node <=vertex ; node++){
        if ( adj[del_node][node]){
            adj[del_node][node]=0 ; 
            indegree[node]=indegree[node] -1 ;
            if( indegree[node] == 0){
                enQue(node);
            }
        }
    }
}
for ( int k = 0 ; k < j ; k++){
    printf("%d\t" , topo[k]);
}
}