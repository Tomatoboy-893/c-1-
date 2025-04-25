#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};


void push(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("メモリの割り当てに失敗しました\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}


void pop(struct Node** head) {
    if (*head == NULL) {
        printf("NULL\n");
        return;
    }

    struct Node* temp = *head;
    *head = (*head)->next;
    int data = temp->data;
    free(temp);
    printf("%d\n", data);
}


void print(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void search(struct Node* head, int k) {
    struct Node* current = head;
    int position = 0;
    while (current != NULL) {
        if (current->data == k) {
            printf("Found at position %d\n", position);
            return;
        }
        current = current->next;
        position++;
    }
    printf("Not found\n");
}


void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    char command[10];
    int k;

    while (1) {
        printf("コマンドを入力してください (push, pop, print, search, quit): ");
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            scanf("%d", &k);
            push(&head, k);
        } else if (strcmp(command, "pop") == 0) {
            pop(&head);
        } else if (strcmp(command, "print") == 0) {
            print(head);
        } else if (strcmp(command, "search") == 0) {
            scanf("%d", &k);
            search(head, k);
        } else if (strcmp(command, "quit") == 0) {
            freeList(head);
            break;
        } else {
            printf("無効なコマンドです\n");
        }
    }

    return 0;
}
