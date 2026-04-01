#ifndef DND_CHARACTER_H
#define DND_CHARACTER_H
#include <stdlib.h>
#include <math.h>
#define MAX_DICE 6
#define MIN_DICE 1
typedef struct {
   int strength;
   int dexterity;
   int constitution;
   int intelligence;
   int wisdom;
   int charisma;
   int hitpoints;
} dnd_character_t;
int one_dice_roll(void);
int ability(void);
int modifier(int score);
dnd_character_t make_dnd_character(void);

#endif
