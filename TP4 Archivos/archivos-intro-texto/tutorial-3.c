#include <stdio.h>
#include <stdlib.h>

int main () {
	FILE *fp;
	char a[200];
	scanf("%c",a);
	fp = fopen("archivo-append.txt", "a");
	fputs(a, fp);
	fclose(fp);
	return(0);
}
