
#include "eval.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int card_ptr_comp(const void * vp1, const void * vp2) {
  //printf("enter card_ptr_comp\n");
 const card_t * const * cp1=vp1;
 const card_t * const * cp2=vp2;
 int x = ((*(* cp1)).value - (*(* cp2)).value);
 int y = ((*(* cp1)).suit - (*(* cp2)).suit);
 if(x>0){
     return -1;
 }
 else if(x==0){
     if(y>0){
         return -1;
     }
     else if (y==0){
         return 0;
     }
     else{
          return 1;
     }    
 }
 else{
     return 1;
 }
}


suit_t flush_suit(deck_t * hand) {
  //printf("[0] = %d\n",((*((* hand).cards)[0]).suit ) );
  if((* hand).n_cards <1){
    return 4;
  }
  int x=0;
  int j;
  for(j=0; j<4; j++){
    for (int i=0; i<(* hand).n_cards; i++){
        if(((*((* hand).cards)[i]).suit )== j){
            x++;//add one if there is a suit j
        }
    }
    //if the count is >=5
    if(x>=5){
    return j;
    }
    else{
        x=0;
    }  
  }
return 4;
}

//returns the largest number. to find largest n ofa  kind
unsigned get_largest_element(unsigned * arrr, size_t n) {
  //printf("enter get_largest_element\n")
   unsigned large;
   large= ((arrr)[0]);
   for (int i=1; i<n; i++){
       //printf("arrr[%d]=%u\n",i,arrr[i]);
       if (arrr[i]> large){
        large = arrr[i];
       }       
    }
    return large;
}

//You will write this function in Course 4.
//For now, we leave a prototype (and provide our
//implementation in eval-c4.o) so that the
//other functions we have provided can make
//use of get_match_counts.
unsigned * get_match_counts(deck_t * hand) ;

//idx of a element with is equal to n_of_akind
size_t get_match_index(unsigned * match_counts, size_t n,unsigned n_of_akind){
  for(int i=0; i<n; i++){
    if(match_counts[i]==n_of_akind){
      //printf("match_counts[i]= %u", match_counts[i]);
      return i;
    }
  }
  return -1;//abort?
}

//lowest idx with match counts >1 & value not same as value of match_idx.
ssize_t  find_secondary_pair(deck_t * hand, unsigned * match_counts,size_t match_idx) {
  //printf("enter find_secondary_pair \n");
    for (int i=0; i<(* hand).n_cards; i++){
      //printf("(match_counts[i])=%u\n", (match_counts[i]) );
      //printf("(*((* hand).cards)[i]).value )= %u,  ((*((* hand).cards)[match_idx]).value )=%u\n",((*((* hand).cards)[i]).value ), ((*((* hand).cards)[match_idx]).value ));
        if((((*((* hand).cards)[i]).value )!= ((*((* hand).cards)[match_idx]).value )) &&\
         (match_counts[i])>1){ 
            //printf("entered if statemant of find_secondary pair at %d\n",i);       
           return i;
        }       
    }
    //printf("no secondary pair\n");
    return -1;
}

