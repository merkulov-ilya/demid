//
//  main.c
//  demid
//
//  Created by Ilya Merkulov on 09/01/2019.
//  Copyright © 2019 Ilya Merkulov. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//void print_array(int *array, int n) {
//    for (int i = 0; i < n - 1; i++) {
//        printf("%d", array[i]);
//    }
//    printf("%d\n", array[n - 1]);
//}

int next_operations_set(char *array, int n) {
    int i = n - 1;
    while (i >= 0) {
        if (array[i] == '+') {
            array[i] = '*';
            for (int j = i + 1; j < n; j++) {
                array[j] = '+';
            }
            return 1;
        }
        i--;
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    char *operations;
    int start_num, end_num, n;

//    printf("Введите размер массива: ");
//    scanf("%d", &n);
    start_num = 2;
    end_num = 10;
    n = 3;
    
    operations = (char*) malloc(n * sizeof(char));
    for (int i = 0; i < n; i++) {
        operations[i] = '+';
    }
    
    do {
        int res = start_num;
        printf("|%d|", res);
        for (int i = 0; i < n; i++) {
            printf("%c ", operations[i]);
            if (operations[i] == '+') {
                res += start_num;
            } else {
                res *= start_num;
            }
            printf("%d|", res);
        }
        printf("\r");
    } while (next_operations_set(operations, n));
    
    free(operations);
    return 0;
}
