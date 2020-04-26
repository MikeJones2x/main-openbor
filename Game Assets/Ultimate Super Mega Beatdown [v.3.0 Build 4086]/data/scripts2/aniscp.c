



void changeanitothrowbykey(void Key, int Hflag, int damage)
{ //Throws entity if a key combo is pressed during an animation
  //place this command a frame after the actual hit
  //V0.10 Matman
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    if ( checkent(target) == 1 ) {
      int Direction = getentityproperty(self, "direction");
      void Health = getentityproperty(target,"health");
      void iRKey = checkkeycombo(self, Key, Hflag);
      void cancon = 0;

      if (iRKey)
      {
       cancon = isinpainanimation(target);
       if (cancon == 1) //only throw enemy if he is in pain
       {

         if ((Health - damage) > 1)
         {
           changeentityproperty(target, "damage_on_landing", damage);
         }

         performattack(self, openborconstant("ANI_THROW"), 1);
         if (Direction == 0){ //left
           tossentity(target, 4, 3, 0);
         } else { tossentity(target, 4, -3, 0); }
         changeentityproperty(target, "animation", openborconstant("ani_fall"));
         statusthrown(1, target);
       //throwenemy(10,10,0);
     }
    }
   }
   }
}


void changeanitothrowbykeydetailed(void throwani, void Key, int Hflag, int x, int y, int z)
{ //Throws entity if a key combo is pressed during an animation
  //place this command a frame after the actual hit
  //throwani: animation to use as throw
  //Key: key combo
  //hflag: key combo type
  //x,y,z: direction to throw. automatically takes account of direction for x
  //V0.08 Matman
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    if ( checkent(target) == 1 ) {
    int Direction = getentityproperty(self, "direction");
    void iRKey = checkkeycombo(self, Key, Hflag);
    void cancon = 0;

    if (iRKey)
    {
     cancon = isinpainanimation(target);
     if (cancon == 1) //only throw enemy if he is in pain
     {
       performattack(self, openborconstant(throwani), 1);
       if (Direction == 0){ //left
         tossentity(target, y, x, z);
       } else { tossentity(target, y, -x, z); }
       statusthrown(1, target);
     }
    }
  }
  }
}


void changeanitothrowifpain(void Ani, void targetani, int changedirection, int vx, int vy, int vz)
{
// V0.08 Matman:
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    void Health = getentityproperty(self,"health");
    int Direction = getentityproperty(self, "direction");
    int cancon = 0;
    cancon = isinpainanimation(target);

    if ( cancon = 1 && Health > 0){
      performattack(self, openborconstant(Ani), 1);

      if (Direction == 0){ //left
        if (changedirection == 1) { changeentityproperty(self, "direction", 1); }
        tossentity(target, vy, vx, vz);
      } else {
        if (changedirection == 1) { changeentityproperty(self, "direction", 0); }
        tossentity(target, vy, -vx, vz);
        //tossentity(target, 4, -3, 0);
      }
      statusthrown(1, target);
      }
    }
}


void enemypositionduringfall(float dx, float dy, float dz)
{ //
 //V 0.05
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     void target = getentityproperty(self, "opponent");
     if ( checkent(target) == 1 ) {
       void thealth = getentityproperty(target, "health");
       void canCont = 0;
       int direction = getentityproperty(self, "direction");
   float fx;
   float fy;
   float fz;


   if( target!=NULL() && thealth > 0 )
   {
     canCont = isinfallanimation(target);
     if (canCont==1)
     {
       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = dy + getentityproperty(self, "a"); //Get Y location and add adjustment.
       fz = dz + getentityproperty(self, "z"); //Get Z location and add adjustment.
       if ( checkwall(fx,fz) <= getentityproperty(self, "a")
         && getentityproperty(target, "speed") > 0 )
       {
         changeentityproperty(target, "position", fx, fz, fy);
       }
     }
   }
   }
  }
}


void enemypositionduringfallx(float dx)
{
   //v 0.05  Matman
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     void target = getentityproperty(self, "opponent");
     if ( checkent(target) == 1 ) {
       void thealth = getentityproperty(target, "health");
       void canCont = 0;
       int direction = getentityproperty(self, "direction");
       float fx;
       float fy;
       float fz;

   if( target!=NULL() && thealth > 0 )
   {
     canCont = isinfallanimation(target);
     if (canCont==1 )
     {
       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = getentityproperty(target, "a"); //Get Y location and add adjustment.
       fz = getentityproperty(target, "z"); //Get Z location and add adjustment.

       if ( checkwall(fx,fz) <= getentityproperty(self, "a")
         && getentityproperty(target, "speed") > 0 )
       {
         changeentityproperty(target, "position", fx, fz, fy);
       }
     }
   }
   }
   }
}


void enemypositionduringpain(float dx, float dy, float dz)
{ // Modify grabbed entity's position relative to grabber
 //V 0.06
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     void target = getentityproperty(self, "opponent");
     if ( checkent(target) == 1 ) {
       void canCont = 0;
       int direction = getentityproperty(self, "direction");
       float fx;
       float fy;
       float fz;

   if( target!=NULL())
   {
     canCont = isinpainanimation(target);
     if (canCont==1
      && getentityproperty(target, "speed") > 0 )
     {

       //settextobj(0, 50, 30, 0, -1, "flop");

       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
       //updateframe(target, Frame);
        //Get X location and add adjustment.
       fy = dy + getentityproperty(self, "a"); //Get Y location and add adjustment.
       fz = dz + getentityproperty(self, "z"); //Get Z location and add adjustment.
       if ( checkwall(fx,fz) <= getentityproperty(self, "a")
         && getentityproperty(target, "speed") > 0 )
       {
         changeentityproperty(target, "position", fx, fz, fy);
       }
     }
   }
   }
   }
}


void enemypositionduringpainx(float dx)
{ // Modify grabbed entity's position relative to grabber
 //v 0.04
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     void target = getentityproperty(self, "opponent");
     if ( checkent(target) == 1 ) {
       void canCont = 0;
       int direction = getentityproperty(self, "direction");
       float fx;
       float fy;
       float fz;

   if( target!=NULL() )
   {
     canCont = isinpainanimation(target);
     if (canCont==1)
     {
       //make sure it pushes the entity back
       if (direction == 1) { fx = getentityproperty(self, "x") + dx ; } else
       if (direction == 0) { fx = getentityproperty(self, "x") - dx ; }
        //Get X location and add adjustment.
       fy = getentityproperty(target, "a"); //Get Y location and add adjustment.
       fz = getentityproperty(target, "z"); //Get Z location and add adjustment.
       //If destination doesn't have a wall then move
       //log(" \n Speed " + getentityproperty(target, "speed") );
       if ( checkwall(fx,fz) <= getentityproperty(self, "a")
         && getentityproperty(target, "speed") > 0 )
       {
         changeentityproperty(target, "position", fx, fz, fy);
       }
     }
   }
   }
   }
}


void tossentityduringfall(float x, float y, float z)
{
  // V 0.08
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    if ( checkent(target) == 1 ) {
      void thealth = getentityproperty(target, "health");
      int Direction = getentityproperty(self, "direction");
      void cancon = isinfallanimation(target);
      if (cancon == 1 && thealth > 0)
      {
        if ( self != NULL() && target != NULL()){
          if ( checkrange(self, target) ) { cancon = 1; } else { cancon = 0; }
        }
      //if ( thealth == 0 ) { cancon = 0; }
      //checkrange(entity, target, int animid)

      if (cancon == 1)
      {
        //log(" can toss during fall " +x+y+z);
        if (Direction == 0){ //left
             tossentity(target, y, x, z);
           } else { tossentity(target, y, -x, z); }
        statusthrown(1, target);
      }
  }
  }
  }
}


void tossentityduringfallnorange(float x, float y, float z)
{ //Tosses enemy if they are falling and does no range check.
  // V 0.05
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    if ( checkent(target) == 1 ) {
      //void thealth = getentityproperty(target, "health");
      int Direction = getentityproperty(self, "direction");
      void cancon = isinfallanimation(target);
      if (cancon == 1 )//&& thealth > 0)
      {

        if (cancon == 1)
        {
          //log(" can toss during fall " +x+y+z);
          if (Direction == 0){ //left
             tossentity(target, y, x, z);
           } else { tossentity(target, y, -x, z); }
        statusthrown(1, target);
      }
  }
  }
  }
}




void bindtoparent(int lock, int x, int y, int z)
{
  // Binds itself to the parent
  // V 0.02
  void vself = getlocalvar("self");
  if ( checkent(vself) == 1 ) {
  void parent = getentityproperty(vself, "parent");
  void Health = getentityproperty(parent,"health");
  int cancon = 0;

  if ( parent != NULL() && Health > 0 )
  {

    if (lock == 1)
    {
       bindentity(vself, parent , x, z, y, 0, 0);
    }else {
     if (lock == 0)
     {
       bindentity( vself, NULL());
     }
    }
  }
  if (Health < 1)
  {
    changeentityproperty( vself, "health", 0 );
    changeentityproperty( vself, "aiflag", "autokill", 1 );
  }
  }
}


void bounceofwall(int isTrue)
{// Checks if there is wall at defined distance
  // V 0.04
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     int Direction = getentityproperty(self, "direction");
     int x = getentityproperty(self, "x");
     int z = getentityproperty(self, "z");
     float H;
     float Hz;

     if (Direction == 0){ //Is entity facing left?
       H = checkwall(x+10,z);
     }  else {
       H = checkwall(x-10,z);
     }
   /*
   if (checkwall(x,z-10) > 0) {
     Hz = 1;
   } else {
     if (checkwall(x,z+10) > 0) {
       Hz = -1;
     }
   }
   */
   if (H > 0)
   {
     if (Direction == 0){ //Is entity facing left?
         changeentityproperty(self, "direction", 1);
         tossentity(self, -1, 1.5, 0);
       }  else {
         changeentityproperty(self, "direction", 0);
         tossentity(self, 1, 1.5, 0);
       }
   }
   /*
   if (Hz > 0)
   {
     tossentity(self, 0, 1.5, -0.5);
   } else {
     if (Hz < 0)
     {
       tossentity(self, 0, 1.5, 0.5);
     }
   }
   */
   }
}


void breakgrabchangeanibykeytoattack(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.08
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      //int Direction = getentityproperty(self, "direction");
      //int iPIndex = getentityproperty(self,"playerindex"); //Get player index
      void iRKey = checkkeycombo(self, Key, Hflag);
      void isFalling = 0;

      if (iRKey)
      {
        //grabfree(1, self);
        isFalling = isinfallanimation(self);
        if (isFalling == 1) { statusthrown(0, self); }
        if (getentityproperty(self, "animationid") == openborconstant("ANI_grab")) { statusgrabbed(0,self); }
        changeanibykeytoattack(self,Ani,Frame,Key,Hflag,Limit);
      }
    }
}


void changeanibykey(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.04
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      void Health = getentityproperty(self,"health");
      //int Direction = getentityproperty(self, "direction");
      //int iPIndex = getentityproperty(self,"playerindex"); //Get player index
      void iRKey = checkkeycombo(self, Key, Hflag);
      if ((Health > Limit)&&iRKey){
        changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
        changeentityproperty(self, "animpos", Frame);
      }
    }
}


void changeanibykeydirection(void Ani, void Key, int Hflag)
{// Change current animation if proper key is pressed and option to change direction
// V0.05
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     //void target = getentityproperty(self, "opponent");
     int Direction = getentityproperty(self, "direction");
     //int iPIndex = getentityproperty(self,"playerindex"); //Get player index
     void iRKey = checkkeycombo(self, Key, Hflag);

     if (iRKey)
     {
       if (Direction == 0){ //left
         changeentityproperty(self, "direction", 1);
       } else {
         changeentityproperty(self, "direction", 0);
     }
     performattack(self, openborconstant(Ani), 1);
    }
  }
}


void changeanibykeytoattackforself(void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.07
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      changeanibykeytoattack(self, Ani, Frame, Key, Hflag, Limit);
    }
}


void changeanibykeytoattackoffwallself(void Ani, void Key)
{// Change current animation if proper key is pressed and entity is by a wall
// V0.02
// Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
       //Until openborvariant("hresolution") works will need to hard code the width
       //480x272
       if (  openborvariant("xpos")+20 > getentityproperty(self, "x")
         ||  openborvariant("xpos")+460-20 < getentityproperty(self, "x")
         || getentityproperty(self, "direction") == 0 &&  checkwall( getentityproperty(self, "x")+20, getentityproperty(self, "z") ) > getentityproperty(self, "a")
         || getentityproperty(self, "direction") == 1 &&  checkwall( getentityproperty(self, "x")-20, getentityproperty(self, "z") ) > getentityproperty(self, "a")
          )
       {
         changeanibykeytoattack(self, Ani, 0, Key, 0, 0);
       }
    }
}


void changeanitoattackiffall(void Ani)
{// Force's change on current animation if enemy is falling
// V0.04 Matman:
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      void target = getentityproperty(self, "opponent");
      if ( checkent(target) == 1 ) {
        void Health = getentityproperty(self,"health");
        int cancon = 0;
        cancon = isinfallanimation(target);

        if ( cancon = 1 && Health > 0){
          performattack(self, openborconstant(Ani), 1);
        }
      }
    }
}


void changeanitoattackifpain(void Ani)
{// Force's change on current animation if enemy is in pain
// V0.04 Matman:
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      void target = getentityproperty(self, "opponent");
      if ( checkent(target) == 1 ) {
        void Health = getentityproperty(self,"health");
        int cancon = 0;
        cancon = isinpainanimation(target);

        if ( cancon = 1 && Health > 0){
          performattack(self, openborconstant(Ani), 1);
        }
      }
    }
}


void changeanitosselfbykeydetailedfall(void newani, void Key, int Hflag, float x, float y, float z)
{
  //place this command a frame after the actual hit
  //throwani: animation to use as throw
  //Key: key combo
  //hflag: key combo type
  //x,y,z: direction to throw self. automatically takes account of direction for x
  //V0.07 Matman
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    int Direction = getentityproperty(self, "direction");
    void thealth = getentityproperty(target, "health");
    void cancon = 0;

    void iRKey = checkkeycombo(self, Key, Hflag);

    if (iRKey)
    {
     cancon = isinfallanimation(target);
     if (cancon == 1 && thealth > 0) //only throw enemy is falling
     {
       performattack(self, openborconstant(newani), 1);
       if (Direction == 0){ //left
         tossentity(self, y, x, z);
       } else { tossentity(self, y, -x, z); }
       if ( getentityproperty(self, "a") > 20)
         {
           statusjump(1, self);
           //changeentityproperty(self, "aiflag", "jumping", 1);
         }
     }
    }
  }
}


void changeanitosselftoss(void newani, void Key, float x, float y, float z)
{
  //place this command a frame after the actual hit
  //throwani: animation to use as throw
  //Key: key combo
  //x,y,z: direction to throw self. automatically takes account of direction for x
  //V0.03 Matman
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    int Direction = getentityproperty(self, "direction");
    void thealth = getentityproperty(target, "health");

    void iRKey = checkkeycombo(self, Key, 0);

     if (iRKey)
      {
       if (thealth > 0) //
       {
         performattack(self, openborconstant(newani), 1);
         if (Direction == 0){ //left
           tossentity(self, y, x, z);
         } else { tossentity(self, y, -x, z); }
         if ( getentityproperty(self, "a") > 5)
           {
             statusjump(1, self);
             //changeentityproperty(self, "aiflag", "jumping", 1);
           }
       }
     }
  }
}


void changedirectionbykey(void Key, void Hflag)
{
  //v 0.03
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    int Direction = getentityproperty(self, "direction");
    void iRKey = checkkeycombo(self, Key, Hflag);
    if (iRKey)
    {
      if (Direction == 0){ //Is entity facing left?
          changeentityproperty(self, "direction", 1);
        } else {
          changeentityproperty(self, "direction", 0);
        }
    }
  }

}


void entityincreasehealth(float amount)
{// increase current health amount, not max health.
// V0.02 Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      increasehealthforentity( self, amount );
    }
}


void entityincreasespeed(float amount)
{// increase current speed amount.
// V0.03 Matman
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      increasespeedforentity( self, amount );
    /*
    void cmp = getentityproperty(self,"speed");
    cmp = cmp + (amount);
    changeentityproperty(self, "speed", cmp);
    */
    }
}


void freeself(int istrue)
{ // Kills entity without playing the death animation
// V0.02 Matman
   if (istrue == 1) {
     void self = getlocalvar("self");
     //killentity(self);
     freeentity(self);
   }
}


void killselfonfloor(int heightisbelow)
{
  //Kills entity if it is on the floor
  // Matman v 0.03
  void self = getlocalvar("self"); //Get calling entity.
  if ( checkent(self) == 1 ) {
    killentityonfloor(self, heightisbelow);
  }
}



