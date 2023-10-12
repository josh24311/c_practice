/*
Project    : Pick Red Game in C language
Author     : josh24311
Date       : 20231012
Version    : 1.0.0
---
Description:
A poker game for 4 people to play.The one has highest points wins the game.


---
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <assert.h>
#include <locale.h>
#include <wchar.h>

#define minCardNum  0
#define totalCardNum  52
#define totalSuitNum 4
#define numInSuit 13
#define playerNum  4
#define beginTableSize  4
#define maxHold  6
#define maxAteSize 24

wchar_t *clubs = L"\u2667";
wchar_t *diamonds = L"\u2666";
wchar_t *hearts = L"\u2665";
wchar_t *spades = L"\u2664";

struct pokerCards{
  char   color;//顏色 B: 黑色 , R: 紅色
  char   num;//數字
  wchar_t* suit;//花色
  int    point;//分數
  int    prior;
};
struct playerCard{
  int holdSize;
  int ateSize;
  struct pokerCards holds[maxHold];
  struct pokerCards ate[maxAteSize];
};


/*
D5 card[17] eat H5 card[30] get 70
*/
int cmp(const void *a, const void *b){
  struct pokerCards *cardA = (struct pokerCards *)a;
  struct pokerCards *cardB = (struct pokerCards *)b;
  if(cardA->point == cardB->point){
    return cardA->prior - cardB->prior;
  }
  else{
    return cardA->point - cardB->point;  
  }
  
}
int randint(int n) {
  if ((n - 1) == RAND_MAX) {
    return rand();
  } else {
    /* 計算可以被整除的長度 */
    long end = RAND_MAX / n;
    assert (end > 0L);
    end *= n;

    /* 將尾端會造成偏差的幾個亂數去除，
       若產生的亂數超過 limit，則將其捨去 */
    int r;
    while ((r = rand()) >= end);

    return r % n;
  }
}
void setCardsState(struct pokerCards* cards){
  for(int i = 0; i < totalSuitNum; i++){
    for(int j = 0; j < numInSuit ; j++){
      if(i == 0){
        //cards[i*numInSuit+j].suit = 'C';
        cards[i*numInSuit+j].suit = clubs;
        cards[i*numInSuit+j].color = 'B';
      }
      else if(i == 1){
        //cards[i*numInSuit+j].suit = 'D'; 
        cards[i*numInSuit+j].suit = diamonds; 
        cards[i*numInSuit+j].color = 'R';
      }
      else if(i == 2){
        //cards[i*numInSuit+j].suit = 'H'; 
        cards[i*numInSuit+j].suit = hearts; 
        cards[i*numInSuit+j].color = 'R';
      }
      else if(i == 3){
        //cards[i*numInSuit+j].suit = 'S'; 
        cards[i*numInSuit+j].suit = spades; 
        cards[i*numInSuit+j].color = 'B';
      }
      if(j < 9 && j > 0){
        cards[i*numInSuit+j].num = (j+1)+'0';
      }
      else{
        if(j == 9){
          cards[i*numInSuit+j].num = 'T';
        }
        else if (j == 10){
          cards[i*numInSuit+j].num = 'J';
        }
        else if (j == 11){
          cards[i*numInSuit+j].num = 'Q';
        }
        else if(j == 12){
          cards[i*numInSuit+j].num = 'K';
        }
        else if (j == 0){
          cards[i*numInSuit+j].num = 'A';
        }
      }  
    }
  }
  //set points
  for(int i = 0; i < totalCardNum; i++){
    cards[i].point = 0;
  }
  
  for(int i = 0; i < totalCardNum; i++){
    if( cards[i].color == 'R'){
      if(cards[i].num == 'A'){
        cards[i].point = 20;      
      }
      else if (cards[i].num >= '2' && cards[i].num <= '8'){
        cards[i].point  = cards[i].num - '0';
      }
      else if (cards[i].num == '9' || cards[i].num == 'T' || cards[i].num == 'J' || cards[i].num == 'Q' || cards[i].num == 'K'){
        cards[i].point  = 10;
      }
    }
    if(i == 39){
      cards[i].point = 30;
    }
    if(i == 0){
      cards[i].point = 40;
    }
    
  }
  // set prior
  for(int i = 0; i < totalCardNum; i++){
    cards[i].prior = 40;//initial all set to 40
  }
  
  for(int i = 1; i <= 7; i++){
    cards[i].prior = 9-i;// num 2 ~ num 8
  }
  for(int i = 40; i <= 46; i++){
    cards[i].prior = 48-i;// num 2 ~ num 8
  }
  for(int i = 9; i <= 12; i++){
    cards[i].prior = 10;// num T ~ num K
  }
  for(int i = 48; i <= 51; i++){
    cards[i].prior = 10;// num T ~ num K
  }

}
        
