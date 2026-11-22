# RFC: Hardware Prop Decisions

Project 12: Emergent technology and hardware integration end-to-end motion capture game/experience design

Charlie Tolls <tollsc@oregonstate.edu>

| Field | Value |
|---|---|
| Author | Charlie Tolls |
| Date | 2026-11-21 |
| Status | Proposed |
| Decision Date | Pending |
| Deciders | Pending |
| Superseded By | N/A |

## Problem and Context

Our capstone team is building a short arcade-style shooter for OptiTrack, a company that makes optical motion capture systems, as a trade-show and in-office demo of its ActiveIO tracking hardware. A visitor picks up a physical gun prop, aims it at a vertical screen, and the game follows the prop in real time (docs/design.md). It serves visitors who play for a few minutes with no training, and the OptiTrack staff who run the booth.

For readers new to motion capture: OptiTrack cameras track small infrared markers attached to an object. Motive is OptiTrack's software that turns the camera data into 3D positions and streams them to other programs. A "rigid body" is a group of markers whose distances never change, like markers fixed to a hard prop; Motive uses rigid body assets to track rigid, unmalleable objects (OptiTrack, n.d.-b), reporting the whole prop's position and rotation every frame. Our Unreal Engine 5.8.1 game will receive that stream through the OptitrackLiveLink plugin (README.md).

The game is a space-themed, level-based shooter. Level 1 has targets moving in formations (commit 42ad173), an enemy whose projectile the player must shoot down (ShooterGuy.cpp), and a physics ball that bounces into enemies (Ball.cpp).

This RFC decides the prop's shape: a handgun (like Time Crisis) or a long gun (like Big Buck Hunter). It touches the player-input path, which today is a mouse: MousePlayerController.cpp casts a ray under the cursor on a left click, and targets react through NotifyActorOnClicked (TargetActor.cpp). The prop will replace both.

Why now: the shape determines marker placement, trigger wiring, and level pacing. The trigger path is still TBD (docs/design.md), and our risk register rates unreliable tracking high likelihood, high impact (R-1, docs/risks.md). If we do nothing, levels get tuned around a mouse and the prop gets designed around the game, risking rework. We also build the prop at our partner's facility, so waiting adds lead time we do not control.

The decision is reversible today because nothing is printed or tuned to a prop. It becomes hard to reverse once we print, define the rigid body, and balance levels around the prop's feel.

## Options

### Option A: Long gun

This choice entails that we design a long gun for our project: a two-handed prop akin to a rifle. This choice works well with a slower, precise shooting game experience where two hands provide more leverage and accuracy; however, this choice doesn’t restrict us to this style of game. A larger prop also allows us to attach additional tracking markers if needed. An additional benefit is that our project partners already have several long gun props (including an airsoft rifle and a VR gun prop), which we can use without needing to design our own. The costs might include a clunkier, heavier, or slower experience overall, which might feel less natural for some users and might restrict us to a certain style of game. The airsoft rifle we held on our 2026-10-16 partner office tour was heavy. Right choice if playtesters strongly prefer it and a light enough version exists.

### Option B: Handgun

This choice means we design a smaller handgun prop, like a pistol, which allows one-handed play. A handgun-style prop benefits a faster-paced, shorter, casual experience where mobility is key. This prop style might allow greater accessibility and ease of use in general. Another benefit is that a smaller prop is easier to 3D print, which our project partners have allowed us to do at their facility. Of course, we aren’t restricted to a fast-paced style of game with this prop. The downsides include accuracy and possible technical challenges that occur with a smaller prop, plus design and print time. Right choice if a light printed pistol tracks as reliably as a long gun.

### Option C: Do Nothing

If we tread the current path and put off the prop design, we risk technical overhead, design mishaps, and lead-time challenges. We may not be worse off if we develop the game first and then build the prop, but the possibility of integration difficulties increases. Our project partners also require communication and collaboration with us to use their facility, so an earlier start window benefits both of us. The cost gradually builds the longer we put it off; there’s no set date where inaction hurts us. Right choice only if the tracking or trigger hardware were unavailable for weeks, so no prop could be tested anyway.

### Option D: Hybrid prop

A pistol with a detachable stock or foregrip, usable one-handed or steadied with two hands. The cost is complexity: attaching a part changes the shape and possibly which markers cameras see, so we need two rigid body definitions or a layout the attachment never covers, plus extra print time. Right choice if playtesters split clearly between pistol and rifle.

## Analysis

I weigh the tradeoffs below with evidence from our repository and outside sources.