void killselfoutofzboundry(int outby)
{
  //Kills entity if it is on the floor
  // Matman v 0.02
  void self = getlocalvar("self"); //Get calling entity.
  if ( checkent(self) == 1 ) {
    int y = getentityproperty(self, "z");
    int minz = openborvariant("PLAYER_MIN_Z");
    int maxz = openborvariant("PLAYER_MAX_Z");
    //log("\n minz" + minz + " maxz " + maxz + " z " + y);
    //n minz 330   maxz 435   z 392.000000

    if ( y < (minz-outby))
    {
      //for now it disapears entity
      killentity(self);
    }
    if ( y > (maxz+outby) )
    {
      //for now it disapears entity
      killentity(self);
    }
  }
}


void locktarget(int lock, int x, int y, int z)
{ //Binds target to self
  //MatMan v0.03
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void target = getentityproperty(self, "opponent");
    void Health = getentityproperty(target,"health");
    int cancon = 0;

    if ( target != NULL()
      && getentityproperty(target, "speed") > 0 )
    {

    if (lock == 1)
    {
      cancon = isinpainanimation(target);
      if ( cancon == 1 )
      {
      //bindentity(entity, target, int x, int z, int a, int direction, int bindanimation)
      //~bindanimation: 0 No effect. 1 Keep same animation as the target. 2 Also keep same frame as the target. 4 Kill the entity if the animation doesn't match.
        changeentityproperty(target, "animation", openborconstant("ani_pain"));
        bindentity(target, self, x, y, z, 0, 0);
      } else {
        changeentityproperty(target, "animation", openborconstant("ani_pain"));
        bindentity(target, self, x, y, z, 0, 0);
      }
    }else {
     if (lock == 0)
     {
       bindentity(target, NULL());
     } else
     {
       if (lock ==2) //try to set grab status
       {
         bindentity(target, NULL());
         /*
         changeentityproperty(self, "animation", openborconstant("ANI_GRAB"));
         changeentityproperty(target, "animation", openborconstant("ani_pain"));
         changeentityproperty(target, "aiflag", "idling", 0);
         changeentityproperty(self, "aiflag", "idling", 0);
         changeentityproperty(self, "takeaction", "common_grab");
         changeentityproperty(target, "takeaction", "common_grabbed");
         */
     }
    }
  }
  if (Health < 1)
  {
    changeentityproperty(target, "aiflag", "autokill", 1);
  }
  }
  }
}


void stopself(int i)
{// Stop enemy's movement!
 //Matman V 0.03

    void vSelf = getlocalvar("self");
    if ( checkent(vSelf) == 1 ) {
      changeentityproperty(vSelf, "aiflag", "running", 0);
      changeentityproperty(vSelf, "animation", openborconstant("ANI_Idle"));
      changeentityproperty(vSelf, "velocity", 0, 0, 0);
    }
}


void stunself(int btime)
{
  //v0.02
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    stunentity(self, btime);
  }
}


void teleportbehindnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
  // V 0.02
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==0){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player
    void target = getlocalvar("T"+self);
    enemdir = getentityproperty(target, "direction");

    if( getlocalvar("T"+self) != NULL()){

      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");


      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
      if (dir == 0)
      {
        if (Tx+dx > dx)
        {
          changeentityproperty(self, "direction", 1);
        } else
        {
          changeentityproperty(self, "direction", 0);
        }
      } else
      {
         if (Tx+dx > dx)
        {
          changeentityproperty(self, "direction", 0);
        } else
        {
          changeentityproperty(self, "direction", 1);
        }
      }
      //changeentityproperty(self, "direction", enemdir); //Teleport to target!
    }
}


void teleportinfrontnearestenemy(int dx, int dy, int dz)
{// Targetting opponent then teleport to target
 // V 0.02
    void self = getlocalvar("self");
    int dir = getentityproperty(self, "direction");
    int enemdir = 0;

    if(dir==1){ // Facing left?
      dx = -dx ;
    }

    setlocalvar("T"+self, findtarget(self)); //Get nearest player
    void target = getlocalvar("T"+self);
    enemdir = getentityproperty(target, "direction");

    if( getlocalvar("T"+self) != NULL()){

      int Tx = getentityproperty(target, "x");
      int Tz = getentityproperty(target, "z");

      if (enemdir==1)
      {
        enemdir = 0;
      } else
      if (enemdir==0)
      {
        enemdir = 1;
      }

      changeentityproperty(self, "position", Tx+dx, Tz+dz, dy); //Teleport to target!
      changeentityproperty(self, "direction", enemdir); //Teleport to target!
    }
}


void tossself(int changedirection, float x, float y, float z)
{
  // v 0.04 MatMan
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    int Direction = getentityproperty(self, "direction");
    if (Direction == 0)
    { //left
      tossentity(self, y, x, z);
      if ( changedirection = 1)
      {
        changeentityproperty(self, "direction", 1);
      }
    } else {
      tossentity(self, y, -x, z);
      if ( changedirection = 1)
      {
        changeentityproperty(self, "direction", 0);
      }
    }
  }
}


void tossselfbykey(void Key, int Hflag, int changedirection, float x, float y, float z)
{ //Throws self if a key combo is pressed during an animation
  //V0.06 Matman
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    int Direction = getentityproperty(self, "direction");
    void iRKey = checkkeycombo(self, Key, Hflag);
    if (iRKey)
     {
       if (Direction == 0){ //left
         tossentity(self, y, x, z);
         if ( changedirection = 1)
         {
           changeentityproperty(self, "direction", 1);
         }

       } else {
         tossentity(self, y, -x, z);
         if ( changedirection = 1)
         {
           changeentityproperty(self, "direction", 0);
         }
         if ( getentityproperty(self, "a") > 20)
         {
           statusjump(1, self);
           //changeentityproperty(self, "aiflag", "jumping", 1);
         }
       }
     }
   }
}




void scaleentityself(int scaleX, int scaleY)
{
  //Matman V 0.02
  //scalex/y 256 is default full size. Less is smaller, more is bigger.
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
    scaleentity(vSelf,scaleX, scaleY);
  }
}




void spawnchildandtoss(void vName, float fX, float fY, float fZ, float vX, float vY, float vZ, int gravity )
{
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
        //vX: X Velocity.
        //vY: Y Velocity.
        //vZ: Z Velocity.
        //gravity: Set gravity
        //Matman v0.05
	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	if ( self != NULL() )
	{
          void Health = getentityproperty(self,"health");
          int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.

          vSpawn = spawnchildentityforparent(vName, self, fX, fY, fZ, 1);
          if ( gravity == 1)
          {
            changeentityproperty(vSpawn, "subject_to_gravity", 0);
          }
          else
          {
            changeentityproperty(vSpawn, "subject_to_gravity", 1);
          }
          if (iDirection == 0)
          { //left
           tossentity(vSpawn, vY, vX, vZ);
          } else
          {
            tossentity(vSpawn, vY, -vX, vZ);
          }
        }
	return vSpawn; //Return spawn.
}


void spawnchildandtossDirection(void vName, float fX, float fY, float fZ, float vX, float vY, float vZ, int gravity, int changedirection )
{
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
        //vX: X Velocity.
        //vY: Y Velocity.
        //vZ: Z Velocity.
        //gravity: Set gravity
        //changedirection: 1 = will change direction
        //Matman v0.04

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
	if ( self != NULL())
	{
          void Health = getentityproperty(self,"health");
	  int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.

	  vSpawn = spawnchildentityforparent(vName, self, fX, fY, fZ, 1);
	  /*
          loadmodel(vName);
          clearspawnentry(); //Clear current spawn entry.
          setspawnentry("name", vName); //Acquire spawn entity by name.
	  if (iDirection == 0){ //Is entity facing left?
            fX = -fX; ////Reverse X direction to match facing.
	  }
          fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
          fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
          fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.
	  vSpawn = spawn(); //Spawn in entity.
	  changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
          changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
          changeentityproperty(vSpawn, "parent", self);
          */
          if ( gravity == 1)
          {
            changeentityproperty(vSpawn, "subject_to_gravity", 0);
          }
          else
          {
            changeentityproperty(vSpawn, "subject_to_gravity", 1);
          }
          if (changedirection == 1)
          {
            if (iDirection == 1){
                 iDirection = 0;
                 changeentityproperty(vSpawn, "direction", 0);
            } else {
                 iDirection = 1;
                 changeentityproperty(vSpawn, "direction", 1);
            }
          }

          if (iDirection == 0)
          { //left
           tossentity(vSpawn, vY, vX, vZ);
          } else
          {
            tossentity(vSpawn, vY, -vX, vZ);
          }
        }

	return vSpawn; //Return spawn.
}


void spawnchildentity(void vName, float fX, float fY, float fZ)
{
      //Spawns entity next to caller.
      //
      //vName: Model name of entity to be spawned in.
      //fX: X location adjustment.
      //fZ: Y location adjustment.
      //fY: Z location adjustment.

      //Matman V0.05

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.

	vSpawn = spawnchildentityforparent(vName, self, fX, fY, fZ, 1);

	return vSpawn; //Return spawn.
}


void spawnentity(void vName, float fX, float fY, float fZ, int iH)
{
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
        //fY: Z location adjustment.
        //iH: Spawn type.


	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn; //Spawn object.
        void Health = getentityproperty(self,"health");
	int  iDirection = getentityproperty(self, "direction"); // Get caller's direction.
	int  iMap = getentityproperty(self, "map"); // Get caller's remap.

        loadmodel(vName);

	clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", vName); //Acquire spawn entity by name.

	if (iDirection == 0){ //Is entity facing left?
          fX = -fX; ////Reverse X direction to match facing.
	}

      fX = fX + getentityproperty(self, "x"); //Get X location and add adjustment.
      fY = fY + getentityproperty(self, "a"); //Get Y location and add adjustment.
      fZ = fZ + getentityproperty(self, "z"); //Get Z location and add adjustment.

	vSpawn = spawn(); //Spawn in entity.

	changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
	changeentityproperty(vSpawn, "direction", iDirection); //Set direction.

	if (iH == 0){ // For spawning AI control entity
	  //changeentityproperty(vSpawn, "parent", self); //Set caller as parent.
      }
	if (iH == 1){ // For spawning dead fallen rider
        damageentity(vSpawn, self, 1000, 1, openborconstant("ATK_NORMAL"));
	  if (iDirection == 1){
          tossentity(vSpawn, 3, -1, 0);
        } else {tossentity(vSpawn, 3, 1, 0);}
      }
	if (iH == 2){ // For spawning motor
	  changeentityproperty(vSpawn, "map", iMap); //Set map.
      }
	return vSpawn; //Return spawn.
}


void spawnentitybyallenemy(void vName, float fX, float fY, float fZ)
{
  //Spawns an entity relative to each enemy target.
  //Matman  v0.04
    void    vEnt;                                                                           //Entity placeholder.
    int     iType;                                                                          //Entity type.
    int     iValid;                                                                         //Entity valid.
    int     iDead;                                                                          //Entity death status.
    int     iECnt;                                                                          //Current # of entities in play.
    int     iEnt;                                                                           //Entity counter.
    int Tx = 0;
    int Ty = 0;
    int Tz = 0;
    int Direction = 0;
    void spawned = 0;
    void self = getlocalvar("self");

    iECnt   = openborvariant("ent_max");                                                    //Get current entity count.

	for(iEnt=0; iEnt<iECnt; iEnt++)                                                         //Loop entity collection.
	{
		vEnt    = getentity(iEnt);                                                          //Get entity handle.

        if(vEnt)                                                                            //Valid handle?
        {
            iValid  = getentityproperty(vEnt, "exists");                                    //Get exists confirmation.
            iDead   = getentityproperty(vEnt, "dead");                                      //Get death status.
            iType   = getentityproperty(vEnt, "type");                                      //Get type.

            if(vEnt                                                                         //Valid handle?
                && iValid                                                                   //Valid entity?
                && !iDead                                                                   //Alive?
                && iType == openborconstant("TYPE_ENEMY"))                                  //Enemy type?
            {
                Tx = getentityproperty(vEnt, "x");
                Ty = getentityproperty(vEnt, "a");
                Tz = getentityproperty(vEnt, "z");

                //spawned = spawnchildentityforparent(vName, self, (fX), (fY), (fZ), 0);
                if ( Direction == 0)
                {
                  spawned = spawnchildentityforparent(vName, self, (Tx+fX), (Ty+fY), (Tz+fZ), 0);
                  changeentityproperty(spawned, "direction",1);
                } else
                {
                  fX = -fX;
                  Tx = -Tx;
                  spawned = spawnchildentityforparent(vName, self, (Tx-fX), (Ty+fY), (Tz+fZ), 0);
                  changeentityproperty(spawned, "direction",0);
                }
                /*
                //log(" \n Tx " + Tx + " Ty " + Ty + " Tz " + Tz + " vName " + vName);
                Direction = getentityproperty(vEnt, "direction");
                spawned = spawnentity(vName, 0, 0, 0, 0);
                //void spawnchildentity(void vName, float fX, float fY, float fZ, int iH)
                if  (Direction == 0)
                {
                  changeentityproperty(spawned, "direction",1);
                  changeentityproperty(spawned, "position", (Tx+fX), (Tz+fZ), (Ty+fY)); //Teleport to target!

                } else
                {
                  //fX = -fX;
                  //Tx = -Tx;
                  changeentityproperty(spawned, "direction",0);
                  changeentityproperty(spawned, "position", (Tx-fX), (Tz+fZ), (Ty+fY));
                }
                */

            }
        }
	}
}


void spawnentitylesspercentage(void vName, float fX, float fY, float fZ, int iH, int lessthanprecentage)
{//Only spawns if health percentage is less that specified
	//Spawns entity next to caller.
	//
	//vName: Model name of entity to be spawned in.
	//fX: X location adjustment.
	//fZ: Y location adjustment.
      //fY: Z location adjustment.
      //iH: Spawn type.

	void self = getlocalvar("self"); //Get calling entity.
	void vSpawn;
        float spawnershealth = gethealthpercentageforentity(self);


	if (spawnershealth < lessthanprecentage )
	{
	  //settextobj(1, 100, 50, 0, -1, getentityproperty(self,"health"));
           vSpawn = spawnentity(vName,fX,fY,fZ,iH);
        }
	return vSpawn; //Return spawn.
}




void decreasehealth(int amount)
{// increase current mp amount. Not max Mp.
// V0.02
    void self = getlocalvar("self");
    if ( self != NULL() && getentityproperty(self, "exists")) {
      void cmp = getentityproperty(self,"health");
      cmp = cmp - amount;
      if (cmp <= 0) {
        killentity(self);
      } else {
      changeentityproperty(self, "health", cmp);
      }
    }
}


void decreasemp(int amount)
{// Decrease current mp amount. Not max Mp.
// V0.02
    void self = getlocalvar("self");
    if ( self != NULL() && getentityproperty(self, "exists")) {
      void cmp = getentityproperty(self,"mp");
      cmp = cmp - amount;
      changeentityproperty(self, "mp", cmp);
    }
}


void decreasempthenhealth(int amount)
{// Decrease current mp amount and if its less than 0 then decrease health. Not max Mp.
// V0.02
    void self = getlocalvar("self");
    if ( self != NULL() && getentityproperty(self, "exists")) {
      void health = getentityproperty(self,"health");
      void cmp = getentityproperty(self,"mp");
      cmp = cmp - amount;
      if (cmp <= 0)
      {
        health = health + (cmp / 2);
        cmp = 0;
      }
      changeentityproperty(self, "mp", cmp);
      changeentityproperty(self, "health", health);
    }
}


void increasehealth(int amount)
{// increase current mp amount. Not max Mp.
// V0.02
    void self = getlocalvar("self");
    if ( self != NULL() && getentityproperty(self, "exists")) {
      void cmp = getentityproperty(self,"health");
      cmp = cmp + amount;
      changeentityproperty(self, "health", cmp);
    }
}


void increasemp(int amount)
{// increase current mp amount. Not max Mp.
// V0.02 MatMan
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      int cmp = getentityproperty(self,"mp");
      cmp = cmp + amount;
      changeentityproperty(self, "mp", cmp);
    }
}


void setslowmotion(int istrue)
{ // set slow motion status
// V0.02 Matman
  int slow = openborvariant("slowmotion");
  if (slow != istrue)
  {
    changeopenborvariant("slowmotion", istrue);
  }

}


void subjecttogravity(int isfalse)
{// change gravity setting
// V0.02
    void self = getlocalvar("self");
    if ( self != NULL() && getentityproperty(self, "exists")) {
      changeentityproperty(self, "subject_to_gravity", isfalse);
    }
}




