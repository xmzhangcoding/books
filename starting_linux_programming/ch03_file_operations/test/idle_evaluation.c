#include <stdio.h>
#include <stdlib.h>

int main()
{
	int c, i = 0, second = 1;
	FILE *in, *out;
	char buf[100];
	double tm[1000], vol[1000], cur[1000], power[1000];

	char temp[100];
	double average = 0, sum =0, max = 0;

	in = fopen("power.txt","r");
	out = fopen("post_power.txt","w");

	fgets(buf, sizeof(buf), in);
	fputs("time\taverage_current\tmax_current\n", out);

	while (second <= 300) {
		while(i < 1000) {
			fgets(buf, sizeof(buf), in);
			sscanf(buf, "%lf\t%lf\t%lf\t%lf", &tm[i], &vol[i], &cur[i], &power[i]);

			max = (max > cur[i]) ? max : cur[i];

			sum += cur[i];
			i++;
		}

		average = sum / i;
	//	printf("%lf\n", average);
		sprintf(temp, "%d\t%lf\t%lf\n",second ,average, max);
		fputs(temp, out);

		sum = 0;
		i = 0;

		second++;
	}

	exit(0);
}
