#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


// Function returns one of the 128 printable ASCII characters which includes all the
// required characters needed to increment the state variable from 0 to 9.

char inputChar()
{
    int charInt = (rand() % 96)+32;
    return (char) charInt;

}

// Function randomly selects one of the 5 ASCII characters (r,e,s,t, and the end of string marker)
// forms a 6 digit string which it returns. Assuming the 6 digit string is "reset\0 then the main routine
// will end.

char *inputString()
{
    static char inString[6];

    for (int i=0; i<6; i++) {
        int charInt = rand() % 5;
        if (charInt != 0) {
            if (charInt == 1) {
                charInt = 114;
            } else if (charInt == 2) {
                charInt = 101;
            } else if (charInt == 3) {
                charInt = 115;
            } else if (charInt == 4) {
                charInt = 116;
            }
        }

/*        for (int i=0; i<6; i++) {
            int charInt = rand() % 27;
            if (charInt != 0) {
                charInt += 96;
           }
 */
        inString[i] = (char) charInt;
    }


    printf("String = %s\n", inString);

    return inString;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();

    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
