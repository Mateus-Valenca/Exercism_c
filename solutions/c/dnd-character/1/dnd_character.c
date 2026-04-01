#include "dnd_character.h"

int one_dice_roll(void)
{
    return MIN_DICE + rand() % (MAX_DICE - MIN_DICE + 1);
}
int ability(void)
{
    int total = 0, smallest =6, dice_roll = 0;
    for(int i = 0; i < 4; i++){
        dice_roll = one_dice_roll();
        total += dice_roll;
        if(dice_roll < smallest) smallest = dice_roll;
    }
    return total - smallest;
}

int modifier(int score)
{
    return (int)floor((score - 10) / 2.0);
}
dnd_character_t make_dnd_character(void)
{
    dnd_character_t random_char;
    random_char.strength     = ability();
    random_char.dexterity    = ability();
    random_char.constitution = ability();
    random_char.intelligence = ability();
    random_char.wisdom       = ability();
    random_char.charisma     = ability();
    random_char.hitpoints    = 10 - modifier(random_char.constitution);

    return random_char;
}