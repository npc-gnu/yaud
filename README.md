![yaud logo](./yaudlogo.png)

# YAUD - Yet Another User Defender

## What is YAUD?

**YAUD** is a terminal safety tool designed to help new GNU/Linux users. It prevents potentially dangerous commands like `rm` (in critical directories), `umount`, `dd`, and `mkfs` from running while it is active. When YAUD is inactive, it does nothing and allows all commands.

## How to Use YAUD

| Command               | Description                         |
|-----------------------|-------------------------------------|
| `sudo yaud --h`       | Displays the help menu              |
| `sudo yaud --s`       | Shows whether YAUD is active        |
| `sudo yaud --c`       | Closes (deactivates) YAUD           |
| `sudo yaud --a`       | Activates YAUD                      |

## Does it Require Sudo?

Yes. YAUD must be run with `sudo` for the following reasons:

- During installation, it copies files to `/usr/local/bin`, which requires root permissions.
- To monitor or block commands like `sudo rm -rf /`, YAUD itself must also run as root.
- If run without `sudo`, it will return an error.

## Installation Guide

### 1. Install Required Packages

**Arch / Arch-based:**
```bash
sudo pacman -S git gcc g++
```

**Debian / Ubuntu-based:**
```bash
sudo apt install git g++ gcc
```

**Fedora / RHEL-based:**
```bash
sudo dnf install git gcc-c++
```

**openSUSE:**
```bash
sudo zypper install git gcc-c++
```

**Alpine:**
```bash
sudo apk add git g++
```

**Old Pardus (non-Debian) / PisiLinux:**
```bash
sudo pisi it git gcc
```

**Gentoo:**
```bash
sudo emerge --ask dev-vcs/git sys-devel/gcc
```

### 2. Clone the Repository

```bash
git clone https://github.com/npc-gnu/yaud.git
```

### 3. Navigate to the Project Directory

```bash
cd yaud
```

> ⚠️ Do **not** enter `yaud/src` or `yaud/include` directly, otherwise the build may fail.

### 4. Compile the Project

```bash
g++ -Iinclude src/yaud.cpp -o yaud && g++ -Iinclude src/dd.cpp -o dd && g++ -Iinclude src/rm.cpp -o rm && g++ -Iinclude src/umount.cpp -o umount && g++ -Iinclude src/mkfs.cpp -o mkfs && g++ -Iinclude src/installer.cpp -o installer
```

### 5. Install the Program

```bash
sudo ./installer
```

> After installation, YAUD is **not** activated by default.  
> To activate it, run:

```bash
yaud --a
```

### 6. You're Done!

YAUD is now ready to help protect your terminal experience.

## AUR Support?

There is an [AUR package](https://aur.archlinux.org/packages/yaud), but it currently doesn't work. I'm still working on fixing it.

## License

This project is licensed under the [GNU Affero General Public License v3 (AGPLv3)](https://www.gnu.org/licenses/agpl-3.0.html).
