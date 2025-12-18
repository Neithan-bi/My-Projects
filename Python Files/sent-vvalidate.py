import re

# Example HTML content (you can also load from a file or web request)
html_content = """
<html>
  <body>
    <a href="https://www.google.com">Google</a>
    <a href='https://www.openai.com'>OpenAI</a>
    <a href="/about.html">About Us</a>
    <a name="anchor">No link here</a>
  </body>
</html>
"""

# Regex pattern to extract href links (handles both single and double quotes)
pattern = r'href=[\'"]([^\'"]+)[\'"]'

# Find all matching links
links = re.findall(pattern, html_content)

# Display results
if links:
    print("Hyperlinks found in the HTML content:")
    for link in links:
        print(link)
else:
    print("No hyperlinks found.")