void initialGame(struct pokerCards* cards, struct pokerCards** cTable, struct pokerCards** cBank, struct playerCard** player, int* tableSize){
  int cardI[totalCardNum];
  int hs[totalCardNum] = {0};
  int now = 0;
  while(now < totalCardNum){
    int r = randint(totalCardNum - minCardNum + 1) + minCardNum;//random function from 0~51
    if(hs[r] == 0){
      cardI[now] = r;
      hs[r] = 1;
      now++;
    }
  }
  /*
  for(int i = 0 ; i < totalCardNum; i++){
    printf("%d\t %d\n",i,cardI[i]);
  }*/

  for(int i = 0; i < playerNum; i++){// 0,1,2,3
    (*player)[i].holdSize = 6;     // set holdSize as 6
    (*player)[i].ateSize = 0;      // set ateSize as 0
    
    for(int j = 0; j < maxHold; j++){// 0,1,2,3,4,5
      (*player)[i].holds[j] = cards[cardI[i*maxHold+j]];
    }
    for(int k = 0; k < maxAteSize; k++){
      (*player)[i].ate[k].point = -1;
    }
    
    qsort((*player)[i].holds, (*player)[i].holdSize, sizeof(struct pokerCards), cmp);// sort player holds cards with point
  }
  
  
  /*Initial cTable Status*/
  *tableSize = beginTableSize;
  int tmp = playerNum*maxHold;
  for(int i = 0; i < beginTableSize; i++){
    (*cTable)[i] = cards[cardI[i+playerNum*maxHold]];
  }
  qsort((*cTable), beginTableSize, sizeof(struct pokerCards), cmp);// sort table with point
  
  for(int i = 0; i < (totalCardNum-tmp)-beginTableSize; i++){//initial with 24 cards
    (*cBank)[i] = cards[cardI[i+tmp+beginTableSize]];
  }
  
}

void printPlayerHold(struct pokerCards* cards, struct playerCard* player){
  
  for(int i = 0; i < playerNum; i++){// 0,1,2,3
    printf("Player %d hold [\t",i);
    for(int j = 0; j < player[i].holdSize; j++){// 0,1,2,3,4,5
      printf("%ls%c\t",player[i].holds[j].suit, player[i].holds[j].num);
    }
    printf("]\n");
  }
  printf("\n");
}

void printPlayerAte(struct pokerCards* cards, struct playerCard* player){
  for(int i = 0; i < playerNum; i++){// 0,1,2,3
    printf("Player %d ate [\t",i);
    for(int j = 0; j < player[i].ateSize; j++){// up to 24(maxAteSize) , store in player[i].ateSize
      if(player[i].ate[j].point != -1){
        printf("%ls%c\t",player[i].ate[j].suit, player[i].ate[j].num);
      } 
    }
    printf("]\n\n");
  }
  printf("\n");
}

void printTable(struct pokerCards* cards, struct pokerCards* cTable, int* tableSize){
  printf("card Table : \n");
  for(int i = 0; i < *tableSize; i++){
    printf("%ls%c\t", cTable[i].suit,cTable[i].num);
  }
  printf("\n");
}

void printBank(struct pokerCards* cards, struct pokerCards* cBank, int* bankSize){
  printf("\ncard Bank : \n");
  for(int i = *bankSize-1; i >= 0; i--){
    printf("%ls%c\n",cBank[i].suit,cBank[i].num);
  }
}

