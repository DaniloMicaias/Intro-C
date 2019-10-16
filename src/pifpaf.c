#include <stdlib.h>  // para o malloc() e free()
#include <stdio.h>   // entrada e saída pelo console
#include <time.h>    // para time(), usado na inicialização do gerador de número aleatório

/** Constante para o número máximo de cartas do maço ou do lixo (2 baralhos) */
#define MAX_CARDS 104

/** Constante para o número máximo de cartas da mão (do jogador ou do computador) */
#define MAX_HAND  10

/** Tipo booleano */
typedef enum {
  false, true
} bool;

/** Tipo que inclui os valores não numéricos das cartas do baralho */
typedef enum {
  A = 1, J = 11, Q, K
} CardValue;

/** Tipo que representa os naipes do baralho */
typedef enum {
  DIAMONDS, CLUBS, HEARTS, SPADES
} CardSuit;

/** Tipo que representa uma carta do baralho, com seu valor e seu naipe */
typedef struct {
  CardValue value;
  CardSuit suit;
} Card;

/** Tipo que representa um conjunto (ou deque) de cartas. Pode ser o maço de onde os jagadores irão comprar
 * as cartas, as cartas do lixo (onde os jogadores descartam) ou as cartas na mão de um jogador
 */
typedef struct {
  int size;     // tamanho do array de cartas (espaço alocado dinamicamente)
  int num;      // quantidade de cartas válidas (sempre será menor ou igual a "size")
  Card *cards;  // array de cartas de tamanho "size" (a ser alocado dinamicamente)
} Deck;

/**
 * Imprime os dados de uma carta.
 * @param c Carta a ser impressa
 */
void printCard(Card c) {
  switch(c.value) {
    case A: printf("Ás de "); break;
    case J: printf("Valete de "); break;
    case Q: printf("Dama de "); break;
    case K: printf("Rei de "); break;
    default: printf("%d de ", c.value);
  }
  switch(c.suit) {
    case DIAMONDS: printf("OURO"); break;
    case CLUBS: printf("PAUS"); break;
    case HEARTS: printf("COPAS"); break;
    case SPADES: printf("ESPADAS"); break;
  }
}

/**
 * Imprime um deque de cartas (conjunto de cartas).
 * @param d Grupo de cartas a ser impresso.
 */
void printDeck(Deck d) {
  for (int i = 0; i < d.num; i++) {
    printf("%i - ", i+1);
    printCard(d.cards[i]);
    printf("\n");
  }
}

/**
 * Inicializa um deque de cartas. Inicializa a quantidade de cartas com 0 e aloca o espaço para um array
 * com um determinado número de cartas.
 * @param d Referência (ponteiro) para o grupo a ser modoficado.
 * @param maxSize Tamanho do array de cartas a ser alocado dinamicamente.
 */
void initDeck(Deck *d, int maxSize) {
  d->size = maxSize;
  d->num = 0;
  d->cards = calloc(maxSize, sizeof(Card));
}

/**
 * Adicona uma carta no final de um deque de cartas.
 * @param d Referência (ponteiro) para o deque onde a carta será inserida.
 * @param c Carta a ser inserida.
 */
void addCard(Deck *d, Card c) {
  if (d->num < d->size) {
    d->cards[d->num] = c;
    d->num++;
  }
}

/**
 * Remove a i-ésima carta de um deque, onde i é o índice da carta no deque e retorna a carta removida.
 * @param d Referência (ponteiro) para o deque de a carta será removida.
 * @param i Índice da carta a ser removida.
 * @return c Carta removida.
 */
Card removeCard(Deck *d, int index) {
  if (index < d->num) {
    Card c = d->cards[index];
    // percorre os elementos a partir de 'index', copiando os valores das
    // cartas na posição anterior. Ou seja, desloca as cartas de uma posição.
    for(int i = index + 1; i < d->num; i++)  {
      d->cards[i - 1] = d->cards[i];
    }
    d->num--;
    return c;
  }
}

/**
 * Remove a última carta de um deque e retorna a carta removida.
 * @param d Referência (ponteiro) para o deque de a carta será removida.
 * @return c Carta removida.
 */
Card popCard(Deck *d) {
  return removeCard(d, d->num - 1);  // remove o último do deque
}

/**
 * Insere o conjunto de cartas de um determinado naipe em um deque.
 * @param d Referência ao deque onde as cartas serão inseridas.
 * @param s Naipe das cartas.
 */
void addSuit(Deck *d, CardSuit s) {
  for (int v = A; v <= K; v++) {
    Card c = { v, s };
    addCard(d, c);
  }
}

