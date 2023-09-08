#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_MAX  500
#define BOOKS_MAX   1000
#define FRIENDS_MAX 1000

#define INVALID_INDEX -1
#define BOOK_AVAILABLE (FRIENDS_MAX+1)

typedef unsigned int uint;

struct book {
  char title[STRING_MAX];
  char authors[STRING_MAX];
  uint  nb_pages;
};

struct friend {
  char firstname[STRING_MAX];
  char lastname[STRING_MAX];
};

typedef struct book book_t;
typedef struct friend friend_t;

struct library_manager {
  uint nb_books;
  uint nb_friends;
  book_t books_tab[BOOKS_MAX];
  friend_t friends_tab[FRIENDS_MAX];
  uint book_held_by[BOOKS_MAX];
};
typedef struct library_manager library_manager_t;





void library_manager_init(library_manager_t *p_lib) {
  (*p_lib).nb_books = 0;
  (*p_lib).nb_friends = 0;
}

void check_one_more_book(library_manager_t *p_lib) {
  if ((*p_lib).nb_books == BOOKS_MAX) {
    fprintf(stderr, "The library is already full of books. New books cannot be added.\n");
    exit(EXIT_FAILURE);
  }
}

void check_one_more_friend(library_manager_t *p_lib) {
  if ((*p_lib).nb_friends == FRIENDS_MAX) {
    fprintf(stderr, "Too much friends already. New friends cannot be added.\n");
    exit(EXIT_FAILURE);
  }
}

void fill_book(char *title, char *authors, uint nb_pages, book_t *p_book) {
  strcpy((*p_book).title, title);
  strcpy((*p_book).authors, authors);
  (*p_book).nb_pages = nb_pages;
}

void fill_friend(char *firstname, char *lastname, friend_t *p_friend) {
  strcpy((*p_friend).firstname, firstname);
  strcpy((*p_friend).lastname, lastname);
}

void display_a_book(book_t *p_book) {
    printf("Title: %s, Authors: %s, Number of pages: %d\n", (*p_book).title, (*p_book).authors,(*p_book).nb_pages);
}

void display_books(library_manager_t *p_lib) {
  uint nb_books = (*p_lib).nb_books;
  for (uint i = 0; i < nb_books; i++) {
    display_a_book(&((*p_lib).books_tab[i]));
  }
}


void display_a_friend(friend_t *p_friend){
    printf("Prenom: %s, Nom: %s", (*p_friend).firstname, (*p_friend).lastname);
}
void display_friends(library_manager_t *p_lib){
    for (uint i = 0; i < (*p_lib).nb_friends; i++) {
        display_a_friend(&((*p_lib).friends_tab[i]));
}}


int get_friend_index(library_manager_t *p_lib, char *firstname, char *lastname){
  uint nb_friends = (*p_lib).nb_friends;
  for (uint i = 0; i < nb_friends; i++) {
    if (strcmp(((*p_lib).friends_tab[i]).lastname, lastname) == 0 &&
	    strcmp(((*p_lib).friends_tab[i]).firstname, firstname) == 0) {
      return i;
    }
  }
  return INVALID_INDEX;
}


int get_book_index_by_title(library_manager_t *p_lib, char *title){
    uint nb_book = (*p_lib).nb_books;
    for (uint i = 0; i < nb_book; i++) {
        if (strcmp(&((*p_lib).books_tab[i]).title, title) == 0) return i;
  }
  return INVALID_INDEX;
}

void add_a_book(library_manager_t *p_lib, char *title, char *authors, unsigned int nb_pages) {
  if (get_book_index_by_title(p_lib, title) != INVALID_INDEX){ //book already present
    return; 
  }
  check_one_more_book(p_lib);
  book_t *p_book = &((*p_lib).books_tab[(*p_lib).nb_books]);
  fill_book(title, authors, nb_pages, p_book);
  (*p_lib).book_held_by[(*p_lib).nb_books]=BOOK_AVAILABLE;
  (*p_lib).nb_books=(*p_lib).nb_books+1; //((*p_lib).nb_books)++;
}