void grabfree(int isTrue, void vself)
{// releases player and enemy grab state
  // V 0.02
   //void self = getlocalvar("self");
   void target = getentityproperty(vself, "opponent");
   //void target = getlocalvar("Target" + vself);

   if(target==NULL())
   {
     target = getentityproperty(vself, "grabbing");
     setlocalvar("Target" + vself, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());
     bindentity(vself, NULL());
     changeentityproperty(target, "aiflag", "idling", 1);
     changeentityproperty(target, "animation", openborconstant("ani_idle"));
     //performattack(target, openborconstant("ANI_IDLE"));
     //performattack(vself, openborconstant("ANI_IDLE"));
     /*
     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
     */
   }
}


void grabrelease(int Gr)
{// Release grabbed entity
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     bindentity(target, NULL());

     if(Gr == 1)
     {
       int x = getentityproperty(target, "x");
       int z = getentityproperty(target, "z");
       changeentityproperty(target, "position", x, z, 0);
     }
   }
}


void throwenemy(int height, int speedx, int speedz)
{ //
// V0.01 Matman
   void self = getlocalvar("self");
   void target = getlocalvar("Target" + self);

   if(target==NULL())
   {
     target = getentityproperty(self, "grabbing");
     setlocalvar("Target" + self, target);
   }
   if(target!=NULL())
   {
     tossentity(target, height, speedx, speedz);
   }

}




int countaliveenemies(int istrue)
{ // Count how many alive enemies there are
// V0.02 Matman
   int cnt = 0;
   if ( openborvariant("count_enemies") != NULL() ) { cnt = openborvariant("count_enemies"); }
   return cnt;
}


int countaliveplayers(int istrue)
{ // Count how many alive players there are
// V0.02 Matman
   int cnt = 0;
   if ( openborvariant("count_players") != NULL() ) { cnt = openborvariant("count_players"); }
   return cnt;
}


void getdifficulty(int istrue)
{ // Get current difficulty setting
// V0.02 Matman
     int cnt = 0;
     if ( openborvariant("current_set") != NULL() ) { cnt = openborvariant("current_set"); }
     return cnt;

}


int getheight(void entity)
{ // Get entities height
// V0.03 Matman
   int cnt = 0;
   if ( checkent(entity) == 1 ) {
     if ( getentityproperty(entity, "height") ) { cnt = getentityproperty(entity, "height"); }
     //getentityproperty({ent}, "height"); - Model level height setting.
     //getentityproperty({ent}, "animheight"); - Animation level height setting (current animation).
   }
   return cnt;
}


void invincibleentity(void entity, int btime)
{
  //MatMan v0.02
  if ( checkent(entity) == 1 ) {
        void iTime = openborvariant("elapsed_time") + getentityproperty(entity, "freezetime");

        changeentityproperty(entity, "invincible", 1);
        changeentityproperty(entity, "invinctime", iTime + btime);
  }
        return entity;
}


void isinfallanimation(void target)
{
  // v 0.03 Matman
  void canCont = 0;
  if ( checkent(target) == 1 ) {
    void aniID = getentityproperty(target, "animationid");

    if (aniID == openborconstant("ANI_FALL")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL2")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL3")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL4")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL5")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL6")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL7")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL8")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL9")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_FALL10")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_SHOCK")) { canCont = 1; } else
    if (aniID == openborconstant("ANI_BURN")) { canCont = 1; }
  }
  return canCont;
}


void isinpainanimation(void target)
{
  // v 0.03 Matman
  int canCont = 0;
  if ( checkent(target) == 1 ) {
    int aniID = getentityproperty(target, "animationid");

    if ( aniID == openborconstant("ANI_PAIN")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN2")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN3")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN4")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN5")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN6")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN7")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN8")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_PAIN9")) { canCont = 1;} else
    if (aniID == openborconstant("ANI_SHOCKPAIN")) { canCont = 1; } else
    if (aniID == openborconstant("ANI_BURNPAIN")) { canCont = 1; } else
    if (aniID == openborconstant("ANI_BLOCKPAIN")) { canCont = 1; }
  }
  return canCont;
}


void keypressmultileft(void Key, int iPIndex)
{// returns a openbor key if succesful in-put was entered when facing left
//V0.04 MatMan
    void iRKey;
      //Direction
      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else
        if (Key=="D"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else
        if (Key=="B"){ //Backwards Required?
          iRKey = playerkeys(iPIndex, 0, "moveright");
	} else
        if (Key=="F"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft");
	} else
      //Keys
        if (Key=="J"){ //Jump Required?
          iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else
        if (Key=="A"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
        } else

	if (Key=="A2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack"
        } else
        if (Key=="DA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack2"); // "Attack"
        } else
        if (Key=="UA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack2"); // "Attack"
        } else
        if (Key=="BA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveright","attack2"); // "Attack"
        } else
        if (Key=="FA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft","attack2"); // "Attack"
        } else

	if (Key=="A3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack"
        } else
        if (Key=="DA3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack2"); // "Attack"
        } else
        if (Key=="UA3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack2"); // "Attack"
        } else

	if (Key=="A4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack"
	} else
	if (Key=="DA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack4"); // "Attack"
        } else
        if (Key=="UA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack4"); // "Attack"
        } else
        if (Key=="BA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveright","attack4"); // "Attack"
        } else
        if (Key=="FA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft","attack4"); // "Attack"
        } else

        if (Key=="S"){ //Special Required?
          iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	} else
      if (Key=="JS"){ //Special + jump Required?
        iRKey = playerkeys(iPIndex, 0, "special", "jump"); // "Special"
	} else
      //Direction Plus Attack
      if (Key=="UA"){ //Up Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "attack"); // "Up Attack"
	} else
      if (Key=="DA"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "attack"); // "Down Attack"
	} else
      if (Key=="BA"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "attack");
	} else
      if (Key=="FA"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "attack");
	} else
      //Direction Plus Jump
      if (Key=="UJ"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	} else
      if (Key=="DJ"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "jump"); // "Down" + "Jump"
	} else
      if (Key=="BJ"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "jump"); // "Back" + "Jump"
	} else
      if (Key=="FJ"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "jump"); // "Forwad" + "Jump"
	} else
      //Direction Plus Special
      if (Key=="US"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "special"); // "Up" + "special"
	} else
      if (Key=="DS"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "special"); // "Down" + "special"
	}
      return iRKey;
}


void keypressmultiright(void Key, int iPIndex)
{// returns a openbor key if succesful in-put was entered when facing right
//V0.04 MatMan
    void iRKey;
      //Direction
      if (Key=="U"){ //Up Required?
       iRKey = playerkeys(iPIndex, 0, "moveup"); // "Up"
	} else
        if (Key=="D"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "movedown"); // "Down"
	} else
        if (Key=="B"){ //Backwards Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft"); // "Backwards"
	} else
        if (Key=="F"){ //Down Required?
          iRKey = playerkeys(iPIndex, 0, "moveright"); // "Forward"
	} else
      //Keys
        if (Key=="J"){ //Jump Required?
          iRKey = playerkeys(iPIndex, 0, "jump"); // "Jump"
	} else
        if (Key=="A"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack"); // "Attack"
        } else

	if (Key=="A2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack2"); // "Attack"
        } else
        if (Key=="DA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack2"); // "Attack"
        } else
        if (Key=="UA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack2"); // "Attack"
        } else
        if (Key=="BA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft","attack2"); // "Attack"
        } else
        if (Key=="FA2"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveright","attack2"); // "Attack"
        } else

	if (Key=="A3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack3"); // "Attack"
        } else
        if (Key=="DA3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack3"); // "Attack"
        } else
        if (Key=="UA3"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack3"); // "Attack"
        } else

	if (Key=="A4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "attack4"); // "Attack"
	} else
	if (Key=="DA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "movedown", "attack4"); // "Attack"
        } else
        if (Key=="UA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveup","attack4"); // "Attack"
        } else
        if (Key=="BA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveleft","attack4"); // "Attack"
        } else
        if (Key=="FA4"){ //Attack Required?
          iRKey = playerkeys(iPIndex, 0, "moveright","attack4"); // "Attack"
        } else

        if (Key=="S"){ //Special Required?
          iRKey = playerkeys(iPIndex, 0, "special"); // "Special"
	} else
       if (Key=="JS"){ //Special Required?
        iRKey = playerkeys(iPIndex, 0, "special", "jump"); // "Special"
	} else
      //Direction Plus Attack
      if (Key=="UA"){ //Up Attack Required?
        iRKey = playerkeys(iPIndex, 0, "moveup", "attack"); // "Up Attack"
	} else
      if (Key=="DA"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "attack"); // "Down Attack"
	} else
      if (Key=="BA"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "attack"); // "Backwards"
	} else
      if (Key=="FA"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "attack"); // "Forward"
	} else
      //Direction Plus Jump
      if (Key=="UJ"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "jump"); // "Up" + "Jump"
	} else
      if (Key=="DJ"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "jump"); // "Down" + "Jump"
	} else
      if (Key=="BJ"){
        iRKey = playerkeys(iPIndex, 0, "moveleft", "jump"); // "Back" + "Jump"
	} else
      if (Key=="FJ"){
        iRKey = playerkeys(iPIndex, 0, "moveright", "jump"); // "Forwad" + "Jump"
	} else
      //Direction Plus Special
      if (Key=="US"){
        iRKey = playerkeys(iPIndex, 0, "moveup", "special"); // "Up" + "special"
	} else
      if (Key=="DS"){
        iRKey = playerkeys(iPIndex, 0, "movedown", "special"); // "Down" + "special"
	}
      return iRKey;
}


void killentityonfloor(void entity, int heightisbelow)
{
  //Kills entity if it is on the floor
  // Matman v 0.03
  if ( checkent(entity) == 1 ) {
    int y = 0;
    if ( getentityproperty(entity, "a") != NULL() ){ y = getentityproperty(entity, "a"); }
    if ( y < heightisbelow)
    {
      //for now it disapears entity
      killentity(entity);
    }
  }
}


void scaleentity(void entity, int scaleX, int scaleY)
{
  //Matman V 0.03
  //scalex/y 256 is default full size. Less is smaller, more is bigger.
  if ( checkent(entity) == 1 ) {
    //setdrawmethod(entity, int flag, int scalex, int scaley, int flipx, int flipy, int shiftx, int alpha, int remap, int fillcolor, int rotate, int fliprotate, int transparencybg, pointer colormap)
    setdrawmethod(entity, 1, scaleX, scaleY);
  }
  return entity;
}


void statusgrabbed(int istrue, void target)
{
  //Set targets thrown status-
  //Istrue = 1 (is true)
  // Matman V 0.06
  if ( checkent(target) == 1 ) {
    void opponent = getentityproperty(target, "opponent");
    if (istrue == 1)
    {
      //this doesn't work yet...
      changeentityproperty(target, "aiflag", "inpain", 0);
      changeentityproperty(target, "aiflag", "idling", 0);
      changeentityproperty(target, "aiflag", "falling", 1);
      changeentityproperty(target, "aiflag", "drop", 1);

      changeentityproperty(target, "attacking", 1);
      changeentityproperty(target, "projectile", 1);
    } else {
      //this might work?
      changeentityproperty(target, "aiflag", "idling", 1);
      changeentityproperty(target, "attacking", 1);
      changeentityproperty(target, "projectile", 0);

      changeentityproperty(opponent, "aiflag", "idling", 1);
    }
  }
}


void statusjump(int istrue, void target)
{
  //Set targets jump status-
  //Istrue = 1 (is true)
  // Matman V 0.04
  if ( checkent(target) == 1 ) {
    if (istrue == 1)
    {
      changeentityproperty(target, "aiflag", "turning", 0);
      changeentityproperty(target, "aiflag", "inpain", 0);
      changeentityproperty(target, "aiflag", "idling", 0);
      changeentityproperty(target, "aiflag", "running", 0);
      //changeentityproperty(target, "takeaction", "fall");
      changeentityproperty(target, "aiflag", "jumping", 1);
      //changeentityproperty(target, "aiflag", "drop", 0);
      changeentityproperty(target, "attacking", 1);
      changeentityproperty(target, "projectile", 0);
      changeentityproperty(target, "takeaction", "common_jump");
    } else {
      changeentityproperty(target, "attacking", 1);
      changeentityproperty(target, "damage_on_landing", 0);
      changeentityproperty(target, "projectile", 0);
      changeentityproperty(target, "aiflag", "jumping", 0);
    }
  }
}


void statusreset(int isTrue)
{
  // matman v0.04
  void self = getlocalvar("self");
  if ( getentityproperty(self, "exists")
   && !getentityproperty(self, "dead") )
    {
      changeentityproperty(self, "aiflag", "projectile", 0);
      bindentity(self, NULL());
    }
    if (openborvariant("slowmotion") == 1 )
    {
      changeopenborvariant("slowmotion", 0);
    }
}



void statusthrown(int istrue, void target)
{
  //Set targets thrown status-
  //Istrue = 1 (is true)
  // Matman V 0.07
  if (istrue == 1
      && !getentityproperty(target, "dead")
      && getentityproperty(target, "exists")
      )
  {

    changeentityproperty(target, "aiflag", "turning", 0);
    changeentityproperty(target, "aiflag", "inpain", 0);
    changeentityproperty(target, "aiflag", "idling", 0);
    changeentityproperty(target, "aiflag", "running", 0);

    changeentityproperty(target, "aiflag", "falling", 1);
    changeentityproperty(target, "aiflag", "drop", 1);

    changeentityproperty(target, "attacking", 1);
    changeentityproperty(target, "projectile", 1);
    changeentityproperty(target, "takeaction", "common_fall");
    //changeentityproperty(target, "takeaction", "common_vault");
  } else {
    if (
          !getentityproperty(target, "dead")
      && getentityproperty(target, "exists")
       )
    changeentityproperty(target, "attacking", 1);
    changeentityproperty(target, "damage_on_landing", 0);
    changeentityproperty(target, "projectile", 0);
  }
}


void stunentity(void entity, int btime)
{
  //MatMan v0.03
  if ( checkent(entity) == 1 ) {
        //Get current time and any previous freezetime, then apply it to target.
        void iTime = openborvariant("elapsed_time") + getentityproperty(entity, "freezetime");

        changeentityproperty(entity, "frozen", 1);
        changeentityproperty(entity, "freezetime", iTime + btime);
  }
  return entity;
}




void changeanibykeytoattack(void self, void Ani, int Frame, void Key, int Hflag, int Limit)
{// Change current animation if proper key is pressed or released provided HP is more than limit
// V0.010
// Matman
    if ( checkent(self) == 1 ) {
      if ( getentityproperty(self, "animationid") != openborconstant(Ani)  )
      {
        void Health = getentityproperty(self,"health");
        void iRKey = 0;
        void isFalling = 0;
        iRKey = checkkeycombo(self, Key, Hflag);
        if ((Health > Limit)&&iRKey){
          isFalling = isinfallanimation(self);
          if (isFalling == 1) { statusjump(1, self); }
          //changeentityproperty(self, "animation", openborconstant(Ani)); //Change the animation
          //changeentityproperty(self, "animpos", 0);
          performattack(self, openborconstant(Ani), 1);
        }
      }
    }
}


void checkent(void self)
{
  // V0.03 matman
  //Checks if a entity is alive and valid
  void s;
  if ( self != NULL() )
  {
    if (
       getentityproperty(self, "exists")
   && !getentityproperty(self, "dead")
   //&& getentityproperty( self, "aiflag", "autokill" ) == 0
   //changeentityproperty(self, "aiflag", "dead", 1 );
   //&& getentityproperty( self, "aiflag", "animating" ) == 1
   //&&  getentityproperty(self, "health")>0
    ) {
      //_gep_aiflag_autokill
      s = 1;
    }
  }
  return s;
}


void freeentity(void entity)
{ // Kills entity without playing the death animation
// V0.02 Matman
  if ( entity != NULL()
    && getentityproperty(entity, "exists") )
  {
     killentity(entity);
  }
}




