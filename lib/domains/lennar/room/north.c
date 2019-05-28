#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("copy of citystreet1.c");
    SetLong("This is a long north-south street that bisects Lennar. To the north you see a large city square with a statue. To the west is the Prancing Dolphin tavern.");
    SetExits(([
      ]));

    SetClimate("indoors");

}
void init(){
    ::init();
}
