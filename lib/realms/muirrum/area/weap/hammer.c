#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("hammer");
    SetAdjectives( ({"large", "heavy", "war"}) );
    SetId( ({"hammer", "warhammer"}) );
    SetShort("a heavy warhammer");
    SetLong("A very heavy blunt weapon designed to crush and pound. It looks like it can deal a world of hurt very quickly.");
    SetHands(2);
    SetMass(700);
    SetVendorType(VT_WEAPON);
    SetClass(30);
    SetDamageType(BLUNT);
    SetWeaponType("blunt");
}
void init(){
    ::init();
}
