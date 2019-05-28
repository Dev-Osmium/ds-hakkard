#include <lib.h>
#include <daemons.h>
#ifndef REQUIRE_QUESTING
#define REQUIRE_QUESTING 1
#endif

inherit LIB_SENTIENT;
int hint;
int Advance(mixed arg);
mapping advancement, Levels;
static void create() {
    int i;
    sentient::create();
    Levels = PLAYERS_D->GetLevelList();
    advancement = ([]);
    SetKeyName("odo");
    SetId( ({"odo"}) );
    SetAdjectives(({"non player"}));
    SetShort("Odo Garfield");
    SetLong("This dark-skinned man stands 5'11\" and tends to wear a heavy leather apron. Coupled with his rolled up shirt sleeves this gives him a very relaxed look. His long blonde hair reaches down to his waist. His brown eyes have a joyful gleam in them most of the time.");
    SetPolyglot(1);
    SetLanguage("common", 100);
    SetDefaultLanguage("common");
    SetLevel(15);
    SetMelee(1);
    SetRace("human");
    SetGender("male");

    // Talk logic
    AddTalkResponse("hello", "Hi! Ask me about advancement.");

    SetCommandResponses( ([
        "advance": (: Advance :)
    ]));

    SetConsultResponses( ([
        ({"level", "levels", "leveling", "advancement", "advancing" }) : "To level, get some experience, then come back and ask me to advance. For some levels you may need quest points to advance as well as experience.",
        ({"xp", "XP", "experience"}) : "You can gain experience by killing monsters or completing quests.",
    ]));
    for(i=0;i<21;i++){
        advancement[i] = Levels[i];
    }
}
void init(){
    ::init();
}

int Advance(mixed arg) {
    int level,xp,qp;
    int desired_level,required_xp,required_qp;
    mixed *statlist;
    mapping this_stat;
    int statclass, statlevel, i;

    statlist = this_player()->GetStats();

    if(this_player()->GetKeyName() == "guest") {
        this_object()->eventForce("say I don't deal with temporary constructs");
        return 1;
    }

    if(!level = this_player()->GetLevel()) {
        this_object()->eventForce("say Now I'm confused... Your level does not match up with my records.");
        return 1;
    }

    if (level>19) {
        this_object()->eventForce("say I can't teach you anymore. You'll need to move on to other branches to go any higher.");
        return 1;
    }

    xp = this_player()->GetExperiencePoints();

    if (!qp = this_player()->GetQuestPoints()) qp = 0;
    desired_level = level+1;
    required_xp = advancement[desired_level]["xp"];
    if(!required_qp = advancement[desired_level]["qp"]) required_qp = 0;
    if(!REQUIRE_QUESTING) required_qp = 0;

    this_object()->eventForce("say Level " + desired_level + "with the title of \"" + advancement[desired_level]["title"]+"\" requires "+required_xp+" experience points and "+required_qp+" quest points");

    if (xp > required_xp-1 && qp > required_qp-1) {
        this_object()->eventForce("say Congratulations! You're promoted to level "+desired_level+" and have earned the name "+this_player()->GetName()+" "+advancement[desired_level]["title"]+".");
        this_player()->ChangeLevel(desired_level);
        this_player()->AddTrainingPoints(desired_level);
        this_player()->AddTitle(advancement[desired_level]["title"]);
        this_player()->RemoveTitle(advancement[desired_level-1]["title"]);
        this_player()->save_player(this_player()->GetKeyName());

        if(level == MAX_NEWBIE_LEVEL){
            write("\nOdo raises his hand and sternly points to you.\n");
            say("\nOdo raises his hand and sternly points to "+
                    this_player()->GetName()+".\n");
            this_object()->eventForce("say "+this_player()->GetName()+","+
                    " you are no longer a newbie. From now on, you will need"+
                    " a light source to see in the dark. From now on, you will"+
                    " not understand languages you haven't learned. You have"+
                    " earned this promotion, and now face the future as a"+
                    " real adventurer.");
        }
    }
    else this_object()->eventForce("say I'm sorry, "+this_player()->GetName()+", but you haven't fulfilled the requirements of your next level. Keep trying!");
    return 0;
}

string GetLevelTitle(int level){
    if(!level) level = 1;
    return advancement[level]["title"];
}
