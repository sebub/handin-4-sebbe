#include <stdio.h>
#include <search.h>
#include <stdlib.h>
#include <time.h>

enum card_value {two, three, four, five, six, seven, eight, nine, ten, knight, queen, king, ace, joker};
enum card_color {clover, diamonds, hearts, spades, misc};

typedef struct {
    enum card_value value;
    enum card_color cardColor;
}cards;

void fillDeck(cards deck[]);   //Takes an array and fills it with the type struct card
void printDeck(cards deck[]);  //Prints the array in the current order
void shuffleDeck(cards deck[]);//Shuffles deck in random order
void sortDeck(cards deck[]);   //Uses qsort to sort the deck
int sortCompare(const void *x, const void *y); //holds the logic of how the deck should be sorted

int main(void) {
    srand(time(NULL));//initialises random for future use when shuffling cards randomly
    cards cardGame[55];//initialises the array that will hold our deck. Holds entries of the type "cards".
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

void fillDeck(cards deck[]) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; ++j) {//Fills an array with the struct "cards" from two to ace
            deck[count].cardColor = i;//in ascending order for each of the four card colors
            deck[count].value = j;

            count++;
        }
    }
    for (int i = 0; i < 3; ++i) {//adds 3 jokers to the deck
        deck[count].cardColor = 4;
        deck[count].value = 13;
        count++;

    }
}

void printDeck(cards deck[]) {
    for (int i = 0; i < 55; ++i) {//Prints color and value of each in the current order.
        printf("Card %d: ", i + 1);
        switch (deck[i].value) {
            case two:   printf("Two of ");   break;
            case three: printf("Three of "); break;
            case four:  printf("Four of ");  break;
            case five:  printf("Five of ");  break;
            case six:   printf("Six of ");   break;
            case seven: printf("Seven of "); break;
            case eight: printf("Eight of "); break;
            case nine:  printf("Nine of ");  break;
            case ten:   printf("Ten of ");   break;
            case knight:printf("Knight of ");break;
            case queen: printf("Queen of "); break;
            case king:  printf("King of ");  break;
            case ace:   printf("Ace of ");   break;
            case joker: printf("Joker\n");   break;
            default:    printf("Error no value assigned");
        }

        switch (deck[i].cardColor) {
            case hearts:   printf("hearts\n");   break;
            case spades:   printf("spades\n");   break;
            case diamonds: printf("diamonds\n"); break;
            case clover:   printf("clovers\n");  break;
            case misc: break;
            default: printf("Error no value assigned");
        }
    }
}
void shuffleDeck(cards deck[]) {//shuffles the deck in random order
    for (int i = 0; i < 55; ++i) {

        int randomIndex = rand() % 55; //Gets random number between 0 and 54
        cards TempRandom = deck[randomIndex];//Creates temp card to avoid duplicating cards
        deck[randomIndex] = deck[i];//takes the card on the random index and swaps places with the card on the
        deck[i] = TempRandom;       //index of the current iterations of the loop.

    }
}

void sortDeck(cards deck[]) {
    qsort(deck, 55, sizeof(cards), sortCompare);//Takes an array, the
    // length of the array, size of the elements in the array, and the function that determine the order the array that
    // is returned.
}

int sortCompare(const void *x, const void *y) { //compares two entries in an array and returns 1 if x should go before y,
    cards *cardA = (cards *) x;                 //0 they are equivalent and -1 if y should go before x.
    cards *cardB = (cards *) y;

    int check;
    if (cardA->cardColor > cardB->cardColor)    //Compares entries by color in the
        check = 1;                              //order clover < diamonds < hearts < spades < misc

    if (cardA->cardColor < cardB->cardColor)
        check = -1;

    if (cardA->cardColor == cardB->cardColor) { //If compared entries have the same card color, sort by value in the
        if (cardA->value < cardB->value)        //order 2 < 3 < 4 < 5 < 6 < 7 < 8 < 9 < 10 < knight < queen < king < ace < joker
            check = -1;
        else if (cardA->value > cardB->value)
            check = 1;
        else
            check = 0;
    }
    return check;

}