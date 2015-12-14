#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char label[50];
    int priority;
    struct node *next;
}Node;

Node * head = NULL;
Node * post, * prior, * current;

void load_file();
void printDetails(Node *);
int insertsomething();
void insert(Node *);
void deletesomething();
void printitout();
void servesomething();
void save();
char file_name[50];

FILE * fin, * fout;

void load_file(){

    printf("What is the file name?\n");
    scanf("%s", file_name);

        if((fin = fopen(file_name, "r")) == NULL){ //replace california.txt with file_name********
            printf("File could not be opened \n");
            }
        else{
            head = NULL;
            head = malloc(sizeof(Node));
            fscanf(fin, "%s %d\n", head->label, &head->priority);
            printf("%s %d\n", head->label, head->priority);
            current = head;

            while(fscanf(fin, "%d", current->priority) != EOF){
                current->next = malloc(sizeof(Node));
                current = current->next;
                fscanf(fin, "%s %d\n", current->label, &current->priority);
                current->next = NULL;
                printDetails(current);
            }
        }
        fclose(fin);
}

void printDetails(Node * pf){
    while(pf != NULL){
        printf("%s %d\n", pf->label, pf->priority);
        pf = pf->next;
    }
}
int insertsomething()
 {
   char string[20];
   int value;

   Node * ptr;

   printf("Enter item name and its priority.\n");
   scanf("%s %d", string, &value);
    if (value <= 0){
        printf("Priority Not Valid\n\n");
        return 0;
    }
   printf("OK, got it, thanks.\n\n");
   ptr = malloc(sizeof (Node));


    // check for the NULL pointer
   // leave to you
   strcpy(ptr->label,string);
   ptr->priority=value;
   ptr->next=NULL;
   insert(ptr);

 }

void insert(Node * newnode){
    prior = head;
    post = prior->next;

    if (head==NULL)   // list is empty
        head=newnode;
    else if (newnode->priority >= head->priority){ // put as new head
            newnode->next = head;
            head=newnode;
    }
    else{
        while (post->next != NULL){
            if (newnode->priority > post->priority){
                newnode->next = post;
                prior->next = newnode;
                return;
            }
            prior = post;
            post = post->next;
        }

        if (post->next == NULL){
            if (newnode->priority > post->priority){ // last node's next pointer is pointing to NULL so we're good
                newnode->next = post;
                prior->next = newnode;
            }
            else if (newnode->priority <= post->priority){ // then post->next goes from NULL to post->next = newnode and
                //newnode becomes last node so you have to newnode->next = NULL to end the list
                post->next = newnode;
                newnode->next = NULL;

            }

        }
    }
}

void printitout()
{
    int n=1;
    Node * ptr=head;
    if (ptr==NULL)
        printf("List is empty\n");
    else
        {
         while (ptr != NULL)
            {
               // system("pause");
                printf("The values for node no. %d are:\n", n);
                printf("The name of the task is: %s \n", ptr->label);
                printf("The priority is: %d\n", ptr->priority);
                printf("\n\n");
                ptr=ptr->next;
                n++;
            }
        }
}

void deletesomething(){
    char user_input[50];
    Node *temp;
    printf("What would you like to delete? (Case Sensitive!)\n");
    scanf("%s", user_input);
    //case: empty list
    if(head == NULL){
        printf("Empty list\n");
        return;
    //case: delete from front
    }else if (strcmp(head->label, user_input) == 0){
        head = head->next;
        free(temp);
        printf("\n%s was deleted\n", user_input);
    //case: delete from middle and the end
    }else{
        current=head;
        while(current != NULL){
            if(strcmp(user_input, current->label) == 0){
                prior->next=current->next; //prior links with the one after post, now post is lost
                free(current);
                printf("\n%s was deleted\n", user_input);
                break;
            }else{ //condition wasn't met above, so let's move prior and post along and check again
                prior=current;
                current=prior->next;
            }
        }
        if (current == NULL) // we got to the end of the list and didn't find anything
            printf("\nitem not found\n");
    }
}


void servesomething(){

 char key[25];
 Node * ptr = head;
 printf("\nEnter the item to search for: (Case Sensitive!)\n");
 scanf("%s", key);

if(strcmp(ptr->label, key) == 0){
 printf("\n%s has a priority value of %d \n", ptr->label, ptr->priority);
 return;
}

do{
 ptr = ptr->next;
}while (strcmp (ptr->label,key) != 0);
printf("\n%s has a priority value of %d \n", ptr->label, ptr->priority);
}

void save(){
    Node * ptr = head;
    fout = fopen("California.txt", "w");
    while(ptr != NULL){
        fprintf(fout, "%s %d\n", ptr->label, ptr->priority);
        ptr = ptr->next;
    }
    fclose(fout);
    printf("Saved!\n");
}


