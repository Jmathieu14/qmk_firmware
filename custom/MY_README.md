# Initial Setup
1. [CLI Development Environment](../docs/cli_development.md)
2. Run `make git-submodule` in msys64 at project root
3. Run `qmk setup`
    - If you come across the following error, simply run the command `pacman -S mingw-w64-x86_64-hidapi -y` and then `qmk setup`
    - ``` python
      Error: %s: %s ('ImportError', ImportError('Unable to load any of the following libraries:libhidapi-hidraw.so libhidapi-hidraw.so.0 libhidapi-libusb.so libhidapi-libusb.so.0 libhidapi-iohidmanager.so libhidapi-iohidmanager.so.0 libhidapi.dylib hidapi.dll libhidapi-0.dll'))
4. If there are still issues running the program, try `util/qmk_install.sh`
5. If you come across an error that states it is missing certain drivers, run `qmk clean`

    a. More information on that can be found here: https://www.reddit.com/r/olkb/comments/pdk39w/qmk_breaking_changes_2021_august_28/
6. Furthermore, make sure MSYS or QMK MSYS are on the latest available version
    
# Keymap.json to Keymap.hex! (Windows OS)
_Note, all `qmk` commands must be run in the MSYS2 64bit Terminal_
1. First run `qmk new-keymap -kb <keyboard_name>` so that qmk creates the new keymap folder for the specified board.

    a. It will then prompt you to enter the name for the keymap.
    
2. Now open 'keymap_json_to_c_layers.py' and make sure the path in the main method points to the qmk json keymap exported 
from https://config.qmk.fm/.
    
3. Next, navigate to the folder that contains this new keymap.

4. Run `python keymap_json_to_c_layers.py -f <json_filepath>` and paste the output into the keymap.c file for your new layout.

5. Open `QMK MSYS` and navigate to this qmk_firmware repo

6. Type `export PYTHONUTF8=1` into the cli to ensure python and Windows get along

7. Finally, run `qmk compile -kb <keyboard_name> -km <keymap>`. The hex file will be exported to `/.build`.
    
    a. If you have any `ANY()` functions in your keymap.c file, you will have to delete that function. I.e. 
    `ANY(LSFT(LCTL(KC_GRV)))` will become `LSFT(LCTL(KC_GRV))`. _It will still work as expected!_
    
# Flashing the firmware
1. Open qmk toolbox and select the hex file you just made!

2. Select `atmega32a` under MCU's if using a jj40 or other board that has the same processor

3. Reset your board into flashing mode. If your jj40 still has the default firmware installed, unplug the device. 
Re-plug the device while holding down the top right key.

4. Flash the firmware onto your device!

### Specific Commands
> ``` 
> cd bin
> python3 ./qmk new-keymap -kb jj40
> 
> python custom/keymap_json_to_c_layers.py
> 
> cd bin
> python3 ./qmk compile -kb jj40 -km <keymap>
> 
> C:\\users\\jmath\\appdata\\local\\programs\\python\\python38\\python.exe or python3 will work
> ```

### Custom keymaps
``` python
# Keymap Name: jm_split_qwerty
$ jm_split_qwerty keymap directory created in: C:/msys64/home/jmath/git/qmk_firmware/keyboards/jj40/keymaps/jm_split_qwerty
  Compile a firmware with your new keymap by typing:

        qmk compile -kb jj40 -km jm_split_qwerty

# Keymap Name: jm_game (for Prime E)
INFO jm_game keymap directory created in: C:/msys64/home/jmath/git/qmk_firmware/keyboards/primekb/prime_e/keymaps/jm_game
INFO Compile a firmware with your new keymap by typing:

        qmk compile -kb primekb/prime_e/rgb -km jm_game
        
# qmk new-keymap -kb primekb/prime_e/rgb
Keymap Name: jm_game_colemak_modified
Ψ jm_game_colemak_modified keymap directory created in: C:/Users/User/Local_Documents/git/qmk_firmware/keyboards/primekb/prime_e/keymaps/jm_game_colemak_modified
Ψ Compile a firmware with your new keymap by typing:

        qmk compile -kb primekb/prime_e/rgb -km jm_game_colemak_modified
        
# Keymap Name: jm_game (for Mercutio)
# Ψ jm_game keymap directory created in: C:/Users/User/Local_Documents/git/qmk_firmware/keyboards/mechwild/mercutio/keymaps/jm_game
# Ψ Compile a firmware with your new keymap by typing:

        qmk compile -kb mechwild/mercutio -km jm_game
```

##### Other Resources
- https://www.tutorialspoint.com/python/python_command_line_arguments.htm
