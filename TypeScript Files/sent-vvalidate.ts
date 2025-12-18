import re

# Input: webpage source (as text)
webpage_source = input("Enter webpage source or HTML content: ")

# Regular expression to find URLs (http, https, www)
pattern = r'(https?://[^\s"\'<>]+|www\.[^\s"\'<>]+)'

# Find all URLs in the text
urls = re.findall(pattern, webpage_source)

# Display results
if urls:
    print("Valid URLs found:")
    for url in urls:
        print(url)
else:
    print("No valid URLs found.")