void printCardSetting(struct pokerCards* cards){
  for(int i = 0; i < totalCardNum; i++){
  printf("card %d\t:\t%ls%c , with color %c, point:\t%d\t, prior:\t%d\n", i, cards[i].suit, cards[i].num,cards[i].color,cards[i].point,cards[i].prior);
  }
  printf("\n");
}

bool cardGoEat(struct pokerCards* cards, int i, int j){
  // i in hand , j on table
  
  if((i == 0  || i == 13 || i == 26 || i == 39) && (cards[j].color == 'R' && cards[j].num == '9')) return true;
  if((i == 0  || i == 13 || i == 26 || i == 39) && (cards[j].color == 'B' && cards[j].num == '9')) return true;
  if((i == 1  || i == 14 || i == 27 || i == 40) && (cards[j].color == 'R' && cards[j].num == '8')) return true;
  if((i == 1  || i == 14 || i == 27 || i == 40) && (cards[j].color == 'B' && cards[j].num == '8')) return true;
  if((i == 2  || i == 15 || i == 28 || i == 41) && (cards[j].color == 'R' && cards[j].num == '7')) return true;
  if((i == 2  || i == 15 || i == 28 || i == 41) && (cards[j].color == 'B' && cards[j].num == '7')) return true;
  if((i == 3  || i == 16 || i == 29 || i == 42) && (cards[j].color == 'R' && cards[j].num == '6')) return true;
  if((i == 3  || i == 16 || i == 29 || i == 42) && (cards[j].color == 'B' && cards[j].num == '6')) return true;
  if((i == 4  || i == 17 || i == 30 || i == 43) && (cards[j].color == 'R' && cards[j].num == '5')) return true;
  if((i == 4  || i == 17 || i == 30 || i == 43) && (cards[j].color == 'B' && cards[j].num == '5')) return true;
  if((i == 5  || i == 18 || i == 31 || i == 44) && (cards[j].color == 'R' && cards[j].num == '4')) return true;
  if((i == 5  || i == 18 || i == 31 || i == 44) && (cards[j].color == 'B' && cards[j].num == '4')) return true;
  if((i == 6  || i == 19 || i == 32 || i == 45) && (cards[j].color == 'R' && cards[j].num == '3')) return true;
  if((i == 6  || i == 19 || i == 32 || i == 45) && (cards[j].color == 'B' && cards[j].num == '3')) return true;
  if((i == 7  || i == 20 || i == 33 || i == 46) && (cards[j].color == 'R' && cards[j].num == '2')) return true;
  if((i == 7  || i == 20 || i == 33 || i == 46) && (cards[j].color == 'B' && cards[j].num == '2')) return true;
  if((i == 8  || i == 21 || i == 34 || i == 47) && (cards[j].color == 'R' && cards[j].num == 'A')) return true;
  if((i == 8  || i == 21 || i == 34 || i == 47) && (cards[j].color == 'B' && cards[j].num == 'A')) return true;
  if((i == 9  || i == 22 || i == 35 || i == 48) && (cards[j].color == 'R' && cards[j].num == 'T')) return true;
  if((i == 9  || i == 22 || i == 35 || i == 48) && (cards[j].color == 'B' && cards[j].num == 'T')) return true;
  if((i == 10 || i == 23 || i == 36 || i == 49) && (cards[j].color == 'R' && cards[j].num == 'J')) return true;
  if((i == 10 || i == 23 || i == 36 || i == 49) && (cards[j].color == 'B' && cards[j].num == 'J')) return true;
  if((i == 11 || i == 24 || i == 37 || i == 50) && (cards[j].color == 'R' && cards[j].num == 'Q')) return true;
  if((i == 11 || i == 24 || i == 37 || i == 50) && (cards[j].color == 'B' && cards[j].num == 'Q')) return true;
  if((i == 12 || i == 25 || i == 38 || i == 51) && (cards[j].color == 'R' && cards[j].num == 'K')) return true;
  if((i == 12 || i == 25 || i == 38 || i == 51) && (cards[j].color == 'B' && cards[j].num == 'K')) return true;
  
  return false;
  
}

