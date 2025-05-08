#include <stdio.h>
#include <unistd.h>

void smart_light() { printf("Smart Light ON (PID: %d)\n", getpid()); }
void smart_ac() { printf("Smart AC ON (PID: %d)\n", getpid()); }
void smart_alarm() { printf("Smart Alarm Armed (PID: %d)\n", getpid()); }

int main() {
    for (int i = 0; i < 3; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            if (i == 0) smart_light();
            else if (i == 1) smart_ac();
            else smart_alarm();
            return 0;
        }
    }
    return 0;
}
