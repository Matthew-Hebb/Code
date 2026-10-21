#include <stdio.h>
#include <stdlib.h>

void process_data(int *ptr) {
    printf("Processing value...\n");
    *ptr = 500; // Expected crash location
}

void compute(void) {
    int *uninitialized_ptr; // Uninitialized wild pointer
    process_data(uninitialized_ptr);
}

int main(void) {
    compute();
    return 0;
}
