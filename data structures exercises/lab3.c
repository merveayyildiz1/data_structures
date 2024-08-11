#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    char songName[50];
    int num;
    struct node* prev;
    struct node* next;
};

struct node* create_linkedList(const char* name, int i);
void addToEnd(struct node** head, const char* name, int i);
void display(struct node* ptr, char harf, int j);
void free_node(struct node* start);

struct node* create_linkedList(const char* name, int i) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    strcpy(new_node->songName, name);
    new_node->prev = NULL;
    new_node->num = i;
    new_node->next = NULL;
    return new_node;
}

void addToEnd(struct node** head, const char* name, int i) {
    struct node* new_node = create_linkedList(name, i);
    if (*head == NULL) {
        *head= new_node;
    } else {
        struct node* ptr = *head;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_node;
        new_node->prev = ptr;
    }
}

void display(struct node* ptr, char harf, int j) {
    if (ptr == NULL) {
        return;
    }

    if (harf == 'F') {
        while (ptr != NULL) {
            printf("%s\n", ptr->songName);
            for (int i = 0; i < j; i++) {
                if (ptr->next != NULL) {
                    ptr = ptr->next;
                } else {
                    return;
                }
            }
        }
    } else if (harf == 'L') {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        while (ptr != NULL) {
            printf("%s\n", ptr->songName);
            for (int i = 0; i < j; i++) {
                if (ptr->prev != NULL) {
                    ptr = ptr->prev;
                } else {
                    return;
                }
            }
        }
    }
}

void free_node(struct node* head) {
    while (head != NULL) {
        struct node* ptr = head;
        head = head->next;
        free(ptr);
    }
}

int main() {
    struct node* head = NULL;
    char songName[50];
    char harf;
    int j = 1;

    while (scanf(" %[^\n]", songName) && strcmp(songName, "-1") != 0) {
        addToEnd(&head, songName, j);
        j++;
    }

    scanf(" %c %d", &harf, &j);
    display(head, harf, j);
    free_node(head);

    return 0;
}