/**
 * Troca os valores de duas cartas. Ou seja, o que estava armazenada em uma passa a ser armazenado
 * na outra.
 * @param c1 Ponteiro para a 1ª carta.
 * @param c2 Ponteiro para a 2ª carta.
 */
void swapCards(Card *c1, Card *c2) {
  Card aux = *c1;
  *c1 = *c2;
  *c2 = aux;
}

/**
 * Embaralha um deque de cartas.
 * @param d Deque de cartas a ser embaralhado.
 */
void shuffleDeck(Deck *d) {
  // percorre todas as cartas...
  for (int i = 0; i < d->num; i++) {
    // ...escolhe uma outra carta aleatoriamente...
    int j = rand() % d->size;
    // ...e troca seus valores.
    swapCards(&d->cards[i], &d->cards[j]);
  }
}

/**
 * Organiza  um deque de cartas em ordem crescente de valores e seguindo a sequência
 * dos naipes: ouro, paus, copas e, por fim, espadas.
 * @param d Referência para o deque a ser organizado.
 */
void sortDeck(Deck *d) {
  // utiliza o algorito de bubblesort
  for (int i = 0; i < d->num - 1; i++) {
    for (int j = i + 1; j < d->num; j++) {
      Card c1 = d->cards[i];
      Card c2 = d->cards[j];
      if (c1.suit * 13 + c1.value > c2.suit * 13 + c2.value) {
        swapCards(&d->cards[i], &d->cards[j]);
      }
    }
  }
}

/**
 * Inicializa o jogo, inserindo as cartas de dois baralhos, embaralhando e distribuindo
 * 9 cartas para cada jogador.
 * @param d Referência para o maço de cartas de onde os jagadores irão comprar as cartas.
 * @param gb Referência para as cartas do lixo (onde os jogadores irão descartar suas cartas).
 * @param pl Referência para as cartas na mão do jogador usuário
 * @param comp Referência para as cartas na "mão" do computador
 */
void initGame(Deck *d, Deck *gb, Deck *pl, Deck *comp) {
  initDeck(d, MAX_CARDS);
  initDeck(gb, MAX_CARDS);
  initDeck(pl, MAX_HAND);
  initDeck(comp, MAX_HAND);

  for(int i = 0; i < 2; i++) {
    addSuit(d, DIAMONDS);
    addSuit(d, CLUBS);
    addSuit(d, HEARTS);
    addSuit(d, SPADES);
  }
  shuffleDeck(d);

  for(int i = 0; i < 9; i++) {
    addCard(pl, popCard(d));
    addCard(comp, popCard(d));
  }
  sortDeck(pl);
  sortDeck(comp);
}

/**
 * Gerencia a rodada do jogador-usuário. Mostra as cartas que o usuário tem, o que tem no lixo
 * e pergunta de onde quer comprar. Em seguida, mostra o novo conjunto de cartas e pergunta o
 * que quer descartar.
 * @param d Referência para o maço de cartas de onde o usuário pode comprar uma carta.
 * @param gb Referência para as cartas do lixo, onde o usuário pode descartar uma carta.
 * @param pl Referência para as cartas na mão do usuário
 */
void playerTurn(Deck *d, Deck *gb, Deck *pl) {
  int action, index;
  printf("Sua mão:\n");
  printDeck(*pl);
  printf("-----------------------------\n");
  printf("Topo do lixo: ");
  if (gb->num > 0) {
    printCard(gb->cards[gb->num-1]);
  }
  printf("\n-----------------------------\n");
  printf("O que deseja fazer? [1 - comprar do maço; 2 - comprar do lixo] ");
  scanf("%i", &action);
  Card c = popCard(action == 1 ? d : gb);
  addCard(pl, c);
  printf("Você retirou a carta: ");
  printCard(c);
  printf("\n...e está com a seguinte mão:\n");
  sortDeck(pl);
  printDeck(*pl);
  printf("\n-----------------------------\n");
  printf("Qual carta deseja descartar? [1 - 10] ");
  scanf("%i", &index);
  addCard(gb, removeCard(pl, index - 1));
}


/**
 * Calcula a distância entre duas cartas do baralho. A distância é definida pela diferença entre os valores
 * de cartas do mesmo naipe. Por exemplo, a distância de um Ás de Ouro e um 5 de Ouro é 5 - 1 = 4. Já a
 * distância de entre um Ás de Ouro e um 2 de Paus deve ser a maior possível, pois são naipes diferentes.
 * @param c1 A carta a ser calculada a distância a c2
 * @param c2 A carta a ser calculada a distância a c1
 */
