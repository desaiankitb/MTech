%{
#include <stdio.h>


extern char yytext[];
extern int column;

struct node {
	int value;
	int type;//0  Reg //1 if //2 For 3 while //4 Function 
	int group;
	struct node *next;
};
/*------------------- globals ------------------------*/
struct node n[10000];
struct node  head = {99999, 0,0,'\0'};
int node_count=0;
int group_count=-1;
int curr_count=-1;
int type_spec=-1;
void traverse(struct node *h)
{
	struct node *p = h;
	FILE *fd;
	fd = fopen("graph.txt","w+");
	while(p->next != NULL){
		fprintf(fd,"%d %d %d\n", p->value,p->type,p->group);
		p = p->next;
	}
	printf("[%d-%d-%d]->", p->value,p->type,p->group);
	fprintf(fd,"%d %d %d\n", p->value,p->type,p->group);

   	close(fd);
}

/*-------------------- add_node ----------------------*/
/*
  pre-condition: a head node with a list and an incoming node.
  post-condition: a list with added node.
  action: add node to list.
  returns: pointer to added node.
*/
struct node * add_node(struct node *h, struct node *n,int type,int cc)
{
	struct node p = *h, *pp = &p;
	
	n->next = NULL;
	if(h->next == '\0'){	
		h->next = n; /* take care of empty list  */		
		n->type = type;
		n->group = cc;
		return n;
	}
	while(pp->next != '\0'){
		pp = pp->next;     /* step to end of the list */
	}
	pp->next = n;
	n->type = type;
	n->group = cc;
	return n;
}

%}

%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%%

primary_expression
	: IDENTIFIER
	| CONSTANT
	| STRING_LITERAL
	| '(' expression ')'		
	;

postfix_expression
	: primary_expression	
	| postfix_expression '[' expression ']'
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			if(type_spec==2)
			{			
			add_node( &head, &n[node_count] ,0,curr_count+1);
			}
			else if (type_spec==3)
			{			
			add_node( &head, &n[node_count] ,0,curr_count);
			}
			else
			{
			add_node( &head, &n[node_count] ,0, curr_count);
			}				
			traverse(&head);
		}
	| postfix_expression DEC_OP
		{
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			if(type_spec==2)
			{			
			add_node( &head, &n[node_count] ,0,curr_count+1);
			}
			else if (type_spec==3)
			{			
			add_node( &head, &n[node_count] ,0,curr_count);
			}
			else
			{
			add_node( &head, &n[node_count] ,0, curr_count);
			}				
			traverse(&head);

		}
	;

argument_expression_list
	: assignment_expression
	| argument_expression_list ',' assignment_expression
	;

unary_expression
	: postfix_expression
	| INC_OP unary_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			if(type_spec==2)
			{			
			add_node( &head, &n[node_count] ,0,curr_count+1);
			}
			else if (type_spec==3)
			{			
			add_node( &head, &n[node_count] ,0,curr_count);
			}
			else
			{
			add_node( &head, &n[node_count] ,0, curr_count);
			}				
			traverse(&head);

		}
	| DEC_OP unary_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			if(type_spec==2)
			{			
			add_node( &head, &n[node_count] ,0,curr_count+1);
			}
			else if (type_spec==3)
			{			
			add_node( &head, &n[node_count] ,0,curr_count);
			}
			else
			{
			add_node( &head, &n[node_count] ,0, curr_count);
			}				
			traverse(&head);
		}
	| unary_operator cast_expression
	| SIZEOF unary_expression
	| SIZEOF '(' type_name ')'
	
	;

unary_operator
	: '&' 
	| '*'
	| '+'
	| '-'
	| '~'
	| '!'
	;

cast_expression
	: unary_expression
	| '(' type_name ')' cast_expression
	;

multiplicative_expression
	: cast_expression
	| multiplicative_expression '*' cast_expression
	| multiplicative_expression '/' cast_expression
	| multiplicative_expression '%' cast_expression
	;

additive_expression
	: multiplicative_expression
	| additive_expression '+' multiplicative_expression
	| additive_expression '-' multiplicative_expression
	;

shift_expression
	: additive_expression	
	| shift_expression LEFT_OP additive_expression
	| shift_expression RIGHT_OP additive_expression
	;

relational_expression
	: shift_expression
	| relational_expression '<' shift_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	| relational_expression '>' shift_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	| relational_expression LE_OP shift_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	| relational_expression GE_OP shift_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	;

equality_expression
	: relational_expression
	| equality_expression EQ_OP relational_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	| equality_expression NE_OP relational_expression
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],type_spec,curr_count );
			traverse(&head);
		}
	;

and_expression
	: equality_expression
	| and_expression '&' equality_expression
	;

exclusive_or_expression
	: and_expression
	| exclusive_or_expression '^' and_expression
	;

inclusive_or_expression
	: exclusive_or_expression
	| inclusive_or_expression '|' exclusive_or_expression
	;

logical_and_expression
	: inclusive_or_expression
	| logical_and_expression AND_OP inclusive_or_expression
	;

logical_or_expression
	: logical_and_expression
	| logical_or_expression OR_OP logical_and_expression
	;

conditional_expression
	: logical_or_expression
	| logical_or_expression '?' expression ':' conditional_expression
	;

