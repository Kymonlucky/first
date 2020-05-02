#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<cs50.h>

int main(int argc,char* argv[]){
	if(argc != 2){
		printf("Error!\n");
		return 1;
	}
	
	int keys = atoi(argv[1]);
	char* plainText;
	char cipherText[200];
	int ascii;
	char current;
	int sum;

	plainText = get_string("plaintext: ");

	for(int x = 0,l = strlen(plainText); x < l; x++){
	current = plainText[x];
		
	if(isalpha(current)){

		if(isupper((int)plainText[x])){
			ascii = (int)current;
			sum =(((ascii - 'A') + keys) % 26) + 'A';
			cipherText[x] = (char)sum;
		//sum =(((ascii - 'A') + keys) % 26) + 'A';
			}

		else{
			ascii = (int)current;
		cipherText[x] = (char)(((ascii - 'a') + keys) % 26) + 'a';
		}
	
		}

	else cipherText[x] = plainText[x];

		
		}
	//printf("Sum: %c\n",sum);
	printf("ciphertext: %s\n",cipherText);

}
