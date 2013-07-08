Trigram
=======

A trigram generator that creates new plausible-sounding words based on a list of input words.

This is the source code used to create the ZC Trigram Generator available here:
http://zetacentauri.com/software_trigram.htm

Building requires that wxWidgets be installed.  There is a Makefile for use on Linux.  If
your wx-config is in a different location than that in the Makfile, change it.

This should also build on Windows, but you'll have to create your own Visual Studio project.
There are two .hpp and two .cpp files, so that should be easy.  As always, setting paths on
windows is the most annoying part of creating a project, and wxWidgets is a nuisance in that
respect.

This project uses the MIT License.
