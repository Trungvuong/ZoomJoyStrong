/**********************************************************************
* This program is going to be the beginning of our new created 
* language known as ZoomJoyStrong. This is the lexer we are creating 
* to create our language.
*
* @author Trungvuong Pham
* @date October 28, 2018
**********************************************************************/
%{
    #include <stdio.h>
    #include "zoomjoystrong.tab.h"
%}

%option noyywrap

%%

(end)			{ return END;}  
;			{ return END_STATEMENT;}  
(point)			{ return POINT;}
(line) 			{ return LINE;}
(circle)		{ return CIRCLE;}
(rectangle)		{ return RECTANGLE;}
(set_color)		{ return SET_COLOR;}
[0-9]+			{ yylval.i=atoi(yytext); return INT;}
[0-9]+\.[0-9]+		{ yylval.f=atof(yytext); return FLOAT;}
[\n \t \ ]+		;
.			{ return ERROR;}		

%%

