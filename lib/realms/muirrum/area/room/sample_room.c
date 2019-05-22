#include <lib.h>
#include "/realms/muirrum/area/customdefs.h"

inherit LIB_ROOM;

static void create() {
    room::create();
    SetClimate("indoors");
    SetAmbientLight(30);
    SetShort("Room 1");
    SetLong("This is a room you can use as a template.");
    SetItems( ([
        "template" : "That's what this is.",
      ]) );
    SetExits( ([
        "east" : "/realms/muirrum/area/room/sample_two",
        "west" : "/realms/muirrum/workroom",
        "south" : "/realms/muirrum/area/room/testroom1.c",
      ]) );
    SetInventory( ([
        MY_OBJ "/table" : 1,
        MY_NPC "/fighter" : 1,
      ]) );
}

void init(){
    ::init();
}
