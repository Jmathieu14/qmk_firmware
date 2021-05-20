# Initial Setup
1. [CLI Development Environment](docs/cli_development.md)
2. Run `make git-submodule` in msys64 at project root

# Keymap.json to Keymap.hex! (Windows OS)
_Note, all `qmk` commands must be run in the MSYS2 64bit Terminal_
1. First run `qmk new-keymap -kb <keyboard_name>` so that qmk creates the new keymap folder for the specified board.
    a. It will then prompt you to enter the name for the keymap.
    
2. Now open 'keymap_json_to_c_layers.py' and make sure the path in the main method points to the qmk json keymap exported 
from https://config.qmk.fm/.
    
3. Next, navigate to the folder that contains this new keymap.

4. Run `python keymap_json_to_c_layers.py` and paste the output into the keymap.c file for your new layout.

5. Finally, run `qmk compile -kb <keyboard_name> -km <keymap>`. The hex file will be exported to `/.build`.
    
    a. If you have any `ANY()` functions in your keymap.c file, you will have to delete that function. I.e. 
    `ANY(LSFT(LCTL(KC_GRV)))` will become `LSFT(LCTL(KC_GRV))`. _It will still work as expected!_

### Specific Commands
> ``` 
> cd bin
> python3 ./qmk new-keymap -kb jj40
> 
> python keymap_json_to_c_layers.py
> 
> cd bin
> python3 ./qmk compile -kb jj40 -km <keymap>
> 
> C:\\users\\jmath\\appdata\\local\\programs\\python\\python38\\python.exe or python3 will work
> ```

### Custom keymaps for jj40
``` python
# Keymap Name: jm_split_qwerty
$ jm_split_qwerty keymap directory created in: C:/msys64/home/jmath/git/qmk_firmware/keyboards/jj40/keymaps/jm_split_qwerty
  Compile a firmware with your new keymap by typing:

        qmk compile -kb jj40 -km jm_split_qwerty

```
