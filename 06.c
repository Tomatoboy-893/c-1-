#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define K 32

typedef struct Node {
    char name[K];
    struct Node* next;
} Node;

//push関数
Node* push(Node* head, char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }

    strncpy(newNode->name, name, K-1);
    newNode->name[K - 1] = '\0';
    newNode->next = head;

    return newNode;
}

//pop関数
Node* pop(Node* head) {
    if (head == NULL) {
        printf("NULL\n");
        return NULL;
    }

    Node* temp = head;
    printf("%s\n", temp->name);
    head = head->next;
    free(temp);

    return head;
}

//del関数
Node* del(Node* head, int k) {
    if (k <= 0) {
        printf("もう一度お願いします\n");
        return head;
    }

    if (k == 1) {
        Node* temp = head;
        if (temp != NULL) {
            printf("Deleted: %s\n", temp->name);
            head = head->next;
            free(temp);
        } else {
            printf("%d番目はありません\n", k);
        }
    } else {
        Node* temp = head;
        int position = 1;

        while (temp != NULL && position < k - 1) {
            temp = temp->next;
            position++;
        }

        if (temp != NULL && temp->next != NULL) {
            Node* deletedNode = temp->next;
            printf("Deleted: %s\n", deletedNode->name);
            temp->next = deletedNode->next;
            free(deletedNode);
        } else {
            printf("Position %d not found\n", k);
        }
    }

    return head;
}

//ins関数
Node* ins(Node* head, int k, const char* name) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        exit(1);
    }

    strncpy(newNode->name, name, K - 1);
    newNode->name[K - 1] = '\0'; 

    if (k <= 0) {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    if (k == 1 || head == NULL) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        int position = 1;

        while (temp != NULL && position < k) {
            temp = temp->next;
            position++;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
}

//print関数
void print(Node* head) {
    while (head != NULL) {
        printf("%s", head->name);
        head = head->next;
    }
    printf("\n");
}

//search関数
void search(Node* head, char* name) {
    int position = 0;
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            printf("検索した整数は%d番目にある\n", position);
            return;
        }
        head = head->next;
        position++;
    }

    printf("見つかりませんでした\n");
}

//終わり
void quit(Node* head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
}

int main(void) {
    Node* head = NULL;
    char command[10];
    char name[K];
    int position;
    
    while (1) {
        printf("コマンドを入力してください (push, pop, print, search, quit): ");
        scanf("%s", command);

        if (strcmp(command, "push") == 0) {
            printf("string: ");
            scanf("%31s", name);
            head = push(head, name);
        } else if (strcmp(command, "pop") == 0) {
            head = pop(head);
        } else if (strcmp(command, "del") == 0) {
            printf("Enter position to delete: ");
            scanf("%d", &position);
            head = del(head, position);
        } else if (strcmp(command, "ins") == 0) {
            printf("Enter position to insert: ");
            scanf("%d", &position);
            printf("Enter name to insert: ");
            scanf("%s", name);
            head = ins(head, position, name);
        } else if (strcmp(command, "print") == 0) {
            print(head);
        } else if (strcmp(command, "search") == 0) {
            printf("search string: ");
            scanf("%31s", name);
            search(head, name);
        } else if (strcmp(command, "quit") == 0) {
            quit(head);
            break;
        } else {
            printf("もう一度お願いします\n");
        }
    }

    return 0;
}