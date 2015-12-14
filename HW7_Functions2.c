#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char label[26];
    int priority;
    struct node *next;
}Node;

Node * head = NULL;
Node * post, * prior, * current;

void load_file();
void insertsomething();
void insert(Node *);
void printitout();
char file_name[50];
FILE * fin, fout;

void load_file()
{

    printf("What is the file name?\n");
    scanf("%s", file_name);

        if((fin = fopen(file_name, "r")) == NULL){
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
void insertsomething()
 {
   char string[20];
   int value;

   Node * ptr;

   printf("Enter the name of the task to be entered - one word without spaces.\n");
   scanf("%s", string);
   printf("Enter the priority of this task as an integer greater than zero.\n");
   scanf("%d", &value);
   printf("OK, got it, thanks.\n");
   ptr = malloc(sizeof (Node));

    // check for the NULL pointer
   // leave to you
   strcpy(ptr->label,string);
   ptr->priority=value;
   ptr->next=NULL;
   insert(ptr);

 }

void insert(Node * newnode)
    {
        post = head;
        prior = head;
        current = head;


	    if (head==NULL){   // list is empty
            head=newnode;
	    }

        if (newnode->priority >= post->priority) // put as new head
           {    newnode->next = head;
                head=newnode;
           }
        else if (newnode->priority <= prior->priority && newnode->priority >= post->priority){
            newnode->next = post;
            current->next = newnode;
        }
        else {
            newnode->next = NULL;
            current->next = newnode;
        }
        printf("TEST");
        /*else 		// look for it elsewhere
		  {   post=prior->next;
                while (post != NULL)   {
			if (newnode->priority >= post->priority)
                            {
                                newnode->next=post;
                                prior->next=newnode;
                            }
                        else    // move on to the next node to check it.
                            {
                                prior=post;
                                post=prior->next;
                             }
                }
            }*/
    }

void printitout()
{
    int n=1;
    Node * ptr=current;
    if (head==NULL)
        printf("List is empty\n");
    else
        {
         while (ptr != NULL)
            {
                printf("The values for node no. %d are:\n", n);
                printf("The name of the task is: %s \n", ptr->label);
                printf("The priority is: %d\n", ptr->priority);
                printf("\n\n");
                ptr=ptr->next;
                n++;
            }
        }
}

/*void deletesomething()  {
	Entryptr post=head, prior=head, ptr=NULL;
    char * string;
    printf("What task do you want to delete?\n");
    scanf("%s", string);
        	if (head == NULL)            // list is empty - nothing to delete
        		printf("The list is empty\n");
        	else if (strcmp(head->label,string)==0) {    // it’s the head!
            	ptr=head;   // temporary ptr to free up the memory
            	head=head->next;
            	free(ptr);    }
     	else    {        // look down the list for the task to be deleted
            	post=prior->next;
            	while (post != NULL) { //we look for the task
                        if((strcmp(post->label,string)==0)) { //found it!
                            	prior->next=post->next;   // snip
                            	free(post);     }      // free up memory
                    	else    {            // keep looking
                            	prior=post;
                            	post=prior->next;
                            	}
            	}
     	}
}

*/
