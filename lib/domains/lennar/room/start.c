#include <lib.h>
#include ROOMS_H

inherit LIB_ROOM;

void create() {
    room::create();
    SetAmbientLight(30);
    SetShort("Prancing Dolphin");
    SetLong("This is a long, low room filled with tables and patrons talking loudly. There is a bar spanning the eastern wall, with stools spaced evenly along it. The bartender paces around behind it, casting glances at some of the more rowdy patrons.");
    SetItems(([
        ({ "table", "tables" }) : "These are long wooden tables, that look like they've seen many years of drinking and abuse. Though old, they look sturdy enough to take many more beatings.",
        ({ "patron", "patrons" }) : "These are smelly, unwashed humans and halflings enjoying themselves enormously.",
      ]));
    SetInventory(([
        "/domains/lennar/npc/sarumsmort" : 1,
        "/domains/lennar/npc/clereboldvance" : 1,
      ]));
    SetExits( ([
        "east" : "/domains/lennar/room/citystreet1.c",
      ]) );
    SetClimate("indoors");

    SetDoor("east", "/domains/lennar/doors/dolphintostreet.c");

}
void init(){
    ::init();
}
