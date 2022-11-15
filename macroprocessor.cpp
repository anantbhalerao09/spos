#include <iostream >
#include <cstdio >
#include <cstring >
#include <cstdlib >

 class deftab {
 public:
 char lab [10];
 char opc [10];
 char oper [10];
 } d[10];

 int main() {
 char label [10], opcode [10], operand [10];
 char macroname [10];
 int i = 0, lines = 0;
 FILE *f1 , *f2 , *f3;

 f1 = fopen("macin.dat", "r");
 f2 = fopen("macout.dat", "w");
 f3 = fopen("deftab.dat", "w");

 fscanf(f1 , "%s%s%s", label , opcode , operand);

 while (strcmp(opcode , "END") != 0) {
 if (strcmp(opcode , "MACRO") == 0) {
 strcpy(macroname , label);
 fscanf(f1 , "%s%s%s", label , opcode , operand);
 lines = 0;

 while (strcmp(opcode , "MEND") != 0) {
 fprintf(f3 , "%s\t%s\t%s\n", label , opcode , operand);
 strcpy(d[lines ].lab , label);
 strcpy(d[lines ].opc , opcode);
 strcpy(d[lines ].oper , operand);

 fscanf(f1 , "%s%s%s", label , opcode , operand);
 lines ++;
 }
 }
 else if (strcmp(opcode , macroname) == 0) {
 printf("Lines = %d\n", lines);

 for (i = 0; i < lines; i++) {
 fprintf(f2 , "%s\t%s\t%s\n", d[i].lab , d[i].opc , d[i].oper);
 printf("DLAB = %s \nDOPC = %s \nDOPER = %s \n", d[i].lab , d[i].opc ,
d[i].oper);
 }
 }
 else {
     fprintf(f2 , "%s\t%s\t%s\n", d[i].lab , d[i].opc , d[i].oper);
 }
 fscanf(f1 , "%s%s%s", label , opcode , operand);
 }
 fprintf(f2 , "%s\t%s\t%s\n", d[i].lab , d[i].opc , d[i].oper);
 fclose(f1);
 fclose(f2);
 fclose(f3);
 printf("FINISHED\n");
 return 0;
 }


 CALC   START 1000
 SUM    MACRO **
 **     LDA #5
 **     ADD #10
 **     STA 2000
 **     MEND **
 **     LDA LENGTH
 **     COMP ZERO
 **     JEQ LOOP
 **     SUM **
 LENGTH WORD 0
 LOOP   SUM **
 **     END **