void namefemalemedieval(int isTrue)
{
  //V0.02 Matman
  int i = rand()%45;
  void s = "";
  if (i < 0 )
     {i= -i;}


  if(i==0){s = "Alys";}  else
  if(i==1){s = "Ayleth";} else
  if(i==2){s = "Anastas";} else
  if(i==3){s = "Alianor";} else
  if(i==4){s = "Cedany";} else
  if(i==5){s = "Ellyn";} else
  if(i==6){s = "Helewys";} else
  if(i==7){s = "Malkyn";} else
  if(i==8){s = "Peronell";} else
  if(i==9){s = "Sybbyl";} else
  if(i==10){s = "Ysmay";} else
  if(i==11){s = "Thea";} else
  if(i==12){s = "Jacquelyn";} else
  if(i==13){s = "Countess Amelia";} else
  if(i==14){s = "Gloriana";} else
  if(i==15){s = "Good Queen Bess";} else
  if(i==16){s = "Catherine of Aragon";} else
  if(i==17){s = "Anne of Cleves";} else
  if(i==18){s = "Mary, Queen of Scots";} else
  if(i==19){s = "Mary of Guise";} else
  if(i==20){s = "Arabella";} else
  if(i==21){s = "Elizabeth";} else
  if(i==22){s = "Hildegard";} else
  if(i==23){s = "Brunhild";} else
  if(i==24){s = "Adelaide";} else
  if(i==25){s = "Alice";} else
  if(i==26){s = "Beatrix";} else
  if(i==27){s = "Cristiana";} else
  if(i==28){s = "Eleanor";} else
  if(i==29){s = "Emeline";} else
  if(i==30){s = "Isabel";} else
  if(i==31){s = "Juliana";} else
  if(i==32){s = "Margaret";} else
  if(i==33){s = "Matilda";} else
  if(i==34){s = "Mirabelle";} else
  if(i==35){s = "Rose";} else
  if(i==36){s = "Helena";} else
  if(i==37){s = "Guinevere";} else
  if(i==38){s = "Isolde";} else
  if(i==39){s = "Maerwynn";} else
  if(i==40){s = "Muriel";} else
  if(i==41){s = "Winifred";} else
  if(i==42){s = "Godiva";} else
  if(i==43){s = "Catrain";} else
  if(i==44){s = "Angmar";} else
  if(i==45){s = "Gussalen";}

  if (s=="") { s = namefemalemedieval(1); }

  return s;
}


void namemalemedieval(int isTrue)
{
  //V0.02 Matman
  int i = rand()%41;
  void s = "";

  if (i < 0 )
     {i= -i;}


  if(i==0){s = "Ulric";}  else
  if(i==1){s = "Tybalt";} else
  if(i==2){s = "Borin";} else
  if(i==3){s = "Sadon";} else
  if(i==4){s = "Terrowin";} else
  if(i==5){s = "Rowan";} else
  if(i==6){s = "Forthwind";} else
  if(i==7){s = "Althalos";} else
  if(i==8){s = "Fendrel";} else
  if(i==9){s = "Brom";} else
  if(i==10){s = "Hadrian";} else
  if(i==11){s = "Crewe";} else
  if(i==12){s = "Walter De Bolbec";} else
  if(i==13){s = "Derwintwater";} else
  if(i==14){s = "Montagu";} else
  if(i==15){s = "John Fenwick of Wallington";} else
  if(i==16){s = "Oliver Cromwell";} else
  if(i==17){s = "Justice McKinnon";} else
  if(i==18){s = "Clifton Writingham";} else
  if(i==19){s = "Walter deGrey";} else
  if(i==20){s = "Roger de Mowbray";} else
  if(i==21){s = "Joseph Rowntree";} else
  if(i==22){s = "Geoffrey Chaucer";} else
  if(i==23){s = "William of Wykeham";} else
  if(i==24){s = "Francis Drake";} else
  if(i==25){s = "Simon de Montfort";} else
  if(i==26){s = "John of Gaunt";} else
  if(i==27){s = "William of Orange";} else
  if(i==28){s = "Cornwallis";} else
  if(i==29){s = "Edmund Cartwright";} else
  if(i==30){s = "Charles the Bald";} else
  if(i==31){s = "Benedict";} else
  if(i==32){s = "Gregory";} else
  if(i==33){s = "Peter";} else
  if(i==34){s = "Henry";} else
  if(i==35){s = "Frederick";} else
  if(i==36){s = "Walter";} else
  if(i==37){s = "Thomas";} else
  if(i==38){s = "Arthur";} else
  if(i==39){s = "Bryce";} else
  if(i==40){s = "Donald";} else
  if(i==41){s = "Leofrick";}

  if (s=="") { s = namemalemedieval(1); }

  return s;
}




void spawnchildentityforparent(void vName, void parent, float fX, float fY, float fZ, int byParent)
{
      //
      //vName: Model name of entity to be spawned in.
      //fX: X location adjustment.
      //fZ: Y location adjustment.
      //fY: Z location adjustment.
      //byParent: 1 = Spawn entity relative to parent
      //Matman V0.07
	void vSpawn; //Spawn object.
	int  iDirection = 0;

        loadmodel(vName);

        clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", vName); //Acquire spawn entity by name.
        if ( checkent(parent) == 1 ) {
          iDirection = getentityproperty(parent, "direction"); // Get caller's direction.
          if ( byParent == 1 )
          {
	    if (iDirection == 0){ //Is entity facing left?
              fX = -fX; ////Reverse X direction to match facing.
            }
            fX = fX + getentityproperty(parent, "x"); //Get X location and add adjustment.
            fY = fY + getentityproperty(parent, "a"); //Get Y location and add adjustment.
            fZ = fZ + getentityproperty(parent, "z"); //Get Z location and add adjustment.
          }
          vSpawn = spawn(); //Spawn in entity.
          if ( getentityproperty(parent,"offense", openborconstant("ATK_NORMAL")) != 0 )
          {
            setoffenseforentity(vSpawn, openborconstant("ATK_NORMAL"), getentityproperty(parent,"offense", openborconstant("ATK_NORMAL")));
          }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_NORMAL2")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_NORMAL2"), getentityproperty(parent,"offense", openborconstant("ATK_NORMAL2")));
	  }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_BLAST")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_BLAST"), getentityproperty(parent,"offense", openborconstant("ATK_BLAST")));
	  }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_BURN")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_BURN"), getentityproperty(parent,"offense", openborconstant("ATK_BURN")));
	  }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_FREEZE")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_FREEZE"), getentityproperty(parent,"offense", openborconstant("ATK_FREEZE")));
	  }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_SHOCK")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_SHOCK"), getentityproperty(parent,"offense", openborconstant("ATK_SHOCK")));
	  }
	  if ( getentityproperty(parent,"offense", openborconstant("ATK_STEAL")) != 0 )
	  {
	    setoffenseforentity(vSpawn, openborconstant("ATK_STEAL"), getentityproperty(parent,"offense", openborconstant("ATK_STEAL")));
	  }
	  changeentityproperty(vSpawn, "parent", parent);
	}

  changeentityproperty(vSpawn, "position", fX, fZ, fY); //Set spawn location.
  changeentityproperty(vSpawn, "direction", iDirection); //Set direction.
  return vSpawn; //Return spawn.
}


void spawnentitybyrate(void self, void newent, int spawnamount, int movexby, int movezby, int startzbyself)
{
  // Spawns x amount of entitie's and move each spawned entity by x,z amount
  // MatMan v0.02
  // startzbyself = Will start creating spawn by self entity else it will start a stages min z value
  //void self = getlocalvar("self");
  void spawned;
  if ( checkent(self) == 1 ) {
    void fMinZ		=	openborvariant("PLAYER_MIN_Z");
    void fMaxZ		=	openborvariant("PLAYER_MAX_Z");
    void totalZ = fMaxZ-fMinZ ;
    int x = 0;
    int z = 0;
    int i = 0;
    loadmodel(newent);
    x = getentityproperty(self, "x");
    if ( startzbyself == 1 )
    {
      z = getentityproperty(self, "z");
    } else  { z = fMinZ + 5; }
    for( i=0; i<spawnamount; i++)
    {
      if (i!= 0)
      {
        x = x + movexby;
        z = z + movezby;
      }
      if ( checkwall(x, z) < 1 )
      {
        clearspawnentry(); //Clear current spawn entry.
        setspawnentry("name", newent); //Acquire spawn entity by name.
        spawned = spawn(); //Spawn in entity.
        //spawned = spawnentity(newent, x, position, 1, 0)
        changeentityproperty(spawned, "position", x, z, 1); //Set spawn location.
      }
    }
  }
  return spawned;
}


void spawnentitydivbyz(void self, void newent, int divby, int movexby)
{
  // Spawns entity by divby amount of times and will spread evenly via the lateral depth
  // v0.04
  //void self = getlocalvar("self");
  void spawned;
  if ( self != NULL() && getentityproperty(self, "exists") ) {
    void fMinZ		=	openborvariant("PLAYER_MIN_Z");
    void fMaxZ		=	openborvariant("PLAYER_MAX_Z");
    void totalZ = fMaxZ-fMinZ ;
    //log(" \n totalZ " + totalZ);
    //log(" fMinZ" + fMinZ + " fMaxZ" + fMaxZ);
    void placedposition = (totalZ/divby);
    //log(" \n placedposition " + placedposition);
    int x = 0;
    int position = fMinZ;
    int i = 0;
    loadmodel(newent);
    x = getentityproperty(self, "x");

  for( i=0; i<divby; i++)
  {
    /*
    if ( i == 0) {
      position = fMinZ + ( placedposition*(i+1) - (placedposition/2) - (placedposition/4) ) ; //This places correctly
    } else {
       position = fMinZ + ( placedposition*(i+1) + ((placedposition/2)*(i+1)) - placedposition ) ;
     }
    */
     position = fMinZ + ( placedposition*(i+1) + ((placedposition/2)*(i+1)) - placedposition ) ;
    if ( checkwall(x, position) < 1 )
    {
      //log(" \n position" + position);
      x = x + movexby;
      clearspawnentry(); //Clear current spawn entry.
      setspawnentry("name", newent); //Acquire spawn entity by name.
      spawned = spawn(); //Spawn in entity.
      //spawned = spawnentity(newent, x, position, 1, 0)
      changeentityproperty(spawned, "position", x, position, 1); //Set spawn location.
    }
  }
  }

  return spawned;
}




void checkkeycombo(void vSelf, void Key, int Hflag)
{
  //MatMan V0.03
 void iRKey;
 if ( checkent(vSelf) == 1 ) {
   //int iPIndex = getentityproperty(vSelf,"playerindex");
   //int Direction = getentityproperty(vSelf, "direction");
   if ( getentityproperty(vSelf, "direction") == 0){ //Is entity facing left?
        iRKey = keypressmultileft( Key, getentityproperty(vSelf,"playerindex") );
     //} else if ( getentityproperty(vSelf, "direction") == 1) {
     } else {
        iRKey = keypressmultiright( Key, getentityproperty(vSelf,"playerindex") );
     }
     if (Hflag==1){ //Not holding the button case?
          iRKey = !iRKey; //Take the opposite condition
	}
  }
  return iRKey;
}


void decreasehealthforentity(void aentity, int amount)
{
// V0.05 Matman
    if ( aentity != NULL() && getentityproperty(aentity, "exists") ) {
      void cmp = getentityproperty( aentity,"health" );
      cmp = cmp - amount;
      if (cmp < 1) {
        killentity(aentity);
      } else {
        changeentityproperty(aentity, "health", cmp);
      }
    }
}


void decreasemaxhealthforentity(void aentity,int amount)
{// increase current health amount. Not max health.
// V0.05 Matman
    //void self = getlocalvar("self");
    if ( aentity != NULL() && getentityproperty(aentity, "exists") ) {
      int cmp = getentityproperty(aentity,"health");
      /*
      log("\n health cmp " + cmp);
      log(". amount" + amount );
      cmp = cmp - amount;
      log(". new health " + cmp);
      changeentityproperty(aentity, "health", cmp);
      */
      int maxcmp = getentityproperty(aentity,"maxhealth");
      log("--- maxhealth " + maxcmp);
      maxcmp = maxcmp - amount;
      log(". health " + maxcmp);
      changeentityproperty(aentity, "maxhealth",maxcmp);

      /*
      if (cmp < 1)
      {
        changeentityproperty(aentity, "maxhealth",10);
        changeentityproperty(aentity, "health", 0);
      } else {
        changeentityproperty(aentity, "maxhealth",cmp);
        changeentityproperty(aentity, "health", cmp);
      }
      */
    }
    return aentity;
}


void decreasemaxmpforentity(void aentity,int amount)
{// increase current max mp amount.
// V0.02 Matman
    if ( aentity != NULL() && getentityproperty(aentity, "exists") ) {
      void cmp = getentityproperty(aentity,"maxmp");

      cmp = cmp - amount;
      changeentityproperty(aentity, "maxmp",cmp);
      changeentityproperty(aentity, "mp", cmp);
    }
    return aentity;
}


void decreasempthenhealth(int amount)
{// Decrease current mp amount and if its less than 0 then decrease health. Not max Mp.
// V0.05 MatMan
    void self = getlocalvar("self");
    if ( checkent(self) == 1 ) {
      void health = getentityproperty(self,"health");
      void cmp = getentityproperty(self,"mp");
      int ichance = 0;// rand()%45;
      int cancon = 1;
      cmp = cmp - amount;
      if (cmp <= 0)
      {
        health = health + (cmp / 2);
        changeentityproperty(self, "health", health);
        cmp = 0;
      }
      if (cmp < 10) {
        ichance = rand()%100;
        if ( ichance > 85 ) { cancon = 0 ;}
      }
      if ( cmp < 5 && health < 40)
      {
        ichance = rand()%100;
        if ( ichance > 10 ) { cancon = 0 ;}
      }
      changeentityproperty(self, "mp", cmp);
      if ( cancon == 0)
      {
        changeentityproperty(self, "aiflag", "idling", 1);			//Set idle flag.
        changeentityproperty(self, "animation", openborconstant("ani_cant")); //Change the animation
      }
    }
}


void decreasespeedforentity(void aentity,float amount)
{// increase current speed amount.
 //Includes running speed.
// V0.04
    if ( checkent(aentity) == 1 ) {
      if ( amount != 0 )
      {
        float cmp = getentityproperty(aentity,"speed");
        float runspd = getentityproperty(aentity,"running","speed");
        cmp = cmp - (amount * 0.1);
        changeentityproperty(aentity, "speed", cmp);
        changeentityproperty(aentity, "running", runspd-(amount*0.1));
      }
    }
    return aentity;
}


void gethealthpercentageforallplayers(int isTrue)
{
// V0.02 Matman
// Returns the total health percentage of all alive human controlled players

    int totalpercentage = 0;
    int alveplayers = 0;

    void P1 = getplayerproperty(0, "entity"); //Get Player 1
    void P2 = getplayerproperty(1, "entity"); //Get Player 2
    void P3 = getplayerproperty(2, "entity"); //Get Player 3
    void P4 = getplayerproperty(3, "entity"); //Get Player 4

    int p1Health = 0;
    int p2Health = 0;
    int p3Health = 0;
    int p4Health = 0;
    int p1MaxHealth = 0;
    int p2MaxHealth = 0;
    int p3MaxHealth = 0;
    int p4MaxHealth = 0;

    int totalhealth = 0;

    if ( checkent(P1) == 1 ) {
      alveplayers++ ;
      p1Health = getentityproperty( P1,"health" );
      p1MaxHealth = getentityproperty( P1,"maxhealth" );
    }
    if ( checkent(P2) == 1 ) {
      alveplayers++ ;
      p2Health = getentityproperty( P2,"health" );
      p2MaxHealth = getentityproperty( P2,"maxhealth" );
    }
    if ( checkent(P3) == 1 ) {
      alveplayers++ ;
      p3Health = getentityproperty( P3,"health" );
      p3MaxHealth = getentityproperty( P3,"maxhealth" );
    }
    if ( checkent(P4) == 1 ) {
      alveplayers++ ;
      p4Health = getentityproperty( P4,"health" );
      p4MaxHealth = getentityproperty( P4,"maxhealth" );
    }

    //float health = getentityproperty(aentity,"health");
    //float mxhealth = getentityproperty(aentity,"maxhealth");
    totalhealth = ((p1Health+p2Health+p3Health+p4Health)*(alveplayers*100))/(p1MaxHealth+p2MaxHealth+p3MaxHealth+p4MaxHealth);
    //log("--total per " + totalhealth);
    return totalhealth;
}


void gethealthpercentageforentity(void aentity)
{
// V0.04 MatMan
    int rval = 0;
    if(aentity==NULL()){
      rval = 0;
    } else
    {
      if (checkent(aentity) == 1) {
        float health = getentityproperty(aentity,"health");
        float mxhealth = getentityproperty(aentity,"maxhealth");
        float totalhealth = (health*100)/mxhealth;
        rval = totalhealth;
      }
    }
    return rval;
}


