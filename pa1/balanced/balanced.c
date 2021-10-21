#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struct to hold the expected close brace character and a pointer to the next element.
typedef struct element {
    char close;
    struct element* next;
}element;

void pop (element** top);
void push (element** top, char bracket);
struct element* newNode(char bracket);
void freepop (element** top);
bool isPair(char left, char right);

int main(int argc, char* argv[])
{

    FILE* fp = fopen(argv[1], "r");
    if (!fp) {
        perror("fopen failed");
        return EXIT_FAILURE;
    }

    bool balanced = true;

    element* top = NULL;

    char buff;
    while ( fscanf(fp, "%c", &buff)==1 ) {
        if (buff == '<' || buff == '(' || buff == '[' || buff == '{'){
            push(&top, buff);
        }else if (buff == '>' || buff == ')' || buff == ']' || buff == '}'){
            if (top == NULL){
                balanced = false;
                break;
            }
            if (isPair(top->close, buff)){
                pop(&top);
            }else {
                balanced = false;
            }
        }
    }

    if (top != NULL){
        balanced = false;
    }
    printf ( balanced ? "yes" : "no" );
    fclose(fp);
    
    while (top != NULL){
        freepop(&top);
    }
    return 0;
}

void pop (element** top){
    element* temp = *top;

    if (*top == NULL){
        return;
    }
        *top = (*top)->next;
        //char returnChar = temp->close;
        free(temp);
        return;
}

void push (element** top, char bracket){
    element* temp = newNode(bracket);
    temp->next = *top;
    *top = temp;
    return;
}

struct element* newNode(char bracket){
    struct element* newElement = (struct element*)malloc(sizeof(struct element));
    newElement->close = bracket;
    newElement->next = NULL;
    return newElement;
}

void freepop (element** top){
    element* temp = *top;
    if (*top == NULL){
        return;
    }
    *top = (*top)->next;
    free(temp);
    return;
}

bool isPair(char left, char right){
    if (left == '(' && right == ')') 
        return 1; 
    else if (left == '{' && right == '}') 
        return 1; 
    else if (left == '[' && right == ']') 
        return 1; 
    else if (left == '<' && right == '>')
        return 1;
    else
        return 0; 
}