/* Mason McDaniel UTAID: 1001456342 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char s[50];
    struct node *next;
};

struct node* enq(char s[]);
void printQueue(struct node* head);
void freeMem(struct node* head) ;
struct node* deq(struct node* head) ;


int main(void) {
    struct node *head = NULL, *tail, *temp;
    char buffer[50] = "go";

    while( strcmp(buffer, "stop\n") != 0 ) {
        printf("action (enq/deq/stop/print)? ");
        fgets(buffer, sizeof(buffer), stdin);

        if( strcmp(buffer, "enq\n") == 0 ) {
            printf("string to store? ");
            fgets(buffer, sizeof(buffer), stdin);

            temp = enq(buffer);
            if(head == NULL)
                head = temp;
            else
                tail->next = temp;

            tail = temp;
        } else if ( strcmp(buffer, "deq\n" ) == 0 ) {
            if(head == NULL)
                printf("ERROR: queue doesn't exist\n");
            else
                head = deq(head);
        } else if ( strcmp(buffer, "print\n" ) == 0 ) {
            printQueue(head);
        }
    }

    freeMem(head);
}

struct node* enq(char s[]) {
    struct node *temp = malloc(sizeof(struct node));

    strcpy(temp->s, s);
    temp->next = NULL;

    return temp;
}

void printQueue(struct node* head) {
    while(head != NULL ) {
        printf("%s", head->s);
        head = head->next;
    }
}

void freeMem(struct node* head) {
    struct node *temp = head;

    while(temp != NULL ) {
        printf("%s", temp->s);
        head = temp;
        temp = temp->next;
        free(head);
    }
}

struct node* deq(struct node* head) {
    struct node *temp = head->next;

    free(head);

    return temp;
}
