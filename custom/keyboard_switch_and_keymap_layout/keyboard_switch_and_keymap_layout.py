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

    def min_keycode_length_for_column(self, column_index, layer: KeyboardKeymap):
        rows = self.switch_layout.rows
        min_length = layer.key_codes[0].__len__()
        switch_index = column_index
        for i in range(0, rows.__len__()):
            max_index = rows[i].switch_count - 1
            if column_index <= max_index:
                keycode = layer.key_codes[switch_index]
                min_length = max(min_length, keycode.__len__())
            switch_index = switch_index + max_index + 1
        return min_length

    def layer_as_string(self, layer_index: int):
        layer: KeyboardKeymap = self.keymap_layers[layer_index]
        min_length = layer.get_min_keycode_length()
        string_to_return = '\n[{0}] = LAYOUT( \\\n'.format(layer.name)
        num_rows = self.switch_layout.rows.__len__()
        rows = self.switch_layout.rows
        key_code_index = 0
        for row_index in range(0, num_rows):
            for switch_index in range(0, rows[row_index].switch_count):
                min_keycode_length = self.min_keycode_length_for_column(switch_index, layer)
                my_keycode = layer.key_codes[key_code_index]
                if row_index == num_rows - 1 and switch_index == rows[row_index].switch_count - 1:
                    string_to_return = '{0}{1})'.format(string_to_return, my_keycode)
                elif switch_index == rows[row_index].switch_count - 1:
                    string_to_return = '{0}{1}, \\\n'.format(string_to_return, my_keycode)
                else:
                    string_to_return = '{0}{1}, '.format(string_to_return, my_keycode)
                key_code_index = key_code_index + 1
        return string_to_return

    def __str__(self):
        pass
