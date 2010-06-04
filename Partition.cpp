#include "Partition.h"

string Partition::getTypeDescription(unsigned char type) {

    switch( type ) {
        case 0x00:
            return "Empty";
        case 0x01:
            return "DOS 12-bit FAT";
        case 0x02:
            return "XENIX root";
        case 0x03:
            return "XENIX /usr";
        case 0x04:
            return "DOS 3.0+ 16-bit FAT (up to 32M)";
        case 0x05:
            return "DOS 3.3+ Extended Partition";
        case 0x06:
            return "DOS 3.31+ 16-bit FAT (over 32M)";
        case 0x07:
            return "OS/2 IFS/HPFS/NTFS";
        case 0x08:
            return "AIX boot partition";
        case 0x09:
            return "AIX bootable";
        case 0x0a:
            return "OS/2 Boot Manager";
        case 0x0b:
            return "WIN95 OSR2 FAT32";
        case 0x0c:
            return "WIN95 OSR2 FAT32 (LBA)";
        case 0x0e:
            return "WIN95 DOS 16-bit FAT (LBA)";
        case 0x0f:
            return "WIN95 Extended partition (LBA)";
        case 0x10:
            return "OPUS";
        case 0x11:
            return "Hidden DOS 12-bit FAT";
        case 0x12:
            return "Compaq Config/diag partition";
        case 0x14:
            return "Hidden DOS 16-bit FAT <32M";
        case 0x16:
            return "Hidden DOS 16-bit FAT >=32M";
        case 0x17:
            return "Hidden OS/2 IFS/HPFS/NTFS";
        case 0x18:
            return "AST SmartSleep Partition";
        case 0x19:
            return "Unused";
        case 0x1b:
            return "Hidden WIN95 OSR2 FAT32";
        case 0x1c:
            return "Hidden WIN95 OSR2 (LBA)";
        case 0x1e:
            return "Hidden WIN95 16-bit FAT (LBA)";
        case 0x21:
        case 0x22:
        case 0x23:
            return "Unused";
        case 0x24:
            return "NEC DOS 3.x";
        case 0x26:
            return "Reserved";
        case 0x27:
            return "PQservice/Windows RE Hidden/MirOS/RouterBOOT partition";
        case 0x2a:
            return "AtheOS File System";
        case 0x2b:
            return "SyllableSecure (SylStor)";
        case 0x31:
            return "Reserved";
        case 0x32:
            return "NOS";
        case 0x33:
        case 0x34:
            return "Reserved";
        case 0x35:
            return "JFS on OS/2 or eCS";
        case 0x36:
            return "Reserved";
        case 0x38:
            return "THEOS ver 3.2 2gb partition";
        case 0x39:
            return "Plan 9/THEOS ver 4 spanned partition";
        case 0x3a:
            return "THEOS ver 4 4gb partition";
        case 0x3b:
            return "THEOS ver 4 extended partition";
        case 0x3c:
            return "PartitionMagic recovery partition";
        case 0x3d:
            return "Hidden NetWare";
        case 0x40:
            return "Venix 80286/PICK";
        case 0x41:
            return "Linux/MINIX (sharing disk with DRDOS)/Personal RISC Boot/PPC PReP Boot";
        case 0x42:
            return "Linux swap (sharing disk with DRDOS)/Windows 2000 dynamic extended partition";
        case 0x43:
            return "Linux native (sharing disk with DRDOS)";
        case 0x44:
            return "GoBack partition";
        case 0x45:
            return "Priam/EUMEL/Elan";
        case 0x46:
        case 0x47:
        case 0x48:
            return "EUMEL/Elan";
        case 0x4a:
            return "ALFS";
        case 0x4c:
            return "Oberon partition";
        case 0x4d:
            return "QNX4.x";
        case 0x4e:
            return "QNX4.x 2nd part";
        case 0x4f:
            return "QNX4.x 3rd part/Oberon";
        case 0x50:
            return "OnTrack Disk Manager/Lynx RTOS/Native Oberon";
        case 0x51:
            return "OnTrack Disk Manager RW/Novell";
        case 0x52:
            return "CP/M/Microport SysC/AT";
        case 0x53:
            return "Disk Manager 6.0 Aux3";
        case 0x54:
            return "Disk Manager 6.0 Dynamic Driver Overlay";
        case 0x55:
            return "EZ-Drive";
        case 0x56:
            return "Golden Bow VFeature Partitioned Volume";
        case 0x57:
            return "DrivePro/VNDI partition";
        case 0x5c:
            return "Priam EDisk";
        case 0x61:
            return "SpeedStor";
        case 0x63:
            return "Unix System V";
        case 0x64:
            return "PC_ARMOUR protected partition/Novell Netware 286";
        case 0x65:
            return "Novell Netware 386, 3.xx or 4.xx";
        case 0x66:
            return "Novell Netware SMS Partition";
        case 0x67:
        case 0x68:
            return "Novell";
        case 0x69:
            return "Novell Netware 5+, Novell Netware NSS Partition";
        case 0x70:
            return "DiscSecure Multi-Boot";
        case 0x71:
            return "Reserved";
        case 0x72:
            return "V7/x86";
        case 0x73:
        case 0x74:
            return "Reserved/Scramdisk";
        case 0x75:
            return "IBM PC/IX";
        case 0x76:
            return "Reserved";
        case 0x77:
            return "M2FS/M2CS/VNDI partition";
        case 0x78:
            return "XOSL FS";
        case 0x7e:
        case 0x7f:
            return "Unused";
        case 0x80:
            return "MINIX until 1.4a";
        case 0x81:
            return "MINIX since 1.4b, early Linux";
        case 0x82:
            return "Prime/Solaris x86/Linux swap";
        case 0x83:
            return "Linux native partition";
        case 0x84:
            return "OS/2 hidden C: drive/Hibernation partition";
        case 0x85:
            return "Linux extended partition";
        case 0x86:
            return "Old Linux RAID partition superblock/FAT16 volume set";
        case 0x87:
            return "NTFS volume set";
        case 0x88:
            return "Linux plaintext partition table";
        case 0x8a:
            return "Linux Kernel Partition (AiR-BOOT)";
        case 0x8b:
            return "Legacy Fault Tolerant FAT32 volume";
        case 0x8c:
            return "Legacy Fault Tolerant FAT32 volume using BIOS extd INT13h";
        case 0x8d:
            return "Free FDISK 0.96+ hidden Primary DOS FAT12 partition";
        case 0x8e:
            return "Linux Logical Volume Manager partition";
        case 0x90:
            return "Free FDISK 0.96+ hidden Primary DOS FAT16 partition";
        case 0x91:
            return "Free FDISK 0.96+ hidden DOS extended partition";
        case 0x92:
            return "Free FDISK 0.96+ hidden Primary DOS large FAT16 partition";
        case 0x93:
            return "Amoeba";
        case 0x94:
            return "Amoeba bad block table";
        case 0x95:
            return "MIT EXOPC native partitions";
        case 0x96:
            return "CHRP ISO-9660 filesystem";
        case 0x97:
            return "Free FDISK 0.96+ hidden Primary DOS FAT32 partitition";
        case 0x98:
            return "Free FDISK 0x97/Datalight ROM-DOS Super-Boot Partition";
        case 0x99:
            return "CDE376 logical drive";
        case 0x9a:
            return "Free FDISK 0.96+ hidden Primary DOS FAT16 partitition (LBA)";
        case 0x9b:
            return "Free FDISK 0.96+ hidden DOS extended partitition (LBA)";
        case 0x9e:
            return "ForthOS partition";
        case 0x9f:
            return "BSD/OS";
        case 0xa0:
        case 0xa1:
            return "Laptop hibernation partition/HP Volume Expansion (SpeedStor)";
        case 0xa3:
        case 0xa4:
            return "HP Volume Expansion (SpeedStor variant)";
        case 0xa5:
            return "BSD/386, 386BSD, NetBSD, FreeBSD";
        case 0xa6:
            return "OpenBSD/HP Volume Expansion (SpeedStor variant)";
        case 0xa7:
            return "NeXTStep";
        case 0xa8:
            return "Mac OS-X";
        case 0xa9:
            return "NetBSD";
        case 0xaa:
            return "Olivetti Fat 12 1.44MB Service Partition";
        case 0xab:
            return "Mac OS-X Boot partition/GO! partition";
        case 0xae:
            return "ShagOS filesystem";
        case 0xaf:
            return "MacOS X HFS";
        case 0xb0:
            return "BootStar Dummy";
        case 0xb1:
            return "HP Volume Expansion (SpeedStor variant)/QNX Neutrino Power-Safe filesystem";
        case 0xb2:
            return "QNX Neutrino Power-Safe filesystem";
        case 0xb3:
            return "HP Volume Expansion (SpeedStor variant)/QNX Neutrino Power-Safe filesystem";
        case 0xb4:
            return "HP Volume Expansion (SpeedStor variant)";
        case 0xb6:
            return "HP Volume Expansion (SpeedStor variant)/Corrupted Windows NT mirror set (master), FAT16 file system";
        case 0xb7:
            return "Corrupted Windows NT mirror set (master), NTFS file system/BSDI BSD/386 filesystem";
        case 0xb8:
            return "BSDI BSD/386 swap partition";
        case 0xbb:
            return "Boot Wizard hidden";
        case 0xbc:
            return "Acronis backup partition";
        case 0xbe:
            return "Solaris 8 boot partition";
        case 0xbf:
            return "New Solaris x86 partition";
        case 0xc0:
            return "CTOS/REAL/32 secure small partition/NTFT Partition/DR-DOS/Novell DOS secured partition";
        case 0xc1:
            return "DRDOS/secured (FAT-12)";
        case 0xc2:
            return "Unused/Hidden Linux";
        case 0xc3:
            return "Hidden Linux swap";
        case 0xc4:
            return "DRDOS/secured (FAT-16, < 32M)";
        case 0xc5:
            return "DRDOS/secured (extended)";
        case 0xc6:
            return "DRDOS/secured (FAT-16, >= 32M)/Windows NT corrupted FAT16 volume/stripe set";
        case 0xc7:
            return "Windows NT corrupted NTFS volume/stripe set/Syrinx boot";
        case 0xc8:
        case 0xc9:
        case 0xca:
            return "Reserved for DR-DOS 8.0+";
        case 0xcb:
            return "DR-DOS 7.04+ secured FAT32 (CHS/";
        case 0xcc:
            return "DR-DOS 7.04+ secured FAT32 (LBA)/";
        case 0xcd:
            return "CTOS Memdump?";
        case 0xce:
            return "DR-DOS 7.04+ FAT16X (LBA)/";
        case 0xcf:
            return "DR-DOS 7.04+ secured EXT DOS (LBA)/";
        case 0xd0:
            return "REAL/32 secure big partition/Multiuser DOS secured partition";
        case 0xd1:
            return "Old Multiuser DOS secured FAT12";
        case 0xd4:
            return "Old Multiuser DOS secured FAT16 <32M";
        case 0xd5:
            return "Old Multiuser DOS secured extended partition";
        case 0xd6:
            return "Old Multiuser DOS secured FAT16 >=32M";
        case 0xd8:
            return "CP/M-86";
        case 0xda:
            return "Non-FS Data/Powercopy Backup";
        case 0xdb:
            return "Digital Research CP/M, Concurrent CP/M, Concurrent DOS/CTOS (Convergent Technologies OS -Unisys)/KDG Telemetry SCPU boot";
        case 0xdd:
            return "Hidden CTOS Memdump?";
        case 0xde:
            return "Dell PowerEdge Server utilities (FAT fs)";
        case 0xdf:
            return "DG/UX virtual disk manager partition/BootIt EMBRM";
        case 0xe0:
            return "Reserved by STMicroelectronics for a filesystem called ST AVFS.";
        case 0xe1:
            return "DOS access or SpeedStor 12-bit FAT extended partition";
        case 0xe3:
            return "DOS R/O or SpeedStor";
        case 0xe4:
            return "SpeedStor 16-bit FAT extended partition < 1024 cyl.";
        case 0xe5:
            return "Tandy MSDOS with logically sectored FAT";
        case 0xe6:
            return "Storage Dimensions SpeedStor";
        case 0xe8:
            return "LUKS";
        case 0xeb:
            return "BeOS BFS";
        case 0xec:
            return "SkyOS SkyFS";
        case 0xed:
            return "Unused";
        case 0xee:
            return "Indication that this legacy MBR is followed by an EFI header";
        case 0xef:
            return "Partition that contains an EFI file system";
        case 0xf0:
            return "Linux/PA-RISC boot loader";
        case 0xf1:
            return "Storage Dimensions SpeedStor";
        case 0xf2:
            return "DOS 3.3+ secondary partition";
        case 0xf3:
            return "Reserved";
        case 0xf4:
            return "SpeedStor large partition/Prologue single-volume partition";
        case 0xf5:
            return "Prologue multi-volume partition";
        case 0xf6:
            return "Storage Dimensions SpeedStor";
        case 0xf7:
            return "DDRdrive Solid State File System";
        case 0xf9:
            return "pCache";
        case 0xfa:
            return "Bochs";
        case 0xfb:
            return "VMware File System partition";
        case 0xfc:
            return "VMware Swap partition";
        case 0xfd:
            return "Linux raid partition with autodetect using persistent superblock";
        case 0xfe:
            return "/LANstep/Windows NT Disk Administrator hidden partition/Linux Logical Volume Manager partition (old)";
        case 0xff:
            return "Xenix Bad Block Table";
        default:
            return "Unknown partition type";
    }
}
