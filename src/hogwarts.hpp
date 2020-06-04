/*
*   hy352, 2019-2020
*   George Kostomanolakis,  csd3787
*   Dimitris Milathianakis, csd3657
*/

#include "data.hpp"

#pragma once

Damage damage;
Heal heal;
Equip equip;
Action var_action;
forActionsClass *class_action = new forActionsClass();
Wizard *wizard_tolearn = new Wizard();
Wand o;  //takes value o(1) from operator- overload func
Wand _(2);
int flag_fromAfter = 0;
int dummy_learn[14];

#define BEGIN_GAME            \
    int main() {              \
        Types temp_obj;       \
        Wizards temp_wizards; \
        Spells temp_spells;

#define CREATE ;
#define WIZARD temp_obj.wizard_tmp = new Wizard
#define WIZARDS temp_wizards
#define SPELLS temp_spells
#define SPELL temp_obj.spell_tmp = new Spell
#define NAME name
#define HOUSE house
#define HP hp
#define ACTION action
#define DAMAGE \
    ;          \
    damage =
#define HEAL \
    ;        \
    heal =
#define EQUIP \
    ;         \
    equip =
#define GET_HP(wizard) returnWizard(wizard 1)->getWizardHp()  //i sinartisi returnWizard pairnei orisma to (wizard,) kai epistrefei (wizard)
#define GET_HOUSE(wizard) returnWizard(wizard 1)->getWizardHouse()
#define GET_NAME(wizard) returnWizard(wizard 1)->getWizardName()
#define HAS_WAND(wizard) returnWizard(wizard 1)->getWizardWand()
#define ATTACKER Vectors::Players.at(new_game->getAttackerIndex()),
#define DEFENDER Vectors::Players.at(new_game->getDefenderIndex()),
#define SHOW               \
    ;                      \
    std::cout << std::endl \
              <<
#define END_GAME         \
    ;                    \
    temp_obj = temp_obj; \
    ;                    \
    }
#define START []() {
#define NUMARGS(...) (sizeof((int[]){__VA_ARGS__}) / sizeof(int))
#define AND(...) and_function(NUMARGS(__VA_ARGS__), __VA_ARGS__)
#define OR(...) or_function(NUMARGS(__VA_ARGS__), __VA_ARGS__)
#define NOT(x) not_function(x)
#define IF if(
#define ELSE_IF \
    ;           \
    }else if(
#define DO ) \
    {
#define ELSE \
    ;        \
    }        \
    else {
#define AFTER                                                    \
    ;                                                            \
    flag_fromAfter = 1;                                          \
    class_action = new forActionsClass();                        \
    returnWizard(ATTACKER 1)->myactions.push_back(class_action); \
    for (int i = 0; i <
#define FOR                                                      \
    ;                                                            \
    class_action = new forActionsClass();                        \
    returnWizard(ATTACKER 1)->myactions.push_back(class_action); \
    for (int i = 0; i <
#define ROUNDS                                                              \
    ;                                                                       \
         i++)                                                               \
    {                                                                       \
        if (flag_fromAfter) {                                               \
            class_action->actions.push_back(&(class_action->empty_action)); \
        } else {                                                            \
            class_action->actions.push_back(&(class_action->action));       \
        }                                                                   \
    }                                                                       \
    class_action->actions.pop_back();                                       \
    class_action->actions.push_back(&(class_action->action));               \
    flag_fromAfter = 0;                                                     \
    class_action->action = [](
#define MR \
    ; wizard_tolearn = find_wizard(
#define MRS \
    ; wizard_tolearn = find_wizard(
#define LEARN ); \
    dummy_learn
#define SPELL_NAME(spell) \
    -learn_spell(#spell, wizard_tolearn)
#define DUEL \
    ;        \
    duel();
#define END \
    ;       \
    }
