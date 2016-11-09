/*
 * Copyright (C) 2015 Adrien Devresse <adrien.devresse@epfl.ch>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */
#ifndef X3D_EXPORTER_H
#define X3D_EXPORTER_H


#include <string>
#include <fstream>
#include <functional>

#include <morpho/morpho_h5_v1.hpp>

namespace morpho{

class x3d_exporter
{
public:
    x3d_exporter(const std::string & morphology_filename, const std::string & mesh_filename);


    void export_to_sphere();

private:
    morpho::h5_v1::morpho_reader reader;
    std::ofstream x3d_stream;
    std::string dest_filename;


    void envelop_header_and_footer(const std::function<void (void)> & fcontent);

    void html_viewer();

    void export_all_points();
};


}

#endif // X3D_EXPORTER_H
