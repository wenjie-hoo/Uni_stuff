def compress(msg):
    if len(msg) == 0:
        return []
    res = []
    last = msg[0]
    count = 0
    for char in msg:
        if char == last:
            count+=1
        else:
            res.append((count, last))
            last = char
            count = 1
    if count != 0: res.append((count, last))
    return res

def decompress(msg):
    res = ''
    for count, char in msg:
        res += count*char
    return res

compressed = compress("aaaaffcccss")
print(compressed)

print(decompress(compressed))