int distance(Card c1, Card c2) {
  if (c1.suit != c2.suit) {
    return MAX_CARDS;   // se não for do mesmo naipe, então é muito distante!
  }
  int diff = (c1.value >= c2.value) ? (c1.value - c2.value) : (c2.value - c1.value);
  return diff;
}

/**
 * Calcula a menor "distância" de uma dada carta a outras de um deque, desde que não seja a
 * mesma carta (ou seja, que a distância seja 0). A função é útil para o computador escolher se
 * vale a pena puxar uma carta do lixo ou não.
 * @param d Cartas a serem verificadas.
 * @param c Carta para calcular a menor ditância em relação às cartas de d.
 */
int minDistance(Deck d, Card c) {
  int min = MAX_CARDS;  // não tem como ter valor maior que esse :-)
  for (int i = 0; i < d.num; i++) {
    int dist = distance(c, d.cards[i]);
    if (dist > 0 && dist < min) {
      min = dist;
    }
  }
  return min;
}

/**
 * Retorna o índice da carta de um deque que possui a maior distância para as demais cartas.
 * A função é útil para escolher a carta que o computador deve descartar, que é aquela mais "distante"
 * das demais.
 * @param d Deque a ser avaliado.
 */
int maxDistance(Deck d) {
  int maxIndex = 0;
  int maxDist = 0;
  for (int i = 0; i < d.num; i++) {
    int leftDist = MAX_CARDS;   // distância da carta à esquerda
    int rightDist = MAX_CARDS;  // distância da carta à direita
    if (i > 0) {                // atualiza a dist à esq se houver carta à esq.
      leftDist = distance(d.cards[i-1], d.cards[i]);
    }
    if (i < d.num - 1) {        // atualiza a dist à dir se houver carta à dir.
      rightDist = distance(d.cards[i], d.cards[i+1]);
    }
    int dist = leftDist > rightDist ? rightDist : leftDist;
    if (dist == 0) {            // a distância considerada é a menor entre a esq e a dir.
      return i;
    }
    else if (dist > maxDist) {  // se a distância for maior que a já calculada até o momento
      maxDist = dist;           // atualiza o valor da maior distância
      maxIndex = i;             // e o índice da carta com maior distância
    }
  }
  return maxIndex;
}

/**
 * Gerencia a rodada do jogador-computador. 
 * @param d Referência para o maço de cartas de onde o computador pode comprar uma carta.
 * @param gb Referência para as cartas do lixo, onde o computador pode descartar uma carta.
 * @param pl Referência para as cartas na mão do comutador
 */
void computerTurn(Deck *d, Deck *gb, Deck *comp) {
  int action, index;
  printf("Topo do lixo: ");
  bool removeFromDeque = true;
  if (gb->num > 0) {
    Card topGarbage = gb->cards[gb->num-1];
    printCard(topGarbage);
    int minDist = minDistance(*comp, topGarbage);
    if (minDist > 0 && minDist < 3) {
      removeFromDeque = false;
    }
  }
  printf("\n-----------------------------\n");
  if (removeFromDeque) {
    printf("O computador retirou uma carta do maço.");
    addCard(comp, popCard(d));
  }
  else {
    printf("O computador retirou a carta do lixo: ");
    Card c = popCard(gb);
    addCard(comp, c);
    printCard(c);
  }
  sortDeck(comp);
  int removeIndex = maxDistance(*comp);
  Card toRemove = removeCard(comp, removeIndex);
  printf("\nO computador descartou a carta: ");
  printCard(toRemove);
  addCard(gb, toRemove);
}

/**
 * Verifica se há uma sequência em uma "mão" de cartas e atualiza um array indicando quais as cartas
 * que fazem parte de algum jogo (sequência ou trinca).
 * @param hand Cartas que serão verificadas.
 * @param seq Array de booleanos indicando as cartas que fazem parte de algum jogo (valores true).
 */
void checkSequence(Deck hand, bool seq[]) {
  for(int i = 0; i < hand.num; i++) {   // para cada carta na mão
    if (seq[i] == false) {               //   se ela ainda não estiver marcada (parte de uma sequência ou trinca)
      Card c = hand.cards[i];           //   guarda seu valor em c
      int j = 1;                         //   percorre as cartas seguintes para ver se são do mesmo naipe e estão em sequência
      while (i + j < hand.num && c.suit == hand.cards[i+j].suit && c.value == hand.cards[i+j].value - j) {
        j++;
      }
      if (j >= 3) {                      //   se houver 3 ou mais cartas em sequência
        for (int k = i; k < i+j; k++) {  //     percorre as cartas da sequência e...
          seq[k] = true;                 //       ...as marca como parte de um jogo
        }
      }
    }
  }
}

