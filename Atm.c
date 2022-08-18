#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#define max 100
#define apass "1234"
void attendant();
void user(char[]);
void open();
void update();
void dands();
void balance(char[]);
void transfer(char[]);
void withdrawal(char[]);
void rau(char[]);
void changepass(char[]);
struct Account{
	char name[20];
	char lastname[20];
	char account_number[5];
	char password[5];	
	long int balance;
	signed long recent[5];
};
struct Account db[max];
struct Account t[max];
static int index = 0;
long int tran;
int amount;
void delay(float number_of_seconds)
{
    float milli_seconds = 1000 * number_of_seconds;
    clock_t start_time = clock();
    while (clock() < start_time + milli_seconds)
        ;
}
int main(){
	char w[]="lastname";
	
	int i , j ;
	char n[] = {'s','h','a','k','i','l','a',' ','k','a','r','i','m','i'};
	char m[] = {'A','T','M'};
		for(i = 0 ; i<100 ; i++){
		delay(0.04);
		if(i<49){
			printf("/");
		}
		if(i==49){
			printf(" ");
			for(j = 0 ; j<3 ; j++ ){
				printf("%c",m[j]);
				delay(0.08);
			}
			printf(" ");
			i=52;
		}
		if(i>=52){
			printf("\\");
		}
	}
		printf("\n");
	for(i = 0 ; i<100 ; i++){
		delay(0.04);
		printf("*");
		if(i==42){
			printf(" ");
			for(j = 0 ; j<15 ; j++ ){
				printf("%c",n[j]);
				delay(0.08);
			}
			printf(" ");
			i=57;
		}
}
			printf("\n");

	char c ;
	printf("1.sign in as attendant .\n");
	printf("2.sign in as user .\n");
	printf("3.Exit .\n");
	char password[5];
	c = getchar();
	int c1 = 0 ;
	while(c!='3'){
		switch(c){
			case '1': printf("Enter the password :"); 
			scanf("%s",password); 
			if(strcmp(password,apass)==0){
			attendant();
			} else{
				printf("Wrong password !");
			} break;
			case '2': printf("Enter the password :"); 
			scanf("%s",password); 
			for(i = 0 ; i < index ; i++){
				if(strcmp(password,db[i].password)==0){
					user(password);
					c1 = 1;}
				else if(c1==0&&i==index-1){
					printf("Wrong password !");
				}}
				break;
			default: break ;
		}
		if(c!='1'&&c!='2'){
			break;
		}
		printf("1.sign in as attendant .\n");
		printf("2.sign in as user .\n");
		printf("3.Exit .\n");
		c = getchar();
	}
}
void attendant(){
	getchar();
	char c ;
	printf("1.Open an account .\n");
	printf("2.Update an account .\n");
	printf("3.Delete and settle an account .\n");
	printf("4.Back to the main menu .\n");
	while((c = getchar())!='4'){
		switch(c){
			case '1': open(); break;
			case '2': update(); break;
			case '3': dands(); break;
			default : break;
		}
		if(c!='1'&&c!='2'&&c!='3'){
			break;
		}
		printf("1.Open an account .\n");
	    printf("2.Update an account .\n");
	    printf("3.Delete and settle an account .\n");
		printf("4.Back to the main menu .\n");
	}
	getchar();
}
void user(char password[]){
	getchar();
	char c ;
	printf("1.Account balance .\n");
	printf("2.Cash Transfer .\n");
	printf("3.Cash Withdrawal .\n");
	printf("4.Recent Account updates .\n");
	printf("5.Change Password .\n");
	printf("6.Back to the main menu .\n");
	c = getchar();
	while(c!='6'){
		switch(c){
			case '1': balance(password); break;
			case '2': transfer(password); break;
			case '3': withdrawal(password); break;
			case '4': rau(password); break ;
			case '5': changepass(password); break;
			default: break;
		}
		if(c!='1'&&c!='2'&&c!='3'&&c!='4'&&c!='5'){
			break;
		}
		printf("1.Account balance .\n");
	    printf("2.Cash Transfer .\n");
	    printf("3.Cash Withdrawal .\n");
		printf("4.Recent Account updates .\n");
		printf("5.Change Password .\n");
		printf("6.Back to the main menu .\n");
		c = getchar();
	}
	getchar();
}
void open(){
	getchar();
	printf("Enter user's name :");
	scanf("%[^\n]s",db[index].name);
	getchar();
	printf("Enter user's last name :");
	scanf("%[^\n]s",db[index].lastname);
	getchar();
	printf("Enter user's Account Number :");
	scanf("%[^\n]s",db[index].account_number);
	getchar();
	printf("Enter user's password:");
	scanf("%[^\n]s",db[index].password);
	getchar();
	printf("Enter user's balance :");
	scanf("%d",&db[index].balance);
	getchar();
	index++;
}
void update(){
	getchar();
	printf("which user's information do you want to change(Enter the Account Number)?");
	char an[5];
	int i , andis ; 
	scanf("%[^\n]s",an);
	getchar();
	for(i = 0 ; i < index ; i++){
		if(strcmp(an,db[i].account_number)==0){
			andis = i ;
		}
	}
	printf("\nwhat information of mr/mrs %s %s's account do you want to update(choose a number from the bottom list) ? ",db[andis].name,db[andis].lastname);
	char w[10];
	printf("\n1.password\n2.balance\n");
	char c = getchar();
	switch(c){
		case '1':printf("Enter the new password of the user :");scanf("%s",db[andis].password);break;
		case '2':printf("Enter the new balance of the user :");scanf("%d",db[andis].balance);break;
	}
	}	
