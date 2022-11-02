#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <time.h>

enum card_value {
    two, three, four, five, six, seven, eight, nine, ten, knight, queen, king, ace, joker
};
enum card_color {
    clover, diamonds, hearts, spades, misc
};

struct cards {
    enum card_value value;
    enum card_color cardColor;
};

void fillDeck(struct cards a[]);

void printDeck(struct cards a[]);

void shuffleDeck(struct cards a[]);

int sortCompare(const void *p, const void *j);

void sortDeck(struct cards a[]);

int main(void) {
    srand(time(NULL));
    struct cards cardGame[55];
    fillDeck(cardGame);
    printDeck(cardGame);

    printf("-------------------\n");
    shuffleDeck(cardGame);
    printDeck(cardGame);

    printf("-------------------\n");
    sortDeck(cardGame);
    printDeck(cardGame);


    return 0;
}

void fillDeck(struct cards a[]) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; ++j) {
            a[count].cardColor = i;
            a[count].value = j;

            count++;
        }
    }
    for (int i = 0; i < 3; ++i) {
        a[count].cardColor = 4;
        a[count].value = 13;
        count++;

    }
}// Fills an array with struct cards from 2 to ace
// Clover, diamonds, hearts then spades and puts 3 jokers in end
void printDeck(struct cards a[]) {
    for (int i = 0; i < 55; ++i) {
        printf("Card %d: ", i + 1);
        switch (a[i].value) {
            case two:
                printf("Two of ");
                break;
            case three:
                printf("Three of ");
                break;
            case four:
                printf("Four of ");
                break;
            case five:
                printf("Five of ");
                break;
            case six:
                printf("Six of ");
                break;
            case seven:
                printf("Seven of ");
                break;
            case eight:
                printf("Eight of ");
                break;
            case nine:
                printf("Nine of ");
                break;
            case ten:
                printf("Ten of ");
                break;
            case knight:
                printf("Knight of ");
                break;
            case queen:
                printf("Queen of ");
                break;
            case king:
                printf("King of ");
                break;
            case ace:
                printf("Ace of ");
                break;
            case joker:
                printf("Joker\n");
                break;
            default:
                printf("Error no value assigned");
        }

        switch (a[i].cardColor) {
            case hearts:
                printf("hearts\n");
                break;
            case spades:
                printf("spades\n");
                break;
            case diamonds:
                printf("diamonds\n");
                break;
            case clover:
                printf("clovers\n");
                break;
            case misc:
                break;
        }
    }
}//Prints an array in the current order
void shuffleDeck(struct cards a[]) {
    for (int i = 0; i < 55; ++i) {

        int randomIndex = rand() % 55;

        struct cards TempRandom = a[randomIndex];
        a[randomIndex] = a[i];
        a[i] = TempRandom;

    }
}

void sortDeck(struct cards a[]) {
    qsort(a, 55, sizeof(struct cards), sortCompare);
}

int sortCompare(const void *p, const void *j) {
    struct cards *cardA = (struct cards *) p;
    struct cards *cardB = (struct cards *) j;


    int check;
    if (cardA->cardColor > cardB->cardColor)
        check = 1;

    if (cardA->cardColor < cardB->cardColor)
        check = -1;

    if (cardA->cardColor == cardB->cardColor) {
        if (cardA->value < cardB->value)
            check = -1;
        else if (cardA->value > cardB->value)
            check = 1;
        else
            check = 0;
    }
    return check;

}