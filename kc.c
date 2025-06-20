#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBERS 9

void find_combinations(int *combination, int start, int sum, int target_sum, int num_cells, int *used, int *must_include, int must_count, int *cannot_include, int cannot_count) {
    if (num_cells == 0) {
        if (sum == target_sum) {
            for (int i = 0; i < MAX_NUMBERS; i++) {
                if (used[i]) {
                    printf("%d ", i + 1);
                }
            }
            printf("\n");
        }
        return;
    }

    for (int i = start; i < MAX_NUMBERS; i++) {
        if (used[i] || (cannot_count > 0 && cannot_include[i])) {
            continue;
        }

        if (must_count > 0 && !must_include[i]) {
            continue;
        }

        used[i] = 1;
        combination[MAX_NUMBERS - num_cells] = i + 1;
        find_combinations(combination, i + 1, sum + (i + 1), target_sum, num_cells - 1, used, must_include, must_count, cannot_include, cannot_count);
        used[i] = 0;
    }
}

void parse_arguments(int argc, char *argv[], int *target_sum, int *num_cells, int *must_include, int *cannot_include, int *must_count, int *cannot_count) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <target_sum> <num_cells> [-<exclude_numbers>] [+<include_numbers>]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    *target_sum = atoi(argv[1]);
    *num_cells = atoi(argv[2]);
    *must_count = 0;
    *cannot_count = 0;

    for (int i = 3; i < argc; i++) {
        if (argv[i][0] == '-') {
            for (int j = 1; j < strlen(argv[i]); j++) {
                int num = argv[i][j] - '0';
                if (num >= 1 && num <= MAX_NUMBERS) {
                    cannot_include[num - 1] = 1;
                    (*cannot_count)++;
                }
            }
        } else if (argv[i][0] == '+') {
            for (int j = 1; j < strlen(argv[i]); j++) {
                int num = argv[i][j] - '0';
                if (num >= 1 && num <= MAX_NUMBERS) {
                    must_include[num - 1] = 1;
                    (*must_count)++;
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int target_sum, num_cells;
    int must_include[MAX_NUMBERS] = {0};
    int cannot_include[MAX_NUMBERS] = {0};
    int must_count, cannot_count;

    parse_arguments(argc, argv, &target_sum, &num_cells, must_include, cannot_include, &must_count, &cannot_count);

    int combination[MAX_NUMBERS] = {0};
    int used[MAX_NUMBERS] = {0};

    find_combinations(combination, 0, 0, target_sum, num_cells, used, must_include, must_count, cannot_include, cannot_count);

    return 0;
}
