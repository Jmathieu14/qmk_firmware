# Author: Jacques
# Date: 09/10/2021
# Time: 2:11 PM
from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, KeyboardSwitchLayout
from custom.keyboard_switch_and_keymap_layout.parser.keymap_c_parser import parse_keymap_c


def main():
    switch_row1 = KeyboardSwitchRow(13)
    switch_row2 = KeyboardSwitchRow(12)
    switch_row3 = KeyboardSwitchRow(13)
    switch_row4 = KeyboardSwitchRow(8)
    prime_e_switch_layout = KeyboardSwitchLayout([switch_row1, switch_row2, switch_row3, switch_row4])
    prime_e_keymap_filepath = '../keyboards/primekb/prime_e/keymaps/jm_game_colemak_modified/keymap.c'
    my_layout = parse_keymap_c(prime_e_keymap_filepath, prime_e_switch_layout)
    print(my_layout.__str__())


if __name__ == '__main__':
    main()
