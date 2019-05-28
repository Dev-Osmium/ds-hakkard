#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("East Main Street");
    SetLong("This is a long east-west street that bisects Lennar. To the west is a large city square with a statue. To the north is the Adventurer's Guild, and to the south is the Mage's Guild.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetExits( ([
        "north" : "/domains/lennar/room/adventurersguildmain",
        "west" : "/domains/lennar/room/everettsquare",
        "south" : "/domains/lennar/room/magesguildmain.c",
      ]) );

    SetClimate("indoors");

}
void init(){
    ::init();
}
