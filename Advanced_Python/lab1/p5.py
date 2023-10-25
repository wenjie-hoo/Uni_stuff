def common_prefix(word_list):
    word_list = [word.lower() for word in word_list]
    if len(word_list) < 2:
        return ""
    shortest_word = min(word_list, key=len)    
    common_prefix = ""
    for i in range(len(shortest_word)):
        current_char = word_list[0][i]
        if all(word[i] == current_char for word in word_list):
            common_prefix += current_char
        else:
            break
    return common_prefix

if __name__ == "__main__":
    word_list = ["Cyxprian", "cyxberotoman", "cyxnik", "cyxeniac", "cyxzule"]
    print(f'longest common prefix: {common_prefix(word_list)}')
