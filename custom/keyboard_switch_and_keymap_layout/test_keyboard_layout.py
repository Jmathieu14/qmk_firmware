import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, \
    KeyboardSwitchLayout, KeyboardKeymap, KeyboardLayout


class TestKeyboardLayout(unittest.TestCase):
    def test_init_with_invalid_input__raises_error(self):
        nine_key_switch_layout = KeyboardSwitchLayout([
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3)
        ])
        eight_key_layer_list = [
            "KC_8", "KC_7", "KC_6",
            "KC_5", "KC_4", "KC_3",
            "KC_2", "KC_1"
        ]
        eight_key_layer = KeyboardKeymap("layer_1", eight_key_layer_list)
        with self.assertRaises(ValueError) as error:
            KeyboardLayout(nine_key_switch_layout, [eight_key_layer])
        self.assertEqual(error.exception.__str__(), "Layer layer_1 has 8 keycodes on a board with 9 switches")

    def test_init_with_valid_input__does_not_raise_error(self):
        nine_key_switch_layout = KeyboardSwitchLayout([
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3)
        ])
        nine_key_layer_list = [
            "KC_8", "KC_7", "KC_6",
            "KC_5", "KC_4", "KC_3",
            "KC_2", "KC_1", "KC_0"
        ]
        nine_key_layer = KeyboardKeymap("layer_1", nine_key_layer_list)
        nine_key_keyboard_layout = KeyboardLayout(nine_key_switch_layout, [nine_key_layer])
        self.assertIsNotNone(nine_key_keyboard_layout)


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeyboardLayout)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
