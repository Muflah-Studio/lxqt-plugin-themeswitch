# LXQt Plugin Lorem Ipsum

## Build instruction

Build dependencies:
```
lxqt-build-tools ...
```

```sh
mkdir build
cd build
cmake ..
sudo make install
```

For testing or development purpose, change cmake execution with:
```sh
cmake -DCMAKE_INSTALL_PREFIX=/home/youruser/.local -DCMAKE_INSTALL_LIBDIR=/home/youruser/.local/lib -DCMAKE_BUILD_TYPE=Debug ..
```

> Make sure `~/.local/lib` exists, or even `~/.local/lib/<arch-id>` where `arch-id` is _Multiarch Architecture Specifiers_ like `x86_64_linux_gnu`.

Make a symlink for compiled plugin to the global LXQt plugins.
```
sudo ln -s /home/youruser/.local/lib/lxqt-panel/libloremipsum.so /usr/lib/x86_64_linux_gnu/lxqt-panel/
```

Run `lxqt-panel` from terminal to debug using config file contains:
```
[panel1]
position=Right
```

Save to `panel.conf` and run with:
```sh
lxqt-panel --configfile panel.conf
```

## License

<one line to give the program's name and a brief idea of what it does.>
Copyright (C) <year>  <name of author>

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
