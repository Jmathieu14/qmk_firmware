# Author: Jacques
# Date: 09/10/2021
# Time: 4:32 PM
import os.path as osp
import re

from custom.keyboard_switch_and_keymap_layout.keyboard_switch_and_keymap_layout import KeyboardSwitchLayout, KeyboardKeymap, KeyboardLayout

KEYMAPS_START_MATCHER = re.compile('keymaps\[]\[MATRIX_ROWS]\[MATRIX_COLS]\s*=\s*{')
KEYMAP_LAYER_MATCHER = re.compile('\[\w+]\s*=\s*LAYOUT\((\w|\s|,)+\),*')


def does_file_exist(path):
    if not path.__str__().find(osp.curdir.__str__()):
        path = osp.abspath(osp.curdir + "\\" + path)
    return osp.exists(path)


def abs_path(path):
    if not path.__str__().find(osp.curdir.__str__()):
        path = osp.abspath(osp.curdir + "\\" + path)
    return path


def remove_all_whitespace(s: str):
    s = s.strip()
    s = s.replace('\n', '')
    s = s.replace('\t', '')
    s = s.replace(' ', '')
    return s


def remove_c_comments(s: str):
    multiline_comment_matcher = re.compile('/\*(\w|\s|\*)*\*/')
    multiline_comments = []
    for match in multiline_comment_matcher.finditer(s):
        multiline_comments.append(s[match.start():match.end()])
    for comment in multiline_comments:
        s = s.replace(comment, '')
    single_comment_matcher = re.compile('//.*')
    comments = []
    for match in single_comment_matcher.finditer(s):
        comments.append(s[match.start():match.end()])
    for comment in comments:
        s = s.replace(comment, '')
    return s


def parse_keymap_c(filepath: str, switch_layout: KeyboardSwitchLayout):
    if does_file_exist(filepath):
        with open(abs_path(filepath), 'r') as my_file:
            raw_content = my_file.read()
        cleaned_content = remove_c_comments(raw_content)
        keymaps_match = KEYMAPS_START_MATCHER.search(cleaned_content)
        if keymaps_match is not None:
            end_of_keymaps_start = keymaps_match.end()
            cleaned_content = cleaned_content[end_of_keymaps_start:]
            cleaned_content = cleaned_content.replace('\\', '')
            layers = [layer.group() for layer in KEYMAP_LAYER_MATCHER.finditer(cleaned_content)]
            keymap_layers = []
            for layer_index in range(0, layers.__len__()):
                layer = layers[layer_index]
                layer_name_matcher = re.compile('\[(\w|\s)+]')
                layer_start_matcher = re.compile('\[(\w|\s)+]\s*=\s*\w+\(')
                layer_name = layer_name_matcher.search(layer)
                layer_name = layer_name.group().strip()
                layer_name = layer_name.replace('[', '').replace(']', '')
                layer_start = layer_start_matcher.search(layer)
                key_codes = layer[layer_start.end():]
                if key_codes[-1:] == ',':
                    key_codes = key_codes[:-2]
                else:
                    key_codes = key_codes[:-1]
                key_codes = remove_all_whitespace(key_codes)
                key_codes = key_codes.split(',')
                switch_layer = KeyboardKeymap(layer_name, key_codes)
                keymap_layers.append(switch_layer)
            return KeyboardLayout(switch_layout, keymap_layers)
    else:
        raise FileNotFoundError('Could not find {0}'.format(filepath))


def main():
    pass


if __name__ == '__main__':
    main()
