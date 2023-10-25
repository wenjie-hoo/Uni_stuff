import urllib.request
import re

def calc_stats(url, stats=None):
    if stats is None:
        stats = {}
    try:
        text = urllib.request.urlopen(url).read().decode('utf-8')
        text = ''.join(c.lower() for c in text if c.isalnum())
        text = re.sub(r'[0-9]+', '', text)
        for char in text:
            if char in stats:
                stats[char] += 1
            else:
                stats[char] = 1
        total_char = len(text)
        for char in stats:
            stats[char] /= total_char
    except Exception as e:
        print(f"Error: {e}")
    return stats

def guess_lang(langs, url):
    input_stats = calc_stats(url)
    min_diff = 1
    detected_lang = ''
    for lang_name, lang_stats, _ in langs:
        if len(lang_stats) == 0:
            continue
        diff = 0
        for char, frequency in lang_stats.items():
            if char in input_stats:
                diff += abs(frequency - input_stats[char])
            else:
                diff += frequency
        average_diff = diff / len(lang_stats)
        if average_diff < min_diff:
            min_diff = average_diff
            detected_lang = lang_name
    return detected_lang

english_sources = [
    'https://www.gutenberg.org/cache/epub/71828/pg71828-images.html',
    'https://www.gutenberg.org/cache/epub/71827/pg71827-images.html',
    'https://www.gutenberg.org/cache/epub/71831/pg71831-images.html'
]
finnish_sources = [
    'https://www.gutenberg.org/cache/epub/11296/pg11296.html',
    'https://www.gutenberg.org/cache/epub/71606/pg71606.html',
    'https://www.gutenberg.org/cache/epub/71702/pg71702.html',
    'https://www.gutenberg.org/cache/epub/11296/pg11296.html'
]
german_sources = [
    'https://www.gutenberg.org/cache/epub/44956/pg44956-images.html',
    'https://www.gutenberg.org/cache/epub/7205/pg7205-images.html',
    'https://www.gutenberg.org/cache/epub/65661/pg65661-images.html',
    'https://www.gutenberg.org/cache/epub/38126/pg38126-images.html',
    'https://www.gutenberg.org/cache/epub/65662/pg65662-images.html'
]

langs = [
    ('english', {}, english_sources),
    ('finnish', {}, finnish_sources),
    ('german', {}, german_sources)
]        
guess_list = [
    ('https://www.gutenberg.org/cache/epub/71824/pg71824-images.html', 'english'),
    ('https://www.gutenberg.org/cache/epub/41907/pg41907-images.html', 'german'),
    ('https://www.gutenberg.org/cache/epub/41907/pg41907-images.html', 'german'),
    ('https://www.gutenberg.org/cache/epub/45263/pg45263.html', 'finnish')
]

# update stats
for _, lang, sources in langs:
    for source in sources:
        lang = calc_stats(source, lang)
# guess        
for url, initial_lang in guess_list:
    detected_lang = guess_lang(langs, url)
    print(f' oringe: {initial_lang} -> {detected_lang} {url})')