void getmppercentageforallplayers(int isTrue)
{
// V0.03 MatMan
// Returns the total health percentage of all alive human controlled players

    int totalpercentage = 0;
    int alveplayers = 0;

    void P1 = getplayerproperty(0, "entity"); //Get Player 1
    void P2 = getplayerproperty(1, "entity"); //Get Player 2
    void P3 = getplayerproperty(2, "entity"); //Get Player 3
    void P4 = getplayerproperty(3, "entity"); //Get Player 4

    int p1mp = 0;
    int p2mp = 0;
    int p3mp = 0;
    int p4mp = 0;
    int p1Maxmp = 0;
    int p2Maxmp = 0;
    int p3Maxmp = 0;
    int p4Maxmp = 0;

    int totalmp = 0;

    if ( checkent(P1) == 1) {
      alveplayers++ ;
      p1mp = getentityproperty( P1,"mp" );
      p1Maxmp = getentityproperty( P1,"maxmp" );
    }
    if ( checkent(P2) == 1) {
      alveplayers++ ;
      p2mp = getentityproperty( P2,"mp" );
      p2Maxmp = getentityproperty( P2,"maxmp" );
    }
    if ( checkent(P3) == 1) {
      alveplayers++ ;
      p3mp = getentityproperty( P3,"mp" );
      p3Maxmp = getentityproperty( P3,"maxmp" );
    }
    if ( checkent(P4) == 1) {
      alveplayers++ ;
      p4mp = getentityproperty( P4,"mp" );
      p4Maxmp = getentityproperty( P4,"maxmp" );
    }

    totalmp = ((p1mp+p2mp+p3mp+p4mp)*(alveplayers*100))/(p1Maxmp+p2Maxmp+p3Maxmp+p4Maxmp);
    return totalmp;
}


void increaseaggressionforentity(void aentity,int amount)
{// increase current aggression.
// V0.02 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"aggression");
      cmp = cmp + amount;
      changeentityproperty(aentity, "aggression", cmp);
    }
    return aentity;
}


void increaseblockoddsforentity(void aentity,int amount)
{
// V0.04 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"blockodds");
      cmp = cmp + amount;
      changeentityproperty(aentity, "blockodds", cmp);
    }
    return aentity;
}


void increaseedelayforentity(void target, float value)
{

  log("\n edlay mode " + getentityproperty(target, "edelay", "mode"));
  log(" edlay factor " + getentityproperty(target, "edelay", "factor"));
  log(" edlay cap_min " + getentityproperty(target, "edelay", "cap_min"));
  log(" edlay cap_max " + getentityproperty(target, "edelay", "cap_max"));
  log(" edlay range_min " + getentityproperty(target, "edelay", "range_min"));
  log(" edlay range_max " + getentityproperty(target, "edelay", "range_max"));

  /*
    edelay {Mode} {Factor} {Cap Min} {Cap Max} {Range Min} {Range Max}
    ~{Mode} defines how {factor} is applied to delay.
        0 = Original delay + {factor}
        1 = Original delay * {factor}
    ~{Factor} is the value you want to apply to delay.
    ~{Cap Min} is possible shortest delay.
    ~{Cap Max} is possible longest delay.
    ~{Range Min} is the shortest original delay that will be adjusted. Useful to prevent short delays such as 1 centisecond delay to be shortened.
    ~{Range Max} is the longest original delay that will be adjusted. Useful to prevent long delays such as 500 centiseconds delay to be extended.

  */
  //changeentityproperty(target, "edelay", 1, 2, 3, 4, 5, 6);
  changeentityproperty(target, "edelay",
                                0,
                                25, //No matter what i set the factor to it always sets it as 0
                                -5,
                                5,
                                -50,
                                25);

  //n edlay cap_max 4 edlay cap_min 3 edlay factor 0 edlay mode 1 edlay range_max 6 edlay range_min 5

  log("\n edlay mode " + getentityproperty(target, "edelay", "mode"));
  log(" edlay factor " + getentityproperty(target, "edelay", "factor"));
  log(" edlay cap_min " + getentityproperty(target, "edelay", "cap_min"));
  log(" edlay cap_max " + getentityproperty(target, "edelay", "cap_max"));
  log(" edlay range_min " + getentityproperty(target, "edelay", "range_min"));
  log(" edlay range_max " + getentityproperty(target, "edelay", "range_max"));

  log("\n---------------------");

  /*
    enum gep_aiflag_enum {
        _gep_aiflag_falling,
        }

    enum gep_edelay_enum {
        _gep_edelay_cap_max,
        _gep_edelay_cap_min,
        _gep_edelay_factor,
        _gep_edelay_mode,
        _gep_edelay_range_max,
        _gep_edelay_range_min,
        _gep_edelay_the_end,
    };
  */

  return target;

}


void increaseescapecountforentity(void aentity,int amount)
{
// V0.03 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"escapecount");
      cmp = cmp + amount;
      changeentityproperty(aentity, "escapecount", cmp);
    }
    return aentity;
}


void increasegrabforceforentity(void aentity,int amount)
{
// V0.03 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"grabforce");
      cmp = cmp + amount;
      changeentityproperty(aentity, "grabforce", cmp);
    }
    return aentity;
}


 void increaseguardpointsforentity(void aentity,int amount)
{// increase current guardpoints.
// V0.03 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"guardpoints");
      //void cmp1 = getentityproperty(aentity,"maxguardpoints");
      cmp = cmp + amount;
      changeentityproperty(aentity, "guardpoints", cmp);
    }
    return aentity;
}


void increasehealthforentity(void aentity,int amount)
{// increase current health amount. Not max health.
// V0.03 MatMan
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"health");
      cmp = cmp + amount;
      changeentityproperty(aentity, "health", cmp);
    }
    return aentity;
}


void increasehealththenmp(int amount)
{// Increas current health, if health is full then add to mp
// V0.02 MatMan
    void self = getlocalvar("self");
    if ( checkent(self) == 1) {
      int maxhealth = getentityproperty(self,"maxhealth");
      int health = getentityproperty(self,"health");
      int cmp = getentityproperty(self,"mp");
      cmp = cmp - amount;
      if ( health == maxhealth)
      {
        increasemp(amount/2);
      } else {
        changeentityproperty(self, "health", health+amount);
      }
    }
}


void increaseknockdowncountforentity(void aentity,int amount)
{
// V0.02
    if ( checkent(aentity) == 1) {
      //void cmp = getentityproperty(aentity,"knockdowncount");
      //cmp = cmp + amount;
      //changeentityproperty(aentity, "knockdowncount", cmp);
    }
    return aentity;
}


void increasemaxhealthforentity(void aentity,int amount)
{// increase current health amount. Not max health.
// V0.05 Matman
    if ( aentity != NULL() && getentityproperty(aentity, "exists") ) {
      int cmp = getentityproperty(aentity,"maxhealth");

      cmp = cmp + amount;
      changeentityproperty(aentity, "maxhealth",cmp);
      changeentityproperty(aentity, "health", cmp);
    }
    return aentity;
}


void increasemaxmpforentity(void aentity,int amount)
{// increase current max mp amount.
// V0.02 Matman
    if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"maxmp");
      cmp = cmp + amount;
      changeentityproperty(aentity, "maxmp",cmp);
      changeentityproperty(aentity, "mp", cmp);
    }
    return aentity;
}


void increaseoffenseforentity(void aentity, int offensetype, float amount)
{
  //MatMan v0.01
  if ( checkent(aentity) == 1 ) {
    //getentityproperty(aentity,"offense", offensetype);
    changeentityproperty(aentity, "offense", offensetype, getentityproperty(aentity,"offense", offensetype)+amount);
  }
  return aentity;
}


void increasespeedforentity(void aentity,float amount)
{// increase current speed amount.
 //Includes running speed.
// V0.05
    if ( checkent(aentity) == 1) {
      if ( amount != 0 )
      {
        float cmp = getentityproperty(aentity,"speed");
        float runspd = getentityproperty(aentity,"running","speed");
        cmp = cmp + (amount * 0.1);
        changeentityproperty(aentity, "speed", cmp);
        changeentityproperty(aentity, "running", runspd+(amount*0.1));
      }
    }
    return aentity;
}


void increasetholdforentity(void aentity,int amount)
{
// V0.02 MatMan
     if ( checkent(aentity) == 1) {
      int cmp = getentityproperty(aentity,"thold");
      cmp = cmp + amount;
      changeentityproperty(aentity, "thold", cmp);
    }
    return aentity;
}


void multiplyaggressionforentity(void aentity,int amount)
{// increase current aggression amount.
// V0.02 MatMan
    if ( checkent(aentity) == 1) {
      void cmp = getentityproperty(aentity,"aggression");
      cmp = cmp * amount;
      changeentityproperty(aentity, "aggression", cmp);
    }
    return aentity;
}


void multiplyhealthforentity(void entity,float amount)
{// increase current health amount.
// V0.02 Matman
    if ( checkent(entity) == 1) {
      void cmp = getentityproperty(entity,"health");
      cmp = cmp * amount;
      changeentityproperty(entity, "health", cmp);
    }
    return entity;
}


void multiplymaxhealthforentity(void entity,float amount,int includehealth)
{// increase current health amount.
//aentity: the passed entity
//amount: the * value
//includehealth: 1 = update normal health to new max health
// V0.03 MatMan
    //void self = getlocalvar("self");
    if ( checkent(entity) == 1) {
      int cmp = getentityproperty(entity,"maxhealth");
      cmp = cmp * amount;
      changeentityproperty(entity, "maxhealth", cmp);
      if (includehealth == 1) {changeentityproperty(entity, "health", cmp);}
    }
    return entity;
}


void randomcolormap(void aentity,int maxmapcount)
{
  // V0.03 MatMan
  if ( checkent(aentity) == 1) {
    int i = rand()%maxmapcount;
    if (i < 0 )
       {i=-i;}
    changeentityproperty(aentity, "map", i);
  }
  return aentity;
}


void setaliasforentity(void aentity,void newalias)
{
// V0.02
    //openBor doesn't support this yet
    if ( checkent(aentity) == 1 ) {
      changeentityproperty(aentity, "name", newalias);
    }
    return aentity;
}


void setdefenceknockdownfromattack(void aentity, float amount, int anitype)
{
  // V 0.04
  // Set's amount of damage that is required for an attack to cause the pain animation.
  // Only seems to work for atk_normal . Tried it with other attack types but no go.
    if ( checkent(aentity) == 1) {
    float 	fFac 	= getentityproperty(aentity, "defense", anitype, "factor"		);  	//Get factor.
    int 	iPai 	= getentityproperty(aentity, "defense", anitype, "pain"            	);  	//Get pain.
    float 	fKno 	= getentityproperty(aentity, "defense", anitype, "knockdown"       	);  	//Get knockdown.
    int 	fBpo 	= getentityproperty(aentity, "defense", anitype, "blockpower"      	);  	//Get block power.
    int 	iThr 	= getentityproperty(aentity, "defense", anitype, "blockthreshold"	);  	//Get threshold.
    float 	fRai	= getentityproperty(aentity, "defense", anitype, "blockratio"      	);	//Get block ratio.
    int 	iBty	= getentityproperty(aentity, "defense", anitype, "blocktype"       	);  	//Get block type.
    log("\n     fFac " + fFac);
    log(" iPai " + iPai);
    log(" fKno " + fKno);
    log(" fBpo " + fBpo);
    log(" iThr " + iThr);
    log(" fRai " + fRai);
    log(" iBty " + iBty);
    log(" anitype " + anitype);
    log(" aentity " + aentity);
    //iPai = amount;
    //log(" changed3 " + changeentityproperty(aentity, "defense", anitype, 1,2,3,4,5,6,7) );
    //log(" changedFin " + changeentityproperty(aentity, "defense", anitype, fFac, iPai, fKno+amount, fBpo, iThr, fRai, iBty) );
    log(" changed " + changeentityproperty(aentity, "defense", anitype, fFac, iPai+amount, fKno+amount, fBpo+amount, iThr+amount, fRai+amount, iBty+amount) );

    //n after set     fFac 1.000000 iPai 2.000000 fKno 3.000000 fBpo 4.000000 iThr 5.000000 fRai 6.000000 iBty 7.000000

    fFac 	= getentityproperty(aentity, "defense", anitype, "factor"		);  	//Get factor.
    iPai 	= getentityproperty(aentity, "defense", anitype, "pain"            	);  	//Get pain.
    fKno 	= getentityproperty(aentity, "defense", anitype, "knockdown"       	);  	//Get knockdown.
    fBpo 	= getentityproperty(aentity, "defense", anitype, "blockpower"      	);  	//Get block power.
    iThr 	= getentityproperty(aentity, "defense", anitype, "blockthreshold"	);  	//Get threshold.
    fRai	= getentityproperty(aentity, "defense", anitype, "blockratio"      	);	//Get block ratio.
    iBty	= getentityproperty(aentity, "defense", anitype, "blocktype"       	);  	//Get block type.
    log("\n------------------------ \n as   fFac " + fFac);
    log(" iPai " + iPai);
    log(" fKno " + fKno);
    log(" fBpo " + fBpo);
    log(" iThr " + iThr);
    log(" fRai " + fRai);
    log(" iBty " + iBty);
    log(" anitype " + anitype);

  }
  return aentity;
}


void setoffenseforentity(void aentity, int offensetype, float amount)
{
  //MatMan v0.02
  if ( checkent(aentity) == 1 && offensetype != NULL() ) {
    //getentityproperty(aentity,"offense", offensetype);
    changeentityproperty(aentity, "offense", offensetype, amount);
  }
  return aentity;
}




