/*
 * Remmina - The GTK+ Remote Desktop Client
 * Copyright (C) 2014-2022 Antenore Gatta, Giovanni Panozzo
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301, USA.
 *
 *  In addition, as a special exception, the copyright holders give
 *  permission to link the code of portions of this program with the
 *  OpenSSL library under certain conditions as described in each
 *  individual source file, and distribute linked combinations
 *  including the two.
 *  You must obey the GNU General Public License in all respects
 *  for all of the code used other than OpenSSL. *  If you modify
 *  file(s) with this exception, you may extend this exception to your
 *  version of the file(s), but you are not obligated to do so. *  If you
 *  do not wish to do so, delete this exception statement from your
 *  version. *  If you delete this exception statement from all source
 *  files in the program, then also delete it here.
 *
 */

/**
 * @file 	remmina_plugin_python.h
 *
 * @brief	Declares the interface between the Python plugin implementation and Remmina covering the initialization of
 * 			the implementation and the load function, that allows Remmina to load plugins into the application.
 *
 * @details When Remmina discovers Python scripts in the plugin root folder the plugin manager passes the path to the
 * 			Python plugin loader. There it gets executed and the plugin classes get mapped to "real" Remmina plugin
 * 			instances.
 *
 * 			For the communication between Remmina and Python the python module called 'remmina' is initialized and
 * 			loaded into the environment of the plugin script (@see remmina_plugin_python_module.c).
 *
 * 			@see http://www.remmina.org/wp for more information.
 */

#pragma once

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// I N C L U D E
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "remmina/plugin.h"

G_BEGIN_DECLS

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// A P I
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief 	Initializes the Python plugin loaders.
 * @details This does not load any plugins but initializes the implementation (e.g. globals and the Python engine).
 */
void remmina_plugin_python_init(void);

/**
 * @brief 	Loads a plugin from the Remmina plugin folder with the given name.
 *
 * @param   service     The instance of the service providing an API between Remmina and its plugins.
 * @param   filename    The filename of the plugin to load.
 *
 * @return  TRUE on success, FALSE otherwise.
 */
gboolean remmina_plugin_python_load(RemminaPluginService* service, const gchar* filename);

G_END_DECLS
