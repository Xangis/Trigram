# Trigram Generator

A word generation application for Windows and Linux.

This is a trigram generator that creates new plausible-sounding words based on 
a list of input words. It is written in C++ and uses wxWidgets for the user 
interface. It was originally available at http://zetacentauri.com and was
downloaded more than 12,000 times before being open-sourced.

![Trigram Generator Screenshot](https://github.com/Xangis/Trigram/blob/master/images/Trigram1.2StormNames.png)

A prebuilt Windows installer is in the installer directory:

https://github.com/Xangis/Trigram/blob/master/installer/ZCTrigramGenerator1.2Setup.exe

This project uses the MIT License. See the LICENSE.TXT file for details.

# Usage

Paste or type some text into the box at the top, or load a file using the 
"Load Text" button. Select the number of words to generate, and then click 
"Generate" and it will create words in the bottom box.

The more text you use in the top box, the better the results will be in the 
bottom. If you use too little text (generally less than a full paragraph), 
generation may fail because the program doesn't have enough to go on. In that 
case, add add a few more words and try again.

## How It Works

What the Trigram Generator does is look at pairs of letters and find out 
what letter usually shows up after that pair of letters. For instance, in 
the word "the" the trigram generator will see that "th" is followed by "e".

It counts up all of the probabilities in the original text and uses them
to generate random words. These words will be similar to those found in
the original text, but "mashed up" because the generator is looking at 
pairs of letters to select the next letter rather than looking at 
entire words.

For example, if you were to take a list of the tropical storm names for 
2006-2011 and use them to generate a new list of names, it would look like 
the screenshot above.
     
Another example would be taking a list of named stars and using it to 
generate new names. Since many of the names of stars in the Milky Way are 
based on Arabic names, the generated words would tend to be vaguely 
Arabic-sounding.

![Trigram Generator Screenshot](https://github.com/Xangis/Trigram/blob/master/images/Trigram1.2StarNames.png)

There are a few uses for this tool. The most common reason would be to come 
up with a name for a character in a story, a product, a place, a business,
or any sort of proper noun. The advantage of using a trigram generator is 
that the words generated will tend to look similar to the input and will 
often be pronounceable.

# Building

Building requires that wxWidgets 3.0 be installed, though it should also work 
with other versions (2.8, etc). 

## Linux

There is a Makefile for use on Linux that assumes
access to wx-config in your path. If your wx-config is in a different location, 
change the path in the Makefile.

To get the required wxWidgets development libraries on an Ubuntu or Debian-based 
system, run:

sudo apt-get install libwxgtk3.0-dev

## Windows

To get wxWidgets for Windows, download it here:

http://wxwidgets.org/downloads/

There is a Visual Studio project included as Trigram.sln. However, you'll need to
edit the "Additional Library Directories" and "Additional Include Directories"
paths to point to where wxWidgets is on your system.

If it complains about not finding "wx/wx.h", then you need to set the include
path.

If it complains about a bunch of "unresolved external symbols" starting with wx,
then you need to set the library path.

# Changelog

### Changes in Version 1.2:

- Added "Load Text" button to load a text file.

# Development Status

I consider this application to be finished and it is no longer under active 
development. However, I do still maintain it and will update it as necessary
to be sure that it runs on modern operating systems.
