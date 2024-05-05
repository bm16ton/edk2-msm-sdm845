This is my fork/hybrid edk2-msm edk2sdm845 for oneplus 6t, non of the repo's i found had both the ability to boot/dual-boot android and linux, with working touchscreen support. The touchscreen is working because of a terribly dirty aweful hack...but it works. I have partitioned my user data into 2 partitions a fat32 boot at its start followed by ext4 linux root. Heres how to install;

./build.sh --device fajita --toolchain GCC5 --installer-zip

then copy over the newly created uefi-installer-fajita.zip to your phone and from your magisk rooted android install use magisk  app  to  install it as a module. This has only been tested with android 9, tho its said somewhere you can use twrp to install this but not sure how two hooks for recovery would play with each other. I then created the boot config file  simpleinit.static.uefi.cfg in my fat32 boot partition, I have put a copy in root of this repo. With this setup on boot the bootloader will present multiple options, reboot to android for android and linux mainline for linux.

ORIGINAL README CONTENTS;


# EDK2 UEFI firmware for Qualcomm Snapdragon platforms

![banner_wide_dark](https://user-images.githubusercontent.com/17036722/199902341-b086ec31-8d5c-4766-953a-8b9e1492de8b.png)

![Github](https://img.shields.io/github/downloads/edk2-porting/edk2-sdm845/total)
![Github](https://img.shields.io/github/v/release/edk2-porting/edk2-sdm845?include_prereleases)

## Description

This repository aims to provide an usable EDK2 UEFI environment for modern Qualcomm SoCs.

It can be used as a boot manager for multi-booting mainline Linux, Android and optionally Windows on certain SoCs.

## User guide and documentations

Please visit [Renegade Project Wiki](https://wiki.renegade-project.cn/)

## Acknowledgements
- Gustave Monce and his [SurfaceDuoPkg](https://github.com/WOA-Project/SurfaceDuoPkg)
- [DuoWoa Project](https://github.com/WOA-Project)
- [EFIDroid](https://github.com/efidroid)
- [Ben (Bingxing) Wang](https://github.com/imbushuo/)
- [Lumia950XLPkg](https://github.com/WOA-Project/Lumia950XLPkg)
- BigfootACA and his [SimpleInit](https://github.com/BigfootACA/simple-init) and [LinuxSimpleMassStorage](https://github.com/BigfootACA/linux-simple-mass-storage)
- fxsheep and his original edk2-sagit
- All the developers and members of [Renegade Project](https://github.com/edk2-porting/) for offering efforts, equipments, valuable documents and more
## License
All code except drivers in GPLDriver directory are licensed under BSD 2-Clause. GPL Drivers are licensed under GPLv2 license.
