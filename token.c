#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

  int sum = 0;
  int maxToken = 0;
  int minToken = 0;
  int currValue = 0;
  int tokenCounter = 0;

  printf("Welcome to token generator\n");
  printf("You may enter as may words as you like\n");
  printf("Press q and <Enter> key when finished\n");

   scanToken(&sum, &currValue, &maxToken, &minToken, &tokenCounter);

   return 0;
}

scanToken(int *s, int *current, int *max, int *min, int *counter){

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
  	*counter = *counter+1;
  	char *array = token;
  	sumAndGetMinMax(array, current, s, min, max, counter);

  	printf("Current number of token entered: %d \n", *counter);
 	printf("Current token value: %d \n", *current);
 	printf("current final token value: %d \n ", *s);
 	scanToken(s, current, max, min, counter); // recursive until the user enter a 'q'

  }

}

sumAndGetMinMax(char *array, int *current, int*s, int *min, int *max, int *count)
{
	int i;

	*current = 0;

	for(i=0;i<strlen(array);i++)
	{
		int ascii = (int) array[i]; 
		if (ascii == 10)//if enter a line , exit loop
		{
			break;
		}

	  	*s += ascii;
	  	*current +=ascii;
	}
	if(*count == 1)
	{
		*min = *current;
		*max = *current;
	}

	if(*current > *max)
	{
    	*max = *current;
    }
   	else 
	{
		if (*current < *min)
		{
     		*min = *current;
      	}
    }
}

summary(int *s, int *current, int *max, int *min, int *counter)
{
	if(*counter!=0)
	{

		printf("Number of tokens entered: %d\n",  *counter);
		printf("Smalles token value: %d \n", *min);
		printf("Largest token value: %d \n", *max);
		printf("Final token value: %d\n", *s);

	}
}
