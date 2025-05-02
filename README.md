# YAUD - Yet Another User Defender

## What YAUD is doing?
YAUD is a program that makes using terminal safer for new GNU/Linux users and blocks rm(in dangerous directorys), umount,dd and mkfs commands while it is working. When YAUD is closed, it is not saying anything.

## How to use YAUD?

`sudo yaud --h` (help) help menu
`sudo yaud --s` (status) Shows it is working or not
`sudo yaud --c` (close) closes YAUD
`sudo yaud --a` (activate) opens YAUD

## Is it have to run with sudo?

Yes. Because when it is installing, it copies files to /usr/local/bin and it needs root to do it. And for detecting things like sudo rm -rf / it needs to run with sudo. If it doesn't run with sudo it will give error.

# How to install it?

## 1. Install the requried apps:
Arch and Arch based: `sudo pacman -S git gcc g++`
Debian and Debian based: `sudo apt install git g++ gcc`
Fedora/RHEL and Fedora/RHEL based: `sudo dnf install git gcc-c++`
openSUSE and openSUSE based: `sudo zypper install git gcc-c++`
Alpine and Alpine based: `sudo apk add git g++`
Old Pardus(not debian based) versions and PisiLinux: `sudo pisi it git gcc`
Gentoo and Gentoo based: `sudo emerge --ask dev-vcs/git sys-devel/gcc`
## 2. Clone the repo with `git clone git clone https://github.com/npc-gnu/yaud.git` .  
## 3. Enter the directory with running cd yaud. Dont enter the yaud/src or yaud/include otherwise you cant compile it.
## 4. Compile by running these commands:

g++ -Iinclude src/yaud.cpp -o yaud && g++ -Iinclude src/dd.cpp -o dd && g++ -Iinclude src/rm.cpp -o rm && g++ -Iinclude src/umount.cpp -o umount && g++ -Iinclude src/mkfs.cpp -o mkfs && g++ -Iinclude src/installer.cpp -o installer

## 5. Run the installer by `sudo ./installer` . When the installation is completed, yaud will not activate. To activate yaud run `yaud --a` .
## 6. Thats it. Now you can use yaud.

NOTE: Yaud's warnings and help table is turkish for now. It will be english soon.

# License

This project and every part of it lisenced by GNU General Public Lisence v3. (GPLv3).

