#include <lib.h>

inherit LIB_TRAINER;

static void create() {
    sentient::create();
    SetKeyName("ralf ridley");
    SetId( ({"ralf", "ralf ridley"}) );
    SetAdjectives(({"fighter"}));
    SetShort("Ralf Ridley");
    SetLong("This is an older man who wears a faded coat and loose pants complete with feathered hat, he is not a threatening figure. He wears his hair in dreadlocks. His blue eyes lackadaisically let the world flow into them.");
    SetClass("fighter");
    SetLevel(10);
    SetMelee(1);
    SetRace("human");
    SetGender("male");
    AddTrainingSkills(({"blade attack", "blade defense", "melee attack", "melee defense"}));
    SetCustomXP(40);
}
void init(){
    trainer::init();
}
