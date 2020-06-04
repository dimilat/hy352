#include "hogwarts.hpp"
BEGIN_GAME
CREATE SPELL{
    NAME : "Expelliarmus",
    ACTION : START
            //Αφοπλίζει τον αντίπαλο μάγο (DEFENDER)
            EQUIP DEFENDER _
                // Μετά απο 2 γύρους επιστρέφει το ραβδί στον αντίπαλο (DEFENDER)
                AFTER 2 ROUNDS DO
                    EQUIP DEFENDER-- -
        o
            END
                END
} CREATE SPELL{
    NAME : "Sectumsempra",
    ACTION : START
            // Για 5 γύρους κάνει 8 damage στον αντίπαλο (DEFENDER)
            FOR 5 ROUNDS DO
                IF GET_HP(DEFENDER) > 73 DO

                                          DAMAGE DEFENDER 8 END END
                                              END
} CREATE SPELL{
    NAME : "Expulso",
    ACTION : START
        // Κάνει 22 damage στον αντίπαλο (DEFENDER)
        DAMAGE DEFENDER 22 END
} CREATE SPELL{
    NAME : "Anapneo",
    ACTION : START
        // Κάνει heal στον εαυτό του (ATTACKER)
        HEAL ATTACKER 30 END
} CREATE SPELL {
    NAME:""
} 
CREATE WIZARD{
    NAME : "Harry",
    HOUSE : "Gryffindor",
    HP : 100
} CREATE WIZARD{
    NAME : "Draco",
    HOUSE : "Slytherin",
    HP : 90
} MR "Harry" LEARN[SPELL_NAME(Expelliarmus)
                       SPELL_NAME(Sectumsempra)
                           SPELL_NAME(Expulso)
                               SPELL_NAME(Anapneo)] MR "Draco" LEARN[SPELL_NAME(Expelliarmus)
                                                                         SPELL_NAME(Expulso)] DUEL END_GAME