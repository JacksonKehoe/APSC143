//Jackson Kehoe, 20105920, 17jpk3
//Hussan Asim, 20115592, 17ah79

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 100 //Take 100 usernames
#define MAXLEN 20 // Max username and password length

// Function declarations
int readDatabase(char *usrDB[], int pswrdDB[]);
char *getUsername();
char *getPassword();
int searchUsername(char *username, char *usernameDB[], int size);
int attemptLogin(int passwordDB[], int idx);
int hashPassword(char *password);

int main(int argc, char **argv)
{
	char *usernameDB[NUM];		// Array of pointers to strings. Will read usernames from file into this array
	int passwordDB[NUM];		// Array of ints. Will read password hashes from file into this array.
	int numUsers;				// The number of users.
	char response[MAXLEN] = {};	// Generic array for user input.
	
	// Read in username and password
	// YOUR CODE GOES HERE
	numUsers = readDatabase(usernameDB, passwordDB);
	
	// Infinite loop
	while(1){
		int usrIdx;			// Index of target username
		int loginStatus;	// Indicates whether passwords match
		char *username;		// User specified username
		int password;		// User specified password
		
		do {
			username = getUsername();
			usrIdx = searchUsername(username, usernameDB, numUsers);
			
			if (usrIdx == -1) { 
				printf("Username not found.\n");
			} 
		} while (usrIdx == -1);
		
		do {
			loginStatus = attemptLogin(passwordDB, usrIdx);
			if (loginStatus == 0)
				printf("Password does not match.\n");
		} while (loginStatus == 0);
		
		printf("Logged in.\n");
		printf("Press enter to log out.");
		fgets(response, MAXLEN, stdin);
		printf("Logged out.\n\n");
		
		printf("Log in to another account? (Y/N)");
		fgets(response, MAXLEN, stdin);
		if((response[0] == 'N') || (response[0] == 'n'))
			break;
	}
	
	return 0;
}

// Function definitions

int readDatabase(char *usrDB[], int pswrdDB[]){
    int numUsers = 0, numPasswords = 0;
    char userBuffer[MAXLEN];
    
    FILE *usrFP = fopen("../usernames.txt", "r");
    // Pointers to user list file
	//checks if file opens
    if (usrFP == NULL){
        printf("could not open username file\n"); exit(1);
    }
    while(fgets(userBuffer, MAXLEN, usrFP)){
    // Add new user...
        int len = strlen(userBuffer);
		strtok(userBuffer, "\n");
        usrDB[numUsers] = (char *)malloc(sizeof(char)*(len));
        strcpy(usrDB[numUsers++], userBuffer); 
    // remove the new line from the end of the buffer // use malloc to get memory to store the username // use strcpy to copy the memory
    } fclose(usrFP);
    //opens passwords file and makes sure there are no erros
    FILE *pswrdFP = fopen("../passwords.txt", "r"); 
    if (pswrdFP == NULL){
        printf("could not open password file\n");
        exit(1); 
    }
	
    while(fgets(userBuffer, MAXLEN, usrFP)){
    // Add new password
		pswrdDB[numPasswords++] = atoi(userBuffer);
    // only have to read a number, use fscanf
    }
    fclose(pswrdFP);
    //makes sure passwords and usernames match
    if (numUsers != numPasswords)
        printf("Number of usernames and passwords dont match\n");
        
    return numUsers;
}

char *getUsername(){
	printf("Enter the username: ");
	char buffer[MAXLEN];
	fgets(buffer, MAXLEN, stdin);
	int len = strlen(buffer);
	strtok(buffer, "\n");
	char *username = (char *)malloc(sizeof(char)*(len));
	strcpy(username, buffer);
	
    return username;
}

char *getPassword(){
	printf("Enter the password: ");
	char buffer[MAXLEN];
	fgets(buffer, MAXLEN, stdin);
	int len = strlen(buffer);
	strtok(buffer, "\n");
	char *password = (char *)malloc(sizeof(char)*(len));
	strcpy(password, buffer);
	
    return password;
}

int searchUsername(char *username, char *usernameDB[], int size){
	for (int i = 0; i < size; i++) {
		// printf("%d ", strcmp(usernameDB[i], username));
		// printf("%s %s\n", username, usernameDB[i]);
		if (strcmp(usernameDB[i], username) == 0) {
			return i;
		}
	}
    return -1;
}

int attemptLogin(int passwordDB[], int idx){
	char *password = getPassword();
	int n = 4891;
	int hash = 0;
	for (int i = 0; i < strlen(password); i++) {
		hash = (int)password[i];
	}
	hash = hash * hash;
	hash = hash % n;
	//checks if password matches
	if (hash == passwordDB[idx])
		return 1;
	else
		return 0;
}