assignment_expression
	: conditional_expression
	| unary_expression assignment_operator assignment_expression	
		{ 
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;			
			add_node( &head, &n[node_count],0 ,curr_count);
			traverse(&head);
		}
	;

assignment_operator
	: '='	
	| MUL_ASSIGN
	| DIV_ASSIGN
	| MOD_ASSIGN
	| ADD_ASSIGN
	| SUB_ASSIGN
	| LEFT_ASSIGN
	| RIGHT_ASSIGN
	| AND_ASSIGN
	| XOR_ASSIGN
	| OR_ASSIGN
	;

expression
	: assignment_expression
		/*{
			node_count++;
			n[node_count].value = node_count;
			n[node_count].next = NULL;						
			add_node( &head, &n[node_count] );
			traverse(&head);
		}*/
	| expression ',' assignment_expression
	;

constant_expression
	: conditional_expression
	;

declaration
	: declaration_specifiers ';'
	| declaration_specifiers init_declarator_list ';'
	;

declaration_specifiers
	: storage_class_specifier
	| storage_class_specifier declaration_specifiers
	| type_specifier 					
	| type_specifier declaration_specifiers
	| type_qualifier
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator
	| init_declarator_list ',' init_declarator
	;

init_declarator
	: declarator
	| declarator '=' initializer
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID
	| CHAR
	| SHORT
	| INT
	| LONG
	| FLOAT
	| DOUBLE
	| SIGNED
	| UNSIGNED
	| struct_or_union_specifier
	| enum_specifier
	| TYPE_NAME
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT
	| UNION
	;

struct_declaration_list
	: struct_declaration
	| struct_declaration_list struct_declaration
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	| type_specifier
	| type_qualifier specifier_qualifier_list
	| type_qualifier
	;

struct_declarator_list
	: struct_declarator
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}'
	| ENUM IDENTIFIER '{' enumerator_list '}'
	| ENUM IDENTIFIER
	;

enumerator_list
	: enumerator
	| enumerator_list ',' enumerator
	;

enumerator
	: IDENTIFIER
	| IDENTIFIER '=' constant_expression
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator
	| direct_declarator
	;

direct_declarator
	: IDENTIFIER
	| '(' declarator ')'
	| direct_declarator '[' constant_expression ']'
	| direct_declarator '[' ']'
	| direct_declarator '(' parameter_type_list ')'
	| direct_declarator '(' identifier_list ')'
	| direct_declarator '(' ')'
	;

pointer
	: '*'
	| '*' type_qualifier_list
	| '*' pointer
	| '*' type_qualifier_list pointer
	;

type_qualifier_list
	: type_qualifier
	| type_qualifier_list type_qualifier
	;


parameter_type_list
	: parameter_list
	| parameter_list ',' ELLIPSIS
	;

parameter_list
	: parameter_declaration
	| parameter_list ',' parameter_declaration
	;

parameter_declaration
	: declaration_specifiers declarator
	| declaration_specifiers abstract_declarator
	| declaration_specifiers
	;

identifier_list
	: IDENTIFIER
	| identifier_list ',' IDENTIFIER
	;

type_name
	: specifier_qualifier_list
	| specifier_qualifier_list abstract_declarator
	;

abstract_declarator
	: pointer
	| direct_abstract_declarator
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	| '[' ']'
	| '[' constant_expression ']'
	| direct_abstract_declarator '[' ']'
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression
	| '{' initializer_list '}'
	| '{' initializer_list ',' '}'
	;

initializer_list
	: initializer
	| initializer_list ',' initializer
	;

statement
	: labeled_statement
	| compound_statement		
	| expression_statement		
	| selection_statement		
	| iteration_statement		
	| jump_statement		
	;

labeled_statement
	: IDENTIFIER ':' statement
	| CASE constant_expression ':' statement
	| DEFAULT ':' statement
	;

compound_statement
	: '{' '}'
	| '{' statement_list '}'
	| '{' declaration_list '}'
	| '{' declaration_list statement_list '}'
	;

declaration_list
	: declaration
	| declaration_list declaration
	;

statement_list
	: statement		
	| statement_list statement
	;

expression_statement
	: ';' 
	| expression ';'
	;

selection_statement
	: IF '(' expression ')' statement 	 
	| IF '(' expression ')' statement ELSE statement
	| SWITCH '(' expression ')' statement 			
	;

iteration_statement
	: WHILE '(' expression ')' statement
	| DO statement WHILE '(' expression ')' ';'
	| FOR '(' expression_statement expression_statement ')' statement
	| FOR '(' expression_statement expression_statement expression ')' statement
	;

jump_statement
	: GOTO IDENTIFIER ';'
	| CONTINUE ';'
	| BREAK ';'
	| RETURN ';'
	| RETURN expression ';'
	;

translation_unit
	: external_declaration
	| translation_unit external_declaration
	;

external_declaration
	: function_definition
	| declaration		
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement		
	| declaration_specifiers declarator compound_statement
	| declarator declaration_list compound_statement
	| declarator compound_statement
	;


%%
yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
printlinkedlisttofile()
{
  
}
int main(void) {
    yyparse();
    printlinkedlisttofile();
    return 0;
}


