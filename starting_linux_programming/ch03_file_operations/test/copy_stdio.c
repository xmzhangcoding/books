#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, i = 0, j = 1;
    FILE *in, *out;
	char buf[100];
	double tm[1000], vol[1000], cur[1000], power[1000];

	double f = 0;

    in = fopen("power.txt","r");
    out = fopen("file.out","w");

	fgets(buf, sizeof(buf), in);
    fputs(buf, out);
	while(i < 1000) {
		fgets(buf, sizeof(buf), in);
		sscanf(buf, "%lf\t%lf\t%lf\t%lf", &tm[i], &vol[i], &cur[i], &power[i]);
	
		f += cur[i];

		//printf("%lf %lf %lf %lf\n", tm[i], vol[i], cur[i], power[i]);

		i++;

		//if ((c = fgetc(in)) == '\t')
#if 0
		j--;
		buf[i] = (char )c;
		i++;
		printf("%c\n", (char )c);
		fputc(c,out);
#endif
	}
	
	char temp[100];
	f = f / 1000;
	printf("%lf\n", f);
	sprintf(temp, "%d\t%d\t%lf\t%d",1 ,1, f, 1);
	fputs(temp, out);


#if 0
	buf[i] = '\0';
        
	printf("%d\n", i);
	printf("%s\n", buf);

	f = atof(buf);
	printf("%lf\n", f);
#endif

	char str[260]; 
	float ft = -3.1415926; 
	float f1 = 263e-5; 
	sprintf(str,"%f",ft); 
	printf("%s\n",str); 
	sprintf(str,"%f",f1); 
	printf("%s\n",str);

	exit(0);
}
