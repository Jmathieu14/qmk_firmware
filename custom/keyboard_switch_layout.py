class KeyboardSwitchRow:
    def __init__(self, switch_count):
        self._validate_count()
        self.switch_count = switch_count

    def _validate_count(self):
        if self.switch_count <= 0:
            raise ValueError()

    def __str__(self):
        return "row switch count: {0}".format(self.switch_count)


class KeyboardSwitchLayout:
    def __init__(self, rows):
        self.rows = rows

    def __str__(self):
        rows_string = ""
        for row in self.rows:
            rows_string = "{0}\n{1}".format(rows_string, row)
        return rows_string


class KeyboardLayer:
    def __init__(self, name: str, key_codes: list[str]):
        self.name = name
        self.key_codes = key_codes


class KeyboardLayout:
    def __init__(self, switch_layout: KeyboardSwitchLayout, layers: list[KeyboardLayer]):
        self.switch_layout = switch_layout
        self.layers = layers
        self._validate_input()

    def _validate_input(self):
        pass


# row_one = KeyboardSwitchRow(4)
# row_two = KeyboardSwitchRow(5)
#
# demo_switch_layout = KeyboardSwitchLayout([row_one, row_two])
#
# print(demo_switch_layout)
