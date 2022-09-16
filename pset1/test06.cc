#include "m61.hh"
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cinttypes>
#include <cstddef>
// Check for correct allocation alignment.

int main() {
    double* ptr = (double*) m61_malloc(sizeof(double));
    assert((uintptr_t) ptr % alignof(double) == 0);
    assert((uintptr_t) ptr % alignof(unsigned long long) == 0);
    assert((uintptr_t) ptr % alignof(std::max_align_t) == 0);

    char* ptr2 = (char*) m61_malloc(1);
    assert((uintptr_t) ptr2 % alignof(double) == 0);
    assert((uintptr_t) ptr2 % alignof(unsigned long long) == 0);
    //printf("(uintptr_t) ptr2: %li\n",(uintptr_t) ptr2);
    //printf("alignment of max_align_t: %li\n", alignof(std::max_align_t));
    //printf("some shit: %li" ,(uintptr_t) ptr2 % alignof(std::max_align_t));

    // address value returned by m61_malloc() must be evenly divisible by 16 ... this returns 8!
    // pointer address must be shifted or added by 8 in order for it to be divisible by 16!
    assert((uintptr_t) ptr2 % alignof(std::max_align_t) == 0);

    m61_free(ptr);
    m61_free(ptr2);
}
