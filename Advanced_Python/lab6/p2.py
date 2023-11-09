from bs4 import BeautifulSoup
import re
import requests
import time

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

def remove_html(str):
    soup = BeautifulSoup(str, features="lxml").text
    str = re.compile('<.*?>')
    str = re.compile('{.*?}')
    str = re.sub(str, '', soup)
    return str

urls = ['https://www.bbc.com/news', 'https://news.google.com/', 'https://www.nbcnews.com/']
sleep_time = 5

while True:    
    for url in urls:
        website_content = {}
        response = requests.get(url)
        website_content[url] = response.text
        time.sleep(sleep_time)    
        response_new= requests.get(url)
        l, r = find_diff(website_content[url], response_new.text)
        if website_content[url] != response_new.text:
            print(f'---------- new news {url} ----------') 
            print(f'Old content: \n{website_content[url][l:r]}')
            print("New content: ")
            new = response_new.text[l:r]
            filtered_text = remove_html(new) # may not necessary
            print(filtered_text)
            print()
            website_content[url] = response_new.text
    