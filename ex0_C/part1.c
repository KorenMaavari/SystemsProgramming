#include <stdio.h>
#include <stdlib.h>

#define VALID -1
#define INVALID -2
#define DNE -3 // Does Not Exist
#define TWO 2
#define INT_MAXIMUM 2147483647

int enter_size_of_input (int *size_of_input_pointer);
int verify_size_of_input (int size_of_input);
int enter_numbers (int size_of_input, int *numbers);
int pow_of_2 (int number);
void print_pows_of_2_and_sum (int numbers[], int size_of_input);

int main () {
    int size_of_input = 0;
    int *size_of_input_pointer = &size_of_input;
    if (enter_size_of_input(size_of_input_pointer) == INVALID) {
        return 0;
    }
    if (verify_size_of_input(size_of_input) == INVALID) {
        return 0;
    }
    int *numbers = (int*)malloc(sizeof(int*) * size_of_input);
    if (numbers == NULL) {
        printf("Error!\n");
        free(numbers);
        return 0;
    }
    if (enter_numbers(size_of_input, numbers) == INVALID) {
        free(numbers);
        return 0;
    }
    print_pows_of_2_and_sum(numbers, size_of_input);
    free(numbers);

    return 0;
}

int enter_size_of_input (int *size_of_input_pointer) {
    printf("Enter size of input:\n");
    scanf("%d", size_of_input_pointer);
    if ((*size_of_input_pointer) <= 0 || (*size_of_input_pointer) >= INT_MAXIMUM) {
        printf("Invalid size\n");
        return INVALID;
    }
    return VALID;
}

int verify_size_of_input (int size_of_input) {
    if (size_of_input <= 0) {
        printf("Invalid size\n");
        return INVALID;
    }
    return VALID;
}

int enter_numbers (int size_of_input, int *numbers) {
    printf("Enter numbers:\n");
    for (int i=0 ; i<size_of_input ; i++) {
        if (scanf(" %d", &numbers[i]) < 1) {
            printf("Invalid number\n");
            return INVALID;
        }
    }
    return VALID;
}

int pow_of_2 (int number) {
    int i = 0;
    int two_pow_i = 1;
    while (two_pow_i <= number) {
        if (number < 1 || two_pow_i < 1) {
            break;
        } else if (number == two_pow_i) {
            return i;
        } else {
            i++;
            two_pow_i *= TWO;
        }
    }
    return DNE;
}

void print_pows_of_2_and_sum (int numbers[], int size_of_input) {
    int curr_exp;
    int sum = 0;
    for (int i=0 ; i<size_of_input ; i++) {
        curr_exp = pow_of_2(numbers[i]);
        if (curr_exp == DNE) {
            continue;
        }
        printf("The number %d is a power of 2: %d = 2^%d\n",
        numbers[i], numbers[i], curr_exp);
        sum += curr_exp;
    }
    printf("Total exponent sum is %d\n", sum);
}
