import requests
import time
import threading

# longest prefix suffix
def find_diff(str1, str2):
    l1, l2 = 0 , 0
    r1, r2 = len(str1)-1, len(str2)-1
    while l1 < len(str1) and l2 < len(str2) and str1[l1] == str2[l2]:
            l1 += 1
            l2 += 1
    while r1 >= 0 and r2 >= 0 and  str1[r1] == str2[r2]: 
            r1 -= 1
            r2 -= 1
    return (l1, r1)

def fetch_and_compare(url, website_content, sleep_time):
    while True:
        response = requests.get(url)
        website_content[url] = response.text
        time.sleep(sleep_time)    
        response_new = requests.get(url)
        l, r = find_diff(website_content[url], response_new.text)
        if website_content[url] != response_new.text:
            print(f'---------- new news {url} ----------') 
            print(f'Old content: \n{website_content[url][l:r]}')
            print("New content: ")
            new = response_new.text[l:r]
            print(new)
            print()
            website_content[url] = response_new.text


urls = ['https://www.bbc.com/news', 'https://news.google.com/', 'https://www.nbcnews.com/']
sleep_time = 5

website_content = {url: '' for url in urls}

threads = []
for url in urls:
    thread = threading.Thread(target=fetch_and_compare, args=(url, website_content, sleep_time))
    threads.append(thread)

for thread in threads:
    thread.start()

for thread in threads:
    thread.join()
