# CONTRIBUTING.md

### Contributing Guide

Contributing Guide: After following Getting Started to set up the project, each teammate creates a branch off main for their task (nobody commits directly to main), keeps changes small and focused, and play-tests in the Unreal editor (using mock or mouse input if hardware isn’t available) while running the relevant tests, linting, and security checks locally. They then open a pull request describing the change and including any documentation updates, and at least one teammate reviews and approves it, aiming for a response within 48 hours. Once all CI checks pass and the PR is approved, it merges into main, and the Quality Owner tags a release from main at the end of each sprint. (CI, linting, and security gates will be added as the repo grows, owned by the Quality Owner; exact tools and commands get filled in once code exists.)

### Code of Conduct

We treat teammates and OptiTrack staff respectfully and give feedback on the work, not the person. Concerns follow our charter’s conflict path: the team first, then our TA or instructors.

### Getting Started

Install Unreal Engine (version to be confirmed with OptiTrack), clone our team GitHub repo, pull the large starter assets using our agreed large-file method (e.g., Git LFS), then build and run locally. Secrets and NDA material never go in the repo. (Fill in exact versions and steps once code exists.)

### Branching and Workflow

We will use a feature-based design flow where each team member has a branch for their work. The “main” branch will be the default branch that has all of the updated, functioning code.

Branch naming should be task-based, defining the purpose of what is being added clearly. We will merge after testing and approving commits to the main branch. Rebasing will do the same to test that code functions properly before updating for everyone.

### Issues and Planning

We will use GitHub issues to track bugs, features, and project tasks. All issues need to include descriptive titles and short explanations. There will be acceptance criteria describing when a task will be complete. We will use labels like “feature, bug, documentation”. We will estimate task size by the amount of work needed, to help schedule and divide work. During team meetings, we will review issues, prioritize tasks, and assign tasks to a team member. Team member should update their issues.

### Commit Messages

We will have Conventional Commits like “fix: lights turn off after ___”. The commit messages should be concise and describe changes being made. When applicable, commits should reference the related GitHub issue using its number like “feat: add player movement (#12)”. We will use descriptive, short messages to indicate changes and updates.

### Code Style, Linting, and Formatting

We will follow a consistent C++ coding style across the project, use 4 spaces for indentation, and have descriptive names for variables and functions. Also having function headers that clearly comment on what something does. We will use formatting and code-checking tools supported by our development environment if available. We will prioritize readable code and address compiler warnings. Team members should ensure changes compile and work as expected before they are merged into the main branch.

### Testing

We will perform unit tests for individual functions and components. Integration tests to ensure gameplay systems work and playtesting to verify the game is working properly. Some important systems include motion tracking, enemy behavior, and hit detection. We should run automated tests before submitting a pull request. Manual playtesting should be performed for changes to gameplay. The specific test commands will depend on our game engine and build setup. We will aim to have at least 70% code coverage for testable gameplay logic. Features like motion capture and movement will require additional testing. Tests will be required on new features and when we face consistent bugs. All tests should pass before things are merged into main.

### Definition of Done

A task is considered complete when its implementation meets the requirements, passes relevant tests, receives approval from at least one teammate, and includes any necessary documentation updates. Code must also pass linting and security checks before merging. Pull requests must pass all CI checks and receive approval before merging into the main branch.

### Contribution Norm

Each team member is responsible for completing at least one accepted contribution per sprint. Tasks and progress will be tracked through GitHub Issues, with completed work submitted through pull requests or documented deliverables. Code contributions are accepted once reviewed, approved, and merged, while non-code contributions require team review and approval. Tasks will be divided into manageable sizes to ensure everyone can contribute, with pairing encouraged for more complex work. Team members should review pull requests within 48 hours to avoid blocking progress.

### Pull Requests & Reviews

All code changes must be submitted through GitHub pull requests using a standard template that includes a summary of changes, related issues, and a checklist for testing and documentation. PRs should be kept small and focused, ideally under 400 lines of code, with larger changes split when possible. Each PR requires approval from at least one teammate who did not author it, with reviewers expected to provide feedback within 48 hours. Before merging, all GitHub Actions CI checks, including automated tests, linting, and security scans, must pass. Authors must address review feedback and resolve outstanding comments before merging into the main branch.

### CI/CD

We will use GitHub Actions for CI/CD, with pipeline configurations stored in .github/workflows/. Mandatory checks will include automated tests, linting, and security scanning. Team members can view logs and re-run failed jobs through the repository's Actions tab. All CI checks must pass and at least one teammate must approve the pull request before merging into the main branch. Releases must also pass the full test suite. The CI/CD pipeline will be established by Sprint 2.

### Security & Secrets

All team members must follow secure coding practices and never commit hard-coded credentials, API keys, tokens, or other sensitive information. Secrets must be stored using approved environment variables or secret management tools. Suspected vulnerabilities or accidental exposure of sensitive information must be reported promptly to the team lead or designated security contact and must not be disclosed publicly. Dependencies should be kept up to date with security patches prioritized, and new dependencies should be reviewed for maintenance, reliability, and known vulnerabilities. Automated scanning tools, including dependency audits, secret detection, and static analysis, should be used where available to identify and address security risks before merging changes.

### Documentation Expectations

Documentation must be updated whenever changes affect functionality, setup, usage, or system behavior. This includes updating the README, relevant files in docs/, API references, and CHANGELOG as appropriate. Public functions, classes, and modules should include clear docstrings, while comments should explain complex or non-obvious logic. Documentation should remain concise, accurate, and consistent with the current implementation. Documentation updates are expected as part of any change that affects documented behavior.

### Release Process

Releases should follow Semantic Versioning (MAJOR.MINOR.PATCH), with version numbers reflecting the scope and impact of changes. Each release must include an updated CHANGELOG summarizing notable changes, fixes, and breaking changes. Approved releases should be tagged in version control and pass all required tests and checks before packaging or publishing through the project's designated distribution process. If a release introduces critical issues, the team should revert to the last stable version or deploy a hotfix, document the incident, and communicate relevant updates to affected contributors.

### Support & Contact

Contributors should direct questions, technical discussions, and implementation concerns to the team's designated communication channel or project discussion space. Bugs and feature requests should be submitted through the project's issue tracker, while urgent issues should be escalated directly to the maintainers. Maintainers should aim to acknowledge questions and reports within two business days, though resolution times may vary depending on complexity and availability. Contributors should provide sufficient context, relevant logs, and steps to reproduce issues when requesting support.
