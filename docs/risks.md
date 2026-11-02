# Risks

Objective: Develop a motion-capture game where players use motion-capture equipment to interact with enemies.

Ranking: Likelihood/Impact (H/M/L) and why.

R-1 technical, H/H: (Tracking feature unreliable; core game functionality relies on it).
Motion Capture tracking hasn’t been tested with the game’s intended movements and technology yet; if it fails to recognize the player's movements and actions, the core gameplay may become unresponsive.
Owner: Charlie Tolls
Mitigate: Test tracking with different players early in development.
Trigger: Repeated missed or incorrect detections during testing.

R-2 team, M/H: (Learning source control/development tools; mistakes can slow development).
The team may experience difficulty using source control correctly and tools for game development and Motion Capture integration. This can cause merge conflicts or delays to combining the work and having products running.
Owner: Maxwell Yang
Mitigate: Practice using branches, commits, and merging early on. Watch tutorials and be set up with tools.
Trigger: Experiencing repeated merge conflicts or losing track of changes. Problems with workflow.

R-3 technical, M/M: (Prototype still in development; some features take longer to implement).
Tasks that rely on each other in development may take longer than estimated if important features are unfinished in the prototype. The team may not have a game to use in motion capture testing.
Owner: Maxwell McKinney
Mitigate: Prioritize essential tasks and features, and refer to sprints to see progress.
Trigger: Seeing prototype tasks delayed into later sprints.


R-4 technical, M/M: (Prop design hasn’t been tested; design can interfere with tracking).
The prop design is still being developed and the design decision can potentially cause interference with motion capture system or struggle to recognize movements.
Owner: Thanushyan Balasankar
Accept, because initial design can be adjusted during testing without preventing prototype development, so fallback is cheap.
Mitigate: Consider motion-tracking requirements while designing prop and test the design.
Trigger: The prop interferes with tracking during testing.
R-5 business, M/M: (Not audience tested yet; unclear controls can affect demo experience).
Intended audience have not yet tested the gameplay experience. Demonstration of motion capture technology integration will not be successful if plates struggle with control or understanding the game.
Owner: Thanushyan Balasankar
Mitigate: Gather feedback from different groups of users.
Trigger: No playtesting session scheduled before gameplay is finalized.

R-6 technical, M/H: (Experiences delay in movements in motion capture; difficult controls).
Game may experience delays between players' movements and on-screen responses. Could lead to difficult controls for the user.
Owner: Maxwell Yang
Mitigate: Test input response times for optimization of tracking integration.
Trigger: Noticeable delays during gameplay testing.


Risk Review

Review the highest-ranked risks during every sprint planning meeting. Focus on which risks are most prevalent to this Sprint. Update the likelihood, triggers and mitigation plans accordingly as we progress. 
