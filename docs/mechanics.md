## Main Focus (Elevator pitch):
Present the player with split-second decisions between score and survival while managing resources in a fast-paced shooting gallery environment.

## Inspirations:
Super Monkey Ball 2: Monkey Shot minigame ([video here](https://www.youtube.com/watch?v=PkpZhiOrVEc))
- Arcade style shooting game
- Managing ammo, reload times, defending yourself from oncoming bullets
- Bullets that approach the screen and deal damage to you when they get too close

Wii Play: Shooting Range ([video here](https://www.youtube.com/watch?v=RsqLO3gWJp0))
(Mostly just the cans in level 4)
- Juggling an object with a peripheral controller pointed at the screen
- Quick-thinking and potential to quickly flick aim and hit targets for more points while risking dropping a juggled object
- Kinda exactly what we're doing, but made with 2006 hardware

Touhou 1: Highly Responsive To Prayer ([video here, major seizure warning](https://www.youtube.com/watch?v=w3YmmdgcHb8))
- Using a ball to hit targets
- More management of juggling a ball while avoiding danger

General top-down SHMUP genre, mostly the other Touhou games ([video of TH10 here](https://www.youtube.com/watch?v=ygM1rqNMGBo&t=23s))
- Having several smaller targets to mow through
- Making scoring rewarding to players who aren't motivated by high-score
- Balancing survival with playing greedily to get more points
- Wanting to perfect early stages to have more resources for later stages
- (Mostly relevant when we get to the campaign)

## Basic Mechanics:
Ammo: Player spends ammo to shoot targets, cannot shoot anymore when they're out of ammo until they reload.
- Creates moments of downtime the player needs to manage ("When am I safe to reload")
- Punishes players for shooting willy-nilly, rewards precision
- Makes shooting droves of fodder targets generally infeasible
- Reloading by doing something physical with the prop (Current idea is just pointing it down at the ground, away from the screen) would be interesting

Enemy Bullets: Enemies are able to shoot at you.
- These bullets can be shot to destroy them, but become a problem when they are numerous
- Generally move towards the screen and damage the player if they get too close
- Should have some sort of indicator for how close they are beyond just being eyeballed
- Player has only so much health before they lose

Ball: Player can juggle a ball into enemies to destroy them, skillful manipulation of this ball will allow them to destroy many more targets with less ammo.
- Managing this in a 3D space with a fixed camera angle is likely impossible to do well, so this ball and the enemies it interacts with will need to stay on a 2D plane. Other enemies, their projectiles, and level geometry don't need to be on this plane. (In the current greybox, the green shooter enemy is not on the ball plane.)
- Ball can go off the sides of the screen and is removed from play upon touching the floor, so making sure it remains in play is important 
- Generally, hitting targets with the ball will give more points and do significantly more damage than just shooting them, so it's beneficial to try to keep it around.
- Big risk: may be very difficult to control when we get to actual hardware.

Enemy Types: Several enemy types that do different things to attempt to hurt you or protect their allies. Some basic ideas (though different enemy types are generally very easy to implement):
- Basic fodder enemy
- Enemy that shoots a bullet at you
- Enemy that carries a shield to block line of sight to enemies behind it, but can be shot itself
- Enemy that explodes violently on death, killing nearby enemies and pushing nearby balls away violently
- Enemy that has, like, pinball bumpers on its side so it cannot be hit by a ball but can be shot
- Enemy that winds up and shoots a barrage of projectiles at you if allowed to complete their windup (think a minigun or something)
- Enemy that redirects all damage taken by allies in an area to itself with a massive health pool, but takes more damage from being directly shot
- Enemy that speeds up all bullets and balls on screen while it is alive
- Miniboss type enemy that teleports around the screen and shoots at you
- Boss enemy that can spawn balls below it and has a weak point on its top that can be hit by a ball, otherwise similarly bounces it away, so a ball has to be carefully juggled around it?
- Other ball manipulation enemies if that part ends up being fun

Game Modes: Two different modes for different settings
- Campaign Mode: A longer campaign of several levels meant to ramp up in difficulty, each one comprised of several different enemy formations and a boss, and comes to a natural end whenever the player is not skilled enough to continue or reaches the end. Finishing should take a significant amount of practice and engagement with game mechanics.
- Trade Show Mode: A singular longer level to show off the mechanics and be fun while not being overwhelming to someone seeing it for the first time. Most people should be able to win this while still being enjoyable.

Powerups: Have powerups be obtainable that temporarily give a buff to the player. Some ideas:
- Temporary unlimited ammunition
- Temporarily change the gun into a laser that damages anything it's pointing at
- Bomb an area of the screen, dealing heavy damage to anything in the area
- Spawn several balls that rain from the top of the screen
- Briefly slow time down

## Stretch Mechanics:
Multiplayer: Allow two players to co-op the campaign while simultaneously competing for points on the side (think Zelda Four Swords Adventures)
- Will require a second matching prop
- Mostly just kinda fun, but I can see programming it getting out of hand.
- Motive can track two different ActiveIO devices, right?

Campaign Mode Upgrade Progression: At the end of each level, you may choose upgrades to your gun (ammo clip size, reload speed, shot damage, etc.) from a selection a la Vampire Survivors to make a more roguelite experience. You receive more of these upgrades based on how many points you got.
- Will likely require some creativity so we don't *just* have number increases
- Easy way to make points valuable to players that don't care about high scores
- Fun, increases variety between different playthroughs
- Be fr with me, is replayability on a long campaign something we care about here?

Powerup Drawing: Instead of having powerups drop at specific points, drop a charge that can be expended to draw a shape to invoke an effect depending on the shape, a la Okami (i.e. drawing a bomb bombs the screen, drawing a bullet gives ammo)
- This one is a lot of work and deeply unecessary, but quickly drawing a shape with a prop in the heat of gameplay sounds fun
- Definitely a "if we finish early and have nothing else to do"


