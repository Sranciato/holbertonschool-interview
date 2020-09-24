#!/usr/bin/python3
"""Queries Reddit API and finds keywords from all hot posts"""
import requests
from sys import argv


def count_words(subreddit, word_list, after="", counter={}, check=0):
    """Queries Reddit API and finds keywords from all hot posts"
    """
    if check == 0:
        for word in word_list:
            counter[word] = 0
    headers = {'User-Agent': 'steve'}
    json = requests.get('https://api.reddit.com/r/{}/hot?after={}'.
                        format(subreddit, after),
                        headers=headers).json()
    try:
        key = json['data']['after']
        parent = json['data']['children']
        for obj in parent:
            for word in counter:
                counter[word] += obj['data']['title'].lower().split(' ').count(
                    word.lower())
        if key:
            count_words(subreddit, word_list, key, counter, 1)
        else:
            res = sorted(counter.items(), key=lambda i: i[1], reverse=True)
            for key, value in res:
                if value != 0:
                    print('{}: {}'.format(key, value))
    except Exception:
        return None
