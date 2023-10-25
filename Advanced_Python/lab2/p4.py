import random

def word_len(word : str):
    return len(word.rstrip(",.!?\"\'"))

def simplify_sentence(text : str, dl_word, word_number):
    if len(text) == 0 or word_number <= 0:
        return ""
    words = list(filter(lambda word: word_len(word) <= dl_word, text.split()))
    if word_number >= len(words):
        return " ".join(words).capitalize() + '.'
    random_indices = random.sample(range(0, len(words)), word_number)
    result = " ".join([words[i] for i in sorted(random_indices)])
    if result[-1] not in ".!?":
        result += '.'
    return result.capitalize()

text = "Periclinal division of fusiform initials \
the cambium is characterized by a division wall initiated in the maximum plane."

print(simplify_sentence(text, 10, 5))


