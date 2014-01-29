# LibMikuMikuPenguin(libmmp) v0.1 Readme (English)
Hello.

I wanted to MikuMiku on my favorite operating system, so I wrote a program to do just that.
It's still very buggy, and the API isn't particularly fixed in any manner so it's still too early to effectively use MMP as a library.
However, I hope that this becomes a starting point for the development of MMD on operating systems other than Windows (although you actually can use this library in Windows).

You should be able to get the latest version of the source code here:
https://github.com/sn0w75/MikuMikuPenguin/

## Contents
The contents are listed below:

* COPYING: This license for MikuMikuPenguin is included in here.
* doc: This is a folder for putting various documentation into, but there's nothing in here in particular at this point in time.
* include: LibMikuMikuPenguin's header (.h) files are in this folder.
* INSTALL: Details on the installation of LibMikuMikuPenguin are available in this file (English only)
* libmmp: LibMikuMikuPenguin's source (.cpp) files are in this folder.
* shaders: PMXViewer's shaders are in this folder.
* src: PMXViewer's source code (.cpp, .h) are in this folder.
* data: Required textures and other data files are in this folder.

## Requirements
For LibMikuMikuPenguin, libglfw, libglew, libglm, and libBullet are needed.

For PMXViewer, libmmp and libSOIL are needed. If you want to play music along with the VMD motion, you'll need SDL2 and SDL2_mixer. (You can compile the code without music playback support)

### Details about libraries (1/20/2014):
* libglfw: At the time of writing 2.7 is needed. Versions 3.0+ are not supported.
* libglm: At the time of writing 0.9.4 (0.9.2 and 0.9.3 may also be acceptable) is needed. Versions 0.9.5+ are not supported.

**WARNING!!!!!**

In GLM 0.9.3（perhaps also <=0.9.2）there's a bug:
https://github.com/g-truc/glm/issues/15

To avoid this bug, you must use the -fpermissive flag.
So like this:

    $ export CXXFLAGS="-fpermissive"
    $ autoreconf -i
    $ ./configure
    # make install

## Installation
This source code uses autotools, so compiling the code is very simple:

To compile, run the following commands in a terminal:

    $ autoreconf -i
    $ ./configure
    $ make

To install libmmp and PMXViewer on your system, run:

    $ sudo make install

(There may be an alternative to 'sudo' you need to use depending on your distro to run a process with admin privileges.)

If you have any other questions, please toss me a message. I'll gladly help you out.
* Twitter [@sn0w75](http://twitter.com/sn0w75)
* E-mail <ibenrunnin@gmail.com>