/**
 * Verifica se há uma trinca em uma "mão" de cartas e atualiza um array indicando quais as cartas
 * que fazem parte de algum jogo (sequência ou trinca).
 * @param hand Referência para as cartas que serão verificadas.
 * @param seq Array de booleanos indicando as cartas que fazem parte de algum jogo (valores true).
 */
void checkSet(Deck hand, bool seq[]) {
  for(int i = 0; i < hand.num; i++) {     // para cada carta na mão
    if (seq[i] == false) {                 //   se ela ainda não estiver marcada (parte de uma sequência ou trinca)
      Card c = hand.cards[i];             //   guarda seu valor em c
      int count = 0;                       //   inicializa uma variável para contar as cartas de uma trinca
      int setIndex[10] = { 0 };            //   inicializa um array para guardar os índices das cartas da trinca
      int suits[4] = { 0 };                //   inicializa um array para contar quantas cartas da trinca tem cada naipe
      suits[c.suit] = 1;                   //   mas sabemos que o naipe da carta inicial já tem uma carta!
      for(int j = i; j < hand.num; j++) { //   percorre todas as cartas da mão...
        if (seq[j] == false && c.value == hand.cards[j].value) {  // ...procurando as cartas com o mesmo valor da inicial (c)
          setIndex[count] = j;             //     guarda o índice da carta com o mesmo valor
          count++;                         //     e atualiza o contador de cartas com o mesmo valor
          suits[hand.cards[j].suit]++;    //     atualiza o contador de cartas do naipe
        }
      }
      int countZeros = 0;                  //   conta quantos 0s tem os contadores dos naipes porque se houver
      for(int i = 0; i < 4; i++) {         //   só um significa que tem três naipes com cartas de mesmo valor, o que forma
        if (suits[i] == 0) {               //   uma trinca.
          countZeros++;
        }
      }
      if (count >= 3 && countZeros == 1) { // na regra indicada no trabalho, uma trinca não pode ser formada pelos 4 naipes.
        for(int i = 0; i < count; i++) {   // Tem que ser só três. Nesse caso, a condição de formação de trinca é de countZeros = 1.
          seq[setIndex[i]] = true;         // Porém, eu conhecia a regra de ter pelo menos três naipes. Nesse caso, a condição
        }                                  // seria countZeros <= 1.
      }
    }
  }
}

/**
 * Verifica todas as cartas de uma determinada "mão" formam jogo (trinca ou sequência).
 * @param hand Referência para as cartas que serão verificadas.
 */
bool won(Deck hand) {
  bool seq[hand.num];     // inicializa um array com o tamanho das cartas na mão e o inicializa todos os elementos com falso.
  for (int i = 0; i < hand.num; i++) {
    seq[i] = false;
  }
  checkSequence(hand, seq);
  checkSet(hand, seq);
  bool w = true;           // se houver pelo menos uma carta que não utilizada em um jogo (seq[i] == false), não terá ganhado.
  for (int i = 0; i < hand.num; i++) {
    w = w && seq[i];
  }
  return w;
}

/**
 * Rotina para testar casos específicos de cartas
 */
// void main() {
//   Deck hand;
//   Card cards[] =     {
//     { A, DIAMONDS },
//     { 2, DIAMONDS },
//     { 3, DIAMONDS },
//     { A, CLUBS },
//     { A, HEARTS },
//     { A, DIAMONDS }
//   };

//   initDeck(&hand, 9);
//   for(int i = 0; i < 6; i++) {
//     addCard(&hand, cards[i]);
//   }
//   printf("%i\n", won(hand));
// }

/**
 * Rotina principal do programa. Inicializa as cartas e fica num laço até alguém ganhar
 * ou não houver mais cartas no maço de compra.
 */
void main() {
  Deck deck, garbage, player, computer;

  srand(time(0));
  initGame(&deck, &garbage, &player, &computer);

  while(deck.num > 0) {
    printf("\n------------------------ JOGADOR -----------------------\n");
    playerTurn(&deck, &garbage, &player);
    if (won(player)) {
      printf("Parabéns!!! Você ganhou!!!\n");
      printDeck(player);
      break;
    }

    printf("\n------------------------ COMPUTADOR -----------------------\n");
    computerTurn(&deck, &garbage, &computer);
    if (won(computer)) {
      printf("O computador ganhou!!!\n");
      printDeck(computer);
      break;
    }
  }
  // libera as áreas alocadas dinamicamente.
  free(deck.cards);
  free(garbage.cards);
  free(player.cards);
  free(computer.cards);
}