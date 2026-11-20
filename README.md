# Optitrack ActiveIO Game
The Optitrack ActiveIO game is for use with Optitrack technology.

## Installation
The game will be an Unreal Engine 5.8.1 project using the OptitrackLiveLink
plugin, which is downloaded from the OptiTrack website. Also Visual Studio 2022

Setup Steps:
-Clone the repository
-Navigate to project directory
-Find Prototype_Capstone.uproject and click on .uproject file and select Generate Visual Studio project files
-This generates a .sln file in Visual Studio, so open that
-In toobar, select the following build configurations:
    -Configuration: Development Editor
    -Platform: Win64
-In Solution Explorer, find and click Prototype_Capstone project
-Select Build and wait for compilation to finish
-Click on Prototype_Capstone.uproject to launch file in Unreal Engine

Demo:
-Once Unreal Engine opens, find Content Drawer and go to Protolvl level
-Once level is loaded, click on Play button in toolbar of Unreal Engine
-Click on targets with left mouse button clicks to interact with them to see them disappear and respawn


## CI
No Unreal project is committed to this repo yet, so CI currently checks that the
six required docs exist and are non-empty. Build and gameplay tests will be added
once the Unreal project lands in the repo.
