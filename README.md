
# VikingMud's Modified DGD Driver

This repository, `viking-dgd`, contains the modified DGD (Dworkin's Game Driver) driver for VikingMud. It is a work in progress to update our driver to a more modern version of DGD, tailored specifically for VikingMud's requirements and features.

Please note that this is not the official DGD repository. For the official DGD source code and documentation, please visit the [DGD source repository](https://github.com/dworkin/dgd) and [DGD's home page](https://www.dworkin.nl/dgd).

# Original Readme

This file was written for release 1.5 of DGD, Dworkin's Game Driver.

DGD is a rewrite from scratch of the LPMud server.  It runs on Windows, MacOS
and many versions of Unix.  The source repository for DGD can be found at:

    https://github.com/dworkin/dgd

DGD's home page is at:

    http://www.dworkin.nl/dgd/


This distribution is organized as follows:

bin		Installation binaries will be created here (Unix).
doc		Documentation, still very incomplete.
mud		A place to put the mudlib.
src		Where the source of DGD resides, and where you issue your
		`make' command on Unix.
src/host/*	Subdirectories for various platform-dependent files.
tmp		The place where temporary files, such as the swap file, are
		created by DGD.

See the file doc/Platforms for help on compiling DGD on various platforms.
Also consult the src/host/*/README file for your platform, if there is one.


This version of DGD is released under the GNU Affero General Public License.
