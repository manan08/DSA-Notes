#include<iostream>
#include<cstring>
using namespace std;
/*
Whenever some input is given by console the data enters the input buufer only when Enter gets hit
and some code gets executed for the input buffer

	[hello world] + enter -> |h|e|l|l| |w|o|r|l|d|
	                      cin ^
	   input		             input buffer
	   -----				     ------------
	(cin starts from 'h' and when it reaches the white space it leaves the input buffer, so only
	the hello is stored in the character array)


-> cin function takes input but stops taking input as soon as a new line character or a white space is
encoutered
so this creates a problem for taking input for a sentence which contains white spaces
for this we can use
1. cin.get() - this takes input of a single character and can read any type of character
and will terminate on users condition if used
inside a loop.
								char word = cin.get();
								while(word != '\n'){
									word = cin.get();
								}
in above loop youc an pass a character of your wish for loop to terminate but when you enter a new
line character in input then the each input seperated by a new line character will enter input buffer
and code will be executed for that
*/

/*
Counting number of Digits, Spaces and Alphabets in character array

// taking input of first character
	char word = cin.get();

	int digits = 0;
	int spaces = 0;
	int alphabets = 0;


	while (word != '\n') {
		// for numbers
		if (word >= '0' and word <= '9')
			digits++;

		// for alphabets
		else if (word >= 'a' and word <= 'z' or word >= 'A' and word <= 'Z')
			alphabets++;

		// for spaces
		else if (word == ' ')
			spaces++;

		// new word input
		word = cin.get();
	}

	cout << "Digits: " << digits << endl;
	cout << "Alphabets: " << alphabets << endl;
	cout << "Spaces: " << spaces << endl;
*/

/*
cin.getline() :-

Using cin.getline() instead of cin.get is an advantage because it can read a whole line at once as well
as store it in the character array.
			cin.getline(name_of_character_array, sizeof_chracter_array, input_stopping_parameter)

-> this function automatically adds a null charatcer at the end of the string by replacing it with a new
line character

-> while taking input using cin.get() you need an extra check condition that does the number of charaters
exceed the size of character array or not because if it exceeds it might lead to a segmentation fault
and to avoid that segmentation fault that condition must exit from the loop and stop taking input

-> whereas in cin.getline() function we pass the size of character array and it automatically terminates
after taking size - 1 character as input and adds a null charatcer at the end.

-> the input stopping parameter is set as new line character ('\n') as default, this can further be passed
as per the user need to which character the input buffer should be read

for example : cin.getline(line, 10, '.');
			  this fucntion will take input upto 9 characters or will stop taking input if it encounters a '.'
*/


/*
cstring functions :-

	1. strcpy(destination, source);
	   this function copies the source string into the destination string in linear time
	   for ex - char a[1000] = "manan";
	   			char b[1000];
	   			strcpy(b, a);
	   			cout << b;    -> manan

	2. strcat(a,b);
	   this function cancatenates two cstrings
	   for ex - char a[100] = "manan";
	   			char b[100] = "sharma";
	   			char c[100];
	   			strcpy(c, strcat(a, b));   //  a + b -> "manan" + "sharma"
	   			cout << c;   -> manansharma

	3. strlen(a);
	   this function returns the length or we can say number of characters present in the character
	   array but this does not includes the null character.
	   for ex - char a[] = "manan";
	   			strlen(a)   ->   5
	   			sizeof(a)   ->   6   (including the null character space)

*/


/*
Consider a case where you want to take input of string for N times inside a loop
				N
				string 1
				string 2
				.
				.
				string n
In this case you will take input of n then run a loop N times to take input of string sentences using
cin.getline()
So yes you are taking input of n strings but the nth string will not be taken as input beacuse after
n there is a new line character.
And as we know that cin.getline() will take input till it encounters a new line character, so in this case
an empty string will be stored inside the character array in the first iteration.

Input buffer :-   | N | \n | Stirng 1 | \n | Stirng 2 | \n | String N | \n |
						 ^               ^               ^   			 ^
So now we want the first new line character to be ignored:
1. You can input that new line charatcer in a temporary character variable using cin.get() and then
   cin.getline() will operate from next line.
2. You can use a function cin.ignore() to ignore the extra new line character and switch to next line for
   input as it flushes the buffer.


*/
int main() {
	char line[100];
	char word = cin.get();
	line[0] = word;
	int len = 1;
	while (word != '\n') {
		word = cin.get();
		line[len++] = word;
	}
	line[len - 1] = '\0';
	cout << line << "\nLength: " << strlen(line);
	cout << "\nSize: " << sizeof(line);

}