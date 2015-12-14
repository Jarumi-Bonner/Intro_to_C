#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct entry  {
		char label[20];
		int priority;
		struct entry *next;
};

typedef struct entry Entry;
typedef Entry *Entryptr;
Entryptr * head = NULL;

void insertsomething();
void insert(Entryptr *);
void printitout();
void deletesomething();
void takeout(Entryptr *, Entryptr *);
void servesomething();
Entryptr serve(Entryptr;);

int main()
{

  	int choice;

  	printf("what would you like to do?\n");
  	printf("1 - Insert something in the list\n");
  	printf("2 – Delete something from the list\n");
  	printf("3 - Print out its contents\n");
  	printf("4 - Return the element selected\n");
  	printf("5 - Nothing at all\n");
  	printf("Enter 1 through 5:");
  	scanf("%d", &choice);

  	switch(choice)  {
        case 1:
            insertsomething();
            printitout();
            break;
        case 2:
            deletesomething();
            break;
        case 3:
            printitout();
            break;
        case 4:
            servesomething();
            break;
        default:
            printf("OK, bye\n");
            return 0;
            }

  	return 0;
}

void insertsomething()
 {
   char string[20];
   int value;
   Entryptr * ptr;
   printf("Enter the name of the task to be” “entered - one word without spaces.\n");
   scanf("%s", string);
   printf("Enter the priority of this task as an” “integer greater than zero.\n");
   scanf("%d", &value);
   printf("OK, got it, thanks.\n");
   ptr = malloc(sizeof (Entry));

   // check for the NULL pointer
   // leave to you
   strcpy(ptr->label, string);
   ptr->priority=value;
   ptr->next=NULL;
   insert(ptr);
}

void insert(Entryptr * newnode)
    {
        Entryptr * post = head, * prior = head;
	    if (head==NULL)   // list is empty
            head=newnode;
        else  if (newnode->priority >= post->priority) // put as new head
           {    newnode->next = head;
                head=newnode; }
        else 		// look for it elsewhere
		  {   post=previous->next;
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
            }
    }

void printitout()
{
    int n=1;
    Entryptr ptr=head;
    if (head==NULL)
        printf("List is empty\n");
    else
        {
         while (ptr != NULL)
            {
                printf("The values for node no. %d are:\n", n);
                printf("The name of the task is: %s \n", ptr->			label);
                printf("The priority is: %d\n", ptr->priority);
                printf("\n\n");
                ptr=ptr->next;
                n++;
            }
        }
}

void deletesomething()  {
	Entryptr post=head, prior=head, ptr=NULL;
    char * string;
    printf("What task do you want to delete?\n");
    scanf("%s", string);
        	if (head == NULL)            // list is empty - nothing to delete
        		printf("The list is empty\n");
        	else if (strcmp(head->label,string)==0) {    // it’s the head!
            	ptr=head;   // temporary ptr to free up the memory             		head=head->next;
            	free(ptr);    }
     	else    {        // look down the list for the task to be deleted
            	post=prior->next;
            	while (post != NULL) { //we look for the task           				if((strcmp(post->label,string)==0)) { //found it!
                            	prior->next=post->next;   // snip
                            	free(post);     }      // free up memory
                    	else    {            // keep looking
                            	prior=post;
                            	post=prior->next;
                            	}
                }
}



