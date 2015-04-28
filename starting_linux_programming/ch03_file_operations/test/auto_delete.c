#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int second = 1;
	FILE *in, *out;
	char buf[100];

	in = fopen(argv[1],"r");
	out = fopen(argv[2],"w");

	while (second <= 300) {
		fgets(buf, sizeof(buf), in);
		fputs(buf+3, out);

		second++;
	}

	exit(0);
}
