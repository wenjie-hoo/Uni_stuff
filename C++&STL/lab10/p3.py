import chardet

def detect_encoding(file_path):
    with open(file_path, 'rb') as f:
        result = chardet.detect(f.read())

    return result['encoding']

print(f"text.txt encoding is: {detect_encoding('text.txt')}")
print(f"output_utf32.txt encoding is: {detect_encoding('output_utf32.txt')}")
print(f"output_iso88592.txt encoding is: {detect_encoding('output_iso88592.txt')}")