#include <lib.h>

inherit LIB_BARKEEP;

static void create() {
    barkeep::create();
    SetKeyName("Sarum Smort");
    SetId( ({"sarum", "sarum smort", "smort"}) );
    SetAdjectives(({"non player"}));
    SetShort("Sarum Smort");
    SetLong(" He is an exceptionally muscular looking western young adult. He wears a simple green robe with violet stripes complete with hood. Beneath his clothing is a huge mess of scar tissue. His red hair is still thick. His brown eyes show the wear and tear of someone lonely with a great burden to carry.");
    SetLevel(1);
    SetMelee(1);
    SetMenuItems(([
        ({"ale"}) : "/domains/lennar/meals/ale",
      ]));
    SetRace("human");
    SetGender("male");
    SetPolyglot(1);
    SetLanguage("Common", 100);
    SetDefaultLanguage("common");
}
void init(){
    ::init();
}