int findTableIdFromCards(struct pokerCards* cards, struct pokerCards** cTable, const int idx){
  int w = -1;
  for(w = 0; w < totalCardNum; w++){
    if((*cTable)[idx].suit == cards[w].suit && (*cTable)[idx].num == cards[w].num){
      break;
    }
  }
  return w;
}

int findHoldIdFromCards(struct pokerCards* cards, struct playerCard** player, const int pNum, const int idx){
  int q = -1;
  for(q = 0; q < totalCardNum; q++){
    if((*player)[pNum].holds[idx].suit == cards[q].suit && (*player)[pNum].holds[idx].num == cards[q].num){
      break;// found index q in cards
    }
  }
  return q;
}

int findBankIdFromCards(struct pokerCards* cards, struct pokerCards** cBank, int* bankSize){
  int w = -1;
  for(w = 0; w < totalCardNum; w++){
    if((*cBank)[(*bankSize)-1].suit == cards[w].suit && (*cBank)[(*bankSize)-1].num == cards[w].num){
      break;
    }
  }
  return w;
}


bool strategy(struct pokerCards* cards, 
struct playerCard** player,  
struct pokerCards** cTable, 
struct pokerCards** cBank, 
int* tableSize, 
int* bankSize,
const int j,
int* hidx,
int* tidx){
  int i = 0, q = 0, k = 0, w = 0;
  bool canEat;
  for(i = (*player)[j].holdSize-1; i >= 0; i--){
    q = findHoldIdFromCards(cards, player, j,i);
    
    for(k = (*tableSize)-1; k >= 0; k--){
      canEat = false;
      w = findTableIdFromCards(cards, cTable, k);
      
      canEat = cardGoEat(cards, q, w);// 手牌[i] 是否能吃 table [k]
      if(canEat){
        *hidx = i;
        *tidx = k;
        return true;
      }
      
    }
  }
  return false;
}

void throwCards(struct pokerCards* cards, 
struct playerCard** player,  
struct pokerCards** cTable, 
struct pokerCards** cBank, 
int* tableSize, 
int* bankSize,
int j){
  /*
  四種情況:
  1. 手牌吃桌面 翻牌吃桌面
  2. 手牌吃桌面 翻牌不能吃
  3. 手牌不能吃 翻牌吃桌面
  4. 手牌不能吃 翻牌不能吃
  */
  int hidx = -1;
  int tidx = -1;
  bool hasEaten = strategy(cards, player, cTable, cBank, tableSize, bankSize, j, &hidx, &tidx);
  if(hasEaten){//手牌吃桌面
    bool bankEatTable = false;
    // hold to ate
    (*player)[j].ate[(*player)[j].ateSize] = (*player)[j].holds[hidx];
    (*player)[j].ateSize++;
    for(int i = hidx; i < (*player)[j].holdSize-1; i++){
      (*player)[j].holds[i] = (*player)[j].holds[i+1];
    }
    (*player)[j].holdSize--;

    // cTable to ate
    (*player)[j].ate[(*player)[j].ateSize] = (*cTable)[tidx];
    (*player)[j].ateSize++;
    // move items in table
    for(int i = tidx; i < (*tableSize)-1; i++){
      (*cTable)[i] = (*cTable)[i+1];
    }
    (*tableSize)--;

    //bank to cTable 翻牌是否能吃
    int b = findBankIdFromCards(cards, cBank, bankSize);//get bank top id in cards
    for(int i = (*tableSize)-1; i >= 0; i--){
      int w = findTableIdFromCards(cards, cTable, i);
      bankEatTable = cardGoEat(cards, b, w);// bank top 是否可以吃table[i]
      if(bankEatTable){// 翻牌可以吃
        // bank to ate
        (*player)[j].ate[(*player)[j].ateSize] = (*cBank)[*bankSize-1];
        (*player)[j].ateSize++;
        (*bankSize)--;
        // cTable to ate
        (*player)[j].ate[(*player)[j].ateSize] = (*cTable)[i];
        (*player)[j].ateSize++;
        // move items in table
        for(int k = i; k < (*tableSize)-1; k++){
          (*cTable)[k] = (*cTable)[k+1];
        }
        (*tableSize)--;
        break;
      } 
    }
    if(!bankEatTable){//翻牌不能吃 
      (*cTable)[*tableSize] = (*cBank)[*bankSize-1];
      (*tableSize)++;
      qsort((*cTable), (*tableSize), sizeof(struct pokerCards), cmp);// sort table with point
      (*bankSize)--;
    }
    
  }
  else{//手牌沒法吃桌面
    bool bankEatTable = false;
    (*cTable)[*tableSize] = (*player)[j].holds[0];//丟prior最小者到table
    (*tableSize)++;
    qsort((*cTable), (*tableSize), sizeof(struct pokerCards), cmp);// sort table with point
    for(int i = 0; i < (*player)[j].holdSize-1; i++){
      (*player)[j].holds[i] = (*player)[j].holds[i+1];
    }
    (*player)[j].holdSize--;


    // 翻牌
    int b = findBankIdFromCards(cards, cBank, bankSize);//get bank top id in cards
    for(int i = (*tableSize)-1; i >= 0; i--){
      int w = findTableIdFromCards(cards, cTable, i);
      bankEatTable = cardGoEat(cards, b, w);// bank top 是否可以吃table[i]
      if(bankEatTable){// 翻牌可以吃
        // bank to ate
        (*player)[j].ate[(*player)[j].ateSize] = (*cBank)[*bankSize-1];
        (*player)[j].ateSize++;
        (*bankSize)--;
        // cTable to ate
        (*player)[j].ate[(*player)[j].ateSize] = (*cTable)[i];
        (*player)[j].ateSize++;
        // move items in table
        for(int k = i; k < (*tableSize)-1; k++){
          (*cTable)[k] = (*cTable)[k+1];
        }
        (*tableSize)--;
        break;
      } 
    }
    if(!bankEatTable){//翻牌不能吃 
      (*cTable)[*tableSize] = (*cBank)[*bankSize-1];
      (*tableSize)++;
      qsort((*cTable), (*tableSize), sizeof(struct pokerCards), cmp);// sort table with point
      (*bankSize)--;
    }
  }

}

