#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 32

struct Node {
    char data[MAX_STRING_LENGTH];
    struct Node* next;
};


void push(struct Node** head, const char* newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("メモリの割り当てに失敗しました\n");
        exit(1);
    }
    strncpy(newNode->data, newData, MAX_STRING_LENGTH - 1);
    newNode->data[MAX_STRING_LENGTH - 1] = '\0'; 
    newNode->next = *head;
    *head = newNode;
}


void displayAndFree(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%s -> ", current->data);
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    char input[MAX_STRING_LENGTH];

    while (1) {
        printf("文字列を入力してください (Ctrl+zまたはCtrl+dで終了): ");
        if (scanf("%s", input) == EOF) {
            break;
        }

        push(&head, input);
    }

    
    if (head != NULL) {
        printf("リストの内容:\n");
        displayAndFree(head);
    } else {
        printf("リストは空です。\n");
    }

    return 0;
}