//straight flush or straight of length n at the given index
int is_n_length_straight_at(deck_t * hand, size_t index, suit_t fs, int n){
  int j=0;
  unsigned * match_counts = get_match_counts(hand);
  for(int i=index; (i< (((* hand).n_cards)-1) &&  (index+n) <=((* hand).n_cards) ); i++){
    //printf("for count %d\n",i);
    if(((*((* hand).cards)[(i+1)]).value ) == ((*((* hand).cards)[i]).value )){
      //printf("first \n");
      continue;
    }
    if(((*((* hand).cards)[(i+1)]).value ) == (((*((* hand).cards)[i]).value )-1)){
      j=j+1;
    }
    if(((*((* hand).cards)[(i+1)]).value ) != (((*((* hand).cards)[i]).value )-1)){
      break;
    }
  }
  //printf("j count in is %d straignt is %d\n",n,j);
  if(j>=(n-1)){
    if(fs == 4){
      return 1;      
    }
    else{
      j=0;
      //check straight flush
      for(int i=index;i< ((* hand).n_cards); i++ ){
        //printf("for count1 %d\n",i);
        if(i==index){
          if((*((* hand).cards)[(i)]).suit == fs){
            j++;
            continue;
          }
          else{
            return 0;
          }
        }
        if((*((* hand).cards)[(i)]).value == (*((* hand).cards)[(index)]).value){
          continue;
        }
        if(match_counts[i] ==1){
          if((*((* hand).cards)[(i)]).suit == fs){
            j++;
            continue;
          }
          else{
            break;
          }         
        }
        if(match_counts[i] ==2){
          //printf("has match count 2\n");
          if(((*((* hand).cards)[(i)]).suit == fs) || \
          ((*((* hand).cards)[(i+1)]).suit == fs) ){
            j++;
            i++;
            //printf("\ni is added as %d\n", i);
            continue;
          }
          else{
            break;
          }         
        }
        if(match_counts[i] ==3){
          if(((*((* hand).cards)[(i)]).suit == fs) || \
          ((*((* hand).cards)[(i+1)]).suit == fs) || \
          ((*((* hand).cards)[(i+2)]).suit == fs) ){
            j++;
            i=i+2;
            continue;
          }
          else{
            break;
          }
        }
      }
      if(j>=n){
        //printf("j count in is n straignt flush is %d\n",j);
        return 1;
      }
    }
  }
  return 0;
}


//ace low straight at idx index of suit fs
int is_ace_low_straight_at(deck_t * hand, size_t index, suit_t fs){
    //printf("enter ace low straight\n");
    for (int i=1; i<4; i++){
      if(((*((* hand).cards)[i]).value )==5){
    //printf("true1\n");
    //if there is for lenght straight sta
    if((is_n_length_straight_at(hand, i, fs, 4) ==1) ){
      //printf("true2\n");
      //printf("\n((*((* hand).cards)[0]).value = %d \n", ((*((* hand).cards)[0]).value));
      if(((*((* hand).cards)[index]).value )==14){
        //printf("true3\n");
        if(fs !=4){
          if(((*((* hand).cards)[index]).suit )==fs){
            //printf("true4\n");
            //printf("\n is ace low straight flush at index %d\n\n", index);
            return 1;
          }
        }
        else{
          //printf("\n is ace low straight at index %d\n\n", index);
            return 1;
        }        
      }
    }
  }
}  
  //printf("\n is not ace low straight at index %d\n\n", index);
  return 0;
}

//check straignt at idx for suit ds
int is_straight_at(deck_t * hand, size_t index, suit_t fs){
    //printf("enter is straight at\n");
  if(index == 0){
    if(is_ace_low_straight_at(hand, 0,fs)==1){
      //printf("is ace low straight at index 0 and fs %d",fs);
      return -1;
    }
  }
  if(is_n_length_straight_at(hand, index, fs, 5)==1){
    //printf("is straight at index %zu and fs %d",index,fs);
    return 1;
  }
  //printf("is s\n");
  return 0;
}


//form cards for n of a kind
hand_eval_t build_hand_from_match(deck_t * hand,\
unsigned n,hand_ranking_t what,size_t idx){

  //printf("enter build_hand_from_match\n");
  //printf("what is %d\n", what);
  hand_eval_t h;
  h.ranking=what;

  //nothing hand_eval_t
  hand_eval_t hand_0;
  hand_0.ranking= what;
  (hand_0.cards)[0]= ((hand)->cards)[0];
  (hand_0.cards)[1]= ((hand)->cards)[1];
  (hand_0.cards)[2]= ((hand)->cards)[2];
  (hand_0.cards)[3]= ((hand)->cards)[3];
  (hand_0.cards)[4]= ((hand)->cards)[4];
  //printf("\nn is %d\n",n);

  if(n<=1 ){
    return hand_0;
  }
  int j=0;
  for(int i =0;j<n ; i++){
    //printf("for count %d\n",i);
    (h.cards)[i]= ((hand)->cards)[idx+i];
    //printf("cards[%d].value=%u\n", i,(h.cards)[i]->value );
    //printf("for count %d j is %d\n",i,j);
    j++;
  }
  if(n==2){
    j=0;
    for(int i =0;i< ((* hand).n_cards); i++){
       // printf("for count1 in n is 2 is %d\n",i);
        if(((((hand)->cards)[i])->value != (((hand)->cards)[idx])->value)){
            (h.cards)[2+j]= ((hand)->cards)[i];
            //printf("cards[%d].value=%u\n",2+j, (h.cards)[2+j]->value );
            j++;
        }
       if(j==3){
        break;
       }
    }
  }
  if(n==3){
    j=0;
    for(int i =0;i< ((* hand).n_cards); i++){
        if(((((hand)->cards)[i])->value != (((hand)->cards)[idx])->value)){
            (h.cards)[3+j]= ((hand)->cards)[i];
            //printf("cards[%d].value=%u\n",3+j, (h.cards)[3+j]->value );
            j++;
        }
        if(j==2){
            break;
        }        
    }
  }
  if(n==4){
    for(int i =0;i< ((* hand).n_cards); i++){
        if(((((hand)->cards)[i])->value != (((hand)->cards)[idx])->value)){
            (h.cards)[4]= ((hand)->cards)[i];
            break;
        }
    }
  }

  //printf("done");
  return h; 
}


