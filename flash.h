/*
 * Copyright (C) Marek Lindner
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of version 3 of the GNU General Public
 * License as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA
 *
 * SPDX-License-Identifier: GPL-3.0+
 * License-Filename: LICENSES/preferred/GPL-3.0
 */

#ifndef __AP51_FLASH_FLASH_H__
#define __AP51_FLASH_FLASH_H__

#include <stdint.h>

#include "types.h"

#if defined(CLEAR_SCREEN)
extern int num_nodes_flashed;
#endif

struct node *node_list_get(const uint8_t *mac_addr);
void our_mac_set(struct node *node);
int flash_start(const char *iface);

static inline void list_prepend(struct list **list, struct list *list_item)
{
	if (!(*list)) {
		*list = list_item;
		return;
	}

	list_item->next = (*list)->next;
	(*list)->next = list_item;
}

#endif /* __AP51_FLASH_FLASH_H__ */
