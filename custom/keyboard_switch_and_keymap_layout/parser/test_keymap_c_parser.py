# TODO: import simple_keymap and make sure you get the expected layers

import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, KeyboardSwitchLayout, KeyboardLayout, KeyboardKeymap
from custom.keyboard_switch_and_keymap_layout.parser.keymap_c_parser import parse_keymap_c

switch_row_len_2 = KeyboardSwitchRow(2)
simple_switch_layout = KeyboardSwitchLayout([switch_row_len_2, switch_row_len_2])


class TestKeymapCParser(unittest.TestCase):

    def test_import_simple_keymap__has_expected_number_of_layers(self):
        actual_keyboard_layout = parse_keymap_c('./assets/simple_keymap.c', simple_switch_layout)
        self.assertEqual(1, actual_keyboard_layout.keymap_layers.__len__())

    def test_import_simple_keymap__returns_expected_keyboard_layout_object(self):
        actual_keyboard_layout = parse_keymap_c('./assets/simple_keymap.c', simple_switch_layout)
        expected_keyboard_layout = KeyboardLayout(simple_switch_layout, [
            KeyboardKeymap('0', ['KC_1', 'KC_2', 'KC_3', 'KC_4'])
        ])
        self.assertEqual(expected_keyboard_layout, actual_keyboard_layout)

    def test_import_non_existent_file__raises_error(self):
        with self.assertRaises(FileNotFoundError):
            parse_keymap_c('./wah/no_file.c', simple_switch_layout)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeymapCParser)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()

