/**********************************************************************
* This is the bison file used for the ZoomJoyStrong language we are 
* creating for our project.
* 
* @author Trung-Vuong Pham
* @date November 19, 2018
**********************************************************************/

%{
	#include <stdio.h>
	#include <string.h>
	#include "zoomjoystrong.h"
	void yyerror(const char* s);
	int yylex();
%}

%error-verbose
%start statement_list

%union {int i; double f;}

/** Definitions and declarations of tokens from the flex file **/
%token END
%token END_STATEMENT
%token POINT
%token LINE
%token CIRCLE
%token RECTANGLE
%token SET_COLOR
%token <i> INT
%token <f> FLOAT
%token ERROR

%%

/** The grammar rules that I established for the language **/
statement_list:		statement END
	 |		statement statement_list
;

statement:	point
	 |	line
	 |	circle	
	 |	rectangle		 
	 |	set_color
	 |      end

point: POINT INT INT END_STATEMENT { point($2, $3);};

line: LINE INT INT INT INT END_STATEMENT { line($2, $3, $4, $5);};

circle: CIRCLE INT INT INT END_STATEMENT { circle($2, $3, $4);};

rectangle: RECTANGLE INT INT INT INT END_STATEMENT 
	 { rectangle($2, $3, $4, $5);};

set_color: SET_COLOR INT INT INT END_STATEMENT { set_color($2, $3, $4);};

end: END END_STATEMENT {finish(); exit(1);};
%%

/**********************************************************************
* The main method which invokes the yyparse() function.
*
* @param argc Size of argv
* @param argv Aaray of strings for command line
* @return 0 Program ends correctly
**********************************************************************/
int main(int argc, char** argv){
	setup();
	printf("Welcome to ZoomJoyStrong\n");
	yyparse();
	return 0;
}

/**********************************************************************
* This method prints out any error messages that can occur if a token 
* is not defined in our language. Should print what token is incorrect 
* and restart the parser.
*
* @param s The error message returned
**********************************************************************/
void yyerror(const char* s){
	fprintf(stderr, "ERROR! %s\n", s);
	yyparse();
}
