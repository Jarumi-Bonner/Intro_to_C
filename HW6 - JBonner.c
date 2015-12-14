#include<stdio.h>
#include<stdlib.h>

//Create a struct
typedef struct node{
    int value;
    struct node *next;
}Node;

//Prototypes for the user defined functions
void printList(Node *a);
void generateList(Node *b);

void main(){
    int i;
    Node * head, * tail = NULL; //Set both pointers to Null

    //Create a for loop that goes through the pointer setting its value as you go, as well setting the next to another pointer that creates the list
    for(i=0; i<=10; i++){
        head = malloc(sizeof(Node)); //Creates the size of the struct for the list
        head->value = i; //Sets the value as it moves in the loop
        head->next = tail; //Sends the next pointer to a different struct
        tail = head; //The new struct takes on the values of the first struct so it can go through the loop
        printList(tail);
    }

}

//Print the values inside the for loop
void printList(Node *a){
    printf("%d\n", a->value);
}
