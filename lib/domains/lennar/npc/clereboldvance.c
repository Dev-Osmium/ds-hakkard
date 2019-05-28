#include <lib.h>

inherit LIB_TRAINER;

static void create() {
    trainer::create();
    SetKeyName("Clerebold Vance");
    SetId( ({"clerebold", "clerebold vance", "vance"}) );
    SetAdjectives(({"non player"}));
    SetShort("Clerebold Vance");
    SetLong("He is a small man, but exceptionally fit. He wears a tan shirt with thin black vertical stripes and violet pants. His Stetson hat is riddled with cuts and holes. His eyes are likewise green. His teeth are yellowed and unaligned.");
    SetClass("explorer");
    SetLevel(40);
    SetMelee(1);
    SetRace("human");
    SetGender("male");
    AddTrainingSkills( ({"bargaining"}) );
    SetPolyglot(1);
    SetCustomXP(10);
}
void init(){
    trainer::init();
}

int eventHelp(object who, string unused) {
	::eventHelp(who);
	this_object()->eventForce("speak Please note I only understand English. If you're speaking in a different language I can't understand you!");
	return 1;
}
