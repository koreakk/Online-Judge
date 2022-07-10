import re

def solution(new_id: str) -> str:
    # level 1
    new_id = new_id.lower()

    # level 2
    new_id = re.sub(r'[^a-z0-9_.\-]', '', new_id)

    # level 3
    new_id = re.sub(r'\.+', '.', new_id)

    # level 4
    if new_id != '' and new_id[0] == '.':
        new_id = new_id[1:]
    if new_id != '' and new_id[-1] == '.':
        new_id = new_id[:-1]

    # level 5
    if new_id == '':
        new_id = 'a'

    # level 6
    if len(new_id) >= 16:
        new_id = new_id[:15]

        if new_id[-1] == '.':
            new_id = new_id[:-1]

    # level 7
    if len(new_id) <= 2:
        new_id += new_id[-1] * (3 - len(new_id))

    return new_id