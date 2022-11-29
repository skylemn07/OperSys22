#include <stdio.h>
#include <stdlib.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>

#define KEYBOARD_EVENTS_HISTORY_BUFFER 20
#define RELEASED 0
#define PRESSED 1
#define REPEATED 2

typedef struct input_event input_event;


int getPrevEventIdx(int eventIdx) {
    return (KEYBOARD_EVENTS_HISTORY_BUFFER + (eventIdx - 1)) % KEYBOARD_EVENTS_HISTORY_BUFFER;
}

bool is_PE_shortcut(input_event events[KEYBOARD_EVENTS_HISTORY_BUFFER], int curEventIdx) {
    if (curEventIdx < 0 || curEventIdx >= KEYBOARD_EVENTS_HISTORY_BUFFER)
        return false;

    input_event *curEvent = &events[curEventIdx];

    int prev1Idx = getPrevEventIdx(curEventIdx);
    input_event *pPrev1Event = &events[prev1Idx];

    if ((int) curEvent->code == KEY_E &&
        (pPrev1Event->value == PRESSED || pPrev1Event->value == REPEATED) &&
        (int) pPrev1Event->code == KEY_P)
    {
        return true;
    }

    return false;
}

bool is_CAP_shortcut(input_event events[KEYBOARD_EVENTS_HISTORY_BUFFER], int curEventIdx) {
    if (curEventIdx < 0 || curEventIdx >= KEYBOARD_EVENTS_HISTORY_BUFFER)
        return false;

    input_event *curEvent = &events[curEventIdx];

    int prev1Idx = getPrevEventIdx(curEventIdx);
    input_event *pPrev1Event = &events[prev1Idx];

    int prev2Idx = getPrevEventIdx(prev1Idx);
    input_event *pPrev2Event = &events[prev2Idx];

    if ((int) curEvent->code == KEY_P &&
        (pPrev1Event->value == PRESSED || pPrev1Event->value == REPEATED) &&
        (int) pPrev1Event->code == KEY_A &&
        (pPrev2Event->value == PRESSED || pPrev2Event->value == REPEATED) &&
        (int) pPrev2Event->code == KEY_C)
    {
        return true;
    }

    return false;
}



int main() {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY); 

    if (fd == -1) {
        printf("File with keyboard input events cannot be open\n");
        return 0;
    }

    printf("Available shortcuts: P+E, C+A+P\n");

    input_event events[KEYBOARD_EVENTS_HISTORY_BUFFER];
    int eventIdx = 0;

    input_event tmpEvent;
    ssize_t n;

    while(1) {
        n = read(fd, &tmpEvent, sizeof tmpEvent);

        if (n == (ssize_t) - 1) {
            if (errno == EINTR) continue;
            else break;
        }
        else if (n != sizeof tmpEvent) {
            errno = EIO;
            break;
        }

        if (tmpEvent.type == EV_KEY && (tmpEvent.value == RELEASED || tmpEvent.value == PRESSED)) {
            events[eventIdx] = tmpEvent;

            if (is_PE_shortcut(events, eventIdx))
                printf("\nI passed the Exam!\n");
            else if (is_CAP_shortcut(events, eventIdx))
                printf("\nGet some cappuccino!\n");

            if (++eventIdx == KEYBOARD_EVENTS_HISTORY_BUFFER)
                eventIdx = 0;
        }
    }

    fflush(stdout);
    return 0;
}
