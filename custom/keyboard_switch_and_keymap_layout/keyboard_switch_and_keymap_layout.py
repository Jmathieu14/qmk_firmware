class KeyboardSwitchRow:
    def __init__(self, switch_count):
        self.switch_count = switch_count
        self._validate_count()

    def _validate_count(self):
        if self.switch_count <= 0:
            raise ValueError("Invalid switch count of {0} provided".format(self.switch_count))

    def __str__(self):
        return "row switch count: {0}".format(self.switch_count)


class KeyboardSwitchLayout:
    def __init__(self, rows: list[KeyboardSwitchRow]):
        self.rows = rows

    def total_switch_count(self):
        total_count = 0
        for row in self.rows:
            total_count = total_count + row.switch_count
        return total_count

    def __str__(self):
        rows_string = ""
        for row in self.rows:
            rows_string = "{0}\n{1}".format(rows_string, row)
        return rows_string


class KeyboardKeymap:
    def __init__(self, name: str, key_codes: list[str]):
        self.name = name
        self.key_codes = key_codes

    def get_min_keycode_length(self):
        min_length = 0
        for key_code in self.key_codes:
            if key_code.__len__() > min_length:
                min_length = key_code.__len__()
        return min_length


class KeyboardLayout:
    def __init__(self, switch_layout: KeyboardSwitchLayout, keymap_layers: list[KeyboardKeymap]):
        self.switch_layout = switch_layout
        self.keymap_layers = keymap_layers
        self._validate_input()

    def _validate_input(self):
        for layer in self.keymap_layers:
            if not layer.key_codes.__len__() == self.switch_layout.total_switch_count():
                raise ValueError("Layer {0} has {1} keycodes on a board with {2} switches"
                                 .format(layer.name, layer.key_codes.__len__(), self.switch_layout.total_switch_count()))

    def __str__(self):
        pass
