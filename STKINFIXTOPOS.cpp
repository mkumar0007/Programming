#include<bits/stdc++.h>
using namespace std;

struct stk
{
    unsigned capacity;
    int top;
    char *arr;
};

struct stk* create( unsigned capacity )
{
    struct stk* stack = (struct stk*) malloc(sizeof(struct stk));

    if (!stack)
        return NULL;

    stack->top = -1;
    stack->capacity = capacity;

    stack->arr = (char*) malloc(stack->capacity * sizeof(char));

    if (!stack->arr)
        return NULL;
    return stack;
}

bool isempty(struct stk* s)
{
    return s->top==-1;
}

char peek(struct stk* s)
{
    return s->arr[s->top];
}

void push(struct stk* s,char n)
{
        s->arr[++(s->top)]=n;
}

char pop(struct stk *stack)
{
      if (!isempty(stack))
        return stack->arr[stack->top--] ;
    return '$';

}

int prec(char ch)
{
    switch(ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    }
    return -1;
}

bool isop(char ch)
{
    return (ch>='a'&& ch<='z')|| (ch>='A' && ch<='Z');
}


int func(char* exp)
{
	int i, k;

	// Create a stack of capacity equal to expression size
	struct stk* stack = create(strlen(exp));
	if(!stack) // See if stack was created successfully
		return -1 ;

	for (i = 0, k = -1; exp[i]; ++i)
	{
		// If the scanned character is an operand, add it to output.
		if (isop(exp[i]))
			exp[++k] = exp[i];

		// If the scanned character is an ‘(‘, push it to the stack.
		else if (exp[i] == '(')
			push(stack, exp[i]);

		// If the scanned character is an ‘)’, pop and output from the stack
		// until an ‘(‘ is encountered.
		else if (exp[i] == ')')
		{
			while (!isempty(stack) && peek(stack) != '(')
				exp[++k] = pop(stack);
			if (!isempty(stack) && peek(stack) != '(')
				return -1; // invalid expression
			else
				pop(stack);
		}
		else // an operator is encountered
		{
			while (!isempty(stack) && prec(exp[i]) <= prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	// pop all the operators from the stack
	while (!isempty(stack))
		exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}

int main()
{
    ios_base::sync_with_stdio(false);
    char exp[] = "a+b*(c^d-e)^(f+g*h)-i";
    func(exp);
    return 0;
}