The game performance implications of this choice are hard to identify now, but it’s possible that we have greater precision with a long gun with more markers mounted, but not guaranteed yet. Motive documentation recommends 4 ~ 12 markers per rigid body, placed asymmetrically so Motive can recognize the arrangement (OptiTrack, n.d.-a). A pistol has less surface to spread markers, the main tracking risk for Options B and D; we have not tested any prop yet, so this stays uncertain until the first prototype.

For user performance, the gun size and weight may affect comfort and enjoyment. Arm fatigue from sustained mid-air use is known to degrade user experience (Purdue University, 2017), so although a few-minute demo limits the risk, a heavier long-gun prop should be weighed and tested for comfort before we commit. For scale, AR-15-style airsoft rifles run about 4 to 6 lb: 5.4-5.9 lb for an Arcturus AR15 and 4.1 lb for a Lancer Tactical M4 (Airsoft GI, n.d.-a, n.d.-b). Peer design review feedback suggested 0.5 to 1 lb, about a phone's weight, noting a rifle is fun until the shoulder hurts.

The complexity is likely to be similar between design decisions. The ActiveIO Tag (a mo-cap hardware accessory we might use) supports up to eight LEDs and exposes a GPIO port for button clicks (OptiTrack, 2025), so either a long gun or a pistol can carry redundant tracking markers and a trigger input, which means the partner’s hardware does not force our design choice. In software, every option needs the same change: replacing the cursor ray in MousePlayerController.cpp and the click handlers in TargetActor.cpp, Ball.cpp, and Bullet.cpp with a ray from the rigid body's pose plus a trigger event. A handgun likely proves easier to print, and a long gun easier to test off the bat, considering our partners already have two existing props.

The other factors—maintainability, security, and cost—prove mostly irrelevant to this design decision. Maintainability is equal on either choice, security is not a concern, financial cost is handled through the OSU–OptiTrack partnership, and effort is similar, except that reusing the partner's long gun saves print time.

The other non-technical considerations relate to user enjoyment and the user experience. According to one source, replicating a gun’s shape and weight on a VR shooting controller had negligible effects on immediate shooting performance, but improved subjective appreciation (Berna Moya & Martinez Plasencia, 2019). Our game isn’t VR but is similar in theory, so we should choose the prop’s form factor for how the demo feels rather than for user aim accuracy (not to be confused with technical accuracy). Also, another source highlights that perceived in-game autonomy and competence are associated with game enjoyment, intuitive controls, and presence (Ryan, Rigby, & Przybylski, 2006), so the prop should be easy to pick up and make players feel effective within seconds.

Option C saves effort now but leaves the input path, trigger wiring, and R-1 unresolved.

## Recommendation and Verification Plan

While the decision will ultimately be decided among the whole team, I propose Option B for now.

I propose we build a lightweight pistol-style prop with a two-hand-friendly grip, since an arcade-paced, chaotic game favors a light prop. People realistically hold handguns with two hands, so the grip supports both. This also fits our gameplay, where formations and incoming projectiles reward quick aim changes. My sources emphasized several things that align with this choice: shape and weight had little effect on performance, intuitive controls and competence lead to enjoyment, and the ActiveIO Tag’s LED and GPIO capacity doesn’t force either shape.

A couple of design rules to ensure the smaller prop is sensed accurately should be to place markers high and forward on the prop, with hands low and back, and spread asymmetrically. If the following tests fail, we can redesign it as a compact, light long gun, or move to Option D.

We run these tests on the first prototype before locking in trigger software, repeating them with the partner's long gun as a baseline to show whether the pistol is actually better. Thresholds await team confirmation; latency and accuracy targets come from docs/requirements.md.

- **Tracking:** marker dropouts during a 3-minute session with several hand sizes and one- and two-handed grips. Pass: the rigid body is tracked in at least 99% of Motive frames.
- **Aim accuracy:** aim error at the screen’s top and bottom edges versus the center. Pass: at least 18 of 20 aim-and-fire attempts hit the intended target (requirements.md), within one hit of the long gun.
- **Comfort:** discomfort reported after 3 minutes, plus the prop’s measured weight. Pass: at most 1 lb, and no more than one tester rates arm or shoulder discomfort 3+ on a 1–5 scale.
- **Fun:** 5 to 8 playtesters rate the prop. Pass: median at least 4 of 5, and no lower than the long gun.
- **Trigger and latency:** trigger reliability, plus latency from Motive’s measurements. Pass: 50 of 50 presses register, and tracking updates appear on screen within 100 ms at the 95th percentile (NFR-1).

