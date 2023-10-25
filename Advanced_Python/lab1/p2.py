import re

def is_palindrome(text):
    cleaned_text = re.sub(r'[^a-zA-Z0-9]', '', text).lower()
    return cleaned_text == cleaned_text[::-1]
    
if __name__ == "__main__":
    text = [' ', 'level', 'Koby la ma ma ly bok.!',
            'Eine güldne, gute Tugend: Lüge nie!', 
            'this is not palindrome',
            'M´ıˇc omoˇc´ım',
            '我是我',
            'return false']
    for t in text:
        print(t, is_palindrome(t))
    