void alterallstats(void aentity, int stage, int iDifficulty)
{
  //v 0.15 Matman
  if ( checkent(aentity) == 1
    && stage != NULL()
    && iDifficulty != NULL()) {
    //Modify stats
    int sizeX = 256;
    int sizeY = 256;
    int iChance = 0;
    aentity = maxHealthByStage( aentity, stage, (iDifficulty/2) );
    iChance = rand()%100;
    if ( iChance > 98) {
      aentity = increaseaggressionforentity( aentity, 2 );
      sizeX = sizeX+30;
      //aentity = scaleentity(aentity,286,256);
    }
    aentity = increaseaggressionforentity( aentity, ((iDifficulty/3)+(stage/18)-1) );
    iChance = rand()%100;
    if ( iChance > 98) {
      aentity = increasespeedforentity( aentity, 2 );
      sizeX = sizeX-40;
      sizeY = sizeY+20;
    }
    aentity = increasespeedforentity( aentity,((iDifficulty/4)+(stage/40)-1) );
    iChance = rand()%100;
    if ( iChance > 98) { aentity = increasetholdforentity( aentity, 2 ); }
    aentity = increasetholdforentity( aentity, iDifficulty+(stage/14) );
    iChance = rand()%100;
    if ( iChance > 98) { aentity = increaseblockoddsforentity( aentity, 2 ); }
    iChance = rand()%100;
    if ( iChance > 98) {
      aentity = setoffenseforentity( aentity, openborconstant("ATK_NORMAL"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_NORMAL2"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_BLAST"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_BURN"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_FREEZE"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_SHOCK"), 2);
      aentity = setoffenseforentity( aentity, openborconstant("ATK_STEAL"), 2);
      sizeX = sizeX+40;
      sizeY = sizeY+40;
     }
    aentity = increaseblockoddsforentity( aentity, (iDifficulty+(stage/15)-1) );

    if ( sizeX != 256 || sizeY != 256 ) { aentity = scaleentity(aentity,sizeX,sizeY); }

    //void enemySpawnName = getentityproperty(aentity, "defaultname");
    //log(" enemySpawnName " + enemySpawnName);

    //aentity = increaseknockdowncountforentity( aentity,iDifficulty+(stage/6) );
    //aentity = setdefenceknockdownfromattack( aentity, 10, openborconstant("ATK_NORMAL"));
    //aentity = setdefenceknockdownfromattack( aentity, 10, openborconstant("ATK_NORMAL2"));
    //iChance = rand()%1000;
    //aentity = setriseTime(aentity, -5000);

    aentity = randomcolormap( aentity, 8 );


  }
  return aentity;
}


void castallspecial(void entity, float eX, float eY, float eZ)
{
   //Matman V0.3
   int allplr = 0;
   void vSelf  = getlocalvar("self");
   if ( checkent(vSelf) == 1 ) {
     if ( getentityvar(vSelf, 2) != NULL() ) { allplr = getentityvar(vSelf, 2); }
     if ( allplr > 9)
     {
        spawnentitybyallenemy(entity, eX, eY, eZ);
        setentityvar(vSelf, 2, allplr-10);
     }
     drawguiforplayer(vSelf);
   }
}


void castcharged(int duration)
{
   //Matman v 0.08
   void iTime = 0;
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     int allplr = 0;
     if ( getentityvar(self, 2) != NULL() ) { allplr = getentityvar(self, 2); }
     iTime = openborvariant("elapsed_time");

   if ( allplr > 14)
   {
     if ( getentityvar(self, 4) != 1 )
     {
       setentityvar(self, 4, 1);
       setentityvar(self, 5, duration+iTime);

       //add to stats
       increasemaxhealthforentity( self, 100 );
       increasemaxmpforentity( self, 100 );
       //log(" \n speed " + speed);
       increasespeedforentity( self, 6);
       setoffenseforentity( self, openborconstant("ATK_NORMAL"), 3);
       setoffenseforentity( self, openborconstant("ATK_NORMAL2"), 3);
       setoffenseforentity( self, openborconstant("ATK_BLAST"), 3);
       setoffenseforentity( self, openborconstant("ATK_BURN"), 3);
       setoffenseforentity( self, openborconstant("ATK_FREEZE"), 3);
       setoffenseforentity( self, openborconstant("ATK_SHOCK"), 3);
       setoffenseforentity( self, openborconstant("ATK_STEAL"), 3);
       setentityvar(self, 2, allplr-15);
     }
   }
   drawguiforplayer(self);
   }
}


void createchests(void vSelf, void enemySpawnName)
{
  // MatMan v0.06
  if ( checkent(vSelf) == 1 ) {
    int iChance = 0;
    int iChance2 = rand()%10;
    void spawned;
    //void enemySpawnName = getentityproperty(vSelf, "defaultname");
    iChance = rand()%100;
    //Defense - fence
  if ( iChance2 > 0) //divide by lateral
    {
    if ( iChance > 80  ){ spawned = spawnentitydivbyz(vSelf, enemySpawnName, 3, 25); } else
    if ( iChance > 40  ){ spawned = spawnentitydivbyz(vSelf, enemySpawnName, 2, 25); } else
    if ( iChance > -50 ){ spawned = spawnentitydivbyz(vSelf, enemySpawnName, 1, 25); }
  } else
  { //spawnentitybyrate(void self, void newent, int spawnamount, int movexby, int movezby, int startzbyself)
    if ( iChance > 80  ){ spawned = spawnentitybyrate(vSelf, enemySpawnName, 3, 100, 20, 0); } else
    if ( iChance > 40  ){ spawned = spawnentitybyrate(vSelf, enemySpawnName, 2, 100, 20, 0); } else
    if ( iChance > -50) { spawned = spawnentitybyrate(vSelf, enemySpawnName, 1, 100, 20, 0);
    }
  }
  //void spawnchildentityforparent(void vName, void parent, float fX, float fY, float fZ)
  if ( enemySpawnName == "fence" )
  {
    if (getentityproperty(spawned, "x") > 0)
    {
      spawnchildentityforparent("kensht" ,spawned , -60, 0, 0, 1);
    }
  }
  }
}


void drawguiforplayer(void vSelf)
{
  //Matman v0.01
  //Get all Players
  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4
  //Gold
  int gldx = 0;
  int gldy = 0;
  int gold = 0;
  //All Special Move
  int allplr = 0;
  int allplrX = 0;
  int allplrY = 0;
  //Npc Count
  int npc = 0;
  int npcX = 0;
  int npcY = 0;
  if ( getentityvar(vSelf, 2) != NULL() ) { allplr = getentityvar(vSelf, 2); }
  //Set All Positions
  if (vSelf == P1)
  {
    gldx = 28;
    gldy = 39;
    gold = getvscore(0);
    allplrX = 93;
    allplrY = 2;
    npc = getvnpc(0);
    npcX = 93;
    npcY = 12;
    settextobj(0, gldx, gldy, 1, 1, "G " + gold);
    settextobj(1, allplrX, allplrY, 1, 1, "A " + allplr);
    settextobj(2, npcX, npcY, 1, 1, "S " + npc);
  } else
  if (vSelf == P2)
  {
    gldx = 148;
    gldy = 39;
    gold = getvscore(1);
    allplrX = 212;
    allplrY = 2;
    npc = getvnpc(1);
    npcX = 212;
    npcY = 12;
    settextobj(3, gldx, gldy, 1, 1, "G " + gold);
    settextobj(4, allplrX, allplrY, 1, 1, "A " + allplr);
    settextobj(5, npcX, npcY, 1, 1, "S " + npc);
  } else
  if (vSelf == P3)
  {
    gldx = 267;
    gldy = 39;
    gold = getvscore(2);
    allplrX = 330;
    allplrY = 2;
    npc = getvnpc(2);
    npcX = 330;
    npcY = 12;
    settextobj(6, gldx, gldy, 1, 1, "G " + gold);
    settextobj(7, allplrX, allplrY, 1, 1, "A " + allplr);
    settextobj(8, npcX, npcY, 1, 1, "S " + npc);
  } else
  if (vSelf == P4)
  {
    gldx = 384;
    gldy = 39;
    gold = getvscore(3);
    allplrX = 448;
    allplrY = 2;
    npc = getvnpc(3);
    npcX = 448;
    npcY = 12;
    settextobj(9,  gldx, gldy, 1, 1, "G " + gold);
    settextobj(10, allplrX, allplrY, 1, 1, "A " + allplr);
    settextobj(11, npcX, npcY, 1, 1, "S " + npc);
  }
}


void enemydialog(int t)
{
  //Loads the current levels files enemy dialog.
  int level = openborvariant("current_level");
  void file = -1;
  void s = "";
  int i = 1000;
  int j = 0;

  if ( level == 1 ) { file = openfilestream("data/1e.txt", 0); } else
  if ( level == 2 ) { file = openfilestream("data/2e.txt", 0); } else
  if ( level == 3 ) { file = openfilestream("data/3e.txt", 0); } else
  if ( level == 4 ) { file = openfilestream("data/4e.txt", 0); } else
  if ( level == 5 ) { file = openfilestream("data/5e.txt", 0); } else
  if ( level == 6 ) { file = openfilestream("data/6e.txt", 0); } else
  if ( level == 7 ) { file = openfilestream("data/7e.txt", 0); } else
  if ( level == 8 ) { file = openfilestream("data/8e.txt", 0); }//else
  //{ file = openfilestream("data/11e.txt", 0); }
  //void file = openfilestream("levels/1-1e.txt", 1);
  //void file = openfilestream("data/bin/names.txt", 1);

  if ( file == -1 ) {
     setindexedvar(55,NULL());
    //Not Found
    //file = settingssave(2);

  } else
  {
    setfilestreamposition(file, 0);
    for( j=0; j<1000; j++)
    {
      s = getfilestreamargument(file, 0, "string");
      //log("\n s " + s + " i="+i);
      setindexedvar(i,s);
      if ( s == "End____________________Of__________________File" )
      {
        j = 1001;
        setindexedvar(55,i-1);
        //log("\n getindexedvar(i,s) " + getindexedvar(i));
      } else {
        filestreamnextline(file);
        i++;
      }
    }

  }

}


void getaliasviaspawnname(void spawnedname)
{
  //Check male names
  if ( spawnedname == "devo" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kuse" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kush" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsie" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "dhalsih" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggere" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "juggerh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcome" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "capcomh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sase" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sash" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "talbaie" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "talbaih" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "marue" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "maruh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "specter" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "axle" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "axlh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "banee" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "baneh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "sdioe" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "nchaosh" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "solt" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "hondae" ) { spawnedname = namemalemedieval(1); }else
  if ( spawnedname == "hondah" ) { spawnedname = namemalemedieval(1); } else
  if ( spawnedname == "kene" ) { spawnedname = namemalemedieval(1); }else
  if ( spawnedname == "kenh" ) { spawnedname = namemalemedieval(1); } else
  


  //Check female names
  if ( spawnedname == "taoe" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "taoh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhre" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "rubyhrh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "sonia" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "casne" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "casnh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "roomie" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "roomih" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "bdamee" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "bdameh" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "irohah" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "darke" ) { spawnedname = namefemalemedieval(1); } else
  if ( spawnedname == "darkh" ) { spawnedname = namefemalemedieval(1); }else
  if ( spawnedname == "leileie" ) { spawnedname = namefemalemedieval(1); }else
  if ( spawnedname == "yokoe" ) { spawnedname = namefemalemedieval(1); }else
  if ( spawnedname == "yokoh" ) { spawnedname = namefemalemedieval(1); }


  return spawnedname;
}


void loadallentities(int t)
{ //Matman v0.05
  loadmodel("axle");
  loadmodel("axlh");
  loadmodel("banee");
  loadmodel("baneh");
  loadmodel("bdamee");
  loadmodel("bdameh");
  loadmodel("capcome");
  loadmodel("capcomh");
  loadmodel("casne");
  loadmodel("casnh");
  loadmodel("darke");
  loadmodel("darkh");
  loadmodel("devo");
  loadmodel("dhalsie");
  loadmodel("dhalsih");
  loadmodel("equake");
  loadmodel("hondae");
  loadmodel("hondah");
  loadmodel("juggere");
  loadmodel("juggerh");
  loadmodel("kene");
  loadmodel("kenh");
  loadmodel("kuse");
  loadmodel("kush");
  loadmodel("leileie");
  loadmodel("marue");
  loadmodel("maruh");
  loadmodel("roomie");
  loadmodel("roomih");
  loadmodel("rubyhre");
  loadmodel("rubyhrh");
  loadmodel("sase");
  loadmodel("sash");
  loadmodel("sonia");
  loadmodel("specter");
  loadmodel("talbaie");
  loadmodel("talbaih");
  loadmodel("taoe");
  loadmodel("taoh");
  loadmodel("yokoe");
  loadmodel("yokoh");

  loadmodel("Gold");
  loadmodel("1up");
  loadmodel("inpc");
  loadmodel("as");
  loadmodel("Judith");
  loadmodel("apple");
  loadmodel("chicken");
  loadmodel("pork");
  loadmodel("fish");
  loadmodel("mp");
  loadmodel("box2");
  loadmodel("chst1");
  loadmodel("fence");
  loadmodel("trash");
  loadmodel("mball");
  
}


void maxHealthByStage(void entity, int istage,int iDifficulty)
{
  // v0.03 Matman
  if ( checkent(entity) == 1 ) {
    void cmp = getentityproperty(entity,"maxhealth");

    int z = cmp/2;
    int r = rand()%z;
    int d = (cmp * iDifficulty) / 2 + (istage * 2);
    //drawstring(150, 150, 0, r);
    //int r =
    cmp = cmp + d + r;
    changeentityproperty(entity, "maxhealth", cmp);
    changeentityproperty(entity, "health", cmp);
  }
  return entity;

}


void playenemydialog(int t)
{
  //v0.02 matman
  int iChance = 0;
  int dialogindex = 0;
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    void s = "";
    void iTime = openborvariant("elapsed_time") + 350;
    //dialogindex = RandomNumber(getindexedvar(55)+1000, 1000);
    //dialogindex = RandomNumber(1000, 1010);
    //dialogindex = rand()%56;
  if ( getindexedvar(55) != NULL() )
  {
  dialogindex = rand()%(getindexedvar(55)-1000); //TODO Should be moved to "converted correctly" on file load
  //log("\n getindexedvar(55)-1000 " + getindexedvar(55)-1000);
  if ( dialogindex < 0 )
  {
    dialogindex = -dialogindex;
  }
  dialogindex = dialogindex + 1000;
  //log(" \n " + dialogindex + " getindexedvar(55) " + getindexedvar(55));
  iChance = rand()%100;
  if ( iChance > 90) {
    //s = getindexedvar(1000,s);
    s = getindexedvar(dialogindex,s);

    //log("\n")
    //settextobj({index}, {x}, {y}, {font}, {z}, {text}, {time})
    if ( s!= NULL())
    {
      //log("\n (openborvariant(ypos) " + openborvariant("ypos") + " getentityproperty(self,x) " + getentityproperty(self,"x"));

      settextobj(   12,
                  (getentityproperty(self,"x")-openborvariant("xpos") - 30),
                  //(getentityproperty(self,"a")+openborvariant("ypos") + getheight(self)+10),
                  (getentityproperty(self,"a") + getheight(self)+10),
                  //(openborvariant("ypos") + getheight(self)+10),
                  4,
                  getentityproperty(self,"z"),
                  s,
                  iTime); //Enemy Dialog
    }
  }
  }
  }
}


void randomallbasicitems(int isTrue)
{
  //Matman v0.04
  int i = rand()%2;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "gold";}        else
  if(i==1){s = "as";}

  if (s == "")
  {s = randomallbasicitems(1);}

  return s;


  return s;
}


void randomallboss(int isTrue)
{
  int i = rand()%4;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "sdioe";}        else
  if(i==1){s = "irohah";} else
  if(i==2){s = "nchaosh";} else
  if(i==3){s = "solt";}

  if (s == "")
  {s = randomallboss(1);}

  return s;
}


void randomallchests(int isTrue)
{
  //Matman v0.01
  int i = rand()%4;
  void s = "";
  if (i < 0 )
     {i= -i;}

  if(i==0){s = "box2";}        else
  if(i==1){s = "trash";}        else
  if(i==2){s = "fence";}        else
  if(i==3){s = "chst1";}

  if (s == "")
  {s = randomallchests(1);}

  return s;


  return s;
}


void randomallhealthitems(int isTrue)
{
  int i = rand()%4;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "apple";}        else
  if(i==1){s = "chicken";} else
  if(i==2){s = "pork";} else
  if(i==3){s = "fish";}

  if (s == "")
  {s = randomallhealthitems(1);}

  return s;
}


void randomallminbosshard(int isTrue)
{
  int i = rand()%8;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "kush";}        else
  if(i==1){s = "juggerh";} else
  if(i==2){s = "sash";} else
  if(i==3){s = "equake";} else
  if(i==4){s = "baneh";} else
  if(i==5){s = "bdameh";}else
  if(i==6){s = "hondah";}else
  if(i==7){s = "leileie";}


  if (s == "")
  {s = randomallminbosshard(1);}

  return s;
}


void randomallminbossnormal(int isTrue)
{
  int i = rand()%8;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "kuse";}        else
  if(i==1){s = "juggere";} else
  if(i==2){s = "sase";} else
  if(i==3){s = "equake";} else
  if(i==4){s = "banee";} else
  if(i==5){s = "bdamee";}else
  if(i==6){s = "hondae";}else
  if(i==7){s = "leileie";}

  if (s == "")
  {s = randomallminbossnormal(1);}

  return s;
}


void randomallmiscitems(int isTrue)
{
  //Matman v0.04
  int i = rand()%2;
  void s = "";
  if (i < 0 )
     {i= -i;}

  if(i==0){s = "1up";}        else
  if(i==1){s = "inpc";}
  if ( s == "")
  { s = randomallmiscitems(1); }

  return s;
}


void randomallmpitems(int isTrue)
{
  void s = "mp";
  /*
  int i = rand()%4;
  void s = "";

  if (i < 0 )
     {i=i+i+i;}

  if(i==0){s = "mp";}        else
  if(i==1){s = "chicken";} else
  if(i==2){s = "pork";} else
  if(i==3){s = "fish";}

  if (s == "")
  {s = randomallhealthitems(1);}
  */
  return s;
}


void randomcreator(int maxEnemy, int stage, int forceDifficulty, int EnemyType)
{
// V0.26
// MaxEnemy : Max allowed enemies on stage at any time
// Stage : Spawn characters according to stage number
// forceDifficulty : Spawn characters according to Forced Difficulty setting
// EnemyType : Types of enemy, 1 = normal, 2 = Mini Boss, 3 = Boss.
    //Get games difficulty
    int iDifficulty = getvdifficulty(1);
    int iPlayerCnt = 1;
    int iEnemyCnt = 0;
    int iChance = 0;
    int allplrhealth = gethealthpercentageforallplayers(1);
    void vSelf      = getlocalvar("self");
    if ( vSelf != NULL() && getentityproperty(vSelf, "exists")) {
      if (stage == -1) { stage = getvchaptercomplete(1) ;}
      if ( getentityproperty( vSelf,"mp" ) > 0 ) { maxEnemy = getentityproperty( vSelf,"mp" ); }
      if (forceDifficulty > 0) { iDifficulty = forceDifficulty; }
      //Adjust difficulty to how all players are doing at the moment
      if (allplrhealth == 100) {
        iChance = rand()%100;
        if ( iChance > 92) { iDifficulty++; }
      }
        //If all players are above 50%
      else
      if (allplrhealth > 50) {
        iChance = rand()%100;
        if ( iChance > 98) {
          iDifficulty++;}
      }
        //If all players are below 40%
      else
        if (allplrhealth < 40) {
          iChance = rand()%100;
          if ( iChance > 25) {
            iDifficulty--; }
        }
    //Give a random chance to make it more difficult
    iChance = rand()%100;
    if ( iChance > 95) { iDifficulty++; }
    //Count the amount of active players on the stage.
    iPlayerCnt = countaliveplayers(1);
    //Count the amount of active enemies on the stage.
    iEnemyCnt = countaliveenemies(1);

    maxEnemy = maxEnemy + iPlayerCnt + (iDifficulty/2) - 1;
    if ( iEnemyCnt <  maxEnemy )
    {
      void enemySpawnName = "";
      void aentity = "";
      //Detect Type of enemy to select a random name from and also check for difficulty.
      if ( EnemyType == 1 )
      {
        if ( iDifficulty % 2 == 0 )
          { enemySpawnName = randomlvl1normal(1); } //Even
        else
          { enemySpawnName = randomlvl1hard(1); } //Odd
      }
      if ( EnemyType == 2 )
      {
        if ( iDifficulty % 2 == 0 )
          { enemySpawnName = randomallminbossnormal(1); } //Even
        else
          { enemySpawnName = randomallminbosshard(1); } //Odd
      }
      if ( EnemyType == 3 )
      {
         enemySpawnName = randomallboss(1);
      }
      if ( EnemyType == 4 )
      {
         enemySpawnName = "capcome";
      }
      if ( EnemyType == 5 ) //traps
      {
         enemySpawnName = randomallchests(1);
      }
      //Create entity
      if ( enemySpawnName != "" )
      {
          if ( EnemyType == 5 )
          {
            //spawnentitydivbyz(vSelf, enemySpawnName, 2, 50);
            createchests(vSelf, enemySpawnName);

            decreasehealthforentity( vSelf,1 );

          } else
          {

            if ( iDifficulty != NULL() )
            {
              spawnentity("lsmok",0,0,0,0); //This might cause problems
              aentity = spawnentity( enemySpawnName,0,0,0,0 );
              aentity = setaliasforentity( aentity, getaliasviaspawnname(enemySpawnName) );
              aentity = alterallstats(aentity, stage, iDifficulty );
              decreasehealthforentity( vSelf,1 );
            }
          }
      }
    }
  }
}


