/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
Full Name  :    Jong wan Steven Hur
Student ID#:    122372220
Email      :    shur1@myseneca.ca
Section    :    NCC

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LIVES 10
#define MIN_PATH_LEN 10
#define MAX_PATH_LEN 70
#define MULTIPLE 5

struct PlayerInfo
{
    int numberOfLives;
    char characterSymbol;
    int numberOfTreasure;
    int positionHistory[MAX_PATH_LEN];
};

struct GameInfo
{
    int maximumMoves;
    int pathLength;
    int treasureLocation[MAX_PATH_LEN];
    int bombLocation[MAX_PATH_LEN];
};

int main(void)
{
    struct PlayerInfo pInfo = { 0, 0, 0, {0} };
    struct GameInfo gInfo = { 0, 0, {0}, {0} };
    int outOfRange = 0, i;

    printf("================================\n");
    printf("         Treasure Hunt!\n");
    printf("================================\n");

    printf("\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &pInfo.characterSymbol);
    do {
        printf("Set the number of lives: ");
        scanf("%d", &pInfo.numberOfLives);
        outOfRange = pInfo.numberOfLives < 1 || pInfo.numberOfLives > MAX_LIVES;
        if (outOfRange) printf("     Must be between 1 and %d!\n", MAX_LIVES);
    } while (outOfRange);
    printf("Player configuration set-up is complete\n");

    printf("\n");
    printf("GAME Configuration\n");
    printf("------------------\n");
    do {
        printf("Set the path length (a multiple of %d between %d-%d): ", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
        scanf("%d", &gInfo.pathLength);
        outOfRange = (gInfo.pathLength % MULTIPLE) > 0 || gInfo.pathLength < MIN_PATH_LEN || gInfo.pathLength > MAX_PATH_LEN;
        if (outOfRange) printf("     Must be a multiple of %d and between %d-%d!!!\n", MULTIPLE, MIN_PATH_LEN, MAX_PATH_LEN);
    } while (outOfRange);
    do {
        printf("Set the limit for number of moves allowed: ");
        scanf("%d", &gInfo.maximumMoves);
        outOfRange = gInfo.maximumMoves < pInfo.numberOfLives || gInfo.maximumMoves >(int)(gInfo.pathLength * 0.75);
        if (outOfRange) printf("    Value must be between %d and %d\n", pInfo.numberOfLives, (int)(gInfo.pathLength * 0.75));
    } while (outOfRange);

    printf("\n");
    printf("BOMB Placement\n");
    printf("--------------\n");
    printf("Enter the bomb positions in sets of 5 where a value\n");
    printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gInfo.pathLength);
    for (i = 0; i < gInfo.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &gInfo.bombLocation[i], &gInfo.bombLocation[i + 1], &gInfo.bombLocation[i + 2], &gInfo.bombLocation[i + 3], &gInfo.bombLocation[i + 4]);
    }
    printf("BOMB placement set\n");

    printf("\n");
    printf("TREASURE Placement\n");
    printf("------------------\n");
    printf("Enter the treasure placements in sets of 5 where a value\n");
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", gInfo.pathLength);
    for (i = 0; i < gInfo.pathLength; i += 5)
    {
        printf("   Positions [%2d-%2d]: ", i + 1, i + 5);
        scanf("%d%d%d%d%d", &gInfo.treasureLocation[i], &gInfo.treasureLocation[i + 1], &gInfo.treasureLocation[i + 2], &gInfo.treasureLocation[i + 3], &gInfo.treasureLocation[i + 4]);
    }
    printf("TREASURE placement set\n");

    printf("\n");
    printf("GAME configuration set-up is complete...\n");

    printf("\n");
    printf("------------------------------------\n");
    printf("TREASURE HUNT Configuration Settings\n");
    printf("------------------------------------\n");
    printf("Player:\n");
    printf("   Symbol     : %c\n", pInfo.characterSymbol);
    printf("   Lives      : %d\n", pInfo.numberOfLives);
    printf("   Treasure   : [ready for gameplay]\n");
    printf("   History    : [ready for gameplay]\n");

    printf("\n");
    printf("Game:\n");
    printf("   Path Length: %d\n", gInfo.pathLength);
    printf("   Bombs      : ");
    for (i = 0; i < gInfo.pathLength; i++)
    {
        printf("%d", gInfo.bombLocation[i]);
    }
    printf("\n");
    printf("   Treasure   : ");
    for (i = 0; i < gInfo.pathLength; i++)
    {
        printf("%d", gInfo.treasureLocation[i]);
    }
    printf("\n");

    printf("\n");
    printf("====================================\n");
    printf("~ Get ready to play TREASURE HUNT! ~\n");
    printf("====================================\n");

    int treasuresFound = 0, nextMove = -1;
    char gameBoard[MAX_PATH_LEN];
    for (i = 0; i < gInfo.pathLength; i++)
    {
        gameBoard[i] = '-';
    }

    printf("\n");
    printf("  ");
    for (i = 0; i < gInfo.pathLength; i++)
    {
        printf("%c", gameBoard[i]);
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= gInfo.pathLength; i++)
    {
        if (i % 10 == 0) printf("%d", i / 10);
        else printf("|");
    }
    printf("\n");
    printf("  ");
    for (i = 1; i <= gInfo.pathLength; i++)
    {
        printf("%d", (i % 10));
    }
    printf("\n");
    
    do
    {
        printf("+---------------------------------------------------+\n");
        printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", pInfo.numberOfLives, treasuresFound, gInfo.maximumMoves);
        printf("+---------------------------------------------------+\n");
        do
        {
            printf("Next Move [1-%d]: ", gInfo.pathLength);
            scanf(" %d", &nextMove);
            outOfRange = nextMove < 1 || nextMove > gInfo.pathLength;
            if (outOfRange) printf("  Out of Range!!!\n");
        } while (outOfRange);
        
        if (pInfo.positionHistory[nextMove-1] == 1)
        {
            printf("\n");
            printf("===============> Dope! You've been here before!\n");
            printf("\n");
        }
        
        else
        {
            pInfo.positionHistory[nextMove-1] = 1;
            printf("\n");

            if (gInfo.bombLocation[nextMove-1] == 1 && gInfo.treasureLocation[nextMove-1] == 1)
            {
                gameBoard[nextMove-1] = '&';
                printf("===============> [&] !!! BOOOOOM !!! [&]\n");
                printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n");
                treasuresFound+=1;
                pInfo.numberOfLives-=1;
                printf("\n");
            }
            else if (gInfo.bombLocation[nextMove-1] == 1)
            {
                gameBoard[nextMove - 1] = '!';
                printf("===============> [!] !!! BOOOOOM !!! [!]\n");
                pInfo.numberOfLives-=1;
                printf("\n");
            }
            else if (gInfo.treasureLocation[nextMove-1] == 1)
            {
                gameBoard[nextMove - 1] = '$';
                printf("===============> [$] $$$ Found Treasure! $$$ [$]\n");
                treasuresFound+=1;
                printf("\n");
            }
            else
            {
                gameBoard[nextMove-1] = '.';
                printf("===============> [.] ...Nothing found here... [.]\n");
                printf("\n");
            }

            gInfo.maximumMoves-=1;
        }

        if (pInfo.numberOfLives == 0)
        {
            printf("No more LIVES remaining!\n");
            printf("\n");
        }

        printf("  ");
        for (i = 0; i < gInfo.pathLength; i++)
        {
            if (i == nextMove - 1)
            {
                printf("%c", pInfo.characterSymbol);
                i = gInfo.pathLength;
            }
            else printf(" ");
        }
        printf("\n");
        printf("  ");
        for (i = 0; i < gInfo.pathLength; i++)
        {
            printf("%c", gameBoard[i]);
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= gInfo.pathLength; i++)
        {
            if (i % 10 == 0) printf("%d", i / 10);
            else printf("|");
        }
        printf("\n");
        printf("  ");
        for (i = 1; i <= gInfo.pathLength; i++)
        {
            printf("%d", (i % 10));
        }
        printf("\n");
    } while (gInfo.maximumMoves > 0 && pInfo.numberOfLives > 0);
    
    printf("+---------------------------------------------------+\n");
    printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", pInfo.numberOfLives, treasuresFound, gInfo.maximumMoves);
    printf("+---------------------------------------------------+\n");

    printf("\n");
    printf("##################\n");
    printf("#   Game over!   #\n");
    printf("##################\n");

    printf("\n");
    printf("You should play again and try to beat your score!\n");

    return 0;
}