**Fail rule:** failing any test triggers a redesign (reprint, redefine the rigid body in Motive, recalibrate). If the pistol fails tracking or accuracy twice while the long gun passes, we switch to Option A.

## Constraints

I checked the license, ownership terms, NDA, and plugin; four bind this decision:

**Ownership and license:** AGENTS.md states the team and OptiTrack will have dual ownership of the completed product, and the repository is MIT-licensed under "Copyright (c) 2026 OptiTrack" (LICENSE). Committing printable prop files would publish them under MIT, so we confirm with the partner first or keep them out of the repo.

**Confidentiality:** our NDA bars posting project developments on social media, so prop playtest photos and videos stay internal. AGENTS.md forbids sending NDA material to external AI services, which limited what I shared with AI.

**Licensing:** the OptitrackLiveLink plugin is downloaded separately from OptiTrack (README.md). We check its terms before shipping a packaged build on GitHub Releases (docs/design.md), a condition on every option.

**Data use:** playtest ratings are collected anonymously with no names, so the verification plan stores no personal data.

## Delegation and Validation

Claude AI helped me with topic selection, evidence research, citations, terminology clarification, design suggestions, and the recommendation and verification plan. For this revision, Claude also read our repository, drafted expanded sections, and proposed pass/fail thresholds.

No prop code exists in the repo yet; when it does, it will follow our review gates. Our CI only checks that six required documents exist (.github/workflows/ci.yml), so the real gate is a pull request approved by a teammate who did not write it (CONTRIBUTING.md).

I stopped at every step and questioned every AI response for accuracy, truthfulness, relevance, and logic. I questioned the evidence AI provided and whether it was valid and whether the citations matched the presented evidence. I pieced together my own ideas first for each section of this decision and revised them with AI before proceeding.

I validated three points myself because they cost the most to get wrong. The thresholds decide whether we keep or abandon the prop, so I checked each against docs/requirements.md. I opened each cited repository file to confirm it says what the RFC claims. A wrong LED or GPIO count would break the trigger design, so I checked those against the ActiveIO spec sheet.

I asked clarifying questions and researched nuances before deciding on my proposal.

## Decision

I propose Option B: Handgun Prop Design. Status remains Proposed until the team runs the verification tests and agrees.

## References

Airsoft GI. (n.d.-a). Arcturus AR15 FE AEG airsoft rifle [Product listing]. https://www.airsoftgi.com/product/Arcturus-AR15-FE-AEG-Airsoft-Rifle-73387

Airsoft GI. (n.d.-b). Lancer Tactical LT-06B Gen 2 M4A1 carbine AEG airsoft rifle [Product listing]. https://airsoftgi.com/product/Lancer-Tactical-LT-06B-Gen-2-M4A1-Carbine-AEG-Airsoft-Rifle-Black-31578

Berna Moya, J., & Martinez Plasencia, D. (2019). Exploring the effects of replicating shape, weight and recoil effects on VR shooting controllers. In Human-Computer Interaction – INTERACT 2019 (Lecture Notes in Computer Science, Vol. 11746). Springer. https://www.researchgate.net/publication/335450125_Exploring_the_Effects_of_Replicating_Shape_Weight_and_Recoil_Effects_on_VR_Shooting_Controllers

OptiTrack. (2025). ActiveIO Tag [Product specification sheet]. NaturalPoint. https://optitrack.com/api/media/file/activeio-tag-spec-sheet.pdf

OptiTrack. (n.d.-a). Rigid body tracking [Motive 2.3 documentation]. https://docs.optitrack.com/v2.3/motive/rigid-body-tracking

OptiTrack. (n.d.-b). Rigid body tracking [Motive 3.2 documentation]. https://docs.optitrack.com/v3.2/motive/rigid-body-tracking

OptiTrack/ActiveIOGame. (2026). Project repository [GitHub]. https://github.com/OptiTrack/ActiveIOGame (files cited: README.md, LICENSE, AGENTS.md, CONTRIBUTING.md, docs/design.md, docs/requirements.md, docs/risks.md, .github/workflows/ci.yml, Source/Prototype_Capstone/)

Purdue University. (2017, May 8). Study researches “gorilla arm” fatigue in mid-air computer usage. https://engineering.purdue.edu/cdesign/wp/study-researches-gorilla-arm-fatigue-in-mid-air-computer-usage

Ryan, R. M., Rigby, C. S., & Przybylski, A. (2006). The motivational pull of video games: A self-determination theory approach. Motivation and Emotion, 30(4), 347-363. https://doi.org/10.1007/s11031-006-9051-8