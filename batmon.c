#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
#include <sys/types.h>
#include <dirent.h>
void
die(char *message)
{
	perror(message);
	exit(1);
}
char *
getbatname(int stop, char *buf)
{
	DIR *bats = opendir("/sys/class/power_supply/");
	struct dirent *cbat;
	stop=stop+2;
	for(;
		stop>0 &&
		(cbat=readdir(bats));
		stop--
	);
	strcpy(buf,cbat->d_name);
	return buf;
}
char *
getbatpath(char *name , char *buf)
{
	puts(buf);
	//strcpy(buf,cbat->d_name);
	strcat(buf,"/sys/class/power_supply/");
	puts(buf);
	strcat(buf,name);
	strcat(buf,"/capacity");
	return buf;
}
int
getbat(char *batpath)
{
	char buf[6];
	int bc;
	FILE *f = fopen(batpath,"r");
	if(f){
		bc =atoi(fgets(buf,5,f));
		fclose(f);
		return bc;
	}
	else
	{
		die(batpath);
	}
}
/*void
percentbar(char *message,int n,int w)
{
	int i=0;
	char c;
	for(i=0;i<w;i++){
		c=message
		if(!c)
			c=nm;
			if(c)
				nm++;
		else
			message +=1;
		if(	
}*/
int
main()
{
	char buff[256];
	char *buf=&buff[0];
	*buf=0;
	char buff2[512];
	buff2[0]=0;
//	percentbar("battery: ",getbat(),80);
	printf("%d",getbat(getbatpath(getbatname(2,buf),buff2)));
	return 0;
}
