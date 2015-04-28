#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd, len;

	const char *path = "/proc/sys/kernel/printk";
	char orig[32] = {0};
	char new_set[32] = {0};

	if ((fd = open(path, O_RDWR)) < 0) {
		printf("open error\n");
		return -1;
	}

	len = read(fd, orig, sizeof(orig));
	printf("orig:\t%s", orig);

	memcpy(new_set, orig, sizeof(orig));
	memset(new_set, '1', 1);
	if ((len = write(fd, new_set, sizeof(new_set)) <= 0)) {
		printf("write error");
		return -1;
	}

	len = read(fd, new_set, sizeof(new_set));
	printf("new:\t%s", new_set);

	if ((len = write(fd, orig, sizeof(orig)) <= 0)) {
		printf("write error");
		return -1;
	}

	return 0;
}
