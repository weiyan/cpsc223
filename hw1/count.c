#include <stdio.h>
#include <ctype.h>

main() {
  int lines = 0;
  int c;
  int next_char;

/*booleans*/
  int in_comment = 0;
  int in_string = 0;
  int has_code = 0;

  while ((c = getchar()) != EOF ) {
    next_char = 0;

/*  if we're inside of a comment, then we only need to watch out if
    the char we read signifies the end of the comment  */

    if (in_comment) {
      putchar(c);
      if (c == '*' && (next_char = getchar()) == '/' ){
        in_comment = 0;
      }
      putchar(next_char);
    }

/*  watch for the beginning of a comment, but only if we are not currently
    in a quote (string) */

    else if (!in_string && c == '/') {
      putchar(c);
      if ((next_char = getchar()) == '*') {
        in_comment = 1;
      }
      putchar(next_char);
    }    // at this point, we know we are not in a comment

/*  if we're inside of a string, then we need to watch for escape sequences
    specifically, print out the next char, since it must belong to the
    escape sequence and must not signify anything important, such as the
    end of the quote.  We must also watch for the end of the string.*/

    else if (in_string) {
      putchar(c);
      if (c == '\\') {
        putchar(getchar());
      }
      else if (c == '\"') {
        in_string = 0;
      }
    }

    else if (c == '\"') {
      putchar(c);
      in_string = 1;
      has_code = 1;
    }

/*  test for line splices.  If a backspace occurs, the next char, no matter
    what it is, cannot signify a new line of code  */

    else if (c == '\\') {
      putchar(c);
      next_char = getchar();
      putchar(next_char);
    }

/*  at this point, we know we are not in a comment or string, and there is
    no line splice, so any nonspace character we find is code */

    else if (!isspace(c)) {
      putchar(c);
      has_code = 1;
    }

/*  now, if c is a newline, and there is code, then count as a line */

    else if (c == '\n' && has_code) {
      lines++;
      printf(" /*%d*/\n", lines);
      has_code = 0;
    }

    else {
      putchar(c);
    }

  } // ends while

  return 1;

}

