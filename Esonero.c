#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main (){

  time_t t;
  char plaintextM[128];
  char chiperkeyk[128];
  char casualchiperkeyk[128];
  char chiperedcodeC[128];
  char proof[128];
  int risposta;
  int lengthM;
  int lengthk;


    srand((unsigned) time(&t));

    printf("\n________________________________________________________________\n");
    printf("Inserisci il testo da cifrare:\n");
    printf("(Attenzione il limite massimo e' di 128 caratteri)\n\n");

      fgets(plaintextM, 128, stdin);
      lengthM=strlen(plaintextM);
      /*printf("%d\n",lengthM);*/

    printf("________________________________________________________________\n");
    printf("Ora sara' possibile procedere in due modi differenti:\n\n");
    printf(" 1)Inserire una chiave di cifratura\n");
    printf(" 2)Assegnare una chiave di cifratura casuale\n");
    printf("________________________________________________________________\n");
    printf("Effettuare una scelta [1/2]:\n\n");
      scanf("%d",&risposta);
    printf("________________________________________________________________\n");

        int ch;
        while((ch=getchar()) != '\n'&& ch != EOF);

    switch (risposta) {
      case 1:
        printf("Inserisci la chiave di cifratura: \n");
        printf("(Attenzione la chiave deve essere uguale o superiore alla chiave di cifratura ma inferiore a 128 caratteri)\n\n");
          fgets(chiperkeyk, 128, stdin);
          lengthk=strlen(chiperkeyk);

          while (lengthk<lengthM) {
              printf("________________________________________________________________\n");
              printf("ATTENZIONE LA CHIAVE DI CIFRATURA NON E' CORRETTA\n");
              printf("Inserisci di nuovo la chiave di cifratura: \n");
              printf("(La chiave deve essere uguale o superiore alla chiave di cifratura ma inferiore a 128 caratteri)\n\n");
                fgets(chiperkeyk, 128, stdin);
                lengthk=strlen(chiperkeyk);
          }

        printf("________________________________________________________________\n");
        printf("Operazione XOR tra M e k: \n\n");
          for(int i=0; i<128; i++){
             chiperedcodeC[i]=plaintextM[i]^chiperkeyk[i];
              }
        printf("%s\n", chiperedcodeC);
        printf("________________________________________________________________\n");
        printf("Prova di ritorno (Operazione C^k): \n\n");
          for(int i=0; i<128; i++){
              proof[i]=chiperedcodeC[i]^chiperkeyk[i];
              }
        printf("%s\n", proof);
        printf("________________________________________________________________\n");
      break;

      case 2:
        printf("La chiave assegnata automaticamente e': \n\n");
          for(int i=0; i<lengthM; i++){
              casualchiperkeyk[i]=(rand()%(0-127));
              }
        printf("%s\n", casualchiperkeyk);

        printf("________________________________________________________________\n");
        printf("Operazione XOR tra M e k: \n\n");
          for(int i=0; i<128; i++){
              chiperedcodeC[i]=plaintextM[i]^casualchiperkeyk[i];
              }
        printf("%s\n", chiperedcodeC);
        printf("________________________________________________________________\n");
        printf("Prova di ritorno (Operazione C^k): \n\n");
          for(int i=0; i<128; i++){
              proof[i]=chiperedcodeC[i]^casualchiperkeyk[i];
              }
        printf("%s", proof);
        printf("________________________________________________________________\n");
      break;
    }
}
