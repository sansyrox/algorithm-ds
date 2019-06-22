import sys
import requests
import re
import json

url = sys.argv[-1]
html = requests.get(url)

track_id = re.search(r'soundcloud://sounds:(.+?)"', html.text)
final_page = requests.get("https://api.soundcloud.com/i1/tracks/{0}/streams?client_id=6pDzV3ImgWPohE7UmVQOCCepAaKOgrVL".format(track_id.group(1)))
print(final_page.json()['http_mp3_128_url'])