# Author: Jacques
# Date: 09/10/2021
# Time: 2:11 PM
from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, KeyboardSwitchLayout
from custom.keyboard_switch_and_keymap_layout.parser.keymap_c_parser import parse_keymap_c


def main():
    switch_row1 = KeyboardSwitchRow(12)
    switch_row2 = KeyboardSwitchRow(12)
    switch_row3 = KeyboardSwitchRow(14)
    switch_row4 = KeyboardSwitchRow(7)
    cisne_switch_layout = KeyboardSwitchLayout([switch_row1, switch_row2, switch_row3, switch_row4])
    cisne_keymap_filepath = '../keyboards/cisne/keymaps/Jacques_Mathieu/keymap.c'
    my_layout = parse_keymap_c(cisne_keymap_filepath, cisne_switch_layout, layout_type='LAYOUT_1')
    print(my_layout.__str__())


if __name__ == '__main__':
    main()
