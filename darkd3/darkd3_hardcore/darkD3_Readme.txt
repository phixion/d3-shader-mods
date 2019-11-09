------------------------------------
Darker D3 Filter v 1.1
------------------------------------
Instructions:
	1.	If this is the FIRST time you start Diablo III or the first time after a recent PATCH,
		launch the game then close it, before you proceed.
	1.	Extract/copy all the files in this zip/folder into the root directory of your Diablo III install.
	2.	Run Diablo III, if the launcher starts the game, the filters might cause it to crash. 
		Try starting the game again if this happens. 
		OR run the game without the launcher by running "Diablo III.exe" and not from your desktop or using the "Diablo III Launcher.exe"
	3.	Use the Pause key (beside the Scroll Lock key) to turn the effects On/Off.

------------------------------------
How to uninstall:
	- Remove all files with the prefix "darkD3" and the file "d3d9.dll" in your Diablo III install folder,

------------------------------------
Known issues:
	-	Starting the game with FRAPs (or similar overlays) with the filter on NVIDIA-based cards might not enable the effects.
	-	The sharpening effect might cause an FPS slow down on certain hardware.
		Make sure you have the latest DirectX installed and have updated your video card drivers.

------------------------------------
Risk of getting banned:

I am aware that Blizzard's stance on modifications makes them prohibited. 
But this filter should NOT fall into Blizzard's definiton of a game modification, aka MOD.
The Battle.net Terms of Use prohibit:
	- "The use of cheats, automation software (bots), hacks, mods or any other unauthorized third-party software designed to modify the Service, any Game or any Game experience"
	- "Modify or cause to be modified any files that are a part of any Game or the Service in any way not expressly authorized by Blizzard"
	- "The use any unauthorized third-party software that intercepts, "mines", or otherwise collects information from or through any Game or the Service, including without limitation any software that reads areas of RAM used by any Game or the Service to store information about a character or a Game environment; provided, however, that Blizzard may, at its sole and absolute discretion, allow the use of certain third party user interfaces;"
The reason why is because of these facts:
 - Applying this filter does not modify any of Diablo 3's files at all.
 - When you start the game with the filter nothing gets changed or edited. 
		(Read "What the file "d3d9.dll" does" in the next section for an explanation) 
 - When the game starts with the filter, NONE of the game's process memory is altered. Meaning nothing of the memory is read, written or modified.
		(Altering the game's memory is how many cheats and hacks work, and causes Blizzard's anti-cheat system to raise a red flag)
 - Using this filter in the simplest terms creates a custom version of DirectX, or customized video card drivers.
 - This filter basically adds on a "layer" of pixel shaders changing the way your video card displays the game.
 - Other programs like FRAPs, and the Steam Ingame Overlay use these same techniques to add on to what is rendered on your game's screen.
		(Even worse they do not simply override the d3d9.dll by adding it to the game's startup directory like this filter does,
			they inject their dll files from an external program into the game, a method also commonly used by hacks)
 - There is another filter similar to this one called "ENBSeries" that some WoW players use, and Blizzard did not ban anyone for it.

It is still your own choice if you don't feel confident on using the filter because you might get banned. 

------------------------------------
How it works:

This is a Direct3D DLL override hook that adds custom post processing shader filtering effects onto almost any game.
The filtering values were tweaked to fit different Diablo III color schemes. 
It changes the saturation, color tones, gamma, exposure, sepia tone, and sharpening of the game.

What the file "d3d9.dll" does:
When Windows loads a program's requested libraries (dll files) it first looks in the EXE file's start up directory, and then the system folders.
The real d3d9.dll is stored in "C:\Windows\System32", so by taking advantage of how Windows loads dlls
we can place a different d3d9.dll in the game's root directory, that loads custom DirectX rendering code and then references the real d3d9.dll.
The game will see this as a normal Direct3D loading procedure and should not raise any red flags
as it does not modify the game's code, read or write its memory (this is how many cheats and hacks work), and does not modify the game's files in any way.

Once the customized DLL is loaded it reads the "darkerD3.fx" shader file and applies the effects based on values in the file "darkerD3_Settings.h".


Editing the filter values your self:

If you have some programming syntax knowledge feel free to open the darkD3_Settings.h file in Notepad and edit the values for the effects.
You can change the file while the game is running and the filter will still apply the changes.

------------------------------------
CREDITS:

Adapted and modified for Diablo III by:
	Axecutioner, aka Pyloneer

The DLL and shaders orignate from www.3dcenter.org

Forum thread: http://www.forum-3dcenter.org/vbulletin/showthread.php?t=510658

- Direct3D injection method provided by: 
	[some dude]

- Original code added and aranged by:
	[some dude]
	BeetleatWar1977
	[DKT70]
	Violator
	fpedace