#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Manor Foyer");
    SetLong("This is a long room with ornate pillars. You can see stacks of books to the east. To the west yo can see a small tea room. To the northeast you can hear the sounds of clashing swords, and to the north is a large staircase");
    SetExits( ([
        "south" : "/domains/lennar/room/elmastreetnorth",
        "east" : "/domains/lennarmanor/room/lowerlibrary",
        "west" : "/domains/lennarmanor/room/tearoom",
        "up" : "/domains/lennarmanor/room/receptionhall",
        "northeast" : "/domains/lennarmanor/room/barracks.c",
      ]) );
}
void init(){
    ::init();
}
