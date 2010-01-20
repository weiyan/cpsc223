#include <stdio.h>
#include <ctype.h>

main() {
  int lines = 0;
  int c;

  int in_comment = 0;
  int in_string = 0;
  int has_code = 0;

/*read char
    print char
    if char == newline AND not a comment AND has code
      increment lines
      print lines
*/

  while ((c = getchar()) != EOF ) {
    int next_char = 0;

// problematic for last case

    putchar(c);

/*  if we're inside of a comment, then we only need to watch out if
    the char we read signifies the end of the comment  */

    if (in_comment) {
      if (c == '*' && (next_char = getchar()) == '/' ){
        in_comment = 0;
        putchar('/');
      }
    }

/*  watch for the beginning of a comment, but only if we are not currently
    in a quote (string) */

    else if (!in_string && c == '/' && (next_char = getchar()) == '*') {
      in_comment = 1;
      putchar('*');
    }    // at this point, we know we are not in a comment

/*  if we're inside of a string, then we need to watch for escape sequences
    specifically, print out the next char, since it must belong to the
    escape sequence and must not signify anything important, such as the
    end of the quote */

    else if (in_string) {
      if (c == '\\') {
        putchar(getchar());
      }
    }

    else if (c == '\"') {
      in_string = 1;
    }

/*  test for line splices*/

    else if (c == '\\' && (next_char = getchar()) == '\n' ) {
      putchar('\n');
    }

/*  at this point, we know we are not in a comment or string, and there is
    no line splice, so any nonspace character we find is code */

    else if (!isspace(c)) {
      has_code = 1;
    }

/*  now, if c is a newline, and there is code, then count as a line */

    else if (c == '\n' && has_code) {
      lines++;
      printf(" /*%d*/\n", lines);
      has_code = 0;
    }

// what if getchar() in the middle of while loop returns something unexpected?


  } // ends while

  return 1;

}

