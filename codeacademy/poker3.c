#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
/*
#define STRAIGHT_FLUSH Straight Flush
#define   FOUR_OF_A_KIND Four Of A Kind
#define   FULL_HOUSE Full House
#define   FLUSH Flush
#define   STRAIGHT Straight
#define   THREE_OF_A_KIND Three Of A Kind
#define   TWO_PAIR Two Pair
#define   PAIR Pair
*/
//#ifndef CARD_H
//#define CARD_H
#define VALUE_ACE 14
#define VALUE_KING 13
#define VALUE_QUEEN 12
#define VALUE_JACK 11

typedef enum {
  SPADES,
  HEARTS,
  DIAMONDS,
  CLUBS,
  NUM_SUITS
} suit_t;

struct card_tag {
  unsigned value;
  suit_t suit;
};
typedef struct card_tag card_t;

struct deck_tag {
  card_t ** cards;
  size_t n_cards;
};
typedef struct deck_tag deck_t;

typedef enum {
  STRAIGHT_FLUSH,
  FOUR_OF_A_KIND,
  FULL_HOUSE,
  FLUSH,
  STRAIGHT,
  THREE_OF_A_KIND,
  TWO_PAIR,
  PAIR,
  NOTHING
} hand_ranking_t;

void assert_card_valid(card_t c) {
  assert( c.value >=2);
  assert( c.value <= VALUE_ACE);
  assert( c.suit >= SPADES);
  assert( c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r) {
  switch(r)
    {
        case STRAIGHT_FLUSH:
        return"STRAIGHT FLUSH";
        break;
        case FOUR_OF_A_KIND:
        return "FOUR OF A KIND";
        break;
        case FULL_HOUSE:
        return"FULL HOUSE";
        break;
        case FLUSH:
        return"FLUSH";
        break;
        case STRAIGHT:
        return"STRAIGHT";
        break;
        case THREE_OF_A_KIND:
        return"THREE OF A KIND";
        break;
        case TWO_PAIR:
        return"TWO PAIR";
        break;
        case PAIR:
        return"PAIR";
        break;
        case NOTHING:
        return"NOTHING";
        break;
    }
  return "error";
}

char value_letter(card_t c) {
    switch(c.value)
  {
      case 2:
      return 50;
      break;
      case 3:
      return 51;
      break;
      case 4:
      return 52;
      break;
      case 5:
      return 53;
      break;
      case 6:
      return 54;
      break;
      case 7:
      return 55;
      break;
      case 8:
      return 56;
      break;
      case 9:
      return 57;
      break;
      case 10:
      return 48;
      break;
      case 11:
      return 'J';
      break;
      case 12:
      return 'Q';
      break;
      case 13:
      return 'K';
      break;
      case 14:
      return 'A';
      break;
  }
    return'e';
}


char suit_letter(card_t c) {
  switch(c.suit)
    {
      case SPADES:
      return 's';
      break;
      case HEARTS:
      return 'h';
      break;
      case DIAMONDS:
      return 'd';
      break;
      case CLUBS:
      return 'c';
      break;
      case NUM_SUITS:
      return 'e';
      break;
    }
  return 'e';
}

void print_card(card_t c) {
  //c.value =2 3 .. 14
    printf("%c%c\n", value_letter(c), suit_letter( c) );
}


int int_funct(char v)
 {
   if (v == 50){
     return 2;
   }
      if (v == 51){
     return 3;
   }
   if (v == 52){
     return 4;
   }   if (v == 53){
     return 5;
   }   if (v == 54){
     return 6;
   }   if (v == 55){
     return 7;
   }   if (v == 56){
     return 8;
   }   if (v == 57){
     return 9;
   }  
   if(v==48)
   {
     return 10;
   }
   if(v==74)
   {
     return 11;
   }
  if(v==81)
   {
     return 12;
   }
   if(v==75)
   {
     return 13;
   }
   if(v==65)
   {
     return 14;
   }
   return -1;
 }

 int char_fn(char v)
 {
printf("int %i\n",v);
   if(v=='s')
   {
     
printf("int %c\n",v);
     return 0;
   }
   if(v=='h')
   {
     return 1;
   }
   if(v=='d')
   {
     return 2;
   }
   if(v=='c')
   {
     return 3;
   }

     return -1;
   
 }

card_t card_from_letters(char value_let, char suit_let) {
  card_t temp; 
  //(char)temp.value=  value_let;
  //temp.suit = suit_let;
  //printf("temp.value=%u\n",temp.value);
  //printf("temp.suit=%c\n",temp.suit);
  temp.value =int_funct(value_let);
  temp.suit = char_fn(suit_let);
  print_card(temp);
   //if(temp.value != 2 && temp.value != 3 && temp.value != 4 && temp.value != 5 && temp.value != 6 && temp.value != 7 && temp.value != 8 && temp.value != 9 && temp.value != 10 && temp.value != 11 && temp.value != 12 && temp.value != 13 && temp.value != 14 )
  //if(value_letter(temp) == 'e')
  //if(temp.value != 50 && temp.value != 51 && temp.value != 52 && temp.value != 53 && temp.value != 54 && temp.value != 55 && temp.value != 56 && temp.value != 57 && temp.value != 48 && temp.value != 'J' && temp.value != 'Q' && temp.value != 'K' && temp.value != 'A' )
  if (temp.value == -1)
  {
    printf("sdcfsinvalid value");
    temp.value= 0;
  }
  //if (temp.suit != SPADES && temp.suit != HEARTS && temp.suit != DIAMONDS  && temp.suit != CLUBS)
  //if(suit_letter(temp)== char'e')
  //if (temp.suit != 's' && temp.suit != 'h' && temp.suit != 'd'  && temp.suit != 'c')
  if(temp.suit == -1)
  {
    printf("invalid value");
    temp.suit= NUM_SUITS;   
  }
  return temp;//change ifs
}

card_t card_from_num(unsigned c) {
  card_t temp;
  int x=(c%13);
  switch(x)
  {
      case 0:
      temp.value=2;
      break;
      case 1:
      temp.value=3;
      break;
      case 2:
      temp.value=4;
      break;
      case 3:
      temp.value=5;
      break;
      case 4:
      temp.value=6;
      break;
      case 5:
      temp.value=7;
      break;
      case 6:
      temp.value=8;
      break;
      case 7:
      temp.value=9;
      break;
      case 8:
      temp.value=10;
      break;
      case 9:
      temp.value=11;
      break;
      case 10:
      temp.value=12;
      break;
      case 11:
      temp.value=13;
      break;
      case 12:
      temp.value=14;
      break;
  }
int y=(c/13);
 switch(y)
    {
      case 0:
      temp.suit= SPADES;
      break;
      case 1:
      temp.suit= HEARTS;
      break;
      case 2:
      temp.suit = DIAMONDS;
      break;
      case 3:
      temp.suit= CLUBS;
      break;
    }   
  return temp;
}

//print card value and suit with a space
void print_card_space(card_t c) {
  //c.value =2 3 .. 14
  printf("%c%c ", value_letter(c), suit_letter(c) );
}

//print a deck of cards using print_card_space
void print_hand(deck_t * hand){
  for(int i=0; i< (* hand).n_cards; i++){
      //printf("(*(((* hand).cards)[%d])).value= %u\n ",i, (*(((* hand).cards)[i])).value);
      //printf("(*(((* hand).cards)[%d])).suit= %d\n ",i, (*(((* hand).cards)[i])).suit);
      card_t * c = (*hand).cards[i];
      print_card_space(*c);
  }
    
}

//get a deck and a card. check if the card is in deck
int deck_contains(deck_t * d, card_t c){
  int x=0;
  //printf("(*d).n_cards=%d\n", (*d).n_cards);
  for(int i=0; i< (*d).n_cards; i++){
    if(( c.value == ((*((*d).cards)[i]).value )) && (c.suit == (*(((*d).cards[i]))).suit)){
      //printf("(*((*d).cards)[i]).value = %u\n",(*((*d).cards)[i]).value);
      //printf("(*((*d).cards)[i]).suit = %u\n",(*((*d).cards)[i]).suit);
      x++;
    } 
  }
  if(x>0){
    return 1;
  } 
  return 0;
}

//git card and deck. return how many times the card is in deck
int deck_contains_dou(deck_t * d, card_t c){
  int x=0;
  //printf("(*d).n_cards=%d\n", (*d).n_cards);
  for(int i=0; i< (*d).n_cards; i++){
    if(( c.value == ((*((*d).cards)[i]).value )) && (c.suit == (*(((*d).cards[i]))).suit)){
      //printf("(*((*d).cards)[i]).value = %u\n",(*((*d).cards)[i]).value);
      //printf("(*((*d).cards)[i]).suit = %u\n",(*((*d).cards)[i]).suit);
      printf("w %d\n",((*((*d).cards)[i]).value));
      printf("w %d\n",(*(((*d).cards[i]))).value);
      x++;
    } 
  }
  if(x>0){
    return x;
  } 
  return 0;
}

//shuffle the array of pointers of card
void shuffle(deck_t * d){
  //printf("(*((* d).cards)[0]).value= %u\n (*((* d).cards)[1]).value= %u\n (*((* d).cards)[2]).value=%u\n",(*((* d).cards)[0]).value,(*((* d).cards)[1]).value,(*((* d).cards)[2]).value);
  //printf("(*((* d).cards)[0]).suit= %u\n (*((* d).cards)[1]).suit= %u\n (*((* d).cards)[2]).suit=%u\n",(*((* d).cards)[0]).suit,(*((* d).cards)[1]).suit,(*((* d).cards)[2]).suit);
  card_t * temp;
    for(int i=0; i< (* d).n_cards; i++){  

      int r =  (rand() % ((* d).n_cards));
      //printf("r=%d\n",r);
       temp= ((* d).cards)[i]; 
      ((* d).cards)[i]=  ((* d).cards)[r];    
      ((* d).cards)[r] =  temp;

    }
    //printf("(*((* d).cards)[0]).value= %u\n (*((* d).cards)[1]).value= %u\n (*((* d).cards)[2]).value=%u\n",(*((* d).cards)[0]).value,(*((* d).cards)[1]).value,(*((* d).cards)[2]).value);
    //printf("(*((* d).cards)[0]).suit= %u\n (*((* d).cards)[1]).suit= %u\n (*((* d).cards)[2]).suit=%u\n",(*((* d).cards)[0]).suit,(*((* d).cards)[1]).suit,(*((* d).cards)[2]).suit);
    //printf("(*d).n_cards=%d\n", (*d).n_cards);

}

//assert if the every card in the deck is exactly one
void assert_full_deck(deck_t * d){
  for(int i=0; i< (* d).n_cards; i++){
    card_t c;
    c.value = (*((* d).cards)[i]).value;
    c.suit = (*((* d).cards)[i]).suit;
    assert_card_valid(c);
    printf("c.value= %u \n c.suit=%d\n",c.value, c.suit);
    int x = deck_contains_dou(d, c);
    printf("x=%d",x);
    assert(x==1);
  }
}


int main()
{
    deck_t d;
    d.n_cards=3;
    int a_1=7;
    int a_2=17;
    int a_3=27;

    card_t e_1 = card_from_num(a_1); 
    print_card(e_1);

    card_t e_2 = card_from_num(a_2); 
    print_card(e_2);

    card_t e_3 = card_from_num(a_3); 
    print_card(e_3);

    card_t * a = &e_1;
    card_t * b = &e_2;
    card_t * p = &e_3;
    card_t ** card_arr[]={a, b, p};
    (d.cards) = card_arr;

    //print_hand(&d);
    int k= deck_contains_dou(&d, e_1);
    printf("k=%d\n", k);
    shuffle(&d);
    //assert_full_deck(&d);
    
    return 0;
}