void dands(){
	getchar();
	printf("which user's account do you want to delete(Enter the Account Number)?");
	char an[5];
	int i,j, andis ; 
	scanf("%[^\n]s",an);
	getchar();
	for(i = 0 ; i < index ; i++){
		if(strcmp(an,db[i].account_number)==0){
			andis = i ;
		}
	}
	for(i = andis ; i < index ; i++){
		strcpy(db[i].account_number,db[i+1].account_number);
		db[i].balance = db[i+1].balance;
		strcpy(db[i].lastname,db[i+1].lastname);
		strcpy(db[i].name,db[i+1].name);
		for(j = 0 ; j<5 ; j++){
		db[i].recent[j] = db[i+1].recent[j];}
	}
	index--;
	printf("Succsess !\n");
	
}

void balance(char password[]){
	int i,j, andis ; 
	for(i = 0 ; i < index ; i++){
		if(strcmp(password,db[i].password)==0){
			andis = i ;
		}
	}
	printf("your balance is : %d\n",db[andis].balance);
	getchar();
}

void transfer(char password[]){
	int i , j , andis , andis2 ; 
	for(i = 0 ; i < index ; i++){
		if(strcmp(password,db[i].password)==0){
			andis = i ;
		}
	}
	char an[5];
	long int money ;
	printf("Enter the target account number :");
	scanf("%s",an);
	getchar();
	printf("Enter the amount of money you want to transfer:");
	scanf("%d",&money);
	for(i = 0 ; i < index ; i++){
		if(strcmp(an,db[i].account_number)==0){
			andis2 = i ;
		}
	}
	db[andis].balance-=money ;
	for(i = 0 ; i < 5 ; i++){
		if(db[andis].recent[i]==0){
			db[andis].recent[i]=(-money);
			break;
		}
		else if(i==4){
			for(j = 0 ; j < 5 ; j++){
				db[andis].recent[j]=db[andis].recent[j+1];
			}
			db[andis].recent[4]=(-money);
		}
	}
	db[andis2].balance+=money ;
	for(i = 0 ; i < 5 ; i++){
		if(db[andis2].recent[i]==0){
			db[andis2].recent[i]=money;
			break;
		}
		else if(i==4){
			for(j = 0 ; j < 5 ; j++){
				db[andis2].recent[j]=db[andis].recent[j+1];
			}
			db[andis2].recent[4]=money;
		}
	}
	printf("Success!\n");
	getchar();
}
void withdrawal(char password[]){
	int i,j, andis ; 
	for(i = 0 ; i < index ; i++){
		if(strcmp(password,db[i].password)==0){
			andis = i ;
		}
	}
	printf("Enter the amount of money you'd like to cash out :",db[andis].balance);
	long int money ;
	scanf("%d",&money);
	db[andis].balance-=money ;
	for(i = 0 ; i < 5 ; i++){
		if(db[andis].recent[i]==0){
			db[andis].recent[i]=(-money);
			break;
		}
		else if(i==4){
			for(j = 0 ; j < 5 ; j++){
				db[andis].recent[j]=db[andis].recent[j+1];
			}
			db[andis].recent[4]=(-money);
		}
	}
	printf("Success!\n");
	getchar();
}
void rau(char password[]){
	int i,j, andis ; 
	for(i = 0 ; i < index ; i++){
		if(strcmp(password,db[i].password)==0){
			andis = i ;
		}
	}
	for(i = 0 ; i < 5 ; i++)
		printf("%d : %d\n",i+1,db[andis].recent[i]);
	getchar();
}
void changepass(char password[]){
	int i,j, andis ; 
	for(i = 0 ; i < index ; i++){
		if(strcmp(password,db[i].password)==0){
			andis = i ;
		}
	}
	printf("Enter the new password",db[andis].balance);
	char pass[5] ; scanf("%s",pass);
	strcpy(db[andis].password,pass);
	printf("Success !\n");
	getchar();
}
 
