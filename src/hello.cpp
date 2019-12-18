#include "Hogwarts.hpp"

/* PROGRAM AFTER DEFINES WILL RUN HERE
   EX. 

    BEGIN_GAME

        CREATE WIZARD { NAME: "name", HOUSE: "house", HP: health_points }
        CREATE SPELL {  NAME: "Anapneo",
                        ACTION: START   
                            IF GET_HP(ATTACKER) < 30 DO
                                HEAL ATTACKER 25 
                            ELSE 
                                HEAL ATTACKER 15 
                            END 
                        END}
    END_GAME

*/