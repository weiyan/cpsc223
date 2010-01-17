#include <stdio.h>
#include <ctype.h>

main() {
  int lines = 0;
  int c;

  int in_comment = 0;
  int in_string = 0;
  int is_code = 0;

/*read char
    if it == \n
      lines ++;
      replace with necessary things
    print char */

  while ((c = getchar()) != EOF ) {

    if (in_string) {
      if (c == '\"') {
        in_string = 0;
      }
      putchar(c);
    }
    else if (c == '\"') {
      in_string = 1;
      putchar(c);
    }

    // must not be inside of a string

    /* handles comments */
    else if (in_comment == 1) {
      if ((c == '*') && (getchar() == '/')) {
        in_comment = 0;
        putchar(' ');
      }
    }
    else if ((c == '/') && (getchar() == '*')) {
      in_comment = 1;
    }

    // must not be inside of a comment

    // if not a space
    else if (!isspace(c)) {
      is_code = 1;
      putchar(c);
    }

    //tests for line splices

    else if ((c == '\\') && (getchar() == '\n')) {
      putchar('\\');
      putchar('\n');
    }

    //increments number of lines

    else if (c == '\n') {
      if (is_code) {
        lines ++;
      }
      printf(" /*%d*/\n", lines);
    }

    //in all other cases, just copy the character to standard output

    else {
      putchar(c);
    }


  } // ends while
}

