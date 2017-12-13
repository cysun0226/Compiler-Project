%{
/*
 * scan.l
 *
 * lex input file for pascal scanner
 *
 * extensions: two ways to spell "external" and "->" ok for "^".
 */

 #include <stdio.h>
 #include "parser.tab.h"

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

{A}{N}{D}                    {printf("Shift AND\n"); return(AND);}
{A}{R}{R}{A}{Y}              {printf("Shift ARRAY\n"); return(ARRAY);}
{C}{A}{S}{E}                 {printf("Shift CASE\n"); return(CASE);}
{C}{O}{N}{S}{T}              {printf("Shift CONST\n"); return(CONST);}
{D}{I}{V}                    {printf("Shift DIV\n"); return(DIV);}
{D}{O}                       {printf("Shift DO\n"); return(DO);}
{D}{O}{W}{N}{T}{O}           {printf("Shift DOWNTO\n"); return(DOWNTO);}
{E}{L}{S}{E}                 {printf("Shift ELSE\n"); return(ELSE);}
{E}{N}{D}                    {printf("Shift END\n"); return(END);}
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L}     {printf("Shift EXTERNAL\n"); return(EXTERNAL);}

{F}{O}{R}                    {printf("Shift FOR\n"); return(FOR);}
{F}{O}{R}{W}{A}{R}{D}        {printf("Shift FORWARD\n"); return(FORWARD);}
{F}{U}{N}{C}{T}{I}{O}{N}     {printf("Shift FUNCTION\n"); return(FUNCTION);}
{G}{O}{T}{O}                 {printf("Shift GOTO\n"); return(GOTO);}
{I}{F}                       {printf("Shift IF\n"); return(IF);}
{I}{N}                       {printf("Shift IF\n"); return(IN);}


{I}{N}{T}{E}{G}{E}{R}	    	 {printf("Shift INTEGER\n"); return(INTEGER);}
{L}{A}{B}{E}{L}              {printf("Shift LABEL\n"); return(LABEL);}
{M}{O}{D}                    {printf("Shift MOD\n"); return(MOD);}
{N}{I}{L}                    {printf("Shift NIL\n"); return(NIL);}
{N}{O}{T}                    {printf("Shift NOT\n"); return(NOT);}

{O}{F}                       {printf("Shift OF\n"); return(OF);}
{O}{R}                       {printf("Shift OR\n"); return(OR);}
{O}{T}{H}{E}{R}{W}{I}{S}{E}  {printf("Shift OTHERWISE\n"); return(OTHERWISE);}
{P}{A}{C}{K}{E}{D}           {printf("Shift PACKED\n"); return(PACKED);}
{B}{E}{G}{I}{N}              {printf("Shift begin\n"); return(PBEGIN);}
{F}{I}{L}{E}                 {printf("Shift FILE\n"); return(PFILE);}
{P}{R}{O}{C}{E}{D}{U}{R}{E}  {printf("Shift PROCEDURE\n"); return(PROCEDURE);}
{P}{R}{O}{G}{R}{A}{M}        {printf("Shift PROGRAM\n"); return(PROGRAM);}
{R}{E}{C}{O}{R}{D}           {printf("Shift RECORD\n"); return(RECORD);}
{R}{E}{P}{E}{A}{T}           {printf("Shift REPEAT\n"); return(REPEAT);}

{S}{E}{T}                    {printf("Shift SET\n"); return(SET);}
{T}{H}{E}{N}                 {printf("Shift THEN\n"); return(THEN);}
{T}{O}                       {printf("Shift TO\n"); return(TO);}
{T}{Y}{P}{E}                 {printf("Shift TYPE\n"); return(TYPE);}
{U}{N}{T}{I}{L}              {printf("Shift UNTIL\n"); return(UNTIL);}
{V}{A}{R}                    {printf("Shift VAR\n"); return(VAR);}
{W}{H}{I}{L}{E}              {printf("Shift WHILE\n"); return(WHILE);}
{W}{I}{T}{H}                 {printf("Shift WITH\n"); return(WITH);}

{R}{E}{A}{L}	               {printf("Shift REAL\n"); return(REAL);}

{id_e}                       {printf("Shift [ID] %s (line %d)\n", yytext, line_no); yylval.string = yytext; return(ID);}
":="                         {printf("Shift := \n"); return(ASSIGNMENT);}

\"(\\.|[^\^\n\"])*\"			   {printf("Shift CHARACTER_STRING\n"); return(CHARACTER_STRING);}
":"                          {printf("Shift : \n"); return(COLON);}
","                          {printf("Shift , \n"); return(COMMA);}
{integer}	                   {yylval.number = atoi(yytext); printf("Shift [NUM] %s \n", yytext);  return(NUM);}
"."                          {printf("Shift . \n"); return(DOT);}
".."                         {printf("Shift .. \n"); return(DOTDOT);}
"="                          {printf("Shift = \n"); return(EQUAL);}
">="                         {printf("Shift >= \n"); return(GE);}
">"                          {printf("Shift > \n"); return(GT);}
"["                          {printf("Shift [ \n"); return(LBRAC);}

"<="                         {printf("Shift <= \n"); return(LE);}
"("                          {printf("Shift ( \n"); return(LPAREN);}
"<"                          {printf("Shift < \n"); return(LT);}
"-"                          {printf("Shift - \n"); return(MINUS);}
"+"                          {printf("Shift + \n"); return(PLUS);}
"]"                          {printf("Shift ] \n"); return(RBRAC);}
")"                          {printf("Shift ) \n"); return(RPAREN);}
";"                          {printf("Shift ; \n"); return(SEMICOLON);}

"/"                          {printf("Shift \ \n"); return(SLASH);}
"*"                          {printf("Shift * \n"); return(STAR);}
"**"               		 	     {printf("Shift ** \n"); return(STARSTAR);}
"!="                         {printf("Shift != \n"); return(notEQUAL);}
{real}	           					 {printf("Shift [real] %s \n", yytext); yylval.number = atof(yytext); return(NUM);}
"//"						             { comment(); line_no++; }



'({NQUOTE}|'')+'             {printf("Shift STRING \n"); yylval.string = yytext; return(CHARACTER_STRING);}









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

.    {fprintf(stderr,"Lexical analyzer error at line %d : %s\n",line_no,yytext);}

%%






comment()
{
	char c;

	while ((c = input()) != '\n' && c != 0)
	{}
}
