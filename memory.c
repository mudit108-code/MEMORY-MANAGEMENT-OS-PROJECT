#include <stdio.h>
#include <stdlib.h>

#define MEMORY_SIZE 100

char memory[MEMORY_SIZE]; // Global memory array
int next_allocation_index = 0; // Next available memory index

struct MemoryBlock {
    int size;
    int start_address;
};

struct MemoryBlock allocated_blocks[MEMORY_SIZE / sizeof(struct MemoryBlock)]; // Array to store allocated blocks

void allocateMemory(int size) {
    if (next_allocation_index * sizeof(struct MemoryBlock) < MEMORY_SIZE) {
        allocated_blocks[next_allocation_index].size = size;
        allocated_blocks[next_allocation_index].start_address = next_allocation_index * sizeof(struct MemoryBlock);
        next_allocation_index++;
        printf("Memory allocated successfully.\n");
    } else {
        printf("Memory allocation failed. Insufficient memory.\n");
    }
}

void deallocateMemory(int block_index) {
    if (block_index >= 0 && block_index < next_allocation_index) {
        // Deallocate by marking the block as free
        allocated_blocks[block_index].size = 0;
        printf("Memory deallocated successfully.\n");
    } else {
        printf("Memory deallocation failed. Invalid block index.\n");
    }
}

void displayMemoryStatus() {
    printf("Memory Status:\n");
    for (int i = 0; i < next_allocation_index; i++) {
        printf("Block %d: Start Address: %d, Size: %d\n", i + 1, allocated_blocks[i].start_address, allocated_blocks[i].size);
    }
}

int main() {
    // Allocate and deallocate memory without interactive menu
    allocateMemory(20);
    displayMemoryStatus();

    allocateMemory(30);
    displayMemoryStatus();

    deallocateMemory(1);
    displayMemoryStatus();

    return 0;
}
