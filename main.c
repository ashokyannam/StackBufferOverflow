#include <stdio.h>
#include <string.h>

void maliciousCode()
{
	printf("Successfully executed malicious code!\n");
}

void inputDataProcessing()
{
	char dataBuffer[50];

	printf("Get Input Data Stream:\n");
	gets(dataBuffer);
	printf("Input Data Stream: %s\n", dataBuffer);	
}

int main(int argc, const char * argv[])
{
	inputDataProcessing();

	return 0;
}
