void errp(int line);
void printErrorno(int n);
void openN(int n);
ssize_t Write(int fd, const void *buf, size_t count);

#define err() errp(__LINE__)
