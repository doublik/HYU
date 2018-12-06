#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *data;
    struct Node *next;
}Node;

typedef struct Stack {
    int amount;
    Node *top;
}Stack;

void initStack(Stack *stack) {
    stack->amount = 0;
    stack->top = NULL;
}

void Stack_push(Stack *stack, char *data) {
    Node *now = (Node *)malloc(sizeof(Node));
    now->data = data;
    now->next = stack->top;
    stack->amount++;
    stack->top = now;
}

char *Stack_pop(Stack *stack) {
    if (stack->amount == 0) return NULL;

    Node *now = stack->top;
    char *data = now->data;
    stack->top = now->next;
    free(now);

    return data;
}

char **split(char *str, char *regex) {
    Stack stack;
    //char **words;// = (char **)malloc(sizeof(char *));
    //*words = str;
    int i=0, check=0;

    initStack(&stack);
    while(i<=strlen(str)-strlen(regex)-1) {
        if (strncmp(str+i, regex, strlen(regex)-1) == 0) {
            char *tmp = (char *)malloc(sizeof(char) * (i-check+1));
            strncpy(tmp,str+check,i-check);
            *(tmp+i-check+1) = '\0';
            Stack_push(&stack, tmp);
            i += strlen(regex)-1;
            check = i;
        } else {
            i++;
        }
    }
    char *tmp = (char *)malloc(sizeof(char) * (strlen(str)-check));
    strncpy(tmp,str+check,strlen(str)-check-1);
    *(tmp+strlen(str)-check) = '\0';
    Stack_push(&stack, tmp);

    char **words = (char **)malloc((stack.amount+1) * sizeof(char *));
    for (int i=stack.amount-1; i>=0; i--) {
        *(words+i) = Stack_pop(&stack);
    }
    *(words+stack.amount) = NULL;
        

    return words;
}

int main() {
    char arr[100];
    char regex[10];

    printf("String : ");
    fgets(arr, sizeof(arr), stdin);
    printf("Regex : ");
    fgets(regex, sizeof(regex), stdin);
    
    char **newarr = split(arr, regex);
    for (int i=0; newarr[i]!=NULL; i++) {
        printf("%s\n",newarr[i]);
    }
    return 0;
}
