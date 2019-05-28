#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Everett Square");
    SetLong("This is a large city square with a statue in the center. The streets are filled with the hustle and bustle of everyday life. Elma Street bisects the square from north to south, and Main Street crosses from east to west.");
    SetItems(([
        ({ "statue", "large statue" }) : "It's a large statue of a portly middle-aged man sitting on a throne. His face looks stern.",
      ]));
    SetExits( ([
        "south" : "/domains/lennar/room/citystreet1",
        "east" : "/domains/lennar/room/mainstreet1",
        "north" : "/domains/lennar/room/elmastreetnorth.c",
      ]) );

    SetClimate("indoors");

}
void init(){
    ::init();
}
