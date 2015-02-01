#include <stdio.h>
#include <stdlib.h> 
void
die(char *message)
{
	perror(message);
	exit(1);
}
int
getbat()
{
	char buf[6];
	int bc;
	FILE *f = fopen("/sys/class/power_supply/battery/capacity","r");
	if(f){
		bc =atoi(fgets(buf,5,f));
		fclose(f);
		return bc;
	}
	else
		die("Can't open sysfs battery device, check permisions\n");
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
//	percentbar("battery: ",getbat(),80);
	return 0;
}
