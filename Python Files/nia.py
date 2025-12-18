
import json
import os
from PIL import Image, ImageDraw

def json_to_png(json_path):
    with open(json_path, 'r') as f:
        data = json.load(f)

    img_rel = data.get('imagePath')
    if not img_rel:
        print("No imagePath in JSON.")
        return

    # Resolve path relative to the JSON file
    base = os.path.dirname(json_path)
    img_path = os.path.normpath(os.path.join(base, img_rel))

    if not os.path.exists(img_path):
        print("Image not found:", img_path)
        return

    img = Image.open(img_path).convert("RGBA")

    # If there are shapes, draw simple overlays (optional)
    shapes = data.get("shapes", [])
    if shapes:
        draw = ImageDraw.Draw(img, "RGBA")
        for s in shapes:
            pts = s.get("points", [])
            if not pts:
                continue
            pts_tuples = [(float(x), float(y)) for x, y in pts]
            # draw polygon outline in semi-transparent red
            draw.polygon(pts_tuples, outline=(255,0,0,200))

    out_png = os.path.splitext(img_path)[0] + ".png"
    img.save(out_png)
    print("Saved PNG:", out_png)

if __name__ == "__main__":
    # change this path if you saved the JSON elsewhere
    json_file = r"c:\Users\iguru\OneDrive\Desktop\Code Files\Tooth Imagiese\Tooth19.json"
    json_to_png(json_file)