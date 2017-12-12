%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "parser.tab.h"

 extern FILE *spFile;

/*
#define true 1
#define false 0

#define   AND      1
#define   ARRAY      2
#define   CASE      3
#define   CONST      4
#define   DIV      5
#define   DO      6
#define   DOWNTO      7
#define   ELSE      8
#define   END      9

#define   EXTERNAL      10
#define   FOR      11
#define   FORWARD      12
#define   FUNCTION      13
#define   GOTO      14
#define   IF      15
#define   IN      16
#define   LABEL      17
#define   MOD      18
#define   NIL      19
#define   NOT      20
#define   OF       21
#define   OR      22
#define   OTHERWISE      23
#define   PACKED      24
#define   PBEGIN      25
#define   PFILE      26
#define   PROCEDURE      27
#define   PROGRAM      28
#define   RECORD      29
#define   REPEAT      30
#define   SET      31
#define   THEN      32
#define   TO      33
#define   TYPE      34
#define   UNTIL      35
#define   VAR      36
#define   WHILE      37
#define   WITH      38
#define   IDENTIFIER      39

#define   ASSIGNMENT      40
#define   CHARACTER_STRING      41
#define   COLON      42
#define   COMMA      43
#define   DIGSEQ      44
#define   DOT      45
#define   DOTDOT      46
#define   EQUAL      47
#define   GE      48
#define   GT      49
#define   LBRAC      50
#define   LE      51
#define   LPAREN      52
#define   LT      53
#define   MINUS      54
#define   NOTEQUAL      55
#define   PLUS      56
#define   RBRAC      57
#define   REALNUMBER      58
#define   RPAREN      59
#define   SEMICOLON      60
#define   SLASH      61
#define   STAR      62
#define   STARSTAR      63

#define   notEQUAL    65



#define NUM 66
#define INTEGER 67
#define REAL 68
*/

#define COMMENT 100

int line_no = 1;


%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]
NQUOTE [^'^\n]

id_e [a-zA-Z_]([a-zA-Z0-9_])*
Digit	[0-9]
exp		E[+-]?({i}|{i}\.{i}|{i}?\.{i}|id)
unsigned_int {Digit}+
integer	 {Digit}+
i {unsigned_int}
real    ({i}\.{i}|{i}?\.{i}){exp}?


%%

{A}{N}{D}                    {fprintf( spFile, "Shift AND\n"); return(AND);}
{A}{R}{R}{A}{Y}              {fprintf( spFile, "Shift ARRAY\n"); return(ARRAY);}
{C}{A}{S}{E}                 {fprintf( spFile, "Shift CASE\n"); return(CASE);}
{C}{O}{N}{S}{T}              {fprintf( spFile, "Shift CONST\n"); return(CONST);}
{D}{I}{V}                    {fprintf( spFile, "Shift DIV\n"); return(DIV);}
{D}{O}                       {fprintf( spFile, "Shift DO\n"); return(DO);}
{D}{O}{W}{N}{T}{O}           {fprintf( spFile, "Shift DOWNTO\n"); return(DOWNTO);}
{E}{L}{S}{E}                 {fprintf( spFile, "Shift ELSE\n"); return(ELSE);}
{E}{N}{D}                    {fprintf( spFile, "Shift END\n"); return(END);}
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L}     {fprintf( spFile, "Shift EXTERNAL\n"); return(EXTERNAL);}

{F}{O}{R}                    {fprintf( spFile, "Shift FOR\n"); return(FOR);}
{F}{O}{R}{W}{A}{R}{D}        {fprintf( spFile, "Shift FORWARD\n"); return(FORWARD);}
{F}{U}{N}{C}{T}{I}{O}{N}     {fprintf( spFile, "Shift FUNCTION\n"); return(FUNCTION);}
{G}{O}{T}{O}                 {fprintf( spFile, "Shift GOTO\n"); return(GOTO);}
{I}{F}                       {fprintf( spFile, "Shift IF\n"); return(IF);}
{I}{N}                       {fprintf( spFile, "Shift IF\n"); return(IN);}


{I}{N}{T}{E}{G}{E}{R}	    	 {fprintf( spFile, "Shift INTEGER\n"); return(INTEGER);}
{L}{A}{B}{E}{L}              {fprintf( spFile, "Shift LABEL\n"); return(LABEL);}
{M}{O}{D}                    {fprintf( spFile, "Shift MOD\n"); return(MOD);}
{N}{I}{L}                    {fprintf( spFile, "Shift NIL\n"); return(NIL);}
{N}{O}{T}                    {fprintf( spFile, "Shift NOT\n"); return(NOT);}

