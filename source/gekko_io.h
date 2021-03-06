/*
* gekko_io.h - Platform specifics for device io.
*
 * Copyright (c) 2009 Rhys "Shareese" Koedijk
 * Copyright (c) 2010 Dimok
*
* This program/include file is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as published
* by the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program/include file is distributed in the hope that it will be
* useful, but WITHOUT ANY WARRANTY; without even the implied warranty
* of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software Foundation,
* Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _GEKKO_IO_H
#define _GEKKO_IO_H

#ifndef XENON
#include <ogc/disc_io.h>
#include <gccore.h>
#else
#include <xetypes.h>
#include <diskio/disc_io.h>
#endif
#include "disc_cache.h"
#include "ext2fs.h"

#define MAX_SECTOR_SIZE     (4096)

/**
 * gekko_fd - Gekko device driver descriptor
 */
typedef struct _gekko_fd {
    const DISC_INTERFACE* interface;        /* Device disc interface */
    sec_t startSector;                      /* LBA of partition start */
    sec_t sectorCount;                      /* Total number of sectors in partition */
    u16 sectorSize;                         /* Device sector size (in bytes) */
	int	flags;
	int	access_time;
	ext2_loff_t offset;
	struct struct_io_stats io_stats;
    CACHE *cache;                           /* Cache */
    u32 cachePageCount;                     /* The number of pages in the cache */
    u32 cachePageSize;                      /* The number of sectors per cache page */
} gekko_fd;


/* Gekko device driver i/o operations */
extern io_manager gekko_io_manager;

#endif /* _GEKKO_IO_H */
