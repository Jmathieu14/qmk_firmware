# Author: Jacques
# Date: 09/10/2021
# Time: 4:32 PM
import os.path as osp
import re

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchLayout, KeyboardKeymap, KeyboardLayout

KEYMAPS_START_MATCHER = re.compile('keymaps\[]\[MATRIX_ROWS]\[MATRIX_COLS]\s*=\s*{')
KEYMAP_LAYER_MATCHER = re.compile('\[\w+]\s*=\s*LAYOUT\((\w|\s|,)+\)')


def does_file_exist(path):
    if not path.__str__().find(osp.curdir.__str__()):
        path = osp.abspath(osp.curdir + "\\" + path)
    return osp.exists(path)


def abs_path(path):
    if not path.__str__().find(osp.curdir.__str__()):
        path = osp.abspath(osp.curdir + "\\" + path)
    return path


def parse_keymap_c(filepath: str, switch_layout: KeyboardSwitchLayout):
    if does_file_exist(filepath):
        with open(abs_path(filepath), 'r') as my_file:
            raw_content = my_file.read()
        print(raw_content)
        keymaps_match = KEYMAPS_START_MATCHER.search(raw_content)
        if keymaps_match is not None:
            end_of_keymaps_start = keymaps_match.end()
            raw_content = raw_content[end_of_keymaps_start:]
            raw_content = raw_content.replace('\\', '')
            layers = KEYMAP_LAYER_MATCHER.search(raw_content)
            keymap_layers = []
            for layer in layers.groups():
                switch_layer = KeyboardKeymap('test', ['', '', '', ''])
                keymap_layers.append(switch_layer)
            return KeyboardLayout(switch_layout, keymap_layers)
    else:
        raise FileNotFoundError('Could not find {0}'.format(filepath))


def main():
    pass


if __name__ == '__main__':
    main()