void game(struct pokerCards* cards, 
struct playerCard** player,  
struct pokerCards** cTable, 
struct pokerCards** cBank, 
int* tableSize, 
int* bankSize){
  /*
  throwCards(cards, player, cTable, cBank, tableSize, bankSize, 0);
  throwCards(cards, player, cTable, cBank, tableSize, bankSize, 1);
  throwCards(cards, player, cTable, cBank, tableSize, bankSize, 2);
  throwCards(cards, player, cTable, cBank, tableSize, bankSize, 3);
  */
  int j = 0;
  for(int i = 0 ; i < 6; i++){
    for(j = 0; j < playerNum; j++){
      throwCards(cards, player, cTable, cBank, tableSize, bankSize, j);
      
    }
    /*
    if(i == 4){
      printf("i = 4 ==================\n");
      printPlayerHold(cards,*player);
      printTable(cards,*cTable,tableSize);
      printBank(cards, *cBank,bankSize);
      printf("i = 4 ==================\n");
    }
    */
  }
  printf("========== GAME OVER ========== \n");
}

void printScore(struct pokerCards* cards, struct playerCard* player){
  bool hasDB = false;
  int dbFive[4] = {0};
  int score[playerNum] = {0};
  

  for(int i = 0; i < playerNum; i++){
    for(int j = 0; j < player[i].ateSize-1; j+=2){
      if(player[i].ate[j].num == '5'){//確認是否有人過紅5
        if(player[i].ate[j].color == 'R' && player[i].ate[j+1].color == 'R'){
          hasDB = true;
          dbFive[i] = 1;
        }
      }
    }
  }

  for(int i = 0; i < playerNum; i++){
    for(int j = 0; j < player[i].ateSize-1; j+=2){
      score[i] += player[i].ate[j].point;
      score[i] += player[i].ate[j+1].point;    
    }
  }

  for(int i = 0; i < playerNum; i++){
    if(hasDB){
      if(dbFive[i] == 1){
        printf("Player %d got %d points\t",i,score[i]+60);  
        printf("====== Player %d got double red five! ======\n",i);
      }
      else{
        printf("Player %d got %d-20 = %d points\n",i,score[i],score[i]-20);  
      }
    }
    else{
      printf("Player %d got %d points\n",i,score[i]);
    }
  }
  
}

