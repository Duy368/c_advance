#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* ================= 2. STACK OVERFLOW ================= */
/* 2.1 Requirement: Function using recursion to intentionally cause Stack Overflow. */
/* It prints the current depth to observe the process. */
void cause_stack_overflow(int depth) {
    /* Local array to consume stack memory quickly (approx 4KB per call) */
    int dummy[1000]; 
    memset(dummy, depth, sizeof(dummy));

    printf("Recursion depth: %d\n", depth);
    
    /* Minimal delay to allow observation in terminal */
    usleep(5000); 

    /* Recursive call without a base case leads to infinite recursion */
    cause_stack_overflow(depth + 1); 
}

/* ================= 3. MEMORY LEAK & OUT OF MEMORY ================= */
/* 3.1 Requirement: Infinite loop continuously allocating memory without free(). */
void cause_memory_leak() {
    size_t count = 0;
    /* Using 1MB chunks to reach Out of Memory (OOM) state efficiently */
    const size_t chunk_size = 1024 * 1024; 

    printf("Starting memory leak loop...\n");
    while (1) {
        void *ptr = malloc(chunk_size); 

        /* 3.1 Requirement: Check if malloc returns NULL (Out of Memory) */
        if (ptr == NULL) {
            printf("\n[FATAL ERROR] Out of Memory! Malloc returned NULL.\n");
            printf("Total leaked before failure: %zu MB\n", count);
            /* Return safely so GDB can inspect the final state */
            return; 
        }

        count++;
        if (count % 100 == 0) {
            printf("Currently Leaked: %zu MB\n", count);
        }

        /* ❌ Logic Error: No free(ptr) call here creates the Memory Leak */
    }
}

/* ================= 1. MAIN ================= */
/* 1.2 Requirement: Handle command line parameters to select the error. */
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage:\n");
        printf("  %s stack_overflow\n", argv[0]);
        printf("  %s memory_leak\n", argv[0]);
        printf("  %s out_of_memory\n", argv[0]);
        return 1;
    }

    /* Route to specific error based on argument */
    if (strcmp(argv[1], "stack_overflow") == 0) {
        cause_stack_overflow(1);
    } 
    else if (strcmp(argv[1], "memory_leak") == 0 || 
             strcmp(argv[1], "out_of_memory") == 0) {
        cause_memory_leak();
    } 
    else {
        printf("Error: Unknown option '%s'\n", argv[1]);
        return 1;
    }

    return 0;
}