void add_a_friend(library_manager_t *p_lib, char *firstname, char *lastname){
  if (get_friend_index(p_lib, firstname, lastname) != INVALID_INDEX){ //book already present
    return; 
  }
  check_one_more_friend(p_lib);
  friend_t *p_friend = &((*p_lib).friends_tab[(*p_lib).nb_friends]);
  fill_friend(firstname, lastname, p_friend);
  (*p_lib).nb_friends=(*p_lib).nb_friends+1;
}


void lend_a_book(library_manager_t *p_lib, char *firstname, char *lastname, char *title){
  int indice_book = get_book_index_by_title(p_lib, title);
  int indice_friend = get_friend_index(p_lib, firstname, lastname);
  if(indice_friend == INVALID_INDEX){
        fprintf(stderr, "%s %s ne figure pas dans la liste des amis.\n", firstname, lastname);
        exit(EXIT_FAILURE);
  }
  else if(indice_book == INVALID_INDEX){
        fprintf(stderr, "Le livre %s ne figure pas dans la librairie\n", title);
        exit(EXIT_FAILURE);

  }
  else if((p_lib->book_held_by)[indice_book] != BOOK_AVAILABLE){
    fprintf(stderr, "Le livre %s est déjà emprunté\n", title);
    exit(EXIT_FAILURE);
  }
  (*p_lib).book_held_by[indice_book] = indice_friend;

}



void display_books_lent_to_a_friend(library_manager_t *p_lib, char *firstname, char *lastname){
  int indice_friend = get_friend_index(p_lib, firstname, lastname);
  if(indice_friend == INVALID_INDEX){
    fprintf(stderr, "%s %s ne figure pas dans la liste des amis.\n", firstname, lastname);
    exit(EXIT_FAILURE);
  }
  for(uint i = 0; i<(*p_lib).nb_books; i++){
    if((*p_lib).book_held_by[i] == indice_friend){
      display_a_book(&((*p_lib).books_tab[i]));
    }
  }
}


int main(void) {
  library_manager_t lib_manager;
  library_manager_init(&(lib_manager));
  
  add_a_book(&(lib_manager), "Methodologie de la programmation en C", "Braquelaire A.", 652);
  add_a_book(&(lib_manager), "The C programming language", "B. W. Kernighan and D. Ritchie", 500);
  add_a_book(&(lib_manager), "Les fables de La Fontaine", "La Fontaine", 600);
  add_a_book(&(lib_manager), "Tintin au Tibet", "Herge", 40);
  add_a_book(&(lib_manager), "Asterix chez les bretons", "R. Goscinny et A. Uderzo", 40);
  add_a_book(&(lib_manager), "Introduction a la gestion de lane", "LeFramboisier", 1904);


  add_a_friend(&(lib_manager), "Julie", "Dupond");
  add_a_friend(&(lib_manager), "Zoe", "Dupond");
  add_a_friend(&(lib_manager), "Gary", "Dupont");
  add_a_friend(&(lib_manager), "Paul", "Dupont");
  add_a_friend(&(lib_manager), "Ornn", "Top");



  display_books(&(lib_manager));
  display_friends(&(lib_manager));

  if(get_friend_index(&(lib_manager), "Zoe", "Dupond")==INVALID_INDEX){
    printf("Zoe Dupond is not a friend of mine\n");    
  }
  if(get_friend_index(&(lib_manager), "Luc", "Dupond")==INVALID_INDEX){
    printf("Luc Dupond is not a friend of mine\n");    
  }
  if(get_book_index_by_title(&(lib_manager),"Tintin au Tibet")==INVALID_INDEX){
    printf("Tintin au Tibet is not part of my library.\n");    
  }
  if(get_book_index_by_title(&(lib_manager),"Asterix chez les normands")==INVALID_INDEX){
    printf("Asterix chez les normands is not part of my library.\n");    
  }
  lend_a_book(&(lib_manager), "Zoe", "Dupond", "Tintin au Tibet");
  lend_a_book(&(lib_manager), "Zoe", "Dupond", "The C programming language");
  display_books_lent_to_a_friend(&(lib_manager), "Zoe", "Dupond");
  lend_a_book(&(lib_manager), "Zoe", "Dupond", "Asterix chez les normands"); // doit arreter l'execution du programme
  return EXIT_SUCCESS;
}
