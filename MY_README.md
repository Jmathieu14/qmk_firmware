# Instructions (Windows OS)
_Note, all `qmk` commands must be run in the MSYS2 64bit Terminal_
1. First run `qmk new-keymap -kb <keyboard_name>` so that qmk creates the new keymap folder for the specified board.
    a. It will then prompt you to enter the name for the keymap.
    
2. Now open 'keymap_json_to_c_layers.py' and make sure the path in the main method points to the qmk json keymap exported 
from https://config.qmk.fm/.
    
3. Next, navigate to the folder that contains this new keymap.

4. Run `python keymap_json_to_c_layers.py` and paste the output into the keymap.c file for your new layout.

5. Finally, run `qmk compile -kb <keyboard_name> -km <keymap>`. The hex file will be exported to `/.build`.

### Specific Commands
> ``` 
> C:\\users\\jmath\\appdata\\local\\programs\\python\\python38\\python.exe ./qmk new-keymap -kb jj40
> 
> python keymap_json_to_c_layers.py
> 
> C:\\users\\jmath\\appdata\\local\\programs\\python\\python38\\python.exe ./qmk compile -kb jj40 -km <keymap>
> ```

### Custom keymaps for jj40
``` python
# Keymap Name: jm_custom_mk2
$ jm_custom_mk2 keymap directory created in: C:\msys64\home\jmath\git\qmk_firmware\keyboards\jj40\keymaps\jm_custom_mk2
  Compile a firmware with your new keymap by typing:

        qmk compile -kb jj40 -km jm_custom_mk2

# Keymap Name: jm_custom_split
$ jm_custom_split keymap directory created in: C:\msys64\home\jmath\git\qmk_firmware\keyboards\jj40\keymaps\jm_custom_split←[0m
 Compile a firmware with your new keymap by typing:

        qmk compile -kb jj40 -km jm_custom_split

# Keymap Name: jm_custom_split_v2
$ jm_custom_split_v2 keymap directory created in: C:/msys64/home/jmath/git/qmk_firmware/keyboards/jj40/keymaps/jm_custom_split_v2
 Compile a firmware with your new keymap by typing:

        qmk compile -kb jj40 -km jm_custom_split_v2
```
