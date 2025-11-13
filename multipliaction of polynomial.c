#include <stdio.h>
#include <stdlib.h>

struct node {
    int co, po;
    struct node *addr;
};

typedef struct node *NODE;

l
NODE insertend(NODE start, int co, int po) {
    NODE temp = (NODE)malloc(sizeof(struct node));
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if (start == NULL)
        return temp;

    NODE curr = start;
    while (curr->addr != NULL)
        curr = curr->addr;

    curr->addr = temp;
    return start;
}


void display(NODE start) {
    if (start == NULL) {
        printf("Polynomial is empty\n");
        return;
    }

    NODE temp = start;
    while (temp != NULL) {
        printf("%d*x^%d", temp->co, temp->po);
        if (temp->addr != NULL)
            printf(" + ");
        temp = temp->addr;
    }
    printf("\n");
}


NODE addterm(NODE res, int co, int po) {
    NODE curr = res;
    while (curr != NULL) {
        if (curr->po == po) {
            curr->co += co;
            return res;
        }
        curr = curr->addr;
    }
    return insertend(res, co, po);
}


NODE multiply(NODE poly1, NODE poly2) {
    NODE p1, p2, res = NULL;
    for (p1 = poly1; p1 != NULL; p1 = p1->addr) {
        for (p2 = poly2; p2 != NULL; p2 = p2->addr) {
            res = addterm(res, p1->co * p2->co, p1->po + p2->po);
        }
    }
    return res;
}


int main() {
    NODE poly1 = NULL, poly2 = NULL, poly = NULL;
    int n, i, co, po;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter coefficient and power of term %d: ", i);
        scanf("%d %d", &co, &po);
        poly1 = insertend(poly1, co, po);
    }

    printf("Polynomial 1 is: ");
    display(poly1);

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        printf("Enter coefficient and power of term %d: ", i);
        scanf("%d %d", &co, &po);
        poly2 = insertend(poly2, co, po);
    }

    printf("Polynomial 2 is: ");
    display(poly2);

    poly = multiply(poly1, poly2);
    printf("Resultant polynomial is: ");
    display(poly);

    return 0;
}
