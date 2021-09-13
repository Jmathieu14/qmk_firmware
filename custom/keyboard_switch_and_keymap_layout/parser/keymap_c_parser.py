# Author: Jacques
# Date: 09/10/2021
# Time: 4:32 PM
import os.path as osp
from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchLayout


def does_file_exist(path):
    if not path.__str__().find(osp.curdir.__str__()):
        path = osp.abspath(osp.curdir + "\\" + path)
    return osp.exists(path)


def parse_keymap_c(filepath: str, switch_layout: KeyboardSwitchLayout):
    if does_file_exist(filepath):
        pass
    else:
        raise FileNotFoundError('Could not find {0}'.format(filepath))


def main():
    print("To be implemented")


if __name__ == '__main__':
    main()
