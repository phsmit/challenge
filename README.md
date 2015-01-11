This is a sample Visual Studio project coded in C/C++ to get people started for the contest. I'm just a fellow contestant and so this is **not** an official reference.

"template" is the bare bones to make a DLL with the 3 functions, but they don't do anything.

"unofficial_reference" is a working solution using just the C++ standard library.

To get started, you'll first need a Windows 64-bit computer (the contest appears to only accept Windows 64bit DLLs).

For my sample, you'll need Visual Studio which you can get the free community edition at http://www.visualstudio.com/en-us/products/visual-studio-community-vs
(You can uncheck all the optional components when you install it)

Download all the files for this sample by clicking the "Download ZIP" on the right column of this page.

Then grab the zip file from the contest website if you haven't already. It includes a needed header file and the test framework.

To make it so you can debug your code, unzip them both so that the "solutions.sln" file is in a sub-folder of "point_search.exe" file like so:
```
challenge\
challenge\point_search.exe
challenge\point_search.h
challenge\challenge-master\solutions.sln
challenge\challenge-master\template\
...
 ```
 
Then once Visual Studio is done installing, just open the "solutions.sln" to begin.

If you're uncomfortable with the Visual Studio IDE and rather use your own editor, you can compile them from a command prompt opened in the solutions folder with these commands:
```
call "%VS120COMNTOOLS%VsDevCmd.bat"
devenv solutions.sln /build "Release|x64"
```
the resulting DLLs will be in the "x64" folder