int compare_hands(deck_t * hand1, deck_t * hand2) {
   //printf("enter compare_hands\n");
    qsort(hand1->cards, hand1->n_cards, sizeof(card_t), card_ptr_comp);
    //printf("sorted card\n");
   // print_hand(hand1);
    qsort(hand2->cards, hand2->n_cards, sizeof(card_t), card_ptr_comp);
    //printf("sorted cards\n");
    //print_hand(hand2); 
    //printf("assigned c_1 and c_2\n");
    hand_eval_t A = evaluate_hand(hand1);


    hand_eval_t B =evaluate_hand(hand2);

    if (A.ranking != B.ranking){
        if(A.ranking < B.ranking){
            return 1;//rank A is greater than B
        }
        else{//rank B is greater than A
            return -1;
        }
    }
    else{
        for(int i=0; i<5;i++){
          //printf("for i count %d\n",i);
            if((*((A.cards)[i])).value > (*((B.cards)[i])).value){
              //printf("A is big at %d\n",i);
                return 1;
            }
            if((*((A.cards)[i])).value < (*((B.cards)[i])).value){
              //printf("A is big at %d\n",i);
                return -1;
            }
            if((*((A.cards)[i])).value == (*((B.cards)[i])).value){
                continue;
               //printf("i=%d",i);
            }
        }       
    return 0;   
    }
}


// We provide the below functions.  You do NOT need to modify them
// In fact, you should not modify them!


//This function copies a straight starting at index "ind" from deck "from".
//This copies "count" cards (typically 5).
//into the card array "to"
//if "fs" is NUM_SUITS, then suits are ignored.
//if "fs" is any other value, a straight flush (of that suit) is copied.
void copy_straight(card_t ** to, deck_t *from, size_t ind, suit_t fs, size_t count) {
  //printf("enter copy_straight\n");
  assert(fs == NUM_SUITS || from->cards[ind]->suit == fs);
  unsigned nextv = from->cards[ind]->value;
  size_t to_ind = 0;
  while (count > 0) {
    assert(ind < from->n_cards);
    assert(nextv >= 2);
    assert(to_ind <5);
    if (from->cards[ind]->value == nextv &&
        (fs == NUM_SUITS || from->cards[ind]->suit == fs)){
      to[to_ind] = from->cards[ind];
      to_ind++;
      count--;
      nextv--;
    }
    ind++;
  }
}


//This looks for a straight (or straight flush if "fs" is not NUM_SUITS)
// in "hand".  It calls the student's is_straight_at for each possible
// index to do the work of detecting the straight.
// If one is found, copy_straight is used to copy the cards into
// "ans".
int find_straight(deck_t * hand, suit_t fs, hand_eval_t * ans) {
  //printf("enter find_straight\n");
  if (hand->n_cards < 5){
    return 0;
  }
  for(size_t i = 0; i <= hand->n_cards -5; i++) {
    int x = is_straight_at(hand, i, fs);
    
    if (x != 0){
      //printf("is straight at index %ld and suit %d", i,fs);
      if (x < 0) { //ace low straight
        assert(hand->cards[i]->value == VALUE_ACE &&
               (fs == NUM_SUITS || hand->cards[i]->suit == fs));
        ans->cards[4] = hand->cards[i];
        size_t cpind = i+1;
        while(hand->cards[cpind]->value != 5 ||
              !(fs==NUM_SUITS || hand->cards[cpind]->suit ==fs)){
          cpind++;
          assert(cpind < hand->n_cards);
        }
        copy_straight(ans->cards, hand, cpind, fs,4) ;
      }
      else {
        copy_straight(ans->cards, hand, i, fs,5);
      }
      return 1;
    }
  }
  return 0;
}


