import re

class Palindrome:

    @staticmethod
    def is_palindrome(text):
        text = text.lower()
        simple_text = re.sub(r'[^a-z]', '', text)
        if simple_text == simple_text[::-1]
            return True
        else:
            return False