bool checkUnfair(struct pokerCards* cards, struct pokerCards* cTable, struct pokerCards* cBank, struct playerCard* player, int tableSize, int bankSize){
  int red5 = 0,blk5 = 0;
  int tn = 0, jn = 0, qn = 0, kn = 0;
  for(int i = 0; i < tableSize; i++){
    if(cTable[i].color == 'R' && cTable[i].num == '5'){
      red5++;
    }
    if(cTable[i].color == 'B' && cTable[i].num == '5'){
      blk5++;
    }
    if(cTable[i].num == 'T'){
      tn++;
    }
    if(cTable[i].num == 'J'){
      jn++;
    }
    if(cTable[i].num == 'Q'){
      qn++;
    }
    if(cTable[i].num == 'K'){
      kn++;
    }
    
  }
  /*海底牌存在兩張紅5 或者 兩張黑5*/
  if(red5 == 2 || blk5 == 2){
    printf("There are 2 red fives or 2 black fives on table , go shuffle\n");
    return true;
  }
  /*海底牌存在紅5 黑5 個數加起來3張*/
  if(red5+blk5 == 3){
    printf("There are 3 fives on table, go shuffle\n");
    return true;
  }
  /*10 J Q K 各三張*/
  if(tn == 3 || jn == 3 || qn == 3 || kn == 3){
    printf("There are 3 tens|Jacks|Queens|Kings on table, go shuffle\n");
    return true;
  }
  /*四張海底牌重複*/
  int dupli = 1;
  for(int i = 0; i < tableSize-1; i++){
    if(cTable[i].num == cTable[i+1].num){
      dupli*=1;
    }
    else{
      dupli*=0;
      break;
    }
  }
  if(dupli == 1){
    printf("\n");
    return true;
  }
  /*牌庫最後一張牌為紅5且海底牌有一張紅5*/
  if(cBank[0].color == 'R' && cBank[0].num == '5' && red5 == 1){
    printf("There are a red five on table , and a red five at the bottom of deck, go shuffle\n");
    return true;
  }
  for(int i = 0; i < playerNum; i++){
    int iniScore = 0;
    for(int j = 0; j < player[i].holdSize; j++){
      iniScore += player[i].holds[j].point;
    }
    if(iniScore == 0){
      printf("Player %d got initial Score 0 , go shuffle\n",i);
      return true;
    }
  }
  
  return false;
}

int main(void) {
  setlocale(LC_ALL, "");
  /*
  printf("%ls\n", clubs);
  printf("%ls\n", diamonds);
  printf("%ls\n", hearts);
  printf("%ls\n", spades);
  */
  srand( time(NULL) );
  struct pokerCards* cards = malloc(sizeof(struct pokerCards)*52);
  setCardsState(cards);
  //printCardSetting(cards);
  
  struct playerCard* player = malloc(sizeof(struct playerCard)*playerNum);
  int tableSize = beginTableSize;
  struct pokerCards* cTable = malloc(sizeof(struct pokerCards)*24);//could change
  int bankSize = 24;
  struct pokerCards* cBank = malloc(sizeof(struct pokerCards)*bankSize);//could change
  initialGame(cards,&cTable,&cBank,&player,&tableSize);
  bool unFair = checkUnfair(cards, cTable, cBank, player, tableSize, bankSize);
  if(unFair){
    printf("\n======== After shuffle ======== \n\n");
    initialGame(cards,&cTable,&cBank,&player,&tableSize);  
  }
  
  printPlayerHold(cards,player);
  printPlayerAte(cards, player);
  printTable(cards, cTable, &tableSize);
  printBank(cards,  cBank,  &bankSize);
  
  
  
  game(cards,&player,&cTable,&cBank,&tableSize,&bankSize);
  printPlayerAte(cards, player);
  //printPlayerHold(cards,player);
  //printTable(cards,cTable,&tableSize);
  //printBank(cards, cBank,&bankSize);
  printScore(cards, player);

  
  return 0;
}