//This function puts all the hand evaluation logic together.
//This function is longer than we generally like to make functions,
//and is thus not so great for readability :(
hand_eval_t evaluate_hand(deck_t * hand) {
  //printf("enter evaluate_hand\n");
  suit_t fs = flush_suit(hand);
  //printf("suit_f fs = %d\n",fs);
  hand_eval_t ans;
  if (fs != NUM_SUITS) {
    //printf("fs is not 4\n");
    if(find_straight(hand, fs, &ans)) {
      //printf("straight flush by fs =%d \n",fs);
      ans.ranking = STRAIGHT_FLUSH;
      return ans;
    }
  }
  //printf("into get_match_Counts\n");
  unsigned * match_counts = get_match_counts(hand);
  //printf("crossed get_match_Counts\n");
  unsigned n_of_a_kind = get_largest_element(match_counts, hand->n_cards);
  //printf("n of a kind is %u\n", n_of_a_kind);
  assert(n_of_a_kind <= 4);
  size_t match_idx = get_match_index(match_counts, hand->n_cards, n_of_a_kind);
  //printf("match index is %ld\n", match_idx);
  ssize_t other_pair_idx = find_secondary_pair(hand, match_counts, match_idx);
  //printf("other pair idx  is %ld\n", other_pair_idx);
  free(match_counts);
  //printf("other pair idx  is %ld\n", other_pair_idx);
  if (n_of_a_kind == 4) { //4 of a kind
    return build_hand_from_match(hand, 4, FOUR_OF_A_KIND, match_idx);
  }
  else if (n_of_a_kind == 3 && other_pair_idx >= 0) {     //full house
    ans = build_hand_from_match(hand, 3, FULL_HOUSE, match_idx);
    ans.cards[3] = hand->cards[other_pair_idx];
    ans.cards[4] = hand->cards[other_pair_idx+1];
    return ans;
  }
  else if(fs != NUM_SUITS) { //flush
    ans.ranking = FLUSH;
    size_t copy_idx = 0;
    for(size_t i = 0; i < hand->n_cards;i++) {
      if (hand->cards[i]->suit == fs){
        ans.cards[copy_idx] = hand->cards[i];
        copy_idx++;
        if (copy_idx >=5){
          break;
        }
      }
    }
    return ans;
  }
  else if(find_straight(hand,NUM_SUITS, &ans)) {     //straight
    ans.ranking = STRAIGHT;
    return ans;
  }
  else if (n_of_a_kind == 3) { //3 of a kind
    return build_hand_from_match(hand, 3, THREE_OF_A_KIND, match_idx);
  }
  else if (other_pair_idx >=0) {     //two pair
    assert(n_of_a_kind ==2);
    ans = build_hand_from_match(hand, 2, TWO_PAIR, match_idx);
    ans.cards[2] = hand->cards[other_pair_idx];
    ans.cards[3] = hand->cards[other_pair_idx + 1];
    if (match_idx > 0) {
      ans.cards[4] = hand->cards[0];
    }
    else if (other_pair_idx > 2) {  //if match_idx is 0, first pair is in 01
      //if other_pair_idx > 2, then, e.g. A A K Q Q
      ans.cards[4] = hand->cards[2];
    }
    else {       //e.g., A A K K Q
      ans.cards[4] = hand->cards[4];
    }
    return ans;
  }
  else if (n_of_a_kind == 2) {
    return build_hand_from_match(hand, 2, PAIR, match_idx);
  }
  return build_hand_from_match(hand, 0, NOTHING, 0);
}
