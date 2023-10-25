def word2num(word):
    word_to_num = {
        'zero': 0, 'one': 1, 'two': 2, 'three': 3, 'four': 4,
        'five': 5, 'six': 6, 'seven': 7, 'eight': 8, 'nine': 9,
        'ten': 10, 'eleven': 11, 'twelve': 12, 'thirteen': 13, 'fourteen': 14,
        'fifteen': 15, 'sixteen': 16, 'seventeen': 17, 'eighteen': 18, 'nineteen': 19,
        'twenty': 20, 'thirty': 30, 'forty': 40, 'fifty': 50, 'sixty': 60,
        'seventy': 70, 'eighty': 80, 'ninety': 90,
        'hundred': 100, 'thousand': 1000,
    }
    words = word.split()
    total = 0
    current_num = 0
    for w in words:
        if w in word_to_num:
            num = word_to_num[w]
            if num == 100:
                current_num *= num
            elif num == 1000:
                current_num *= num
                total += current_num
                current_num = 0
            else:
                current_num += num
        elif w == 'and':
            continue
        else:
            compound_parts = w.split('-')
            if len(compound_parts) > 1:
                compound_total = 0
                for part in compound_parts:
                    if part in word_to_num:
                        compound_total += word_to_num[part]
                    else:
                        raise ValueError(f"Invalid word: {part} in {w}")
                current_num += compound_total
            else:
                raise ValueError(f"Invalid word: {w}")
    num = int(total + current_num)
    return [word,num]

words_list_1 = ['one hundred and twenty-three', 'eight hundred and fifteen', 'thirty thousand two hundred']
words_list_2 = ['fourteen thousand and three hundred thirty two','nine hundred and twelve', 'nine hundred and ninety nine',
                'three hundred thousand']

w_n_1 = [word2num(i) for i in words_list_1]
print(sorted(w_n_1, key=lambda x: x[1]))

w_n_2 = [word2num(i) for i in words_list_2]
print(sorted(w_n_2, key=lambda x: x[1]))



