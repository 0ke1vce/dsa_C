#include <stdio.h>
#include <stdlib.h>

typedef struct Array {
    int t_size;
    int u_size;
    int *p;
} arr;

void createarray(arr *a, int tsize, int usize) {
    a->t_size = tsize;
    a->u_size = usize;
    a->p = (int *)malloc(tsize * sizeof(int));
}

void setval(arr *a) {
    for (int i = 0; i < (a->u_size); i++) {
        printf("Enter value\n");
        scanf("%d", (a->p + i));
    }
}

void showarr(arr *a) {
    for (int i = 0; i < (a->u_size); i++) {
        printf("%d ", *(a->p + i));
    }
    printf("\n");
}

void insertion(arr *a, int value, int index) {
    if ((a->u_size) >= (a->t_size)) {
        printf("Overflow\n");
        return;
    }

    for (int i = (a->u_size) - 1; i >= index; i--) {
        *(a->p + i + 1) = *(a->p + i);
    }
    *(a->p + index) = value;
    a->u_size++;
}

void deletion(arr *a, int index) {
    if ((a->u_size) <= 0) {
        printf("Underflow\n");
        return;
    }

    for (int i = index; i < (a->u_size) - 1; i++) {
        *(a->p + i) = *(a->p + i + 1);
    }

    a->u_size--;
}

int main() {
    arr marks;
    int tsize, usize;

    printf("Enter total size and used size\n");
    scanf("%d %d", &tsize, &usize);

    createarray(&marks, tsize, usize);
    setval(&marks);

    printf("Array before insertion:\n");
    showarr(&marks);

    insertion(&marks, 54, 3);

    printf("Array after insertion:\n");
    showarr(&marks);

    deletion(&marks, 3);

    printf("Array after deletion:\n");
    showarr(&marks);

    free(marks.p);  // Don't forget to free allocated memory

    return 0;
}
