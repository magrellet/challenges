#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 
  char token[12] = "sarasa";
  int len;
  int i = 0;
  int sum = 0;
  int maxToken = 0;
  int minToken = 0;
  int currValue = 0;
  int tokenCounter = 10;
  
  printf("Welcome to token generator\n");
  printf("You may enter as may words as you like\n");
  printf("Press q and <Enter> key when finished\n");
  
   scanToken(&sum, &currValue, &maxToken, &minToken, &tokenCounter);
   
//   summary(&sum, &maxToken, &minToken, &tokenCounter);
  
   printf("suma %d \n", sum);
   return 0;
}

scanToken(int *s, int *current, int *max, int *min, int *counter){
  int a;
 
  char token [100];  
  fgets (token, 100, stdin);
  int ascii = (int) token[0];
  if(ascii==113)//113 = ascii value for 'q'
  {
  	summary(s, current, max, min, counter);
    printf("Thank you for using tokengen!");
  }
  else
  {
  	char *array = token;
  	*s = sum(array);
  }
  
}

int sum(char *array)
{
	int i;
	int sum=0;
	for(i=0;i<strlen(array);i++)
	{
		int ascii = (int) array[i];
	  	sum += ascii;  	
	}
	return sum;
}

summary(int *s, int *current, int *max, int *min, int *counter)
{
	printf("Summary\n %d %d %d %d \n", *s, *current, *max, *min, *counter);
}
