#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


void displayList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    
    struct Node* head = NULL;

    
    for (int i = 1; i <= 10; i++) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL) {
            printf("メモリの割り当てに失敗しました\n");
            exit(1);
        }
        newNode->data = i;
        newNode->next = head;
        head = newNode;
    }

    
    printf("リストの内容:\n");
    displayList(head);

    
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
