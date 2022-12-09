//MAGALI ANAHI MEZA CHAVEZ

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

int main() {
    int secretNum, flag=1, attempts=0, answer, round=1, lowPos=0,lower, higPos=0, higher;
    int i, tam=0, array[round], f, total;
    float average;

    srand(time(NULL));

    //Generate the random number
    secretNum=rand()%100+1;
    //printf("%d \n", secretNum); Uncomment to print number to guess

    HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
    printf("A random number was chosen between 1 and 100, you must guess it in a maximum of 10 attempts.. \n");
    printf("Enter 0 to quit the game.\n ");
    SetConsoleTextAttribute(hConsole, 11);
    printf("\n ----Round %d ----- \n", round);

	//Cycle with flag
    do {
        attempts++;
        SetConsoleTextAttribute(hConsole, 15);
        printf("\nWrite the number you think it is: ");
        scanf("%d", &answer);
        if (answer == secretNum) {
          SetConsoleTextAttribute(hConsole, 10);
          printf("\nCorrect! The number was %d and you guessed it in %d tries. \n",secretNum, attempts);
          round= round+1;

          SetConsoleTextAttribute(hConsole, 11);
          printf("\n ---- Let's go for the round %d ----- \n", round);
          array[tam] = attempts;
          tam++;
          attempts=0;
          srand(time(NULL));
          secretNum=rand()%100+1;
          //printf("%d ", secretNum);
        } else if (answer==0){ SetConsoleTextAttribute(hConsole, 10);
            printf("\nLeaving the game...\n");
            round=round-1;
            flag = 0;
        } else if (answer < secretNum) {
          printf("Error, the number is greater\n");
        } else {
          printf(
              "Error, the number is less\n");
        }

        if (attempts >= 10) {
          SetConsoleTextAttribute(hConsole, 10);
          printf("\nYou lost. The number was %d \n", secretNum);
          round= round+1;
          SetConsoleTextAttribute(hConsole, 11);

          printf("\n ----- Let's go for the round %d ----\n", round);
          array[tam] = attempts;
          tam++;
          attempts=0;
          srand(time(NULL));
          secretNum=rand()%100+1;
          //printf("%d ", secretNum);
        }
    } while (flag==1);

    printf("\n         |ROUNDS PLAYED                  |%d           |\n", round);
    higher = lower = array[0];
    for(int i = 1; i <= round-1; ++i)
    {
        if(array[i] > higher)
        {
            higher = array[i];
            higPos = i;
        }
        if(array[i] < lower)
        {
            lower=array[i];
            lowPos = i;
        }
    }
    printf("         |YOUR BEST ROUND  (Round %d)     |%d ATTEMPT   |\n",lowPos+1,lower);
    printf("         |YOUR WORST ROUND (Round %d)     |%d ATTEMPT   |\n",higPos+1,higher);

    for (f=0; f<=round-1; f++){
        total+=array[f];
    }
    average= total/round;
    printf("         |AVERAGE OF YOUR ATTEMPTS       |%.0f ATTEMPTS  |\n", average);

    SetConsoleTextAttribute(hConsole, 15);
    return 0;
}



