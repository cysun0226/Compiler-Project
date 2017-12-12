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

{A}{N}{D}                    { return(AND);}
{A}{R}{R}{A}{Y}              { return(ARRAY);}
{C}{A}{S}{E}                 { return(CASE);}
{C}{O}{N}{S}{T}              { return(CONST);}
{D}{I}{V}                    { return(DIV);}
{D}{O}                       { return(DO);}
{D}{O}{W}{N}{T}{O}           { return(DOWNTO);}
{E}{L}{S}{E}                 { return(ELSE);}
{E}{N}{D}                    { return(END);}
{E}{X}{T}{E}{R}{N} |
{E}{X}{T}{E}{R}{N}{A}{L}     { return(EXTERNAL);}

{F}{O}{R}                    { return(FOR);}
{F}{O}{R}{W}{A}{R}{D}        { return(FORWARD);}
{F}{U}{N}{C}{T}{I}{O}{N}     { return(FUNCTION);}
{G}{O}{T}{O}                 { return(GOTO);}
{I}{F}                       { return(IF);}
{I}{N}                       { return(IN);}


{I}{N}{T}{E}{G}{E}{R}	    	 { return(INTEGER);}
{L}{A}{B}{E}{L}              { return(LABEL);}
{M}{O}{D}                    { return(MOD);}
{N}{I}{L}                    { return(NIL);}
{N}{O}{T}                    { return(NOT);}

{O}{F}                       { return(OF);}
{O}{R}                       { return(OR);}
{O}{T}{H}{E}{R}{W}{I}{S}{E}  { return(OTHERWISE);}
{P}{A}{C}{K}{E}{D}           { return(PACKED);}
{B}{E}{G}{I}{N}              { return(PBEGIN);}
{F}{I}{L}{E}                 { return(PFILE);}
{P}{R}{O}{C}{E}{D}{U}{R}{E}  { return(PROCEDURE);}
{P}{R}{O}{G}{R}{A}{M}        { return(PROGRAM);}
{R}{E}{C}{O}{R}{D}           { return(RECORD);}
{R}{E}{P}{E}{A}{T}           { return(REPEAT);}

{S}{E}{T}                    { return(SET);}
{T}{H}{E}{N}                 { return(THEN);}
{T}{O}                       { return(TO);}
{T}{Y}{P}{E}                 { return(TYPE);}
{U}{N}{T}{I}{L}              { return(UNTIL);}
{V}{A}{R}                    { return(VAR);}
{W}{H}{I}{L}{E}              { return(WHILE);}
{W}{I}{T}{H}                 { return(WITH);}

{R}{E}{A}{L}	               { return(REAL);}

{id_e}                       { yylval.string = yytext; return(ID);}
":="                         { return(ASSIGNMENT);}

\"(\\.|[^\^\n\"])*\"			   { return(CHARACTER_STRING);}
":"                          { return(COLON);}
","                          { return(COMMA);}
{integer}	                   {yylval.number = atoi(yytext); return(NUM);}
"."                          { return(DOT);}
".."                         { return(DOTDOT);}
"="                          { return(EQUAL);}
">="                         { return(GE);}
">"                          { return(GT);}
"["                          { return(LBRAC);}

"<="                         { return(LE);}
"("                          { return(LPAREN);}
"<"                          { return(LT);}
"-"                          { return(MINUS);}
"+"                          { return(PLUS);}
"]"                          { return(RBRAC);}
")"                          { return(RPAREN);}
";"                          { return(SEMICOLON);}

"/"                          { return(SLASH);}
"*"                          { return(STAR);}
"**"               		 	     { return(STARSTAR);}
"!="                         { return(notEQUAL);}
{real}	           					 { yylval.number = atof(yytext); return(NUM);}
"//"						             { comment(); }



'({NQUOTE}|'')+'             { yylval.string = yytext; return(CHARACTER_STRING);}









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
