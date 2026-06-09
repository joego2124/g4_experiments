#include <sys/stat.h>
#include <errno.h>


// Used for closing a file descriptor (not needed for stdout/stderr)
int _close(int file) {
    return -1;
}

// Used to get file status (not needed for a simple UART)
int _fstat(int file, struct stat *st) {
    st->st_mode = S_IFCHR; // Indicate a character device (like a terminal)
    return 0;
}

// Used to check if a file descriptor refers to a terminal (stdout/stderr)
int _isatty(int file) {
    if (file == 1 || file == 2) { // stdout or stderr
        return 1; // Yes, it's a terminal
    }
    return 0;
}

// Used for moving the file offset (not applicable to a serial stream)
int _lseek(int file, int ptr, int dir) {
    return 0;
}

// Used for reading data (e.g., scanf). We don't implement it here.
int _read(int file, char *ptr, int len) {
    errno = ENOSYS; // Error: Function not implemented
    return -1;
}

// Used to manage the heap/memory allocation (often used by malloc)
caddr_t _sbrk(int incr) {
    errno = ENOMEM; // Error: Not enough memory
    return (caddr_t)-1;
}