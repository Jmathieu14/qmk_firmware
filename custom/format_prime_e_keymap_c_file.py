# Author: Jacques
# Date: 09/10/2021
# Time: 2:11 PM
from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, KeyboardSwitchLayout


def string_to_keyboard_layout_object(prime_e_switch_layout: KeyboardSwitchLayout):
    return "k"


def main():
    switch_row1 = KeyboardSwitchRow(13)
    switch_row2 = KeyboardSwitchRow(12)
    switch_row3 = KeyboardSwitchRow(13)
    switch_row4 = KeyboardSwitchRow(8)
    prime_e_switch_layout = KeyboardSwitchLayout([switch_row1, switch_row2, switch_row3, switch_row4])
    my_layout = string_to_keyboard_layout_object(prime_e_switch_layout)
    print(my_layout.__str__())


if __name__ == '__main__':
    main()
