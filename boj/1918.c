#include <stdio.h>
#include <stdlib.h>

/*
rule 0	S -> E
rule 1	E -> T + E
rule 2	E -> T
rule 3	T -> id
rule 4	T -> id * T
rule 5	T -> ( E )
*/

/*
state		+	id	*	(	)	$	S	E	T

0				s3		s4				1	2
1								acc			
2			s5				r2	r2			
3			r3		s6		r3	r3			
4				s3		s4				7	2
5				s3		s4				8	2
6				s3		s4					9
7							s10				
8							r1	r1			
9			r4				r4	r4			
10			r5				r5	r5			
*/

typedef enum {
  ID = 1,
  PLUS = 1 << 1,
  MINUS = 1 << 2,
  MULTI = 1 << 3,
  DIV = 1 << 4,
  LPAREN = 1 << 5,
  RPAREN = 1 << 6
} nodeType;

typedef struct node {
  struct node* left;
  struct node* right;
  nodeType type;
  char data;
} node;

nodeType getType(char c) {
  switch (c) {
    case ('+'):
      return (PLUS);
    case ('-'):
      return (MINUS);
    case ('*'):
      return (MULTI);
    case ('/'):
      return (DIV);
    case ('('):
      return (LPAREN);
    case (')'):
      return (RPAREN);
    default:
      return (ID);
  }
}

char ans[101];
int idx;

void postOrder(node* ast) {
  if (!ast)
    return;
  postOrder(ast->left);
  postOrder(ast->right);
  ans[idx++] = ast->data;
}

int main(void) {
  char input[101];
  scanf("%s", input);

  node* ast = parse(input);
  postOrder(ast);

  ans[idx] = '\0';
  printf("%s\n", ans);
  return (0);
}
