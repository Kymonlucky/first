#include<stdio.h>
#include<stdlib.h>
#include<cs50.h>

int main(void){

	long long ccNumber;
	int sum1;
	int sum2;
	int total;
	int current;
	int digits = 0;
	int fd;
	ccNumber = get_long_long("Number: ");
	long long temp = ccNumber;

	while(temp > 0){

		if(temp < 100 && temp > 10)
			fd = temp;

		temp = temp / 10;
		digits++;
	}
	
	temp = ccNumber;
	temp = temp/10;
	sum1 = 0;
	while(temp > 0){
		current = (temp % 10) * 2;
		if(current > 9){
			sum1 = sum1 + (current%10) + ((current/10)%10);
		}
		else 	sum1 = sum1 + current;
	
		temp = temp / 100; 
	}

	temp = ccNumber;
	sum2 = 0;
	while(temp > 0){
		current = temp %10;
		sum2 = sum2 + current;
		temp = temp /100;
	}


	total = sum1 +  sum2;

	if(total % 10 == 0 && (fd == 34 || fd == 37) && digits == 15)
		printf("AMEX\n");
	else if(total % 10 == 0 && (fd >=51 && fd <= 55) && digits == 16)
		printf("MASTERCARD\n");
	else if(total % 10 == 0 && (fd > 39 && fd < 50) && (digits == 13 || digits == 16))
		printf("VISA\n");
	else
		printf("INVALID\n");
	
}

