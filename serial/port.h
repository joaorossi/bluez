/*
 *
 *  BlueZ - Bluetooth protocol stack for Linux
 *
 *  Copyright (C) 2004-2007  Marcel Holtmann <marcel@holtmann.org>
 *
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

typedef void (*open_notify_t) (int fd, int err, void *data);
typedef void (*udata_free_t) (void *data);

int port_add_listener(DBusConnection *conn, int id, int fd,
			const char *name, const char *owner);

int port_remove_listener(const char *owner, const char *name);

int port_register(DBusConnection *conn, int id, const char *name, char *ppath);

int port_unregister(const char *path);

const char *port_get_owner(DBusConnection *conn, int16_t id);

int port_open(const char *dev, open_notify_t notify,
			void *data, udata_free_t ufree);
