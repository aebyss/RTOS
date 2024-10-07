#include <stdio.h>
#include <stdint.h>
#include <windows.h> // Include this for Sleep function

#define MAX_TIMER 255 

uint8_t timer_tick = 0;

void test_timer_with_delay() {
    uint8_t start_time = 0;  // Start from 0 to make it more clear
    uint8_t timeout = 60;
    uint8_t target_time = (start_time + timeout) % (MAX_TIMER + 1); // Set target_time accordingly

    for (int i = 0; i <= 100; i++) {
        timer_tick = (start_time + i) % (MAX_TIMER + 1); // Update timer_tick

        printf("Tick %d: current_time = %d\n", i, timer_tick);
        fflush(stdout); // Ensure output is displayed immediately

        // Check if timer should trigger
        if (timer_tick >= target_time) {
            printf("Timer triggers at Tick %d (current_time = %d, target_time = %d)\n", i, timer_tick, target_time);
            fflush(stdout); // Flush output before breaking
            break; // Exit the loop if the timer triggers
        }

        Sleep(100); // Wait for 1000 milliseconds (1 second)
    }
}

int main() {
    test_timer_with_delay();
    printf("Press Enter to exit...\n");
    getchar(); // Wait for user to press Enter
    return 0;
}
