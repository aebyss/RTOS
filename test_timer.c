#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define TIMER_EXPIRE_VALUE 100 //finish time in ticks 

bool false_timer_check(uint8_t start_time, uint8_t current_time) {
    return (current_time >= start_time + TIMER_EXPIRE_VALUE);
}

bool correct_timer_check(uint8_t start_time, uint8_t current_time) {
    return ((int8_t)(current_time - start_time) >= TIMER_EXPIRE_VALUE);
}

void run_test(uint8_t start_time, uint8_t ticks_to_expire, uint8_t total_ticks) {
    printf("Test:  Startime= %u,  Finish Time= %u Ticks\n", start_time, ticks_to_expire);
    
    for (uint8_t i = 0; i <= total_ticks; i++) {
        uint8_t current_time = (start_time + i) % 256; //8 bit overflow 
        printf("Current Time: %u\n", current_time);
        
        bool is_false_expired = false_timer_check(start_time, current_time);
        bool is_correct_expired = correct_timer_check(start_time, current_time);
        
        printf("False: %s\n", is_false_expired ? "Timer finished!" : "Timer is running still...");
        printf("Correct: %s\n\n", is_correct_expired ? "Timer finished!" : "Timer is running still...");
    }
    printf("\n");
}

int main() {

    // Test 1: Starttime = 200, Donetime = 100 Ticks
    // run_test(200, 100, 150);  //  150 Ticks

    //Test 2: Startime = 250, Finishtime - 50 Ticks
    run_test(250, 50, 100); //100 ticks

    // Test3: Starttime = 50, Finishtime = 200 Ticks
    // run_test(50, 200, 250); //250 ticks

    return 0;
}
