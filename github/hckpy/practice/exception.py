"""Convert and print string to int or if cannot convert print bad string"""
import sys


S = input().strip()
try:
    print(int(S))
except ValueError:
    print('Bad String')
