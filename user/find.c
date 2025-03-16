#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"

void find(const char *path, const char *target) {
    int fd;
    struct stat st;
    struct dirent de;
    char buf[512], *p;

    // Dizin aç
    if ((fd = open(path, 0)) < 0) {
        printf("find: cannot open %s\n", path);
        return;
    }

    // Dizin bilgisi al
    if (fstat(fd, &st) < 0) {
        printf("find: cannot stat %s\n", path);
        close(fd);
        return;
    }

    if (st.type != T_DIR) {
        printf("find: %s is not a directory\n", path);
        close(fd);
        return;
    }

    // Dizin içeriğini tara
    strcpy(buf, path);
    p = buf + strlen(buf);
    *p++ = '/';
    while (read(fd, &de, sizeof(de)) == sizeof(de)) {
        if (de.inum == 0)
            continue;

        memmove(p, de.name, DIRSIZ);
        p[DIRSIZ] = 0;

        // "." ve ".." dizinlerini atla
        if (strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0)
            continue;

        // Dosya adı kontrolü
        if (strcmp(de.name, target) == 0) {
            printf("%s\n", buf);
        }

        // Alt dizinlere in
        if (stat(buf, &st) == 0 && st.type == T_DIR) {
            find(buf, target);
        }
    }
    close(fd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: find <path> <filename>\n");
        exit(1);
    }
    find(argv[1], argv[2]);
    exit(0);
}
