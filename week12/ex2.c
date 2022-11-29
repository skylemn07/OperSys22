#include <stdio.h>
#include <linux/input.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

typedef struct input_event input_event;

static const char *const eventValNames[3] = {
        "RELEASED",
        "PRESSED ",
        "REPEATED"
};

int main() {
    const char *dev = "/dev/input/by-path/platform-i8042-serio-0-event-kbd";
    int fd = open(dev, O_RDONLY);

    if (fd == -1) {
        printf("File with keyboard input events cannot be open\n");
        return 0;
    }

    input_event event;
    ssize_t n;

    while (1) {
        n = read(fd, &event, sizeof event);

        if (n == (ssize_t) - 1) {
            if (errno == EINTR)
                continue;
            else
                break;
        }
        else if (n != sizeof event) {
            errno = EIO;
            break;
        }

        if (event.type == EV_KEY && event.value >= 0 && event.value <= 2)
            printf("\n%s 0x%04X (%d)\n", eventValNames[event.value], (int)event.code, (int)event.code);
            
    }

    fflush(stdout);
    return 0;
}
