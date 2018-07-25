#include <stdio.h>
#include <stdlib.h>
void itoa(unsigned long val, char *buf, unsigned radix)
{ 
	char *p;           /* pointer to traverse string */ 
	char *firstdig;       /* pointer to first digit */ 
	char temp;           /* temp char */ 
	unsigned digval;       /* value of digit */ 
	
	p = buf; 
	firstdig = p;         /* save pointer to first digit */ 
	
	do{
		digval = (unsigned) (val % radix); 
		val /= radix;     /* get next digit */ 
		
		/* convert to ascii and store */ 
		if (digval > 9) 
			*p++ = (char)(digval - 10 + 'a');   /* a letter */ 
		else 
			*p++ = (char)(digval + '0');     /* a digit */ 
	} while(val > 0); 
	
	/* We now have the digit of the number in the buffer, but in reverse 
	   order.   Thus we reverse them now. */ 
	
	*p-- = '\0';         /* terminate string; p points to last digit */ 
	
	do{ 
		temp = *p; 
		*p = *firstdig; 
		*firstdig = temp;   /* swap *p and *firstdig */ 
		--p; 
		++firstdig;       /* advance to next two digits */ 
	} while (firstdig < p); /* repeat until halfway */ 
}




int main(int argc, char *argv[])
{
	int a = 255;
	char s[10];
	itoa(a, s, atoi(argv[1]));
	printf("%s\n", s);
	return 0;
}
