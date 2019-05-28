#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

static void create() {
    meal::create();
    SetKeyName("Ale Tankard");
    SetId( ({"ale", "tankard", "tankard of ale"}) );
    SetShort("A tankard of ale");
    SetLong("A wooden tankard filled with foamy ale.");
    SetMass(10);
    SetStrength(20);
    SetBaseCost("silver",10);
    SetMealType(MEAL_DRINK | MEAL_ALCOHOL);
    SetMealMessages("You qauff your ale. Mmm!",
      "$N drinks $P ale");
    SetNoCondition(1);
}
void init(){
    ::init();
}