{O}{F}                       {fprintf( spFile, "Shift OF\n"); return(OF);}
{O}{R}                       {fprintf( spFile, "Shift OR\n"); return(OR);}
{O}{T}{H}{E}{R}{W}{I}{S}{E}  {fprintf( spFile, "Shift OTHERWISE\n"); return(OTHERWISE);}
{P}{A}{C}{K}{E}{D}           {fprintf( spFile, "Shift PACKED\n"); return(PACKED);}
{B}{E}{G}{I}{N}              {fprintf( spFile, "Shift begin\n"); return(PBEGIN);}
{F}{I}{L}{E}                 {fprintf( spFile, "Shift FILE\n"); return(PFILE);}
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {fprintf( spFile, "Shift PROCEDURE\n"); return(PROCEDURE);}
{P}{R}{O}{G}{R}{A}{M}        {fprintf( spFile, "Shift PROGRAM\n"); return(PROGRAM);}
{R}{E}{C}{O}{R}{D}           {fprintf( spFile, "Shift RECORD\n"); return(RECORD);}
{R}{E}{P}{E}{A}{T}           {fprintf( spFile, "Shift REPEAT\n"); return(REPEAT);}

{S}{E}{T}                    {fprintf( spFile, "Shift SET\n"); return(SET);}
{T}{H}{E}{N}                 {fprintf( spFile, "Shift THEN\n"); return(THEN);}
{T}{O}                       {fprintf( spFile, "Shift TO\n"); return(TO);}
{T}{Y}{P}{E}                 {fprintf( spFile, "Shift TYPE\n"); return(TYPE);}
{U}{N}{T}{I}{L}              {fprintf( spFile, "Shift UNTIL\n"); return(UNTIL);}
{V}{A}{R}                    {fprintf( spFile, "Shift VAR\n"); return(VAR);}
{W}{H}{I}{L}{E}              {fprintf( spFile, "Shift WHILE\n"); return(WHILE);}
{W}{I}{T}{H}                 {fprintf( spFile, "Shift WITH\n"); return(WITH);}

{R}{E}{A}{L}	               {fprintf( spFile, "Shift REAL\n"); return(REAL);}

{id_e}                       {fprintf( spFile, "Shift [ID] %s\n", yytext); yylval.string = yytext; return(ID);}
":="                         {fprintf( spFile, "Shift := \n"); return(ASSIGNMENT);}

\"(\\.|[^\^\n\"])*\"			   {fprintf( spFile, "Shift CHARACTER_STRING\n"); return(CHARACTER_STRING);}
":"                          {fprintf( spFile, "Shift : \n"); return(COLON);}
","                          {fprintf( spFile, "Shift , \n"); return(COMMA);}
{integer}	                   {yylval.number = atoi(yytext); fprintf( spFile, "Shift [NUM] %s \n", yytext);  return(NUM);}
"."                          {fprintf( spFile, "Shift . \n"); return(DOT);}
".."                         {fprintf( spFile, "Shift .. \n"); return(DOTDOT);}
"="                          {fprintf( spFile, "Shift = \n"); return(EQUAL);}
">="                         {fprintf( spFile, "Shift >= \n"); return(GE);}
">"                          {fprintf( spFile, "Shift > \n"); return(GT);}
"["                          {fprintf( spFile, "Shift [ \n"); return(LBRAC);}

"<="                         {fprintf( spFile, "Shift <= \n"); return(LE);}
"("                          {fprintf( spFile, "Shift ( \n"); return(LPAREN);}
"<"                          {fprintf( spFile, "Shift < \n"); return(LT);}
"-"                          {fprintf( spFile, "Shift - \n"); return(MINUS);}
"+"                          {fprintf( spFile, "Shift + \n"); return(PLUS);}
"]"                          {fprintf( spFile, "Shift ] \n"); return(RBRAC);}
")"                          {fprintf( spFile, "Shift ) \n"); return(RPAREN);}
";"                          {fprintf( spFile, "Shift ; \n"); return(SEMICOLON);}

"/"                          {fprintf( spFile, "Shift / \n"); return(SLASH);}
"*"                          {fprintf( spFile, "Shift * \n"); return(STAR);}
"**"               		 	     {fprintf( spFile, "Shift ** \n"); return(STARSTAR);}
"!="                         {fprintf( spFile, "Shift != \n"); return(notEQUAL);}
{real}	           					 {fprintf( spFile, "Shift [real] %s \n", yytext); yylval.number = atof(yytext); return(NUM);}
"//"						             { comment(); }



'({NQUOTE}|'')+'             {fprintf( spFile, "Shift STRING \n"); yylval.string = yytext; return(CHARACTER_STRING);}









"(*"   |
"{"    { register int c;
     while ((c = input()))
     {
      if (c == '}')
       break;
      else if (c == '*')
      {
       if ((c = input()) == ')')
        break;
       else
        unput (c);
      }
      else if (c == '\n')
       line_no++;
      else if (c == 0)
        fprintf (stderr, "Unexpected EOF inside comment at line %d\n",line_no);
     }
    }

[ \t\f]    ;

\r         ;
\n    line_no++;

.    { fprintf( stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%






comment()
{
	char c;

	while ((c = input()) != '\n' && c != 0)
	{}
}
