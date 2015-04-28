#include <stdio.h>
#include <stdlib.h>

char buf[100];

int process(FILE *in, FILE *out, int len)
{
	while (len--) {
		fgets(buf + sizeof(buf), sizeof(buf), in);
		fputs(buf, out);
	}

	return 0;
}

int main(void)
{

	int i = 0, second = 1;
	FILE *in, *out;
	double tm[1000], vol[1000], cur[1000], power[1000];

	char temp[100], *ch;
	double average = 0, sum =0, max = 0;

	in = fopen("test.txt","r");
	out = fopen("1_test.txt","w");

	printf("debug ok %d\n", __LINE__);

	//fputs("time\taverage_current\tmax_current\n", out);

	ch = fgets(buf, sizeof(buf), in);
	
	printf("ch is %s\n", ch);

	do {

		fputs(buf, out);
	
	} while ( ( ch = fgets(buf, sizeof(buf), in) ) != NULL ); 
	
	//process(in, out, 2);
	//process(in, out, 2);

	return 0;
}
