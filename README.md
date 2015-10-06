Trigram
=======

This is a trigram generator that creates new plausible-sounding words based on a list of
input words. It is written in C++ and uses wxWidgets for the user interface. It was
originally available at http://zetacentauri.com

![ZC Trigram Generator Screenshot](https://github.com/Xangis/Trigram/blob/master/images/Trigram1b.png)

A prebuilt Windows install is in the installer directory.

Building requires that wxWidgets 2.6+ be installed (2.8 recommended).  There is a Makefile
for use on Linux.  If your wx-config is in a different location than that in the Makfile,
change the path in the Makefile.

This should also build on Windows, but you'll have to create your own Visual Studio project.
There are two .hpp and two .cpp files, so that should be easy. Setting paths and libraries
in Visual Studio is the most annoying part of creating a project, and wxWidgets is a
particular nuisance in that respect.

This project uses the MIT License.
