#include <stdio.h>
#include <stdlib.h>


struct Node {
    double data;
    struct Node* next;
};


void push(struct Node** head, double newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("メモリの割り当てに失敗しました\n");
        exit(1);
    }
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}


void displayAndFree(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%lf -> ", current->data);
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    double input;

    while (1) {
        printf("小数を入力してください (負の数で終了): ");
        scanf("%lf", &input);

        if (input < 0) {
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
