#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

bool is_equal(char [], char []);
void get_second_string(char [], int );
int getrandom(int );
int verify_character(char , char []);
int verify_repeat(char , char []);
void get_category(char [], char []);
void get_chocolate(char []);
void get_cricketer(char []);
void get_car(char []);
void get_c_word(char []);
void get_cartoon(char []);
void get_place(char []);

int main() {

	char s1[50] = "";
	char s2[100] = "";
	char s3[100] = "";
	char s4[5];
	char s5[40] = "";

	int n, i, l = 7,t = 0;

	char ch;
	int count = 0;

	get_category(s5, s1);

	n = strlen(s1);

	printf("\t-----------\t\t\t\n");
	printf("I am a %s....guess who am I? \n", s5);
	printf("\t-----------\t\t\t\n");

	get_second_string(s2, n);

	printf("%s\n", s2);

	while ((l != 0) && (!(is_equal(s1, s2)))) {

		if (count == 0) {
			printf("enter an alphabet:\n");
		}
		else {
			printf("enter an alphabet other than %s\b:\n", s3);
		}

		scanf(" %c", &ch);

		if (verify_character(ch, s3)  ==  0) {
			printf("please enter an alphabet\n");
		}
		else if (verify_character(ch, s3)  ==  1) {
			printf("please enter the alphabet in lower case\n");
		}
		else if (verify_character(ch, s3)  ==  -1) {
			printf("you have already entered the alphabet %c\n please", ch);
		}
		else {
			s4[0] = ch;
			s4[1] = ',';
			s4[2] = '\0';
			strcat(s3, s4);
			t = 0;
			for (i = 0; i < n;  i++) {
				if (s1[i] == ch)  {
					t++;
					s2[2 * i] = ch;
				}
			}
			printf("%s\n", s2);
			if (t == 0) {
				l--;
			}
			if ((l != 0) && (!(is_equal(s1, s2)))) {
				printf("you have %d chances left\n", l);
			}
			count++;
		}

	}

	if (l == 0) {
		printf("Oh! you lost the game.. play again.. \n");
		printf("The answer is %s\n", s1);
	}
	else {
		printf("Bravo!you won the game\n");
	}

}

bool is_equal(char s1[], char s2[]) {
    int k = 0, n, j;
    n = strlen(s1);
    for(j = 0; j < n; j++) {
        if(s1[j] != s2[j * 2]) {
            k = 1;
            break;
        }
    }
    if(k == 1) {
        return false;
    } else {
        return true;
    }
}

void get_second_string(char s2[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        strcat(s2,"_ \0");
    }
}

int verify_character(char ch,  char s3[]) {
	int l;
	l = strlen(s3);
	if (!(isalpha(ch))) {
		return 0;
	} else if (!(islower(ch))) {
		return 1;
	} else if (verify_repeat(ch,s3) == 1) {
		return -1;
	}
    else {
			return 2;
    }
}

int verify_repeat(char ch,  char s3[]) {
	int j,  l;
	l = strlen(s3);
	for (j = 0; j < l;  j++) {
		if (s3[j] == ch) {
			return 1;
		}
	}
}

int getrandom(int n) {
    static bool flag = true;
    if(flag) {
        srand(time(NULL));
        flag = false;
    }
    return rand() % n;
}

void get_category(char s5[], char s1[]) {
	int k;
	k = getrandom(6);
	switch(k) {
		case 0: strcpy(s5, "chocolate");
                get_chocolate(s1);
                break;
		case 1: strcpy(s5, "Indian cricketer");
                get_cricketer(s1);
                break;
        case 2: strcpy(s5, "car company");
                get_car(s1);
                break;
		case 3: strcpy(s5, "C technical word");
                get_c_word(s1);
                break;
	    case 4: strcpy(s5, "Historical Monument of India");
                get_place(s1);
                break;
	  default : strcpy(s5, "cartoon character");
                get_cartoon(s1);
	}
}

void get_chocolate(char s1[]) {
    int i;
    i = getrandom(10);
    switch(i)
    {
        case 0 : strcpy(s1, "dairymilk");
                 break;
        case 1 : strcpy(s1, "bournville");
                 break;
        case 2 : strcpy(s1, "barone");
                 break;
        case 3 : strcpy(s1, "gonemad");
                 break;
        case 4 : strcpy(s1, "butterfinger");
                 break;
        case 5 : strcpy(s1, "snickers");
                 break;
        case 6 : strcpy(s1, "munch");
                 break;
        case 7 : strcpy(s1, "kitkat");
                 break;
        case 8 : strcpy(s1, "perk");
                 break;
        case 9 : strcpy(s1, "fivestar");
                 break;
        default: strcpy(s1,"milkybar");
    }
}

void get_cricketer(char s1[]) {
	int k;
	k = getrandom(6);
	switch (k)  {
		case 0: strcpy(s1, "viratkohli");
                break;
		case 1: strcpy(s1, "rahuldravid");
                break;
		case 2: strcpy(s1, "sachin");
                break;
		case 3: strcpy(s1, "ganguly");
                break;
		case 4: strcpy(s1, "sehwag");
                break;
       default: strcpy(s1, "dhoni");
     }
  }

 void get_car(char s1[]) {
 	int k;
 	k = getrandom(7);
 	switch (k)  {
		case 0: strcpy(s1, "buggati");
                break;
		case 1: strcpy(s1, "ferrari");
                break;
		case 2: strcpy(s1, "chevrolet");
                break;
		case 3: strcpy(s1, "jaguar");
                break;
		case 4: strcpy(s1, "hyundai");
                break;
        case 5: strcpy(s1, "renault");
                break;
       default: strcpy(s1, "volkswagen");

     }
  }

  void get_c_word(char s1[]) {
 	int k;
 	k = getrandom(10);
 	switch (k)  {
		case 0: strcpy(s1, "operator");
                break;
		case 1: strcpy(s1, "structure");
                break;
		case 2: strcpy(s1, "delimiter");
                break;
		case 3: strcpy(s1, "keyword");
                break;
		case 4: strcpy(s1, "headerfile");
                break;
        case 5: strcpy(s1, "pointer");
                break;
        case 6: strcpy(s1, "recursion");
                break;
        case 7: strcpy(s1, "stream");
                break;
        case 8: strcpy(s1, "union");
                break;
       default: strcpy(s1, "identifier");

     }
  }

  void get_cartoon(char s1[]) {
 	int k;
 	k = getrandom(9);
 	switch (k)  {
		case 0: strcpy(s1, "mickeymouse");
                break;
		case 1: strcpy(s1, "popeye");
                break;
		case 2: strcpy(s1, "doreamon");
                break;
		case 3: strcpy(s1, "jerry");
                break;
		case 4: strcpy(s1, "donaldduck");
                break;
        case 5: strcpy(s1, "chotabheem");
                break;
        case 6: strcpy(s1, "pluto");
                break;
        case 7: strcpy(s1, "hattori");
                break;
       default: strcpy(s1, "spongebob");
     }
  }

  void get_place(char s1[]) {
 	int k;
 	k = getrandom(7);
 	switch (k)  {
		case 0: strcpy(s1, "tajmahal");
                break;
		case 1: strcpy(s1, "redfort");
                break;
		case 2: strcpy(s1, "charminar");
                break;
		case 3: strcpy(s1, "gatewayofindia");
                break;
		case 4: strcpy(s1, "qutubminar");
                break;
        case 5: strcpy(s1,"mysorepalace");
                break;
       default: strcpy(s1, "ajantacaves");
     }
  }