void randomlvl1hard(int isTrue)
{
  int i = rand()%15;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbaih";} else
  if(i==2){s = "dhalsih";} else
  if(i==3){s = "taoh";} else
  if(i==4){s = "capcomh";} else
  if(i==5){s = "rubyhrh";} else
  if(i==6){s = "sonia";} else
  if(i==7){s = "casnh";} else
  if(i==8){s = "maruh";} else
  if(i==9){s = "specter";} else
  if(i==10){s = "roomih";} else
  if(i==11){s = "axlh";} else
  if(i==12){s = "darkh";} else
  if(i==13){s = "kenh";}else
  if(i==14){s = "yokoh";}


  if (s=="") {s = randomlvl1hard(1);}

  return s;
}


void randomlvl1normal(int isTrue)
{
  int i = rand()%15;
  void s = "";

  if (i < 0 )
     {i= -i;}

  if(i==0){s = "devo";}        else
  if(i==1){s = "talbaie";} else
  if(i==2){s = "dhalsie";} else
  if(i==3){s = "taoe";} else
  if(i==4){s = "capcome";} else
  if(i==5){s = "rubyhre";} else
  if(i==6){s = "sonia";}else
  if(i==7){s = "casne";} else
  if(i==8){s = "marue";} else
  if(i==9){s = "specter";} else
  if(i==10){s = "roomie";} else
  if(i==11){s = "axle";} else
  if(i==12){s = "darke";}else
  if(i==13){s = "kene";}else
  if(i==14){s = "yokoe";}



  if ( s=="" ) { s = randomlvl1normal(1); }
  return s;
}


void respawnplayer(int t)
{ //Make sure that this command starts after frame one in the spawn animation
  //V0.06
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
    void P1 = getplayerproperty(0, "entity"); //Get Player 1
    void P2 = getplayerproperty(1, "entity"); //Get Player 2
    void P3 = getplayerproperty(2, "entity"); //Get Player 3
    void P4 = getplayerproperty(3, "entity"); //Get Player 4

    int maxhealth = 0;
    int maxMP = 0;
    void speed = 0;
        if (vSelf == P1)
        { maxhealth = getvmaxhealth(0);
          maxMP = getvmp(0);
          speed = getvspeed(0);
          setentityvar(vSelf, 4, 0);
        } else
        if (vSelf == P2)
        { maxhealth = getvmaxhealth(1);
          maxMP = getvmp(1);
          speed = getvspeed(1);
          setentityvar(vSelf, 4, 0);
        } else
        if (vSelf == P3)
        { maxhealth = getvmaxhealth(2);
          maxMP = getvmp(2);
          speed = getvspeed(2);
          setentityvar(vSelf, 4, 0);
        } else
        if (vSelf == P4)
        { maxhealth = getvmaxhealth(3);
          maxMP = getvmp(3);
          speed = getvspeed(3);
          setentityvar(vSelf, 4, 0);
        }

   increasemaxhealthforentity( vSelf, (maxhealth*5) );
   increasemaxmpforentity( vSelf, (maxMP*5) );
   //log(" \n speed " + speed);
   increasespeedforentity( vSelf, speed-1);
   //increaseedelayforentity( vSelf, speed-1);
   //int hh = getentityproperty( vSelf, "maxhealth" );
   //log (" player max health on spawn " + maxhealth + ":");
   }
}


void setsnkdepth(int istrue)
{
  //Matman v0.04
  if ( istrue == 1)
  {
    if ( getindexedvar(27) == 1)
    {
      setindexedvar(27, 0);

    } else {
      setindexedvar(27, 1);

    }

  }
  if (   getindexedvar(27) == NULL()
      || getindexedvar(27) == 0) {

          settextobj(12, 200, 126, 1, 1, "Snk Depth Disabled", openborvariant("elapsed_time")+200);
          //drawstring(200, 136, 1, "Snk Depth Disabled: ");
        } else {
          settextobj(12, 200, 126, 1, 1, "Snk Depth Enabled", openborvariant("elapsed_time")+200);
          //drawstring(200, 136, 1, "Snk Depth Enabled: ");
        }
}


void settingsload(int t)
{
  //v 1.08
  void file = openfilestream("mixmasters/save.txt", 1);
  //void file = openfilestream("save.txt", 1); //doesn't work
  //void file = openfilestream("bor/save.txt", 1);
  //If File doesn't exists then create a new one.
  if ( file == -1 ) {

    file = settingssave(2);

  }
  setfilestreamposition(file, 0);
  //Difficulty
  void vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(0,vMatch);
  //Chapter Completed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(1,vMatch);
  //Player 1 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(2,vMatch);
  //Player 2 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(3,vMatch);
  //Player 3 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(4,vMatch);
  //Player 4 health
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(5,vMatch);
  //Player 1 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(6,vMatch);
  //Player 2 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(7,vMatch);
  //Player 3 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(8,vMatch);
  //Player 4 score
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(9,vMatch);
  //Player 1 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(10,vMatch);
  //Player 2 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(11,vMatch);
  //Player 3 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(12,vMatch);
  //Player 4 mp
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(13,vMatch);
  //Player 1 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(14,vMatch);
  //Player 2 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(15,vMatch);
  //Player 3 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(16,vMatch);
  //Player 4 Speed
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(17,vMatch);
  //Chapter Completed 1
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(18,vMatch);
  //Chapter Completed 2
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(19,vMatch);
  //Chapter Completed 3
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(20,vMatch);
  //Chapter Completed 4
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(21,vMatch);
  //Chapter Completed 5
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(22,vMatch);
  //Chapter Completed 6
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(23,vMatch);
  //Chapter Completed 7
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(24,vMatch);
  //Chapter Completed 8
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(25,vMatch);
  //Chapter Completed 9
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(26,vMatch);
  //Npc 1
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(28,vMatch);
  //Npc 2
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(29,vMatch);
  //Npc 3
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(30,vMatch);
  //Npc 4
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(31,vMatch);
  //Critical 1
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(32,vMatch);
  //Critical 2
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(33,vMatch);
  //Critical 3
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(34,vMatch);
  //Critical 4
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(35,vMatch);

  //FireBurst 1
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(59,vMatch);
  //FireBurst 2
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(60,vMatch);
  //FireBurst 3
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(61,vMatch);
  //FireBurst 4
  filestreamnextline(file);
  vMatch = getfilestreamargument(file, 0, "int");
  setindexedvar(62,vMatch);
}


void settingssave(int t)
{
  //V0.08
  void file = createfilestream();
  if (t == 2) //use default settings
  {
    //Difficulty
    filestreamappend(file, "1", 1);   //the 1 at the end is nb to make sure it starts on the first line.
    //Chapter Completed
    filestreamappend(file, "1", 0);
    //Player 1 health
    filestreamappend(file, "1", 0);
    //Player 2 health
    filestreamappend(file, "1", 0);
    //Player 3 health
    filestreamappend(file, "1", 0);
    //Player 4 health
    filestreamappend(file, "1", 0);
    //Player 1 score
    filestreamappend(file, "1", 0);
    //Player 2 score
    filestreamappend(file, "1", 0);
    //Player 3 score
    filestreamappend(file, "1", 0);
    //Player 4 score
    filestreamappend(file, "1", 0);
    //Player 1 mp
    filestreamappend(file, "1", 0);
    //Player 2 mp
    filestreamappend(file, "1", 0);
    //Player 3 mp
    filestreamappend(file, "1", 0);
    //Player 4 mp
    filestreamappend(file, "1", 0);
    //Player 1 speed
    filestreamappend(file, "1", 0);
    //Player 2 speed
    filestreamappend(file, "1", 0);
    //Player 3 speed
    filestreamappend(file, "1", 0);
    //Player 4 speed
    filestreamappend(file, "1", 0);
    //Chapter Completed 1
    filestreamappend(file, "1", 0);
    //Chapter Completed 2
    filestreamappend(file, "1", 0);
    //Chapter Completed 3
    filestreamappend(file, "1", 0);
    //Chapter Completed 4
    filestreamappend(file, "1", 0);
    //Chapter Completed 5
    filestreamappend(file, "1", 0);
    //Chapter Completed 6
    filestreamappend(file, "1", 0);
    //Chapter Completed 7
    filestreamappend(file, "1", 0);
    //Chapter Completed 8
    filestreamappend(file, "1", 0);
    //Chapter Completed 9
    filestreamappend(file, "1", 0);
    //Npc 1
    filestreamappend(file, "3", 0);
    //Npc 2
    filestreamappend(file, "3", 0);
    //Npc 3
    filestreamappend(file, "3", 0);
    //Npc 4
    filestreamappend(file, "3", 0);
    //Critical 1
    filestreamappend(file, "1", 0);
    //Critical 2
    filestreamappend(file, "1", 0);
    //Critical 3
    filestreamappend(file, "1", 0);
    //Critical 4
    filestreamappend(file, "1", 0);
    //FireBurst 1
    filestreamappend(file, "1", 0);
    //FireBurst 2
    filestreamappend(file, "1", 0);
    //FireBurst 3
    filestreamappend(file, "1", 0);
    //FireBurst 4
    filestreamappend(file, "1", 0);
  } else {
    //Difficulty
    filestreamappend(file, getvdifficulty(1), 1);   //the 1 at the end is nb to make sure it starts on the first line.
    //Chapter Completed
    filestreamappend(file, getvchaptercomplete(1), 0);
    //Player 1 health
    filestreamappend(file, getvmaxhealth(0), 0);
    //Player 2 health
    filestreamappend(file, getvmaxhealth(1), 0);
    //Player 3 health
    filestreamappend(file, getvmaxhealth(2), 0);
    //Player 4 health
    filestreamappend(file, getvmaxhealth(3), 0);
    //Player 1 score
    filestreamappend(file, getvscore(0), 0);
    //Player 2 score
    filestreamappend(file, getvscore(1), 0);
    //Player 3 score
    filestreamappend(file, getvscore(2), 0);
    //Player 4 score
    filestreamappend(file, getvscore(3), 0);
    //Player 1 mp
    filestreamappend(file, getvmp(0), 0);
    //Player 2 mp
    filestreamappend(file, getvmp(1), 0);
    //Player 3 mp
    filestreamappend(file, getvmp(2), 0);
    //Player 4 mp
    filestreamappend(file, getvmp(3), 0);
    //Player 1 mp
    filestreamappend(file, getvspeed(0), 0);
    //Player 2 mp
    filestreamappend(file, getvspeed(1), 0);
    //Player 3 mp
    filestreamappend(file, getvspeed(2), 0);
    //Player 4 mp
    filestreamappend(file, getvspeed(3), 0);
    //Chapter Completed 1
    filestreamappend(file, getvstagecomp(1), 0);
    //Chapter Completed 2
    filestreamappend(file, getvstagecomp(2), 0);
    //Chapter Completed 3
    filestreamappend(file, getvstagecomp(3), 0);
    //Chapter Completed 4
    filestreamappend(file, getvstagecomp(4), 0);
    //Chapter Completed 5
    filestreamappend(file, getvstagecomp(5), 0);
    //Chapter Completed 6
    filestreamappend(file, getvstagecomp(6), 0);
    //Chapter Completed 7
    filestreamappend(file, getvstagecomp(7), 0);
    //Chapter Completed 8
    filestreamappend(file, getvstagecomp(8), 0);
    //Chapter Completed 9
    filestreamappend(file, getvstagecomp(9), 0);
    //Npc 1
    filestreamappend(file, getvnpc(0), 0);
    //Npc 2
    filestreamappend(file, getvnpc(1), 0);
    //Npc 3
    filestreamappend(file, getvnpc(2), 0);
    //Npc 4
    filestreamappend(file, getvnpc(3), 0);
    //Critical 1
    filestreamappend(file, getvcritical(0), 0);
    //Critical 2
    filestreamappend(file, getvcritical(1), 0);
    //Critical 3
    filestreamappend(file, getvcritical(2), 0);
    //Critical 4
    filestreamappend(file, getvcritical(3), 0);

    //FireBurst 1
    filestreamappend(file, getvfireburst(0), 0);
    //FireBurst 2
    filestreamappend(file, getvfireburst(1), 0);
    //FireBurst 3
    filestreamappend(file, getvfireburst(2), 0);
    //FireBurst 4
    filestreamappend(file, getvfireburst(3), 0);

    //Extra to prevent need to delete save file.
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
    filestreamappend(file, "1", 0);
  }
  savefilestream(file, "save.txt");
  return file;


}


void spawnnpc(int t)
{
 //Make sure that this command starts after frame one in the spawn animation
  //V0.03
  void vSelf  = getlocalvar("self");

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  int hiredNpc = 0;
  int maxhealth = 0;
  int maxMP = 0;
  void speed = 0;

  if (vSelf == P1)
        { hiredNpc = getvnpc(0);
          maxhealth = getvmaxhealth(0);
          maxMP = getvmp(0);
          speed = getvspeed(0);
        } else
        if (vSelf == P2)
        { hiredNpc = getvnpc(1);
          maxhealth = getvmaxhealth(1);
          maxMP = getvmp(1);
          speed = getvspeed(1);
        } else
        if (vSelf == P3)
        { hiredNpc = getvnpc(2);
          maxhealth = getvmaxhealth(2);
          maxMP = getvmp(2);
          speed = getvspeed(2);
        } else
        if (vSelf == P4)
        { hiredNpc = getvnpc(3);
          maxhealth = getvmaxhealth(3);
          maxMP = getvmp(3);
          speed = getvspeed(3);
        }
  if (hiredNpc>1)
  {
    spawnentity("lsmok",0,0,0,0); //This might cause problems
    //Need to update to handle other npc types
    void childnpc = spawnchildentity( "judith", 0, 0, 0);

    increasemaxhealthforentity( childnpc, (maxhealth*5) );
    increasemaxmpforentity( childnpc, (maxMP*5) );
    increasespeedforentity( childnpc, (speed-1) );
    childnpc = randomcolormap( childnpc, 8 );

    if (vSelf == P1)
        { setvnpc(0,hiredNpc-1);
        } else
        if (vSelf == P2)
        { setvnpc(1,hiredNpc-1);
        } else
        if (vSelf == P3)
        { setvnpc(2,hiredNpc-1);
        } else
        if (vSelf == P4)
        { setvnpc(3,hiredNpc-1);
        }
  }

}




void addgoldtoallplayers(int amount)
{
  //MatMan v0.01
  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4
  if ( P1 != NULL() )
  {
    setvscore(0,getvscore(0)+amount);
  }
  if ( P2 != NULL() )
  {
    setvscore(1,getvscore(1)+amount);
  }
  if ( P3 != NULL() )
  {
    setvscore(2,getvscore(2)+amount);
  }
  if ( P4 != NULL() )
  {
    setvscore(3,getvscore(3)+amount);
  }
}


