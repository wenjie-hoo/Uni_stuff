import os
import platform
import configparser
import asyncio
import aiohttp
from PIL import Image
import io

# The first task is to download imgs of cats. The imgs will be downloaded to the cats folder
# The second task will print a sentence, the website I found randomly

how_many_cats_do_you_want = 10

config = configparser.ConfigParser()
config.read('./private.py')
cat_api = config['DEFAULT']['cat_api']

cats_path = None
os_ = None

# create a folder to save then downloaded cat imgs
# haven't tested on win10 yet
async def create_folder():
    global cats_path
    global os_
    os_ = platform.system()
    current_path = os.getcwd()
    folder_name = 'cats'
    # win and linux has different slash for path, so we have to do this way
    if os_ == "Windows":
        cats_path = os.path.join(current_path, folder_name)
    elif os_ == "Darwin" or os_ == "Linux":  # Darwin for MacOS
        cats_path = os.path.join(current_path, folder_name)
    else:
        print("je ne sais pas")
        return False
    try:
        os.mkdir(cats_path)
    except FileExistsError:
        return True

# save imgs
async def get_cats(session, url, filename):
    async with session.get(url) as response:
        data = await response.read()
        img = Image.open(io.BytesIO(data))
        if img.mode in ("RGBA", "P"):
            img = img.convert("RGB")
        img.save(filename)
        print(f'Saving {filename}')

# for the second task
async def print_title(title):
    print(title)


async def main(limit=1):
    if await create_folder():
        async with aiohttp.ClientSession() as session:
            tasks = []
            for i in range(limit):
                url = f'https://api.thecatapi.com/v1/images/search?api_key={cat_api}'
                async with session.get(url) as response:
                    cat = await response.json()
                    url = cat[0]['url']
                    cat_id = cat[0]['id']
                    filename = os.path.join(cats_path, f'{cat_id}.jpg')
                    task = get_cats(session, url, filename)
                    tasks.append(task)
            
            for i in range(limit):
                i +=1
                url = f'https://jsonplaceholder.typicode.com/posts/{i}'
                async with session.get(url) as response:
                    data = await response.json()
                    title = data['title']
                    task = print_title(title)
                    tasks.append(task)
                    
            await asyncio.gather(*tasks)

if __name__ == "__main__":
    asyncio.run(main(limit=how_many_cats_do_you_want))