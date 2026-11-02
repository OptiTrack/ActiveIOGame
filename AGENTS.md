# AGENTS.md

### Project Overview

This project is an Unreal Engine application developed in collaboration with OptiTrack. The project will integrate motion-tracking data with Unreal Engine. Specific implementation details and requirements will be documented as development progresses.

### Technology Stack

- Engine: Unreal Engine (version TBD with OptiTrack)
- Language: C++ and Unreal Engine Blueprints as needed
- Development Environment: Visual Studio
- Version Control: Git and GitHub
- CI/CD: GitHub Actions
- Asset Management: Git LFS or another team-approved method

### Development Conventions

AI-assisted contributions must follow the team's Contributing Guide.

- Create feature branches for changes; do not commit directly to main.
- Keep changes small, focused, and consistent with existing code.
- Follow established Unreal Engine and C++ coding conventions.
- Include relevant tests and documentation updates.
- Use GitHub Issues to track tasks and pull requests for code review.
- Ensure all required CI checks pass before merging.

### Testing and Review

All changes must meet the team's Definition of Done. Code should compile successfully, pass applicable tests, linting, and security checks, and receive approval from at least one teammate before merging.

When tracking hardware is unavailable, use mock input for local testing where applicable.

### Security and Confidentiality

- Never include credentials, API keys, tokens, or secrets in source code.
- Do not expose OptiTrack confidential information, NDA-protected materials, or proprietary data to external AI services without authorization.
- Do not commit sensitive files or generated assets containing confidential information.
- Review AI-generated code for correctness, security, and compliance before use.

### Documentation References

Refer to the repository's CONTRIBUTING.md for development workflows, testing, branching, reviews, and releases. Additional project documentation will be maintained in README.md and docs/.

### Future Updates

Once the project structure and codebase are established, this file will be updated with exact Unreal Engine versions, build instructions, coding standards, testing commands, CI configurations, and project-specific architectural constraints.

Ownership: The team and Optitrack will have dual ownership over the completed product.
