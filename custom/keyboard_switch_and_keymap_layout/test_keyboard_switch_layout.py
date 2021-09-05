import unittest

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchRow, \
    KeyboardSwitchLayout


class TestKeyboardSwitchLayout(unittest.TestCase):
    def test_total_switch_count_returns_9(self):
        nine_key_switch_layout = KeyboardSwitchLayout([
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3),
            KeyboardSwitchRow(3)
        ])
        self.assertEqual(9, nine_key_switch_layout.total_switch_count())

    def test_total_switch_count_returns_20(self):
        twenty_key_switch_layout = KeyboardSwitchLayout([
            KeyboardSwitchRow(1),
            KeyboardSwitchRow(19),
        ])
        self.assertEqual(20, twenty_key_switch_layout.total_switch_count())


def get_suite():
    return unittest.TestLoader().loadTestsFromTestCase(TestKeyboardSwitchLayout)


def main():
    unittest.TextTestRunner().run(get_suite())


if __name__ == '__main__':
    unittest.main()
