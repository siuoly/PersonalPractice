#!/bin/python3.8
import webbrowser
from os import path

file=path.realpath('a.html')

webbrowser.open(f'file:wsl$/Ubuntu-20.04{file}')
# webbrowser.open(f'a.html') # faile


