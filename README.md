# Trigram

A word generation application for Windows and Linux.

This is a trigram generator that creates new plausible-sounding words based on 
a list of input words. It is written in C++ and uses wxWidgets for the user 
interface. It was originally available at http://zetacentauri.com

![ZC Trigram Generator Screenshot](https://github.com/Xangis/Trigram/blob/master/images/Trigram1b.png)

A prebuilt Windows installer is in the installer directory:

https://github.com/Xangis/SampleRate/blob/master/installer/SampleRateAndBPMCalculator1.01Setup.exe

This project uses the MIT License. See the LICENSE.TXT file for details.

## Building

Building requires that wxWidgets 3.0 be installed, though it should also work 
with other versions (2.8, etc). There is a Makefile for use on Linux that assumes
access to wx-config in your path. If your wx-config is in a different location, 
change the path in the Makefile.

To get the required wxWidgets development libraries on an Ubuntu or Debian-based 
system, run:

sudo apt-get install libwxgtk3.0-dev

To get wxWidgets for Windows, download it here:

http://wxwidgets.org/downloads/

This should also build on Windows, but you'll have to create your own Visual Studio project.
There are two .hpp and two .cpp files, so that should be easy. Setting paths and libraries
in Visual Studio is the most annoying part of creating a project, and wxWidgets is a
particular nuisance in that respect.

# Development Status

I consider this application to be finished and it is no longer under active 
development. However, I do still maintain it and will update it as necessary
to be sure that it runs on modern operating systems.
