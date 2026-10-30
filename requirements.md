# Project Requirements

## 1. Problem Statement

The project partner is developing ActiveIO, a motion-tracking product line that uses infrared (IR) patterns for precise and resilient tracking. The partner needs an interactive trade-show demonstration that allows visitors to experience the technology firsthand. The proposed solution is a small arcade-style shooting game inspired by *Big Game Hunter*, in which a physical gun tracked by ActiveIO controls in-game aiming. The game should provide an engaging experience while demonstrating the capabilities of ActiveIO hardware. This need is based on the partner's project description; direct feedback from trade-show visitors has not yet been collected.

## 2. Functional Requirements

Requirements use **MoSCoW prioritization** (Must, Should, Could, Won't). Priorities describe importance rather than implementation order.

*Partner-stated* indicates a requirement explicitly mentioned in the project description. *Assumed* indicates a proposed requirement awaiting partner confirmation.

### FR-1: ActiveIO Weapon Tracking
- **Priority:** Must — demonstrating ActiveIO tracking is the primary purpose of the project.
- **Status:** Partner-stated.
- **Requirement:** The game must use ActiveIO tracking hardware to control the aiming direction of the in-game weapon.
- **Acceptance Criteria:**
  - Moving or rotating the physical tracked gun changes the aiming direction in the game.
  - The aiming direction corresponds to the physical movement of the gun.
  - The player can aim using ActiveIO without relying on mouse movement.

### FR-2: Target Shooting
- **Priority:** Must — shooting targets is the core gameplay mechanic.
- **Status:** Partner-stated.
- **Requirement:** Players must be able to shoot targets or enemies using an ActiveIO-tracked weapon.
- **Acceptance Criteria:**
  - The game displays targets that can be shot.
  - Shooting while correctly aiming at a target registers a hit.
  - Shooting outside a target does not register a hit on that target.

### FR-3: Score Tracking
- **Priority:** Must — scoring is explicitly required by the partner.
- **Status:** Partner-stated.
- **Requirement:** The game must track the player's score and display it at the top of the screen.
- **Acceptance Criteria:**
  - The current score is visible during gameplay.
  - Successfully hitting a target awards points.
  - The displayed score updates after points are awarded.
  - A new session begins with a reset score.

### FR-4: Gameplay Objectives
- **Priority:** Must — the partner requires an overarching gameplay goal.
- **Status:** Partner-stated.
- **Requirement:** The game must provide players with a clear objective and a way to determine whether they have completed it.
- **Acceptance Criteria:**
  - Players are informed of the gameplay objective.
  - Gameplay provides a way to progress toward the objective.
  - The game indicates when the objective has been completed.

### FR-5: Game Environment
- **Priority:** Should — the environment helps maintain visitor interest, but its theme is flexible.
- **Status:** Partner-stated.
- **Requirement:** The game must include a visually identifiable environment where targets appear.
- **Acceptance Criteria:**
  - The environment contains a visible background.
  - Targets appear within the playable environment.
  - The environment supports the target-shooting gameplay.

### FR-6: Settings Menu
- **Priority:** Should — configuration options are explicitly requested by the partner.
- **Status:** Partner-stated.
- **Requirement:** The game must provide a settings interface for configuring supported gameplay options.
- **Acceptance Criteria:**
  - Players or operators can open and close the settings menu.
  - Users can view available settings.
  - Changing a supported setting updates the corresponding game behavior.
  - Candidate settings include difficulty, environment, controls, and camera functionality. The final set requires partner confirmation.

### FR-7: Difficulty Configuration
- **Priority:** Should — adjustable difficulty may accommodate players with different skill levels.
- **Status:** Assumed.
- **Requirement:** The game should provide at least two selectable difficulty levels that alter gameplay challenge.
- **Acceptance Criteria:**
  - The user can choose between at least two difficulty levels.
  - Changing difficulty produces an observable difference in gameplay challenge.

### FR-8: Game Session Restart
- **Priority:** Should — trade-show demonstrations need to accommodate multiple visitors.
- **Status:** Assumed.
- **Requirement:** Players or operators should be able to begin a new gameplay session without restarting the application.
- **Acceptance Criteria:**
  - Users can start a new session after completing a previous session.
  - Starting a new session resets the score and objective progress.
  - The application remains running between sessions.

## 3. Non-Functional Requirements

The thresholds below are **proposed targets**, not yet approved by the partner. They must be tested using the intended demonstration hardware.

| ID | Requirement | Priority and reason | Measurement |
|---|---|---|---|
| NFR-1 | The game must reflect received ActiveIO tracking updates on-screen within 100 ms at the 95th percentile. | Must — responsive tracking is central to the demonstration. | Measure at least 100 tracking updates on the demonstration hardware. |
| NFR-2 | The game should maintain at least 30 FPS for 95% of one-second measurement windows. | Should — smooth rendering improves the gameplay experience. | Record frame rate during five minutes of gameplay. |
| NFR-3 | The game must complete 10 consecutive gameplay sessions without crashing or requiring an application restart. | Must — reliability is important for trade-show use. | Run 10 consecutive sessions and record failures. |
| NFR-4 | The game should be reproducibly launched from a clean clone without undocumented setup steps. | Should — developers and partner staff need repeatable setup. | Follow the README on a clean supported development machine. |

All four are currently **assumed** and require validation.

## 4. Constraints

Constraints represent requirements imposed by the partner or project environment, rather than technology decisions made by the development team.

- **C-1: ActiveIO Integration.** ActiveIO hardware must control weapon targeting. A mouse-only implementation does not fulfill the project objective.
- **C-2: Trade-Show Demonstration.** The game must be suitable for demonstrating ActiveIO's interactive tracking capabilities at trade shows.
- **C-3: Game Scope.** The product must be a small target-shooting game inspired by *Big Game Hunter* or an analogous game, rather than a full-scale commercial game.
- **C-4: Hardware and Integration Dependencies.** The project must work with the ActiveIO hardware and integration interfaces provided or approved by the partner. Specific interfaces and compatibility requirements remain unconfirmed.

The partner description does not establish a required game engine, operating system, or deployment environment. These must be documented when confirmed.

## 5. Success Metrics

The following proposed metrics will evaluate whether the project achieves its intended purpose.

| Metric | Proposed target | Verification |
|---|---|---|
| Tracking accuracy | At least 18 of 20 aiming-and-fire attempts register the intended target. | Conduct a structured targeting test using ActiveIO hardware. |
| Game stability | 10 consecutive game sessions without crashes or manual restarts. | Run and record consecutive gameplay sessions. |
| Player comprehension | At least 4 of 5 first-time players understand the gameplay objective without verbal assistance. | Observe first-time players and record their responses to a consistent question. |

Targets and test procedures require partner approval.

## 6. Non-Goals

The following features are excluded from the proposed initial scope:

- Recreating the entire *Big Game Hunter* game or its assets.
- Developing or redesigning ActiveIO tracking hardware.
- Online multiplayer functionality.
- User accounts or persistent online leaderboards.
- A general-purpose ActiveIO hardware configuration or calibration application beyond what the game requires.

These exclusions are proposed scope boundaries and have not yet been confirmed by the partner.

## 7. Open Questions

| Question | Responsible Owner | Resolve By |
|---|---|---|
| Which ActiveIO hardware, SDKs, and interfaces will be available, and how will tracking and trigger inputs work? | Whole Team | Before implementing FR-1 and FR-2 |
| What are the final gameplay rules, including scoring, objectives, difficulty, and target behavior? | Game Designers (Thanush, Max, Charlie) | Before implementing core gameplay |
| Which settings and customization options are required for the initial release? | OptiTrack Partner + Team | Before implementing FR-6 |
| What hardware and operating environment will be used for the trade-show demonstration, and what performance targets must it meet? | OptiTrack Partner + Team | Before finalizing deployment and performance requirements |

## 8. Requirements Maintenance

- Each requirement has a unique identifier so implementation tasks, pull requests, and tests can reference it.
- Requirements must be updated in the same pull request as changes to the corresponding behavior.
- Acceptance criteria remain in this document until the requirement is implemented and verified by a named test running in CI.
- Once verified through CI, acceptance criteria may be replaced by the corresponding test name.
- Changes requested by the project partner must be documented, including updates to priorities and confirmation status.
- Implementation order and sprint assignments are maintained on the project board rather than duplicated here.