void buycritical(int amount)
{
  //v0.03
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
  void target = getentityproperty(vSelf, "opponent");
  int cost = 800;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  int critical = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { critical = getvcritical(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { critical = getvcritical(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { critical = getvcritical(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { critical = getvcritical(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvcritical(0,critical+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvcritical(1,critical+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvcritical(2,critical+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvcritical(3,critical+amount);
      setvscore(3,moneyamount-cost);  }
      //drawstring(200, 136, 1, "Better chance for critical: " + critical );
    } else {
      //drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Better chance for critical: " + critical, openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    drawstring(200, 136, 1, "Better chance for critical: " + critical );
    drawstring(200, 146, 1, "Cost: " +  cost );
    */
  }
  }
}


void buyFireburst(int amount)
{
  //v0.04
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
  void target = getentityproperty(vSelf, "opponent");
  int cost = 1900;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"speed");

  int maxFireBurst = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxFireBurst = getvfireburst(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxFireBurst = getvfireburst(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxFireBurst = getvfireburst(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxFireBurst = getvfireburst(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvfireburst(0,maxFireBurst+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvfireburst(1,maxFireBurst+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvfireburst(2,maxFireBurst+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvfireburst(3,maxFireBurst+amount);
      setvscore(3,moneyamount-cost);  }
    //increasespeedforentity( target, (maxspeed-1) );
      //drawstring(200, 136, 1, "Burst Level: " + (maxFireBurst-1) );
    } else {
      //drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Burst Level: " + (maxFireBurst-1), openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    drawstring(200, 136, 1, "Burst Level: " + (maxFireBurst-1) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
    */
  }
  }
}


void buyhealth(int amount)
{
  //v0.08
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
  void target = getentityproperty(vSelf, "opponent");
  int cost = 150;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"maxhealth");

  int maxhealth = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxhealth = getvmaxhealth(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxhealth = getvmaxhealth(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxhealth = getvmaxhealth(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxhealth = getvmaxhealth(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvmaxhealth(0,maxhealth+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvmaxhealth(1,maxhealth+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvmaxhealth(2,maxhealth+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvmaxhealth(3,maxhealth+amount);
      setvscore(3,moneyamount-cost);  }
    increasemaxhealthforentity( target, (amount*5) );
      //drawstring(200, 136, 1, "Added Maximum Health: " + (maxhealth*5) );
    } else {
      //drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Added Maximum Health: " + (maxhealth*5), openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    //drawstring(200, 136, 1, "Player Max health at " + (Health+(maxhealth*5)) );
    drawstring(200, 136, 1, "Added Maximum Health: " + (maxhealth*5) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
    */
  }
  }
}


void buymp(int amount)
{
  //v0.09
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
  void target = getentityproperty(vSelf, "opponent");
  int cost = 175;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"maxhealth");

  int maxMP = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxMP = getvmp(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxMP = getvmp(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxMP = getvmp(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxMP = getvmp(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvmp(0,maxMP+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvmp(1,maxMP+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvmp(2,maxMP+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvmp(3,maxMP+amount);
      setvscore(3,moneyamount-cost);  }
    increasemaxmpforentity( target, (amount*5) );
    //drawstring(200, 136, 1, "Added Maximum Mp: " + (maxMP*5) );
    } else {
      //drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Added Maximum Mp: " + (maxMP*5), openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    //drawstring(200, 136, 1, "Player Max health at " + (Health+(maxhealth*5)) );
    drawstring(200, 136, 1, "Added Maximum Mp: " + (maxMP*5) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
    */
  }
  }
}


void buynpc(int amount)
{
  //v0.06
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
  void target = getentityproperty(vSelf, "opponent");
  int cost = 250;

  void P1 = getplayerproperty(0, "entity"); //Get Player 1
  void P2 = getplayerproperty(1, "entity"); //Get Player 2
  void P3 = getplayerproperty(2, "entity"); //Get Player 3
  void P4 = getplayerproperty(3, "entity"); //Get Player 4

  void Health = getentityproperty(target,"speed");

  int maxnpc = 0;
  int moneyamount = 0;
  int canbuy = 0;
    if (target == P1)
    { maxnpc = getvnpc(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxnpc = getvnpc(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxnpc = getvnpc(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxnpc = getvnpc(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvnpc(0,maxnpc+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvnpc(1,maxnpc+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvnpc(2,maxnpc+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvnpc(3,maxnpc+amount);
      setvscore(3,moneyamount-cost);  }
    //increasespeedforentity( target, (maxspeed-1) );
    drawstring(200, 136, 1, "Total Hired NPC: " + (maxnpc-1) );
    } else {
      drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Total Hired NPC: " + (maxnpc-1), openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    drawstring(200, 136, 1, "Total Hired NPC: " + (maxnpc-1) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
    */
  }
  }
}


void buyspeed(int amount)
{
  //v0.10
  void vSelf  = getlocalvar("self");
  if ( checkent(vSelf) == 1 ) {
    void target = getentityproperty(vSelf, "opponent");
    if ( checkent(target) == 1 ) {
      int cost = 5500;

      void P1 = getplayerproperty(0, "entity"); //Get Player 1
      void P2 = getplayerproperty(1, "entity"); //Get Player 2
      void P3 = getplayerproperty(2, "entity"); //Get Player 3
      void P4 = getplayerproperty(3, "entity"); //Get Player 4
      void Health = getentityproperty(target,"speed");

    int maxspeed = 0;
    int moneyamount = 0;
    int canbuy = 0;
    if (target == P1)
    { maxspeed = getvspeed(0);
      moneyamount = getvscore(0); } else
    if (target == P2)
    { maxspeed = getvspeed(1);
      moneyamount = getvscore(1); } else
    if (target == P3)
    { maxspeed = getvspeed(2);
      moneyamount = getvscore(2); } else
    if (target == P4)
    { maxspeed = getvspeed(3);
      moneyamount = getvscore(3); }

  if ( moneyamount - cost > 0){ canbuy = 1; }

  if ( amount > 0 )
  {
    if (canbuy == 1)
    {
    if (target == P1)
    { setvspeed(0,maxspeed+amount);
      setvscore(0,moneyamount-cost); } else
    if (target == P2)
    { setvspeed(1,maxspeed+amount);
      setvscore(1,moneyamount-cost); } else
    if (target == P3)
    { setvspeed(2,maxspeed+amount);
      setvscore(2,moneyamount-cost); } else
    if (target == P4)
    { setvspeed(3,maxspeed+amount);
      setvscore(3,moneyamount-cost);  }
    increasespeedforentity( target, (maxspeed-1) );
    drawstring(200, 136, 1, "Added Maximum Speed: " + (maxspeed-1) );
    } else {
      drawstring(200, 136, 1, "Not Enough Gold!" );
    }
    drawguiforplayer(target);
  } else {
    settextobj(12, 200, 126, 1, 1, "Added Maximum Speed: " + (maxspeed-1), openborvariant("elapsed_time")+200);
    settextobj(13, 200, 136, 1, 1, "Cost: " + cost, openborvariant("elapsed_time")+200);
    /*
    drawstring(200, 136, 1, "Added Maximum Speed: " + (maxspeed-1) );
    drawstring(200, 146, 1, "Cost: " +  cost );
    drawstring(200, 156, 1, "Gold: " + moneyamount );
    */
  }
    }
  }
}


void displaystagecompleted(int stage)
{
  // V 0.04
  int cnt = 0;
  cnt =  getvstagecomp(stage);
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
    int height = 80; //getheight(vself);
    int x = getentityproperty(self,"x");
    int xscr = openborvariant("xpos");
    int z = getentityproperty(self,"z");
    //log( " x " + x + " z " + z + " xscr " + xscr);
    if ( x!= NULL() && z != NULL() )
    {
      drawstring((x-xscr), 100, 1, cnt );
    }
  }
}


int getvchaptercomplete(int isTrue)
{

  void s = getindexedvar(1);
  //void s = getlocalvar("chap");
  //void s = getglobalvar("chap");


  if ( s > 0 ) { s = s; } else
  {
    settingsload(1);
    s = getindexedvar(1);
  }

  return s;


}


void getvcritical(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(32); } else
  if (plr ==1)
  { val = getindexedvar(33); } else
  if (plr ==2)
  { val = getindexedvar(34); } else
  if (plr ==3)
  { val = getindexedvar(35); }
  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvcritical(plr);
  }

  return val;
}


int getvdifficulty(int isTrue)
{
  //s = getglobalvar("Diff");
  void s = getindexedvar(0);
  //s = getscriptvar();
  //s = getlocalvar("Diff");

  if ( s > 0 ) { s = s; } else
  {
    settingsload(1);
    s = getindexedvar(0);
  }


  return s;


}


void getvfireburst(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(59); } else
  if (plr ==1)
  { val = getindexedvar(60); } else
  if (plr ==2)
  { val = getindexedvar(61); } else
  if (plr ==3)
  { val = getindexedvar(62); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvfireburst(plr);
  }

  return val;
}


void getvmaxhealth(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(2); } else
  if (plr ==1)
  { val = getindexedvar(3); } else
  if (plr ==2)
  { val = getindexedvar(4); } else
  if (plr ==3)
  { val = getindexedvar(5); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvmaxhealth(plr);
  }

  return val;
}


void getvmp(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(10); } else
  if (plr ==1)
  { val = getindexedvar(11); } else
  if (plr ==2)
  { val = getindexedvar(12); } else
  if (plr ==3)
  { val = getindexedvar(13); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvmp(plr);
  }

  return val;
}


void getvnpc(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(28); } else
  if (plr ==1)
  { val = getindexedvar(29); } else
  if (plr ==2)
  { val = getindexedvar(30); } else
  if (plr ==3)
  { val = getindexedvar(31); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvnpc(plr);
  }

  return val;
}


void getvscore(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(6); } else
  if (plr ==1)
  { val = getindexedvar(7); } else
  if (plr ==2)
  { val = getindexedvar(8); } else
  if (plr ==3)
  { val = getindexedvar(9); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvscore(plr);
  }

  return val;
}


void getvspeed(int plr)
{
  int val = 0;
  if (plr ==0)
  { val = getindexedvar(14); } else
  if (plr ==1)
  { val = getindexedvar(15); } else
  if (plr ==2)
  { val = getindexedvar(16); } else
  if (plr ==3)
  { val = getindexedvar(17); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvspeed(plr);
  }

  return val;
}


void getvstagecomp(int stage)
{
  int val = 0;
  if (stage ==1)
  { val = getindexedvar(18); } else
  if (stage ==2)
  { val = getindexedvar(19); } else
  if (stage ==3)
  { val = getindexedvar(20); } else
  if (stage ==4)
  { val = getindexedvar(21); }  else
  if (stage ==5)
  { val = getindexedvar(22); }  else
  if (stage ==6)
  { val = getindexedvar(23); }  else
  if (stage ==7)
  { val = getindexedvar(24); }  else
  if (stage ==8)
  { val = getindexedvar(25); }  else
  if (stage ==9)
  { val = getindexedvar(26); }

  if ( val > 0 ) { val = val; } else
  {
    settingsload(1);
    val = getvstagecomp(stage);
  }

  return val;
}


int setvchaptercomplete(int val)
{

  setindexedvar(1,val);

}


void setvcritical(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(32,value); } else
  if (plr == 1)
  { setindexedvar(33,value); } else
  if (plr == 2)
  { setindexedvar(34,value); } else
  if (plr == 3)
  { setindexedvar(35,value); }
}


void setvdifficulty(int zDiff)
{
  //Matman v0.02
  int i = getvdifficulty(1);

  //settextobj({index}, {x}, {y}, {font}, {z}, {text}, {time})
  //void iTime = openborvariant("elapsed_time") + getentityproperty(entity, "freezetime");
  settextobj(12, 200, 126, 1, 1, "Difficulty set to " + i, openborvariant("elapsed_time")+200);
  /*
  if(i==1){drawstring(200, 136, 1, "Difficulty set to Normal");} else
  if(i==2){drawstring(200, 136, 1, "Difficulty set to Hard");} else
  if(i > 2){drawstring(200, 136, 1, "Difficulty set to Harder " + i);}
  */
  if (zDiff == 1) { //Increase difficulty
    setindexedvar( 0, i + 1 );
  } else
  if (zDiff == 0) { //Decrease difficulty
    if (i > 1)
    {
      setindexedvar( 0, i -1 );
    }

  }
  //setglobalvar("Diff", "2");
  //setindexedvar(0,zDiff);
  //setscriptvar(0, "2");
  //setlocalvar("Diff", 2);
  //void s = getlocalvar("Diff"); //doing it this way work fine
  //drawstring(200, 156, 1, getdifficulty(1)); //calling the method doesn't work


}


void setvfireburst(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(59,value); } else
  if (plr == 1)
  { setindexedvar(60,value); } else
  if (plr == 2)
  { setindexedvar(61,value); } else
  if (plr == 3)
  { setindexedvar(62,value); }

}


void setvmaxhealth(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(2,value); } else
  if (plr == 1)
  { setindexedvar(3,value); } else
  if (plr == 2)
  { setindexedvar(4,value); } else
  if (plr == 3)
  { setindexedvar(5,value); }

}


void setvmp(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(10,value); } else
  if (plr == 1)
  { setindexedvar(11,value); } else
  if (plr == 2)
  { setindexedvar(12,value); } else
  if (plr == 3)
  { setindexedvar(13,value); }

}


void setvnpc(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(28,value); } else
  if (plr == 1)
  { setindexedvar(29,value); } else
  if (plr == 2)
  { setindexedvar(30,value); } else
  if (plr == 3)
  { setindexedvar(31,value); }

}


void setvscore(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(6,value); } else
  if (plr == 1)
  { setindexedvar(7,value); } else
  if (plr == 2)
  { setindexedvar(8,value); } else
  if (plr == 3)
  { setindexedvar(9,value); }

}


void setvspeed(int plr, int value)
{
  if (plr == 0)
  { setindexedvar(14,value); } else
  if (plr == 1)
  { setindexedvar(15,value); } else
  if (plr == 2)
  { setindexedvar(16,value); } else
  if (plr == 3)
  { setindexedvar(17,value); }

}


void setvstagecomp(int stage, int value)
{
  if (stage == 1)
  { setindexedvar(18,value); } else
  if (stage == 2)
  { setindexedvar(19,value); } else
  if (stage == 3)
  { setindexedvar(20,value); } else
  if (stage == 4)
  { setindexedvar(21,value); } else
  if (stage == 5)
  { setindexedvar(22,value); } else
  if (stage == 6)
  { setindexedvar(23,value); } else
  if (stage == 7)
  { setindexedvar(24,value); } else
  if (stage == 8)
  { setindexedvar(25,value); } else
  if (stage == 9)
  { setindexedvar(26,value); }

}




void shootentitybomb(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   // v0.02
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     int Direction = getentityproperty(self, "direction");
     int x = getentityproperty(self, "x");
     int y = getentityproperty(self, "a");
     int z = getentityproperty(self, "z");

     if (Direction == 0){ //Is entity facing left?
        dx = -dx; ////Reverse X direction to match facing
     }
    //entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
     projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 1, 0);
   }
}


void shootentityknife(void Shot, float dx, float dy, float dz)
{ // Shooting projectile
   // v0.02
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     int Direction = getentityproperty(self, "direction");
     int x = getentityproperty(self, "x");
     int y = getentityproperty(self, "a");
     int z = getentityproperty(self, "z");

     if (Direction == 0){ //Is entity facing left?
        dx = -dx; ////Reverse X direction to match facing
     }
    //entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
     projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   }
}


void shootentityknifedirection(void Shot, float dx, float dy, float dz, int changedirection)
{ // Shooting projectile
   //v0.02
   void self = getlocalvar("self");
   if ( checkent(self) == 1 ) {
     int Direction = getentityproperty(self, "direction");
     int x = getentityproperty(self, "x");
     int y = getentityproperty(self, "a");
     int z = getentityproperty(self, "z");
     if (changedirection == 1)
     {
       if (Direction == 1){
         dx = -dx;
         Direction = 0;
       } else {
         Direction = 1;
       }
     } else {
       if (Direction == 0){
         dx = -dx;
       }
     }
  //entity * projectile(char *name, float x, float z, float a, int direction, int type, int ptype, int map)
     projectile(Shot, x+dx, z+dz, y+dy, Direction, 0, 0, 0);
   }
}

void tosstargetinpainself(void x, void y, void z, void useRange)
{
  //Toss's target back if he is in pain
  // V0.01 MatMan
  void self = getlocalvar("self");
  if ( checkent(self) == 1 ) {
  
    tosstargetinpain(getentityproperty(self, "opponent"),x,y,z,useRange);
  }
}

void tosstargetinpain(void target, void x, void y, void z, void useRange)
{
  //Toss's target back if he is in pain
  // V0.01 MatMan
  if ( checkent(target) == 1 ) {
     void cancon = isinpainanimation(target);
     int Direction = getentityproperty(target, "direction");
     if (useRange == 1)
     {
       if ( checkrange(target, getentityproperty(target, "opponent")) > 0 ) { cancon = 1; }
       else { cancon = 0 ;}
     }
     if ( cancon == 1) {
       if (Direction == 0){ //left
         tossentity(target, y, x, z);
       } else { tossentity(target, y, -x, z); }
     }
     
  }
}

//#|edited by openBor Stats v 0.50